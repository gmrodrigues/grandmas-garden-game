// TIM2.EXE: FUN_28eb_3783 @ file 0x031833 Ghidra 0x2C633
// Subsystem: misc | Size: 56 bytes


undefined2 __cdecl16far FUN_28eb_3783(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = (int)((ulong)param_1 >> 0x10);
  iVar1 = *(int *)((int)param_1 + 0x58);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if ((*(int *)(iVar1 + 8) == iVar3) && (*(int *)(iVar1 + 6) == (int)param_1)) {
    uVar2 = *(undefined2 *)(iVar1 + 10);
  }
  else {
    uVar2 = *(undefined2 *)(iVar1 + 6);
  }
  return uVar2;
}

