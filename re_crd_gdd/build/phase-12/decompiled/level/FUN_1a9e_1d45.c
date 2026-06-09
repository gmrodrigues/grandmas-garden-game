// TIM2.EXE: FUN_1a9e_1d45 @ file 0x021925 Ghidra 0x1C725
// Subsystem: level | Size: 596 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16near FUN_1a9e_1d45(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined2 uVar5;
  uint local_6;
  
  iVar2 = DAT_5b41_0044;
  local_6 = (uint)*(byte *)(DAT_5b41_0042 + 0x1b);
  uVar4 = (uint)*(byte *)(DAT_5b41_0042 + 0x1a);
  if (DAT_5b41_1d4e == 0) {
    if (DAT_5b41_1d1e == 0) {
      FUN_1a9e_186c();
      FUN_1a9e_1357();
      DAT_5b41_1d28 = 0;
      DAT_5b41_1d26 = 0xfc4;
      for (DAT_5b41_1d20 = 0; DAT_5b41_1d20 < (int)DAT_5b41_1d26; DAT_5b41_1d20 = DAT_5b41_1d20 + 1)
      {
        *(undefined1 *)((int)_DAT_5b41_1d62 + DAT_5b41_1d20) = 0x20;
      }
      DAT_5b41_1d24 = 0;
    }
    DAT_5b41_1d1e = 0;
    for (; (DAT_5b41_1d24 < 0x3c && (local_6 != uVar4)); local_6 = (local_6 + 1) % 0x80) {
      *(undefined1 *)(DAT_5b41_1d26 + DAT_5b41_1d24 + DAT_5b41_1d62) =
           *(undefined1 *)(local_6 + iVar2);
      DAT_5b41_1d24 = DAT_5b41_1d24 + 1;
    }
    if ((local_6 == uVar4) && (param_1 == 0)) {
      DAT_5b41_1d1e = 1;
      *(undefined1 *)(DAT_5b41_0042 + 0x1b) = (undefined1)local_6;
      return 0;
    }
    for (DAT_5b41_1d20 = 1; DAT_5b41_1d20 < 0x3d; DAT_5b41_1d20 = DAT_5b41_1d20 + 1) {
      FUN_1a9e_1391(DAT_5b41_1d26 - DAT_5b41_1d20);
    }
    FUN_1a9e_1391(DAT_5b41_1d26);
    DAT_5b41_1d4e = 1;
  }
  while( true ) {
    if (DAT_5b41_1d1e == 0) {
      if (DAT_5b41_1d24 < DAT_5b41_1d5e) {
        DAT_5b41_1d5e = DAT_5b41_1d24;
      }
      if (DAT_5b41_1d5e < 3) {
        DAT_5b41_1d5e = 1;
        FUN_1a9e_1c03(*(undefined1 *)((int)_DAT_5b41_1d62 + DAT_5b41_1d26));
      }
      else {
        FUN_1a9e_1c03(DAT_5b41_1d5e + 0xfd);
        FUN_1a9e_1c69(DAT_5b41_1d60);
      }
      DAT_5b41_1d2a = DAT_5b41_1d5e;
      DAT_5b41_1d20 = 0;
    }
    DAT_5b41_1d1e = 0;
    while ((DAT_5b41_1d20 < DAT_5b41_1d2a && (local_6 != uVar4))) {
      _DAT_5b41_1d22 = (uint)*(byte *)(local_6 + iVar2);
      local_6 = (local_6 + 1) % 0x80;
      FUN_1a9e_15b9(DAT_5b41_1d28);
      uVar5 = (undefined2)((ulong)_DAT_5b41_1d62 >> 0x10);
      uVar3 = DAT_5b41_1d22;
      *(undefined1 *)((int)_DAT_5b41_1d62 + DAT_5b41_1d28) = DAT_5b41_1d22;
      if ((int)DAT_5b41_1d28 < 0x3b) {
        *(undefined1 *)(DAT_5b41_1d28 + DAT_5b41_1d62 + 0x1000) = uVar3;
      }
      DAT_5b41_1d28 = DAT_5b41_1d28 + 1 & 0xfff;
      DAT_5b41_1d26 = DAT_5b41_1d26 + 1 & 0xfff;
      FUN_1a9e_1391(DAT_5b41_1d26);
      DAT_5b41_1d20 = DAT_5b41_1d20 + 1;
    }
    if ((local_6 == uVar4) && (param_1 == 0)) break;
    while (iVar1 = DAT_5b41_1d20 + 1, DAT_5b41_1d20 < DAT_5b41_1d2a) {
      DAT_5b41_1d20 = iVar1;
      FUN_1a9e_15b9(DAT_5b41_1d28);
      DAT_5b41_1d28 = DAT_5b41_1d28 + 1 & 0xfff;
      DAT_5b41_1d26 = DAT_5b41_1d26 + 1 & 0xfff;
      DAT_5b41_1d24 = DAT_5b41_1d24 + -1;
      if (DAT_5b41_1d24 != 0) {
        FUN_1a9e_1391(DAT_5b41_1d26);
      }
    }
    DAT_5b41_1d20 = iVar1;
    if (DAT_5b41_1d24 < 1) {
      FUN_1a9e_1ca9();
      *(undefined1 *)(DAT_5b41_0042 + 0x1b) = (undefined1)local_6;
      return 0;
    }
  }
  DAT_5b41_1d1e = 1;
  *(undefined1 *)(DAT_5b41_0042 + 0x1b) = (undefined1)local_6;
  return 0;
}

