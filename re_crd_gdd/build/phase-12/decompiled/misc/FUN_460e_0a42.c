// TIM2.EXE: FUN_460e_0a42 @ file 0x04BD22 Ghidra 0x46B22
// Subsystem: misc | Size: 97 bytes


int __cdecl16far FUN_460e_0a42(int param_1)

{
  int iVar1;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  local_6 = DAT_5b41_1bff;
  local_8 = 0;
  local_a = 0;
  iVar1 = DAT_5b41_1c0b;
  while ((iVar1 != 0 && (local_a == 0 && local_8 == 0))) {
    if (*(int *)(local_6 + 4) == param_1) {
      local_8 = DAT_5b41_1c01;
      local_a = local_6;
    }
    local_6 = local_6 + 8;
    iVar1 = iVar1 + -1;
  }
  return local_a;
}

