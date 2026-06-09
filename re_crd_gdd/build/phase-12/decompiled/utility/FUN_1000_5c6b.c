// TIM2.EXE: FUN_1000_5c6b @ file 0x01AE6B Ghidra 0x15C6B
// Subsystem: utility | Size: 130 bytes


int * __cdecl16far FUN_1000_5c6b(int *param_1,undefined2 *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 local_22;
  
  FUN_1000_27ad();
  if (param_1 == (int *)0x0) {
    param_1 = (int *)FUN_1000_1dd2(2);
    if (param_1 == (int *)0x0) goto LAB_1000_5cd1;
  }
  iVar5 = FUN_1000_1dd2(2);
  if (iVar5 != 0) {
    FUN_50fb_000b(iVar5,*param_2);
    piVar1 = (int *)0x10;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    *(int *)0x12 = *(int *)0x12 - (uint)(iVar3 == 0);
  }
  *param_1 = iVar5;
LAB_1000_5cd1:
  puVar2 = (uint *)0x10;
  uVar4 = *puVar2;
  *puVar2 = *puVar2 + 1;
  *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar4);
  *(undefined2 *)0x14 = local_22;
  return param_1;
}

