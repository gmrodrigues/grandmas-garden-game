// TIM2.EXE: FUN_4340_20be @ file 0x04A6BE Ghidra 0x454BE
// Subsystem: misc | Size: 52 bytes


undefined2 __cdecl16far FUN_4340_20be(undefined4 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  
  if (param_2 == 0 && param_3 == 0) {
    return 0;
  }
  FUN_4340_08dd(*(undefined2 *)((int)param_1 + 2));
  uVar1 = FUN_1a9e_4ea4(param_2,param_3);
  return uVar1;
}

