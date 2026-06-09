// TIM2.EXE: FUN_31f7_8562 @ file 0x03F6D2 Ghidra 0x3A4D2
// Subsystem: misc | Size: 108 bytes


undefined2 __cdecl16far
FUN_31f7_8562(undefined4 param_1,undefined4 param_2,undefined2 param_3,int param_4,
             undefined2 param_5,uint param_6,int param_7)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar5 = (undefined2)((ulong)param_2 >> 0x10);
  iVar4 = (int)param_2;
  if (param_4 == 1) {
    piVar1 = (int *)(*(int *)(iVar4 + 0x76) + 0x18);
    *piVar1 = *piVar1 + 1;
    uVar5 = 0;
  }
  else {
    uVar6 = (undefined2)((ulong)param_1 >> 0x10);
    if ((*(int *)((int)param_1 + 8) == 3) || (*(int *)((int)param_1 + 8) == 0x8b)) {
      iVar3 = *(int *)(iVar4 + 0x42);
      uVar2 = *(uint *)(iVar4 + 0x40);
    }
    else {
      uVar2 = *(uint *)(iVar4 + 0x40) + *(uint *)(iVar4 + 0x40);
      iVar3 = *(int *)(iVar4 + 0x42) + *(int *)(iVar4 + 0x42) +
              (uint)CARRY2(*(uint *)(iVar4 + 0x40),*(uint *)(iVar4 + 0x40));
    }
    if ((iVar3 < param_7) || ((iVar3 <= param_7 && (uVar2 <= param_6)))) {
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
  }
  return uVar5;
}

