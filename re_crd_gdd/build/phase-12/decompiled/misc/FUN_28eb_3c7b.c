// TIM2.EXE: FUN_28eb_3c7b @ file 0x031D2B Ghidra 0x2CB2B
// Subsystem: misc | Size: 84 bytes


void __cdecl16far FUN_28eb_3c7b(undefined4 param_1,char param_2,char param_3,uint param_4)

{
  if ((param_4 & 1) != 0) {
    *(int *)((int)param_1 + 0x3a) = *(int *)((int)param_1 + 0x22) - *(int *)((int)param_1 + 0x26);
    *(int *)((int)param_1 + 0x3a) = *(int *)((int)param_1 + 0x3a) << (9U - param_2 & 0x1f);
  }
  if ((param_4 & 2) != 0) {
    *(int *)((int)param_1 + 0x3c) = *(int *)((int)param_1 + 0x24) - *(int *)((int)param_1 + 0x28);
    *(int *)((int)param_1 + 0x3c) = *(int *)((int)param_1 + 0x3c) << (9U - param_3 & 0x1f);
  }
  FUN_549b_007a(0x28eb,(int)param_1,param_1._2_2_);
  return;
}

