// TIM2.EXE: FUN_31f7_05a1 @ file 0x037711 Ghidra 0x32511
// Subsystem: misc | Size: 294 bytes


undefined2 __cdecl16far
FUN_31f7_05a1(undefined2 param_1,undefined2 param_2,undefined4 param_3,int param_4,uint param_5,
             undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 local_4;
  
  uVar7 = (undefined2)((ulong)param_3 >> 0x10);
  iVar5 = (int)param_3;
  iVar1 = *(int *)(iVar5 + param_4 * 2 + 0x76);
  uVar4 = param_5 & 7;
  if ((uVar4 != 1) && (*(int *)(iVar1 + 0x18) != 0)) {
    if ((param_5 & 0x8000) == 0) {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
    }
    return 0;
  }
  uVar2 = *(undefined2 *)(iVar5 + 0x16);
  iVar6 = 0;
  if (uVar4 == 4) {
    if (param_4 == 0) {
      iVar3 = *(int *)(iVar5 + 0x10);
      goto joined_r0x000325a8;
    }
    iVar3 = *(int *)(iVar5 + 0x10);
joined_r0x00032597:
    if (iVar3 != 2) {
      local_4 = 1;
      goto LAB_31f7_0644;
    }
  }
  else {
    if (uVar4 != 2) goto LAB_31f7_0644;
    if (param_4 == 0) {
      iVar3 = *(int *)(iVar5 + 0x10);
      goto joined_r0x00032597;
    }
    iVar3 = *(int *)(iVar5 + 0x10);
joined_r0x000325a8:
    if (iVar3 != 0) {
      local_4 = 0xffff;
      goto LAB_31f7_0644;
    }
  }
  iVar6 = 1;
LAB_31f7_0644:
  if ((iVar6 == 0) && (uVar4 != 1)) {
    *(undefined2 *)(iVar5 + 0x16) = local_4;
    iVar6 = FUN_31f7_06c7(param_1,param_2,iVar5,uVar7,param_5 & 0x8000,param_6,param_7,param_8);
    if ((param_5 & 0x8000) == 0) {
      if (iVar6 == 0) {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x400;
      }
    }
    else {
      *(undefined2 *)(iVar5 + 0x16) = uVar2;
    }
  }
  if (iVar6 != 0) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x200;
  }
  if ((*(byte *)(iVar5 + 0xd) & 2) == 0) {
    if ((param_5 & 0x8007) == 1) {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  return uVar7;
}

