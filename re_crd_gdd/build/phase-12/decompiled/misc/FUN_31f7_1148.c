// TIM2.EXE: FUN_31f7_1148 @ file 0x0382B8 Ghidra 0x330B8
// Subsystem: misc | Size: 32 bytes


undefined2 __cdecl16far FUN_31f7_1148(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  if ((*(int *)((int)param_1 + 0x10) < DAT_5b41_1976) && (*(int *)((int)param_1 + 0x10) != 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

