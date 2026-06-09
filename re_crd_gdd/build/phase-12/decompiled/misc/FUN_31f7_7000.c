// TIM2.EXE: FUN_31f7_7000 @ file 0x03E170 Ghidra 0x38F70
// Subsystem: misc | Size: 36 bytes


void __cdecl16far FUN_31f7_7000(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  *(undefined2 *)((int)param_1 + 0x98) = *(undefined2 *)*(undefined2 *)(iRam00055830 + 0x46);
  FUN_28eb_3670((int)param_1,uVar1);
  return;
}

