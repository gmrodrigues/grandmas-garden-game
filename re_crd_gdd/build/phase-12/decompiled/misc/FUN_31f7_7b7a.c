// TIM2.EXE: FUN_31f7_7b7a @ file 0x03ECEA Ghidra 0x39AEA
// Subsystem: misc | Size: 35 bytes


undefined2 __cdecl16far FUN_31f7_7b7a(undefined4 param_1)

{
  undefined2 uVar1;
  
  if (*(int *)((int)param_1 + 0x3e) < 0x97) {
    uVar1 = 0x600;
  }
  else {
    uVar1 = 0x400;
  }
  return uVar1;
}

