// TIM2.EXE: FUN_31f7_68c9 @ file 0x03DA39 Ghidra 0x38839
// Subsystem: misc | Size: 327 bytes


undefined2 __cdecl16far FUN_31f7_68c9(undefined4 param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_a;
  undefined2 uStack_8;
  int local_6;
  undefined2 uStack_4;
  
  uStack_8 = (undefined2)((ulong)param_1 >> 0x10);
  local_a = (int)param_1;
  iVar2 = *(int *)(local_a + 0xa0);
  if (*(int *)(local_a + 8) == 0x36) {
    puVar1 = (undefined2 *)(local_a + 0x9c);
    local_6 = local_a;
    uStack_4 = uStack_8;
    local_a = *(int *)(local_a + 0x9a);
    uStack_8 = *puVar1;
  }
  else {
    uStack_4 = *(undefined2 *)(local_a + 0x9c);
    local_6 = *(int *)(local_a + 0x9a);
    *(undefined2 *)(local_6 + 0xae) = 1;
  }
  if ((*(int *)(local_6 + 0x10) < DAT_5b41_09a3) || (DAT_5b41_1a2a <= *(int *)(local_6 + 0x10))) {
    if (*(int *)(local_6 + 0x10) == DAT_5b41_1a30) {
      return 1;
    }
    if ((*(byte *)(local_6 + 0xc) & 0x10) == 0) {
      if (iVar2 < 0x2001) {
        return 1;
      }
    }
    else if (-0x2001 < iVar2) {
      return 1;
    }
    *(uint *)(local_6 + 0xc) = *(uint *)(local_6 + 0xc) ^ 0x10;
  }
  else if ((*(int *)(local_a + 8) != 0x27) && ((iVar2 + 0xc000U & 0x8000) != 0)) {
    if ((*(int *)(local_6 + 0x3c) < 0x1000) &&
       (uVar4 = (int)*(uint *)(local_6 + 0x3a) >> 0xf,
       (int)((*(uint *)(local_6 + 0x3a) ^ uVar4) - uVar4) < 0xc00)) {
      iVar3 = *(int *)(local_6 + 0xa8);
      *(int *)(local_6 + 0x10) = iVar3;
      if (iVar3 != 0) {
        *(int *)(local_6 + 0x10) = *(int *)(local_6 + 0x10) + 1;
      }
    }
    else {
      *(int *)(local_6 + 0x10) = DAT_5b41_1a2a;
      if (*(int *)(local_6 + 0x3c) < 0x1c01) {
        *(undefined2 *)(local_6 + 0xb4) = 0;
      }
      else {
        *(undefined2 *)(local_6 + 0xb4) = 1;
      }
    }
    if ((iVar2 == 0) &&
       ((*(undefined2 *)(local_6 + 0x3c) = 0, *(int *)(local_a + 8) != 5 ||
        (*(int *)(local_a + 0x16) == 0)))) {
      *(undefined2 *)(local_6 + 0x3a) = 0;
    }
  }
  FUN_28eb_3328(local_6,uStack_4);
  return 1;
}

