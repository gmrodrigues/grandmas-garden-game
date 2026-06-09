// TIM2.EXE: FUN_2424_1a04 @ file 0x02AE44 Ghidra 0x25C44
// Subsystem: misc | Size: 354 bytes


void __cdecl16far FUN_2424_1a04(int *param_1,int *param_2,undefined2 param_3)

{
  uint uVar1;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  local_6 = *param_1;
  if (local_6 < *param_2) {
    local_a = *param_2;
  }
  else {
    local_6 = *param_2;
    local_a = *param_1;
  }
  local_4 = param_1[1];
  if (local_4 < param_2[1]) {
    local_8 = param_2[1];
  }
  else {
    local_4 = param_2[1];
    local_8 = param_1[1];
  }
  uVar1 = (uint)(local_a - local_6 < local_8 - local_4);
  local_6 = local_6 - uVar1;
  local_a = local_a + uVar1;
  local_4 = local_4 - (uint)(uVar1 == 0);
  local_8 = local_8 + (uint)(uVar1 == 0);
  local_12 = (local_a - local_6) + 1;
  local_10 = (local_8 - local_4) + 1;
  if (((local_12 < 0x11) || (local_10 < 0x11)) || (1 < DAT_5b41_04aa)) {
    FUN_2424_1da0(&local_6,&local_12,param_3);
  }
  else {
    DAT_5b41_04aa = DAT_5b41_04aa + 1;
    local_4 = param_1[1];
    local_6 = *param_1;
    local_8 = param_2[1];
    local_a = *param_2;
    local_e = (local_a - local_6) / 2 + local_6;
    local_c = (local_8 - local_4) / 2 + local_4;
    FUN_2424_1a04(&local_6,&local_e,param_3);
    FUN_2424_1a04(&local_e,&local_a,param_3);
    local_6 = (local_6 - local_e) / 4 + local_e;
    local_4 = (local_4 - local_c) / 4 + local_c;
    local_e = (local_a - local_e) / 4 + local_e;
    local_c = (local_8 - local_c) / 4 + local_c;
    FUN_2424_1a04(&local_6,&local_e,param_3);
    DAT_5b41_04aa = DAT_5b41_04aa + -1;
  }
  return;
}

