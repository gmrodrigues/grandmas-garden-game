// TIM2.EXE: FUN_1a9e_0131 @ file 0x01FD11 Ghidra 0x1AB11
// Subsystem: utility | Size: 89 bytes


uint __cdecl16near FUN_1a9e_0131(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  undefined2 uVar5;
  
  iVar2 = DAT_5b41_0042;
  if ((*(int *)(DAT_5b41_0042 + 0xc) == *(int *)(DAT_5b41_0042 + 0x10)) &&
     (*(int *)(DAT_5b41_0042 + 10) == *(int *)(DAT_5b41_0042 + 0xe))) {
    return 0xffff;
  }
  puVar1 = (uint *)(DAT_5b41_0042 + 10);
  uVar3 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + (uint)(0xfffe < uVar3);
  if ((DAT_5b41_02ea & 0x20) != 0) {
    uVar3 = FUN_1000_0fdc(DAT_5b41_0047);
    return uVar3;
  }
  uVar5 = 0;
  pbVar4 = (byte *)FUN_1000_1ae8();
  return (uint)*pbVar4;
}

