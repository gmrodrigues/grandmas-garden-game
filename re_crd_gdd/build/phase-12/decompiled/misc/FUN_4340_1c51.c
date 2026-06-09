// TIM2.EXE: FUN_4340_1c51 @ file 0x04A251 Ghidra 0x45051
// Subsystem: misc | Size: 122 bytes


undefined2 __cdecl16far FUN_4340_1c51(undefined4 param_1)

{
  undefined1 local_16 [8];
  undefined2 local_e;
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  if (((int)param_1 != 0 || param_1._2_2_ != 0) &&
     (*(int *)((int)param_1 + 0x10) != 0 || *(int *)((int)param_1 + 0x12) != 0)) {
    local_8 = *(undefined2 *)((int)param_1 + 0xc);
    *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 2;
    local_4 = *(undefined2 *)((int)param_1 + 10);
    *(undefined2 *)((int)param_1 + 10) = 0x7fff;
    FUN_4340_10fe((int)param_1,param_1._2_2_,local_16);
    local_6 = local_e;
    *(undefined2 *)((int)param_1 + 10) = local_4;
    *(undefined2 *)((int)param_1 + 0xc) = local_8;
    FUN_4340_10fe((int)param_1,param_1._2_2_,0,0,1);
    return local_6;
  }
  return 0;
}

