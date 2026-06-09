// TIM2.EXE: FUN_31f7_5716 @ file 0x03C886 Ghidra 0x37686
// Subsystem: misc | Size: 675 bytes


void __cdecl16far FUN_31f7_5716(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar6 = 0x2424;
  FUN_2424_0f94((int)param_1,param_1._2_2_,3);
  uVar5 = (undefined2)((ulong)param_2 >> 0x10);
  iVar4 = (int)param_2;
  iVar1 = *(int *)(iVar4 + 0x22) + (*(int *)(iVar4 + 0x48) >> 1);
  iVar3 = *(int *)(iVar4 + 0x4a) >> 1;
  iVar4 = *(int *)(iVar4 + 0x24) + iVar3;
  if (*(int *)((int)param_1 + 0x4a) < *(int *)((int)param_1 + 0x48)) {
    iVar4 = (iVar1 - 0x40U & 0xfff0) + 8;
    iVar1 = (iVar1 + 0x18U & 0xfff0) + 8;
    if (*(int *)((int)param_1 + 0x22) < iVar4) {
      if (iVar1 < *(int *)((int)param_1 + 0x22) + *(int *)((int)param_1 + 0x48)) {
        iVar2 = FUN_28eb_2f18((int)param_1,param_1._2_2_);
        if (iVar2 == 0 && iVar3 == 0) {
          return;
        }
        FUN_28eb_2a59(iVar2,iVar3,(undefined2 *)&DAT_5b41_054f,0);
        *(uint *)(iVar2 + 10) = *(uint *)(iVar2 + 10) | 0x10;
        *(int *)(iVar2 + 0x48) =
             (*(int *)((int)param_1 + 0x22) + *(int *)((int)param_1 + 0x48)) - iVar1;
        *(int *)(iVar2 + 0x22) = iVar1;
        *(int *)(iVar2 + 0x2e) = iVar1;
        uVar5 = *(undefined2 *)((int)param_1 + 0x24);
        *(undefined2 *)(iVar2 + 0x24) = uVar5;
        *(undefined2 *)(iVar2 + 0x30) = uVar5;
        *(int *)((int)param_1 + 0x48) = iVar4 - *(int *)((int)param_1 + 0x22);
        uVar6 = 0x553b;
        FUN_553b_0101(0x28eb,iVar2,iVar3);
      }
      else if (iVar4 < *(int *)((int)param_1 + 0x22) + *(int *)((int)param_1 + 0x48)) {
        *(int *)((int)param_1 + 0x48) = iVar4 - *(int *)((int)param_1 + 0x22);
      }
    }
    else {
      if (*(int *)((int)param_1 + 0x22) + *(int *)((int)param_1 + 0x48) <= iVar1) {
        if (iVar1 <= *(int *)((int)param_1 + 0x22)) {
          return;
        }
        if (*(int *)((int)param_1 + 0x22) + *(int *)((int)param_1 + 0x48) <= iVar4) {
          return;
        }
        goto LAB_31f7_59ac;
      }
      if (iVar1 <= *(int *)((int)param_1 + 0x22)) {
        return;
      }
      *(int *)((int)param_1 + 0x48) =
           (*(int *)((int)param_1 + 0x22) + *(int *)((int)param_1 + 0x48)) - iVar1;
      *(int *)((int)param_1 + 0x22) = iVar1;
      *(int *)((int)param_1 + 0x2e) = iVar1;
    }
  }
  else {
    iVar1 = (iVar4 - 0x40U & 0xfff0) + 8;
    iVar4 = (iVar4 + 8U & 0xfff0) + 8;
    if (*(int *)((int)param_1 + 0x24) < iVar1) {
      if (iVar4 < *(int *)((int)param_1 + 0x24) + *(int *)((int)param_1 + 0x4a)) {
        iVar2 = FUN_28eb_2f18((int)param_1,param_1._2_2_);
        if (iVar2 == 0 && iVar3 == 0) {
          return;
        }
        FUN_28eb_2a59(iVar2,iVar3,(undefined2 *)&DAT_5b41_054f,0);
        *(uint *)(iVar2 + 10) = *(uint *)(iVar2 + 10) | 0x10;
        *(int *)(iVar2 + 0x4a) =
             (*(int *)((int)param_1 + 0x24) + *(int *)((int)param_1 + 0x4a)) - iVar4;
        uVar5 = *(undefined2 *)((int)param_1 + 0x22);
        *(undefined2 *)(iVar2 + 0x22) = uVar5;
        *(undefined2 *)(iVar2 + 0x2e) = uVar5;
        *(int *)(iVar2 + 0x24) = iVar4;
        *(int *)(iVar2 + 0x30) = iVar4;
        *(int *)((int)param_1 + 0x4a) = iVar1 - *(int *)((int)param_1 + 0x24);
        uVar6 = 0x553b;
        FUN_553b_0101(0x28eb,iVar2,iVar3);
      }
      else if (iVar1 < *(int *)((int)param_1 + 0x24) + *(int *)((int)param_1 + 0x4a)) {
        *(int *)((int)param_1 + 0x4a) = iVar1 - *(int *)((int)param_1 + 0x24);
      }
    }
    else {
      if (*(int *)((int)param_1 + 0x24) + *(int *)((int)param_1 + 0x4a) <= iVar4) {
        if (iVar4 <= *(int *)((int)param_1 + 0x24)) {
          return;
        }
        if (*(int *)((int)param_1 + 0x24) + *(int *)((int)param_1 + 0x4a) <= iVar1) {
          return;
        }
LAB_31f7_59ac:
        *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) | 0x2000;
        return;
      }
      if (iVar4 <= *(int *)((int)param_1 + 0x24)) {
        return;
      }
      *(int *)((int)param_1 + 0x4a) =
           (*(int *)((int)param_1 + 0x24) + *(int *)((int)param_1 + 0x4a)) - iVar4;
      *(int *)((int)param_1 + 0x24) = iVar4;
      *(int *)((int)param_1 + 0x30) = iVar4;
    }
  }
  FUN_553b_0101(uVar6,(int)param_1,param_1._2_2_);
  return;
}

