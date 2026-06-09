// TIM2.EXE: FUN_31f7_5efc @ file 0x03D06C Ghidra 0x37E6C
// Subsystem: misc | Size: 49 bytes


bool __cdecl16far FUN_31f7_5efc(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  return (int)((undefined2 *)&DAT_5b41_1a0e)[DAT_5b41_1a12 <= *(int *)((int)param_1 + 0x10)] <=
         *(int *)((int)param_1 + 0x10);
}

