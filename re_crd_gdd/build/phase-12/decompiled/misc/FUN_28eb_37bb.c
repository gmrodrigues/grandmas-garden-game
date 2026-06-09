// TIM2.EXE: FUN_28eb_37bb @ file 0x03186B Ghidra 0x2C66B
// Subsystem: misc | Size: 365 bytes


uint __cdecl16far FUN_28eb_37bb(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int local_18;
  int iStack_16;
  int local_14;
  undefined2 uStack_12;
  int local_10;
  int local_e;
  uint local_c;
  int local_a;
  int local_8;
  uint local_4;
  
  iVar5 = 1 - param_2;
  if (param_2 == 0) {
    uStack_12 = *(undefined2 *)(param_1 + 6);
    local_14 = *(int *)(param_1 + 4);
    bVar1 = *(byte *)(param_1 + 0x14);
    iStack_16 = *(int *)(param_1 + 10);
    local_18 = *(int *)(param_1 + 8);
    bVar4 = *(byte *)(param_1 + 0x15);
  }
  else {
    uStack_12 = *(undefined2 *)(param_1 + 10);
    local_14 = *(int *)(param_1 + 8);
    bVar1 = *(byte *)(param_1 + 0x15);
    iStack_16 = *(int *)(param_1 + 6);
    local_18 = *(int *)(param_1 + 4);
    bVar4 = *(byte *)(param_1 + 0x14);
  }
  local_4 = (uint)bVar1;
  local_14 = local_14 + local_4 * 4;
  iVar2 = *(int *)(local_14 + 0x60);
  iVar3 = *(int *)(local_14 + 0x5e);
  iVar6 = local_18 + (uint)bVar4 * 4;
  if ((iStack_16 == iVar2) && (local_18 == iVar3)) {
    local_10 = param_1;
    local_e = param_1;
    local_a = param_2;
    local_8 = iVar5;
  }
  else {
    local_e = *(int *)(iVar3 + 0x76);
    local_10 = *(int *)(*(int *)(iVar6 + 0x5e) + 0x76);
    local_8 = 1 - param_2;
    local_a = 1 - iVar5;
  }
  if (*(int *)(local_a * 4 + local_10 + 0x1e) < *(int *)(iVar5 * 4 + param_1 + 0x1e)) {
    local_c = 8;
  }
  else {
    local_c = 0x10;
  }
  if (param_3 == 0) {
    if (*(int *)(local_8 * 4 + local_e + 0x20) < *(int *)(param_2 * 4 + param_1 + 0x20)) {
      return 1;
    }
    if (*(int *)(iVar5 * 4 + param_1 + 0x20) < *(int *)(local_a * 4 + local_10 + 0x20)) {
LAB_28eb_391e:
      return local_c | 4;
    }
  }
  else {
    if (*(int *)(param_2 * 4 + param_1 + 0x20) < *(int *)(local_8 * 4 + local_e + 0x20)) {
      return 1;
    }
    if (*(int *)(iVar5 * 4 + param_1 + 0x20) <= *(int *)(local_a * 4 + local_10 + 0x20))
    goto LAB_28eb_391e;
  }
  return local_c | 2;
}

