// TIM2.EXE: FUN_2424_0a23 @ file 0x029E63 Ghidra 0x24C63
// Subsystem: misc | Size: 1161 bytes


void __cdecl16far FUN_2424_0a23(undefined4 param_1,byte param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_18;
  int iStack_16;
  int local_14;
  int iStack_12;
  undefined2 local_c;
  undefined2 local_a;
  int local_8;
  int local_6;
  undefined2 local_4;
  
  iVar1 = *(int *)((int)param_1 + 0x76);
  local_c = 0x10;
  local_a = 0x10;
  if (DAT_5b41_0937 == 0x2000) {
    uVar2 = *(undefined2 *)(iVar1 + 6);
    iVar5 = *(int *)(iVar1 + 4);
    iVar7 = iVar5 + (uint)*(byte *)(iVar1 + 0x14) * 4;
    iVar6 = *(int *)(iVar7 + 0x60);
    iVar7 = *(int *)(iVar7 + 0x5e);
    if ((param_2 & 1) != 0) {
      if (*(int *)(iVar7 + 8) == 7) {
        iVar4 = *(int *)(iVar7 + 0x76) + 0x2e;
      }
      else {
        iVar4 = iVar1 + 0x32;
      }
      local_4 = FUN_28eb_3b36(iVar5,uVar2,iVar1,1);
      FUN_2424_1b66(iVar1 + 0x2e,iVar4,1,local_4);
      for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
        local_8 = *(int *)(iVar4 * 4 + iVar1 + 0x2e) + -8;
        local_6 = *(int *)(iVar4 * 4 + iVar1 + 0x30) + -8;
        FUN_2424_1da0(&local_8,&local_c,1);
      }
    }
    if ((param_2 & 2) != 0) {
      if (*(int *)(iVar7 + 8) == 7) {
        iVar4 = *(int *)(iVar7 + 0x76) + 0x26;
      }
      else {
        iVar4 = iVar1 + 0x2a;
      }
      local_4 = FUN_28eb_3b36(iVar5,uVar2,iVar1,2);
      FUN_2424_1b66(iVar1 + 0x26,iVar4,2,local_4);
      for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
        local_8 = *(int *)(iVar5 * 4 + iVar1 + 0x2e) + -8;
        local_6 = *(int *)(iVar5 * 4 + iVar1 + 0x30) + -8;
        FUN_2424_1da0(&local_8,&local_c,2);
      }
    }
    if ((*(int *)(iVar1 + 10) != iVar6) || (*(int *)(iVar1 + 8) != iVar7)) {
      uVar2 = *(undefined2 *)(iVar1 + 10);
      iVar5 = *(int *)(iVar1 + 8);
      iVar6 = iVar5 + (uint)*(byte *)(iVar1 + 0x15) * 4;
      uVar3 = *(undefined2 *)(iVar6 + 0x60);
      iVar6 = *(int *)(iVar6 + 0x5e);
      if ((param_2 & 1) != 0) {
        if (*(int *)(iVar6 + 8) == 7) {
          iVar7 = *(int *)(iVar6 + 0x76) + 0x32;
        }
        else {
          iVar7 = iVar1 + 0x2e;
        }
        local_4 = FUN_28eb_3b36(iVar6,uVar3,iVar1,1);
        FUN_2424_1b66(iVar7,iVar1 + 0x32,1,local_4);
        for (iVar7 = 0; iVar7 < 2; iVar7 = iVar7 + 1) {
          local_8 = *(int *)(iVar7 * 4 + iVar1 + 0x2e) + -8;
          local_6 = *(int *)(iVar7 * 4 + iVar1 + 0x30) + -8;
          FUN_2424_1da0(&local_8,&local_c,1);
        }
      }
      if ((param_2 & 2) != 0) {
        if (*(int *)(iVar5 + 8) == 7) {
          iVar5 = *(int *)(iVar6 + 0x76) + 0x2a;
        }
        else {
          iVar5 = iVar1 + 0x26;
        }
        local_4 = FUN_28eb_3b36(iVar6,uVar3,iVar1,2);
        FUN_2424_1b66(iVar5,iVar1 + 0x2a,2,local_4);
        for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
          local_8 = *(int *)(iVar5 * 4 + iVar1 + 0x2e) + -8;
          local_6 = *(int *)(iVar5 * 4 + iVar1 + 0x30) + -8;
          FUN_2424_1da0(&local_8,&local_c,2);
        }
      }
    }
  }
  else {
    if ((param_2 & 1) != 0) {
      iStack_12 = *(int *)(iVar1 + 6);
      local_14 = *(int *)(iVar1 + 4);
      local_18 = local_14 + (uint)*(byte *)(iVar1 + 0x14) * 4;
LAB_2424_0d52:
      iStack_16 = *(int *)(local_18 + 0x60);
      local_18 = *(int *)(local_18 + 0x5e);
LAB_2424_0d60:
      if ((local_14 == 0 && iStack_12 == 0) || (local_18 == 0 && iStack_16 == 0)) {
        for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
          local_8 = *(int *)(iVar5 * 4 + iVar1 + 0x2e) + -8;
          local_6 = *(int *)(iVar5 * 4 + iVar1 + 0x30) + -8;
          FUN_2424_1da0(&local_8,&local_c,1);
        }
        goto LAB_2424_0dab;
      }
      if (*(int *)(local_14 + 8) == 7) {
        iVar5 = *(int *)(local_14 + 0x76) + 0x32;
      }
      else {
        iVar5 = iVar1 + 0x2e;
      }
      if (*(int *)(local_18 + 8) == 7) {
        iVar6 = *(int *)(local_18 + 0x76) + 0x2e;
      }
      else {
        iVar6 = iVar1 + 0x32;
      }
      local_4 = FUN_28eb_3b36(local_14,iStack_12,iVar1,1);
      FUN_2424_1b66(iVar5,iVar6,1,local_4);
      iStack_12 = iStack_16;
      local_14 = local_18;
      iStack_12 = iStack_16;
      if (*(int *)(local_18 + 8) != 7) goto code_r0x00024f83;
      goto LAB_2424_0d52;
    }
