// TIM2.EXE: FUN_460e_1d6a @ file 0x04D04A Ghidra 0x47E4A
// Subsystem: misc | Size: 390 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_460e_1d6a(void)

{
  uint uVar1;
  
  if (DAT_5b41_1ce2 != 0) {
    if (DAT_5b41_1ce4 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffff;
    }
    if (DAT_5b41_1cd2 != _DAT_5b41_1b88) {
      uVar1 = uVar1 | 1;
    }
    if (DAT_5b41_1cd4 != DAT_5b41_1b8a) {
      uVar1 = uVar1 | 2;
    }
    if (DAT_5b41_1cd6 != DAT_5b41_1b84) {
      uVar1 = uVar1 | 4;
    }
    if (DAT_5b41_1cd8 != DAT_5b41_1b86) {
      uVar1 = uVar1 | 8;
    }
    if (DAT_5b41_1cda != DAT_5b41_1b80) {
      uVar1 = uVar1 | 0x10;
    }
    if (DAT_5b41_1cdc != DAT_5b41_1b82) {
      uVar1 = uVar1 | 0x20;
    }
    if (DAT_5b41_1cde != DAT_5b41_1b92) {
      uVar1 = uVar1 | 0x40;
    }
    if (DAT_5b41_1ce0 != _DAT_5b41_1b94) {
      uVar1 = uVar1 | 0x80;
    }
    if (DAT_5b41_1b98 == 0) {
      uVar1 = uVar1 & 0xfeff;
    }
    else {
      uVar1 = uVar1 | 0x100;
    }
    DAT_5b41_1cd2 = _DAT_5b41_1b88;
    DAT_5b41_1cd4 = DAT_5b41_1b8a;
    DAT_5b41_1cd6 = DAT_5b41_1b84;
    DAT_5b41_1cd8 = DAT_5b41_1b86;
    DAT_5b41_1cda = DAT_5b41_1b80;
    DAT_5b41_1cdc = DAT_5b41_1b82;
    DAT_5b41_1cde = DAT_5b41_1b92;
    DAT_5b41_1ce0 = _DAT_5b41_1b94;
    DAT_5b41_1ce4 = 0;
    FUN_42da_05c8(DAT_5b41_1ce2,uVar1);
    if ((uVar1 & 1) != 0) {
      FUN_42da_05c8(DAT_5b41_1ce2,DAT_5b41_1cd2);
    }
    if ((uVar1 & 2) != 0) {
      FUN_42da_05c8(DAT_5b41_1ce2,DAT_5b41_1cd4);
    }
    if ((uVar1 & 4) != 0) {
      FUN_42da_05c8(DAT_5b41_1ce2,DAT_5b41_1cd6);
    }
    if ((uVar1 & 8) != 0) {
      FUN_42da_05c8(DAT_5b41_1ce2,DAT_5b41_1cd8);
    }
    if ((uVar1 & 0x10) != 0) {
      FUN_42da_05c8(DAT_5b41_1ce2,DAT_5b41_1cda);
    }
    if ((uVar1 & 0x20) != 0) {
      FUN_42da_05c8(DAT_5b41_1ce2,DAT_5b41_1cdc);
    }
    if ((uVar1 & 0x40) != 0) {
      FUN_42da_05c8(DAT_5b41_1ce2,DAT_5b41_1cde);
    }
    if ((uVar1 & 0x80) != 0) {
      FUN_42da_05c8(DAT_5b41_1ce2,DAT_5b41_1ce0);
    }
  }
  return;
}

