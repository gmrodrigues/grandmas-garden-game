// TIM2.EXE: FUN_2424_40d8 @ file 0x02D518 Ghidra 0x28318
// Subsystem: misc | Size: 995 bytes


undefined2 __cdecl16far FUN_2424_40d8(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  int local_a;
  int local_8;
  
  local_8 = 0;
  local_a = 0;
  iVar5 = (int)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  bVar7 = (*(byte *)(iVar3 + 0xc) & 0x30) != 0;
  if (*(int *)(iVar3 + 0x48) == 0x20) {
    FUN_2424_4ae2(iVar3,iVar5,0x2000,0,0x10,0xfff0,0);
    iVar4 = iVar3;
    iVar6 = iVar5;
    while( true ) {
      iVar1 = *(int *)(iVar4 + 0x8e);
      iVar4 = *(int *)(iVar4 + 0x8c);
      if ((iVar4 == 0 && iVar1 == 0) || (local_8 != 0)) break;
      iVar6 = iVar1;
      if (((*(int *)(iVar4 + 8) == 0x76) && (*(int *)(iVar4 + 0x4a) == 0x20)) &&
         (*(int *)(iVar4 + 0x24) == *(int *)(iVar3 + 0x24) + -0x20)) {
        bVar8 = (*(byte *)(iVar4 + 0xc) & 0x30) != 0;
        if (((bVar7) || (bVar8)) || (*(int *)(iVar4 + 0x22) != *(int *)(iVar3 + 0x22))) {
          if (((bVar7) && (!bVar8)) &&
             (*(int *)(iVar4 + 0x22) + *(int *)(iVar4 + 0x48) ==
              *(int *)(iVar3 + 0x22) + *(int *)(iVar3 + 0x48))) {
            local_8 = 9;
          }
        }
        else {
          local_8 = 7;
        }
      }
    }
    FUN_2424_4ae2(iVar3,iVar5,0x2000,0,0x10,*(undefined2 *)(iVar3 + 0x4a),
                  *(int *)(iVar3 + 0x4a) + 0x10);
    iVar4 = iVar3;
    iVar6 = iVar5;
    while( true ) {
      iVar1 = *(int *)(iVar4 + 0x8e);
      iVar4 = *(int *)(iVar4 + 0x8c);
      if ((iVar4 == 0 && iVar1 == 0) || (local_a != 0)) break;
      iVar6 = iVar1;
      if ((*(int *)(iVar4 + 8) == 0x76) &&
         ((*(int *)(iVar4 + 0x4a) == 0x20 &&
          (*(int *)(iVar3 + 0x24) + *(int *)(iVar3 + 0x4a) == *(int *)(iVar4 + 0x24))))) {
        bVar8 = (*(byte *)(iVar4 + 0xc) & 0x30) == 0;
        if ((bVar7) || ((bVar8 || (*(int *)(iVar4 + 0x22) != *(int *)(iVar3 + 0x22))))) {
          if ((bVar7) &&
             ((!bVar8 &&
              (*(int *)(iVar4 + 0x22) + *(int *)(iVar4 + 0x48) ==
               *(int *)(iVar3 + 0x22) + *(int *)(iVar3 + 0x48))))) {
            local_a = 0xc;
          }
        }
        else {
          local_a = 10;
        }
      }
    }
  }
  else if (*(int *)(iVar3 + 0x4a) == 0x20) {
    FUN_2424_4ae2(iVar3,iVar5,0x2000,0xfff0,0,0,0x10);
    iVar4 = iVar3;
    iVar6 = iVar5;
    while( true ) {
      iVar1 = *(int *)(iVar4 + 0x8e);
      iVar4 = *(int *)(iVar4 + 0x8c);
      if ((iVar4 == 0 && iVar1 == 0) || (local_8 != 0)) break;
      iVar6 = iVar1;
      if (((*(int *)(iVar4 + 8) == 0x76) && (*(int *)(iVar4 + 0x48) == 0x20)) &&
         (*(int *)(iVar4 + 0x22) == *(int *)(iVar3 + 0x22) + -0x20)) {
        bVar8 = (*(byte *)(iVar4 + 0xc) & 0x30) != 0;
        if (((bVar7) || (bVar8)) || (*(int *)(iVar4 + 0x24) != *(int *)(iVar3 + 0x24))) {
          if (((bVar7) && (!bVar8)) &&
             (*(int *)(iVar4 + 0x24) + *(int *)(iVar4 + 0x4a) ==
              *(int *)(iVar3 + 0x24) + *(int *)(iVar3 + 0x4a))) {
            local_8 = 5;
          }
        }
        else {
          local_8 = 1;
        }
      }
    }
    FUN_2424_4ae2(iVar3,iVar5,0x2000,*(undefined2 *)(iVar3 + 0x48),*(int *)(iVar3 + 0x48) + 0x10,0,
                  0x10);
    iVar4 = iVar3;
    iVar6 = iVar5;
    while( true ) {
      iVar1 = *(int *)(iVar4 + 0x8e);
      iVar4 = *(int *)(iVar4 + 0x8c);
      if ((iVar4 == 0 && iVar1 == 0) || (local_a != 0)) break;
      iVar6 = iVar1;
      if ((*(int *)(iVar4 + 8) == 0x76) &&
         ((*(int *)(iVar4 + 0x48) == 0x20 &&
          (*(int *)(iVar3 + 0x22) + *(int *)(iVar3 + 0x48) == *(int *)(iVar4 + 0x22))))) {
        bVar8 = (*(byte *)(iVar4 + 0xc) & 0x30) == 0;
        if ((bVar7) || ((bVar8 || (*(int *)(iVar4 + 0x24) != *(int *)(iVar3 + 0x24))))) {
          if ((bVar7) &&
             ((!bVar8 &&
              (*(int *)(iVar4 + 0x24) + *(int *)(iVar4 + 0x4a) ==
               *(int *)(iVar3 + 0x24) + *(int *)(iVar3 + 0x4a))))) {
            local_a = 6;
          }
        }
        else {
          local_a = 2;
        }
      }
    }
  }
  if ((*(int *)(iVar3 + 0xae) != local_8) || (*(int *)(iVar3 + 0xb4) != local_a)) {
    FUN_2424_3746(iVar3,iVar5,1);
    FUN_2424_3746(iVar3,iVar5,2);
    *(int *)(iVar3 + 0xae) = local_8;
    *(int *)(iVar3 + 0xb4) = local_a;
    FUN_2424_3746(iVar3,iVar5,1);
    FUN_2424_3746(iVar3,iVar5,2);
  }
  *(int *)(iVar3 + 0xae) = local_8;
  *(int *)(iVar3 + 0xb4) = local_a;
  if ((local_8 == 0) && (local_a == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

