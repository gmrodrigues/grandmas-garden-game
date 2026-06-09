// TIM2.EXE: FUN_4551_049c @ file 0x04ABAC Ghidra 0x459AC
// Subsystem: misc | Size: 102 bytes


/* WARNING: Instruction at (ram,0x000408bc) overlaps instruction at (ram,0x000408bb)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __cdecl16far FUN_4551_049c(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint unaff_SI;
  int unaff_DI;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  int unaff_SS;
  int aiStack_2a [2];
  int iStack_26;
  undefined2 uStack_24;
  int *piStack_22;
  int *piStack_20;
  byte *pbVar13;
  int *piStack_1a;
  int iStack_10;
  undefined4 uStack_e;
  undefined4 local_a;
  int iStack_6;
  
  uVar9 = (undefined2)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  uVar11 = *(undefined2 *)(iVar8 + 10);
  local_a = (int *)CONCAT22(uVar11,(int *)*(undefined2 *)(iVar8 + 8));
  DAT_5b41_1ad2 = 0;
  while( true ) {
    uVar10 = (undefined2)((ulong)local_a >> 0x10);
    piVar6 = (int *)*local_a;
    pbVar13 = (byte *)uStack_e;
    uStack_e = (byte *)CONCAT22(piVar6,(byte *)uStack_e);
    if (piVar6 == (int *)0x0) {
      return (int *)0x0;
    }
    if (piVar6 + -1 < (int *)0x5) break;
    local_a = (int *)CONCAT22(uVar10,(int *)local_a + *(int *)((int)piVar6 * 2));
  }
  iVar7 = (int)(piVar6 + -1) * 2;
  uVar12 = 0x4000;
  switch(piVar6) {
  case (int *)0x2:
    if (piVar6 == (int *)0xffff) {
      return (int *)0x0;
    }
    piVar6[1] = *(int *)0x6;
    *(int *)0x6 = (int)piVar6;
    *piVar6 = unaff_SI + 1;
    return piVar6 + 2;
  case (int *)0x3:
    return piVar6;
  case (int *)0x4:
    while( true ) {
      *(char *)(iVar7 + -0x66) = *(char *)(iVar7 + -0x66) + (char)uVar11;
      bVar2 = in(uVar11);
      iVar5 = unaff_SI + iVar7;
      bVar1 = (&stack0x08c2)[unaff_DI];
      *(undefined2 *)(iVar5 * 0x12 + 0x14) = uVar11;
      *(undefined2 *)(iVar5 * 0x12 + 0x12) = CONCAT11((char)((uint)piVar6 >> 8),bVar2 & bVar1);
      *(undefined2 *)(iVar5 * 0x12 + 4) = 0xfffe;
      *(undefined2 *)(iVar5 * 0x12 + 6) = 0xfffe;
      iVar7 = iVar5 * 0x12;
      if (*(int *)(iVar7 + 0x12) == 0 && *(int *)(iVar7 + 0x14) == 0) {
        FUN_406b_029f();
        return (int *)0x0;
      }
      unaff_SI = iVar5 + 1;
      if (1 < (int)unaff_SI) break;
      piStack_20 = (int *)0x8c2;
      piVar6 = (int *)FUN_22de_01ec();
    }
    FUN_1a9e_58c8();
    piStack_20 = (int *)0x1a9e;
    piStack_22 = (int *)0x938;
    FUN_1a9e_3ec6();
    _DAT_53bd_0052 = iVar8;
    return (int *)0x1;
  case (int *)0x6:
    iVar8 = iStack_6 + -4;
    ((byte *)uStack_e + 6)[0] = 0;
    ((byte *)uStack_e + 6)[1] = 0;
    ((byte *)uStack_e + 4)[0] = 0;
    ((byte *)uStack_e + 4)[1] = 0;
    if (param_1._2_1_ != 'c') {
      if (DAT_554c_5758 == 0) {
        piStack_20 = (int *)0x4000;
        piStack_22 = (int *)0xfcdd;
        iVar7 = FUN_4bdc_2e9c();
        *(int *)((byte *)uStack_e + 6) = iVar8;
        *(int *)((byte *)uStack_e + 4) = iVar7;
        if (iVar7 == 0 && iVar8 == 0) {
          FUN_2e67_10e9();
          return (int *)0x0;
        }
      }
      else {
        piStack_20 = (int *)0x4000;
        piStack_22 = (int *)0xfca0;
        iVar7 = FUN_4bdc_2914();
        *(int *)((byte *)uStack_e + 6) = iVar8;
        *(int *)((byte *)uStack_e + 4) = iVar7;
        if (iVar7 == 0 && iVar8 == 0) {
          FUN_2e67_10e9();
          return (int *)0x0;
        }
      }
LAB_4bdc_3f47:
      *(int **)((byte *)uStack_e + 2) = DAT_554c_5736;
      *(byte **)uStack_e = DAT_554c_5734;
      *(int **)((byte *)uStack_e + 8) = (int *)local_a;
      DAT_554c_5736 = piVar6;
      DAT_554c_5734 = (byte *)uStack_e;
      return (int *)0x1;
    }
    iVar7 = FUN_2e67_0edd();
    *(int *)((byte *)uStack_e + 6) = iVar8;
    *(int *)((byte *)uStack_e + 4) = iVar7;
    if (iVar7 != 0 || iVar8 != 0) {
      iVar7 = 1;
      piStack_20 = *(int **)((byte *)uStack_e + 6);
      piStack_22 = *(int **)((byte *)uStack_e + 4);
      uStack_24 = 0x2e67;
      iStack_26 = -0x3a4;
      iVar8 = FUN_1000_0de2();
      if ((iVar7 == 0) && (iVar8 == 1)) goto LAB_4bdc_3f47;
    }
    FUN_2e67_10e9();
    return (int *)0x0;
  }
  if (((iVar7 != 0) && (DAT_5b41_1b8e != 0x5c)) && (DAT_5b41_1b8e != 0x3a)) {
    DAT_5b41_1b8e = 0;
  }
  if (((DAT_5b41_1b8e == 0x2d) && ((unaff_SI & 0x10) != 0)) &&
     (((int *)((int *)local_a)[9] != piVar6 ||
      (((byte *)((int *)local_a)[8] != (byte *)uStack_e || (**(char **)((int *)local_a + 8) == '-'))
      )))) {
    DAT_5b41_1b8e = 0;
  }
  iVar7 = unaff_DI;
  if (DAT_5b41_1b8e != 0) {
    FUN_4340_0df6();
    uStack_e._0_2_ = (byte *)uStack_e + 1;
    uStack_e = (byte *)CONCAT22(piVar6,(byte *)uStack_e);
    DAT_5450_0010 = 2;
    *(undefined2 *)(iVar8 + 0x26) = 2;
    iVar7 = 1;
    iStack_10 = 1;
    uVar3 = FUN_4340_1c51();
    piStack_20 = (int *)0x4340;
    piStack_22 = (int *)0x99a7;
    FUN_4340_10fe();
    piStack_1a = aiStack_2a;
    iVar5 = 0;
    if ((iStack_26 <= ((int *)local_a)[4]) && (uVar3 <= piStack_22)) {
      piStack_22 = (int *)0x4340;
      uVar12 = 0x4340;
      uStack_24 = 0x99d2;
      piStack_20 = (int *)local_a;
      iVar4 = FUN_4340_167e();
      piStack_1a = piVar6;
      iVar5 = unaff_SS;
      if ((iVar4 != 2) &&
         (((((byte *)((int *)local_a)[2] != (byte *)uStack_e || (DAT_5b41_1b8e != 0x20)) &&
           ((int)(byte *)uStack_e < ((int *)local_a)[2] + ((int *)local_a)[4])) &&
          ((int)piVar6 < ((int *)local_a)[3] + ((int *)local_a)[5])))) goto LAB_4876_130e;
    }
    uVar12 = 0x4340;
    if ((((piStack_22 < uVar3) || ((byte *)uStack_e <= (byte *)(((int *)local_a)[8] + 1))) ||
        (*pbVar13 != 0x20)) ||
       ((pbVar13[-1] == 0x20 ||
        (((int *)local_a)[3] + ((int *)local_a)[5] < (int)piStack_1a + iVar5)))) {
      uStack_e = (byte *)CONCAT22(piVar6,pbVar13);
      FUN_4340_0e53();
      piStack_22 = (int *)local_a;
      uStack_24 = 0x4340;
      uVar12 = 0x4340;
      iStack_26 = -0x6595;
      piStack_20 = (int *)uVar10;
      FUN_4340_10fe();
    }
    else {
      unaff_DI = 1;
    }
  }
LAB_4876_130e:
  if (iVar7 != 0) {
    piStack_1a = (int *)uStack_e._2_2_;
    piStack_20 = (int *)local_a;
    uStack_24 = 0x9a8b;
    piStack_22 = (int *)uVar12;
    iVar5 = FUN_4340_167e();
    pbVar13 = (byte *)uStack_e;
    if (iVar5 != 2) goto LAB_4876_1386;
    if (unaff_DI == -1) {
      while (((byte *)((int *)local_a)[8] < (byte *)uStack_e &&
             (uVar11 = (undefined2)((ulong)uStack_e >> 0x10), ((byte *)uStack_e)[-1] < 0x21))) {
        uStack_e = (byte *)CONCAT22(uVar11,(byte *)uStack_e + -1);
      }
    }
    else {
      while ((*uStack_e != 0 && (*uStack_e < 0x21))) {
        uStack_e = (byte *)CONCAT22(uStack_e._2_2_,(byte *)uStack_e + 1);
      }
    }
    while( true ) {
      piStack_1a = (int *)uStack_e._2_2_;
      piStack_20 = (int *)local_a;
      piStack_22 = (int *)0x4340;
      uStack_24 = 0x9ae3;
      FUN_4340_167e();
      pbVar13 = (byte *)uStack_e;
LAB_4876_1386:
      if (((byte *)uStack_e <= (byte *)((int *)local_a)[8]) ||
         (((int)pbVar13 < ((int *)local_a)[2] + ((int *)local_a)[4] &&
          ((int)piStack_1a + unaff_SS <= ((int *)local_a)[3] + ((int *)local_a)[5])))) break;
      uStack_e = (byte *)CONCAT22(uStack_e._2_2_,(byte *)uStack_e + -1);
    }
    DAT_5450_0016 = (int)piStack_1a;
    DAT_5450_0018 = unaff_SS;
    if (0 < iVar7) {
      DAT_5450_0014 = pbVar13;
    }
  }
  if ((DAT_5450_0008 != uStack_e._2_2_) || (DAT_5450_0006 != (byte *)uStack_e)) {
    DAT_5450_000c = DAT_5450_0008;
    DAT_5450_000a = DAT_5450_0006;
    DAT_5450_0008 = uStack_e._2_2_;
    DAT_5450_0006 = (byte *)uStack_e;
    DAT_5450_0012 = 2;
    *(undefined2 *)(iVar8 + 0x26) = 2;
  }
  if ((iStack_10 == 0) || ((*(byte *)((int *)local_a + 6) & 1) == 0)) {
    piVar6 = (int *)0x1;
  }
  else {
    piVar6 = (int *)0x2;
  }
  return piVar6;
}

