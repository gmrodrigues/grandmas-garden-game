// TIM2.EXE: FUN_1a9e_5f12 @ file 0x025AF2 Ghidra 0x208F2
// Subsystem: level | Size: 24 bytes


char __cdecl16far FUN_1a9e_5f12(void)

{
  char cVar1;
  
  cVar1 = DAT_554c_559e;
  if (DAT_554c_559e != -1) {
    FUN_1a9e_60a1();
    DAT_554c_559e = -1;
  }
  return cVar1;
}

