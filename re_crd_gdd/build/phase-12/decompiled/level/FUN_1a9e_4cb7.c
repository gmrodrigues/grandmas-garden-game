// TIM2.EXE: FUN_1a9e_4cb7 @ file 0x024897 Ghidra 0x1F697
// Subsystem: level | Size: 47 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far FUN_1a9e_4cb7(void)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if (_DAT_0000_041a != _DAT_0000_041c) {
    uVar1 = *_DAT_0000_041a;
    _DAT_0000_041a = _DAT_0000_041a + 1;
    if (_DAT_0000_041a == _DAT_0000_0482) {
      _DAT_0000_041a = _DAT_0000_0480;
    }
  }
  return uVar1;
}

