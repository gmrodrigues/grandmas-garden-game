// TIM2.EXE: FUN_1a9e_5a16 @ file 0x0255F6 Ghidra 0x203F6
// Subsystem: level | Size: 42 bytes


uint __cdecl16far FUN_1a9e_5a16(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = -(uint)DAT_554c_5594;
  if (DAT_554c_5594 != 0) {
    *param_1 = DAT_554c_5178 >> 2;
    uVar1 = DAT_554c_517a >> 2;
    *param_2 = uVar1;
  }
  return uVar1;
}

