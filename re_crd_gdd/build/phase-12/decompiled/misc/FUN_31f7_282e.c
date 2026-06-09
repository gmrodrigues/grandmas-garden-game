// TIM2.EXE: FUN_31f7_282e @ file 0x03999E Ghidra 0x3479E
// Subsystem: misc | Size: 150 bytes


undefined2 __cdecl16far FUN_31f7_282e(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar3 + 0x9c);
  iVar2 = *(int *)(iVar3 + 0x9a);
  uVar4 = *(int *)(iVar3 + 0xa0) + 0x4000;
  if (*(int *)(iVar2 + 0x10) < 4) {
    if ((uVar4 & 0x8000) != 0) goto LAB_31f7_2892;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 4;
  }
  else {
    if ((uVar4 & 0x8000) == 0) goto LAB_31f7_2892;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -4;
  }
  FUN_31f7_28c4(iVar2,uVar1);
  FUN_2e67_045f(0xbcd,0,1,1);
LAB_31f7_2892:
  if (*(int *)(iVar2 + 0x10) == *(int *)(iVar2 + 0xa8)) {
    *(undefined2 *)(iVar2 + 0x16) = 0;
  }
  else {
    *(undefined2 *)(iVar2 + 0x16) = 1;
  }
  if (*(int *)(iVar3 + 8) == 0x14) {
    *(int *)(iVar3 + 0x3a) = *(int *)(iVar3 + 0x3a) + -1;
  }
  return 0;
}

