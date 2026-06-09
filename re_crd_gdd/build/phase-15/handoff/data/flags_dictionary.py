"""Dicionário de Flags para The Incredible Machine 2 (TIM2).

Contém a descrição detalhada e o mapeamento binário de cada bit para
os campos flags_1, flags_2 e flags_3 das peças do puzzle (Parts).

Sourced from: ModdingWiki (knt47) + empirical level analysis.
Flags encode INSTANCE STATE, not type properties — most bits vary per instance.
"""

FLAGS_1_DICT = {
    0x0020: "Confirmed: affects physics bias selection. At EXE 0x53923: if set, bias=0x20 (32 units); if clear, bias=0x02 (2 units). Controls collision/velocity tolerance for moving parts. ~5% usage in TIM2.",
    0x0040: "Confirmed: runtime constraint-processing skip flag. At EXE 0x5542F: if set, part skips rope/belt constraint init. Parts with this bit are static or don't need constraint updates. ~3% usage, moving parts only.",
    0x0200: "Part can be flipped vertically.",
    0x0400: "Part can be flipped horizontally.",
    0x0800: "Part is placed initially into the parts bin (~1%).",
    0x1000: "\"Moving\" part, affected by gravity.",
    0x2000: "Part cannot move, in fixed position (used with 0x4000).",
    0x4000: "Part cannot move, in fixed position (used with 0x2000).",
    0x8000: "Set when 0x0800 is not set (TIM1). Rare in TIM2 (~1%).",
}

FLAGS_2_DICT = {
    0x0001: "A belt can be connected to the part.",
    0x0002: "A belt is connected to the part.",
    0x0004: "A rope can be connected to the part.",
    0x0008: "A second rope can be connected to the part (e.g. teeter-totter).",
    0x0010: "The part sprite is drawn horizontally flipped.",
    0x0020: "The part sprite is drawn vertically flipped. Note: flipping does not always change this bit; some TIM2 parts use appearance instead.",
    0x0040: "Probably unused. No observable effect. ~11% usage, random co-occurrence.",
    0x0080: "Part can be stretched in at least one direction: inclines, conveyor belt, walls.",
    0x0100: "Parts that can be stretched both horizontally and vertically: walls.",
}

FLAGS_3_DICT = {
    0x0001: "The part can be plugged into an electric outlet.",
    0x0002: "The part IS an electric outlet.",
    0x0004: "The part can burn (candle) or has a fuse that can be lit (dynamite, cannon). Usually combined with 0x0008.",
    0x0008: "Confirmed: controls gravity_x direction (wind). At EXE 0x535C9: if bit set, gravity_x subtracts (left); if clear, gravity_x adds (right). ~50% of all parts use it — most use the default (wind-free) direction.",
    0x0040: "Part is 'locked' — not placed into the parts bin (TIM2/3).",
    0x0080: "Sizable scenery part (TIM2/3).",
    0x0100: "Unknown meaning (TIM2/3). Possibly related to mechanical/structural parts (gears, inclines).",
    0x0400: "A 'program' icon is shown for the part (TIM2/3).",
    0x1000: "Scenery part (TIM2/3).",
    0x2000: "Wall part (TIM2/3).",
    0x8000: "A 'Puzzle solution' icon is shown for the part (TIM2/3).",
}


def decode_flags(flags_value: int, flags_dict: dict[int, str]) -> list[str]:
    """Decodifica um valor inteiro de flags numa lista de strings explicativas."""
    descriptions = []
    for bit, desc in sorted(flags_dict.items()):
        if flags_value & bit:
            descriptions.append(f"0x{bit:04x}: {desc}")
    return descriptions


def get_flags_explanation(f1: int, f2: int, f3: int) -> dict[str, list[str]]:
    """Gera um dicionário estruturado com as explicações de flags_1, flags_2 e flags_3."""
    return {
        "flags_1": decode_flags(f1, FLAGS_1_DICT),
        "flags_2": decode_flags(f2, FLAGS_2_DICT),
        "flags_3": decode_flags(f3, FLAGS_3_DICT),
    }
