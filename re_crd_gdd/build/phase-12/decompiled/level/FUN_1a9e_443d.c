// TIM2.EXE: FUN_1a9e_443d @ file 0x02401D Ghidra 0x1EE1D
// Subsystem: level | Size: 39 bytes


int __cdecl16far FUN_1a9e_443d(void)

{
  if ((DAT_f000_fffe == -1) && (DAT_f000_c000 == '!')) {
    DAT_554c_42dc = '\x01';
  }
  return (int)DAT_554c_42dc;
}

