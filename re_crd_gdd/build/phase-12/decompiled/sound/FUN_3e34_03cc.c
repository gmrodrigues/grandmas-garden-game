// TIM2.EXE: FUN_3e34_03cc @ file 0x04390C Ghidra 0x3E70C
// Subsystem: sound | Size: 181 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00036af8) overlaps instruction at (ram,0x00036af7)
    */

uint __cdecl16far FUN_3e34_03cc(undefined4 param_1,undefined2 param_2)

{
  int *piVar1;
  uint *puVar2;
  undefined2 *puVar3;
  long lVar4;
  byte bVar5;
  int iVar6;
  undefined2 uVar7;
  int iVar8;
  undefined2 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int in_DX;
  char cVar13;
  uint uVar14;
  uint unaff_SI;
  byte *unaff_DI;
  undefined2 uVar15;
  undefined2 unaff_ES;
  undefined2 uVar16;
  undefined2 unaff_SS;
  byte abStack_68 [50];
  undefined2 *puStack_36;
  int iStack_34;
  int iStack_32;
  int iStack_30;
  int iStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined2 *puStack_14;
  uint uStack_12;
  byte *pbVar17;
  undefined4 local_a;
  int iStack_8;
  undefined4 local_6;
  
  uVar11 = (int)DAT_554c_42dd - 2;
  if (0xd < uVar11) {
    DAT_5b41_1ad2 = 1;
    return uVar11;
  }
  iVar8 = uVar11 * 2;
  uVar16 = 0x3000;
  cVar13 = (char)((uint)in_DX >> 8);
  uVar14 = unaff_SI;
  switch(uVar11) {
  case 0:
    do {
      _uStack_12 = CONCAT22(0x31fc,uStack_12);
      uVar16 = FUN_4551_0370();
      ((undefined2 *)&DAT_5b41_0973)[unaff_SI] = uVar16;
      _uStack_12 = CONCAT22(0x3218,uStack_12);
      uVar16 = FUN_4551_0370();
      ((undefined2 *)&DAT_5b41_197a)[unaff_SI] = uVar16;
      _uStack_12 = CONCAT22(0x3234,uStack_12);
      uVar16 = FUN_4551_0370();
      ((undefined2 *)&DAT_5b41_197e)[unaff_SI] = uVar16;
      _uStack_12 = CONCAT22(0x3250,uStack_12);
      uVar16 = FUN_4551_0370();
      ((undefined2 *)&DAT_5b41_1982)[unaff_SI] = uVar16;
      _uStack_12 = CONCAT22(0x326c,uStack_12);
      uVar16 = FUN_4551_0370();
      ((undefined2 *)&DAT_5b41_1986)[unaff_SI] = uVar16;
      _uStack_12 = CONCAT22((char *)s_DOSBIN_ITF_554c_3283 + 5,uStack_12);
      uVar16 = FUN_4551_0370();
      ((undefined2 *)&DAT_5b41_0977)[unaff_SI] = uVar16;
      _uStack_12 = CONCAT22((char *)s_nofiles_non_554c_3299 + 0xb,uStack_12);
      uVar16 = FUN_4551_0370();
      ((undefined2 *)&DAT_5b41_198a)[unaff_SI] = uVar16;
      unaff_SI = unaff_SI + 1;
    } while ((int)unaff_SI < 2);
    *(undefined2 *)((uint)param_1 + 0x98) =
         *(undefined2 *)
          ((uint)((*(byte *)((uint)param_1 + 0xc) & 0x10) != 0) * 2 + *(int *)(iRam000557da + 0x46))
    ;
    _uStack_12 = CONCAT22(0x32ea,uStack_12);
    uVar14 = FUN_28eb_3670();
    return uVar14;
  case 1:
    *(int *)(iVar8 + unaff_SI) = *(int *)(iVar8 + unaff_SI) + uVar11;
    if ((DAT_5b41_0d14 != 0) && (DAT_554c_3e4a != 0)) {
      DAT_5b41_0d14 = 0;
      _uStack_12 = (ulong)DAT_5b41_0d12 << 0x10;
      puStack_14 = (undefined2 *)0x3000;
      uStack_18 = (undefined2 *)CONCAT22(0x1920,(undefined2 *)uStack_18);
      puStack_14 = (undefined2 *)FUN_460e_0f42();
      pbVar17 = (byte *)((ulong)_uStack_12 >> 0x10);
      _uStack_12 = CONCAT22(pbVar17,in_DX);
      uVar11 = 0x460e;
      uStack_18 = (undefined2 *)0x460e192a;
      iVar8 = FUN_460e_141e();
      uVar14 = 0;
      iStack_8 = 0;
      local_6._2_2_ = in_DX;
      while (local_6._0_2_ = iVar8, (uint)local_6 != 0 || local_6._2_2_ != 0) {
        iVar12 = *(int *)((uint)local_6 + 10);
        iVar8 = *(int *)((uint)local_6 + 8);
        *(int *)((uint)local_6 + 10) = iStack_8;
        *(int *)((uint)local_6 + 8) = uVar14;
        iStack_8 = local_6._2_2_;
        local_6._2_2_ = iVar12;
        uVar14 = (uint)local_6;
      }
      DAT_554c_42c8 = 0;
      DAT_554c_42ca = DAT_554c_3e4a + -1;
      DAT_554c_42c4 = 0;
      DAT_554c_42c6 = DAT_554c_49aa - 1;
      DAT_554c_42d8 = DAT_554c_42d2;
      if (iRam000557c0 == 0) {
        while (uVar14 != 0 || iStack_8 != 0) {
          iVar8 = *(int *)(uVar14 + 0xe) * 0x12;
          if (*(int *)(iVar8 + 0xda) != 0 || *(int *)(iVar8 + 0xdc) != 0) {
            puVar3 = (undefined2 *)(*(int *)(uVar14 + 0xe) * 0x12 + 0xda);
            _uStack_12 = CONCAT22(uVar14,0x460e);
            puStack_14 = (undefined2 *)0x19ee;
            (*(code *)*puVar3)();
          }
          piVar1 = (int *)(uVar14 + 10);
          uVar14 = *(int *)(uVar14 + 8);
          iStack_8 = *piVar1;
        }
      }
      else {
        uVar11 = 0x551a;
        _uStack_12 = 0x460e19ac;
        func_0x000551c0();
      }
      if (unaff_SI != 0) {
        _uStack_12 = CONCAT22(DAT_554c_3e4a,DAT_554c_49aa);
        puStack_14 = (undefined2 *)0x0;
        uStack_18 = (undefined2 *)(ulong)uVar11;
        uVar11 = 0x406b;
        _iStack_1c = CONCAT22(0x1a21,iStack_1c);
        FUN_406b_000c();
      }
      DAT_554c_42d6 = DAT_554c_42d2;
      DAT_554c_42d8 = 0xa000;
      if (DAT_5b41_1b96 != 0) {
        uVar11 = 0x406b;
        _uStack_12 = CONCAT22(0x1a3c,uStack_12);
        FUN_406b_053a();
      }
      _uStack_12 = (ulong)DAT_554c_49aa << 0x10;
      puStack_14 = (undefined2 *)0x0;
      uStack_18 = (undefined2 *)CONCAT22(uVar11,0x1a4d);
      FUN_406b_0880();
      uStack_18 = (undefined2 *)0x406b;
      _iStack_1c = CONCAT22(0x1a54,iStack_1c);
      FUN_406b_04d8();
      DAT_554c_42d6 = DAT_554c_42d4;
      DAT_554c_42d8 = DAT_554c_42d2;
      puStack_14 = (undefined2 *)0x0;
      _uStack_12 = CONCAT22(DAT_554c_3e4a,DAT_554c_49aa);
      uStack_18 = (undefined2 *)0x1;
      _iStack_1c = CONCAT22(unaff_SS,(int)&uStack_18 + 2);
      uStack_20 = 0x406b1a80;
      FUN_2424_1e00();
      _uStack_12 = CONCAT22(0x1a88,uStack_12);
      uVar11 = FUN_2424_0304();
    }
    return uVar11;
  case 2:
    *(char *)(iVar8 + unaff_SI) = *(char *)(iVar8 + unaff_SI) + (byte)uVar11;
    return uVar11;
  case 3:
    _uStack_12 = CONCAT22(0xe6ff,uStack_12);
    FUN_1000_130c();
    return (uint)local_6;
  case 4:
    if (*(int *)(iVar8 + 0x10) == 0x38) {
      *(undefined2 *)(iVar8 + 0x10) = 0;
    }
    *(undefined2 *)((uint)param_1 + 0xa8) = *(undefined2 *)((uint)param_1 + 0x10);
    uStack_12 = 0x3000;
    puStack_14 = (undefined2 *)0xce17;
    FUN_31f7_ac91();
    _uStack_12 = CONCAT22((uint)param_1,param_1._2_2_);
    uStack_18 = (undefined2 *)0x3000ce22;
    puStack_14 = (undefined2 *)(uint)param_1;
    FUN_28eb_3328();
    uStack_18 = (undefined2 *)CONCAT22(3,param_1._2_2_);
    iStack_1c = 0x28eb;
    uStack_20 = CONCAT22(0xce2f,(int)uStack_20);
    FUN_2424_0f94();
    _iStack_1c = CONCAT22((uint)param_1,2);
    uStack_20 = param_1;
    uStack_24 = 0x2424ce3c;
    uVar14 = FUN_28eb_2d82();
    return uVar14;
  case 5:
    if (*(int *)((uint)param_1 + 0x10) < DAT_5b41_1a9a) {
      iVar8 = 0;
    }
    else if (*(int *)((uint)param_1 + 0x10) < DAT_5b41_1a9c) {
      iVar8 = 1;
    }
    else {
      iVar8 = 2;
    }
    *(uint *)((uint)param_1 + 0xc) = *(uint *)((uint)param_1 + 0xc) | 0x40;
    if (((((undefined2 *)&DAT_5b41_1a8e)[iVar8] + 1 < *(int *)((uint)param_1 + 0x10)) &&
        (*(int *)((uint)param_1 + 0x10) != ((undefined2 *)&DAT_5b41_1a9a)[iVar8])) ||
       ((*(int *)((uint)param_1 + 0x16) != 0 &&
        ((*(int *)((uint)param_1 + 0x10) == ((undefined2 *)&DAT_5b41_1a8e)[iVar8] + 1 &&
         (*(int *)((uint)param_1 + 0xae) = *(int *)((uint)param_1 + 0xae) + 1,
         iVar8 * 0x14 + 0x14 <= *(int *)((uint)param_1 + 0xae))))))) {
      *(int *)((uint)param_1 + 0x10) = *(int *)((uint)param_1 + 0x10) + 1;
    }
    pbVar17 = unaff_DI;
    if ((((undefined2 *)&DAT_5b41_1a8e)[iVar8] + 4 <= *(int *)((uint)param_1 + 0x10)) &&
       (*(int *)((uint)param_1 + 0x10) <= ((undefined2 *)&DAT_5b41_1a8e)[iVar8] + 6)) {
      _uStack_12 = ZEXT24(unaff_DI) << 0x10;
      puStack_14 = (undefined2 *)
                   *(undefined2 *)
                    ((*(int *)((uint)param_1 + 0x10) - ((undefined2 *)&DAT_5b41_1a8e)[iVar8]) * 2 +
                    0x3c86);
      uStack_18 = (undefined2 *)0x260008;
      _iStack_1c = CONCAT22(0x3000,param_1._2_2_);
      uStack_20._0_2_ = 0x3000;
      uVar16 = 0x28eb;
      uStack_24 = CONCAT22(0xb5d0,(int)uStack_24);
      uStack_20._2_2_ = (undefined2 *)(uint)param_1;
      FUN_28eb_51b3();
      uStack_20 = ZEXT24(uStack_20._2_2_) << 0x10;
      uStack_24 = CONCAT22(*(undefined2 *)
                            ((*(int *)((uint)param_1 + 0x10) - ((undefined2 *)&DAT_5b41_1a8e)[iVar8]
                             ) * 2 + 0x3c86),0x26);
      uStack_28 = 0x80000;
      uStack_2c = param_1;
      iStack_2e = 0x28eb;
      iStack_30 = -0x4a00;
      FUN_31f7_b9f5();
      uVar14 = (uint)param_1;
      iVar8 = param_1._2_2_;
      lVar4 = _uStack_12;
      while( true ) {
        _uStack_12 = lVar4;
        lVar4 = _uStack_12;
        pbVar17 = (byte *)((ulong)_uStack_12 >> 0x10);
        iVar12 = *(int *)(uVar14 + 0x8e);
        uVar14 = *(uint *)(uVar14 + 0x8c);
        if (uVar14 == 0 && iVar12 == 0) break;
        iVar8 = iVar12;
        if ((*(byte *)(uVar14 + 0xb) & 0x10) != 0) {
          _uStack_12 = CONCAT22(pbVar17,iVar12);
          uStack_18 = (undefined2 *)0x28ebb61b;
          puStack_14 = (undefined2 *)uVar14;
          iVar10 = FUN_31f7_9711();
          *(int *)(uVar14 + 0x3c) = -iVar10;
          lVar4 = _uStack_12;
          if ((*(int *)(uVar14 + 8) == 0x36) && (*(int *)(uVar14 + 0x10) < DAT_5b41_09a3)) {
            *(int *)(uVar14 + 0x10) = DAT_5b41_09a3;
          }
        }
      }
      *(int *)((uint)param_1 + 0xae) = *(int *)((uint)param_1 + 0xae) + 1;
    }
    uVar14 = *(uint *)((uint)param_1 + 0x10);
    if (uVar14 != *(uint *)((uint)param_1 + 0x12)) {
      _uStack_12 = CONCAT22(pbVar17,param_1._2_2_);
      uStack_18 = (undefined2 *)CONCAT22(uVar16,0xb67a);
      puStack_14 = (undefined2 *)(uint)param_1;
      uVar14 = FUN_28eb_3328();
    }
    return uVar14;
  case 6:
    if (*(int *)((uint)local_6 + 0x16) == 0) {
      if (*(int *)((uint)local_6 + 0x10) == 0) {
        return uVar11;
      }
      *(undefined2 *)((uint)local_6 + 0x10) = 0;
    }
    else {
      *(undefined2 *)((uint)local_6 + 0x10) = 1;
      *(undefined2 *)((uint)local_6 + 0x16) = 0;
    }
    _uStack_12 = CONCAT22((uint)local_6,0x3000);
    puStack_14 = (undefined2 *)0x9c2b;
    uVar14 = FUN_28eb_3328();
    return uVar14;
  case 7:
    do {
      _uStack_12 = CONCAT22(0x83fa,uStack_12);
      FUN_31f7_66af();
      do {
        if (-0x400 < *(int *)(uStack_12 + 0x3c)) {
          FUN_31f7_6656();
          pbVar17 = (byte *)0x8435;
          uVar14 = (uint)pbVar17;
          FUN_2fc8_152f();
          unaff_DI = (byte *)FUN_1000_19bf();
          *(int *)(uStack_12 + 0x3c) = *(int *)(uStack_12 + 0x3c) - (int)unaff_DI;
          _uStack_12 = CONCAT22(0x8457,uStack_12);
          FUN_549b_007a();
          uVar16 = (undefined2)((ulong)_uStack_12 >> 0x10);
          if (*(int *)((int)_uStack_12 + 0x3c) < -0x400) {
            *(undefined2 *)((int)_uStack_12 + 0x3c) = 0xfc00;
          }
        }
        uVar11 = (uint)((ulong)_uStack_12 >> 0x10);
        iVar6 = (int)_uStack_12;
        if (*(int *)(iVar6 + 0x24) != *(int *)(iVar6 + 0x2c)) {
          if ((*(int *)(iVar6 + 8) == 0x36) && (*(int *)(iVar6 + 0x10) < 6)) {
            *(undefined2 *)(iVar6 + 0x10) = 6;
            _uStack_12 = CONCAT22(0x8498,iVar6);
            FUN_28eb_3328();
            uVar14 = uVar11;
          }
          iVar6 = (int)unaff_DI >> 1;
          iVar8 = (int)_uStack_12;
          uVar16 = (undefined2)((ulong)_uStack_12 >> 0x10);
          if ((int)uVar14 < iStack_8 + -4) {
            if ((*(int *)(iVar8 + 0x3a) < 0x200) &&
               (*(int *)(iVar8 + 0x3a) = *(int *)(iVar8 + 0x3a) + iVar6,
               0x200 < *(int *)(iVar8 + 0x3a))) {
              *(undefined2 *)(iVar8 + 0x3a) = 0x200;
            }
          }
          else if (iStack_8 + 4 < (int)uVar14) {
            if ((-0x200 < *(int *)(iVar8 + 0x3a)) &&
               (*(int *)(iVar8 + 0x3a) = *(int *)(iVar8 + 0x3a) - iVar6,
               *(int *)(iVar8 + 0x3a) < -0x200)) {
              *(undefined2 *)(iVar8 + 0x3a) = 0xfe00;
            }
          }
          else if (*(int *)(iVar8 + 0x3a) < 1) {
            *(int *)(iVar8 + 0x3a) = *(int *)(iVar8 + 0x3a) + iVar6;
            if (0 < *(int *)(iVar8 + 0x3a)) goto LAB_31f7_65b4;
          }
          else {
            *(int *)(iVar8 + 0x3a) = *(int *)(iVar8 + 0x3a) - iVar6;
            if (*(int *)(iVar8 + 0x3a) < 0) {
LAB_31f7_65b4:
              *(undefined2 *)(iVar8 + 0x3a) = 0;
            }
          }
        }
        do {
          uVar16 = (undefined2)((ulong)_uStack_12 >> 0x10);
          iVar6 = (int)_uStack_12;
          if (*(int *)(iVar6 + 8) == 0x2d) {
            *(undefined2 *)(iVar6 + 0xb4) = 0;
            *(undefined2 *)(iVar6 + 0x16) = 0;
            *(undefined2 *)(iVar6 + 0x10) = 0;
          }
          uVar14 = *(uint *)(iVar6 + 0x8e);
          iVar6 = *(int *)(iVar6 + 0x8c);
          _uStack_12 = CONCAT22(uVar14,iVar6);
          if (iVar6 == 0 && uVar14 == 0) {
            uVar14 = *(uint *)((uint)param_1 + 0x10);
            if (uVar14 != *(uint *)((uint)param_1 + 0x12)) {
              _uStack_12 = CONCAT22(0x8585,iVar6);
              uVar14 = FUN_28eb_3328();
            }
            return uVar14;
          }
        } while (*(int *)(iVar6 + 0x24) <= *(int *)((uint)param_1 + 0x24) + 0x1f);
        *(uint *)(iVar6 + 10) = *(uint *)(iVar6 + 10) & 0xfffe;
      } while ((((int)uVar14 < iStack_8 + -0x10) || (iStack_8 + 0x10 < (int)uVar14)) ||
              (*(int *)((uint)param_1 + 0x24) + 0x21 <= *(int *)(iVar6 + 0x24)));
    } while( true );
  case 8:
code_r0x00036afc:
    uVar7 = (undefined2)((ulong)uStack_20 >> 0x10);
    iVar12 = (*(int *)((int)uStack_20 + 0x30) +
             (int)*(char *)((int)uStack_20 + (uint)local_6 * 2 + 0x7b)) -
             *(int *)((uint)param_1 + 0x24);
    _uStack_12 = CONCAT22(param_2,uVar16);
    uVar16 = 0x2e67;
    puStack_14 = (undefined2 *)0x6b47;
    iVar8 = FUN_2e67_13d4();
    uVar7 = DAT_5b41_0937;
    if (iVar8 == 0) {
      if ((uStack_20._2_2_ != (undefined2 *)iStack_32) || ((int)uStack_20 != iStack_34)) {
        _iStack_1c = uStack_20;
        goto LAB_31f7_4f5f;
      }
      uStack_20 = 0;
      _iStack_1c = 0;
LAB_31f7_4f6d:
      do {
        lVar4 = _iStack_1c;
        iVar6 = (int)((ulong)_iStack_1c >> 0x10);
        if (iStack_1c != 0 || iVar6 != 0) {
          if ((int)uStack_20 != 0 || uStack_20._2_2_ != (undefined2 *)0x0) goto LAB_31f7_4b13;
        }
        do {
          if ((undefined2 *)uStack_18 != (undefined2 *)0x0 || uStack_18._2_2_ != 0) {
            uStack_18 = (undefined2 *)
                        CONCAT22(((undefined2 *)uStack_18)[1],(undefined2 *)*uStack_18);
          }
          if ((undefined2 *)uStack_18 == (undefined2 *)0x0 && uStack_18._2_2_ == 0) {
            DAT_5b41_0937 = uVar7;
            return 0;
          }
        } while (((*(int *)((uint)param_1 + 8) != 0x4d) || (((undefined2 *)uStack_18)[4] != 0x4c))
                && (((undefined2 *)uStack_18)[4] != 10));
        puStack_36 = (undefined2 *)((undefined2 *)uStack_18)[0x3b];
        uStack_20._2_2_ = (undefined2 *)puStack_36[3];
        iStack_30 = puStack_36[2];
        _iStack_1c = CONCAT22(uStack_20._2_2_,iStack_30);
        _iStack_34 = CONCAT22(puStack_36[5],puStack_36[4]);
        local_6 = (ulong)(uint)*(byte *)(puStack_36 + 10) << 0x10;
        uStack_20._0_2_ = iStack_30 + (uint)*(byte *)(puStack_36 + 10) * 4;
        iStack_2e = (int)uStack_20._2_2_;
LAB_31f7_4f5f:
        uStack_20 = CONCAT22(*(undefined2 *)((int)uStack_20 + 0x60),
                             *(undefined2 *)((int)uStack_20 + 0x5e));
      } while( true );
    }
    DAT_5b41_0937 = 0x1000;
    _uStack_12 = CONCAT22(*puStack_36,0x2e67);
    puStack_14 = (undefined2 *)0x6b6c;
    FUN_2424_0a23();
    _uStack_12 = CONCAT22(0x6b7c,uStack_12);
    DAT_5b41_0937 = uVar7;
    uStack_24._0_2_ = FUN_2321_0f22();
    if ((int)uStack_24 != 0 || iVar12 != 0) {
      _uStack_12 = CONCAT22(0x6b93,uStack_12);
      uStack_24._2_2_ = iVar12;
      uStack_28._0_2_ = FUN_2321_0f22();
      if ((int)uStack_28 != 0 || iVar12 != 0) {
        _uStack_12 = CONCAT22(0x6baf,uStack_12);
        uStack_28._2_2_ = iVar12;
        iVar8 = FUN_2321_0ff6();
        uStack_2c = CONCAT22(iVar12,iVar8);
        if (iVar8 != 0 || iVar12 != 0) {
          _uStack_12 = CONCAT22(uStack_24._2_2_,(int)uStack_24);
          puStack_14 = (undefined2 *)0x2321;
          uStack_18 = (undefined2 *)CONCAT22(0x6bcf,(undefined2 *)uStack_18);
          FUN_28eb_2a59();
          iVar8 = (int)uStack_28;
          *(uint *)((int)uStack_24 + 10) = *(uint *)((int)uStack_24 + 10) | 0x10;
          *(undefined2 *)((int)uStack_24 + 0x22) = *(undefined2 *)((uint)param_1 + 0x22);
          *(int *)((int)uStack_24 + 0x24) = *(int *)((uint)param_1 + 0x24) + unaff_SI;
          puStack_14 = (undefined2 *)0x0;
          uStack_18 = (undefined2 *)CONCAT22((undefined2 *)&DAT_5b41_0557,uStack_28._2_2_);
          iStack_1c = 0x28eb;
          uStack_20 = CONCAT22((undefined2 *)&DAT_5b41_0cb9,(int)uStack_20);
          FUN_28eb_2a59();
          *(uint *)((int)uStack_28 + 10) = *(uint *)((int)uStack_28 + 10) | 0x10;
          uVar16 = *(undefined2 *)((int)uStack_24 + 0x22);
          *(undefined2 *)((int)uStack_28 + 0x24) = *(undefined2 *)((int)uStack_24 + 0x24);
          *(undefined2 *)((int)uStack_28 + 0x22) = uVar16;
          iStack_1c = 0;
          uStack_20._2_2_ = (undefined2 *)&DAT_5b41_054f;
          uStack_20._0_2_ = uStack_2c._2_2_;
          uStack_24 = CONCAT22((int)uStack_2c,0x28eb);
          uStack_28 = CONCAT22(0x6c37,(int)uStack_28);
          FUN_28eb_2a59();
          uVar16 = (undefined2)((ulong)uStack_2c >> 0x10);
          puVar2 = (uint *)((int)uStack_2c + 10);
          *puVar2 = *puVar2 | 0x10;
          iVar6 = *(int *)((int)uStack_2c + 0x76);
          *(undefined2 *)(iVar6 + 6) = uStack_28._2_2_;
          *(int *)(iVar6 + 4) = (int)uStack_28;
          *(undefined2 *)(iVar6 + 10) = iStack_32;
          *(int *)(iVar6 + 8) = iStack_34;
          *(undefined1 *)(iVar6 + 0x14) = 0;
          *(undefined1 *)(iVar6 + 0x15) = *(undefined1 *)((int)puStack_36 + 0x15);
          *(undefined2 *)((int)uStack_28 + 0x60) = uStack_20._2_2_;
          *(int *)((int)uStack_28 + 0x5e) = (int)uStack_20;
          *(int *)((int)uStack_28 + 0x76) = iVar6;
          if (*(int *)((int)uStack_20 + 8) == 7) {
            *(int *)((int)uStack_20 + 0x78) = iVar6;
            *(undefined2 *)((int)uStack_20 + 100) = uStack_28._2_2_;
            *(int *)((int)uStack_20 + 0x62) = (int)uStack_28;
          }
          else {
            *(int *)((int)uStack_20 + (uint)local_6 * 2 + 0x76) = iVar6;
            iVar12 = (int)uStack_20 + (uint)local_6 * 4;
            *(undefined2 *)(iVar12 + 0x60) = uStack_28._2_2_;
            *(int *)(iVar12 + 0x5e) = (int)uStack_28;
          }
          *(int *)(iStack_34 + (uint)*(byte *)(iVar6 + 0x15) * 2 + 0x76) = iVar6;
          puStack_36[5] = uStack_24._2_2_;
          puStack_36[4] = (int)uStack_24;
          *(undefined1 *)((int)puStack_36 + 0x15) = 0;
          *(int *)((int)uStack_24 + 0x60) = iVar8;
          *(int *)((int)uStack_24 + 0x5e) = iStack_1c;
          *(undefined2 *)((int)uStack_24 + 0x76) = puStack_36;
          iVar12 = iStack_1c;
          if (*(int *)(iStack_1c + 8) != 7) {
            iVar12 = iStack_1c + local_6._2_2_ * 4;
          }
          *(undefined2 *)(iVar12 + 0x60) = uStack_24._2_2_;
          *(int *)(iVar12 + 0x5e) = (int)uStack_24;
          uVar16 = *(undefined2 *)((int)uStack_24 + 0x22);
          *(undefined2 *)((int)uStack_24 + 0x26) = uVar16;
          *(undefined2 *)((int)uStack_24 + 0x2a) = uVar16;
          iVar8 = *(int *)((int)uStack_24 + 0x22);
          *(int *)((int)uStack_24 + 0x1c) = iVar8 >> 0xf;
          *(int *)((int)uStack_24 + 0x1a) = iVar8;
          uVar16 = *(undefined2 *)((int)uStack_24 + 0x1c);
          uVar9 = FUN_1000_199e();
          uVar15 = (undefined2)((ulong)uStack_24 >> 0x10);
          iVar12 = (int)uStack_24;
          *(undefined2 *)(iVar12 + 0x1c) = uVar16;
          *(undefined2 *)(iVar12 + 0x1a) = uVar9;
          uVar16 = *(undefined2 *)(iVar12 + 0x24);
          *(undefined2 *)(iVar12 + 0x28) = uVar16;
          *(undefined2 *)(iVar12 + 0x2c) = uVar16;
          iVar8 = *(int *)(iVar12 + 0x24);
          *(int *)(iVar12 + 0x20) = iVar8 >> 0xf;
          *(int *)(iVar12 + 0x1e) = iVar8;
          uVar16 = *(undefined2 *)(iVar12 + 0x20);
          uVar9 = FUN_1000_199e();
          uVar15 = (undefined2)((ulong)uStack_24 >> 0x10);
          *(undefined2 *)((int)uStack_24 + 0x20) = uVar16;
          *(undefined2 *)((int)uStack_24 + 0x1e) = uVar9;
          _uStack_12 = 0x10006d95;
          FUN_28eb_3328();
          uVar9 = (undefined2)((ulong)uStack_28 >> 0x10);
          iVar12 = (int)uStack_28;
          uVar16 = *(undefined2 *)(iVar12 + 0x22);
          *(undefined2 *)(iVar12 + 0x26) = uVar16;
          *(undefined2 *)(iVar12 + 0x2a) = uVar16;
          iVar8 = *(int *)(iVar12 + 0x22);
          *(int *)(iVar12 + 0x1c) = iVar8 >> 0xf;
          *(int *)(iVar12 + 0x1a) = iVar8;
          uVar16 = *(undefined2 *)(iVar12 + 0x1c);
          _uStack_12 = 0x28eb6dc0;
          uVar9 = FUN_1000_199e();
          uVar15 = (undefined2)((ulong)uStack_28 >> 0x10);
          iVar12 = (int)uStack_28;
          *(undefined2 *)(iVar12 + 0x1c) = uVar16;
          *(undefined2 *)(iVar12 + 0x1a) = uVar9;
          uVar16 = *(undefined2 *)(iVar12 + 0x24);
          *(undefined2 *)(iVar12 + 0x28) = uVar16;
          *(undefined2 *)(iVar12 + 0x2c) = uVar16;
          iVar8 = *(int *)(iVar12 + 0x24);
          *(int *)(iVar12 + 0x20) = iVar8 >> 0xf;
          *(int *)(iVar12 + 0x1e) = iVar8;
          uVar16 = *(undefined2 *)(iVar12 + 0x20);
          _uStack_12 = 0x10006df3;
          uVar9 = FUN_1000_199e();
          uVar15 = (undefined2)((ulong)uStack_28 >> 0x10);
          *(undefined2 *)((int)uStack_28 + 0x20) = uVar16;
          *(undefined2 *)((int)uStack_28 + 0x1e) = uVar9;
          _uStack_12 = uStack_28;
          puStack_14 = (undefined2 *)0x1000;
          uStack_18 = (undefined2 *)CONCAT22(0x6e07,(undefined2 *)uStack_18);
          FUN_28eb_3328();
          DAT_5b41_0937 = 0x1000;
          puStack_14 = puStack_36;
          uStack_18 = (undefined2 *)0x28eb6e15;
          FUN_28eb_2107();
          for (iVar8 = 0; iVar8 < 2; iVar8 = iVar8 + 1) {
            uVar16 = puStack_36[iVar8 * 2 + 0x10];
            uVar9 = puStack_36[iVar8 * 2 + 0xf];
            puStack_36[iVar8 * 2 + 0x14] = uVar16;
            puStack_36[iVar8 * 2 + 0x13] = uVar9;
            puStack_36[iVar8 * 2 + 0x18] = uVar16;
            puStack_36[iVar8 * 2 + 0x17] = uVar9;
          }
          uVar16 = 0x28eb;
          _uStack_12 = CONCAT22(0x6e52,uStack_12);
          FUN_28eb_2107();
          for (iVar8 = 0; iVar8 < 2; iVar8 = iVar8 + 1) {
            uVar9 = *(undefined2 *)(iVar8 * 4 + iVar6 + 0x20);
            uVar15 = *(undefined2 *)(iVar8 * 4 + iVar6 + 0x1e);
            *(undefined2 *)(iVar8 * 4 + iVar6 + 0x28) = uVar9;
            *(undefined2 *)(iVar8 * 4 + iVar6 + 0x26) = uVar15;
            *(undefined2 *)(iVar8 * 4 + iVar6 + 0x30) = uVar9;
            *(undefined2 *)(iVar8 * 4 + iVar6 + 0x2e) = uVar15;
          }
          uStack_18 = (undefined2 *)0x0;
          uStack_20 = 0;
          _iStack_1c = 0;
          goto LAB_31f7_4f6d;
        }
      }
    }
    return 0;
  case 9:
    bVar5 = (byte)uVar11 & *unaff_DI;
    uVar16 = CONCAT11((char)(uVar11 >> 8),bVar5);
    *(char *)(iVar8 + unaff_SI) = *(char *)(iVar8 + unaff_SI) - bVar5;
    *(undefined2 *)(iVar8 + 0x2a) = uVar16;
    *(undefined2 *)(iVar8 + 0x26) = uVar16;
    *(undefined2 *)(iVar8 + 0x3a) = 0xd000;
    iVar6 = *(int *)((uint)param_1 + 0x24) + 0xd;
    *(int *)((uint)local_6 + 0x2c) = iVar6;
    *(int *)((uint)local_6 + 0x28) = iVar6;
    *(int *)((uint)local_6 + 0x24) = iVar6;
    uStack_12 = 0x3000;
    puStack_14 = (undefined2 *)0x5252;
    FUN_549b_007a();
    iVar6 = *(int *)((uint)local_6 + 0x22);
    *(int *)((uint)local_6 + 0x1c) = iVar6 >> 0xf;
    *(int *)((uint)local_6 + 0x1a) = iVar6;
    uVar16 = *(undefined2 *)((uint)local_6 + 0x1c);
    uStack_12 = 0x549b;
    puStack_14 = (undefined2 *)0x5271;
    uVar7 = FUN_1000_199e();
    *(undefined2 *)((uint)local_6 + 0x1c) = uVar16;
    *(undefined2 *)((uint)local_6 + 0x1a) = uVar7;
    iVar6 = *(int *)((uint)local_6 + 0x24);
    *(int *)((uint)local_6 + 0x20) = iVar6 >> 0xf;
    *(int *)((uint)local_6 + 0x1e) = iVar6;
    uVar16 = *(undefined2 *)((uint)local_6 + 0x20);
    uStack_12 = 0x1000;
    puStack_14 = (undefined2 *)0x5298;
    uVar7 = FUN_1000_199e();
    *(undefined2 *)((uint)local_6 + 0x20) = uVar16;
    *(undefined2 *)((uint)local_6 + 0x1e) = uVar7;
    _uStack_12 = CONCAT22((uint)local_6,local_6._2_2_);
    uStack_18 = (undefined2 *)0x100052ac;
    puStack_14 = (undefined2 *)(uint)local_6;
    uVar14 = FUN_28eb_3328();
    return uVar14;
  case 10:
    abStack_68[(int)unaff_DI] = abStack_68[(int)unaff_DI] | (byte)in_DX;
    (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] - cVar13;
    _uStack_12 = CONCAT22((char *)s_CREDITS_RES_554c_3920 + 10,uStack_12);
    FUN_28eb_3328();
    _uStack_12 = param_1;
    puStack_14 = (undefined2 *)0x28eb;
    uStack_18 = (undefined2 *)
                CONCAT22((char *)s_CREDITS_BMP_554c_392c + 0xb,(undefined2 *)uStack_18);
    FUN_2424_0f94();
    puStack_14 = (undefined2 *)0x2;
    uStack_18 = (undefined2 *)param_1;
    _iStack_1c = 0x24243944;
    uVar14 = FUN_28eb_2d82();
    return uVar14;
  case 0xc:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 0xd:
    unaff_DI[8] = unaff_DI[8] + cVar13;
    _uStack_12 = 0x3000eefe;
    FUN_3e34_0959();
    return *(uint *)(unaff_SI * 8 + 0x76);
  }
  if (SCARRY2(uVar11,uVar11) == iVar8 < 0) {
    if (*(int *)(iVar8 + 0x10) != 2) {
      local_6 = CONCAT22(local_6._2_2_,1);
      goto LAB_31f7_00c8;
    }
  }
  else if ((local_6._2_2_ < 0x25) && (*(int *)(unaff_SI + 0x10) != 0)) {
    local_6 = CONCAT22(local_6._2_2_,0xffff);
    goto LAB_31f7_00c8;
  }
  uVar14 = 1;
LAB_31f7_00c8:
  if (uVar14 == 0) {
    _uStack_12 = CONCAT22(*(undefined2 *)((uint)param_1 + 0x9a),param_1._2_2_);
    puStack_14 = (undefined2 *)(uint)param_1;
    uStack_18 = (undefined2 *)0x30002052;
    iVar6 = FUN_28eb_46b0();
    if (iVar6 == 0) {
      uVar14 = 1;
    }
    else {
      *(undefined2 *)(unaff_SI + 0x16) = (uint)local_6;
      uVar16 = *(undefined2 *)((uint)param_1 + 0x40);
      *(undefined2 *)(unaff_SI + 0x42) = *(undefined2 *)((uint)param_1 + 0x42);
      *(undefined2 *)(unaff_SI + 0x40) = uVar16;
      *(undefined2 *)((uint)param_1 + 0x9c) = 0;
      *(undefined2 *)((uint)param_1 + 0x9a) = 0;
    }
  }
  return uVar14;
LAB_31f7_4b13:
  if ((iVar6 != iStack_2e) || (iStack_1c != iStack_30)) {
    local_6 = CONCAT22(1,(uint)local_6);
  }
  DAT_5b41_0937 = uVar7;
  _iStack_1c = lVar4;
  if ((uStack_20._2_2_ == (undefined2 *)iStack_32) && ((int)uStack_20 == iStack_34)) {
    local_6 = CONCAT22(local_6._2_2_,(uint)*(byte *)((int)puStack_36 + 0x15));
  }
  goto code_r0x00036afc;
}

