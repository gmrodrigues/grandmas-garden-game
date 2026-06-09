// TIM2.EXE: FUN_460e_1b75 @ file 0x04CE55 Ghidra 0x47C55
// Subsystem: misc | Size: 350 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_460e_1b75(void)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_5b41_1c80 != 0) {
    iVar1 = FUN_1000_1082(DAT_5b41_1c80);
    if (iVar1 == 0) {
      uVar2 = FUN_42da_04d6(DAT_5b41_1c80);
      if ((uVar2 & 1) != 0) {
        DAT_5b41_1c70 = FUN_42da_04d6(DAT_5b41_1c80);
      }
      if ((uVar2 & 2) != 0) {
        DAT_5b41_1c72 = FUN_42da_04d6(DAT_5b41_1c80);
      }
      if ((uVar2 & 4) != 0) {
        DAT_5b41_1c74 = FUN_42da_04d6(DAT_5b41_1c80);
      }
      if ((uVar2 & 8) != 0) {
        DAT_5b41_1c76 = FUN_42da_04d6(DAT_5b41_1c80);
      }
      if ((uVar2 & 0x10) != 0) {
        DAT_5b41_1c78 = FUN_42da_04d6(DAT_5b41_1c80);
      }
      if ((uVar2 & 0x20) != 0) {
        DAT_5b41_1c7a = FUN_42da_04d6(DAT_5b41_1c80);
      }
      if ((uVar2 & 0x40) != 0) {
        DAT_5b41_1c7c = FUN_42da_04d6(DAT_5b41_1c80);
      }
      if ((uVar2 & 0x80) != 0) {
        DAT_5b41_1c7e = FUN_42da_04d6(DAT_5b41_1c80);
      }
      _DAT_5b41_1b88 = DAT_5b41_1c70;
      DAT_5b41_1b8a = DAT_5b41_1c72;
      DAT_5b41_1b80 = DAT_5b41_1c78;
      DAT_5b41_1b82 = DAT_5b41_1c7a;
      DAT_5b41_1b92 = DAT_5b41_1c7c;
      _DAT_5b41_1b94 = DAT_5b41_1c7e;
      DAT_5b41_1b8e = DAT_5b41_1c7c & 0xff;
      DAT_5b41_1b90 = DAT_5b41_1c7c >> 8;
      DAT_5b41_1b84 = DAT_5b41_1c74;
      DAT_5b41_1b86 = DAT_5b41_1c76;
      DAT_5b41_1b98 = (uint)((uVar2 & 0x100) != 0);
      iVar1 = DAT_554c_49ac;
      if (DAT_5b41_1b98 == 0) {
        iVar1 = 0;
      }
      FUN_406b_0c62(DAT_5b41_1c74,DAT_5b41_1c76 + iVar1);
    }
    else {
      FUN_460e_1aea(0,0);
    }
  }
  return;
}

