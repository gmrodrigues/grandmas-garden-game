// TIM2.EXE: FUN_3f2b_0aa7 @ file 0x044F57 Ghidra 0x3FD57
// Subsystem: sound | Size: 231 bytes


int __cdecl16far FUN_3f2b_0aa7(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_16;
  int local_14;
  uint local_e;
  uint local_c;
  int local_6;
  
  uVar2 = DAT_5b41_1b4e;
  uVar1 = DAT_5b41_1b4c;
  local_16 = 0;
  do {
    if (local_16 != 0) {
      return local_16;
    }
    local_c = 0xffff;
    local_e = 0xffff;
    local_14 = 0;
    iVar7 = 0;
    iVar3 = DAT_5b41_1b42;
    iVar4 = DAT_5b41_1b44;
    while (iVar6 = DAT_5b41_1b46, local_6 = iVar3, iVar3 != 0 || iVar4 != 0) {
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        iVar7 = iVar7 + 1;
        if (*(int *)(local_6 + 2) != 0) {
          if ((*(uint *)(local_6 + 8) <= local_c) &&
             (((*(uint *)(local_6 + 8) < local_c || (*(uint *)(local_6 + 6) < local_e)) &&
              (*(int *)(local_6 + 0xc) == 0)))) {
            local_c = *(uint *)(local_6 + 8);
            local_e = *(uint *)(local_6 + 6);
            local_14 = iVar7;
          }
        }
        local_6 = local_6 + 0x12;
      }
      piVar5 = (int *)(iVar3 + DAT_5b41_1b46 * 0x12);
      iVar3 = *piVar5;
      iVar4 = piVar5[1];
    }
    if (local_14 == 0) {
      return 0;
    }
    if (uVar2 <= local_c) {
      if (local_c != uVar2) {
        return 0;
      }
      if (uVar1 < local_e) {
        return 0;
      }
    }
    iVar3 = FUN_3f2b_0a39(local_14);
    if (iVar3 != 0) {
      local_16 = 1;
    }
  } while( true );
}

