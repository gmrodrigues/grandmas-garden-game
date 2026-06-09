// TIM2.EXE: FUN_3f2b_0000 @ file 0x0444B0 Ghidra 0x3F2B0
// Subsystem: sound | Size: 285 bytes


undefined2 __cdecl16far
FUN_3f2b_0000(uint param_1,uint param_2,int param_3,undefined2 param_4,uint param_5)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  int local_8;
  
  if (param_1 < 0x10) {
    param_1 = 0x10;
  }
  if (param_2 < 5) {
    param_2 = 5;
  }
  DAT_5b41_1b52 = param_5;
  DAT_5b41_1b50 = param_4;
  if (((DAT_5b41_1b42 == 0 && DAT_5b41_1b44 == 0) &&
      ((int)DAT_5b41_1b3e == 0 && DAT_5b41_1b3e._2_2_ == 0)) &&
     (DAT_5b41_1b3e._0_2_ = FUN_22de_01ec(param_2 << 2,0,param_4,param_5 | 1),
     DAT_5b41_1b3e._2_2_ = param_5, (int)DAT_5b41_1b3e != 0 || param_5 != 0)) {
    if (param_3 == 0) {
      local_8 = 1;
    }
    else {
      local_8 = (param_3 - 1U) / param_1 + 1;
    }
    lVar1 = (long)local_8;
    iVar4 = (int)((ulong)((int)param_1 * lVar1) >> 0x10);
    while (local_8 != 0) {
      iVar2 = FUN_22de_01ec(param_1 * 0x12 + 4,0,DAT_5b41_1b50,DAT_5b41_1b52 | 1);
      if (iVar2 == 0 && iVar4 == 0) {
        FUN_3f2b_011d(0);
        goto LAB_3f2b_00c3;
      }
      piVar5 = (int *)(iVar2 + param_1 * 0x12);
      piVar5[1] = DAT_5b41_1b44;
      *piVar5 = DAT_5b41_1b42;
      DAT_5b41_1b42 = iVar2;
      DAT_5b41_1b44 = iVar4;
      local_8 = local_8 + -1;
    }
    DAT_5b41_1b4e = 0;
    DAT_5b41_1b4c = 0;
    DAT_5b41_1b3c = 0;
    uVar3 = 1;
    DAT_5b41_1b46 = param_1;
    DAT_5b41_1b48 = (int)((int)param_1 * lVar1);
    DAT_5b41_1b4a = param_2;
  }
  else {
LAB_3f2b_00c3:
    uVar3 = 0;
  }
  return uVar3;
}

