// TIM2.EXE: FUN_1a9e_1f9b @ file 0x021B7B Ghidra 0x1C97B
// Subsystem: level | Size: 372 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16near FUN_1a9e_1f9b(void)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  uint local_4;
  
  if (DAT_5b41_1d50 == 0) {
    DAT_5b41_1d2c = 0;
    FUN_1a9e_186c();
    for (DAT_5b41_1d2e = 0; (int)DAT_5b41_1d2e < 0xfc4; DAT_5b41_1d2e = DAT_5b41_1d2e + 1) {
      *(undefined1 *)((int)_DAT_5b41_1d62 + DAT_5b41_1d2e) = 0x20;
    }
    DAT_5b41_1d34 = 0xfc4;
    DAT_5b41_1d38 = 0;
    DAT_5b41_1d36 = 0;
    DAT_5b41_1d3c = *(int *)(DAT_5b41_0042 + 0x14);
    DAT_5b41_1d3a = *(uint *)(DAT_5b41_0042 + 0x12);
    DAT_5b41_1d50 = 1;
  }
  while ((DAT_5b41_1d38 < DAT_5b41_1d3c ||
         ((DAT_5b41_1d38 == DAT_5b41_1d3c && (DAT_5b41_1d36 < DAT_5b41_1d3a))))) {
    if ((DAT_5b41_1d2c == 0) && (local_4 = FUN_1a9e_1cc3(), (int)local_4 < 0x100)) {
      iVar2 = FUN_1a9e_031d(local_4);
      *(undefined1 *)((int)_DAT_5b41_1d62 + DAT_5b41_1d34) = (undefined1)local_4;
      DAT_5b41_1d34 = DAT_5b41_1d34 + 1 & 0xfff;
      bVar3 = 0xfffe < DAT_5b41_1d36;
      DAT_5b41_1d36 = DAT_5b41_1d36 + 1;
      DAT_5b41_1d38 = DAT_5b41_1d38 + (uint)bVar3;
      if (iVar2 == 0) {
        return 0;
      }
    }
    if ((0xff < (int)local_4) || (DAT_5b41_1d2c != 0)) {
      if (DAT_5b41_1d2c == 0) {
        iVar2 = FUN_1a9e_1cfa();
        DAT_5b41_1d2e = (DAT_5b41_1d34 - iVar2) - 1 & 0xfff;
        DAT_5b41_1d30 = local_4 - 0xfd;
        DAT_5b41_1d32 = 0;
      }
      DAT_5b41_1d2c = 0;
      while (DAT_5b41_1d32 < DAT_5b41_1d30) {
        bVar1 = *(byte *)((int)_DAT_5b41_1d62 + (DAT_5b41_1d2e + DAT_5b41_1d32 & 0xfff));
        local_4 = (uint)bVar1;
        iVar2 = FUN_1a9e_031d(local_4);
        *(byte *)((int)_DAT_5b41_1d62 + DAT_5b41_1d34) = bVar1;
        DAT_5b41_1d34 = DAT_5b41_1d34 + 1 & 0xfff;
        bVar3 = 0xfffe < DAT_5b41_1d36;
        DAT_5b41_1d36 = DAT_5b41_1d36 + 1;
        DAT_5b41_1d38 = DAT_5b41_1d38 + (uint)bVar3;
        DAT_5b41_1d32 = DAT_5b41_1d32 + 1;
        if (iVar2 == 0) {
          DAT_5b41_1d2c = 1;
          return 0;
        }
      }
    }
  }
  return 0;
}

