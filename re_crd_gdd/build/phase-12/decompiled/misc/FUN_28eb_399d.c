// TIM2.EXE: FUN_28eb_399d @ file 0x031A4D Ghidra 0x2C84D
// Subsystem: misc | Size: 409 bytes


int __cdecl16far FUN_28eb_399d(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  int local_c;
  int local_a;
  int local_4;
  
  iVar2 = param_1;
  if ((param_3 == 0) || (*(int *)(param_1 + 8) == 0 && *(int *)(param_1 + 10) == 0)) {
    local_a = 0;
    uVar6 = (undefined2)((ulong)*(undefined4 *)(param_1 + 4) >> 0x10);
    iVar5 = (int)*(undefined4 *)(param_1 + 4) + (uint)*(byte *)(param_1 + 0x14) * 4;
    iVar1 = *(int *)(iVar5 + 0x60);
    iVar5 = *(int *)(iVar5 + 0x5e);
    if ((*(int *)(param_1 + 10) != iVar1) || (*(int *)(param_1 + 8) != iVar5)) {
      local_c = 0;
      iVar2 = *(int *)(iVar5 + 0x76);
      goto LAB_28eb_3a40;
    }
  }
  else {
    local_a = 1;
    uVar6 = (undefined2)((ulong)*(undefined4 *)(param_1 + 8) >> 0x10);
    iVar5 = (int)*(undefined4 *)(param_1 + 8) + (uint)*(byte *)(param_1 + 0x15) * 4;
    iVar1 = *(int *)(iVar5 + 0x60);
    iVar5 = *(int *)(iVar5 + 0x5e);
    if ((*(int *)(param_1 + 6) == iVar1) && (*(int *)(param_1 + 4) == iVar5)) {
      local_c = 0;
      goto LAB_28eb_3a40;
    }
    iVar2 = *(int *)(iVar5 + 0x76);
  }
  local_c = 1;
LAB_28eb_3a40:
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    if (param_2 == 1) {
      uVar3 = *(int *)(local_a * 4 + param_1 + 0x2e) - *(int *)(local_c * 4 + iVar2 + 0x2e);
      uVar4 = (int)uVar3 >> 0xf;
      local_4 = (uVar3 ^ uVar4) - uVar4;
      uVar3 = *(int *)(local_a * 4 + param_1 + 0x30) - *(int *)(local_c * 4 + iVar2 + 0x30);
    }
    else if (param_2 == 2) {
      uVar3 = *(int *)(local_a * 4 + param_1 + 0x26) - *(int *)(local_c * 4 + iVar2 + 0x26);
      uVar4 = (int)uVar3 >> 0xf;
      local_4 = (uVar3 ^ uVar4) - uVar4;
      uVar3 = *(int *)(local_a * 4 + param_1 + 0x28) - *(int *)(local_c * 4 + iVar2 + 0x28);
    }
    else {
      uVar3 = *(int *)(local_a * 4 + param_1 + 0x1e) - *(int *)(local_c * 4 + iVar2 + 0x1e);
      uVar4 = (int)uVar3 >> 0xf;
      local_4 = (uVar3 ^ uVar4) - uVar4;
      uVar3 = *(int *)(local_a * 4 + param_1 + 0x20) - *(int *)(local_c * 4 + iVar2 + 0x20);
    }
    iVar2 = (uVar3 ^ (int)uVar3 >> 0xf) - ((int)uVar3 >> 0xf);
    if (local_4 < iVar2) {
      iVar2 = (local_4 >> 2) + (local_4 >> 3) + iVar2;
    }
    else {
      iVar2 = (iVar2 >> 2) + (iVar2 >> 3) + local_4;
    }
  }
  return iVar2;
}

