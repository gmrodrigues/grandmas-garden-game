// TIM2.EXE: FUN_2424_48ce @ file 0x02DD0E Ghidra 0x28B0E
// Subsystem: misc | Size: 256 bytes


/* WARNING: Instruction at (ram,0x00029a06) overlaps instruction at (ram,0x00029a05)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x0002846f) */
/* WARNING: Removing unreachable block (ram,0x00028473) */
/* WARNING: Removing unreachable block (ram,0x00028483) */

undefined2 * __cdecl16far
FUN_2424_48ce(undefined2 *param_1,undefined2 ******param_2,undefined2 *param_3,
             undefined2 ******param_4,uint param_5,int param_6,uint param_7,int param_8)

{
  char *pcVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  code *pcVar4;
  code *pcVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  char cVar11;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 in_CX;
  int iVar12;
  char cVar13;
  byte bVar14;
  undefined2 ******in_DX;
  uint uVar15;
  uint *puVar16;
  char cVar18;
  int *piVar17;
  undefined2 *puVar19;
  int iVar20;
  int *piVar21;
  int unaff_SI;
  uint unaff_DI;
  uint uVar22;
  undefined2 uVar23;
  undefined2 uVar24;
  int unaff_SS;
  bool bVar25;
  undefined4 uVar26;
  undefined2 *puStack_28;
  undefined2 *****pppppuStack_26;
  undefined2 *puStack_24;
  undefined2 *****pppppuStack_22;
  undefined2 *puStack_20;
  undefined2 *****pppppuStack_1e;
  undefined2 *puStack_16;
  undefined2 *******pppppppuVar27;
  int iVar28;
  undefined2 *local_c;
  undefined2 ******local_a;
  undefined2 *local_8;
  undefined4 uStack_6;
  
  uVar15 = *(uint *)(param_1[4] * 2 + 0x68fe);
  puStack_16 = (undefined2 *)FUN_4551_0370();
  uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
  puVar7 = puStack_16;
  if (param_1[0x57] != 0) {
    iVar12 = param_1[0x57];
    pppppppuVar27 = &local_a;
    FUN_4551_03eb();
    uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
    local_a = (undefined2 ******)((int)local_a + (param_1[0x11] - DAT_5b41_0925));
    puVar7 = (undefined2 *)(param_1[0x12] - DAT_5b41_0927);
    local_8 = (undefined2 *)((int)local_8 + (int)puVar7);
    if (iVar12 - 1U < 9) {
      puVar6 = (undefined2 *)((iVar12 - 1U) * 2);
      switch(iVar12) {
      case 1:
        if ((char)puVar7 != '\0') {
          FUN_2fc8_0364();
          puVar7 = (undefined2 *)0x0;
          if (DAT_554c_5173 < -0x1e) {
            puVar7 = (undefined2 *)0x4;
          }
          else if (0x1d < DAT_554c_5173) {
            puVar7 = (undefined2 *)0x8;
          }
          if (DAT_554c_5175 < -0x1e) {
            puVar7 = (undefined2 *)((uint)puVar7 | 1);
          }
          else if (0x1d < DAT_554c_5175) {
            puVar7 = (undefined2 *)((uint)puVar7 | 2);
          }
        }
        return puVar7;
      case 2:
        cVar13 = (char)((int)puVar7 >> 0xf);
        cVar18 = (char)((uint)puVar6 >> 8) + cVar13;
        *(undefined2 *)(CONCAT11(cVar18,(char)puVar6) + iVar12) = 0x7404;
        puVar7 = puVar7 + 0xdc;
        cVar11 = (&stack0xfffe)[uVar15];
        bVar14 = cVar13 + (&stack0xfffe)[uVar15];
        pbVar2 = (byte *)(CONCAT11(cVar18,(char)puVar6 + (char)((uint)in_CX >> 8)) + uVar15 +
                         -0x15ba);
        *pbVar2 = *pbVar2 >> 3 | *pbVar2 << 5;
        if (bVar14 != 0 && SCARRY1(cVar13,cVar11) == (int)((uint)bVar14 << 8) < 0) {
          *(char *)(iVar12 + 0xb) = *(char *)(iVar12 + 0xb) + bVar14;
          DAT_5b41_0513 = local_8;
          if (DAT_5b41_051d + -0x12 <= (int)local_8) {
            DAT_5b41_0513 = (undefined2 *)(uStack_6._2_2_ + 0x12);
          }
          if ((uVar15 == 0) || (-0x13 < (int)local_a)) {
            unaff_DI = 1;
            DAT_5b41_0515 = (undefined2 *******)local_a;
          }
          else {
            DAT_5b41_0515 = (undefined2 *******)(unaff_SI + -0x12);
            DAT_5b41_0513 = (undefined2 *)(uStack_6._2_2_ + 0x12);
          }
          pppppppuVar27 = DAT_5b41_0515;
          unaff_SS = 0;
          puStack_16 = DAT_5b41_0513;
          puVar7 = (undefined2 *)FUN_4551_01dc();
        }
        if (unaff_SS != 0) {
          *(undefined2 ******)CONCAT22(param_3,param_2) =
               *(undefined2 ******)CONCAT22(param_3,param_2) + -0x12;
          param_2[2] = param_2[2] + 0x12;
        }
        if (unaff_DI != 0) {
          param_2[1] = param_2[1] + -0x12;
          param_2[3] = param_2[3] + 0x12;
        }
        if (pppppppuVar27 != (undefined2 *******)0x0) {
          param_2[2] = param_2[2] + 0x12;
        }
        if (puStack_16 != (undefined2 *)0x0) {
          param_2[3] = param_2[3] + 0x12;
        }
        return puVar7;
      case 3:
        puStack_28 = (undefined2 *)*puVar6;
        pppppuStack_26 = in_DX;
        break;
      case 4:
        FUN_1a9e_5ad4();
        FUN_1a9e_5ad4();
        do {
          uVar15 = 32000;
          if (param_6 == 0) {
            if (param_5 == 0) {
              return (undefined2 *)uStack_6;
            }
            if ((int)param_5 < 0x7d01) {
              uVar15 = param_5;
            }
          }
          (*pcRam00025b2d)();
          (*pcRam00025b2d)();
          local_a = (undefined2 *******)0x5d2;
          (*pcRam00025b2f)();
          bVar25 = param_5 < uVar15;
          param_5 = param_5 - uVar15;
          param_6 = param_6 - (uint)bVar25;
        } while( true );
      case 5:
        param_1[0x4b] = puVar6[0x11];
        param_1[0x1f] = *(undefined2 *)(*(int *)(iVar12 * 2 + 0x302) + 0x38);
        param_1[0x52] = 0xffff;
        param_1[0x53] = 0xffff;
        uVar24 = *(undefined2 *)(*(int *)(iVar12 * 2 + 0x302) + 0x2a);
        param_1[0x25] = in_DX;
        param_1[0x24] = uVar24;
        iVar28 = *(int *)(iVar12 * 2 + 0x302);
        if ((*(int *)(iVar28 + 0x1c) == 0 && *(int *)(iVar28 + 0x1e) == 0) ||
           (puVar3 = (undefined2 *)(*(int *)(iVar12 * 2 + 0x302) + 0x1c),
           iVar28 = (*(code *)*puVar3)(), iVar28 != 0)) {
          puVar3 = (undefined2 *)(*(int *)(iVar12 * 2 + 0x302) + 8);
          (*(code *)*puVar3)();
          uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
          param_1[0x56] = param_1[6];
          FUN_28eb_3328();
          puVar7 = (undefined2 *)0x1;
        }
        else {
          puVar7 = (undefined2 *)0x0;
        }
        return puVar7;
      case 6:
        uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        if ((*(int *)(*(int *)(param_1[4] * 2 + 0x302) + 0x2a) == 0) &&
           (*(int *)(*(int *)(param_1[4] * 2 + 0x302) + 0x2c) == 0)) {
          uVar24 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
          uVar23 = param_1[0x23];
          puVar7 = (undefined2 *)param_1[0x22];
        }
        else {
          iVar12 = *(int *)(param_1[4] * 2 + 0x302);
          uVar23 = *(undefined2 *)(iVar12 + 0x2c);
          puVar7 = (undefined2 *)*(undefined2 *)(iVar12 + 0x2a);
        }
        uVar24 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        param_1[0x2b] = uVar23;
        param_1[0x2a] = puVar7;
        return puVar7;
      case 8:
        if ((puVar6 == (undefined2 *)0x0) || ((char)puVar7 == '\0')) {
          if (DAT_554c_559f == '\x03') {
            puVar7 = (undefined2 *)0x0;
          }
          else {
            puVar7 = (undefined2 *)0x1;
          }
        }
        else {
          puVar7 = (undefined2 *)0x3;
        }
        return puVar7;
      case 9:
        do {
        } while( true );
      }
      uVar22 = uVar15;
      local_c = puStack_16;
      if ((param_1 != (undefined2 *)0x0 || param_2 != (undefined2 ******)0x0) &&
         (((((param_2 == param_4 && (param_1 == param_3)) ||
            ((param_2 == (undefined2 ******)pppppuStack_1e && (param_1 == puStack_20)))) ||
           ((param_2 == (undefined2 ******)pppppuStack_22 && (param_1 == puStack_24)))) ||
          ((param_2 == (undefined2 ******)pppppuStack_26 && (param_1 == puStack_28)))))) {
        uVar22 = uVar15 - 0x23;
        local_c = (undefined2 *)((int)puStack_16 + -0x23);
        unaff_SI = unaff_SI + 0x23;
        unaff_DI = unaff_DI + 0x23;
      }
      if (((((int)local_8 < (int)uVar22) || (unaff_SI <= (int)uStack_6._2_2_)) ||
          ((int)local_a < (int)local_c)) || ((int)unaff_DI <= (int)(undefined2 *)uStack_6)) {
        param_3 = (undefined2 *)0x0;
      }
      else {
        if ((uVar15 != 0) && (DAT_5b41_0939 != 9)) {
          iVar8 = (int)puStack_16 + ((uint)*(byte *)(param_3 + 0x2d) - param_3[0x2e]);
          local_c = (undefined2 *)(((uint)*(byte *)((int)param_3 + 0x5b) + iVar12) - param_3[0x2e]);
          iVar28 = param_3[0x2e] * 2 + iVar8;
          iVar9 = param_3[0x2e] * 2 + (int)local_c;
          if (((undefined2 ******)*(undefined2 *)(uVar15 + 4) == param_2) &&
             ((undefined2 *)*(undefined2 *)(uVar15 + 2) == param_1)) {
            iVar8 = iVar8 + -0x23;
            local_c = (undefined2 *)((int)local_c + -0x23);
            iVar28 = iVar28 + 0x23;
          }
          if (((iVar8 <= (int)local_8) && ((int)uStack_6._2_2_ < iVar28)) &&
             (((int)local_c <= (int)local_a && ((int)(undefined2 *)uStack_6 < iVar9)))) {
            if (((undefined2 ******)*(undefined2 *)(uVar15 + 8) == param_4) &&
               ((undefined2 *)*(undefined2 *)(uVar15 + 6) == param_3)) {
              uVar23 = *(undefined2 *)(uVar15 + 10);
              *(undefined2 *)(uVar15 + 8) = *(undefined2 *)(uVar15 + 0xc);
              *(undefined2 *)(uVar15 + 6) = uVar23;
              *(undefined2 *)(uVar15 + 0xc) = param_4;
              *(undefined2 *)(uVar15 + 10) = param_3;
            }
            return (undefined2 *)*(undefined2 *)(uVar15 + 2);
          }
        }
        puVar7 = (undefined2 *)0x4551;
        for (iVar28 = 0; iVar28 < 2; iVar28 = iVar28 + 1) {
          if (((puVar7 != (undefined2 *)0x0) && (DAT_5b41_0939 != 9)) && (param_3[4] != 7)) {
            cVar11 = *(char *)(param_3 + iVar28 + 0x3d);
            iVar9 = (int)puStack_16 + cVar11 + -8;
            iVar10 = *(char *)((int)param_3 + iVar28 * 2 + 0x7b) + iVar12;
            local_c = (undefined2 *)(iVar10 + -4);
            iVar8 = (int)puStack_16 + cVar11 + 8;
            if (((undefined2 ******)puVar7[1] == param_2) && ((undefined2 *)*puVar7 == param_1)) {
              iVar9 = (int)puStack_16 + cVar11 + -0x2b;
              local_c = (undefined2 *)(iVar10 + -0x27);
              iVar8 = (int)puStack_16 + cVar11 + 0x2b;
            }
            if (((iVar9 <= (int)local_8) && ((int)uStack_6._2_2_ < iVar8)) &&
               (((int)local_c <= (int)local_a && ((int)(undefined2 *)uStack_6 < iVar10 + 4)))) {
              if (((undefined2 ******)puVar7[3] == param_4) && ((undefined2 *)puVar7[2] == param_3))
              {
                FUN_28eb_08be();
              }
              return (undefined2 *)*puVar7;
            }
          }
          puVar7 = (undefined2 *)0x8b4f;
        }
      }
      return param_3;
    }
    puVar7 = (undefined2 *)FUN_2424_1e00();
  }
  uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
  if (param_1[0x5a] != 0) {
    piVar21 = (int *)param_1[0x5a];
    FUN_4551_03eb();
    uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
    local_a = (undefined2 ******)((int)local_a + (param_1[0x11] - DAT_5b41_0925));
    puVar7 = (undefined2 *)(param_1[0x12] - DAT_5b41_0927);
    local_8 = (undefined2 *)((int)local_8 + (int)puVar7);
    piVar17 = piVar21 + -1;
    if (piVar17 < (int *)0xb) {
      puVar16 = (uint *)((int)piVar17 * 2);
      cVar11 = (char)((uint)puVar7 >> 8);
      switch(piVar17) {
      case (int *)0x0:
        do {
          LOCK();
          local_8 = (undefined2 *)*(uint *)((int)puVar16 + -0x3e17);
          *(uint *)((int)puVar16 + -0x3e17) = (uint)puVar7;
          UNLOCK();
          pcVar1 = (char *)((int)puVar16 + (int)(undefined2 *)&DAT_5b41_2839 + uVar15);
          *pcVar1 = *pcVar1 + (char)((uint)local_8 >> 8);
          uVar15 = DAT_5b41_2837;
          DAT_5b41_2839 = (undefined2 *)((int)local_8 + ((int)DAT_5b41_2837 >> 4));
          uStack_6 = (undefined2 *)(CONCAT22(DAT_5b41_2839,DAT_5b41_2837) & 0xffff000f);
          if (DAT_554c_42df == '\0') {
            DAT_5b41_2837 = DAT_5b41_2837 & 0xf;
            uVar26 = FUN_2fc8_00fc();
            FUN_1a9e_74bc();
            puVar7 = (undefined2 *)*piVar21;
            *puVar7 = (int)((ulong)uVar26 >> 0x10);
            puVar7[1] = (int)uVar26;
            FUN_1a9e_7911();
            func_0x0002fdf5();
          }
          else {
            DAT_5b41_2837 = DAT_5b41_2837 & 0xf;
            FUN_1a9e_7911();
          }
          puVar16 = (uint *)*piVar21;
          *puVar16 = uStack_6._2_2_;
          puVar16[1] = (uint)(undefined2 *)uStack_6;
          puVar16[2] = 0xfffe;
          piVar21 = piVar21 + 1;
          puVar7 = DAT_5b41_2839;
        } while (*piVar21 != 0);
        local_8 = (undefined2 *)((int)DAT_5b41_2839 - DAT_5b41_2835);
        iVar12 = DAT_5b41_2837 - DAT_5b41_2833;
        DAT_5b41_282f = (int)local_8 + (iVar12 + 0xf >> 4);
        local_a = (undefined2 ******)*(undefined2 *)*param_1;
        pcVar5 = (code *)swi(0x21);
        (*pcVar5)();
        FUN_1000_130c();
        return (undefined2 *)((int)local_8 * 0x10 + iVar12);
      case (int *)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (int *)0x2:
        *(char *)(int *)((int)puVar16 + (int)piVar21) =
             (char)*(int *)((int)puVar16 + (int)piVar21) + '\x01';
        if (puVar7 != (undefined2 *)0xf6) {
          puVar16 = puVar16 + -1;
        }
        if ((*puVar16 & 1) == 0) {
          puVar7 = (undefined2 *)((int)unaff_DI >> 1);
        }
        else {
          puVar7 = (undefined2 *)(unaff_DI >> 1 | (uint)(((uint)in_DX & 1) != 0) << 0xf);
        }
        return puVar7;
      case (int *)0x3:
        goto switchD_2000_8bda_caseD_3;
      case (int *)0x4:
        do {
          FUN_3e34_0ec9();
          piVar21 = (int *)((int)piVar21 + ((undefined2 *)uStack_6)[3]);
        } while ((int)piVar21 < unaff_SI);
        puVar7 = (undefined2 *)FUN_2424_02ca();
        return puVar7;
      case (int *)0x5:
        (&stack0x0e44)[uVar15] =
             (&stack0x0e44)[uVar15] + (char)in_CX + CARRY2((uint)piVar17,(uint)piVar17);
        local_a = (undefined2 ******)(param_7 + (int)param_3 + (int)puVar7 * -2);
        local_8 = (undefined2 *)
                  ((int)param_4 +
                  ((((uint)CARRY2(param_7,(uint)param_3) + param_8) -
                   ((int)in_DX << 1 | (uint)CARRY2((uint)puVar7,(uint)puVar7))) -
                  (uint)(param_7 + (int)param_3 < (uint)((int)puVar7 * 2))));
        FUN_1000_199e();
        FUN_1000_199e();
        FUN_1000_199e();
        FUN_1000_199e();
        puVar7 = (undefined2 *)(1 << ((byte)param_2 & 0x1f));
        iVar12 = (int)puVar7 >> 0xf;
        uStack_6._2_2_ = FUN_1000_19bf();
        uStack_6._0_2_ = (undefined2 *)FUN_1000_19bf();
        puStack_20 = (undefined2 *)0x0;
        for (pppppuStack_22 = (undefined2 *****)0x0;
            ((int)puStack_20 < iVar12 || (((int)puStack_20 <= iVar12 && (pppppuStack_22 <= puVar7)))
            ); pppppuStack_22 = (undefined2 *****)((int)pppppuStack_22 + 1)) {
          iVar28 = FUN_1000_19bf();
          iVar8 = FUN_1000_19bf();
          if ((uStack_6._2_2_ != iVar28) || ((undefined2 *)uStack_6 != (undefined2 *)iVar8)) {
            FUN_2424_27e0();
            uStack_6._0_2_ = (undefined2 *)iVar8;
            uStack_6._2_2_ = iVar28;
          }
          FUN_1000_180a();
          FUN_1000_180a();
          puStack_20 = (undefined2 *)
                       ((int)puStack_20 + (uint)((undefined2 *)0xfffe < pppppuStack_22));
        }
        return pppppuStack_22;
      default:
        puVar6 = (undefined2 *)CONCAT11(cVar11,*(char *)&DAT_554c_5596);
        if (*(char *)&DAT_554c_5596 == '\0') {
          *(undefined1 *)&DAT_554c_5595 = (char)puVar16;
          *(undefined2 *)&DAT_554c_5178 = in_CX;
          *(undefined2 *)&DAT_554c_517a = in_DX;
          puVar6 = (undefined2 *)CONCAT11(cVar11,*(char *)&DAT_554c_5596);
          if ((*(char *)&DAT_554c_5596 == '\0') &&
             (puVar6 = (undefined2 *)0x0, *(int *)&DAT_554c_517c != 0 || *(int *)&DAT_554c_517e != 0
             )) {
            *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + '\x01';
            *(undefined2 *)&DAT_554c_557e = 0x2000;
            *(undefined2 *)&DAT_554c_557c = 0x2fe;
            FUN_1a9e_5938();
            uVar23 = ((undefined2 *)&DAT_554c_517c)[1];
            pcVar4 = (code *)*(undefined2 *)&DAT_554c_517c;
            *(undefined2 *)&DAT_554c_557e = 0x2000;
            puVar19 = (undefined2 *)&DAT_554c_557c;
            *(undefined2 *)&DAT_554c_557c = 0x303;
            (*pcVar4)();
            *(undefined2 *)((int)puVar19 + -2) = 0x2000;
            *(undefined2 *)((int)puVar19 + -4) = 0x307;
            puVar6 = (undefined2 *)FUN_1a9e_599d();
            *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + -1;
          }
        }
        return puVar6;
      case (int *)0x7:
        return puVar7;
      case (int *)0x8:
        iVar20 = *(int *)(&stack0x6bf6 + uVar15) * -0x15;
        if ((param_2 == DAT_5b41_0ca2) && (param_1 == DAT_5b41_0ca0)) {
          DAT_5b41_0cb9 = 0;
        }
        else if ((param_2 == DAT_5b41_0c9e) && (param_1 == DAT_5b41_0c9c)) {
          DAT_5b41_0cbb = 0;
        }
        else {
          *(undefined2 *)(iVar20 + -2) = param_2;
          *(undefined2 *)(iVar20 + -4) = param_1;
          *(undefined2 *)(iVar20 + -6) = 0x2000;
          *(undefined2 *)(iVar20 + -8) = 0xf845;
          param_1 = (undefined2 *)FUN_22de_0351();
        }
        return param_1;
      case (int *)0x9:
        *(char *)(int *)((int)puVar16 + (int)piVar21) =
             (char)*(int *)((int)puVar16 + (int)piVar21) + cVar11;
        FUN_2424_4ae2();
        puVar7 = param_1;
        iVar12 = (int)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        while( true ) {
          iVar28 = puVar7[0x47];
          puVar7 = (undefined2 *)puVar7[0x46];
          uStack_6 = (undefined2 *)CONCAT22(iVar28,puVar7);
          if ((puVar7 == (undefined2 *)0x0 && iVar28 == 0) || (local_8 != (undefined2 *)0x0)) break;
          iVar12 = iVar28;
          if (((puVar7[4] == 0x76) && (puVar7[0x25] == 0x20)) &&
             (local_8 = (undefined2 *)iVar28, puVar7[0x12] == param_1[0x12] + -0x20)) {
            bVar25 = (*(byte *)(puVar7 + 6) & 0x30) != 0;
            if (((puStack_16 != (undefined2 *)0x0) || (bVar25)) || (puVar7[0x11] != param_1[0x11]))
            {
              if (((puStack_16 != (undefined2 *)0x0) && (!bVar25)) &&
                 (uVar23 = (undefined2)
                           (CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10),
                 puVar7[0x11] + puVar7[0x24] == param_1[0x11] + param_1[0x24])) {
                local_8 = (undefined2 *)0x9;
              }
            }
            else {
              local_8 = (undefined2 *)0x7;
            }
          }
        }
        uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        local_8 = (undefined2 *)(param_1[0x25] + 0x10);
        local_a = (undefined2 ******)param_1[0x25];
        FUN_2424_4ae2();
        puVar7 = param_1;
        iVar12 = (int)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        while( true ) {
          iVar28 = puVar7[0x47];
          puVar7 = (undefined2 *)puVar7[0x46];
          uStack_6 = (undefined2 *)CONCAT22(iVar28,puVar7);
          if ((puVar7 == (undefined2 *)0x0 && iVar28 == 0) || (local_a != (undefined2 ******)0x0))
          break;
          iVar12 = iVar28;
          if ((((puVar7[4] == 0x76) && (puVar7[0x25] == 0x20)) &&
              (uVar23 = (undefined2)
                        (CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10),
              param_1[0x12] + param_1[0x25] == puVar7[0x12])) &&
             (((*(byte *)(puVar7 + 6) & 0x30) != 0 &&
              (uVar23 = (undefined2)
                        (CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10),
              puVar7[0x11] + puVar7[0x24] == param_1[0x11] + param_1[0x24])))) {
            local_a = (undefined2 ******)0xc;
          }
        }
        uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        if (((undefined2 *)param_1[0x57] != local_8) ||
           ((undefined2 ******)param_1[0x5a] != local_a)) {
          local_8 = (undefined2 *)0x1;
          local_a = param_2;
          FUN_2424_3746();
          FUN_2424_3746();
          uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
          param_1[0x57] = local_8;
          param_1[0x5a] = local_a;
          FUN_2424_3746();
          FUN_2424_3746();
        }
        uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
        param_1[0x57] = local_8;
        param_1[0x5a] = local_a;
        if ((local_8 == (undefined2 *)0x0) && (local_a == (undefined2 ******)0x0)) {
          puVar7 = (undefined2 *)0x0;
        }
        else {
          puVar7 = (undefined2 *)0x1;
        }
        return puVar7;
      }
    }
    puVar7 = (undefined2 *)FUN_2424_1e00();
  }
  return puVar7;
LAB_2424_38a7:
  while( true ) {
    while( true ) {
      do {
        uVar23 = (undefined2)((ulong)uStack_6 >> 0x10);
        iVar28 = ((undefined2 *)uStack_6)[0x47];
        puVar7 = (undefined2 *)((undefined2 *)uStack_6)[0x46];
        uStack_6 = (undefined2 *)CONCAT22(iVar28,puVar7);
        if ((puVar7 == (undefined2 *)0x0 && iVar28 == 0) || (iVar12 != 0)) {
          uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
          if (((int *)param_1[0x57] != piVar21) || (param_1[0x5a] != iVar12)) {
            FUN_2424_3746();
            FUN_2424_3746();
            uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
            param_1[0x57] = piVar21;
            param_1[0x5a] = iVar12;
            FUN_2424_3746();
            FUN_2424_3746();
          }
          uVar23 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
          param_1[0x57] = piVar21;
          param_1[0x5a] = iVar12;
          if ((piVar21 == (int *)0x0) && (iVar12 == 0)) {
            puVar7 = (undefined2 *)0x0;
          }
          else {
            puVar7 = (undefined2 *)0x1;
          }
          return puVar7;
        }
      } while ((puVar7[0x25] != 0x10) || (iVar28 = FUN_2424_4087(), iVar28 == 0));
      uVar23 = (undefined2)((ulong)uStack_6 >> 0x10);
      puVar7 = (undefined2 *)uStack_6;
      if (puVar7[0x11] != param_1[0x11]) break;
      iVar12 = 10;
    }
    uVar24 = (undefined2)(CONCAT13(param_2._1_1_,CONCAT12((byte)param_2,param_1)) >> 0x10);
    if (puVar7[0x11] + puVar7[0x24] == param_1[0x11] + param_1[0x24]) break;
switchD_2000_8bda_caseD_3:
    iVar12 = 0xb;
  }
  iVar12 = 0xc;
  goto LAB_2424_38a7;
}

