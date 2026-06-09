// TIM2.EXE: FUN_2424_2afb @ file 0x02BF3B Ghidra 0x26D3B
// Subsystem: misc | Size: 485 bytes


void __cdecl16far FUN_2424_2afb(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  bool bVar8;
  bool bVar9;
  undefined4 local_14;
  int local_10;
  int iStack_e;
  int local_8;
  int local_6;
  int local_4;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  iVar1 = *(int *)(iVar5 + 0x76);
  iStack_e = *(int *)(iVar1 + 6);
  local_10 = *(int *)(iVar1 + 4);
  if ((local_10 != 0 || iStack_e != 0) &&
     (iVar6 = local_10 + (uint)*(byte *)(iVar1 + 0x14) * 4, iVar2 = *(int *)(iVar6 + 0x60),
     iVar6 = *(int *)(iVar6 + 0x5e), local_14 = CONCAT22(iVar2,iVar6), iVar6 == 0 && iVar2 == 0)) {
    uVar3 = *(undefined2 *)(iVar1 + 10);
    uVar4 = *(undefined2 *)(iVar1 + 8);
    goto LAB_2424_2cc3;
  }
  while( true ) {
    if (local_10 == 0 && iStack_e == 0) {
      return;
    }
    if ((int)local_14 == 0 && local_14._2_2_ == 0) break;
    bVar8 = *(int *)(local_10 + 8) != 7;
    if (bVar8) {
      iVar2 = *(int *)(iVar1 + 0x1e) - DAT_5b41_0925;
      local_4 = *(int *)(iVar1 + 0x20) - DAT_5b41_0927;
    }
    else {
      iVar2 = *(int *)(*(int *)(local_10 + 0x76) + 0x22) - DAT_5b41_0925;
      local_4 = *(int *)(*(int *)(local_10 + 0x76) + 0x24) - DAT_5b41_0927;
    }
    bVar9 = *(int *)((int)local_14 + 8) != 7;
    if (bVar9) {
      local_6 = *(int *)(iVar1 + 0x22) - DAT_5b41_0925;
      local_8 = *(int *)(iVar1 + 0x24) - DAT_5b41_0927;
    }
    else {
      local_6 = *(int *)(*(int *)((int)local_14 + 0x76) + 0x1e) - DAT_5b41_0925;
      local_8 = *(int *)(*(int *)((int)local_14 + 0x76) + 0x20) - DAT_5b41_0927;
    }
    if (*(int *)(iVar5 + 8) == 10) {
      DAT_554c_42ce = 0x86;
    }
    else {
      DAT_554c_42ce = 0x85;
    }
    if (bVar9 || bVar8) {
      uVar3 = FUN_28eb_3b36(local_10,iStack_e,iVar1,3);
      FUN_2424_276e(iVar2,local_4,local_6,local_8,uVar3);
    }
    else {
      FUN_2424_27e0(iVar2,local_4,local_6,local_8);
    }
    if ((*(int *)(local_10 + 8) != 0x31) && (*(int *)(local_10 + 8) != 7)) {
      FUN_4551_01dc(*(undefined2 *)(*(int *)(iVar5 + 8) * 2 + 0x68fe),0,iVar2 + -8,local_4 + -7,0);
    }
    if ((*(int *)((int)local_14 + 8) != 0x31) && (*(int *)((int)local_14 + 8) != 7)) {
      FUN_4551_01dc(*(undefined2 *)(*(int *)(iVar5 + 8) * 2 + 0x68fe),0,local_6 + -8,local_8 + -7,0)
      ;
    }
    iStack_e = local_14._2_2_;
    local_10 = (int)local_14;
    iStack_e = local_14._2_2_;
    if (*(int *)((int)local_14 + 8) == 7) {
      uVar3 = *(undefined2 *)((int)local_14 + 0x60);
      uVar4 = *(undefined2 *)((int)local_14 + 0x5e);
LAB_2424_2cc3:
      local_14 = CONCAT22(uVar3,uVar4);
    }
    else {
      local_14 = 0;
    }
  }
  return;
}

