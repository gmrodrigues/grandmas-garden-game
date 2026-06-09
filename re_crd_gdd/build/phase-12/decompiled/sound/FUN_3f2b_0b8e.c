// TIM2.EXE: FUN_3f2b_0b8e @ file 0x04503E Ghidra 0x3FE3E
// Subsystem: sound | Size: 294 bytes


int __cdecl16far FUN_3f2b_0b8e(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_a;
  int iStack_8;
  int local_6;
  int iStack_4;
  
  if ((param_1 == 0) || (DAT_5b41_1b42 == 0 && DAT_5b41_1b44 == 0)) {
    local_6 = 0;
  }
  else {
    iStack_4 = DAT_5b41_1b44;
    local_6 = DAT_5b41_1b42;
    for (uVar4 = param_1 - 1; (local_6 != 0 || iStack_4 != 0 && (DAT_5b41_1b46 <= uVar4));
        uVar4 = uVar4 - DAT_5b41_1b46) {
      piVar3 = (int *)(local_6 + DAT_5b41_1b46 * 0x12);
      local_6 = *piVar3;
      iStack_4 = piVar3[1];
    }
    if ((local_6 == 0 && iStack_4 == 0) &&
       (iVar1 = DAT_5b41_1b42, iVar2 = DAT_5b41_1b44, param_2 != 0)) {
      do {
        iStack_8 = iVar2;
        local_a = iVar1;
        piVar3 = (int *)(local_a + DAT_5b41_1b46 * 0x12);
        iStack_4 = piVar3[1];
        local_6 = *piVar3;
        iVar1 = local_6;
        iVar2 = iStack_4;
      } while (local_6 != 0 || iStack_4 != 0);
      for (uVar4 = uVar4 + DAT_5b41_1b46; DAT_5b41_1b46 <= uVar4; uVar4 = uVar4 - DAT_5b41_1b46) {
        local_6 = FUN_22de_01ec(DAT_5b41_1b46 * 0x12 + 4,0,DAT_5b41_1b50,DAT_5b41_1b52 | 1);
        if (local_6 != 0 || iStack_4 != 0) {
          piVar3 = (int *)(local_a + DAT_5b41_1b46 * 0x12);
          piVar3[1] = iStack_4;
          *piVar3 = local_6;
        }
        local_a = local_6;
        iStack_8 = iStack_4;
      }
    }
    if (local_6 != 0 || iStack_4 != 0) {
      local_6 = local_6 + uVar4 * 0x12;
    }
    if ((local_6 != 0 || iStack_4 != 0) && (DAT_5b41_1b3c <= uVar4)) {
      DAT_5b41_1b3c = uVar4 + 1;
    }
  }
  return local_6;
}

