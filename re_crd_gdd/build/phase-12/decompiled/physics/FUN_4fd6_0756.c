// TIM2.EXE: FUN_4fd6_0756 @ file 0x0556B6 Ghidra 0x504B6
// Subsystem: physics | Size: 12 bytes


void __cdecl16near FUN_4fd6_0756(void)

{
  undefined2 in_CX;
  int in_BX;
  undefined2 unaff_SS;
  
  FUN_4fd6_0762();
  if (in_BX != 0) {
    LOCK();
    *(undefined2 *)(in_BX + 2) = in_CX;
    UNLOCK();
  }
  return;
}

