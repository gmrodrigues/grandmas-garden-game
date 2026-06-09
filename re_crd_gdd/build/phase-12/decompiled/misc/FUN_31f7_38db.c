// TIM2.EXE: FUN_31f7_38db @ file 0x03AA4B Ghidra 0x3584B
// Subsystem: misc | Size: 292 bytes


void __cdecl16far FUN_31f7_38db(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
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
  
  FUN_2424_2e7d((int)param_1,param_1._2_2_,param_2);
  iVar2 = *(int *)((int)param_1 + 0x70);
  iVar1 = *(int *)((int)param_1 + 0x6e);
  if ((iVar1 != 0 || iVar2 != 0) && (DAT_5b41_0937 == 0x2000)) {
    DAT_554c_42cd = 0xe;
    DAT_554c_42ce = 0xe;
    local_6 = (*(int *)(iVar1 + 0x22) + (int)*(char *)(iVar1 + 0x82)) - DAT_5b41_0925;
    local_e = (*(int *)((int)param_1 + 0x24) + 6) - DAT_5b41_0927;
    local_c = (*(int *)(iVar1 + 0x24) + (int)*(char *)(iVar1 + 0x83)) - DAT_5b41_0927;
    local_a = (*(int *)((int)param_1 + 0x24) + 0x10) - DAT_5b41_0927;
    if ((*(byte *)((int)param_1 + 0xc) & 0x10) == 0) {
      local_8 = *(int *)((int)param_1 + 0x22) + 0x12;
    }
    else {
      local_8 = *(int *)((int)param_1 + 0x22) + -1;
    }
    local_8 = local_8 - DAT_5b41_0925;
    local_4 = local_8;
    FUN_1a9e_25bd(3,&local_8,&local_e);
    if (local_8 < local_6) {
      local_12 = local_8;
      local_16 = local_6 - local_8;
    }
    else {
      local_12 = local_6;
      local_16 = local_8 - local_6;
    }
    local_16 = local_16 + 1;
    local_10 = local_e;
    if (local_c <= local_e) {
      local_10 = local_c;
    }
    iVar2 = local_a;
    if (local_a < local_c) {
      iVar2 = local_c;
    }
    local_14 = (iVar2 - local_10) + 1;
    FUN_2424_1da0(&local_12,&local_16,2);
  }
  return;
}

