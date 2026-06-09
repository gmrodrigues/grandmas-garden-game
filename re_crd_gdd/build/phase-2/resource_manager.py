"""ResourceManager — TIM2 asset lookup and extraction.

Usage:
    from resource_manager import ResourceManager
    rm = ResourceManager()
    data = rm.get("BUTTONS.BMP")
    print(rm.list_names()[:5])

Uses the verified hash function (tim2_hash) for name→hash resolution,
RESOURCE.MAP for hash→offset mapping, and RESOURCE.001 for data extraction.
"""
from __future__ import annotations

import csv
import struct
from pathlib import Path
from typing import Iterator

from tim2_hash import tim2_hash

HERE = Path(__file__).resolve().parent
PROJECT_ROOT = HERE.parent.parent


class ResourceManager:
    """Provides hash-based lookup and extraction from TIM2 game assets."""

    def __init__(
        self,
        map_path: str | Path = PROJECT_ROOT / "RESOURCE.MAP",
        vol_path: str | Path = PROJECT_ROOT / "RESOURCE.001",
        manifest_path: str | Path = PROJECT_ROOT / "build" / "phase-1" / "manifest.csv",
    ):
        self._map_path = Path(map_path)
        self._vol_path = Path(vol_path)
        self._volume = self._vol_path.read_bytes()
        self._hash_idx: list[int]
        self._map_entries: list[dict] = []
        self._by_hash: dict[int, dict] = {}
        self._by_name: dict[str, dict] = {}
        self._names: list[str] = []
        self._load_map()
        self._load_manifest(Path(manifest_path))

    def _load_map(self) -> None:
        data = self._map_path.read_bytes()
        self._hash_idx = list(data[0:4])
        nul = data.index(b"\x00", 6)
        entry_start = nul + 1
        n_entries = (len(data) - entry_start) // 8
        page_base = 0
        prev_off = 0
        for i in range(n_entries):
            p = entry_start + i * 8
            typ, h, off_low = struct.unpack_from("<HIH", data, p)
            if off_low < prev_off:
                page_base += 0x10000
            full_off = page_base + off_low
            entry = {
                "hash": h,
                "type": typ,
                "offset_low16": off_low,
                "offset_full": full_off,
            }
            self._map_entries.append(entry)
            self._by_hash[h] = entry
            prev_off = off_low

    def _load_manifest(self, path: Path) -> None:
        with path.open(newline="") as f:
            for row in csv.DictReader(f):
                name = row["name"]
                data_off = int(row["data_offset"])
                size = int(row["size"])
                rec_off = int(row["record_offset"])
                h = tim2_hash(name, self._hash_idx)
                info = {
                    "name": name,
                    "hash": h,
                    "record_offset": rec_off,
                    "data_offset": data_off,
                    "size": size,
                    "type_code": f"0x{self._by_hash.get(h, {}).get('type', 0):04x}",
                }
                self._by_name[name] = info
                self._names.append(name)

    @property
    def hash_idx(self) -> list[int]:
        return list(self._hash_idx)

    @property
    def entry_count(self) -> int:
        return len(self._names)

    def contains(self, name: str) -> bool:
        name_upper = name.upper()
        return name_upper in self._by_name

    def get(self, name: str) -> bytes:
        name_upper = name.upper()
        info = self._by_name.get(name_upper)
        if info is None:
            raise KeyError(f"resource not found: {name}")
        start = info["data_offset"]
        end = start + info["size"]
        return self._volume[start:end]

    def lookup(self, name: str) -> dict | None:
        name_upper = name.upper()
        return self._by_name.get(name_upper)

    def list_names(self) -> list[str]:
        return list(self._names)

    def __iter__(self) -> Iterator[str]:
        return iter(self._names)

    def __len__(self) -> int:
        return len(self._names)

    def __contains__(self, name: str) -> bool:
        return self.contains(name)
