// TIM2.EXE: FUN_4876_082a @ file 0x04E18A Ghidra 0x48F8A
// Subsystem: misc | Size: 20 bytes


void __cdecl16far FUN_4876_082a(undefined4 param_1)

{
  uint *puVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  if (*(int *)((int)param_1 + 0xe) == 2) {
    puVar1 = (uint *)((int)param_1 + 0x24);
    *puVar1 = *puVar1 | 1;
  }
  return;
}

