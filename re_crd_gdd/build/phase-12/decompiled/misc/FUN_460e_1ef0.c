// TIM2.EXE: FUN_460e_1ef0 @ file 0x04D1D0 Ghidra 0x47FD0
// Subsystem: misc | Size: 479 bytes


undefined2 __cdecl16far FUN_460e_1ef0(uint param_1)

{
  undefined2 uVar1;
  uint uVar2;
  uint in_DX;
  int iVar3;
  int iVar4;
  uint local_1a6 [200];
  uint local_16;
  int local_14;
  uint local_12;
  int local_10;
  uint local_e;
  uint local_c;
  uint local_a;
  uint local_8;
  uint local_6;
  uint local_4;
  
  local_8 = 0;
  local_a = 0;
  if (DAT_554c_5744 == 0 && DAT_554c_5746 == 0) {
    uVar1 = 0;
  }
  else {
    if (param_1 == 0) {
      param_1 = 0x2801;
    }
    if (DAT_5b41_1cea != '\0') {
      FUN_460e_20cf();
    }
    FUN_1000_135d(DAT_554c_575e);
    iVar4 = 0;
    while ((iVar4 < 100 && (local_a == 0 && local_8 == 0))) {
      local_e = FUN_1a9e_539c(0xffff,0xffff,0,0);
      local_c = in_DX;
      if (((local_e != 0 || in_DX != 0) && (-1 < (int)in_DX)) &&
         ((in_DX != 0 || (param_1 <= local_e)))) {
        local_6 = FUN_1a9e_539c(local_e,in_DX,0,0);
        local_4 = in_DX;
        if (local_6 != 0 || in_DX != 0) {
          iVar3 = 0;
          uVar2 = FUN_1000_199e();
          local_16 = uVar2 + local_6;
          local_10 = iVar3 + (uint)CARRY2(uVar2,local_6);
          local_12 = local_16;
          local_14 = 0;
          if (((true < CARRY2(param_1,local_16)) || (CARRY2(param_1,local_16))) ||
             (iVar3 = FUN_4bdc_3f75(local_6,local_4,param_1,0), in_DX = local_4, iVar3 != 0)) {
            uVar2 = -local_16;
            local_14 = (1 - local_14) - (uint)(local_16 != 0);
            local_16 = uVar2;
            if ((-1 < local_14) && ((0 < local_14 || (0x10 < uVar2)))) {
              FUN_4bdc_3f75(local_6,local_4,uVar2 - 0x10,local_14 + -1 + (uint)(0xf < uVar2));
            }
            in_DX = local_4;
            uVar2 = local_6;
            local_1a6[iVar4 * 2 + 1] = local_4;
            local_1a6[iVar4 * 2] = uVar2;
          }
          else {
            local_8 = local_4;
            local_a = local_6;
            local_1a6[iVar4 * 2 + 1] = 0;
            local_1a6[iVar4 * 2] = 0;
          }
        }
      }
      iVar4 = iVar4 + 1;
    }
    while (iVar3 = iVar4 + -1, iVar4 != 0) {
      iVar4 = iVar3;
      if (local_1a6[iVar3 * 2] != 0 || local_1a6[iVar3 * 2 + 1] != 0) {
        FUN_1a9e_5415(local_1a6[iVar3 * 2],local_1a6[iVar3 * 2 + 1]);
      }
    }
    if (local_a != 0 || local_8 != 0) {
      DAT_554c_3fd2 = local_8;
      DAT_554c_3fd0 = local_a;
      DAT_5b41_1cea = '\x01';
      DAT_5b41_1ced = param_1;
      DAT_5b41_1cf1 = FUN_1a9e_3ec6(0x2412,0x460e,4);
    }
    if (local_a == 0 && local_8 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

