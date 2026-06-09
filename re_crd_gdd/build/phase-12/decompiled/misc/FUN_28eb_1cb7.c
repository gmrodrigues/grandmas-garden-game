// TIM2.EXE: FUN_28eb_1cb7 @ file 0x02FD67 Ghidra 0x2AB67
// Subsystem: misc | Size: 225 bytes


void __cdecl16far FUN_28eb_1cb7(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 local_8;
  undefined2 local_6;
  
  if ((int)param_2 == 0 && param_2._2_2_ == 0) {
    local_8 = *(int *)((int)param_1 + 0x22) - (DAT_5b41_1b84 + DAT_5b41_0925);
    iVar1 = *(int *)((int)param_1 + 0x24);
    iVar2 = DAT_5b41_1b86 + DAT_5b41_0927;
  }
  else {
    if (*(int *)((int)param_2 + 8) == 7) {
      local_8 = *(int *)((int)param_1 + 0x22) - *(int *)((int)param_2 + 0x22);
      iVar1 = *(int *)((int)param_1 + 0x24) - *(int *)((int)param_2 + 0x24);
      goto LAB_28eb_1d77;
    }
    iVar1 = FUN_28eb_3930((int)param_1,param_1._2_2_,(int)param_2,param_2._2_2_);
    local_8 = *(int *)((int)param_1 + 0x22) -
              (*(int *)((int)param_2 + 0x22) + (int)*(char *)((int)param_2 + iVar1 * 2 + 0x7a));
    iVar2 = *(int *)((int)param_2 + 0x24) + (int)*(char *)((int)param_2 + iVar1 * 2 + 0x7b);
    iVar1 = *(int *)((int)param_1 + 0x24);
  }
  iVar1 = iVar1 - iVar2;
LAB_28eb_1d77:
  local_6 = local_8 >> 0xf;
  FUN_2e67_1277(local_8,local_6,iVar1,iVar1 >> 0xf);
  return;
}

