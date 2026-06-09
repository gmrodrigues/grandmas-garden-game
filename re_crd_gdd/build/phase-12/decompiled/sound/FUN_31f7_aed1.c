// TIM2.EXE: FUN_31f7_aed1 @ file 0x042041 Ghidra 0x3CE41
// Subsystem: sound | Size: 372 bytes


undefined2 __cdecl16far FUN_31f7_aed1(int param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined2 uVar4;
  int local_2c;
  int local_2a;
  int local_28;
  int local_26;
  undefined2 local_24;
  undefined2 local_22;
  int local_20;
  int local_1e;
  int local_1c;
  int local_1a;
  uint local_18;
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  undefined2 local_4;
  
  uVar4 = (undefined2)((ulong)param_2 >> 0x10);
  iVar2 = (int)param_2;
  local_14 = *(int *)(iVar2 + 0x22);
  local_16 = *(int *)(iVar2 + 0x24);
  local_6 = 1;
  piVar3 = (int *)*(int *)(iVar2 + 0x98);
  if (piVar3 != (int *)0x0) {
    local_c = *piVar3 + local_14;
    local_12 = piVar3[1] + local_16;
    local_a = piVar3[3] + local_14;
    local_10 = piVar3[4] + local_16;
    local_e = local_12;
    local_8 = local_c;
  }
  local_4 = 0;
  while (piVar3 != (int *)0x0) {
    local_18 = piVar3[2] + param_1 + 0x4000;
    if (((local_18 & 0x8000) == 0) && (local_18 != 0)) {
      local_24 = 0;
      local_22 = 0;
      local_20 = local_a - local_8;
      local_1e = local_10 - local_e;
      local_2c = *param_3 - local_8;
      local_2a = param_3[1] - local_e;
      local_28 = *param_4 - local_8;
      local_26 = param_4[1] - local_e;
      iVar1 = FUN_2e67_13d4(&local_24,&local_2c,&local_1c);
      if (iVar1 != 0) {
        local_1c = local_1c + local_8;
        local_1a = local_1a + local_e;
        if (((*param_4 != local_1c) || (param_4[1] != local_1a)) &&
           ((*param_3 != local_1c || (param_3[1] != local_1a)))) {
          *param_4 = local_1c;
          param_4[1] = local_1a;
          local_4 = 1;
        }
      }
    }
    local_6 = local_6 + 1;
    if (*(int *)(iVar2 + 0x96) < local_6) {
      piVar3 = (int *)0x0;
    }
    else {
      local_8 = local_a;
      local_e = local_10;
      if (*(int *)(iVar2 + 0x96) == local_6) {
        local_a = local_c;
        piVar3 = piVar3 + 3;
        local_10 = local_12;
      }
      else {
        local_a = piVar3[6] + local_14;
        local_10 = piVar3[7] + local_16;
        piVar3 = piVar3 + 3;
      }
    }
  }
  return local_4;
}

