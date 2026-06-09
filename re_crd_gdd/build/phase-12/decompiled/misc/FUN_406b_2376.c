// TIM2.EXE: FUN_406b_2376 @ file 0x047C26 Ghidra 0x42A26
// Subsystem: misc | Size: 833 bytes


void __cdecl16far
FUN_406b_2376(undefined2 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
             undefined1 param_7)

{
  int iVar1;
  undefined2 uVar2;
  int in_DX;
  int extraout_DX;
  int iVar3;
  undefined1 local_60 [6];
  int local_5a;
  int local_58;
  int local_50;
  int local_46;
  int local_44;
  int local_3a;
  int local_32;
  int local_30;
  int local_28;
  int local_26;
  int local_1e;
  int local_1c;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  if ((((DAT_554c_42c4 <= param_3 + param_5) && (param_3 <= DAT_554c_42c6)) &&
      (DAT_554c_42c8 <= param_4 + param_6)) && (param_4 <= DAT_554c_42ca)) {
    for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
      local_6 = FUN_3e34_0ad5(param_1,param_2 + local_8);
      if (local_6 == 0 && in_DX == 0) {
        return;
      }
      local_4 = in_DX;
      FUN_1000_1842(0x3e34,local_6,in_DX,local_60 + local_8 * 10,0x554c);
      in_DX = extraout_DX;
    }
    local_c = (int)DAT_554c_42c3;
    local_e = DAT_554c_42c6;
    local_10 = DAT_554c_42ca;
    DAT_554c_42c3 = 1;
    if ((local_5a + local_14 < param_5) && (local_58 + local_12 < param_6)) {
      DAT_554c_42cc = 1;
      DAT_554c_42cd = param_7;
      DAT_554c_42ce = param_7;
      FUN_1a9e_3854(param_3 + local_5a,param_4 + local_58,(param_5 - local_5a) - local_14,
                    (param_6 - local_58) - local_12);
    }
    iVar1 = param_3 + local_5a;
    iVar3 = DAT_554c_42c6 % 8;
    local_a = ((param_3 + param_5) - local_46) + (7 - iVar3);
    if (DAT_554c_42c4 <= local_a) {
      DAT_554c_42c6 = local_e;
      if (local_a < local_e) {
        DAT_554c_42c6 = local_a;
      }
      local_6 = FUN_3e34_0ad5(param_1,param_2 + 1);
      local_4 = iVar3;
      for (; iVar1 < (param_3 + param_5) - local_46; iVar1 = iVar1 + local_50) {
        FUN_3e34_0160(local_6,local_4,iVar1,param_4,0);
      }
    }
    iVar1 = param_3 + local_28;
    iVar3 = DAT_554c_42c6 % 8;
    local_a = ((param_3 + param_5) - local_14) + (7 - iVar3);
    if (DAT_554c_42c4 <= local_a) {
      DAT_554c_42c6 = local_e;
      if (local_a < local_e) {
        DAT_554c_42c6 = local_a;
      }
      local_6 = FUN_3e34_0ad5(param_1,param_2 + 6);
      local_4 = iVar3;
      for (; iVar1 < (param_3 + param_5) - local_14; iVar1 = iVar1 + local_1e) {
        FUN_3e34_0160(local_6,local_4,iVar1,(param_4 + param_6) - local_1c,0);
      }
    }
    DAT_554c_42c6 = local_e;
    iVar1 = param_4 + local_58;
    local_a = (param_4 + param_6) - local_26;
    if (DAT_554c_42c8 < local_a) {
      DAT_554c_42ca = local_10;
      if (local_a < local_10) {
        DAT_554c_42ca = local_a;
      }
      local_6 = FUN_3e34_0ad5(param_1,param_2 + 3);
      local_4 = iVar3;
      for (; iVar1 < (param_4 + param_6) - local_26; iVar1 = iVar1 + local_3a) {
        FUN_3e34_0160(local_6,local_4,param_3,iVar1,0);
      }
    }
    iVar1 = param_4 + local_44;
    local_a = (param_4 + param_6) - local_12;
    if (DAT_554c_42c8 < local_a) {
      DAT_554c_42ca = local_10;
      if (local_a < local_10) {
        DAT_554c_42ca = local_a;
      }
      local_6 = FUN_3e34_0ad5(param_1,param_2 + 4);
      local_4 = iVar3;
      for (; iVar1 < (param_4 + param_6) - local_12; iVar1 = iVar1 + local_30) {
        FUN_3e34_0160(local_6,local_4,(param_3 + param_5) - local_32,iVar1,0);
      }
    }
    DAT_554c_42ca = local_10;
    uVar2 = FUN_3e34_0ad5(param_1,param_2,param_3,param_4,0);
    FUN_3e34_0160(uVar2,iVar3);
    uVar2 = FUN_3e34_0ad5(param_1,param_2 + 2,(param_3 + param_5) - local_46,param_4,0);
    FUN_3e34_0160(uVar2,iVar3);
    uVar2 = FUN_3e34_0ad5(param_1,param_2 + 5,param_3,(param_4 + param_6) - local_26,0);
    FUN_3e34_0160(uVar2,iVar3);
    uVar2 = FUN_3e34_0ad5(param_1,param_2 + 7,(param_3 + param_5) - local_14,
                          (param_4 + param_6) - local_12,0);
    FUN_3e34_0160(uVar2,iVar3);
    DAT_554c_42c3 = (char)local_c;
    DAT_554c_42c6 = local_e;
    DAT_554c_42ca = local_10;
  }
  return;
}

