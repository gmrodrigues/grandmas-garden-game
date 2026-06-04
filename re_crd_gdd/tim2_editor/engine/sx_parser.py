"""TIM2.SX container parser — Sierra SND chunked audio resource.

Reads TIM2.SX from game data and exposes:
  - 38 instrument patches (14 FM/OPL2, 24 waveform/music)
  - SCI28 instrument decode for FM patches
  - RAW PCM file references for sound effects
"""

from __future__ import annotations

import json
import logging
import struct
from pathlib import Path
from typing import Dict, List, Optional, Any, Tuple

logger = logging.getLogger(__name__)

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent

DAT_HEADER_SIZE = 12
SCI28_SIZE = 28


class SxParser:
    """Parser for TIM2.SX Sierra SND chunked container format.

    Default paths:
        sx_path: build/phase-1/extracted/TIM2.SX
        raw_dir: build/phase-1/extracted/ (for SX_*.RAW files)
    """

    def __init__(self, sx_path: Optional[Path] = None,
                 raw_dir: Optional[Path] = None):
        self.sx_path = sx_path or (
            PROJECT_ROOT / "build" / "phase-1" / "extracted" / "TIM2.SX"
        )
        self.raw_dir = raw_dir or (
            PROJECT_ROOT / "build" / "phase-1" / "extracted"
        )
        self._parsed = False
        self._data: bytes = b""
        self._chunks: List[dict] = []
        self._snd_preamble: str = ""
        self._inf: dict = {}
        self._patches: List[dict] = []
        self._tag_names: List[dict] = []
        self._raw_files: List[dict] = []
        self._name_map: Dict[int, str] = {}
        self._by_id: Dict[int, dict] = {}

    def parse(self) -> "SxParser":
        """Parse TIM2.SX. Returns self for chaining."""
        if not self.sx_path.exists():
            logger.warning("TIM2.SX not found at %s", self.sx_path)
            return self
        self._data = self.sx_path.read_bytes()
        self._chunks, self._snd_preamble, _ = self._parse_chunks()
        self._inf = self._parse_inf()
        self._patches = self._parse_patches()
        self._tag_names = self._parse_tag()
        for n in self._tag_names:
            self._name_map[n["sound_id"]] = n["name"]
        for p in self._patches:
            p["name"] = self._name_map.get(p["sound_id"], "")
            self._by_id[p["sound_id"]] = p
        self._raw_files = self._parse_raw_files()
        self._parsed = True
        return self

    @property
    def patches(self) -> List[dict]:
        if not self._parsed:
            self.parse()
        return self._patches

    @property
    def fm_patches(self) -> List[dict]:
        return [p for p in self.patches if p["type"] == 7]

    @property
    def waveform_patches(self) -> List[dict]:
        return [p for p in self.patches if p["type"] == 9]

    @property
    def raw_files(self) -> List[dict]:
        if not self._parsed:
            self.parse()
        return self._raw_files

    @property
    def tag_names(self) -> List[dict]:
        if not self._parsed:
            self.parse()
        return self._tag_names

    def get_patch(self, sound_id: int) -> Optional[dict]:
        if not self._parsed:
            self.parse()
        return self._by_id.get(sound_id)

    def get_fm_instrument(self, sound_id: int) -> Optional[dict]:
        patch = self.get_patch(sound_id)
        if patch is None or patch["type"] != 7:
            return None
        payload = patch["instrument_data"]
        return self.decode_sci28(payload)

    def get_waveform_pcm(self, sound_id: int) -> Optional[bytes]:
        patch = self.get_patch(sound_id)
        if patch is None or patch["type"] != 9:
            return None
        return patch["instrument_data"]

    def get_raw_path(self, sound_id: int) -> Optional[Path]:
        wav_path = (
            PROJECT_ROOT / "build" / "phase-6" / "raw-wav"
            / f"SX_{sound_id}_11025.wav"
        )
        if wav_path.exists():
            return wav_path
        raw_path = self.raw_dir / f"SX_{sound_id}.RAW"
        if raw_path.exists():
            return raw_path
        return None

    @staticmethod
    def decode_sci28(payload: bytes) -> Optional[dict]:
        """Decode 28-byte Sierra SCI AdLib instrument format to OPL2 registers."""
        if len(payload) < SCI28_SIZE:
            return None

        def _op(idx: int) -> dict:
            return {
                "ksl_lo": payload[idx + 0] & 0x3,
                "mult": payload[idx + 1] & 0xF,
                "ar": payload[idx + 3] & 0xF,
                "sl": payload[idx + 4] & 0xF,
                "egs": bool(payload[idx + 5]),
                "dr": payload[idx + 6] & 0xF,
                "rr": payload[idx + 7] & 0xF,
                "tl": payload[idx + 8] & 0x3F,
                "am": bool(payload[idx + 9]),
                "vib": bool(payload[idx + 10]),
                "ksr": bool(payload[idx + 11]),
                "wf": payload[idx + 13] & 0x3 if len(payload) > idx + 13 else 0,
            }

        idx = 0
        op0 = _op(idx)
        feedback = payload[idx + 2] & 0x7
        algorithm_sci = not bool(payload[idx + 12])

        idx = 13
        op1 = _op(idx)

        def _to_reg20(op: dict) -> int:
            return (int(op["am"]) << 7) | (int(op["vib"]) << 6) | (int(op["egs"]) << 5) | (int(op["ksr"]) << 4) | op["mult"]

        def _to_reg40(op: dict) -> int:
            return (op["ksl_lo"] << 6) | op["tl"]

        def _to_reg60(op: dict) -> int:
            return (op["ar"] << 4) | op["dr"]

        def _to_reg80(op: dict) -> int:
            return (op["sl"] << 4) | op["rr"]

        return {
            "op0": op0,
            "op1": op1,
            "feedback": feedback,
            "algorithm": 0 if algorithm_sci else 1,
            "opl2": {
                "reg_0x20_op0": _to_reg20(op0),
                "reg_0x40_op0": _to_reg40(op0),
                "reg_0x60_op0": _to_reg60(op0),
                "reg_0x80_op0": _to_reg80(op0),
                "reg_0xE0_op0": op0["wf"],
                "reg_0x20_op1": _to_reg20(op1),
                "reg_0x40_op1": _to_reg40(op1),
                "reg_0x60_op1": _to_reg60(op1),
                "reg_0x80_op1": _to_reg80(op1),
                "reg_0xE0_op1": op1["wf"],
                "reg_0xC0": (feedback << 1) | (0 if algorithm_sci else 1),
            },
        }

    @staticmethod
    def sci28_to_registers(sci28: dict) -> List[Tuple[int, int, int]]:
        """Convert decoded SCI28 to (channel, reg, value) OPL2 writes.

        Channel mapping: op0=modulator on ch 0, op1=carrier on ch 0.
        Returns list of (operator_slot, register, value) tuples.
        Slot is 0 for modulator (op0) and 1 for carrier (op1).
        """
        r = sci28["opl2"]
        regs = []
        # Operator 0 (modulator) — slot 0
        for reg, val in [("reg_0x20_op0", 0x20), ("reg_0x40_op0", 0x40),
                         ("reg_0x60_op0", 0x60), ("reg_0x80_op0", 0x80),
                         ("reg_0xE0_op0", 0xE0)]:
            regs.append((0, val, r[reg]))
        # Operator 1 (carrier) — slot 1
        for reg, val in [("reg_0x20_op1", 0x20), ("reg_0x40_op1", 0x40),
                         ("reg_0x60_op1", 0x60), ("reg_0x80_op1", 0x80),
                         ("reg_0xE0_op1", 0xE0)]:
            regs.append((1, val, r[reg]))
        # Connection register
        regs.append((0, 0xC0, r["reg_0xC0"]))
        return regs

    def summary(self) -> str:
        patches = self.patches
        fm = sum(1 for p in patches if p["type"] == 7)
        wf = sum(1 for p in patches if p["type"] == 9)
        raw = len(self.raw_files)
        return (f"SxParser: {len(patches)} patches ({fm} FM, {wf} waveform), "
                f"{raw} RAW files")

    # --- Internal parsing ---

    def _parse_chunks(self) -> Tuple[List[dict], str, int]:
        data = self._data
        snd_preamble = data[4:8].hex()
        pos = 8
        chunks = []
        while pos + 8 <= len(data):
            tag = data[pos:pos + 4]
            try:
                tag_str = tag.decode("ascii")
            except UnicodeDecodeError:
                tag_str = tag.hex()
            if tag[3:4] != b":":
                break
            size = struct.unpack_from("<I", data, pos + 4)[0]
            if pos + 8 + size > len(data):
                break
            chunk_data = data[pos + 8:pos + 8 + size]
            chunks.append({"tag": tag_str, "offset": pos, "size": size, "data": chunk_data})
            pos += 8 + size
        return chunks, snd_preamble, pos

    def _parse_inf(self) -> dict:
        for c in self._chunks:
            if c["tag"] != "INF:":
                continue
            d = c["data"]
            version = struct.unpack_from("<H", d, 0)[0]
            count = struct.unpack_from("<H", d, 2)[0]
            type_byte = d[4]
            entries = []
            for i in range(count):
                off = 5 + i * 6
                if off + 6 > len(d):
                    break
                sid = struct.unpack_from("<H", d, off)[0]
                foff = struct.unpack_from("<I", d, off + 2)[0]
                entries.append({"sound_id": sid, "file_offset": foff})
            return {"version": version, "count": count, "type_byte": type_byte, "entries": entries}
        return {"version": 0, "count": 0, "type_byte": 0, "entries": []}

    def _parse_patches(self) -> List[dict]:
        data = self._data
        patches = []
        for entry in self._inf.get("entries", []):
            foff = entry["file_offset"]
            if foff + 8 > len(data):
                continue
            tag = data[foff:foff + 4]
            chunk_size = struct.unpack_from("<I", data, foff + 4)[0]
            if tag != b"DAT:":
                continue
            if foff + 8 + chunk_size > len(data):
                continue
            patch_data = data[foff + 8:foff + 8 + chunk_size]
            if len(patch_data) < DAT_HEADER_SIZE:
                continue
            sound_id = struct.unpack_from("<H", patch_data, 0)[0]
            ptype = patch_data[2]
            mode = patch_data[3]
            unknown = patch_data[4]
            parameter = struct.unpack_from("<H", patch_data, 5)[0]
            zero = struct.unpack_from("<H", patch_data, 7)[0]
            init_bytes = patch_data[9:12].hex()
            instrument_data = patch_data[DAT_HEADER_SIZE:]
            patches.append({
                "sound_id": sound_id,
                "type": ptype,
                "mode": mode,
                "unknown": unknown,
                "parameter": parameter,
                "zero": zero,
                "init_bytes": init_bytes,
                "data_size": len(instrument_data),
                "total_size": chunk_size,
                "file_offset": foff,
                "instrument_data": instrument_data,
            })
        return patches

    def _parse_tag(self) -> List[dict]:
        for c in self._chunks:
            if c["tag"] != "TAG:":
                continue
            d = c["data"]
            count = struct.unpack_from("<H", d, 0)[0]
            pos = 2
            names = []
            for _ in range(count):
                if pos + 2 > len(d):
                    break
                sid = struct.unpack_from("<H", d, pos)[0]
                pos += 2
                end = d.index(0, pos)
                name = d[pos:end].decode("ascii", errors="replace")
                pos = end + 1
                names.append({"sound_id": sid, "name": name})
            return names
        return []

    def _parse_raw_files(self) -> List[dict]:
        raw_files = sorted(self.raw_dir.glob("SX_*.RAW"))
        raw_info = []
        for f in raw_files:
            data = f.read_bytes()
            if not data:
                continue
            sid_str = f.stem.replace("SX_", "")
            try:
                sid = int(sid_str)
            except ValueError:
                continue
            mn = min(data)
            mx = max(data)
            avg = sum(data[:256]) / min(256, len(data))
            unique = len(set(data[:min(256, len(data))]))
            raw_info.append({
                "filename": f.name,
                "sound_id": sid,
                "size": len(data),
                "byte_min": mn,
                "byte_max": mx,
            })
        return raw_info


def create_default_parser() -> SxParser:
    return SxParser().parse()
