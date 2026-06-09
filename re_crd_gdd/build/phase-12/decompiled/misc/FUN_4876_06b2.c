// TIM2.EXE: FUN_4876_06b2 @ file 0x04E012 Ghidra 0x48E12
// Subsystem: misc | Size: 110 bytes


void __cdecl16far FUN_4876_06b2(undefined4 param_1)

{
  undefined4 local_6;
  
  local_6 = (int *)CONCAT22(param_1._2_2_,(int *)((int)param_1 + 0x28));
  if (((*local_6 != 0) && (*(int *)((int)param_1 + 0x2c) != 0)) &&
     ((*(byte *)((int)param_1 + 0x24) & 8) == 0)) {
    FUN_4551_01dc(*local_6,*(int *)((int)param_1 + 0x2a) + *(int *)((int)param_1 + 0x2e),
                  *(int *)((int)param_1 + 0x14) + *(int *)((int)param_1 + 0x30),
                  *(int *)((int)param_1 + 0x16) + *(int *)((int)param_1 + 0x32),0);
  }
  return;
}

