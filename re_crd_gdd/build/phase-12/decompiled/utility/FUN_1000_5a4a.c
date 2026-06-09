// TIM2.EXE: FUN_1000_5a4a @ file 0x01AC4A Ghidra 0x15A4A
// Subsystem: utility | Size: 49 bytes


int __cdecl16far FUN_1000_5a4a(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined2 unaff_SS;
  
  FUN_1000_5c6b(param_1,param_2);
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  puVar1 = (uint *)0x10;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)0x12 = *(int *)0x12 + (uint)(0xfffe < uVar2);
  return param_1;
}

