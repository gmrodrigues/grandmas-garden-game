// TIM2.EXE: FUN_406b_0c62 @ file 0x046512 Ghidra 0x41312
// Subsystem: sound | Size: 64 bytes


undefined2 __cdecl16far FUN_406b_0c62(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((((param_1 < 0) || (param_2 < 0)) || (DAT_554c_49aa <= param_1)) ||
     (DAT_554c_49ac + DAT_554c_3e4a <= param_2)) {
    uVar1 = 0;
  }
  else {
    FUN_1a9e_5a40(param_1,param_2);
    FUN_406b_111b(0);
    uVar1 = 1;
  }
  return uVar1;
}

