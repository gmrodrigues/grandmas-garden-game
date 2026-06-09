// TIM2.EXE: FUN_1000_4ed6 @ file 0x01A0D6 Ghidra 0x14ED6
// Subsystem: utility | Size: 453 bytes


/* WARNING: Type propagation algorithm not settling */

uint FUN_1000_4ed6(int *param_1,uint param_2,byte *param_3)

{
  int *piVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_2;
  if ((*(byte *)(param_1 + 1) & 8) == 0) {
    if ((*(byte *)(param_1 + 1) & 0x40) == 0) {
      if (param_1[3] != 0) {
        do {
          if (param_2 == 0) {
            return uVar6;
          }
          piVar1 = param_1;
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + 1;
          if (SCARRY2(iVar4,1) == *piVar1 < 0) {
            uVar5 = FUN_1000_4d52(*(undefined2 *)param_3,param_1);
          }
          else {
            pbVar3 = (byte *)param_1[5];
            param_1[5] = param_1[5] + 1;
            bVar2 = *param_3;
            *pbVar3 = bVar2;
            uVar5 = (uint)bVar2;
          }
          param_3 = param_3 + 1;
          param_2 = param_2 - 1;
        } while (uVar5 != 0xffff);
        return 0;
      }
      uVar6 = FUN_1000_57f7((int)(char)param_1[2],param_3,param_2);
    }
    else if (param_1[3] == 0) {
      if ((*(byte *)((char)param_1[2] * 2 + 0x5917) & 8) != 0) {
        FUN_1000_1c50((int)(char)param_1[2],0,0,2);
      }
      uVar6 = FUN_1000_5924((int)(char)param_1[2],param_3,param_2);
    }
    else {
      if (param_2 <= (uint)param_1[3]) {
        if (SCARRY2(*param_1,param_2) == (int)(*param_1 + param_2) < 0) {
          if (*param_1 == 0) {
            *param_1 = -1 - param_1[3];
          }
          else {
            iVar4 = FUN_1000_3e17(param_1);
            if (iVar4 != 0) {
              return 0;
            }
          }
        }
        FUN_1000_49eb(param_1[5],param_3,param_2);
        *param_1 = *param_1 + param_2;
        param_1[5] = param_1[5] + param_2;
        return param_2;
      }
      if ((*param_1 != 0) && (iVar4 = FUN_1000_3e17(param_1), iVar4 != 0)) {
        return 0;
      }
      if ((*(byte *)((char)param_1[2] * 2 + 0x5917) & 8) != 0) {
        FUN_1000_1c50((int)(char)param_1[2],0,0,2);
      }
      uVar6 = FUN_1000_5924((int)(char)param_1[2],param_3,param_2);
    }
    if (uVar6 == param_2) {
      return param_2;
    }
  }
  else {
    do {
      if (param_2 == 0) {
        return uVar6;
      }
      iVar4 = FUN_1000_4d6f((int)(char)*param_3,param_1);
      param_2 = param_2 - 1;
      param_3 = param_3 + 1;
    } while (iVar4 != -1);
  }
  return 0;
}

