// TIM2.EXE: FUN_1000_6315 @ file 0x01B515 Ghidra 0x16315
// Subsystem: utility | Size: 51 bytes


void __cdecl16far FUN_1000_6315(int param_1)

{
  uint *puVar1;
  undefined2 unaff_SS;
  
  if (*(int *)((int)*(undefined4 *)0x16 + 0x1c) == param_1) {
    puVar1 = (uint *)((int)*(undefined4 *)0x16 + 4);
    *puVar1 = *puVar1 & 0xfffe;
  }
  else {
    FUN_1000_3157(param_1,0x554c);
  }
  return;
}

