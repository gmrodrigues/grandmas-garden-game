// TIM2.EXE: FUN_31f7_119d @ file 0x03830D Ghidra 0x3310D
// Subsystem: misc | Size: 59 bytes


void __cdecl16far FUN_31f7_119d(undefined4 param_1,int param_2)

{
  if (param_2 == 2) {
    *(undefined2 *)((int)param_1 + 0x10) = 1;
  }
  else {
    *(undefined2 *)((int)param_1 + 0x10) = 0;
  }
  FUN_2424_2e7d((int)param_1,param_1._2_2_,param_2);
  *(undefined2 *)((int)param_1 + 0x10) = 0;
  return;
}

