// TIM2.EXE: FUN_1a9e_036b @ file 0x01FF4B Ghidra 0x1AD4B
// Subsystem: utility | Size: 82 bytes


int __cdecl16near FUN_1a9e_036b(undefined2 param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined2 uVar5;
  
  iVar3 = DAT_5b41_0042;
  DAT_5b41_02e5 = DAT_5b41_02e5 + 1;
  if ((DAT_5b41_02ea & 0x20) == 0) {
    puVar1 = (uint *)(DAT_5b41_0042 + 10);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + 1;
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + (uint)(0xfffe < uVar2);
    uVar5 = *(undefined2 *)(DAT_5b41_0042 + 8);
    pcVar4 = (char *)FUN_1000_1a88();
    *pcVar4 = (char)param_1;
    iVar3 = (int)(char)param_1;
  }
  else {
    iVar3 = FUN_1000_1135(param_1,DAT_5b41_0047);
  }
  return iVar3;
}

