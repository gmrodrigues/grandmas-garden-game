// TIM2.EXE: FUN_4340_1f26 @ file 0x04A526 Ghidra 0x45326
// Subsystem: misc | Size: 52 bytes


void __cdecl16far
FUN_4340_1f26(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  FUN_4340_08dd(*(undefined2 *)((int)param_1 + 2));
  DAT_554c_42c0 = *(undefined1 *)((int)param_1 + 0xe);
  DAT_554c_42c2 = 1;
  FUN_1a9e_51b3(param_2,param_3,param_4,param_5);
  return;
}

