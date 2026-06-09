// TIM2.EXE: FUN_1000_9cb9 @ file 0x01EEB9 Ghidra 0x19CB9
// Subsystem: utility | Size: 89 bytes


undefined2 FUN_1000_9cb9(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined2 uVar1;
  
  if ((((((DAT_554c_5e54 < param_4) || (DAT_554c_5e54 < param_2)) || ((int)param_2 < (int)param_4))
       || ((DAT_554c_5e53 < param_3 || (DAT_554c_5e53 < param_1)))) ||
      (((int)param_1 < (int)param_3 || (((int)param_4 < 1 || ((int)param_2 < 1)))))) ||
     (((int)param_3 < 1 || ((int)param_1 < 1)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

