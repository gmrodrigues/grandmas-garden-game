// TIM2.EXE: FUN_31f7_85ce @ file 0x03F73E Ghidra 0x3A53E
// Subsystem: misc | Size: 102 bytes


undefined2 __cdecl16far FUN_31f7_85ce(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar4 + 0x9c);
  iVar2 = *(int *)(iVar4 + 0x9a);
  if (*(int *)(iVar2 + 0x10) == 0) {
    iVar3 = *(int *)(iVar4 + 0xa2);
    if ((*(byte *)(iVar2 + 0xc) & 0x10) != 0) {
      iVar3 = (*(int *)(DAT_554c_0394 + 0x22) - iVar3) + -2;
      if (iVar3 < 0) {
        iVar3 = iVar3 + *(int *)(DAT_554c_0394 + 0x22);
      }
    }
    if ((iVar3 == 0) && (100 < *(int *)(iVar4 + 0x3e))) {
      *(undefined2 *)(iVar2 + 0x16) = 1;
    }
  }
  return 1;
}

