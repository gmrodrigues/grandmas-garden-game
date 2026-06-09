// TIM2.EXE: FUN_31f7_0bb3 @ file 0x037D23 Ghidra 0x32B23
// Subsystem: misc | Size: 65 bytes


undefined2 __cdecl16far FUN_31f7_0bb3(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if ((int)param_1 != 0 || param_1._2_2_ != 0) {
    uVar2 = FUN_1000_12bf(1,0x3e);
    *(undefined2 *)((int)param_1 + 0x58) = uVar2;
    if (*(int *)((int)param_1 + 0x58) == 0) {
      return 0;
    }
    iVar1 = *(int *)((int)param_1 + 0x58);
    *(int *)(iVar1 + 4) = param_1._2_2_;
    *(int *)(iVar1 + 2) = (int)param_1;
  }
  return 1;
}

