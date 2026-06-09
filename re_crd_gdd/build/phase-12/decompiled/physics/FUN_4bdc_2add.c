// TIM2.EXE: FUN_4bdc_2add @ file 0x053A9D Ghidra 0x4E89D
// Subsystem: physics | Size: 67 bytes


void __cdecl16far FUN_4bdc_2add(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  while (iVar1 = (int)param_1, iVar2 = param_1._2_2_, (int)param_1 != 0 || param_1._2_2_ != 0) {
    param_1 = CONCAT22(*(undefined2 *)((int)param_1 + 6),*(undefined2 *)((int)param_1 + 4));
    FUN_2e67_10e9(iVar1,iVar2,9);
  }
  return;
}

