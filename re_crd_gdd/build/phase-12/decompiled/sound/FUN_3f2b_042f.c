// TIM2.EXE: FUN_3f2b_042f @ file 0x0448DF Ghidra 0x3F6DF
// Subsystem: sound | Size: 328 bytes


undefined2 __cdecl16far FUN_3f2b_042f(undefined2 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int in_DX;
  undefined2 *puVar4;
  int *piVar5;
  int iVar6;
  int local_e;
  int iStack_c;
  int local_a;
  int iStack_8;
  int local_6;
  int iStack_4;
  
  iVar2 = FUN_3f2b_0b8e(param_1,0);
  if ((iVar2 == 0 && in_DX == 0) || (*(int *)(iVar2 + 2) == 0)) {
    uVar3 = 0;
  }
  else {
    iStack_c = in_DX;
    if (param_2 != 0) {
      FUN_3f2b_0a39(param_1);
    }
    *(undefined2 *)(iVar2 + 2) = 0;
    *(undefined2 *)(iVar2 + 4) = 0;
    *(undefined2 *)(iVar2 + 8) = 0;
    *(undefined2 *)(iVar2 + 6) = 0;
    local_e = FUN_3f2b_0b8e((DAT_5b41_1b48 - DAT_5b41_1b46) + 1,0);
    iStack_4 = iStack_c;
    local_6 = FUN_3f2b_0b8e(DAT_5b41_1b48 + 1,0);
    local_a = local_6;
    iStack_8 = iStack_4;
    while (local_6 != 0 || iStack_4 != 0) {
      piVar5 = (int *)(local_6 + DAT_5b41_1b46 * 0x12);
      iVar2 = piVar5[1];
      iVar1 = *piVar5;
      iVar6 = DAT_5b41_1b46;
      for (; (iVar6 != 0 && (*(int *)(local_6 + 2) == 0)); local_6 = local_6 + 0x12) {
        iVar6 = iVar6 + -1;
      }
      local_6 = iVar1;
      iStack_4 = iVar2;
      if (iVar6 != 0) {
        iStack_c = iStack_8;
        local_e = local_a;
        local_a = iVar1;
        iStack_8 = iVar2;
      }
    }
    if (local_a != 0 || iStack_8 != 0) {
      puVar4 = (undefined2 *)(local_e + DAT_5b41_1b46 * 0x12);
      puVar4[1] = 0;
      *puVar4 = 0;
      while (local_a != 0 || iStack_8 != 0) {
        piVar5 = (int *)(local_a + DAT_5b41_1b46 * 0x12);
        iVar2 = piVar5[1];
        iVar1 = *piVar5;
        FUN_22de_0351(local_a,iStack_8);
        local_a = iVar1;
        iStack_8 = iVar2;
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}

