// TIM2.EXE: FUN_28eb_443a @ file 0x0324EA Ghidra 0x2D2EA
// Subsystem: misc | Size: 581 bytes


void __cdecl16far FUN_28eb_443a(int param_1,undefined4 param_2,int *param_3,int *param_4)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  
  if ((*(int *)(param_1 + 6) == param_2._2_2_) && (*(int *)(param_1 + 4) == (int)param_2)) {
    uVar2 = (uint)*(byte *)(param_1 + 0x14);
    local_c = *(int *)((int)param_2 + 0x22) + (int)*(char *)((int)param_2 + uVar2 * 2 + 0x7a);
    local_a = *(int *)((int)param_2 + 0x24) + (int)*(char *)((int)param_2 + uVar2 * 2 + 0x7b);
    iVar3 = (int)param_2 + uVar2 * 4;
    uVar5 = *(undefined2 *)(iVar3 + 0x60);
    iVar4 = *(int *)(iVar3 + 0x5e);
    iVar3 = FUN_28eb_3930((int)param_2,param_2._2_2_,iVar4,uVar5);
    if (*(int *)(iVar4 + 8) == 7) {
      local_10 = *(int *)(*(int *)(iVar4 + 0x76) + (1 - iVar3) * 4 + 0x1e);
      local_e = *(int *)(*(int *)(iVar4 + 0x76) + (1 - iVar3) * 4 + 0x20);
      goto LAB_28eb_460e;
    }
    local_10 = *(int *)(iVar4 + 0x22) + (int)*(char *)(iVar4 + iVar3 * 2 + 0x7a);
    local_e = *(int *)(iVar4 + 0x24);
  }
  else {
    uVar1 = *(undefined2 *)(param_1 + 10);
    iVar3 = *(int *)(param_1 + 8);
    uVar2 = (uint)*(byte *)(param_1 + 0x15);
    local_c = *(int *)(iVar3 + 0x22) + (int)*(char *)(iVar3 + uVar2 * 2 + 0x7a);
    local_a = *(int *)(iVar3 + 0x24) + (int)*(char *)(iVar3 + uVar2 * 2 + 0x7b);
    iVar4 = iVar3 + uVar2 * 4;
    uVar5 = *(undefined2 *)(iVar4 + 0x60);
    iVar4 = *(int *)(iVar4 + 0x5e);
    iVar3 = FUN_28eb_3930(iVar3,uVar1,iVar4,uVar5);
    if (*(int *)(iVar4 + 8) == 7) {
      local_10 = *(int *)(*(int *)(iVar4 + 0x76) + (1 - iVar3) * 4 + 0x1e);
      local_e = *(int *)(*(int *)(iVar4 + 0x76) + (1 - iVar3) * 4 + 0x20);
      goto LAB_28eb_460e;
    }
    local_10 = *(int *)(iVar4 + 0x22) + (int)*(char *)(iVar4 + iVar3 * 2 + 0x7a);
    local_e = *(int *)(iVar4 + 0x24);
  }
  local_e = local_e + *(char *)(iVar4 + iVar3 * 2 + 0x7b);
LAB_28eb_460e:
  *param_3 = local_c - local_10;
  *param_4 = local_a - local_e;
  return;
}

