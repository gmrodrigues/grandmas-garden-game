// TIM2.EXE: FUN_1000_2934 @ file 0x017B34 Ghidra 0x12934
// Subsystem: utility | Size: 66 bytes


void __cdecl16far FUN_1000_2934(void)

{
  undefined2 *puVar1;
  undefined2 unaff_SS;
  
  if (*(int *)((int)*(undefined4 *)0x16 + 0x14) == 0) {
    *(undefined2 *)((int)*(undefined4 *)0x16 + 0x14) = 0x554c;
  }
  puVar1 = (undefined2 *)((int)*(undefined4 *)0x16 + 0xe);
  (*(code *)*puVar1)(0x1000,0x554c);
  FUN_1000_143a();
  return;
}

