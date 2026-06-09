// TIM2.EXE: FUN_460e_18af @ file 0x04CB8F Ghidra 0x4798F
// Subsystem: misc | Size: 155 bytes


undefined2 __cdecl16far FUN_460e_18af(uint param_1,undefined2 param_2)

{
  int *piVar1;
  undefined2 uVar2;
  int in_DX;
  undefined4 local_a;
  undefined2 local_6;
  undefined2 uStack_4;
  
  uVar2 = FUN_460e_0f42(0,0,0x10);
  local_6 = FUN_460e_141e(uVar2,in_DX);
  local_a = 0;
  uStack_4 = in_DX;
  while (local_6 != 0 || uStack_4 != 0) {
    if ((param_1 <= *(uint *)(local_6 + 0x10)) &&
       (((int)local_a == 0 && local_a._2_2_ == 0 ||
        (*(uint *)((int)local_a + 0x10) < *(uint *)(local_6 + 0x10))))) {
      local_a = CONCAT22(uStack_4,local_6);
    }
    piVar1 = (int *)(local_6 + 10);
    local_6 = *(int *)(local_6 + 8);
    uStack_4 = *piVar1;
  }
  if ((int)local_a == 0 && local_a._2_2_ == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_460e_174c(*(undefined2 *)((int)local_a + 0xc),0,0,param_2);
  }
  return uVar2;
}

