"""TIM2 filename hash function (reverse-engineered from TIM2.EXE CS:0x05F4)."""

_WEIGHT = [ord(c) for c in "RichRayl@JTP\0RES"]


def _s16(x):
    return x if x < 0x8000 else x - 0x10000


def _imul16(a, b):
    r = _s16(a) * _s16(b)
    return (r >> 16) & 0xFFFF, r & 0xFFFF


def tim2_hash(name, hash_idx=None):
    """Compute TIM2 resource name hash.
    
    Args:
        name: Filename (case-insensitive, uppercased internally).
        hash_idx: 4-element index list (default [0,1,4,7] from MAP header).
    
    Returns:
        32-bit hash value matching TIM2.EXE exactly.
    """
    if hash_idx is None:
        hash_idx = [0, 1, 4, 7]
    
    chars = [ord(c) for c in name.upper()]
    
    # Phase 1: weighted sum & XOR checksum
    wsum = 0
    xorsum = 0
    for i, c in enumerate(chars):
        _, prod = _imul16(c, _WEIGHT[i % 16])
        wsum = (wsum + prod) & 0xFFFF
        xorsum ^= c
        if c in (0x5C, 0x3A):
            wsum = 0
            xorsum = 0
    
    # Phase 2: null-padded 13-byte buffer
    buf = chars + [0] * max(0, 13 - len(chars))
    buf = buf[:13]
    
    # Phase 3: 32-bit ROL8 hash of selected character positions
    rh, rl = 0, 0
    for idx in hash_idx[:4]:
        bx = _s16(rl)
        rl = (rl << 8) & 0xFFFF
        rh = (rh << 8) & 0xFFFF
        rh |= (bx >> 8) & 0xFFFF
        
        cv = buf[idx] if idx < len(buf) else 0
        rl_old = rl
        rl = (rl + cv) & 0xFFFF
        rh = (rh + (1 if rl_old + cv >= 0x10000 else 0)) & 0xFFFF
    
    # Phase 4: combine rotation with (wsum * xorsum) sign-extended
    _, prod = _imul16(wsum, xorsum)
    prod_hi = 0xFFFF if prod >= 0x8000 else 0
    
    rl_old = rl
    rl = (rl + prod) & 0xFFFF
    carry = 1 if rl_old + prod >= 0x10000 else 0
    rh = (rh + prod_hi + carry) & 0xFFFF
    
    return (rh << 16) | rl
