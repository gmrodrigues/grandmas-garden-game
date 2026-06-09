// TIM2.EXE: FUN_50fb_05cb @ file 0x05677B Ghidra 0x5157B
// Subsystem: misc | Size: 77 bytes


void __cdecl16far FUN_50fb_05cb(int param_1,byte param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  piVar1 = (int *)0x10;
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  *(int *)0x12 = *(int *)0x12 - (uint)(iVar2 == 0);
  if (param_1 != 0) {
    FUN_1000_3157(*(undefined2 *)(param_1 + 2));
    if ((param_2 & 1) != 0) {
      FUN_1000_1499(param_1);
    }
  }
  *(undefined2 *)0x14 = local_20;
  return;
}

