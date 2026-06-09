// TIM2.EXE: FUN_1000_9bad @ file 0x01EDAD Ghidra 0x19BAD
// Subsystem: utility | Size: 206 bytes


void FUN_1000_9bad(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  bool bVar1;
  bool bVar2;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_a = FUN_1000_a02d();
  bVar1 = param_3._2_2_ == DAT_554c_5e59;
  if (bVar1) {
    local_6 = FUN_1000_9b3f((undefined2 *)param_3,param_3._2_2_);
  }
  bVar2 = param_2._2_2_ == DAT_554c_5e59;
  if (bVar2) {
    local_8 = FUN_1000_9b3f((undefined2 *)param_2,param_2._2_2_);
  }
  while (param_1 != 0) {
    if (bVar2) {
      FUN_1000_9b79(&local_a,&local_8);
      local_4 = FUN_1000_913e();
    }
    else {
      local_4 = *param_2;
      param_2 = (undefined2 *)CONCAT22(param_2._2_2_,(undefined2 *)param_2 + 1);
    }
    if (bVar1) {
      FUN_1000_9b79(&local_a,&local_6);
      FUN_1000_913e();
      param_1 = param_1 + -1;
    }
    else {
      *param_3 = local_4;
      param_3 = (undefined2 *)CONCAT22(param_3._2_2_,(undefined2 *)param_3 + 1);
      param_1 = param_1 + -1;
    }
  }
  FUN_1000_913e();
  return;
}

