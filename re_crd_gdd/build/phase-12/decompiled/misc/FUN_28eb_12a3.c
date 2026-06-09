// TIM2.EXE: FUN_28eb_12a3 @ file 0x02F353 Ghidra 0x2A153
// Subsystem: misc | Size: 758 bytes


uint __cdecl16far FUN_28eb_12a3(undefined4 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = 0;
  if (((iRam000557bc == 1) || (iRam000557bc == 6)) && ((*(byte *)((int)param_1 + 0xf) & 0x10) == 0))
  {
    if ((*(byte *)((int)param_1 + 0xe) & 0x40) == 0) {
      uVar6 = 0x10;
    }
    else {
      uVar6 = 0x400;
    }
  }
  if (((*(byte *)((int)param_1 + 0xf) & 0x10) == 0) && ((DAT_5b41_051f & 0x10) == 0)) {
    uVar6 = uVar6 | 0x20;
  }
  if ((*(byte *)((int)param_1 + 0xf) & 0x10) != 0) {
    uVar6 = uVar6 | 0x3000;
  }
  if ((*(byte *)((int)param_1 + 0xe) & 0x40) != 0) {
    return uVar6;
  }
  uVar7 = uVar6 | 0x140;
  if (*(int *)((int)param_1 + 8) == 8) {
    return uVar7;
  }
  if (*(int *)((int)param_1 + 8) == 10) {
    return uVar7;
  }
  if (*(int *)((int)param_1 + 8) == 0x4c) {
    return uVar7;
  }
  if ((*(byte *)((int)param_1 + 0xc) & 0x80) != 0) {
    uVar7 = uVar6 | 0x141;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 1) != 0) {
    uVar7 = uVar7 | 2;
  }
  if (((*(byte *)((int)param_1 + 0xb) & 4) == 0) || ((*(byte *)((int)param_1 + 0xb) & 2) == 0)) {
    if ((*(byte *)((int)param_1 + 0xb) & 4) != 0) {
      if (DAT_5b41_0939 == 9) {
        uVar7 = uVar7 | 4;
      }
      else {
        DAT_5b41_050f = 1;
        puVar2 = (undefined2 *)(*(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302) + 0xc);
        (*(code *)*puVar2)(0x28eb,(int)param_1,param_1._2_2_,1);
        *(undefined2 *)((int)param_1 + 0xac) = *(undefined2 *)((int)param_1 + 0xc);
        iVar5 = FUN_28eb_0119((int)param_1,param_1._2_2_);
        if ((iVar5 == 0) &&
           ((*(int *)((int)param_1 + 0x58) == 0 ||
            (iVar5 = FUN_28eb_1c08(*(undefined2 *)((int)param_1 + 0x58)), iVar5 != 0)))) {
          uVar7 = uVar7 | 4;
        }
        puVar2 = (undefined2 *)(*(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302) + 0xc);
        (*(code *)*puVar2)(0x28eb,(int)param_1,param_1._2_2_,1);
        *(undefined2 *)((int)param_1 + 0xac) = *(undefined2 *)((int)param_1 + 0xc);
        DAT_5b41_050f = 0;
      }
    }
    if ((*(byte *)((int)param_1 + 0xb) & 2) == 0) goto LAB_28eb_155d;
    if (DAT_5b41_0939 == 9) {
      uVar7 = uVar7 | 8;
      goto LAB_28eb_155d;
    }
    DAT_5b41_050f = 1;
    puVar2 = (undefined2 *)(*(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302) + 0xc);
    (*(code *)*puVar2)(0x28eb,(int)param_1,param_1._2_2_,2);
    *(undefined2 *)((int)param_1 + 0xac) = *(undefined2 *)((int)param_1 + 0xc);
    iVar5 = FUN_28eb_0119((int)param_1,param_1._2_2_);
    if ((iVar5 == 0) &&
       ((*(int *)((int)param_1 + 0x58) == 0 ||
        (iVar5 = FUN_28eb_1c08(*(undefined2 *)((int)param_1 + 0x58)), iVar5 != 0)))) {
      uVar7 = uVar7 | 8;
    }
    puVar2 = (undefined2 *)(*(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302) + 0xc);
    (*(code *)*puVar2)(0x28eb,(int)param_1,param_1._2_2_,2);
    *(undefined2 *)((int)param_1 + 0xac) = *(undefined2 *)((int)param_1 + 0xc);
  }
  else {
    if (DAT_5b41_0939 == 9) {
      uVar7 = uVar7 | 0xc;
      goto LAB_28eb_155d;
    }
    iVar5 = *(int *)((int)param_1 + 0x10);
    iVar1 = *(int *)((int)param_1 + 0xc);
    DAT_5b41_050f = 1;
    bVar3 = false;
    do {
      puVar2 = (undefined2 *)(*(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302) + 0xc);
      (*(code *)*puVar2)(0x28eb,(int)param_1,param_1._2_2_,0xf);
      *(undefined2 *)((int)param_1 + 0xac) = *(undefined2 *)((int)param_1 + 0xc);
      if ((*(int *)((int)param_1 + 0x10) == iVar5) && (*(int *)((int)param_1 + 0xc) == iVar1)) {
LAB_28eb_13e7:
        bVar3 = true;
      }
      else {
        iVar4 = FUN_28eb_0119((int)param_1,param_1._2_2_);
        if ((iVar4 == 0) &&
           ((*(int *)((int)param_1 + 0x58) == 0 ||
            (iVar4 = FUN_28eb_1c08(*(undefined2 *)((int)param_1 + 0x58)), iVar4 != 0)))) {
          uVar7 = uVar7 | 0xc;
          goto LAB_28eb_13e7;
        }
      }
    } while (!bVar3);
    *(int *)((int)param_1 + 0x10) = iVar5;
    *(int *)((int)param_1 + 0xc) = iVar1;
    *(int *)((int)param_1 + 0xac) = iVar1;
    puVar2 = (undefined2 *)(*(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302) + 0xc);
    (*(code *)*puVar2)(0x28eb,(int)param_1,param_1._2_2_,0);
  }
  DAT_5b41_050f = 0;
LAB_28eb_155d:
  if ((*(byte *)((int)param_1 + 0xf) & 4) != 0) {
    if ((uVar7 & 1) == 0) {
      uVar7 = uVar7 | 0x80;
    }
    else {
      uVar7 = uVar7 | 0x800;
    }
  }
  if (((iRam000557bc == 1) || (iRam000557bc == 6)) && ((*(byte *)((int)param_1 + 0xf) & 0x80) != 0))
  {
    uVar7 = uVar7 | 0x200;
  }
  return uVar7;
}

