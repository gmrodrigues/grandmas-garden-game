// TIM2.EXE: FUN_50fb_02c8 @ file 0x056478 Ghidra 0x51278
// Subsystem: misc | Size: 106 bytes


void __cdecl16far FUN_50fb_02c8(undefined2 *param_1,byte param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  piVar1 = (int *)0x10;
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  *(int *)0x12 = *(int *)0x12 - (uint)(iVar3 == 0);
  if (param_1 != (undefined2 *)0x0) {
    piVar5 = (int *)*param_1;
    piVar1 = piVar5;
    *piVar1 = *piVar1 + -1;
    if (*piVar5 == 0) {
      puVar2 = (uint *)0x10;
      uVar4 = *puVar2;
      *puVar2 = *puVar2 + 1;
      *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar4);
      FUN_50fb_05cb(*param_1,3);
    }
    if ((param_2 & 1) != 0) {
      FUN_1000_1499(param_1);
    }
  }
  *(undefined2 *)0x14 = local_20;
  return;
}

