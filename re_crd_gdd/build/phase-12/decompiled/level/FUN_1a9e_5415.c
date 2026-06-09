// TIM2.EXE: FUN_1a9e_5415 @ file 0x024FF5 Ghidra 0x1FDF5
// Subsystem: level | Size: 23 bytes


void __cdecl16far FUN_1a9e_5415(int param_1,int param_2)

{
  code *pcVar1;
  
  if (param_1 != 0 || param_2 != 0) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  return;
}

