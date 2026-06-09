// TIM2.EXE: FUN_2424_167d @ file 0x02AABD Ghidra 0x258BD
// Subsystem: misc | Size: 461 bytes


void __cdecl16far FUN_2424_167d(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  int in_DX;
  int iVar8;
  undefined2 *puVar9;
  int local_1e;
  int local_1c;
  int local_1a;
  int local_18;
  undefined2 local_10;
  int local_e;
  int local_c;
  int local_a;
  int iStack_8;
  int local_6;
  int iStack_4;
  
  if (param_1 != 0) {
    iVar5 = FUN_460e_0f42(param_1);
    if (iVar5 == 0 && in_DX == 0) {
      return;
    }
    local_10 = *(undefined2 *)(iVar5 + 0x10);
  }
  uVar6 = FUN_460e_0f42(0,local_10,0);
  local_6 = FUN_460e_141e(uVar6,in_DX);
  if (local_6 != 0 || in_DX != 0) {
    local_1a = 999;
    local_18 = 999;
    local_1e = 0;
    local_1c = 0;
    local_c = 0;
    local_e = 0;
    local_a = local_6;
    iStack_8 = in_DX;
    iStack_4 = in_DX;
    while (puVar9 = DAT_5b41_04b0, local_a != 0 || iStack_8 != 0) {
      if (*(int *)(local_a + 0x14) < local_18) {
        local_18 = *(int *)(local_a + 0x14);
      }
      if (local_1c <= *(int *)(local_a + 0x14) + *(int *)(local_a + 0x18)) {
        local_1c = *(int *)(local_a + 0x14) + *(int *)(local_a + 0x18) + -1;
      }
      if (*(int *)(local_a + 0x16) < local_1a) {
        local_1a = *(int *)(local_a + 0x16);
      }
      if (local_1e <= *(int *)(local_a + 0x16) + *(int *)(local_a + 0x1a)) {
        local_1e = *(int *)(local_a + 0x16) + *(int *)(local_a + 0x1a) + -1;
      }
      local_6 = local_a;
      iStack_4 = iStack_8;
      iVar5 = *(int *)(local_a + 10);
      iVar2 = *(int *)(local_a + 8);
      *(int *)(local_a + 10) = local_c;
      *(int *)(local_a + 8) = local_e;
      local_c = iStack_8;
      local_e = local_a;
      local_a = iVar2;
      iStack_8 = iVar5;
    }
    for (; puVar9 != (undefined2 *)0x0; puVar9 = (undefined2 *)*puVar9) {
      iVar5 = puVar9[1];
      iVar2 = puVar9[2];
      iVar3 = puVar9[3];
      iVar4 = puVar9[4];
      if ((((local_18 <= iVar3) && (iVar5 <= local_1c)) && (local_1a <= iVar4)) &&
         ((iVar2 <= local_1e && (iVar2 <= iVar4)))) {
        DAT_554c_42c3 = 1;
        iVar7 = local_6;
        iVar8 = iStack_4;
        DAT_554c_42c4 = iVar5;
        DAT_554c_42c6 = iVar3;
        DAT_554c_42c8 = iVar2;
        DAT_554c_42ca = iVar4;
        if (iVar5 < 0) {
          DAT_554c_42c4 = 0;
        }
        while (iVar7 != 0 || iVar8 != 0) {
          if (*(int *)(iVar7 + 0x1c) != 0 || *(int *)(iVar7 + 0x1e) != 0) {
            (*(code *)*(undefined2 *)(iVar7 + 0x1c))(0x460e,iVar7,iVar8);
          }
          piVar1 = (int *)(iVar7 + 10);
          iVar7 = *(int *)(iVar7 + 8);
          iVar8 = *piVar1;
        }
      }
    }
    FUN_2424_02e7();
  }
  return;
}

