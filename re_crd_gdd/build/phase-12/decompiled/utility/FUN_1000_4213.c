// TIM2.EXE: FUN_1000_4213 @ file 0x019413 Ghidra 0x14213
// Subsystem: utility | Size: 243 bytes


uint FUN_1000_4213(int *param_1,uint param_2,undefined1 *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint in_DX;
  uint local_4;
  
  do {
    while( true ) {
      if (param_2 == 0) {
        return 0;
      }
      uVar2 = param_2 + 1;
      local_4 = uVar2;
      if ((uint)param_1[3] <= uVar2) {
        local_4 = param_1[3];
      }
      if (((((*(byte *)(param_1 + 1) & 0x40) == 0) || (param_1[3] == 0)) ||
          (uVar2 <= (uint)param_1[3])) || (*param_1 != 0)) break;
      local_4 = 0;
      for (; (uint)param_1[3] <= param_2; param_2 = param_2 - param_1[3]) {
        local_4 = local_4 + param_1[3];
      }
      in_DX = FUN_1000_2006((int)(char)param_1[2],param_3,local_4);
      if (in_DX == 0xffff) {
        in_DX = 0;
        param_1[1] = param_1[1] | 0x10;
      }
      param_3 = param_3 + in_DX;
      if (in_DX != local_4) {
        param_2 = param_2 + (local_4 - in_DX);
        goto LAB_1000_42aa;
      }
    }
    while ((param_2 = uVar2, param_2 = param_2 - 1, param_2 != 0 &&
           (local_4 = local_4 - 1, local_4 != 0))) {
      piVar1 = param_1;
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      if (SBORROW2(iVar3,1) == *piVar1 < 0) {
        pbVar4 = (byte *)param_1[5];
        param_1[5] = param_1[5] + 1;
        in_DX = (uint)*pbVar4;
      }
      else {
        in_DX = FUN_1000_4807(param_1);
      }
      if (in_DX == 0xffff) break;
      *param_3 = (char)in_DX;
      param_3 = param_3 + 1;
      uVar2 = param_2;
    }
  } while (in_DX != 0xffff);
LAB_1000_42aa:
  param_1[1] = param_1[1] | 0x20;
  return param_2;
}

