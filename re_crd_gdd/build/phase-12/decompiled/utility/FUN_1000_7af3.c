// TIM2.EXE: FUN_1000_7af3 @ file 0x01CCF3 Ghidra 0x17AF3
// Subsystem: utility | Size: 42 bytes


void __cdecl16far FUN_1000_7af3(void)

{
  undefined2 *puVar1;
  undefined2 unaff_SS;
  
  puVar1 = (undefined2 *)*(undefined2 *)0x14;
  FUN_1000_7920(puVar1,0);
  *(undefined2 *)0x14 = *puVar1;
  return;
}

