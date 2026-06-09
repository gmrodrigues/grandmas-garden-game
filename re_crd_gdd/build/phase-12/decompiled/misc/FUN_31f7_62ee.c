// TIM2.EXE: FUN_31f7_62ee @ file 0x03D45E Ghidra 0x3825E
// Subsystem: misc | Size: 116 bytes


undefined2 __cdecl16far FUN_31f7_62ee(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0xa2);
  if ((*(byte *)(*(int *)(iVar2 + 0x9a) + 0xc) & 0x10) != 0) {
    iVar1 = (*(int *)(iRam00055828 + 0x22) - iVar1) + -2;
    if (iVar1 < 0) {
      iVar1 = iVar1 + *(int *)(iRam00055828 + 0x22);
    }
  }
  if ((*(int *)(*(int *)(iVar2 + 0x9a) + 0x16) == 0) ||
     ((iVar1 != 5 && (*(int *)(iVar2 + 0xa0) != -0x8000)))) {
    uVar3 = 1;
  }
  else {
    FUN_31f7_66af(iVar2,uVar3);
    uVar3 = 0;
  }
  return uVar3;
}

