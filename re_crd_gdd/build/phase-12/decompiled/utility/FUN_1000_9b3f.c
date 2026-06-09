// TIM2.EXE: FUN_1000_9b3f @ file 0x01ED3F Ghidra 0x19B3F
// Subsystem: utility | Size: 58 bytes


undefined2 FUN_1000_9b3f(uint param_1)

{
  char cVar1;
  
  cVar1 = (char)((param_1 >> 1) / (uint)DAT_554c_5e54);
  return CONCAT11(cVar1,(char)(param_1 >> 1) - cVar1 * DAT_554c_5e54);
}

