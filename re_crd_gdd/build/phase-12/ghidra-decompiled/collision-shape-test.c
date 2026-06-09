// TIM2.EXE decompiled function: FUN_4bdc_368d
// Source: file offset 0x054760 → Ghidra 0x4F560
// Body: 0x4F44D - 0x4F710
// Size: 706 bytes


int __cdecl16far FUN_4bdc_368d(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  int *piVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined4 local_e;
  uint local_a;
  int local_8;
  uint local_6;
  int local_4;
  
  if (((param_2 == 0) || (param_1 != DAT_554c_5752)) || (DAT_554c_5752 == 0)) {
    if ((DAT_554c_5752 != param_1) && (DAT_554c_5754 != 0)) {
      FUN_1a9e_6e73(DAT_554c_5752);
      DAT_554c_5752 = 0;
      DAT_554c_5754 = 0;
    }
    iVar2 = FUN_1a9e_6ea7(param_1);
    if (iVar2 == 0) {
      DAT_554c_5752 = FUN_1a9e_69e9(param_1);
      if (DAT_554c_5752 == 0) goto LAB_4bdc_38f5;
      DAT_554c_5754 = 1;
    }
    else {
      DAT_554c_5752 = param_1;
    }
    FUN_4bdc_32e9(0);
    FUN_1000_0e6d(DAT_554c_5752,0xc,0,0);
    iVar2 = FUN_1000_0d10(&local_a,4,1,DAT_554c_5752);
    if (iVar2 != 1) goto LAB_4bdc_38f5;
    if ((int *)DAT_554c_574e != (int *)0x0 || DAT_554c_574e._2_2_ != 0) {
      FUN_2e67_10e9((int *)DAT_554c_574e,DAT_554c_574e._2_2_,10);
    }
    iVar2 = local_a + 4;
    piVar4 = (int *)FUN_2e67_0edd(iVar2,local_8 + (uint)(0xfffb < local_a),10);
    DAT_554c_574e = (int *)CONCAT22(iVar2,piVar4);
    if (piVar4 == (int *)0x0 && iVar2 == 0) goto LAB_4bdc_38f5;
    iVar3 = 1;
    iVar2 = FUN_1000_0de2(piVar4 + 2,iVar2,local_a,local_8,1,0,DAT_554c_5752);
    piVar1 = DAT_554c_574e;
    if ((iVar3 != 0) || (iVar2 != 1)) goto LAB_4bdc_38f5;
    iVar2 = (int)((ulong)DAT_554c_574e >> 0x10);
    piVar4 = (int *)DAT_554c_574e;
    if (piVar4[2] != 2) goto LAB_4bdc_38f5;
    in_DX = (int)piVar4 + 9;
    piVar4[1] = iVar2;
    *piVar1 = in_DX;
  }
  if ((0 < param_2) && (iVar2 = FUN_4bdc_3951(param_2), iVar2 != 0 || in_DX != 0)) {
    return DAT_554c_5752;
  }
  uVar5 = (undefined2)((ulong)DAT_554c_574e >> 0x10);
  local_e = (int *)CONCAT22(((int *)DAT_554c_574e)[1],(int *)*DAT_554c_574e);
  if (param_2 < 1) {
    for (iVar2 = 0; iVar2 < ((int *)DAT_554c_574e)[3]; iVar2 = iVar2 + 1) {
      uVar5 = (undefined2)((ulong)local_e >> 0x10);
      piVar4 = (int *)local_e;
      iVar3 = FUN_1000_0e6d(DAT_554c_5752,piVar4[1] + 4,piVar4[2] + (uint)(0xfffb < (uint)piVar4[1])
                            ,0);
      if ((iVar3 != 0) ||
         (iVar3 = FUN_4bdc_3d8c(DAT_554c_5752,(char)((int *)DAT_554c_574e)[4]), iVar3 == 0))
      goto LAB_4bdc_38f5;
      local_e = (int *)CONCAT22(uVar5,piVar4 + 3);
    }
  }
  else {
    local_4 = 0;
    local_6 = 0;
    for (iVar2 = 0; iVar2 < ((int *)DAT_554c_574e)[3]; iVar2 = iVar2 + 1) {
      uVar6 = (undefined2)((ulong)local_e >> 0x10);
      piVar4 = (int *)local_e;
      if (*local_e == param_2) {
        local_4 = piVar4[2];
        local_6 = piVar4[1];
        break;
      }
      local_e = (int *)CONCAT22(uVar6,piVar4 + 3);
    }
    if (local_6 == 0 && local_4 == 0) {
      return 0;
    }
    iVar2 = FUN_1000_0e6d(DAT_554c_5752,local_6 + 4,local_4 + (uint)(0xfffb < local_6),0);
    if (iVar2 != 0) {
LAB_4bdc_38f5:
      if ((DAT_554c_5752 != 0) && (DAT_554c_5754 != 0)) {
        FUN_1a9e_6e73(DAT_554c_5752);
      }
      if ((int *)DAT_554c_574e != (int *)0x0 || DAT_554c_574e._2_2_ != 0) {
        FUN_2e67_10e9((int *)DAT_554c_574e,DAT_554c_574e._2_2_,10);
      }
      FUN_4bdc_32e9(0);
      DAT_554c_5752 = 0;
      DAT_554c_574e = (int *)0x0;
      return 0;
    }
    iVar2 = FUN_4bdc_3d8c(DAT_554c_5752,(char)((int *)DAT_554c_574e)[4]);
    if (iVar2 == 0) {
      return 0;
    }
  }
  return DAT_554c_5752;
}


