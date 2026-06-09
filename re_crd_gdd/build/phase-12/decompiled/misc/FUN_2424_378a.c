// TIM2.EXE: FUN_2424_378a @ file 0x02CBCA Ghidra 0x279CA
// Subsystem: misc | Size: 737 bytes


undefined2 __cdecl16far FUN_2424_378a(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = 0;
  iVar7 = 0;
  iVar8 = (int)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if (*(int *)(iVar4 + 0x4a) == 0x10) {
    if (*(int *)(iVar4 + 0x4a) == 0x10) {
      FUN_2424_4ae2(iVar4,iVar8,0x2000,0xfff0,0,0,0x10);
      iVar5 = iVar4;
      iVar9 = iVar8;
      while( true ) {
        iVar1 = *(int *)(iVar5 + 0x8e);
        iVar5 = *(int *)(iVar5 + 0x8c);
        if ((iVar5 == 0 && iVar1 == 0) || (iVar6 != 0)) break;
        iVar9 = iVar1;
        if ((*(int *)(iVar5 + 0x4a) != 0x10) && (iVar2 = FUN_2424_4087(iVar5,iVar1), iVar2 != 0)) {
          if (*(int *)(iVar5 + 0x24) == *(int *)(iVar4 + 0x24)) {
            iVar6 = 1;
          }
          else if (*(int *)(iVar5 + 0x24) + *(int *)(iVar5 + 0x4a) ==
                   *(int *)(iVar4 + 0x24) + *(int *)(iVar4 + 0x4a)) {
            iVar6 = 5;
          }
          else {
            iVar6 = 3;
          }
        }
      }
      FUN_2424_4ae2(iVar4,iVar8,0x2000,*(undefined2 *)(iVar4 + 0x48),*(int *)(iVar4 + 0x48) + 0x10,0
                    ,0x10);
      iVar5 = iVar4;
      iVar9 = iVar8;
      while( true ) {
        iVar1 = *(int *)(iVar5 + 0x8e);
        iVar5 = *(int *)(iVar5 + 0x8c);
        if ((iVar5 == 0 && iVar1 == 0) || (iVar7 != 0)) break;
        iVar9 = iVar1;
        if ((*(int *)(iVar5 + 0x4a) != 0x10) && (iVar2 = FUN_2424_4087(iVar5,iVar1), iVar2 != 0)) {
          if (*(int *)(iVar5 + 0x24) == *(int *)(iVar4 + 0x24)) {
            iVar7 = 2;
          }
          else if (*(int *)(iVar5 + 0x24) + *(int *)(iVar5 + 0x4a) ==
                   *(int *)(iVar4 + 0x24) + *(int *)(iVar4 + 0x4a)) {
            iVar7 = 6;
          }
          else {
            iVar7 = 4;
          }
        }
      }
    }
  }
  else {
    FUN_2424_4ae2(iVar4,iVar8,0x2000,0,0x10,0xfff0,0);
    iVar5 = iVar4;
    iVar9 = iVar8;
    while( true ) {
      iVar1 = *(int *)(iVar5 + 0x8e);
      iVar5 = *(int *)(iVar5 + 0x8c);
      if ((iVar5 == 0 && iVar1 == 0) || (iVar6 != 0)) break;
      iVar9 = iVar1;
      if ((*(int *)(iVar5 + 0x4a) == 0x10) && (iVar2 = FUN_2424_4087(iVar5,iVar1), iVar2 != 0)) {
        if (*(int *)(iVar5 + 0x22) == *(int *)(iVar4 + 0x22)) {
          iVar6 = 7;
        }
        else if (*(int *)(iVar5 + 0x22) + *(int *)(iVar5 + 0x48) ==
                 *(int *)(iVar4 + 0x22) + *(int *)(iVar4 + 0x48)) {
          iVar6 = 9;
        }
        else {
          iVar6 = 8;
        }
      }
    }
    FUN_2424_4ae2(iVar4,iVar8,0x2000,0,0x10,*(undefined2 *)(iVar4 + 0x4a),
                  *(int *)(iVar4 + 0x4a) + 0x10);
    iVar5 = iVar4;
    iVar9 = iVar8;
    while( true ) {
      iVar1 = *(int *)(iVar5 + 0x8e);
      iVar5 = *(int *)(iVar5 + 0x8c);
      if ((iVar5 == 0 && iVar1 == 0) || (iVar7 != 0)) break;
      iVar9 = iVar1;
      if ((*(int *)(iVar5 + 0x4a) == 0x10) && (iVar2 = FUN_2424_4087(iVar5,iVar1), iVar2 != 0)) {
        if (*(int *)(iVar5 + 0x22) == *(int *)(iVar4 + 0x22)) {
          iVar7 = 10;
        }
        else if (*(int *)(iVar5 + 0x22) + *(int *)(iVar5 + 0x48) ==
                 *(int *)(iVar4 + 0x22) + *(int *)(iVar4 + 0x48)) {
          iVar7 = 0xc;
        }
        else {
          iVar7 = 0xb;
        }
      }
    }
  }
  if ((*(int *)(iVar4 + 0xae) != iVar6) || (*(int *)(iVar4 + 0xb4) != iVar7)) {
    FUN_2424_3746(iVar4,iVar8,1);
    FUN_2424_3746(iVar4,iVar8,2);
    *(int *)(iVar4 + 0xae) = iVar6;
    *(int *)(iVar4 + 0xb4) = iVar7;
    FUN_2424_3746(iVar4,iVar8,1);
    FUN_2424_3746(iVar4,iVar8,2);
  }
  *(int *)(iVar4 + 0xae) = iVar6;
  *(int *)(iVar4 + 0xb4) = iVar7;
  if ((iVar6 == 0) && (iVar7 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

