// TIM2.EXE: FUN_50fb_00d9 @ file 0x056289 Ghidra 0x51089
// Subsystem: misc | Size: 156 bytes


int * __cdecl16far FUN_50fb_00d9(int *param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 local_22;
  
  FUN_1000_27ad();
  if (param_1 == (int *)0x0) {
    param_1 = (int *)FUN_1000_1dd2(2);
    if (param_1 == (int *)0x0) goto LAB_50fb_0159;
  }
  iVar5 = FUN_1000_1dd2(10);
  if (iVar5 != 0) {
    if (param_2 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_1000_54d4(param_2,0,0,0);
    }
    FUN_50fb_0516(iVar5,param_2,uVar6);
    piVar1 = (int *)0x10;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    *(int *)0x12 = *(int *)0x12 - (uint)(iVar3 == 0);
  }
  *param_1 = iVar5;
LAB_50fb_0159:
  puVar2 = (uint *)0x10;
  uVar4 = *puVar2;
  *puVar2 = *puVar2 + 1;
  *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar4);
  *(undefined2 *)0x14 = local_22;
  return param_1;
}

