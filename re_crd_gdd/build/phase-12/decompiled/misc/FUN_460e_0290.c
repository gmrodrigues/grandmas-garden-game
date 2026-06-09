// TIM2.EXE: FUN_460e_0290 @ file 0x04B570 Ghidra 0x46370
// Subsystem: misc | Size: 722 bytes


uint __cdecl16far FUN_460e_0290(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_DX;
  undefined4 local_12;
  undefined4 local_e;
  undefined4 local_a;
  undefined4 local_6;
  
  if (((param_1 == 0) || (param_3 == 0 && param_4 == 0)) ||
     ((DAT_5b41_1bff == (undefined2 *)0x0 && DAT_5b41_1c01 == 0 &&
      (iVar1 = FUN_460e_0006(5,0x32,0), iVar1 == 0)))) {
LAB_460e_0479:
    param_2 = 0;
  }
  else {
    iVar1 = FUN_460e_0aa3(param_1,param_2,param_3,param_4);
    if (iVar1 != 0 || in_DX != 0) {
      return *(uint *)(iVar1 + 4);
    }
    puVar2 = (undefined2 *)FUN_460e_0a42(param_1);
    local_6 = (undefined2 *)CONCAT22(in_DX,puVar2);
    if (puVar2 == (undefined2 *)0x0 && in_DX == 0) {
      local_a._0_2_ = DAT_5b41_1bff;
      for (iVar1 = DAT_5b41_1c0b; in_DX = DAT_5b41_1c01, iVar1 != 0; iVar1 = iVar1 + -1) {
        if ((undefined2 *)local_6 != (undefined2 *)0x0 || local_6._2_2_ != 0) break;
        if (((undefined2 *)local_a)[2] == 0) {
          local_6 = (undefined2 *)CONCAT22(DAT_5b41_1c01,(undefined2 *)local_a);
        }
        local_a._0_2_ = (undefined2 *)local_a + 4;
      }
    }
    if ((undefined2 *)local_6 == (undefined2 *)0x0 && local_6._2_2_ == 0) {
      DAT_5b41_1ad2 = 10;
      return 0;
    }
    ((undefined2 *)local_6)[2] = param_1;
    iVar1 = in_DX;
    if (param_2 != 0) {
      iVar3 = FUN_460e_0aa3(param_1,param_2,0,0);
      iVar1 = in_DX;
      if ((iVar3 != 0 || in_DX != 0) &&
         (iVar4 = FUN_4340_0b8a(iVar3 + 7,in_DX,param_3,param_4), iVar4 != 0)) {
        DAT_5b41_1ad2 = 0xb;
        return 0;
      }
      if (iVar3 != 0 || in_DX != 0) {
        return param_2;
      }
    }
    uVar5 = FUN_4340_0a09(param_3,param_4);
    local_12 = (undefined2 *)0x0;
    if ((uVar5 < 0xd) &&
       ((DAT_5b41_1c03 != (undefined2 *)0x0 || DAT_5b41_1c05 != 0 ||
        (iVar3 = FUN_460e_0006(0,8,0), iVar3 != 0)))) {
      local_12 = (undefined2 *)CONCAT22(DAT_5b41_1c05,DAT_5b41_1c03);
      iVar1 = DAT_5b41_1c03[1];
      DAT_5b41_1c03 = (undefined2 *)*local_12;
      DAT_5b41_1c05 = iVar1;
    }
    else if ((uVar5 < 0x15) &&
            ((DAT_5b41_1c07 != (undefined2 *)0x0 || DAT_5b41_1c09 != 0 ||
             (iVar3 = FUN_460e_0006(0,0,8), iVar3 != 0)))) {
      local_12 = (undefined2 *)CONCAT22(DAT_5b41_1c09,DAT_5b41_1c07);
      iVar1 = DAT_5b41_1c07[1];
      DAT_5b41_1c07 = (undefined2 *)*local_12;
      DAT_5b41_1c09 = iVar1;
    }
    if ((undefined2 *)local_12 == (undefined2 *)0x0 && local_12._2_2_ == 0) {
      puVar2 = (undefined2 *)FUN_22de_01ec(uVar5 + 8,0,0xb,1);
      local_12 = (undefined2 *)CONCAT22(iVar1,puVar2);
      if (puVar2 == (undefined2 *)0x0 && iVar1 == 0) goto LAB_460e_0479;
      *(undefined1 *)(puVar2 + 3) = 9;
    }
    FUN_4340_0a29((int)(undefined2 *)local_12 + 7,local_12._2_2_,param_3,param_4);
    if (param_2 == 0) {
      local_a = (undefined2 *)CONCAT22(((undefined2 *)local_6)[1],(undefined2 *)*local_6);
      param_2 = 1;
      while( true ) {
        if ((undefined2 *)local_a == (undefined2 *)0x0 && local_a._2_2_ == 0) break;
        if (((undefined2 *)local_a)[2] == param_2) {
          param_2 = ((undefined2 *)local_a)[2] + 1;
        }
        local_a = (undefined2 *)CONCAT22(((undefined2 *)local_a)[1],(undefined2 *)*local_a);
      }
    }
    ((undefined2 *)local_12)[2] = param_2;
    local_a = (undefined2 *)CONCAT22(((undefined2 *)local_6)[1],(undefined2 *)*local_6);
    local_e = (undefined2 *)0x0;
    while( true ) {
      if (((undefined2 *)local_a == (undefined2 *)0x0 && local_a._2_2_ == 0) ||
         (param_2 <= (uint)((undefined2 *)local_a)[2])) break;
      local_e = local_a;
      local_a = (undefined2 *)CONCAT22(((undefined2 *)local_a)[1],(undefined2 *)*local_a);
    }
    ((undefined2 *)local_12)[1] = local_a._2_2_;
    *local_12 = (undefined2 *)local_a;
    if ((undefined2 *)local_e != (undefined2 *)0x0 || local_e._2_2_ != 0) {
      local_6._0_2_ = (undefined2 *)local_e;
      local_6._2_2_ = local_e._2_2_;
    }
    ((undefined2 *)local_6)[1] = local_12._2_2_;
    *(undefined2 *)local_6 = (undefined2 *)local_12;
  }
  return param_2;
}

