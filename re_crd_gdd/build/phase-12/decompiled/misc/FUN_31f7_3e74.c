// TIM2.EXE: FUN_31f7_3e74 @ file 0x03AFE4 Ghidra 0x35DE4
// Subsystem: misc | Size: 22 bytes


undefined2 __cdecl16far FUN_31f7_3e74(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)((int)param_1 + 0x9a);
  *(undefined2 *)((int)uVar1 + 0x16) = 1;
  return 1;
}

