// TIM2.EXE: FUN_1a9e_1cc3 @ file 0x0218A3 Ghidra 0x1C6A3
// Subsystem: level | Size: 55 bytes


int __cdecl16near FUN_1a9e_1cc3(void)

{
  int iVar1;
  uint uVar2;
  
  for (uVar2 = *(uint *)((int)DAT_5b41_1d42 + 0x4e4); uVar2 < 0x273;
      uVar2 = *(uint *)((int)DAT_5b41_1d42 + (uVar2 + iVar1) * 2)) {
    iVar1 = FUN_1a9e_177b();
  }
  FUN_1a9e_1ae7(uVar2 - 0x273);
  return uVar2 - 0x273;
}

