// TIM2.EXE: FUN_1a9e_1cfa @ file 0x0218DA Ghidra 0x1C6DA
// Subsystem: level | Size: 75 bytes


uint __cdecl16near FUN_1a9e_1cfa(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = FUN_1a9e_17c7();
  bVar1 = *(byte *)(uVar2 + 0x40b2);
  iVar4 = *(byte *)(uVar2 + 0x41b2) - 2;
  while (iVar4 != 0) {
    iVar3 = FUN_1a9e_177b();
    uVar2 = uVar2 * 2 + iVar3;
    iVar4 = iVar4 + -1;
  }
  return (uint)bVar1 << 6 | uVar2 & 0x3f;
}

