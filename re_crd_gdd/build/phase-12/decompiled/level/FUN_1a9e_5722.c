// TIM2.EXE: FUN_1a9e_5722 @ file 0x025302 Ghidra 0x20102
// Subsystem: level | Size: 233 bytes


void __cdecl16far FUN_1a9e_5722(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (DAT_554c_42c3 == '\0') goto LAB_1a9e_5806;
  if ((int)param_2 < (int)DAT_554c_42c8) {
    uVar1 = param_2;
    uVar2 = param_1;
    uVar4 = param_3;
    uVar3 = param_4;
    if ((int)param_4 < (int)DAT_554c_42c8) {
      return;
    }
LAB_1a9e_5759:
    param_1 = uVar2 + (int)(((long)(int)(uVar4 - uVar2) * (long)(int)(DAT_554c_42c8 - uVar1)) /
                           (long)(int)(uVar3 - uVar1));
    param_2 = DAT_554c_42c8;
    param_3 = uVar4;
    param_4 = uVar3;
  }
  else {
    uVar1 = param_4;
    uVar2 = param_3;
    uVar4 = param_1;
    uVar3 = param_2;
    if ((int)param_4 < (int)DAT_554c_42c8) goto LAB_1a9e_5759;
  }
  if ((int)param_1 < (int)DAT_554c_42c4) {
    uVar1 = param_2;
    uVar2 = param_1;
    param_1 = param_3;
    uVar4 = param_4;
    if ((int)param_3 < (int)DAT_554c_42c4) {
      return;
    }
LAB_1a9e_5789:
    param_2 = uVar1 + (int)(((long)(int)(uVar4 - uVar1) * (long)(int)(DAT_554c_42c4 - uVar2)) /
                           (long)(int)(param_1 - uVar2));
    uVar3 = DAT_554c_42c4;
    param_3 = param_1;
    param_4 = uVar4;
  }
  else {
    uVar1 = param_4;
    uVar2 = param_3;
    uVar3 = param_1;
    uVar4 = param_2;
    if ((int)param_3 < (int)DAT_554c_42c4) goto LAB_1a9e_5789;
  }
  if (DAT_554c_42ca < param_2) {
    uVar1 = param_2;
    uVar2 = uVar3;
    uVar4 = param_3;
    param_2 = param_4;
    if (DAT_554c_42ca < param_4) {
      return;
    }
LAB_1a9e_57b6:
    uVar3 = uVar2 + (int)(((long)(int)(uVar4 - uVar2) * (long)(int)(DAT_554c_42ca - uVar1)) /
                         (long)(int)(param_2 - uVar1));
    param_3 = uVar4;
  }
  else {
    uVar1 = param_4;
    uVar2 = param_3;
    uVar4 = uVar3;
    if (DAT_554c_42ca < param_4) goto LAB_1a9e_57b6;
  }
  if ((DAT_554c_42c6 < uVar3) && (DAT_554c_42c6 < param_3)) {
    return;
  }
LAB_1a9e_5806:
  (*DAT_554c_4d7e)(0x1a9e);
  return;
}

