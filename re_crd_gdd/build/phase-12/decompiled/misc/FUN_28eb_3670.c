// TIM2.EXE: FUN_28eb_3670 @ file 0x031720 Ghidra 0x2C520
// Subsystem: misc | Size: 218 bytes


void __cdecl16far FUN_28eb_3670(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined2 uVar5;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x98) != 0) {
    piVar3 = (int *)*(undefined2 *)(iVar2 + 0x98);
    for (iVar4 = 1; iVar4 < *(int *)(iVar2 + 0x96); iVar4 = iVar4 + 1) {
      local_e = *piVar3;
      local_c = piVar3[1];
      local_a = piVar3[3];
      local_8 = piVar3[4];
      FUN_2e67_15e5(&local_e);
      local_4 = local_a - local_e;
      local_6 = local_8 - local_c;
      iVar1 = FUN_2e67_1277(local_4,local_4 >> 0xf,local_6,local_6 >> 0xf);
      piVar3[2] = -0x4000 - iVar1;
      piVar3 = piVar3 + 3;
    }
    local_e = *piVar3;
    local_c = piVar3[1];
    local_a = *(int *)*(undefined2 *)(iVar2 + 0x98);
    local_8 = *(int *)(*(int *)(iVar2 + 0x98) + 2);
    FUN_2e67_15e5(&local_e);
    local_4 = local_a - local_e;
    local_6 = local_8 - local_c;
    iVar2 = FUN_2e67_1277(local_4,local_4 >> 0xf,local_6,local_6 >> 0xf);
    piVar3[2] = -0x4000 - iVar2;
  }
  return;
}

