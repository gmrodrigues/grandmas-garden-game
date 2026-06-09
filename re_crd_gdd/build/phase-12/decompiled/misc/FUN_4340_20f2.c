// TIM2.EXE: FUN_4340_20f2 @ file 0x04A6F2 Ghidra 0x454F2
// Subsystem: misc | Size: 32 bytes


undefined2 __cdecl16far FUN_4340_20f2(undefined4 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if (param_2 == 0 && param_3 == 0) {
    return 0;
  }
  uVar1 = FUN_4340_09cc(*(undefined2 *)((int)param_1 + 2));
  return uVar1;
}

