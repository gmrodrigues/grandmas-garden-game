// TIM2.EXE: FUN_2e67_0093 @ file 0x033903 Ghidra 0x2E703
// Subsystem: misc | Size: 106 bytes


void __cdecl16far
FUN_2e67_0093(undefined4 param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  FUN_4340_08dd(*(undefined2 *)((int)param_1 + 2));
  DAT_554c_42c2 = 1;
  DAT_554c_42c0 = 0xe;
  FUN_1a9e_51b3(param_2,param_3,param_4 + -1,param_5 + -1);
  DAT_554c_42c0 = 0xf;
  FUN_1a9e_51b3(param_2,param_3,param_4 + 1,param_5 + 1);
  DAT_554c_42c0 = *(undefined1 *)((int)param_1 + 0xe);
  FUN_1a9e_51b3(param_2,param_3,param_4,param_5);
  return;
}

