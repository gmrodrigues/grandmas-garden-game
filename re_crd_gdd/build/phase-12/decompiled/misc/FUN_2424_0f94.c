// TIM2.EXE: FUN_2424_0f94 @ file 0x02A3D4 Ghidra 0x251D4
// Subsystem: misc | Size: 95 bytes


void __cdecl16far FUN_2424_0f94(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  
  if (((int)param_1 != 0 || param_1._2_2_ != 0) && (DAT_5b41_050f == 0)) {
    iVar1 = *(int *)((int)param_1 + 8);
    if (iVar1 == 8) {
      FUN_2424_09c2((int)param_1,param_1._2_2_,param_2);
    }
    else if ((iVar1 == 10) || (iVar1 == 0x4c)) {
      FUN_2424_0a23((int)param_1,param_1._2_2_,param_2);
    }
    else {
      FUN_2424_0ead((int)param_1,param_1._2_2_,param_2);
    }
  }
  return;
}

