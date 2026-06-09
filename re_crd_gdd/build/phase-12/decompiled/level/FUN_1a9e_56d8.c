// TIM2.EXE: FUN_1a9e_56d8 @ file 0x0252B8 Ghidra 0x200B8
// Subsystem: level | Size: 26 bytes


byte __cdecl16far FUN_1a9e_56d8(byte param_1)

{
  byte bVar1;
  
  bVar1 = in(0x201);
  return bVar1 >> (param_1 & 3) + 4 & 1 ^ 1;
}

