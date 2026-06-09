// TIM2.EXE: FUN_28eb_024e @ file 0x02E2FE Ghidra 0x290FE
// Subsystem: misc | Size: 433 bytes


undefined2 __cdecl16far FUN_28eb_024e(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  int *local_3a;
  int local_38;
  int local_36;
  int local_34;
  int local_32;
  int local_30;
  int local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  int local_28;
  int local_26;
  int local_24;
  int local_22;
  int local_20;
  int local_1e;
  int local_1c;
  int local_1a;
  int local_18;
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  local_12 = *(int *)(iVar2 + 0x22);
  local_14 = *(int *)(iVar2 + 0x24);
  uVar7 = (undefined2)((ulong)param_2 >> 0x10);
  iVar3 = (int)param_2;
  local_22 = *(int *)(iVar3 + 0x22);
  local_24 = *(int *)(iVar3 + 0x24);
  local_4 = 1;
  local_3a = (int *)*(int *)(iVar2 + 0x98);
  if (local_3a != (int *)0x0) {
    local_a = *local_3a + local_12;
    local_10 = local_3a[1] + local_14;
    local_c = local_10;
    local_6 = local_a;
    goto LAB_28eb_03db;
  }
  while( true ) {
    if (local_3a == (int *)0x0) {
      return 0;
    }
    local_2c = 0;
    local_2a = 0;
    local_28 = local_8 - local_6;
    local_26 = local_e - local_c;
    iVar5 = 1;
    piVar4 = (int *)*(int *)(iVar3 + 0x98);
    if (piVar4 != (int *)0x0) break;
    while (piVar4 != (int *)0x0) {
      local_34 = local_16 - local_6;
      local_32 = local_1c - local_c;
      local_30 = local_18 - local_6;
      local_2e = local_1e - local_c;
      iVar1 = FUN_2e67_13d4(&local_2c,&local_34,&local_38);
      if ((iVar1 != 0) && ((local_36 != local_26 || (local_38 != local_28)))) {
        return 1;
      }
      iVar5 = iVar5 + 1;
      if (*(int *)(iVar3 + 0x96) < iVar5) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = piVar4 + 3;
        local_16 = local_18;
        local_1c = local_1e;
        if (*(int *)(iVar3 + 0x96) == iVar5) {
          local_18 = local_1a;
          local_1e = local_20;
        }
        else {
LAB_28eb_0383:
          local_18 = piVar4[3] + local_22;
          local_1e = piVar4[4] + local_24;
        }
      }
    }
    local_4 = local_4 + 1;
    if (*(int *)(iVar2 + 0x96) < local_4) {
      local_3a = (int *)0x0;
    }
    else {
      local_3a = local_3a + 3;
      local_6 = local_8;
      local_c = local_e;
      if (*(int *)(iVar2 + 0x96) == local_4) {
        local_8 = local_a;
        local_e = local_10;
      }
      else {
LAB_28eb_03db:
        local_8 = local_3a[3] + local_12;
        local_e = local_3a[4] + local_14;
      }
    }
  }
  local_1a = *piVar4 + local_22;
  local_20 = piVar4[1] + local_24;
  local_1c = local_20;
  local_16 = local_1a;
  goto LAB_28eb_0383;
}

