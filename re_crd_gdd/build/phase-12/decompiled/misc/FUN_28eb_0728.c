// TIM2.EXE: FUN_28eb_0728 @ file 0x02E7D8 Ghidra 0x295D8
// Subsystem: misc | Size: 406 bytes


int __cdecl16far FUN_28eb_0728(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  if ((int)param_1 == 0 && param_1._2_2_ == 0) {
    return (int)param_2;
  }
  if ((int)param_2 == 0 && param_2._2_2_ == 0) {
    return (int)param_1;
  }
  iVar2 = *(int *)((int)param_1 + 8);
  iVar3 = *(int *)((int)param_2 + 8);
  if ((*(uint *)((int)param_1 + 10) & 0x4000) == (*(uint *)((int)param_2 + 10) & 0x4000)) {
    bVar1 = *(byte *)(*(int *)(iVar2 * 2 + 0x302) + 0x20);
    if (bVar1 == *(byte *)(*(int *)(iVar3 * 2 + 0x302) + 0x20)) {
      iVar4 = *(int *)(*(int *)(iVar2 * 2 + 0x302) + 0x38);
      if (iVar4 == *(int *)(*(int *)(iVar3 * 2 + 0x302) + 0x38)) {
        if ((iVar2 == 0xb) && (iVar3 == 0xb)) {
          if (*(int *)((int)param_1 + 0x24) == *(int *)((int)param_2 + 0x24)) {
            if (*(int *)((int)param_2 + 0x22) < *(int *)((int)param_1 + 0x22)) goto LAB_28eb_089f;
          }
          else if (*(int *)((int)param_1 + 0x24) < *(int *)((int)param_2 + 0x24)) {
LAB_28eb_089f:
            bVar5 = true;
            goto LAB_28eb_08a8;
          }
        }
        else if (*(int *)((int)param_1 + 0x24) == *(int *)((int)param_2 + 0x24)) {
          if (*(int *)((int)param_2 + 0x22) < *(int *)((int)param_1 + 0x22)) goto LAB_28eb_089f;
        }
        else if (*(int *)((int)param_2 + 0x24) < *(int *)((int)param_1 + 0x24)) goto LAB_28eb_089f;
LAB_28eb_08a4:
        bVar5 = false;
        goto LAB_28eb_08a8;
      }
      if (*(int *)(*(int *)(iVar3 * 2 + 0x302) + 0x38) <= iVar4) goto LAB_28eb_08a4;
    }
    else if (*(byte *)(*(int *)(iVar3 * 2 + 0x302) + 0x20) <= bVar1) goto LAB_28eb_08a4;
    bVar5 = true;
    goto LAB_28eb_08a8;
  }
  bVar5 = (*(byte *)((int)param_1 + 0xb) & 0x40) == 0;
  iVar2 = *(int *)((int)param_1 + 8);
  if (iVar2 == 0x61) {
LAB_28eb_07a8:
    bVar5 = true;
  }
  else if (iVar2 < 0x62) {
    if ((iVar2 == 0x39) || (iVar2 == 0x58)) goto LAB_28eb_07a8;
  }
  else if (iVar2 == 0x62) goto LAB_28eb_07a8;
  iVar2 = *(int *)((int)param_2 + 8);
  if (iVar2 != 0x61) {
    if (iVar2 < 0x62) {
      if ((iVar2 != 0x39) && (iVar2 != 0x58)) goto LAB_28eb_08a8;
    }
    else if (iVar2 != 0x62) goto LAB_28eb_08a8;
  }
  bVar5 = false;
LAB_28eb_08a8:
  if (bVar5) {
    param_2._0_2_ = (int)param_1;
  }
  return (int)param_2;
}

