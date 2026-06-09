// TIM2.EXE: FUN_1000_5ffc @ file 0x01B1FC Ghidra 0x15FFC
// Subsystem: utility | Size: 339 bytes


undefined2 __cdecl16near
FUN_1000_5ffc(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined4 local_6;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  local_6 = (int *)CONCAT22(uVar7,(int *)(iVar5 + *(int *)(iVar5 + 0xc)));
  do {
    uVar8 = (undefined2)((ulong)local_6 >> 0x10);
    piVar6 = (int *)local_6;
    iVar3 = piVar6[1];
    iVar4 = *local_6;
    if (iVar4 == 0 && iVar3 == 0) {
      local_6 = (int *)CONCAT22(uVar7,(int *)(iVar5 + *(int *)(iVar5 + 10)));
      while( true ) {
        uVar7 = (undefined2)((ulong)local_6 >> 0x10);
        piVar6 = (int *)local_6;
        iVar5 = piVar6[1];
        iVar3 = *local_6;
        if (iVar3 == 0 && iVar5 == 0) {
          return 0;
        }
        if ((param_6 == 0) || ((piVar6[3] & 3U) != 3)) {
          iVar4 = 0;
        }
        else {
          iVar4 = 1;
        }
        iVar1 = FUN_1000_5f71(param_2,param_3,iVar3,iVar5);
        if (((iVar1 != 0) && (iVar4 != 0)) ||
           (((*(byte *)(iVar3 + 8) & 4) != 0 &&
            (iVar5 = FUN_1000_5ffc(iVar3,iVar5,param_2,param_3,param_4,param_5,iVar4), iVar5 != 0)))
           ) break;
        local_6 = (int *)CONCAT22(uVar7,piVar6 + 4);
      }
      return 1;
    }
    if ((*(byte *)(piVar6 + 3) & 8) == 0) {
      if ((param_6 == 0) || ((piVar6[3] & 3U) != 3)) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
      iVar2 = FUN_1000_5f71(param_2,param_3,iVar4,iVar3);
      if ((iVar2 != 0) && (iVar1 != 0)) {
        return 1;
      }
      if (((*(byte *)(iVar4 + 8) & 4) != 0) &&
         (iVar3 = FUN_1000_5ffc(iVar4,iVar3,param_2,param_3,param_4,param_5,iVar1), iVar3 != 0)) {
        return 1;
      }
    }
    local_6 = (int *)CONCAT22(uVar8,piVar6 + 4);
  } while( true );
}

