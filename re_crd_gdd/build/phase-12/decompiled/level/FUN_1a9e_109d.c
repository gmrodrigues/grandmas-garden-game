// TIM2.EXE: FUN_1a9e_109d @ file 0x020C7D Ghidra 0x1BA7D
// Subsystem: level | Size: 353 bytes


uint __cdecl16far FUN_1a9e_109d(undefined2 param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 uVar4;
  bool bVar5;
  undefined4 uVar6;
  uint local_6;
  int local_4;
  
  iVar1 = FUN_1a9e_03bd(param_1);
  if (iVar1 == 0) {
    return 0xffff;
  }
  local_4 = 0;
  local_6 = 0;
  if (param_4 == 1) {
    local_4 = *(int *)(DAT_5b41_0042 + 0x18);
    local_6 = *(uint *)(DAT_5b41_0042 + 0x16);
  }
  else if (param_4 == 2) {
    local_4 = *(int *)(DAT_5b41_0042 + 0x14);
    local_6 = *(uint *)(DAT_5b41_0042 + 0x12);
  }
  bVar5 = CARRY2(local_6,param_2);
  local_6 = local_6 + param_2;
  local_4 = local_4 + param_3 + (uint)bVar5;
  if ((*(int *)(DAT_5b41_0042 + 0x18) == local_4) && (*(uint *)(DAT_5b41_0042 + 0x16) == local_6)) {
    return local_6;
  }
  if ((*(int *)(DAT_5b41_0042 + 0x18) < local_4) ||
     ((*(int *)(DAT_5b41_0042 + 0x18) <= local_4 && (*(uint *)(DAT_5b41_0042 + 0x16) <= local_6))))
  {
    if ((local_4 < *(int *)(DAT_5b41_0042 + 0x14)) ||
       ((*(int *)(DAT_5b41_0042 + 0x14) == local_4 && (local_6 < *(uint *)(DAT_5b41_0042 + 0x12)))))
    {
      bVar5 = local_6 < *(uint *)(DAT_5b41_0042 + 0x16);
      local_6 = local_6 - *(uint *)(DAT_5b41_0042 + 0x16);
      local_4 = (local_4 - *(int *)(DAT_5b41_0042 + 0x18)) - (uint)bVar5;
    }
    else {
      local_6 = *(uint *)(DAT_5b41_0042 + 0x12) - *(uint *)(DAT_5b41_0042 + 0x16);
      local_4 = (*(int *)(DAT_5b41_0042 + 0x14) - *(int *)(DAT_5b41_0042 + 0x18)) -
                (uint)(*(uint *)(DAT_5b41_0042 + 0x12) < *(uint *)(DAT_5b41_0042 + 0x16));
      DAT_5b41_02eb = CONCAT22(DAT_5b41_02eb._2_2_,(undefined2)DAT_5b41_02eb);
    }
  }
  else {
    FUN_1a9e_1202(param_1);
    DAT_5b41_02eb = CONCAT22(DAT_5b41_02eb._2_2_,(undefined2)DAT_5b41_02eb);
    if ((local_4 < 1) &&
       ((local_4 != 0 ||
        (DAT_5b41_02eb = CONCAT22(DAT_5b41_02eb._2_2_,(undefined2)DAT_5b41_02eb), local_6 == 0)))) {
      return 0;
    }
  }
  while( true ) {
    if ((0 < local_4) || ((uVar3 = local_6, -1 < local_4 && (31999 < local_6)))) {
      uVar3 = 32000;
    }
    uVar3 = FUN_1a9e_075d(param_1,uVar3);
    bVar5 = local_6 < uVar3;
    local_6 = local_6 - uVar3;
    local_4 = local_4 - (uint)bVar5;
    if (local_6 == 0 && local_4 == 0) break;
    uVar4 = *(undefined2 *)(DAT_5b41_0042 + 8);
    uVar2 = FUN_1000_1a88();
    uVar6 = func_0x000106aa(0x1000,uVar2,uVar4);
    DAT_5b41_02eb = uVar6;
  }
  return *(uint *)(DAT_5b41_0042 + 0x16);
}

