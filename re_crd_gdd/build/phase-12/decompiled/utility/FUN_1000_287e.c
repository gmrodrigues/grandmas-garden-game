// TIM2.EXE: FUN_1000_287e @ file 0x017A7E Ghidra 0x1287E
// Subsystem: utility | Size: 101 bytes


void __cdecl16far FUN_1000_287e(void)

{
  undefined2 *puVar1;
  undefined2 unaff_SS;
  undefined2 local_20;
  
  FUN_1000_27ad();
  FUN_1000_3f88();
  if (*(int *)((int)*(undefined4 *)0x16 + 0x12) == 0) {
    *(undefined2 *)((int)*(undefined4 *)0x16 + 0x12) = 0x554c;
  }
  puVar1 = (undefined2 *)((int)*(undefined4 *)0x16 + 10);
  (*(code *)*puVar1)(0x1000,0x554c);
  FUN_1000_143a();
  *(undefined2 *)0x14 = local_20;
  return;
}

