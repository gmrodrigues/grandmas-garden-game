// TIM2.EXE decompiled function: FUN_1a9e_7325
// Source: file offset 0x02794B → Ghidra 0x2274B
// Body: 0x2006A - 0x2EE60
// Size: 1238 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000289ed) overlaps instruction at (ram,0x000289ec)
    */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __cdecl16far FUN_1a9e_7325(uint *param_1,undefined2 param_2,int param_3)

{
  byte *pbVar1;
  char *pcVar2;
  undefined2 *puVar3;
  code *pcVar4;
  code *pcVar5;
  undefined1 auVar6 [2];
  undefined1 auVar7 [2];
  undefined1 uVar8;
  undefined1 uVar9;
  byte bVar10;
  uint *puVar11;
  uint *in_AX;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  char cVar18;
  int iVar17;
  int in_CX;
  uint in_DX;
  int extraout_DX;
  char cVar19;
  byte bVar20;
  undefined2 *puVar21;
  byte *pbVar22;
  char cVar24;
  int iVar23;
  undefined2 *puVar25;
  undefined2 *puVar26;
  int iVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined2 *puVar30;
  int *piVar31;
  int *piVar32;
  uint *puVar33;
  undefined4 in_ESI;
  int *piVar34;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 uVar35;
  uint uVar36;
  uint uVar37;
  undefined2 uVar38;
  undefined2 uVar39;
  undefined2 unaff_SS;
  byte in_AF;
  bool bVar40;
  longdouble in_ST0;
  undefined1 in_XMM4 [16];
  undefined4 uVar41;
  uint *puVar42;
  long lVar43;
  undefined4 uStackY_48;
  undefined4 uStackY_44;
  uint *in_stack_0000ffcc;
  uint *puStack_20;
  undefined1 uStack_1e;
  undefined1 auStack_1d [2];
  undefined1 auStack_1b [2];
  undefined1 uStack_19;
  undefined4 uStack_18;
  uint *puStack_14;
  uint *puStack_12;
  undefined4 in_stack_0000fff6;
  int local_6;
  int local_4;
  
  puVar28 = &stack0xfffe;
  puVar30 = (undefined2 *)&stack0xfffe;
  uVar35 = (undefined2)((ulong)in_ESI >> 0x10);
  puVar42 = (uint *)CONCAT22(uVar35,(uint *)param_1);
  iVar12 = (int)((ulong)in_stack_0000fff6 >> 0x10);
  puVar16 = (uint *)param_1 + -2;
  if ((uint *)0xc < puVar16) {
    puStack_12 = (uint *)0x1a9e;
    puStack_14 = (uint *)0x1d6a;
    iVar12 = FUN_1a9e_6ea7();
    if (iVar12 == 0) {
      puStack_12 = (uint *)0x1a9e;
      puStack_14 = (uint *)0x1d7e;
      param_1._2_2_ = FUN_1a9e_69e9();
    }
    if (param_1._2_2_ != 0) {
      puStack_12 = (uint *)0x55d7;
      puStack_14 = (uint *)0x1a9e;
      uStack_18._2_2_ = (uint *)0x1da0;
      FUN_1000_132f();
      puStack_12 = (uint *)0x55d3;
      uStack_18._2_2_ = (uint *)0x1000;
      uStack_18._0_2_ = 0x1db0;
      puStack_14 = (uint *)param_1._2_2_;
      iVar13 = FUN_1a9e_6a85();
      if ((in_DX != 0xffff) || (iVar13 != -1)) {
        puStack_12 = (uint *)0x1000;
        puStack_14 = (uint *)0x1dc6;
        puStack_12 = (uint *)FUN_1a9e_6e3d();
        puStack_14 = (uint *)0x5614;
        uStack_18._0_2_ = 0xffff;
        auStack_1b[1] = 0;
        uStack_19 = 0x10;
        auStack_1d[1] = 0xd9;
        auStack_1b[0] = 0x1d;
        uStack_18._2_2_ = (uint *)param_1._2_2_;
        iVar13 = FUN_28eb_2779();
        if (-1 < iVar13) {
          puStack_12 = (uint *)0x1000;
          puStack_14 = (uint *)0x1dec;
          uVar41 = FUN_28eb_2ba9();
          bVar40 = true;
          puStack_12 = (uint *)0x1000;
          puStack_14 = (uint *)0x1e05;
          FUN_1000_1821();
          if (!bVar40) {
            puStack_12 = (uint *)DAT_554c_55b4;
            puStack_14 = DAT_554c_55b2;
            uStack_18._2_2_ = (uint *)0x1000;
            uStack_18._0_2_ = 0x1e14;
            func_0x0002fdf5();
          }
          puStack_12 = (uint *)0x0;
          puStack_14 = (uint *)0x0;
          auStack_1b[1] = 0;
          uStack_19 = 0x10;
          auStack_1d[1] = 0x26;
          auStack_1b[0] = 0x1e;
          uStack_18 = uVar41;
          puVar42 = (uint *)FUN_2fc8_00fc();
          DAT_554c_55b4 = (undefined2)((ulong)puVar42 >> 0x10);
          DAT_554c_55b2 = (uint *)puVar42;
          bVar40 = true;
          puStack_12 = (uint *)0x1000;
          puStack_14 = (uint *)0x1e39;
          FUN_1000_1821();
          if (!bVar40) {
            puStack_14 = (uint *)DAT_554c_55b4;
            uStack_18._2_2_ = DAT_554c_55b2;
            auStack_1b[1] = 0;
            uStack_19 = 0x10;
            auStack_1d[1] = 0x4e;
            auStack_1b[0] = 0x1e;
            uStack_18._0_2_ = iVar13;
            puStack_12 = (uint *)(int)uVar41;
            FUN_28eb_2aad();
            puStack_14 = (uint *)0x1000;
            uStack_18._2_2_ = (uint *)0x1e59;
            puStack_12 = (uint *)iVar13;
            FUN_28eb_29db();
            if (iVar12 == 0) {
              puStack_14 = (uint *)0x1000;
              uStack_18._2_2_ = (uint *)0x1e68;
              puStack_12 = (uint *)param_1._2_2_;
              FUN_1a9e_6e73();
            }
            return DAT_554c_55b2;
          }
        }
      }
    }
    return (uint *)0x0;
  }
  puVar21 = (undefined2 *)((int)puVar16 * 2);
  uVar39 = 0x2000;
  puVar29 = &stack0xfffe;
  switch(puVar16) {
  case (uint *)0x0:
    goto switchD_2000_1d21_caseD_0;
  case (uint *)0x1:
    LOCK();
    puVar21[0x2345] = in_AX;
    UNLOCK();
                    /* WARNING: Could not recover jumptable at 0x0002228b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar16 = (uint *)(*pcRam00055c48)();
    return puVar16;
  case (uint *)0x2:
    if ((iRam000557bc == 6) && ((*(byte *)((int)(uint *)param_1 + 0xf) & 0x10) == 0)) {
      if ((((uint *)param_1)[7] & 0x40) == 0) {
        puVar42 = (uint *)(ulong)((uint)(uint *)param_1 | 0x10);
      }
      else {
        puVar42 = (uint *)(ulong)((uint)(uint *)param_1 | 0x400);
      }
    }
    puVar16 = (uint *)puVar42;
    if (((*(byte *)((int)(uint *)param_1 + 0xf) & 0x10) == 0) && ((DAT_5b41_051f & 0x10) == 0)) {
      puVar16 = (uint *)((uint)puVar16 | 0x20);
    }
    if ((*(byte *)((int)(uint *)param_1 + 0xf) & 0x10) != 0) {
      puVar16 = (uint *)((uint)puVar16 | 0x3000);
    }
    if ((((uint *)param_1)[7] & 0x40) != 0) {
      return puVar16;
    }
    puVar33 = (uint *)((uint)puVar16 | 0x140);
    if (((uint *)param_1)[4] == 8) {
      return puVar33;
    }
    if (((uint *)param_1)[4] == 10) {
      return puVar33;
    }
    if (((uint *)param_1)[4] == 0x4c) {
      return puVar33;
    }
    if ((((uint *)param_1)[6] & 0x80) != 0) {
      puVar33 = (uint *)((uint)puVar16 | 0x141);
    }
    if ((*(byte *)((int)(uint *)param_1 + 0xd) & 1) != 0) {
      puVar33 = (uint *)((uint)puVar33 | 2);
    }
    puVar42 = (uint *)ZEXT24(puVar33);
    if (((*(byte *)((int)(uint *)param_1 + 0xb) & 4) == 0) ||
       ((*(byte *)((int)(uint *)param_1 + 0xb) & 2) == 0)) {
      if ((*(byte *)((int)(uint *)param_1 + 0xb) & 4) != 0) {
        if (DAT_5b41_0939 == 9) {
          puVar42 = (uint *)(ulong)((uint)puVar33 | 4);
        }
        else {
          DAT_5b41_050f = 1;
          puStack_12 = (uint *)param_1._2_2_;
          puStack_14 = (uint *)param_1;
          puVar3 = (undefined2 *)(*(int *)(((uint *)param_1)[4] * 2 + 0x302) + 0xc);
          uStack_18._2_2_ = (uint *)0x2000;
          uStack_18._0_2_ = 0xa305;
          (*(code *)*puVar3)();
          ((uint *)param_1)[0x56] = ((uint *)param_1)[6];
          puStack_14 = (uint *)0x2000;
          uStack_18._2_2_ = (uint *)0xa31c;
          puStack_12 = (uint *)param_1;
          iVar12 = FUN_28eb_0119();
          puVar16 = (uint *)puVar42;
          if (iVar12 == 0) {
            if (((uint *)param_1)[0x2c] != 0) {
              puStack_12 = (uint *)0x2000;
              puStack_14 = (uint *)0xa336;
              iVar12 = FUN_28eb_1c08();
              puVar16 = (uint *)puVar42;
              if (iVar12 == 0) goto LAB_28eb_1490;
            }
            puVar42 = (uint *)(ulong)((uint)puVar16 | 4);
          }
LAB_28eb_1490:
          puStack_14 = (uint *)param_1;
          puVar3 = (undefined2 *)(*(int *)(((uint *)param_1)[4] * 2 + 0x302) + 0xc);
          uStack_18._2_2_ = (uint *)0x2000;
          uStack_18._0_2_ = 0xa358;
          puStack_12 = (uint *)param_1._2_2_;
          (*(code *)*puVar3)();
          ((uint *)param_1)[0x56] = ((uint *)param_1)[6];
          DAT_5b41_050f = 0;
        }
      }
      if ((*(byte *)((int)(uint *)param_1 + 0xb) & 2) == 0) goto LAB_28eb_155d;
      if (DAT_5b41_0939 == 9) {
        puVar42 = (uint *)(ulong)((uint)(uint *)puVar42 | 8);
        goto LAB_28eb_155d;
      }
      DAT_5b41_050f = 1;
      puVar3 = (undefined2 *)(*(int *)(((uint *)param_1)[4] * 2 + 0x302) + 0xc);
      uStack_18._2_2_ = (uint *)0x2000;
      uStack_18._0_2_ = 0xa3a5;
      puStack_14 = (uint *)param_1;
      puStack_12 = (uint *)param_1._2_2_;
      (*(code *)*puVar3)();
      ((uint *)param_1)[0x56] = ((uint *)param_1)[6];
      puStack_14 = (uint *)0x2000;
      uStack_18._2_2_ = (uint *)0xa3bc;
      puStack_12 = (uint *)param_1;
      iVar12 = FUN_28eb_0119();
      puVar16 = (uint *)puVar42;
      if (iVar12 == 0) {
        if (((uint *)param_1)[0x2c] != 0) {
          puStack_12 = (uint *)0x2000;
          puStack_14 = (uint *)0xa3d6;
          iVar12 = FUN_28eb_1c08();
          puVar16 = (uint *)puVar42;
          if (iVar12 == 0) goto LAB_28eb_1530;
        }
        puVar42 = (uint *)(ulong)((uint)puVar16 | 8);
      }
LAB_28eb_1530:
      puStack_12 = (uint *)param_1._2_2_;
      puStack_14 = (uint *)param_1;
      puVar3 = (undefined2 *)(*(int *)(((uint *)param_1)[4] * 2 + 0x302) + 0xc);
      uStack_18._2_2_ = (uint *)0x2000;
      uStack_18._0_2_ = 0xa3f8;
      (*(code *)*puVar3)();
      ((uint *)param_1)[0x56] = ((uint *)param_1)[6];
    }
    else {
      if (DAT_5b41_0939 == 9) {
        puVar42 = (uint *)(ulong)((uint)puVar33 | 0xc);
        goto LAB_28eb_155d;
      }
      uVar36 = ((uint *)param_1)[8];
      uVar37 = ((uint *)param_1)[6];
      DAT_5b41_050f = 1;
      bVar40 = false;
      do {
        puStack_12 = (uint *)param_1._2_2_;
        puStack_14 = (uint *)param_1;
        puVar3 = (undefined2 *)(*(int *)(((uint *)param_1)[4] * 2 + 0x302) + 0xc);
        uStack_18._2_2_ = (uint *)0x2000;
        uStack_18._0_2_ = 0xa248;
        (*(code *)*puVar3)();
        ((uint *)param_1)[0x56] = ((uint *)param_1)[6];
        if ((((uint *)param_1)[8] == uVar36) && (((uint *)param_1)[6] == uVar37)) {
LAB_28eb_13e7:
          bVar40 = true;
        }
        else {
          puStack_14 = (uint *)0x2000;
          uStack_18._2_2_ = (uint *)0xa273;
          puStack_12 = (uint *)param_1;
          iVar12 = FUN_28eb_0119();
          puVar16 = (uint *)puVar42;
          if (iVar12 == 0) {
            if (((uint *)param_1)[0x2c] != 0) {
              puStack_12 = (uint *)0x2000;
              puStack_14 = (uint *)0xa28d;
              iVar12 = FUN_28eb_1c08();
              puVar16 = (uint *)puVar42;
              if (iVar12 == 0) goto LAB_28eb_13ea;
            }
            puVar42 = (uint *)(ulong)((uint)puVar16 | 0xc);
            goto LAB_28eb_13e7;
          }
        }
LAB_28eb_13ea:
      } while (!bVar40);
      ((uint *)param_1)[8] = uVar36;
      ((uint *)param_1)[6] = uVar37;
      ((uint *)param_1)[0x56] = uVar37;
      puVar3 = (undefined2 *)(*(int *)(((uint *)param_1)[4] * 2 + 0x302) + 0xc);
      uStack_18._2_2_ = (uint *)0x2000;
      uStack_18._0_2_ = 0xa2c7;
      puStack_14 = (uint *)param_1;
      puStack_12 = (uint *)param_1._2_2_;
      (*(code *)*puVar3)();
    }
    DAT_5b41_050f = 0;
LAB_28eb_155d:
    puVar16 = (uint *)puVar42;
    if ((*(byte *)((int)(uint *)param_1 + 0xf) & 4) != 0) {
      if (((ulong)puVar42 & 1) == 0) {
        puVar16 = (uint *)((uint)puVar16 | 0x80);
      }
      else {
        puVar16 = (uint *)((uint)puVar16 | 0x800);
      }
    }
    if (((iRam000557bc == 1) || (iRam000557bc == 6)) &&
       ((*(byte *)((int)(uint *)param_1 + 0xf) & 0x80) != 0)) {
      puVar16 = (uint *)((uint)puVar16 | 0x200);
    }
    return puVar16;
  case (uint *)0x3:
    if (((param_3 != 0) && (DAT_5b41_0939 != 9)) && ((DAT_5b41_0939 & 0x8000) == 0)) {
      FUN_28eb_12a3();
      puStack_12 = (uint *)0x6490;
      FUN_2424_31e8();
    }
    if ((*(byte *)((int)(uint *)param_1 + 0xf) & 0x20) != 0) {
      FUN_2424_36c1();
    }
    puStack_12 = (uint *)&DAT_5b41_0565;
    puVar16 = (uint *)FUN_2424_1e00();
    return puVar16;
  case (uint *)0x4:
    return in_AX;
  case (uint *)0x5:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (uint *)0x6:
switchD_2000_8802_caseD_5:
    piVar34 = (int *)((int)puVar21 + (int)(uint *)puVar42);
    *piVar34 = (int)(*piVar34 + (int)in_AX);
    if ((unaff_DI == (uint *)0x0) || (DAT_554c_5740 == 0 && DAT_554c_5742 == 0)) {
      DAT_5b41_0c40 = 0;
    }
    else {
      DAT_5b41_0c40 = 1;
    }
    DAT_5b41_0c42 = (uint)(DAT_554c_5744 != 0 || DAT_554c_5746 != 0);
    FUN_2e67_0231(*(undefined2 *)(puVar29 + 0xc),unaff_ES);
    return DAT_5b41_0bec;
  case (uint *)0x7:
    register0x00000010 = (uint *)&stack0xfff0;
    puVar26 = (undefined2 *)&stack0xfff0;
    cVar18 = '\x05';
    do {
      puVar30 = puVar30 + -1;
      puVar26 = puVar26 + -1;
      *puVar26 = *puVar30;
      cVar18 = cVar18 + -1;
    } while ('\0' < cVar18);
    uVar35 = puVar21[0x30];
    iVar12 = puVar21[0x2f];
    uVar39 = *(undefined2 *)(iVar12 + 100);
    iVar13 = *(int *)(iVar12 + 0x62);
    iVar17 = FUN_28eb_3930();
    uStack_1e = (undefined1)iVar17;
    auStack_1d[0] = (byte)((uint)iVar17 >> 8);
    puVar16 = (uint *)puVar42;
    uVar38 = (undefined2)((ulong)uStackY_48 >> 0x10);
    iVar23 = (int)uStackY_48 + (uint)*(byte *)((int)puVar16 + 0x15) * 4;
    *(undefined2 *)(iVar23 + 0x60) = uVar39;
    *(int *)(iVar23 + 0x5e) = iVar13;
    iVar13 = iVar13 + iVar17 * 4;
    *(undefined2 *)(iVar13 + 0x60) = uVar38;
    *(int *)(iVar13 + 0x5e) = (int)uStackY_48;
    for (iVar13 = 0; iVar13 < 2; iVar13 = iVar13 + 1) {
      iVar17 = iVar12 + iVar13 * 4;
      *(undefined2 *)(iVar17 + 0x60) = 0;
      *(undefined2 *)(iVar17 + 0x5e) = 0;
    }
    uVar35 = FUN_28eb_399d();
    *(undefined2 *)((int)*(undefined4 *)puVar16 + 0xb4) = uVar35;
    piVar34 = (int *)((int)uStackY_44 + 0xae);
    *piVar34 = *piVar34 + (int)uStack_18._2_2_;
    return in_stack_0000ffcc;
  case (uint *)0x8:
    iVar13 = *(int *)(*(int *)(puVar21[4] * 2 + 0x302) + 0x22);
    *(int *)&DAT_554c_0096 = iVar13;
    if ((iVar13 != 0) && (*(int *)(*(int *)(((uint *)param_1)[4] * 2 + 0x302) + 0x46) == 0)) {
      puVar30 = (undefined2 *)((uint *)param_1)[0x4c];
      puStack_12 = (uint *)0x6;
      puStack_14 = (uint *)*(undefined2 *)&DAT_554c_0096;
      uStack_18._2_2_ = (uint *)0x2000;
      uVar39 = 0x1000;
      uStack_18._0_2_ = 0xc07a;
      puVar21 = (undefined2 *)FUN_1000_12bf();
      *(undefined2 *)0x98 = puVar21;
      if (puVar21 == (undefined2 *)0x0) {
        local_6 = 1;
        goto LAB_28eb_3257;
      }
      for (local_4 = 0; local_4 < *(int *)&DAT_554c_0096; local_4 = local_4 + 1) {
        *puVar21 = *puVar30;
        puVar21[1] = puVar30[1];
        puVar21[2] = puVar30[2];
        puVar21 = puVar21 + 3;
        puVar30 = puVar30 + 3;
      }
    }
    *(uint *)0xa8 = ((uint *)param_1)[0x54];
    *(uint *)0xaa = ((uint *)param_1)[0x55];
    *(uint *)0xac = ((uint *)param_1)[0x56];
    puVar3 = (undefined2 *)(*(int *)(*(int *)0x8 * 2 + 0x302) + 8);
    uStack_18._0_2_ = 0xc104;
    uStack_18._2_2_ = (uint *)uVar39;
    puStack_14 = (uint *)0;
    puStack_12 = (uint *)iVar12;
    (*(code *)*puVar3)();
LAB_28eb_3257:
    if ((local_6 != 0) && (iVar12 != 0)) {
      uStack_18._0_2_ = 0xc120;
      uStack_18._2_2_ = (uint *)uVar39;
      puStack_14 = (uint *)0;
      puStack_12 = (uint *)iVar12;
      FUN_2321_0c23();
    }
    return (uint *)0x0;
  default:
    puStack_12 = (uint *)0x2000;
    puStack_14 = (uint *)0x4692;
    FUN_2424_2165();
    uVar35 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
    iVar12 = (int)DAT_5b41_0567;
    if (((*(int *)(iVar12 + 8) == 0x16) || (*(int *)(iVar12 + 8) == 0x37)) &&
       (*(int *)(iVar12 + 0x62) != 0 || *(int *)(iVar12 + 100) != 0)) {
      puStack_12 = (uint *)0x2000;
      puStack_14 = (uint *)0x46c6;
      FUN_2424_2165();
    }
    puVar28 = &stack0xfffe;
    if (DAT_554c_02f0 == -1) goto LAB_2424_04d4;
    DAT_554c_42ce = (undefined1)DAT_554c_02f0;
    puStack_12 = (uint *)(DAT_5b41_0547 - DAT_5b41_0925);
    puStack_14 = (uint *)0x2000;
    uStack_18._2_2_ = (uint *)0x4704;
    FUN_2424_276e();
    puStack_14 = (uint *)0x2;
    puVar28 = &stack0xfffe;
    goto code_r0x00024706;
  case (uint *)0xa:
    goto switchD_2000_1d21_caseD_a;
  case (uint *)0xb:
    if ((((int)puVar16 < 0 != (int)puVar21 < 0) == (int)puVar21 < 0) &&
       ((int)(uint *)param_1 < 0x10)) {
      DAT_554c_2f22 = (uint *)param_1;
      puStack_12 = (uint *)0x2000;
      puStack_14 = (uint *)0xee58;
      FUN_4bdc_35c9();
    }
    return unaff_DI;
  }
switchD_2000_8bda_caseD_3:
  iVar12 = 0xb;
  while( true ) {
    while( true ) {
      do {
        do {
          piVar31 = (int *)piVar34;
          uVar39 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -4) >> 0x10);
          iVar13 = (int)*(undefined4 *)(puVar28 + -4);
          uVar35 = *(undefined2 *)(iVar13 + 0x8c);
          *(undefined2 *)(puVar28 + -2) = *(undefined2 *)(iVar13 + 0x8e);
          *(undefined2 *)(puVar28 + -4) = uVar35;
          if ((*(int *)(puVar28 + -4) == 0 && *(int *)(puVar28 + -2) == 0) || (iVar12 != 0)) {
            uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
            iVar13 = (int)*(undefined4 *)(puVar28 + 6);
            if (((int *)*(undefined2 *)(iVar13 + 0xae) != piVar31) ||
               (*(int *)(iVar13 + 0xb4) != iVar12)) {
              FUN_2424_3746(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8),1);
              FUN_2424_3746(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8),2);
              uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              iVar13 = (int)*(undefined4 *)(puVar28 + 6);
              *(undefined2 *)(iVar13 + 0xae) = piVar31;
              *(int *)(iVar13 + 0xb4) = iVar12;
              FUN_2424_3746(iVar13,*(undefined2 *)(puVar28 + 8),1);
              FUN_2424_3746(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8),2);
            }
            uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
            iVar13 = (int)*(undefined4 *)(puVar28 + 6);
            *(undefined2 *)(iVar13 + 0xae) = piVar31;
            *(int *)(iVar13 + 0xb4) = iVar12;
            if ((piVar31 == (int *)0x0) && (iVar12 == 0)) {
              puVar16 = (uint *)0x0;
            }
            else {
              puVar16 = (uint *)0x1;
            }
            return puVar16;
          }
          iVar13 = (int)*(undefined4 *)(puVar28 + -4);
        } while (*(int *)(iVar13 + 0x4a) != 0x10);
        iVar13 = FUN_2424_4087(iVar13,*(undefined2 *)(puVar28 + -2));
      } while (iVar13 == 0);
      if (*(int *)((int)*(undefined4 *)(puVar28 + -4) + 0x22) !=
          *(int *)((int)*(undefined4 *)(puVar28 + 6) + 0x22)) break;
      iVar12 = 10;
    }
    uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -4) >> 0x10);
    iVar12 = (int)*(undefined4 *)(puVar28 + -4);
    uVar39 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
    iVar13 = (int)*(undefined4 *)(puVar28 + 6);
    if (*(int *)(iVar12 + 0x22) + *(int *)(iVar12 + 0x48) !=
        *(int *)(iVar13 + 0x22) + *(int *)(iVar13 + 0x48)) break;
    iVar12 = 0xc;
  }
  goto switchD_2000_8bda_caseD_3;
switchD_2000_8976_caseD_7:
  while ((puVar16 = (uint *)puVar42, puVar11 != (uint *)0x0 || puVar21[-0x3d6c] != 0 &&
         ((int)puVar16 < 0x14))) {
    puVar21 = (undefined2 *)(((int)puVar16 + 1U) * 4);
    puVar11 = (uint *)puVar21[-0x3d6d];
    puVar42 = (uint *)(ulong)((int)puVar16 + 1U);
  }
  if ((int)puVar16 < 0x14) {
    iVar12 = FUN_1a9e_6ea7(in_AX);
    if (iVar12 == 0) {
      *(undefined2 *)(puVar28 + -2) = 1;
      in_AX = (uint *)FUN_1a9e_69e9(in_AX);
    }
    else {
      *(undefined2 *)(puVar28 + -2) = 0;
    }
    iVar12 = FUN_1a9e_6a85(in_AX,DAT_554c_55a8,0);
    if ((in_DX == 0xffff) && (iVar12 == -1)) {
      puVar16 = (uint *)0x0;
    }
    else {
      FUN_1000_0d10(puVar16 + 0x217a,1,1,in_AX);
      if (((char)puVar16[0x217a] == -3) || ((char)puVar16[0x217a] == -1)) {
        *(char *)(puVar16 + -0x3d77) = -(char)puVar16[0x217a];
        FUN_1000_0d10(puVar16 + 0x217a,1,1,in_AX);
        FUN_1000_0d10(puVar16 + 0x2184,1,1,in_AX);
        FUN_1000_0d10(puVar16 + -0x3cf5,1,1,in_AX);
        FUN_1000_0d10(puVar16 + 0x218e,1,1,in_AX);
        FUN_1000_0d10(puVar16 + 0x2198,1,1,in_AX);
        FUN_1000_0d10(puVar28 + -4,1,2,in_AX);
        uVar35 = FUN_1a9e_6e3d(in_AX);
        iVar12 = FUN_28eb_2779(0xffff,in_AX,0x55af,uVar35,in_DX);
        *(int *)(puVar28 + -6) = iVar12;
        *(uint *)(puVar28 + -8) = (uint)(iVar12 < 0);
        if (*(int *)(puVar28 + -8) == 0) {
          iVar12 = FUN_28eb_2ba9(0x1000,*(undefined2 *)(puVar28 + -6));
          *(uint *)(puVar28 + -8) = (uint)(iVar12 != *(int *)(puVar28 + -4));
        }
        if (*(int *)(puVar28 + -8) == 0) {
          lVar43 = FUN_2fc8_00fc(0x1000,*(undefined2 *)(puVar28 + -4),0,0,0);
          *(int *)(puVar28 + -10) = (int)((ulong)lVar43 >> 0x10);
          *(int *)(puVar28 + -0xc) = (int)lVar43;
          *(uint *)(puVar28 + -8) = (uint)(lVar43 == 0);
        }
        if (*(int *)(puVar28 + -8) == 0) {
          iVar12 = FUN_28eb_2aad(*(undefined2 *)(puVar28 + -6),*(undefined2 *)(puVar28 + -0xc),
                                 *(undefined2 *)(puVar28 + -10),*(undefined2 *)(puVar28 + -4));
          *(uint *)(puVar28 + -8) = (uint)(iVar12 != *(int *)(puVar28 + -4));
        }
        if (*(int *)(puVar28 + -8) == 0) {
          uVar35 = *(undefined2 *)(puVar28 + -0xc);
          ((undefined2 *)&DAT_5b41_2678)[(int)puVar16 * 2] = *(undefined2 *)(puVar28 + -10);
          ((undefined2 *)&DAT_5b41_2676)[(int)puVar16 * 2] = uVar35;
          *(uint *)(puVar28 + -0xc) = *(int *)(puVar28 + -0xc) + (uint)(byte)puVar16[0x2198] * 2;
          uVar35 = *(undefined2 *)(puVar28 + -0xc);
          *(undefined2 *)((undefined *)&DAT_5b41_2628 + (int)puVar16 * 4) =
               *(undefined2 *)(puVar28 + -10);
          ((undefined2 *)&DAT_5b41_2626)[(int)puVar16 * 2] = uVar35;
          *(uint *)(puVar28 + -0xc) = *(int *)(puVar28 + -0xc) + (uint)(byte)puVar16[0x2198];
          uVar35 = *(undefined2 *)(puVar28 + -0xc);
          ((undefined2 *)&DAT_5b41_25d8)[(int)puVar16 * 2] = *(undefined2 *)(puVar28 + -10);
          ((undefined2 *)&DAT_5b41_25d6)[(int)puVar16 * 2] = uVar35;
        }
        FUN_28eb_29db(*(undefined2 *)(puVar28 + -6));
        if (*(int *)(puVar28 + -8) != 0) {
          if (*(int *)(puVar28 + -0xc) != 0 || *(int *)(puVar28 + -10) != 0) {
            func_0x0002fdf5(0x1000,*(undefined2 *)(puVar28 + -0xc),*(undefined2 *)(puVar28 + -10));
          }
          puVar16 = (uint *)0x0;
        }
      }
      else {
        if ((char)puVar16[0x217a] == -2) {
          *(undefined1 *)(puVar16 + -0x3d77) = 2;
          FUN_1000_0d10(puVar16 + 0x217a,1,1,in_AX);
          *(uint *)(puVar28 + -4) = (uint)(byte)puVar16[0x217a];
        }
        else {
          *(undefined1 *)(puVar16 + -0x3d77) = 0;
          *(int *)(puVar28 + -4) = (int)((byte)puVar16[0x217a] + 7) >> 3;
        }
        FUN_1000_0d10(puVar16 + 0x2184,1,1,in_AX);
        FUN_1000_0d10(puVar16 + 0x218e,1,1,in_AX);
        FUN_1000_0d10(puVar16 + 0x2198,1,1,in_AX);
        iVar12 = *(int *)(puVar28 + -4) * (uint)(byte)puVar16[0x2184] * (uint)(byte)puVar16[0x2198];
        *(int *)(puVar28 + -4) = iVar12;
        iVar12 = FUN_1000_127a(iVar12);
        *(int *)(puVar28 + -0xe) = iVar12;
        *(uint *)(puVar28 + -8) = (uint)(iVar12 == 0);
        if (*(int *)(puVar28 + -8) == 0) {
          FUN_1000_0d10(*(undefined2 *)(puVar28 + -0xe),*(undefined2 *)(puVar28 + -4),1,in_AX);
        }
        if (*(int *)(puVar28 + -8) == 0) {
          uVar35 = *(undefined2 *)(puVar28 + -0xe);
          ((undefined2 *)&DAT_5b41_25d8)[(int)puVar16 * 2] = 0x554c;
          ((undefined2 *)&DAT_5b41_25d6)[(int)puVar16 * 2] = uVar35;
          ((undefined2 *)&DAT_5b41_2678)[(int)puVar16 * 2] = 0;
          ((undefined2 *)&DAT_5b41_2676)[(int)puVar16 * 2] = 0;
          *(undefined2 *)((undefined *)&DAT_5b41_2628 + (int)puVar16 * 4) = 0;
          ((undefined2 *)&DAT_5b41_2626)[(int)puVar16 * 2] = 0;
        }
        if (*(int *)(puVar28 + -8) != 0) {
          if (*(int *)(puVar28 + -0xe) != 0) {
            FUN_1000_130c(*(undefined2 *)(puVar28 + -0xe));
          }
          puVar16 = (uint *)0x0;
        }
      }
    }
    if (*(int *)(puVar28 + -2) != 0) {
      FUN_1a9e_6e73(in_AX);
    }
  }
  else {
    puVar16 = (uint *)0x0;
  }
  return puVar16;
LAB_2424_4a1f:
  do {
    puVar33 = (uint *)puVar42;
    puVar16 = (uint *)puVar33[1];
    *(uint *)(puVar28 + -2) = puVar33[2];
    *(uint *)(puVar28 + -4) = puVar33[3];
    *(uint *)(puVar28 + -6) = puVar33[4];
    if (((((int)puVar16 <= *(int *)(puVar28 + -0xe)) &&
         (*(int *)(puVar28 + -0xe) + *(int *)(puVar28 + -10) <= *(int *)(puVar28 + -4))) &&
        (*(int *)(puVar28 + -2) <= *(int *)(puVar28 + -0xc))) &&
       (*(int *)(puVar28 + -0xc) + *(int *)(puVar28 + -8) <= *(int *)(puVar28 + -6))) {
      FUN_2424_02ca();
      puVar16 = (uint *)FUN_4551_01dc(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8),
                                      *(undefined2 *)(puVar28 + 10),*(undefined2 *)(puVar28 + 0xc),
                                      *(undefined2 *)(puVar28 + 0xe));
      return puVar16;
    }
    if (((*(int *)(puVar28 + -0xe) <= *(int *)(puVar28 + -4)) &&
        ((int)puVar16 <= *(int *)(puVar28 + -0xe) + *(int *)(puVar28 + -10))) &&
       (((*(int *)(puVar28 + -0xc) <= *(int *)(puVar28 + -6) &&
         ((*(int *)(puVar28 + -2) <= *(int *)(puVar28 + -0xc) + *(int *)(puVar28 + -8) &&
          ((int)puVar16 < *(int *)(puVar28 + -4))))) &&
        (*(int *)(puVar28 + -2) <= *(int *)(puVar28 + -6))))) {
      DAT_554c_42c3 = 1;
      DAT_554c_42c6 = *(uint **)(puVar28 + -4);
      DAT_554c_42c8 = *(undefined2 *)(puVar28 + -2);
      DAT_554c_42ca = *(uint **)(puVar28 + -6);
      DAT_554c_42c4 = puVar16;
      FUN_4551_01dc(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8),
                    *(undefined2 *)(puVar28 + 10),*(undefined2 *)(puVar28 + 0xc),
                    *(undefined2 *)(puVar28 + 0xe));
    }
    puVar42 = (uint *)(ulong)*puVar33;
  } while (*puVar33 != 0);
  puVar16 = (uint *)FUN_2424_02ca();
  return puVar16;
switchD_2000_1d21_caseD_0:
  register0x00000018 = (uint *)((int)(uint *)param_1 + 1);
  puVar42 = (uint *)CONCAT22(uVar35,register0x00000018);
  puVar28 = &stack0xfff0;
  uStack_1e = SUB21(unaff_DI,0);
  auStack_1d[0] = (byte)((uint)unaff_DI >> 8);
  unaff_DI = (uint *)*(undefined2 *)(*(int *)0x8 * 2 + 0x68fe);
  puStack_20 = (uint *)0x3;
switchD_2000_1d21_caseD_a:
  uVar39 = (undefined2)((ulong)puVar42 >> 0x10);
  *(long *)(puVar28 + (int)unaff_DI + -0x141) = (long)in_ST0;
  uVar35 = FUN_4551_0370(unaff_DI,0x36a);
  *(undefined2 *)(puVar28 + -10) = uVar35;
  uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
  iVar12 = (int)*(undefined4 *)(puVar28 + 6);
  if (*(int *)(iVar12 + 0xae) == 0) {
LAB_2424_4827:
    uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
    iVar12 = (int)*(undefined4 *)(puVar28 + 6);
    if (*(int *)(iVar12 + 0xb4) != 0) {
      puVar42 = (uint *)CONCAT22(uVar39,(uint *)*(undefined2 *)(iVar12 + 0xb4));
      FUN_4551_03eb(unaff_DI,*(undefined2 *)(puVar28 + -10),puVar28 + -8);
      uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
      iVar12 = (int)*(undefined4 *)(puVar28 + 6);
      *(int *)(puVar28 + -8) = *(int *)(puVar28 + -8) + (*(int *)(iVar12 + 0x22) - DAT_5b41_0925);
      in_AX = (uint *)(*(int *)(iVar12 + 0x24) - DAT_5b41_0927);
      *(undefined1 **)(puVar28 + -6) = (undefined1 *)(*(int *)(puVar28 + -6) + (int)in_AX);
      puVar16 = (uint *)puVar42;
      if (puVar16 + -1 < (uint *)0xb) {
        iVar12 = (int)(puVar16 + -1) * 2;
        uVar35 = 0x2000;
        puVar33 = stack0xffe4;
        switch(puVar16) {
        case (uint *)0x2:
          if ((in_DX == 0xffff) && (in_AX == (uint *)0xffff)) {
            auStack_1d[1] = 0;
            auStack_1b[0] = 0;
            uStack_1e = 0x5d;
            auStack_1d[0] = 0x56;
            puStack_20 = puVar16;
            iVar12 = FUN_1a9e_6a85();
            if ((in_DX != 0xffff) || (iVar12 != -1)) {
              *(undefined2 *)(puVar28 + -0x1a) = 6;
            }
          }
          else {
            *(undefined2 *)(puVar28 + -0x1a) = 5;
          }
          puVar16 = (uint *)puVar42;
          if (4 < *(int *)(puVar28 + -0x1a)) {
            auStack_1d[1] = SUB41(puVar42,0);
            auStack_1b[0] = (undefined1)((ulong)puVar42 >> 8);
            uStack_1e = 0;
            auStack_1d[0] = 0x20;
            puStack_20 = (uint *)0x2b68;
            uVar39 = FUN_1a9e_6e3d();
            auStack_1d[1] = (undefined1)in_DX;
            auStack_1b[0] = (undefined1)(in_DX >> 8);
            uStack_1e = (undefined1)uVar39;
            auStack_1d[0] = (byte)((uint)uVar39 >> 8);
            puStack_20 = (uint *)0x5666;
            unaff_DI = (uint *)FUN_28eb_2779(0,(uint *)puVar42);
            puVar16 = (uint *)puVar42;
            if (-1 < (int)unaff_DI) {
              *(undefined2 *)(puVar28 + -0x1c) = 0;
              *(undefined2 *)(puVar28 + -0x1e) = 0x7fff;
              while( true ) {
                auStack_1d[1] = 0;
                auStack_1b[0] = 0;
                uStack_1e = 0;
                auStack_1d[0] = 0;
                puStack_20 = *(uint **)(puVar28 + -0x1c);
                lVar43 = FUN_2fc8_00fc(0x2000,*(undefined2 *)(puVar28 + -0x1e));
                *(int *)(puVar28 + -0xc) = (int)((ulong)lVar43 >> 0x10);
                *(int *)(puVar28 + -0xe) = (int)lVar43;
                if (lVar43 != 0) break;
                uVar36 = *(uint *)(puVar28 + -0x1c);
                uVar37 = *(uint *)(puVar28 + -0x1e);
                *(int *)(puVar28 + -0x1c) = (int)uVar36 >> 1;
                *(uint *)(puVar28 + -0x1e) = uVar37 >> 1 | (uint)((uVar36 & 1) != 0) << 0xf;
              }
              uVar39 = *(undefined2 *)(puVar28 + -6);
              *(undefined2 *)(puVar28 + -8) = *(undefined2 *)(puVar28 + -4);
              *(undefined2 *)(puVar28 + -10) = uVar39;
              while( true ) {
                auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -0x1e);
                auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -0x1e) >> 8);
                uStack_1e = (undefined1)*(undefined2 *)(puVar28 + -0xc);
                auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + -0xc) >> 8);
                puStack_20 = *(uint **)(puVar28 + -0xe);
                iVar12 = FUN_28eb_2aad(unaff_DI);
                uVar9 = uStack_19;
                puVar16 = (uint *)puVar42;
                *(int *)(puVar28 + -0x14) = iVar12;
                uStack_19 = (undefined1)((uint)uVar35 >> 8);
                uVar8 = uStack_19;
                if (iVar12 < 1) break;
                uStack_19 = uVar9;
                if (*(int *)(puVar28 + -0x1a) == 6) {
                  auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -0x14);
                  auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -0x14) >> 8);
                  uStack_1e = (undefined1)*(undefined2 *)(puVar28 + -0xc);
                  auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + -0xc) >> 8);
                  puStack_20 = *(uint **)(puVar28 + -0xe);
                  FUN_1a9e_836a(*(undefined2 *)(puVar28 + -0xe),*(undefined2 *)(puVar28 + -0xc));
                  *(int *)(puVar28 + -0x14) = *(int *)(puVar28 + -0x14) << 1;
                  *(int *)(puVar28 + -0x14) = *(int *)(puVar28 + -0x14) << 1;
                }
                auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -0x14);
                auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -0x14) >> 8);
                uStack_1e = (undefined1)*(undefined2 *)(puVar28 + -8);
                auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + -8) >> 8);
                puStack_20 = *(uint **)(puVar28 + -10);
                (*DAT_554c_4db2)(uVar35,*(undefined2 *)(puVar28 + -0xe),
                                 *(undefined2 *)(puVar28 + -0xc));
                uVar35 = 0x1000;
                auStack_1d[1] = 0x1d;
                auStack_1b[0] = 0x2c;
                auStack_1b[1] = 0;
                uStack_19 = uVar8;
                FUN_1000_1a00();
              }
              auStack_1d[1] = SUB21(unaff_DI,0);
              auStack_1b[0] = (undefined1)((uint)unaff_DI >> 8);
              puStack_20 = (uint *)0x2c3c;
              uStack_1e = 0;
              auStack_1d[0] = uStack_19;
              uStack_19 = uVar9;
              FUN_28eb_29db();
            }
          }
          bVar40 = true;
          auStack_1d[1] = 0;
          auStack_1b[0] = (undefined1)((uint)uVar35 >> 8);
          uStack_1e = 0x4e;
          auStack_1d[0] = 0x2c;
          FUN_1000_1821();
          if (!bVar40) {
            auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -0xc);
            auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -0xc) >> 8);
            uStack_1e = (undefined1)*(undefined2 *)(puVar28 + -0xe);
            auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + -0xe) >> 8);
            puStack_20 = (uint *)0x1000;
            func_0x0002fdf5();
          }
          if (*(int *)(puVar28 + -0x10) != 0) {
            auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -0x10);
            auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -0x10) >> 8);
            uStack_1e = 0;
            auStack_1d[0] = 0x10;
            puStack_20 = (uint *)0x2c6c;
            FUN_1000_130c();
            uRam00055624 = 0;
            uRam00055622 = 0;
          }
          if (*(int *)(puVar28 + -0x1a) == 0) {
            bVar40 = true;
            auStack_1d[1] = 0;
            auStack_1b[0] = 0x10;
            uStack_1e = 0x90;
            auStack_1d[0] = 0x2c;
            FUN_1000_1821();
            if (!bVar40) {
              auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -4);
              auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -4) >> 8);
              uStack_1e = (undefined1)*(undefined2 *)(puVar28 + -6);
              auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + -6) >> 8);
              puStack_20 = (uint *)0x1000;
              func_0x0002fdf5();
            }
            if (unaff_DI != (uint *)0x0) {
              auStack_1d[1] = SUB21(unaff_DI,0);
              auStack_1b[0] = (undefined1)((uint)unaff_DI >> 8);
              uStack_1e = 0;
              auStack_1d[0] = 0x10;
              puStack_20 = (uint *)0x2caa;
              FUN_28eb_29db();
            }
            auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -2);
            auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -2) >> 8);
            uStack_1e = 0;
            auStack_1d[0] = 0x10;
            puStack_20 = (uint *)0x2cb5;
            FUN_1a9e_82f5();
            *(undefined2 *)(puVar28 + -2) = 0;
          }
          if (*(int *)(puVar28 + -0x18) != 0) {
            auStack_1d[1] = SUB21(puVar16,0);
            auStack_1b[0] = (undefined1)((uint)puVar16 >> 8);
            uStack_1e = 0;
            auStack_1d[0] = 0x10;
            puStack_20 = (uint *)0x2cc9;
            FUN_1a9e_6e73();
          }
          return *(uint **)(puVar28 + -2);
        case (uint *)0x3:
          do {
            iVar12 = iVar12 + (int)in_AX * 4;
            iVar13 = *(int *)(puVar28 + -2);
            if (((*(uint *)(iVar12 + 0x1d) & 0x7fff) == *(uint *)(iVar13 + 0x3d)) &&
               (*(int *)(iVar12 + 0x1b) == *(int *)(iVar13 + 0x3b))) {
              if (*(int *)(iVar13 + 0x37) == 0) {
                puVar16 = (uint *)FUN_1a9e_6a52(iVar13);
                return puVar16;
              }
              *(int *)(*(int *)(puVar28 + -2) + 0x37) = *(int *)(*(int *)(puVar28 + -2) + 0x37) + -4
              ;
            }
            else if ((*(uint *)(*(int *)(puVar28 + -2) +
                                (*(int *)(*(int *)(puVar28 + -2) + 0x37) >> 2) * 4 + 0x1d) & 0x8000)
                     == 0) {
              puVar30 = *(undefined2 **)(puVar28 + -2);
              iVar12 = *(int *)((int)puVar30 + 0x41);
              uVar37 = *(uint *)((int)puVar30 + 0x3f);
              puVar42 = (uint *)((int)puVar30 + 0x3b);
              uVar36 = *puVar42;
              *puVar42 = *puVar42 + uVar37;
              *(int *)((int)puVar30 + 0x3d) =
                   *(int *)((int)puVar30 + 0x3d) + iVar12 + (uint)CARRY2(uVar36,uVar37);
              FUN_1000_0e6d(*puVar30,*(undefined2 *)((int)puVar30 + 0x3b),
                            *(undefined2 *)((int)puVar30 + 0x3d),0);
            }
            else {
              iVar12 = FUN_1000_0d10(*(int *)(puVar28 + -2) +
                                     *(int *)((int)*(undefined2 **)(puVar28 + -2) + 0x37) + 2,1,4,
                                     **(undefined2 **)(puVar28 + -2));
              if (iVar12 != 4) {
                puVar16 = (uint *)FUN_1a9e_6a52(*(undefined2 *)(puVar28 + -2));
                return puVar16;
              }
              iVar12 = *(int *)(puVar28 + -2);
              *(int *)(iVar12 + 0x37) = *(int *)(iVar12 + 0x37) + 4;
              if (0x17 < *(int *)(iVar12 + 0x37)) {
                puVar16 = (uint *)FUN_1a9e_6a52(iVar12);
                return puVar16;
              }
              *(undefined1 *)(*(int *)(puVar28 + -2) + *(int *)(*(int *)(puVar28 + -2) + 0x37) + 2)
                   = 0;
              puVar30 = *(undefined2 **)(puVar28 + -2);
              puVar42 = (uint *)((int)puVar30 + 0x3b);
              uVar36 = *puVar42;
              *puVar42 = *puVar42 + 8;
              *(int *)((int)puVar30 + 0x3d) =
                   *(int *)((int)puVar30 + 0x3d) + (uint)(0xfff7 < uVar36);
              iVar12 = FUN_1000_0d10(*(int *)(puVar28 + -2) + 0x3f,4,1,*puVar30);
              if (iVar12 != 1) {
                puVar16 = (uint *)FUN_1a9e_6a52(*(undefined2 *)(puVar28 + -2));
                return puVar16;
              }
              iVar12 = *(int *)(puVar28 + -2);
              uVar36 = *(uint *)(iVar12 + 0x3b);
              uVar37 = *(uint *)(iVar12 + 0x3f);
              iVar13 = *(int *)(puVar28 + -2) + (*(int *)(iVar12 + 0x37) >> 2) * 4;
              *(int *)(iVar13 + 0x1d) =
                   *(int *)(iVar12 + 0x3d) + *(int *)(iVar12 + 0x41) +
                   (uint)CARRY2(uVar36,*(uint *)(iVar12 + 0x3f));
              *(int *)(iVar13 + 0x1b) = uVar36 + uVar37;
              iVar12 = *(int *)(puVar28 + -2);
              *(undefined2 *)(iVar12 + 0x3f) = *(undefined2 *)(iVar12 + 0x3f);
              *(uint *)(iVar12 + 0x41) = *(uint *)(iVar12 + 0x41) & 0x7fff;
              if (*(int *)(iVar12 + 0x41) < 0) {
LAB_1a9e_6ddd:
                puVar16 = (uint *)FUN_1a9e_6a52(*(undefined2 *)(puVar28 + -2));
                return puVar16;
              }
              uVar37 = *(uint *)(*(int *)(puVar28 + -2) + 0x1d) & 0x7fff;
              uVar36 = *(uint *)(*(int *)(puVar28 + -2) + 0x41);
              if ((uVar37 <= uVar36) &&
                 ((uVar36 != uVar37 ||
                  (*(uint *)(*(int *)(puVar28 + -2) + 0x1b) <=
                   *(uint *)(*(int *)(puVar28 + -2) + 0x3f))))) goto LAB_1a9e_6ddd;
              if (*(int *)(*(int *)(puVar28 + -2) + 0x37) == *(int *)(puVar28 + -4)) {
                iVar12 = FUN_1a9e_6904(*(int *)(puVar28 + -2) + 2,*(undefined2 *)(puVar28 + 8),
                                       *(undefined2 *)(puVar28 + -4));
                if ((iVar12 != 0) &&
                   (iVar12 = *(int *)(puVar28 + 10),
                   *(int *)(puVar28 + 10) = *(int *)(puVar28 + 10) + -1, iVar12 == 0)) {
                  iVar12 = *(int *)(puVar28 + -2);
                  *(undefined2 *)(iVar12 + 0x39) = *(undefined2 *)(puVar28 + -6);
                  return (uint *)*(undefined2 *)(iVar12 + 0x3b);
                }
              }
            }
            iVar12 = *(int *)(puVar28 + -2);
            in_AX = (uint *)(*(int *)(iVar12 + 0x37) >> 2);
          } while( true );
        case (uint *)0x4:
          return in_AX;
        case (uint *)0x5:
          do {
            unique0x10001840 = puVar33;
            FUN_1a9e_836a(*(undefined2 *)(puVar28 + -0xe),*(undefined2 *)(puVar28 + -0xc));
            do {
              auStack_1d[1] = SUB41(puVar42,0);
              auStack_1b[0] = (undefined1)((ulong)puVar42 >> 8);
              uStack_1e = (undefined1)(*(int *)(puVar28 + -0x14) << 1);
              auStack_1d[0] = (byte)((uint)(*(int *)(puVar28 + -0x14) << 1) >> 8);
              puStack_20 = unaff_DI;
              func_0x0002ea8f(0x2000,*(undefined2 *)(puVar28 + -0xe),*(undefined2 *)(puVar28 + -0xc)
                              ,0);
              unaff_DI = (uint *)((int)unaff_DI + (int)(uint *)puVar42);
              if (*(int *)(puVar28 + -0x12) < (int)((int)unaff_DI + (int)(uint *)puVar42)) {
                puVar42 = (uint *)(ulong)(uint)(*(int *)(puVar28 + -0x12) - (int)unaff_DI);
                *(int *)(puVar28 + -10) =
                     (*(int *)(puVar28 + -0x12) - (int)unaff_DI) * *(int *)(puVar28 + -0x14);
                if (*(int *)(puVar28 + -6) == 6) {
                  *(uint *)(puVar28 + -10) = *(uint *)(puVar28 + -10) >> 1;
                  *(uint *)(puVar28 + -10) = *(uint *)(puVar28 + -10) >> 1;
                }
              }
LAB_1a9e_7d65:
              if (*(int *)(puVar28 + -0x12) <= (int)unaff_DI) {
LAB_1a9e_7d6a:
                auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -0xe);
                auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -0xe) >> 8);
                uStack_1e = 0;
                auStack_1d[0] = 0x20;
                puStack_20 = (uint *)0x2752;
                FUN_1000_130c();
                auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -2);
                auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -2) >> 8);
                uStack_1e = 0;
                auStack_1d[0] = 0x10;
                puStack_20 = (uint *)0x275d;
                FUN_28eb_29db();
                if (*(int *)(puVar28 + -4) != 0) {
                  auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + 6);
                  auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + 6) >> 8);
                  uStack_1e = 0;
                  auStack_1d[0] = 0x10;
                  puStack_20 = (uint *)0x276e;
                  FUN_1a9e_6e73();
                }
                return *(uint **)(puVar28 + -6);
              }
              auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -10);
              auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -10) >> 8);
              uStack_1e = (undefined1)*(undefined2 *)(puVar28 + -0xc);
              auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + -0xc) >> 8);
              puStack_20 = *(uint **)(puVar28 + -0xe);
              FUN_28eb_2aad(*(undefined2 *)(puVar28 + -2));
            } while (*(int *)(puVar28 + -6) != 6);
            puVar33 = *(uint **)(puVar28 + -10);
            auStack_1d[1] = SUB21(puVar33,0);
            auStack_1b[0] = (undefined1)((uint)puVar33 >> 8);
            uStack_1e = (undefined1)*(undefined2 *)(puVar28 + -0xc);
            auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + -0xc) >> 8);
            puStack_20 = *(uint **)(puVar28 + -0xe);
          } while( true );
        case (uint *)0x7:
          do {
            out(in_DX,(char)in_AX);
            FUN_4551_03eb(*(undefined2 *)(puVar28 + -4),*(undefined2 *)(puVar28 + -6),puVar28 + -0xe
                         );
            *(int *)(puVar28 + -0xe) = *(int *)(puVar28 + -0xe) + (int)(uint *)puVar42;
            *(undefined1 **)(puVar28 + -0xc) =
                 (undefined1 *)(*(int *)(puVar28 + -0xc) + (int)unaff_DI);
            puVar33 = (uint *)FUN_2424_1e00(puVar28 + -0xe);
            puVar16 = stack0xffe4;
            auVar6 = (undefined1  [2])CONCAT11(auStack_1d[1],auStack_1d[0]);
            unaff_ES = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
            iVar12 = (int)*(undefined4 *)(puVar28 + 6);
            if (*(int *)(iVar12 + 0xb4) == 0) {
              return puVar33;
            }
            *(undefined2 *)(puVar28 + -2) = *(undefined2 *)(iVar12 + 0xb4);
            puVar33 = (uint *)(*(int *)(iVar12 + 0x22) - DAT_5b41_0925);
            puVar42 = (uint *)CONCAT22((int)((ulong)puVar42 >> 0x10),puVar33);
            in_AX = (uint *)(*(int *)(iVar12 + 0x24) - DAT_5b41_0927);
            uVar36 = *(int *)(puVar28 + -2) - 2;
            if (10 < uVar36) {
              FUN_4551_03eb(*(undefined2 *)(puVar28 + -4),*(undefined2 *)(puVar28 + -6),
                            puVar28 + -0xe);
              *(int *)(puVar28 + -0xe) = *(int *)(puVar28 + -0xe) + (int)(uint *)puVar42;
              *(undefined1 **)(puVar28 + -0xc) =
                   (undefined1 *)(*(int *)(puVar28 + -0xc) + (int)in_AX);
              puVar16 = (uint *)FUN_2424_1e00(puVar28 + -0xe);
              return puVar16;
            }
            puVar21 = (undefined2 *)(uVar36 * 2);
            bVar20 = (byte)in_AX;
            puVar11 = in_AX;
            puVar29 = puVar28;
            unaff_DI = in_AX;
            switch(uVar36) {
            case 0:
              *(byte *)(uint *)((int)puVar21 + (int)puVar33) =
                   (char)*(uint *)((int)puVar21 + (int)puVar33) + bVar20;
              break;
            case 1:
              puVar42 = puVar33;
              *puVar42 = *puVar42 +
                         (uint)CARRY2(uVar36,uVar36) * (((uint)in_AX & 3) - (*puVar42 & 3));
              uVar9 = in(in_DX);
              *(undefined1 *)in_AX = uVar9;
              puVar42 = (uint *)(puVar28 + (int)puVar33);
              *puVar42 = *puVar42 +
                         (uint)(auStack_1d[0] < (byte)in_AX[0x1e]) *
                         (((uint)(in_AX + 1) & 3) - (*puVar42 & 3));
              auVar7 = (undefined1  [2])(in_AX + 2);
              uVar36 = in(in_DX);
              in_AX[1] = uVar36;
              auStack_1b[0] = SUB21(auVar7,0);
              auStack_1b[1] = (undefined1)((uint)auVar7 >> 8);
              puVar30 = (undefined2 *)(puVar28 + -1);
              uVar35 = in(in_DX);
              bVar20 = 9 < ((byte)uVar35 & 0xf) | 9 < ((bVar20 ^ 0x38) & 0xf) | in_AF;
              if ((int)puVar16 + 1 == 1 || (char)((int)puVar16 + 1) == (char)((uint)puStack_20 >> 8)
                 ) {
                bVar10 = ((byte)uVar35 + bVar20 * '\x06' & 0xf) % 0x37;
                puVar21 = (undefined2 *)auStack_1d;
                auStack_1d[0] = (byte)puVar30;
                auStack_1d[1] = (undefined1)((uint)puVar30 >> 8);
                cVar18 = '\x16';
                auStack_1b = auVar7;
                auStack_1d = (undefined1  [2])puVar30;
                do {
                  puVar30 = puVar30 + -1;
                  puVar21 = puVar21 + -1;
                  *puVar21 = *puVar30;
                  cVar18 = cVar18 + -1;
                } while ('\0' < cVar18);
                puVar42 = (uint *)auVar7;
                bVar20 = 9 < (bVar10 & 0xf) | bVar20;
                _DAT_5000_eaf7 = CONCAT11(bVar20,bVar10 + bVar20 * '\x06') & 0xff0f;
                uVar36 = *puStack_20;
                auVar6 = auStack_1d;
                auVar7 = auStack_1b;
                if (((int)(uint)bVar10 < (int)*puVar42) && (SBORROW2((uint)bVar10,*puVar42))) {
                  *(uint *)((int)puStack_20 + -1) = *(uint *)((int)puStack_20 + -1) ^ (uint)puVar33;
                  DAT_554c_36f1 = DAT_554c_36f1 + '\x01';
                  puVar30 = (undefined2 *)in(0x36);
                  *(undefined1 *)(in_AX + 3) = *(undefined1 *)0xb136;
                  *(undefined2 *)0x367c = puVar30;
                  out(*puVar30,CONCAT11((char)uVar36,(char)in_DX));
                }
              }
              else {
                out(*puVar33,in_DX);
              }
              auStack_1d = auVar6;
              auStack_1b = auVar7;
              puVar16 = (uint *)FUN_28eb_4cfc();
              return puVar16;
            case 2:
              out(in_DX,bVar20);
              puVar16 = (uint *)(in_CX + (int)(((long)((int)in_AX - in_CX) *
                                               (long)(int)(in_AX + -uVar36)) /
                                              (long)(int)(puVar28 + uVar36 * -2)));
              if (DAT_554c_42ca < puVar16) {
                puVar11 = puVar16;
                puVar33 = DAT_554c_42c4;
                if (DAT_554c_42ca < in_AX) {
                  return DAT_554c_42ca;
                }
              }
              else {
                puVar11 = DAT_554c_42c4;
                if (in_AX <= DAT_554c_42ca) goto LAB_1a9e_57cd;
                puVar42 = (uint *)ZEXT24(DAT_554c_42c4);
                puVar11 = in_AX;
                in_AX = puVar16;
              }
              puVar11 = (uint *)((int)puVar33 +
                                (int)(((long)((int)(uint *)puVar42 - (int)puVar33) *
                                      (long)((int)DAT_554c_42ca - (int)puVar11)) /
                                     (long)((int)in_AX - (int)puVar11)));
LAB_1a9e_57cd:
              if ((puVar11 <= DAT_554c_42c6) ||
                 (puVar16 = DAT_554c_42c6, (uint *)puVar42 <= DAT_554c_42c6)) {
                puVar16 = (uint *)(*DAT_554c_4d7e)(0x2000);
              }
              return puVar16;
            case 3:
              goto LAB_2424_4a1f;
            case 4:
              return (uint *)*(uint **)puVar33;
            case 5:
              movmskps(puVar42,in_XMM4);
              while( true ) {
                iVar12 = puVar21[0x11];
                iVar13 = puVar21[0x12];
                *(int *)(puVar28 + in_CX + -10) = puVar21[0x2a] + iVar12;
                *(int *)(puVar28 + in_CX + -0xc) = puVar21[0x2b] + iVar13;
                if (((((iVar12 < *(int *)(puVar28 + in_CX + -6)) &&
                      (*(int *)(puVar28 + in_CX + -2) < *(int *)(puVar28 + in_CX + -10))) &&
                     (iVar13 < *(int *)(puVar28 + in_CX + -8))) &&
                    (*(int *)(puVar28 + in_CX + -4) < *(int *)(puVar28 + in_CX + -0xc))) &&
                   (((iVar12 = FUN_28eb_024e(*(undefined2 *)(puVar28 + in_CX + 6),
                                             *(undefined2 *)(puVar28 + in_CX + 8),puVar21,
                                             *(undefined2 *)(puVar28 + in_CX + -0xe)), iVar12 != 0
                     || (iVar12 = FUN_28eb_03ff(*(undefined2 *)(puVar28 + in_CX + 6),
                                                *(undefined2 *)(puVar28 + in_CX + 8),
                                                *(undefined2 *)(puVar28 + in_CX + -0x10),
                                                *(undefined2 *)(puVar28 + in_CX + -0xe)),
                        iVar12 != 0)) ||
                    (iVar12 = FUN_28eb_03ff(*(undefined2 *)(puVar28 + in_CX + -0x10),
                                            *(undefined2 *)(puVar28 + in_CX + -0xe),
                                            *(undefined2 *)(puVar28 + in_CX + 6),
                                            *(undefined2 *)(puVar28 + in_CX + 8)), iVar12 != 0))))
                break;
                do {
                  do {
                    do {
                      uVar35 = FUN_28eb_32d8(*(undefined2 *)(puVar28 + in_CX + -0x10),
                                             *(undefined2 *)(puVar28 + in_CX + -0xe),0x1000);
                      *(uint *)(puVar28 + in_CX + -0xe) = in_DX;
                      *(undefined2 *)(puVar28 + in_CX + -0x10) = uVar35;
                      if (*(int *)(puVar28 + in_CX + -0x10) == 0 &&
                          *(int *)(puVar28 + in_CX + -0xe) == 0) {
                        return (uint *)0x0;
                      }
                      iVar12 = FUN_28eb_00cb(*(undefined2 *)
                                              ((int)*(undefined4 *)(puVar28 + in_CX + 6) + 8),
                                             *(undefined2 *)
                                              ((int)*(undefined4 *)(puVar28 + in_CX + -0x10) + 8));
                    } while (iVar12 != 0);
                    in_DX = *(uint *)(puVar28 + in_CX + -0xe);
                  } while ((in_DX == *(uint *)(puVar28 + in_CX + 8)) &&
                          (*(int *)(puVar28 + in_CX + -0x10) == *(int *)(puVar28 + in_CX + 6)));
                  unaff_ES = (undefined2)((ulong)*(undefined2 **)(puVar28 + in_CX + -0x10) >> 0x10);
                  puVar21 = (undefined2 *)*(undefined2 **)(puVar28 + in_CX + -0x10);
                } while (((*(byte *)((int)puVar21 + 0xd) & 0x20) != 0) ||
                        ((*(byte *)((int)puVar21 + 0xf) & 0x50) != 0));
              }
              return (uint *)0x1;
            case 6:
              goto switchD_2000_8802_caseD_5;
            case 7:
              goto switchD_2000_8976_caseD_7;
            case 8:
              goto switchD_2000_8802_caseD_7;
            case 9:
              goto switchD_2000_8b75_caseD_3;
            case 10:
              func_0x0002fe0c();
              puStack_20 = (uint *)0x3c;
              DAT_554c_516f = (uint *)FUN_2fc8_01f3();
              uStack_1e = 0x4c;
              auStack_1d[0] = 0;
              uVar35 = FUN_2fc8_01f3();
              puVar30 = *(undefined2 **)(puVar28 + 8);
              **(undefined2 **)(puVar28 + 10) = uVar35;
              puVar16 = DAT_554c_516f;
              *puVar30 = DAT_554c_516f;
              return puVar16;
            }
          } while( true );
        case (uint *)0x8:
          if (((((unaff_DI == (uint *)0x4) && (999 < DAT_5b41_0c98)) &&
               (in_DX = DAT_554c_2fce, (int)*(uint *)(puVar28 + 8) <= (int)DAT_554c_2fce)) &&
              ((DAT_554c_2fce != *(uint *)(puVar28 + 8) || (*(uint *)(puVar28 + 6) <= DAT_554c_2fcc)
               ))) && (DAT_5b41_0cb9 == 0)) {
            *(uint *)(puVar28 + -2) = DAT_5b41_0ca2;
            *(uint **)(puVar28 + -4) = DAT_5b41_0ca0;
            DAT_5b41_0cb9 = DAT_5b41_0c98;
            in_DX = DAT_5b41_0ca2;
            FUN_1a9e_5c44(*(undefined2 *)(puVar28 + -4),DAT_5b41_0ca2,0,*(undefined2 *)(puVar28 + 6)
                          ,*(undefined2 *)(puVar28 + 8));
          }
          if (((DAT_5b41_0c9c != (uint *)0x0 || DAT_5b41_0c9e != 0) && (unaff_DI == (uint *)0x4)) &&
             (DAT_5b41_0c98 < 1000)) {
            in_DX = (int)DAT_554c_2fd0 >> 0xf;
            if (((int)*(uint *)(puVar28 + 8) <= (int)in_DX) &&
               ((piVar31 = _DAT_554c_2fd2, in_DX != *(uint *)(puVar28 + 8) ||
                (*(uint *)(puVar28 + 6) <= DAT_554c_2fd0)))) {
              for (; (piVar31 != (int *)0x0 && ((*piVar31 != -1 && (*piVar31 != DAT_5b41_0c98))));
                  piVar31 = piVar31 + 1) {
              }
              if ((piVar31 == (int *)0x0) || (*piVar31 == DAT_5b41_0c98)) {
                *(uint *)(puVar28 + -2) = DAT_5b41_0c9e;
                *(uint **)(puVar28 + -4) = DAT_5b41_0c9c;
                in_DX = DAT_5b41_0c9e;
                if (DAT_5b41_0cbb != 0) {
                  FUN_4bdc_32e9(DAT_5b41_0cbb);
                }
                DAT_5b41_0cbb = DAT_5b41_0c98;
                FUN_1a9e_5c44(*(undefined2 *)(puVar28 + -4),*(undefined2 *)(puVar28 + -2),0,
                              *(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8));
              }
            }
          }
          if (*(int *)(puVar28 + -4) == 0 && *(int *)(puVar28 + -2) == 0) {
            iVar12 = FUN_22de_01ec(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8),2,1);
            *(uint *)(puVar28 + -2) = in_DX;
            *(int *)(puVar28 + -4) = iVar12;
            if ((iVar12 != 0 || *(int *)(puVar28 + -2) != 0) && (unaff_DI == (uint *)0x4)) {
              DAT_5b41_0c9a = 1;
            }
          }
          return *(uint **)(puVar28 + -4);
        case (uint *)0x9:
          uVar35 = *(undefined2 *)(puVar28 + -0x30);
          uVar39 = FUN_1000_199e();
          *(undefined2 *)(puVar28 + -0x20) = uVar35;
          *(undefined2 *)(puVar28 + -0x22) = uVar39;
          iVar12 = 1 << (puVar28[-10] & 0x1f);
          *(int *)(puVar28 + -0x40) = iVar12 >> 0xf;
          *(int *)(puVar28 + -0x42) = iVar12;
          uVar35 = FUN_1000_19bf();
          *(undefined2 *)(puVar28 + -4) = uVar35;
          uVar35 = FUN_1000_19bf();
          *(undefined2 *)(puVar28 + -2) = uVar35;
          *(undefined2 *)(puVar28 + -0x3c) = 0;
          *(undefined2 *)(puVar28 + -0x3e) = 0;
          while( true ) {
            if ((*(int *)(puVar28 + -0x40) <= *(int *)(puVar28 + -0x3c)) &&
               ((*(int *)(puVar28 + -0x40) < *(int *)(puVar28 + -0x3c) ||
                (*(uint **)(puVar28 + -0x42) < *(uint **)(puVar28 + -0x3e))))) break;
            uVar35 = FUN_1000_19bf();
            *(undefined2 *)(puVar28 + -8) = uVar35;
            uVar35 = FUN_1000_19bf();
            *(undefined2 *)(puVar28 + -6) = uVar35;
            if ((*(int *)(puVar28 + -4) != *(int *)(puVar28 + -8)) ||
               (*(int *)(puVar28 + -2) != *(int *)(puVar28 + -6))) {
              FUN_2424_1a04(puVar28 + -4,puVar28 + -8,*(undefined2 *)(puVar28 + 10));
              *(undefined2 *)(puVar28 + -4) = *(undefined2 *)(puVar28 + -8);
              *(undefined2 *)(puVar28 + -2) = *(undefined2 *)(puVar28 + -6);
            }
            iVar12 = *(int *)(puVar28 + -0xc);
            uVar14 = FUN_1000_180a();
            uVar37 = *(uint *)(puVar28 + -0x16);
            uVar15 = uVar14 + *(uint *)(puVar28 + -0x16);
            iVar13 = *(int *)(puVar28 + -0x14);
            puVar42 = (uint *)(puVar28 + -0x1e);
            uVar36 = *puVar42;
            *puVar42 = *puVar42 + uVar15;
            *(uint *)(puVar28 + -0x1c) =
                 *(int *)(puVar28 + -0x1c) + iVar12 + iVar13 + (uint)CARRY2(uVar14,uVar37) +
                 (uint)CARRY2(uVar36,uVar15);
            iVar12 = *(int *)(puVar28 + -0x10);
            uVar14 = FUN_1000_180a();
            uVar37 = *(uint *)(puVar28 + -0x1a);
            uVar15 = uVar14 + *(uint *)(puVar28 + -0x1a);
            iVar13 = *(int *)(puVar28 + -0x18);
            puVar42 = (uint *)(puVar28 + -0x22);
            uVar36 = *puVar42;
            *puVar42 = *puVar42 + uVar15;
            *(uint *)(puVar28 + -0x20) =
                 *(int *)(puVar28 + -0x20) + iVar12 + iVar13 + (uint)CARRY2(uVar14,uVar37) +
                 (uint)CARRY2(uVar36,uVar15);
            puVar42 = (uint *)(puVar28 + -0x3e);
            uVar36 = *puVar42;
            *puVar42 = *puVar42 + 1;
            *(uint *)(puVar28 + -0x3c) = *(int *)(puVar28 + -0x3c) + (uint)(0xfffe < uVar36);
          }
          return *(uint **)(puVar28 + -0x3e);
        case (uint *)0xa:
          do {
          } while( true );
        case (uint *)0xc:
switchD_2000_8a43_caseD_9:
          uVar9 = in(in_DX);
          lVar43 = CONCAT22(in_DX,CONCAT11((char)((uint)in_AX >> 8),uVar9));
          do {
            iVar12 = (int)((ulong)lVar43 >> 0x10);
            *(int *)(puVar28 + -10) = (int)lVar43;
            do {
              if (*(int *)(puVar28 + -0x12) <= (int)unaff_DI) {
                *(undefined2 *)(puVar28 + -6) = 1;
                if (DAT_554c_42df != '\0') {
                  auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -2);
                  auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -2) >> 8);
                  uStack_1e = 0;
                  auStack_1d[0] = 0x20;
                  puStack_20 = (uint *)0x2634;
                  FUN_28eb_29db();
                  auStack_1d[1] = 0;
                  auStack_1b[0] = 0;
                  uStack_1e = 0x2c;
                  auStack_1d[0] = 0x56;
                  puStack_20 = *(uint **)(puVar28 + 6);
                  iVar13 = FUN_1a9e_6a85();
                  if ((iVar12 == -1) && (iVar13 == -1)) {
                    auStack_1d[1] = 0;
                    auStack_1b[0] = 0;
                    uStack_1e = 0x35;
                    auStack_1d[0] = 0x56;
                    puStack_20 = *(uint **)(puVar28 + 6);
                    iVar13 = FUN_1a9e_6a85();
                    if ((iVar12 != -1) || (iVar13 != -1)) {
                      *(undefined2 *)(puVar28 + -6) = 6;
                    }
                  }
                  else {
                    *(undefined2 *)(puVar28 + -6) = 5;
                  }
                  if (4 < *(int *)(puVar28 + -6)) {
                    auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + 6);
                    auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + 6) >> 8);
                    uStack_1e = 0;
                    auStack_1d[0] = 0x20;
                    puStack_20 = (uint *)0x268c;
                    uVar35 = FUN_1a9e_6e3d();
                    auStack_1d[1] = (undefined1)iVar12;
                    auStack_1b[0] = (undefined1)((uint)iVar12 >> 8);
                    uStack_1e = (undefined1)uVar35;
                    auStack_1d[0] = (byte)((uint)uVar35 >> 8);
                    puStack_20 = (uint *)0x563e;
                    iVar12 = FUN_28eb_2779(0,*(undefined2 *)(puVar28 + 6));
                    *(int *)(puVar28 + -2) = iVar12;
                    if (-1 < iVar12) {
                      unaff_DI = (uint *)0x0;
                      puVar42 = (uint *)((ulong)*(uint *)(puVar28 + -8) /
                                        (ulong)*(uint *)(puVar28 + -0x14));
                      if (*(int *)(puVar28 + -6) == 6) {
                        *(uint *)(puVar28 + -8) = *(uint *)(puVar28 + -8) >> 1;
                        *(uint *)(puVar28 + -8) = *(uint *)(puVar28 + -8) >> 1;
                      }
                      *(undefined2 *)(puVar28 + -10) = *(undefined2 *)(puVar28 + -8);
                      if ((int)(uint *)puVar42 <= *(int *)(puVar28 + -0x12)) goto LAB_1a9e_7d65;
                      puVar42 = (uint *)(ulong)*(uint *)(puVar28 + -0x12);
                      goto LAB_1a9e_7d65;
                    }
                  }
                }
                goto LAB_1a9e_7d6a;
              }
              auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + -10);
              auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + -10) >> 8);
              uStack_1e = (undefined1)*(undefined2 *)(puVar28 + -0xc);
              auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + -0xc) >> 8);
              puStack_20 = *(uint **)(puVar28 + -0xe);
              FUN_28eb_2aad(*(undefined2 *)(puVar28 + -2));
              auStack_1d[1] = SUB41(puVar42,0);
              auStack_1b[0] = (undefined1)((ulong)puVar42 >> 8);
              uStack_1e = (undefined1)(*(int *)(puVar28 + -0x14) << 1);
              auStack_1d[0] = (byte)((uint)(*(int *)(puVar28 + -0x14) << 1) >> 8);
              puStack_20 = unaff_DI;
              func_0x0002ea8b(0x2000,*(undefined2 *)(puVar28 + -0xe),*(undefined2 *)(puVar28 + -0xc)
                              ,0);
              unaff_DI = (uint *)((int)unaff_DI + (int)(uint *)puVar42);
              iVar12 = extraout_DX;
            } while ((int)((int)unaff_DI + (int)(uint *)puVar42) <= *(int *)(puVar28 + -0x12));
            in_AX = *(uint **)(puVar28 + -0x12);
switchD_2000_8a43_caseD_7:
            puVar42 = (uint *)(ulong)(uint)((int)in_AX - (int)unaff_DI);
            lVar43 = (long)((int)in_AX - (int)unaff_DI) * (long)*(int *)(puVar28 + -0x14);
          } while( true );
        }
switchD_2000_8a43_caseD_8:
        uVar35 = 0x2000;
        puVar16 = (uint *)puVar42;
        if (DAT_554c_02e6 != 0) {
          uVar35 = 0x54bb;
          func_0x00054bdf(0x2000,0,&puStack_20);
        }
        func_0x00054ab0(uVar35);
        if ((puVar16 != (uint *)0x0) && (5000 < DAT_554c_2f1c)) {
          FUN_460e_101b(0,DAT_554c_2f1c,1);
        }
        FUN_2424_03c5();
        FUN_2424_028d();
        FUN_460e_18af(DAT_554c_2f1c,1);
        FUN_2e67_0a1f();
        FUN_2424_08e8();
        FUN_311b_06b8();
        FUN_406b_03cb(0xfffd,0xffff);
        puVar16 = (uint *)FUN_2424_01b2();
        return puVar16;
      }
      iVar12 = FUN_2424_4007(puVar28 + -8);
      if (iVar12 != 0) goto LAB_2424_489b;
    }
    puVar16 = (uint *)0x0;
  }
  else {
    puVar42 = (uint *)CONCAT22(uVar39,(uint *)*(undefined2 *)(iVar12 + 0xae));
    FUN_4551_03eb(unaff_DI,*(undefined2 *)(puVar28 + -10),puVar28 + -8);
    uVar36 = (uint)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
    iVar12 = (int)*(undefined4 *)(puVar28 + 6);
    *(int *)(puVar28 + -8) = *(int *)(puVar28 + -8) + (*(int *)(iVar12 + 0x22) - DAT_5b41_0925);
    in_AX = (uint *)(*(int *)(iVar12 + 0x24) - DAT_5b41_0927);
    *(undefined1 **)(puVar28 + -6) = (undefined1 *)(*(int *)(puVar28 + -6) + (int)in_AX);
    puVar16 = (uint *)puVar42;
    if ((int)puVar16 - 1U < 9) {
      pbVar22 = (byte *)(((int)puVar16 - 1U) * 2);
      switch(puVar16) {
      case (uint *)0x1:
code_r0x00024706:
        FUN_2424_1a04((undefined2 *)&DAT_5b41_0547,(undefined2 *)&DAT_5b41_054b);
LAB_2424_04d4:
        if (5000 < DAT_554c_2f1c) {
          uStack_18._2_2_ = (uint *)0x2000;
          uStack_18._0_2_ = 0x4721;
          FUN_2424_196d();
          uStack_18._2_2_ = (uint *)0x1;
          uStack_18._0_2_ = 0x2000;
          auStack_1b[1] = 0x28;
          uStack_19 = 0x47;
          FUN_2424_184a();
        }
        uStack_18._2_2_ = (uint *)0x2000;
        uStack_18._0_2_ = 0x472f;
        FUN_2424_0304();
        uStack_18._2_2_ = (uint *)0x0;
        uStack_18._0_2_ = 0x2000;
        auStack_1b[1] = 0x36;
        uStack_19 = 0x47;
        FUN_460e_1314();
        uStack_18._2_2_ = (uint *)0x460e;
        uStack_18._0_2_ = 0x473e;
        FUN_2424_1650();
        DAT_5b41_0567 = (uint *)CONCAT22(*(undefined2 *)(puVar28 + -2),*(uint **)(puVar28 + -4));
        return *(uint **)(puVar28 + -4);
      case (uint *)0x2:
        in_AX = (uint *)*(undefined2 *)(*(int *)(pbVar22 + 8) * 2 + 0x68fe);
        puVar16 = (uint *)FUN_4551_0370(in_AX,3);
        *(uint **)(puVar28 + -10) = puVar16;
        uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
        iVar12 = (int)*(undefined4 *)(puVar28 + 6);
        if (*(int *)(iVar12 + 0xae) != 0) {
          iVar12 = *(int *)(iVar12 + 0xae);
          FUN_4551_03eb(in_AX,*(undefined2 *)(puVar28 + -10),puVar28 + -8);
          uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
          iVar13 = (int)*(undefined4 *)(puVar28 + 6);
          *(int *)(puVar28 + -8) =
               *(int *)(puVar28 + -8) + (*(int *)(iVar13 + 0x22) - DAT_5b41_0925);
          puVar16 = (uint *)(*(int *)(iVar13 + 0x24) - DAT_5b41_0927);
          *(int *)(puVar28 + -6) = *(int *)(puVar28 + -6) + (int)puVar16;
          if (iVar12 - 1U < 9) {
            puVar21 = (undefined2 *)((iVar12 - 1U) * 2);
            switch(iVar12) {
            case 1:
              if ((char)puVar16 != '\0') {
                FUN_2fc8_0364(0x2000,*(undefined2 *)(puVar28 + 6),(undefined2 *)&DAT_554c_5173,
                              (undefined2 *)&DAT_554c_5175);
                puVar16 = (uint *)0x0;
                if (DAT_554c_5173 < -0x1e) {
                  puVar16 = (uint *)0x4;
                }
                else if (0x1d < DAT_554c_5173) {
                  puVar16 = (uint *)0x8;
                }
                if (DAT_554c_5175 < -0x1e) {
                  puVar16 = (uint *)((uint)puVar16 | 1);
                }
                else if (0x1d < DAT_554c_5175) {
                  puVar16 = (uint *)((uint)puVar16 | 2);
                }
              }
              return puVar16;
            case 2:
              cVar19 = (char)((int)puVar16 >> 0xf);
              cVar24 = (char)((uint)puVar21 >> 8) + cVar19;
              *(undefined2 *)(CONCAT11(cVar24,(char)puVar21) + iVar12) = 0x7404;
              puVar16 = puVar16 + 0xdc;
              cVar18 = puVar28[(int)in_AX];
              bVar20 = cVar19 + puVar28[(int)in_AX];
              pbVar1 = (byte *)((int)in_AX +
                               CONCAT11(cVar24,(char)puVar21 + (char)((uint)in_CX >> 8)) + -0x15ba);
              *pbVar1 = *pbVar1 >> 3 | *pbVar1 << 5;
              if (bVar20 != 0 && SCARRY1(cVar19,cVar18) == (int)((uint)bVar20 << 8) < 0) {
                *(char *)(iVar12 + 0xb) = *(char *)(iVar12 + 0xb) + bVar20;
                if (*(int *)(puVar28 + -6) < DAT_5b41_051d + -0x12) {
                  DAT_5b41_0513 = *(int *)(puVar28 + -6);
                  *(undefined2 *)(puVar28 + -0x12) = 1;
                }
                else {
                  DAT_5b41_0513 = *(int *)(puVar28 + -2) + 0x12;
                  *(undefined2 *)(puVar28 + -0x10) = 1;
                }
                if ((*(int *)(puVar28 + -0x16) == 0) || (-0x13 < *(int *)(puVar28 + -8))) {
                  DAT_5b41_0515 = *(int *)(puVar28 + -8);
                  *(undefined2 *)(puVar28 + -0xe) = 1;
                }
                else {
                  DAT_5b41_0515 = *(int *)(puVar28 + -0xc) + -0x12;
                  DAT_5b41_0513 = *(int *)(puVar28 + -2) + 0x12;
                  *(undefined2 *)(puVar28 + -0x10) = 1;
                  *(undefined2 *)(puVar28 + -0x14) = 1;
                }
                uVar35 = DAT_5b41_04dc;
                if (*(int *)(puVar28 + -0x16) != 0) {
                  uVar35 = DAT_5b41_04de;
                }
                *(undefined2 *)(puVar28 + -0x18) = uVar35;
                puVar16 = (uint *)FUN_4551_01dc(DAT_5b41_050d,uVar35,DAT_5b41_0513,DAT_5b41_0515,0);
              }
              if (*(int *)(puVar28 + -0x10) != 0) {
                piVar34 = *(int **)(puVar28 + 8);
                *piVar34 = *piVar34 + -0x24;
                ((int *)piVar34)[2] = ((int *)piVar34)[2] + 0x24;
              }
              if (*(int *)(puVar28 + -0xe) != 0) {
                uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 8) >> 0x10);
                iVar12 = (int)*(undefined4 *)(puVar28 + 8);
                piVar34 = (int *)(iVar12 + 2);
                *piVar34 = *piVar34 + -0x24;
                piVar34 = (int *)(iVar12 + 6);
                *piVar34 = *piVar34 + 0x24;
              }
              if (*(int *)(puVar28 + -0x12) != 0) {
                piVar34 = (int *)((int)*(undefined4 *)(puVar28 + 8) + 4);
                *piVar34 = *piVar34 + 0x24;
              }
              if (*(int *)(puVar28 + -0x14) != 0) {
                piVar34 = (int *)((int)*(undefined4 *)(puVar28 + 8) + 6);
                *piVar34 = *piVar34 + 0x24;
              }
              return puVar16;
            case 4:
              uVar41 = FUN_1a9e_5ad4();
              *(int *)(puVar28 + 6) = (int)uVar41;
              *(int *)(puVar28 + 8) = (int)((ulong)uVar41 >> 0x10);
              puStack_20 = (uint *)0x590;
              FUN_1a9e_5ad4();
              do {
                uVar36 = 32000;
                if (*(int *)(puVar28 + 0x10) == 0) {
                  uVar37 = *(uint *)(puVar28 + 0xe);
                  if (uVar37 == 0) {
                    return *(uint **)(puVar28 + -4);
                  }
                  if ((int)uVar37 < 0x7d01) {
                    uVar36 = uVar37;
                  }
                }
                puStack_20 = (uint *)0x5bc;
                (*pcRam00025b2d)();
                uStack_1e = 0xc9;
                auStack_1d[0] = 5;
                (*pcRam00025b2d)();
                auStack_1d[1] = 0xd2;
                auStack_1b[0] = 5;
                (*pcRam00025b2f)();
                puVar42 = (uint *)(puVar28 + 0xe);
                uVar37 = *puVar42;
                *puVar42 = *puVar42 - uVar36;
                *(uint *)(puVar28 + 0x10) = *(int *)(puVar28 + 0x10) - (uint)(uVar37 < uVar36);
              } while( true );
            case 5:
              *(undefined2 *)(*(int *)(puVar28 + 6) + 0x96) = puVar21[0x11];
              iVar13 = *(int *)(puVar28 + 6);
              *(undefined2 *)(iVar13 + 0x3e) = *(undefined2 *)(*(int *)(iVar12 * 2 + 0x302) + 0x38);
              *(undefined2 *)(iVar13 + 0xa4) = 0xffff;
              *(undefined2 *)(iVar13 + 0xa6) = 0xffff;
              uVar39 = *(undefined2 *)(*(int *)(iVar12 * 2 + 0x302) + 0x2a);
              iVar13 = *(int *)(puVar28 + 6);
              *(uint *)(iVar13 + 0x4a) = in_DX;
              *(undefined2 *)(iVar13 + 0x48) = uVar39;
              iVar13 = *(int *)(iVar12 * 2 + 0x302);
              if (*(int *)(iVar13 + 0x1c) != 0 || *(int *)(iVar13 + 0x1e) != 0) {
                puVar3 = (undefined2 *)(*(int *)(iVar12 * 2 + 0x302) + 0x1c);
                iVar13 = (*(code *)*puVar3)(0x2000,*(undefined2 *)(puVar28 + 6),
                                            *(undefined2 *)(puVar28 + 8));
                if (iVar13 == 0) {
                  return (uint *)0x0;
                }
              }
              puVar3 = (undefined2 *)(*(int *)(iVar12 * 2 + 0x302) + 8);
              (*(code *)*puVar3)(0x2000,*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8));
              uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              iVar12 = (int)*(undefined4 *)(puVar28 + 6);
              *(undefined2 *)(iVar12 + 0xac) = *(undefined2 *)(iVar12 + 0xc);
              FUN_28eb_3328(iVar12,*(undefined2 *)(puVar28 + 8));
              return (uint *)0x1;
            case 6:
switchD_2000_8802_caseD_7:
              uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              if ((*(int *)(*(int *)(*(int *)((int)*(undefined4 *)(puVar28 + 6) + 8) * 2 + 0x302) +
                           0x2a) == 0) &&
                 (*(int *)(*(int *)(*(int *)(*(int *)(puVar28 + 6) + 8) * 2 + 0x302) + 0x2c) == 0))
              {
                uVar39 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
                iVar12 = (int)*(undefined4 *)(puVar28 + 6);
                uVar35 = *(undefined2 *)(iVar12 + 0x46);
                puVar16 = (uint *)*(undefined2 *)(iVar12 + 0x44);
              }
              else {
                iVar12 = *(int *)(*(int *)((int)*(undefined4 *)(puVar28 + 6) + 8) * 2 + 0x302);
                uVar35 = *(undefined2 *)(iVar12 + 0x2c);
                puVar16 = (uint *)*(undefined2 *)(iVar12 + 0x2a);
              }
              uVar39 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              iVar12 = (int)*(undefined4 *)(puVar28 + 6);
              *(undefined2 *)(iVar12 + 0x56) = uVar35;
              *(undefined2 *)(iVar12 + 0x54) = puVar16;
              return puVar16;
            case 7:
switchD_2000_8b75_caseD_7:
              if ((*(int *)(puVar28 + 6) != 0 || *(int *)(puVar28 + 8) != 0) &&
                 (((((*(int *)(puVar28 + 8) == *(int *)(puVar28 + 0xc) &&
                     (*(int *)(puVar28 + 6) == *(int *)(puVar28 + 10))) ||
                    ((*(int *)(puVar28 + 8) == *(int *)(puVar28 + -0x1c) &&
                     (*(int *)(puVar28 + 6) == *(int *)(puVar28 + -0x1e))))) ||
                   ((*(int *)(puVar28 + 8) == *(int *)(puVar28 + -0x20) &&
                    (*(int *)(puVar28 + 6) == *(int *)(puVar28 + -0x22))))) ||
                  ((*(int *)(puVar28 + 8) == *(int *)(puVar28 + -0x24) &&
                   (*(int *)(puVar28 + 6) == *(int *)(puVar28 + -0x26))))))) {
                in_AX = (uint *)((int)in_AX + -0x23);
                *(int *)(puVar28 + -10) = *(int *)(puVar28 + -10) + -0x23;
                *(int *)(puVar28 + -0xc) = *(int *)(puVar28 + -0xc) + 0x23;
                *(int *)(puVar28 + -0xe) = *(int *)(puVar28 + -0xe) + 0x23;
              }
              if ((((*(int *)(puVar28 + -6) < (int)in_AX) ||
                   (*(int *)(puVar28 + -0xc) <= *(int *)(puVar28 + -2))) ||
                  (*(int *)(puVar28 + -8) < *(int *)(puVar28 + -10))) ||
                 (*(int *)(puVar28 + -0xe) <= *(int *)(puVar28 + -4))) {
                puVar16 = (uint *)0x0;
              }
              else {
                if ((*(int *)(puVar28 + -0x16) != 0) && (DAT_5b41_0939 != 9)) {
                  uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 10) >> 0x10);
                  iVar13 = (int)*(undefined4 *)(puVar28 + 10);
                  iVar12 = ((uint)*(byte *)(iVar13 + 0x5a) + *(int *)(puVar28 + -0x14)) -
                           *(int *)(iVar13 + 0x5c);
                  *(uint *)(puVar28 + -10) =
                       ((uint)*(byte *)(iVar13 + 0x5b) + *(int *)(puVar28 + -0x12)) -
                       *(int *)(iVar13 + 0x5c);
                  *(int *)(puVar28 + -0xc) = *(int *)(iVar13 + 0x5c) * 2 + iVar12;
                  *(int *)(puVar28 + -0xe) = *(int *)(iVar13 + 0x5c) * 2 + *(int *)(puVar28 + -10);
                  if ((*(int *)(*(int *)(puVar28 + -0x16) + 4) == *(int *)(puVar28 + 8)) &&
                     (*(int *)(*(int *)(puVar28 + -0x16) + 2) == *(int *)(puVar28 + 6))) {
                    iVar12 = iVar12 + -0x23;
                    *(int *)(puVar28 + -10) = *(int *)(puVar28 + -10) + -0x23;
                    *(int *)(puVar28 + -0xc) = *(int *)(puVar28 + -0xc) + 0x23;
                  }
                  if (((iVar12 <= *(int *)(puVar28 + -6)) &&
                      (*(int *)(puVar28 + -2) < *(int *)(puVar28 + -0xc))) &&
                     ((*(int *)(puVar28 + -10) <= *(int *)(puVar28 + -8) &&
                      (*(int *)(puVar28 + -4) < *(int *)(puVar28 + -0xe))))) {
                    iVar12 = *(int *)(puVar28 + -0x16);
                    if ((*(int *)(iVar12 + 8) == *(int *)(puVar28 + 0xc)) &&
                       (*(int *)(iVar12 + 6) == *(int *)(puVar28 + 10))) {
                      uVar35 = *(undefined2 *)(iVar12 + 10);
                      *(undefined2 *)(iVar12 + 8) = *(undefined2 *)(iVar12 + 0xc);
                      *(undefined2 *)(iVar12 + 6) = uVar35;
                      uVar35 = *(undefined2 *)(puVar28 + 10);
                      *(undefined2 *)(iVar12 + 0xc) = *(undefined2 *)(puVar28 + 0xc);
                      *(undefined2 *)(iVar12 + 10) = uVar35;
                    }
                    return (uint *)*(undefined2 *)(*(int *)(puVar28 + -0x16) + 2);
                  }
                }
                piVar31 = *(int **)(puVar28 + -0x18);
                *(undefined2 *)(puVar28 + -0x10) = 0;
                while (*(int *)(puVar28 + -0x10) < 2) {
                  if ((piVar31 != (int *)0x0) && (DAT_5b41_0939 != 9)) {
                    uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 10) >> 0x10);
                    iVar12 = (int)*(undefined4 *)(puVar28 + 10);
                    if (*(int *)(iVar12 + 8) != 7) {
                      iVar12 = iVar12 + *(int *)(puVar28 + -0x10) * 2;
                      iVar13 = (int)*(char *)(iVar12 + 0x7a) + *(int *)(puVar28 + -0x14);
                      iVar17 = iVar13 + -8;
                      *(int *)(puVar28 + -10) =
                           (int)*(char *)(iVar12 + 0x7b) + *(int *)(puVar28 + -0x12) + -4;
                      *(int *)(puVar28 + -0xc) = iVar13 + 8;
                      *(int *)(puVar28 + -0xe) = *(int *)(puVar28 + -10) + 8;
                      if ((piVar31[1] == *(int *)(puVar28 + 8)) &&
                         (*piVar31 == *(int *)(puVar28 + 6))) {
                        iVar17 = iVar13 + -0x2b;
                        *(int *)(puVar28 + -10) = *(int *)(puVar28 + -10) + -0x23;
                        *(int *)(puVar28 + -0xc) = *(int *)(puVar28 + -0xc) + 0x23;
                      }
                      if ((((iVar17 <= *(int *)(puVar28 + -6)) &&
                           (*(int *)(puVar28 + -2) < *(int *)(puVar28 + -0xc))) &&
                          (*(int *)(puVar28 + -10) <= *(int *)(puVar28 + -8))) &&
                         (*(int *)(puVar28 + -4) < *(int *)(puVar28 + -0xe))) {
                        if ((piVar31[3] == *(int *)(puVar28 + 0xc)) &&
                           (piVar31[2] == *(int *)(puVar28 + 10))) {
                          FUN_28eb_08be(piVar31);
                        }
                        return (uint *)*piVar31;
                      }
                    }
                  }
                  piVar31 = *(int **)(puVar28 + -0x1a);
                  *(int *)(puVar28 + -0x10) = *(int *)(puVar28 + -0x10) + 1;
                }
                puVar16 = *(uint **)(puVar28 + 10);
              }
              return puVar16;
            case 8:
              if ((puVar21 == (undefined2 *)0x0) || ((char)puVar16 == '\0')) {
                if (DAT_554c_559f == '\x03') {
                  puVar16 = (uint *)0x0;
                }
                else {
                  puVar16 = (uint *)0x1;
                }
              }
              else {
                puVar16 = (uint *)0x3;
              }
              return puVar16;
            case 9:
              do {
              } while( true );
            }
switchD_2000_8b75_caseD_3:
            uVar35 = *puVar21;
            *(uint *)(puVar28 + -0x24) = in_DX;
            *(undefined2 *)(puVar28 + -0x26) = uVar35;
            goto switchD_2000_8b75_caseD_7;
          }
          puVar16 = (uint *)FUN_2424_1e00(puVar28 + -8);
        }
        uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
        iVar12 = (int)*(undefined4 *)(puVar28 + 6);
        if (*(int *)(iVar12 + 0xb4) != 0) {
          piVar34 = (int *)(ulong)*(uint *)(iVar12 + 0xb4);
          FUN_4551_03eb(in_AX,*(undefined2 *)(puVar28 + -10),puVar28 + -8);
          uVar37 = (uint)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
          iVar12 = (int)*(undefined4 *)(puVar28 + 6);
          *(int *)(puVar28 + -8) =
               *(int *)(puVar28 + -8) + (*(int *)(iVar12 + 0x22) - DAT_5b41_0925);
          puVar16 = (uint *)(*(int *)(iVar12 + 0x24) - DAT_5b41_0927);
          *(int *)(puVar28 + -6) = *(int *)(puVar28 + -6) + (int)puVar16;
          piVar32 = (int *)piVar34;
          piVar31 = piVar32 + -1;
          if (piVar31 < (int *)0xb) {
            puVar33 = (uint *)((int)piVar31 * 2);
            cVar18 = (char)((uint)puVar16 >> 8);
            switch(piVar31) {
            case (int *)0x0:
              do {
                LOCK();
                uVar36 = *(uint *)((int)puVar33 + -0x3e17);
                *(uint *)((int)puVar33 + -0x3e17) = (uint)puVar16;
                UNLOCK();
                pcVar2 = (char *)((int)(undefined2 *)&DAT_5b41_2839 +
                                 (int)((int)puVar33 + (int)in_AX));
                *pcVar2 = *pcVar2 + (char)(uVar36 >> 8);
                in_AX = DAT_5b41_2837;
                *(uint *)(puVar28 + -6) = uVar36;
                DAT_5b41_2839 = (uint *)(*(int *)(puVar28 + -6) + ((int)DAT_5b41_2837 >> 4));
                DAT_5b41_2837 = (uint *)((uint)DAT_5b41_2837 & 0xf);
                *(uint **)(puVar28 + -2) = DAT_5b41_2839;
                *(uint **)(puVar28 + -4) = DAT_5b41_2837;
                piVar31 = (int *)piVar34;
                if (DAT_554c_42df == '\0') {
                  *(int *)(puVar28 + -10) = *(int *)(*piVar31 + 6) * *(int *)(*piVar31 + 8);
                  uVar41 = FUN_2fc8_00fc(0x2000,*(undefined2 *)(puVar28 + -10),0,0,0);
                  *(int *)(puVar28 + -0xc) = (int)((ulong)uVar41 >> 0x10);
                  *(int *)(puVar28 + -0xe) = (int)uVar41;
                  *(uint *)(puVar28 + -10) = *(uint *)(puVar28 + -10) >> 1;
                  *(uint *)(puVar28 + -10) = *(uint *)(puVar28 + -10) >> 1;
                  *(uint *)(puVar28 + -10) = *(uint *)(puVar28 + -10) >> 1;
                  FUN_1a9e_74bc(*(undefined2 *)(puVar28 + -0xe),*(undefined2 *)(puVar28 + -0xc),
                                *(undefined2 *)*piVar31,((undefined2 *)*piVar31)[1],
                                *(undefined2 *)(puVar28 + -10));
                  puVar30 = (undefined2 *)*piVar31;
                  *puVar30 = *(undefined2 *)(puVar28 + -0xc);
                  puVar30[1] = *(undefined2 *)(puVar28 + -0xe);
                  FUN_1a9e_7911(puVar30);
                  func_0x0002fdf5(0x2000,*(undefined2 *)(puVar28 + -0xe),
                                  *(undefined2 *)(puVar28 + -0xc));
                }
                else {
                  FUN_1a9e_7911(*piVar31);
                }
                puVar33 = (uint *)*piVar31;
                *puVar33 = *(uint *)(puVar28 + -2);
                puVar33[1] = *(uint *)(puVar28 + -4);
                puVar33[2] = 0xfffe;
                puVar11 = DAT_5b41_2837;
                iVar12 = DAT_5b41_2833;
                piVar34 = (int *)ZEXT24(piVar31 + 1);
                puVar16 = DAT_5b41_2839;
              } while (piVar31[1] != 0);
              *(int *)(puVar28 + -6) = (int)DAT_5b41_2839 - DAT_5b41_2835;
              DAT_5b41_282f =
                   *(int *)(puVar28 + -6) + ((int)((int)DAT_5b41_2837 + (0xf - DAT_5b41_2833)) >> 4)
              ;
              *(undefined2 *)(puVar28 + -8) = *(undefined2 *)**(undefined2 **)(puVar28 + 6);
              pcVar5 = (code *)swi(0x21);
              (*pcVar5)();
              puStack_20 = DAT_5b41_283f;
              FUN_1000_130c();
              return (uint *)((int)puVar11 + (*(int *)(puVar28 + -6) * 0x10 - iVar12));
            case (int *)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            case (int *)0x2:
              *(char *)(int *)((int)puVar33 + (int)piVar32) =
                   (char)*(int *)((int)puVar33 + (int)piVar32) + '\x01';
              if (puVar16 != (uint *)0xf6) {
                puVar33 = puVar33 + -1;
                *(uint **)(puVar28 + 2) = puVar33;
              }
              if ((*puVar33 & 1) == 0) {
                puVar16 = (uint *)((int)uVar36 >> 1);
              }
              else {
                puVar16 = (uint *)(uVar36 >> 1 | (uint)((in_DX & 1) != 0) << 0xf);
              }
              return puVar16;
            case (int *)0x3:
              goto switchD_2000_8bda_caseD_3;
            case (int *)0x4:
              while( true ) {
                piVar31 = (int *)piVar34;
                FUN_3e34_0ec9(puVar33,*(undefined2 *)(puVar28 + -2),piVar31,in_AX,0,uVar37,uVar36);
                uVar36 = (int)piVar31 + *(int *)((int)*(undefined4 *)(puVar28 + -4) + 6);
                piVar34 = (int *)(ulong)uVar36;
                if (*(int *)(puVar28 + -0xc) <= (int)uVar36) break;
                uVar35 = (undefined2)((ulong)*(uint **)(puVar28 + -4) >> 0x10);
                puVar33 = (uint *)*(uint **)(puVar28 + -4);
                uVar36 = puVar33[4];
                uVar37 = puVar33[3];
              }
              puVar16 = (uint *)FUN_2424_02ca();
              return puVar16;
            case (int *)0x5:
              (puVar28 + (int)in_AX)[0xe46] =
                   (puVar28 + (int)in_AX)[0xe46] + (char)in_CX + CARRY2((uint)piVar31,(uint)piVar31)
              ;
              uVar36 = *(uint *)(puVar28 + 0x12) + *(uint *)(puVar28 + 10);
              *(uint *)(puVar28 + -6) =
                   ((*(int *)(puVar28 + 0x14) + *(int *)(puVar28 + 0xc) +
                    (uint)CARRY2(*(uint *)(puVar28 + 0x12),*(uint *)(puVar28 + 10))) -
                   (in_DX << 1 | (uint)CARRY2((uint)puVar16,(uint)puVar16))) -
                   (uint)(uVar36 < (uint)((int)puVar16 * 2));
              *(uint *)(puVar28 + -8) = uVar36 + (int)puVar16 * -2;
              uVar36 = *(uint *)(puVar28 + 0x1a);
              uVar37 = *(uint *)(puVar28 + 0x1e) + *(uint *)(puVar28 + 0x16);
              *(uint *)(puVar28 + -10) =
                   ((*(int *)(puVar28 + 0x20) + *(int *)(puVar28 + 0x18) +
                    (uint)CARRY2(*(uint *)(puVar28 + 0x1e),*(uint *)(puVar28 + 0x16))) -
                   (*(int *)(puVar28 + 0x1c) << 1 | (uint)CARRY2(uVar36,uVar36))) -
                   (uint)(uVar37 < uVar36 * 2);
              *(uint *)(puVar28 + -0xc) = uVar37 + uVar36 * -2;
              iVar12 = (*(int *)(puVar28 + 0x10) - *(int *)(puVar28 + 0xc)) -
                       (uint)(*(uint *)(puVar28 + 0xe) < *(uint *)(puVar28 + 10));
              uVar35 = FUN_1000_199e();
              *(int *)(puVar28 + -0xe) = iVar12;
              *(undefined2 *)(puVar28 + -0x10) = uVar35;
              iVar12 = (*(int *)(puVar28 + 0x1c) - *(int *)(puVar28 + 0x18)) -
                       (uint)(*(uint *)(puVar28 + 0x1a) < *(uint *)(puVar28 + 0x16));
              uVar35 = FUN_1000_199e();
              *(int *)(puVar28 + -0x12) = iVar12;
              *(undefined2 *)(puVar28 + -0x14) = uVar35;
              iVar12 = *(int *)(puVar28 + 8);
              *(int *)(puVar28 + -0x26) = iVar12 * 2 >> 0xf;
              *(int *)(puVar28 + -0x28) = iVar12 * 2;
              uVar35 = *(undefined2 *)(puVar28 + 0xc);
              uVar39 = FUN_1000_199e();
              *(undefined2 *)(puVar28 + -0x16) = uVar35;
              *(undefined2 *)(puVar28 + -0x18) = uVar39;
              uVar35 = *(undefined2 *)(puVar28 + 0x18);
              uVar39 = FUN_1000_199e();
              *(undefined2 *)(puVar28 + -0x1a) = uVar35;
              *(undefined2 *)(puVar28 + -0x1c) = uVar39;
              iVar12 = 1 << (puVar28[8] & 0x1f);
              *(int *)(puVar28 + -0x22) = iVar12 >> 0xf;
              *(int *)(puVar28 + -0x24) = iVar12;
              uVar35 = FUN_1000_19bf();
              *(undefined2 *)(puVar28 + -2) = uVar35;
              uVar35 = FUN_1000_19bf();
              *(undefined2 *)(puVar28 + -4) = uVar35;
              *(undefined2 *)(puVar28 + -0x1e) = 0;
              *(undefined2 *)(puVar28 + -0x20) = 0;
              while( true ) {
                if ((*(int *)(puVar28 + -0x22) <= *(int *)(puVar28 + -0x1e)) &&
                   ((*(int *)(puVar28 + -0x22) < *(int *)(puVar28 + -0x1e) ||
                    (*(uint **)(puVar28 + -0x24) < *(uint **)(puVar28 + -0x20))))) break;
                iVar12 = FUN_1000_19bf();
                iVar13 = FUN_1000_19bf();
                if ((*(int *)(puVar28 + -2) != iVar12) || (*(int *)(puVar28 + -4) != iVar13)) {
                  FUN_2424_27e0(*(undefined2 *)(puVar28 + -2),*(undefined2 *)(puVar28 + -4),iVar12,
                                iVar13);
                  *(int *)(puVar28 + -2) = iVar12;
                  *(int *)(puVar28 + -4) = iVar13;
                }
                iVar12 = *(int *)(puVar28 + -6);
                uVar14 = FUN_1000_180a();
                uVar37 = *(uint *)(puVar28 + -0x10);
                uVar15 = uVar14 + *(uint *)(puVar28 + -0x10);
                iVar13 = *(int *)(puVar28 + -0xe);
                puVar42 = (uint *)(puVar28 + -0x18);
                uVar36 = *puVar42;
                *puVar42 = *puVar42 + uVar15;
                *(uint *)(puVar28 + -0x16) =
                     *(int *)(puVar28 + -0x16) + iVar12 + iVar13 + (uint)CARRY2(uVar14,uVar37) +
                     (uint)CARRY2(uVar36,uVar15);
                iVar12 = *(int *)(puVar28 + -10);
                uVar14 = FUN_1000_180a();
                uVar37 = *(uint *)(puVar28 + -0x14);
                uVar15 = uVar14 + *(uint *)(puVar28 + -0x14);
                iVar13 = *(int *)(puVar28 + -0x12);
                puVar42 = (uint *)(puVar28 + -0x1c);
                uVar36 = *puVar42;
                *puVar42 = *puVar42 + uVar15;
                *(uint *)(puVar28 + -0x1a) =
                     *(int *)(puVar28 + -0x1a) + iVar12 + iVar13 + (uint)CARRY2(uVar14,uVar37) +
                     (uint)CARRY2(uVar36,uVar15);
                puVar42 = (uint *)(puVar28 + -0x20);
                uVar36 = *puVar42;
                *puVar42 = *puVar42 + 1;
                *(uint *)(puVar28 + -0x1e) = *(int *)(puVar28 + -0x1e) + (uint)(0xfffe < uVar36);
              }
              return *(uint **)(puVar28 + -0x20);
            default:
              puVar11 = (uint *)CONCAT11(cVar18,*(char *)&DAT_554c_5596);
              if (*(char *)&DAT_554c_5596 == '\0') {
                *(undefined1 *)&DAT_554c_5595 = (char)puVar33;
                *(int *)&DAT_554c_5178 = in_CX;
                *(uint *)&DAT_554c_517a = in_DX;
                puVar11 = (uint *)CONCAT11(cVar18,*(char *)&DAT_554c_5596);
                if ((*(char *)&DAT_554c_5596 == '\0') &&
                   (puVar11 = (uint *)0x0,
                   *(int *)&DAT_554c_517c != 0 || *(int *)&DAT_554c_517e != 0)) {
                  *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + '\x01';
                  *(undefined2 *)&DAT_554c_557e = 0x2000;
                  *(undefined2 *)&DAT_554c_557c = 0x2fe;
                  FUN_1a9e_5938();
                  uVar35 = ((undefined2 *)&DAT_554c_517c)[1];
                  pcVar4 = (code *)*(undefined2 *)&DAT_554c_517c;
                  *(undefined2 *)&DAT_554c_557e = 0x2000;
                  puVar25 = (undefined2 *)&DAT_554c_557c;
                  *(undefined2 *)&DAT_554c_557c = 0x303;
                  (*pcVar4)();
                  *(undefined2 *)((int)puVar25 + -2) = 0x2000;
                  *(undefined2 *)((int)puVar25 + -4) = 0x307;
                  puVar11 = (uint *)FUN_1a9e_599d();
                  *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + -1;
                }
              }
              return puVar11;
            case (int *)0x7:
              return puVar16;
            case (int *)0x8:
              iVar27 = *(int *)(puVar28 + (int)in_AX + 0x6bf8) * -0x15;
              puVar16 = *(uint **)(puVar28 + 6);
              if ((*(uint *)(puVar28 + 8) == DAT_5b41_0ca2) && (puVar16 == DAT_5b41_0ca0)) {
                DAT_5b41_0cb9 = 0;
              }
              else {
                puVar16 = *(uint **)(puVar28 + 6);
                if ((*(uint *)(puVar28 + 8) == DAT_5b41_0c9e) && (puVar16 == DAT_5b41_0c9c)) {
                  DAT_5b41_0cbb = 0;
                }
                else {
                  *(undefined2 *)(iVar27 + -2) = *(undefined2 *)(puVar28 + 8);
                  *(undefined2 *)(iVar27 + -4) = *(undefined2 *)(puVar28 + 6);
                  *(undefined2 *)(iVar27 + -6) = 0x2000;
                  *(undefined2 *)(iVar27 + -8) = 0xf845;
                  puVar16 = (uint *)FUN_22de_0351();
                }
              }
              return puVar16;
            case (int *)0x9:
              *(char *)(int *)((int)puVar33 + (int)piVar32) =
                   (char)*(int *)((int)puVar33 + (int)piVar32) + cVar18;
              FUN_2424_4ae2(puVar33,*(undefined2 *)(puVar28 + 8));
              uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              iVar12 = (int)*(undefined4 *)(puVar28 + 6);
              while( true ) {
                uVar39 = *(undefined2 *)(iVar12 + 0x8c);
                *(undefined2 *)(puVar28 + -2) = *(undefined2 *)(iVar12 + 0x8e);
                *(undefined2 *)(puVar28 + -4) = uVar39;
                if ((*(int *)(puVar28 + -4) == 0 && *(int *)(puVar28 + -2) == 0) ||
                   (*(int *)(puVar28 + -6) != 0)) break;
                uVar41 = *(undefined4 *)(puVar28 + -4);
                uVar35 = (undefined2)((ulong)uVar41 >> 0x10);
                iVar12 = (int)uVar41;
                if ((*(int *)(iVar12 + 8) == 0x76) && (*(int *)(iVar12 + 0x4a) == 0x20)) {
                  auStack_1b[1] = (undefined1)((ulong)uVar41 >> 0x10);
                  uStack_19 = (undefined1)((ulong)uVar41 >> 0x18);
                  if (*(int *)(iVar12 + 0x24) ==
                      *(int *)((int)*(undefined4 *)(puVar28 + 6) + 0x24) + -0x20) {
                    bVar40 = (*(byte *)(iVar12 + 0xc) & 0x30) != 0;
                    if (((*(int *)(puVar28 + -10) != 0) || (bVar40)) ||
                       (*(int *)((int)*(undefined4 *)(puVar28 + -4) + 0x22) !=
                        *(int *)((int)*(undefined4 *)(puVar28 + 6) + 0x22))) {
                      if (((*(int *)(puVar28 + -10) != 0) && (!bVar40)) &&
                         (uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -4) >> 0x10),
                         iVar12 = (int)*(undefined4 *)(puVar28 + -4),
                         uVar39 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10),
                         iVar13 = (int)*(undefined4 *)(puVar28 + 6),
                         *(int *)(iVar12 + 0x22) + *(int *)(iVar12 + 0x48) ==
                         *(int *)(iVar13 + 0x22) + *(int *)(iVar13 + 0x48))) {
                        *(undefined2 *)(puVar28 + -6) = 9;
                      }
                    }
                    else {
                      *(undefined2 *)(puVar28 + -6) = 7;
                    }
                  }
                }
                uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -4) >> 0x10);
                iVar12 = (int)*(undefined4 *)(puVar28 + -4);
              }
              uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              iVar13 = (int)*(undefined4 *)(puVar28 + 6);
              iVar12 = *(int *)(iVar13 + 0x4a) + 0x10;
              auStack_1b[1] = (undefined1)iVar12;
              uStack_19 = (undefined1)((uint)iVar12 >> 8);
              auStack_1d[1] = (undefined1)*(undefined2 *)(iVar13 + 0x4a);
              auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(iVar13 + 0x4a) >> 8);
              uStack_1e = 0x10;
              auStack_1d[0] = 0;
              puStack_20 = (uint *)0x0;
              unique0x10001828 = iVar12;
              FUN_2424_4ae2(iVar13,*(undefined2 *)(puVar28 + 8),0x2000);
              uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              iVar12 = (int)*(undefined4 *)(puVar28 + 6);
              while( true ) {
                uVar39 = *(undefined2 *)(iVar12 + 0x8c);
                *(undefined2 *)(puVar28 + -2) = *(undefined2 *)(iVar12 + 0x8e);
                *(undefined2 *)(puVar28 + -4) = uVar39;
                if ((*(int *)(puVar28 + -4) == 0 && *(int *)(puVar28 + -2) == 0) ||
                   (*(int *)(puVar28 + -8) != 0)) break;
                uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -4) >> 0x10);
                iVar12 = (int)*(undefined4 *)(puVar28 + -4);
                if ((*(int *)(iVar12 + 8) == 0x76) && (*(int *)(iVar12 + 0x4a) == 0x20)) {
                  uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
                  iVar12 = (int)*(undefined4 *)(puVar28 + 6);
                  uVar39 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -4) >> 0x10);
                  iVar13 = (int)*(undefined4 *)(puVar28 + -4);
                  if (*(int *)(iVar12 + 0x24) + *(int *)(iVar12 + 0x4a) == *(int *)(iVar13 + 0x24))
                  {
                    bVar40 = (*(byte *)(iVar13 + 0xc) & 0x30) == 0;
                    if (((*(int *)(puVar28 + -10) != 0) || (bVar40)) ||
                       (*(int *)((int)*(undefined4 *)(puVar28 + -4) + 0x22) !=
                        *(int *)((int)*(undefined4 *)(puVar28 + 6) + 0x22))) {
                      if (((*(int *)(puVar28 + -10) != 0) && (!bVar40)) &&
                         (uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -4) >> 0x10),
                         iVar12 = (int)*(undefined4 *)(puVar28 + -4),
                         uVar39 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10),
                         iVar13 = (int)*(undefined4 *)(puVar28 + 6),
                         *(int *)(iVar12 + 0x22) + *(int *)(iVar12 + 0x48) ==
                         *(int *)(iVar13 + 0x22) + *(int *)(iVar13 + 0x48))) {
                        *(undefined2 *)(puVar28 + -8) = 0xc;
                      }
                    }
                    else {
                      *(undefined2 *)(puVar28 + -8) = 10;
                    }
                  }
                }
                uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -4) >> 0x10);
                iVar12 = (int)*(undefined4 *)(puVar28 + -4);
              }
              uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              iVar12 = (int)*(undefined4 *)(puVar28 + 6);
              if ((*(int *)(iVar12 + 0xae) != *(int *)(puVar28 + -6)) ||
                 (*(int *)(iVar12 + 0xb4) != *(int *)(puVar28 + -8))) {
                auStack_1b[1] = 1;
                uStack_19 = 0;
                auStack_1d[1] = (undefined1)*(undefined2 *)(puVar28 + 8);
                auStack_1b[0] = (undefined1)((uint)*(undefined2 *)(puVar28 + 8) >> 8);
                uStack_1e = (undefined1)*(undefined2 *)(puVar28 + 6);
                auStack_1d[0] = (byte)((uint)*(undefined2 *)(puVar28 + 6) >> 8);
                puStack_20 = (uint *)0x2000;
                FUN_2424_3746();
                puStack_20 = (uint *)0x2;
                FUN_2424_3746(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8));
                uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
                iVar12 = (int)*(undefined4 *)(puVar28 + 6);
                *(undefined2 *)(iVar12 + 0xae) = *(undefined2 *)(puVar28 + -6);
                *(undefined2 *)(iVar12 + 0xb4) = *(undefined2 *)(puVar28 + -8);
                FUN_2424_3746(iVar12,*(undefined2 *)(puVar28 + 8),1);
                FUN_2424_3746(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8),2);
              }
              uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + 6) >> 0x10);
              iVar12 = (int)*(undefined4 *)(puVar28 + 6);
              *(undefined2 *)(iVar12 + 0xae) = *(undefined2 *)(puVar28 + -6);
              *(undefined2 *)(iVar12 + 0xb4) = *(undefined2 *)(puVar28 + -8);
              if ((*(int *)(puVar28 + -6) == 0) && (*(int *)(puVar28 + -8) == 0)) {
                puVar16 = (uint *)0x0;
              }
              else {
                puVar16 = (uint *)0x1;
              }
              return puVar16;
            }
          }
          puVar16 = (uint *)FUN_2424_1e00(puVar28 + -8);
        }
        return puVar16;
      case (uint *)0x3:
        uVar36 = puVar16[0x18];
        *pbVar22 = *pbVar22 >> 1;
        pcVar2 = (char *)(uVar36 * -0x7d + 9);
        *pcVar2 = *pcVar2 + (char)(in_DX >> 8);
        if (((DAT_5b41_0c9c == (uint *)0x0 && DAT_5b41_0c9e == 0) ||
            (DAT_5b41_0cac == 0 && DAT_5b41_0cae == 0)) ||
           ((DAT_554c_2fca != 0 && (DAT_5b41_0ca4 == 0 && DAT_5b41_0ca6 == 0)))) {
          FUN_2e67_0e27();
        }
        else {
          DAT_5b41_0cb8 = 1;
        }
        return (uint *)(uint)DAT_5b41_0cb8;
      case (uint *)0x4:
        do {
          *(uint *)(puVar28 + -0x18) = (uint)pbVar22[0x15];
          puStack_20 = (uint *)0x3;
          uVar35 = FUN_28eb_3b36(*(undefined2 *)(puVar28 + -0x1c),*(undefined2 *)(puVar28 + -0x1a),
                                 pbVar22);
          *(undefined2 *)(puVar28 + -0x14) = uVar35;
          do {
            uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -0x20) >> 0x10);
            iVar12 = (int)*(undefined4 *)(puVar28 + -0x20);
            puStack_20 = (uint *)*(int *)(iVar12 + 0x2e);
            *(int *)(puVar28 + -6) =
                 (int)puStack_20 + (int)*(char *)(iVar12 + *(int *)(puVar28 + -0x18) * 2 + 0x7a);
            puStack_20 = (uint *)*(int *)(*(int *)(puVar28 + -0x20) + 0x30);
            *(int *)(puVar28 + -8) =
                 (int)puStack_20 +
                 (int)*(char *)(*(int *)(puVar28 + -0x20) + *(int *)(puVar28 + -0x18) * 2 + 0x7b);
            if (*(int *)(puVar28 + -2) < *(int *)(puVar28 + -6)) {
              *(int *)(puVar28 + -10) = *(int *)(puVar28 + -2) - DAT_5b41_0925;
              iVar12 = *(int *)(puVar28 + -6);
            }
            else {
              *(int *)(puVar28 + -10) = *(int *)(puVar28 + -6) - DAT_5b41_0925;
              iVar12 = *(int *)(puVar28 + -2);
            }
            *(int *)(puVar28 + -0xe) = iVar12 - DAT_5b41_0925;
            if (*(int *)(puVar28 + -4) < *(int *)(puVar28 + -8)) {
              *(int *)(puVar28 + -0xc) = *(int *)(puVar28 + -4) - DAT_5b41_0927;
              iVar12 = *(int *)(puVar28 + -8);
            }
            else {
              *(int *)(puVar28 + -0xc) = *(int *)(puVar28 + -8) - DAT_5b41_0927;
              iVar12 = *(int *)(puVar28 + -4);
            }
            iVar12 = iVar12 - DAT_5b41_0927;
            if (0 < *(int *)(puVar28 + -0x14)) {
              iVar12 = iVar12 + (*(int *)(puVar28 + -0x14) >> 1);
            }
            uVar36 = (uint)(*(int *)(puVar28 + -0xe) - *(int *)(puVar28 + -10) <
                           iVar12 - *(int *)(puVar28 + -0xc));
            *(uint *)(puVar28 + -0x10) = uVar36;
            *(uint *)(puVar28 + -0x12) = (uint)(uVar36 == 0);
            iVar13 = *(int *)(puVar28 + -0x10);
            *(int *)(puVar28 + -10) = *(int *)(puVar28 + -10) - iVar13;
            *(int *)(puVar28 + -0xe) = *(int *)(puVar28 + -0xe) + iVar13;
            *(int *)(puVar28 + -0xc) = *(int *)(puVar28 + -0xc) - *(int *)(puVar28 + -0x12);
            for (puVar30 = DAT_5b41_04ac; puVar30 != (undefined2 *)0x0;
                puVar30 = (undefined2 *)*puVar30) {
              if (((puVar30[6] == 1) && ((int)puVar30[1] <= *(int *)(puVar28 + -0xe))) &&
                 ((*(int *)(puVar28 + -10) <= (int)puVar30[3] &&
                  (((int)puVar30[2] <= iVar12 + *(int *)(puVar28 + -0x12) &&
                   (*(int *)(puVar28 + -0xc) <= (int)puVar30[4])))))) {
                puStack_20 = (uint *)0x81;
                FUN_28eb_2d82(*(undefined2 *)(puVar28 + 6),*(undefined2 *)(puVar28 + 8));
                uVar35 = *(undefined2 *)(puVar28 + -0x28);
                *(undefined2 *)(puVar28 + -0x1e) = *(undefined2 *)(puVar28 + -0x26);
                *(undefined2 *)(puVar28 + -0x20) = uVar35;
                break;
              }
            }
            if ((*(int *)(puVar28 + -0x1e) == *(int *)(puVar28 + -0x26)) &&
               (*(int *)(puVar28 + -0x20) == *(int *)(puVar28 + -0x28))) {
              *(undefined2 *)(puVar28 + -0x1e) = 0;
              *(undefined2 *)(puVar28 + -0x20) = 0;
              *(undefined2 *)(puVar28 + -0x1a) = 0;
              *(undefined2 *)(puVar28 + -0x1c) = 0;
            }
            else {
              uVar35 = *(undefined2 *)(puVar28 + -0x20);
              *(undefined2 *)(puVar28 + -0x1a) = *(undefined2 *)(puVar28 + -0x1e);
              *(undefined2 *)(puVar28 + -0x1c) = uVar35;
              uVar39 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -0x20) >> 0x10);
              iVar12 = (int)*(undefined4 *)(puVar28 + -0x20);
              uVar35 = *(undefined2 *)(iVar12 + 0x5e);
              *(undefined2 *)(puVar28 + -0x1e) = *(undefined2 *)(iVar12 + 0x60);
              *(undefined2 *)(puVar28 + -0x20) = uVar35;
            }
            if ((*(int *)(puVar28 + -0x1c) == 0 && *(int *)(puVar28 + -0x1a) == 0) ||
               (*(int *)(puVar28 + -0x20) == 0 && *(int *)(puVar28 + -0x1e) == 0)) {
              return (uint *)0x0;
            }
            if ((*(int *)(puVar28 + -0x1a) != *(int *)(puVar28 + -0x22)) ||
               (*(int *)(puVar28 + -0x1c) != *(int *)(puVar28 + -0x24))) {
              *(undefined2 *)(puVar28 + -0x16) = 1;
              *(undefined2 *)(puVar28 + -0x14) = 0;
            }
            uVar35 = (undefined2)((ulong)*(undefined4 *)(puVar28 + -0x1c) >> 0x10);
            iVar12 = (int)*(undefined4 *)(puVar28 + -0x1c);
            puStack_20 = (uint *)*(int *)(iVar12 + 0x2e);
            *(int *)(puVar28 + -2) =
                 (int)puStack_20 + (int)*(char *)(iVar12 + *(int *)(puVar28 + -0x16) * 2 + 0x7a);
            puStack_20 = (uint *)*(int *)(*(int *)(puVar28 + -0x1c) + 0x30);
            *(int *)(puVar28 + -4) =
                 (int)puStack_20 +
                 (int)*(char *)(*(int *)(puVar28 + -0x1c) + *(int *)(puVar28 + -0x16) * 2 + 0x7b);
          } while ((*(int *)(puVar28 + -0x1e) != *(int *)(puVar28 + -0x26)) ||
                  (*(int *)(puVar28 + -0x20) != *(int *)(puVar28 + -0x28)));
          pbVar22 = *(byte **)(puVar28 + -0x2a);
        } while( true );
      case (uint *)0x5:
        FUN_54a4_0043(0,(undefined2 *)&DAT_5b41_1a3c,0x7983,0);
        FUN_2424_050d(0);
        auStack_1d[1] = 0x24;
        auStack_1b[0] = 0x24;
        uStack_1e = 0x1a;
        auStack_1d[0] = 0x3c;
        FUN_2424_03c5();
        DAT_5b41_0945 = 0;
        DAT_5b41_0943 = 0;
        DAT_5b41_093d = 0;
        DAT_5b41_093b = 0;
        DAT_5b41_0941 = 0;
        DAT_5b41_093f = 0;
        DAT_5b41_0953 = 1;
        auStack_1d[1] = 0;
        auStack_1b[0] = 0;
        uStack_1e = 0xfc;
        auStack_1d[0] = 0xff;
        puStack_20 = (uint *)0x2424;
        puVar16 = (uint *)FUN_406b_03cb();
        if (puVar16 == (uint *)0x0) {
          if (DAT_5b41_094f == 0) {
            uStack_1e = 0x22;
          }
          else {
            uStack_1e = 0x23;
          }
          auStack_1d[1] = 0xdc;
          auStack_1b[0] = 0xff;
          auStack_1d[0] = 0;
          puStack_20 = (uint *)0x406b;
          puVar16 = (uint *)FUN_406b_03cb();
        }
        return puVar16;
      case (uint *)0x6:
        cRam00059b4d = cRam00059b4d + (char)in_DX;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (uint *)0x7:
        goto switchD_2000_8a43_caseD_7;
      case (uint *)0x9:
        goto switchD_2000_8a43_caseD_9;
      }
      goto switchD_2000_8a43_caseD_8;
    }
    iVar12 = FUN_2424_4007(puVar28 + -8);
    uVar39 = (undefined2)((ulong)puVar42 >> 0x10);
    if (iVar12 == 0) goto LAB_2424_4827;
LAB_2424_489b:
    puVar16 = (uint *)0x1;
  }
  return puVar16;
}