LAB_2424_0dab:
    if ((param_2 & 2) != 0) {
      iStack_12 = *(int *)(iVar1 + 6);
      local_14 = *(int *)(iVar1 + 4);
      local_18 = local_14 + (uint)*(byte *)(iVar1 + 0x14) * 4;
      do {
        iStack_16 = *(int *)(local_18 + 0x60);
        local_18 = *(int *)(local_18 + 0x5e);
        while( true ) {
          if ((local_14 == 0 && iStack_12 == 0) || (local_18 == 0 && iStack_16 == 0)) {
            for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
              local_8 = *(int *)(iVar5 * 4 + iVar1 + 0x26) + -8;
              local_6 = *(int *)(iVar5 * 4 + iVar1 + 0x28) + -8;
              FUN_2424_1da0(&local_8,&local_c,2);
            }
            return;
          }
          if (*(int *)(local_14 + 8) == 7) {
            iVar5 = *(int *)(local_14 + 0x76) + 0x2a;
          }
          else {
            iVar5 = iVar1 + 0x26;
          }
          if (*(int *)(local_18 + 8) == 7) {
            iVar6 = *(int *)(local_18 + 0x76) + 0x26;
          }
          else {
            iVar6 = iVar1 + 0x2a;
          }
          local_4 = FUN_28eb_3b36(local_14,iStack_12,iVar1,2);
          FUN_2424_1b66(iVar5,iVar6,2,local_4);
          iStack_12 = iStack_16;
          local_14 = local_18;
          iStack_12 = iStack_16;
          if (*(int *)(local_18 + 8) == 7) break;
          local_18 = 0;
          iStack_16 = 0;
        }
      } while( true );
    }
  }
  return;
code_r0x00024f83:
  local_18 = 0;
  iStack_16 = 0;
  goto LAB_2424_0d60;
}

