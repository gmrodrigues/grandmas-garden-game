// TIM2.EXE: FUN_1000_5ced @ file 0x01AEED Ghidra 0x15CED
// Subsystem: utility | Size: 70 bytes


void __cdecl16far FUN_1000_5ced(undefined2 *param_1,byte param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined2 unaff_SS;
  
  piVar1 = (int *)0x10;
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  *(int *)0x12 = *(int *)0x12 - (uint)(iVar3 == 0);
  if (param_1 != (undefined2 *)0x0) {
    puVar2 = (uint *)0x10;
    uVar4 = *puVar2;
    *puVar2 = *puVar2 + 1;
    *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar4);
    FUN_50fb_02c8(*param_1,3);
    if ((param_2 & 1) != 0) {
      FUN_1000_1499(param_1);
    }
  }
  return;
}

