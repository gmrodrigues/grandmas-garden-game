// TIM2.EXE: FUN_2e67_02b5 @ file 0x033B25 Ghidra 0x2E925
// Subsystem: misc | Size: 68 bytes


/* WARNING: Instruction at (ram,0x00028bd6) overlaps instruction at (ram,0x00028bd5)
    */

int * FUN_2e67_02b5(undefined2 param_1,int ******param_2,int ******param_3,int ******param_4,
                   int ******param_5,uint param_6,int param_7)

{
  byte *pbVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *****pppppiVar10;
  int *****pppppiVar11;
  int *piVar12;
  uint uVar13;
  undefined2 in_CX;
  char cVar15;
  byte bVar16;
  int ******ppppppiVar14;
  char cVar18;
  int ******ppppppiVar17;
  undefined2 *puVar19;
  int unaff_SI;
  int ******unaff_DI;
  undefined2 unaff_ES;
  int ******ppppppiVar20;
  undefined2 unaff_SS;
  bool bVar21;
  char acStack_3bc [916];
  int *****pppppiStack_28;
  int *****pppppiStack_26;
  int *****pppppiStack_24;
  int *****pppppiStack_22;
  int *****pppppiStack_20;
  int *****pppppiStack_1e;
  int *****pppppiStack_1c;
  int *****pppppiStack_1a;
  int in_stack_0000ffe8;
  int in_stack_0000ffea;
  int iStack_14;
  int iStack_12;
  int *****pppppiStack_10;
  int *****pppppiStack_e;
  int ******in_stack_0000fff4;
  int ******ppppppiStack_a;
  int in_stack_0000fff8;
  
  if (DAT_5b41_0bec == 0) {
    return (int *)0xffff;
  }
  if ((DAT_5b41_0503 != 0) && (param_2 < (int ******)0x3e8)) {
    piVar12 = (int *)FUN_2e67_03ef();
    return piVar12;
  }
  DAT_5b41_0c98 = param_2;
  uVar13 = (uint)param_2 / 1000;
  ppppppiVar14 = (int ******)((uint)param_2 % 1000);
  if (4 < uVar13) {
    piVar12 = (int *)FUN_2e67_03ef();
    return piVar12;
  }
  ppppppiVar17 = (int ******)(uVar13 * 2);
  ppppppiVar20 = (int ******)0x2000;
  switch(uVar13) {
  case 0:
    acStack_3bc[(int)unaff_DI] = acStack_3bc[(int)unaff_DI] + -1;
    ppppppiStack_a = (int ******)0xcb0c;
    pppppiVar11 = (int *****)FUN_1000_19bf();
    param_2[0x1d] = pppppiVar11;
    ppppppiStack_a = (int ******)0xcb20;
    pppppiVar11 = (int *****)FUN_1000_19bf();
    param_2[0x1e] = pppppiVar11;
    return (int *)pppppiVar11;
  case 1:
    ppppppiStack_a = (int ******)((int)ppppppiStack_a + ((int)ppppppiVar17[0x11] - DAT_5b41_0925));
    piVar12 = (int *)((int)ppppppiVar17[0x12] - DAT_5b41_0927);
    if ((int)param_2 - 1U < 9) {
      puVar19 = (undefined2 *)(((int)param_2 - 1U) * 2);
      switch(param_2) {
      case (int ******)0x1:
        if ((char)piVar12 != '\0') {
          ppppppiStack_a = param_2;
          pppppiStack_e = (int *****)0x84;
          FUN_2fc8_0364();
          piVar12 = (int *)0x0;
          if (DAT_554c_5173 < -0x1e) {
            piVar12 = (int *)0x4;
          }
          else if (0x1d < DAT_554c_5173) {
            piVar12 = (int *)0x8;
          }
          if (DAT_554c_5175 < -0x1e) {
            piVar12 = (int *)((uint)piVar12 | 1);
          }
          else if (0x1d < DAT_554c_5175) {
            piVar12 = (int *)((uint)piVar12 | 2);
          }
        }
        return piVar12;
      case (int ******)0x2:
        cVar15 = (char)((int)piVar12 >> 0xf);
        cVar18 = (char)((uint)puVar19 >> 8) + cVar15;
        *(undefined2 *)(CONCAT11(cVar18,(char)puVar19) + (int)param_2) = 0x7404;
        piVar6 = piVar12 + 0xdc;
        cVar2 = (&stack0xfffe)[(int)unaff_DI];
        bVar16 = cVar15 + (&stack0xfffe)[(int)unaff_DI];
        pbVar1 = (byte *)((int)unaff_DI +
                         CONCAT11(cVar18,(char)puVar19 + (char)((uint)in_CX >> 8)) + -0x15ba);
        *pbVar1 = *pbVar1 >> 3 | *pbVar1 << 5;
        if (bVar16 != 0 && SCARRY1(cVar15,cVar2) == (int)((uint)bVar16 << 8) < 0) {
          *(char *)((int)param_2 + 0xb) = *(char *)((int)param_2 + 0xb) + bVar16;
          if (in_stack_0000fff8 + (int)piVar12 < DAT_5b41_051d + -0x12) {
            iStack_14 = 1;
            DAT_5b41_0513 = (int ******)(in_stack_0000fff8 + (int)piVar12);
          }
          else {
            DAT_5b41_0513 = (int ******)(unaff_SI + 0x12);
          }
          DAT_5b41_0515 = ppppppiStack_a;
          if ((in_stack_0000ffe8 != 0) && ((int)ppppppiStack_a < -0x12)) {
            DAT_5b41_0513 = (int ******)(unaff_SI + 0x12);
            in_stack_0000ffea = 1;
            DAT_5b41_0515 = (int ******)((int)pppppiStack_e + -0x12);
          }
          pppppiStack_1a = (int *****)DAT_5b41_04dc;
          if (in_stack_0000ffe8 != 0) {
            pppppiStack_1a = (int *****)DAT_5b41_04de;
          }
          ppppppiStack_a = DAT_5b41_0513;
          pppppiStack_e = (int *****)DAT_5b41_050d;
          pppppiStack_10 = (int *****)0x2000;
          iStack_12 = 0x7797;
          piVar6 = (int *)FUN_4551_01dc();
        }
        if (iStack_12 != 0) {
          *(int ******)CONCAT22(param_4,param_3) = *(int ******)CONCAT22(param_4,param_3) + -0x12;
          param_3[2] = param_3[2] + 0x12;
        }
        if ((int ******)pppppiStack_10 != (int ******)0x0) {
          param_3[1] = param_3[1] + -0x12;
          param_3[3] = param_3[3] + 0x12;
        }
        if (iStack_14 != 0) {
          param_3[2] = param_3[2] + 0x12;
        }
        if (in_stack_0000ffea != 0) {
          param_3[3] = param_3[3] + 0x12;
        }
        return piVar6;
      case (int ******)0x3:
        pppppiStack_28 = (int *****)*puVar19;
        pppppiStack_26 = (int *****)ppppppiVar14;
        break;
      case (int ******)0x4:
        FUN_1a9e_5ad4();
        FUN_1a9e_5ad4();
        do {
          uVar13 = 32000;
          if (param_7 == 0) {
            if (param_6 == 0) {
              return (int *)0x57f;
            }
            if ((int)param_6 < 0x7d01) {
              uVar13 = param_6;
            }
          }
          (*pcRam00025b2d)();
          (*pcRam00025b2d)();
          (*pcRam00025b2f)();
          bVar21 = param_6 < uVar13;
          param_6 = param_6 - uVar13;
          param_7 = param_7 - (uint)bVar21;
        } while( true );
      case (int ******)0x5:
        param_2[0x4b] = (int *****)puVar19[0x11];
        param_2[0x1f] = (int *****)*(int *)(*(int *)((int)param_2 * 2 + 0x302) + 0x38);
        param_2[0x52] = (int *****)0xffff;
        param_2[0x53] = (int *****)0xffff;
        pppppiVar11 = (int *****)*(int *)(*(int *)((int)param_2 * 2 + 0x302) + 0x2a);
        param_2[0x25] = (int *****)ppppppiVar14;
        param_2[0x24] = pppppiVar11;
        iVar5 = *(int *)((int)param_2 * 2 + 0x302);
        if (*(int *)(iVar5 + 0x1c) != 0 || *(int *)(iVar5 + 0x1e) != 0) {
          puVar4 = (undefined2 *)(*(int *)((int)param_2 * 2 + 0x302) + 0x1c);
          ppppppiStack_a = (int ******)0x2000;
          iVar5 = (*(code *)*puVar4)();
          if (iVar5 == 0) {
            return (int *)0x0;
          }
        }
        puVar4 = (undefined2 *)(*(int *)((int)param_2 * 2 + 0x302) + 8);
        ppppppiStack_a = (int ******)0x2000;
        (*(code *)*puVar4)();
        param_2[0x56] = param_2[6];
        ppppppiStack_a = param_3;
        pppppiStack_e = (int *****)0x2000;
        pppppiStack_10 = (int *****)0x40fe;
        FUN_28eb_3328();
        return (int *)0x1;
      case (int ******)0x6:
        if ((*(int *)(*(int *)((int)param_2[4] * 2 + 0x302) + 0x2a) == 0) &&
           (*(int *)(*(int *)((int)param_2[4] * 2 + 0x302) + 0x2c) == 0)) {
          pppppiVar11 = param_2[0x23];
          pppppiVar10 = param_2[0x22];
        }
        else {
          iVar5 = *(int *)((int)param_2[4] * 2 + 0x302);
          pppppiVar11 = (int *****)*(int *)(iVar5 + 0x2c);
          pppppiVar10 = (int *****)*(int *)(iVar5 + 0x2a);
        }
        param_2[0x2b] = pppppiVar11;
        param_2[0x2a] = pppppiVar10;
        return (int *)pppppiVar10;
      case (int ******)0x8:
        if ((puVar19 == (undefined2 *)0x0) || ((char)piVar12 == '\0')) {
          if (DAT_554c_559f == '\x03') {
            piVar12 = (int *)0x0;
          }
          else {
            piVar12 = (int *)0x1;
          }
        }
        else {
          piVar12 = (int *)0x3;
        }
        return piVar12;
      case (int ******)0x9:
        do {
        } while( true );
      }
      ppppppiVar14 = unaff_DI;
      if ((param_2 != (int ******)0x0 || param_3 != (int ******)0x0) &&
         ((((param_3 == param_5 && (param_2 == param_4)) ||
           ((param_3 == (int ******)pppppiStack_1e && (param_2 == (int ******)pppppiStack_20)))) ||
          (((param_3 == (int ******)pppppiStack_22 && (param_2 == (int ******)pppppiStack_24)) ||
           ((param_3 == (int ******)pppppiStack_26 && (param_2 == (int ******)pppppiStack_28))))))))
      {
        ppppppiVar14 = (int ******)((int)unaff_DI + -0x23);
        in_stack_0000fff4 = (int ******)((int)in_stack_0000fff4 + -0x23);
        pppppiStack_e = (int *****)((int)pppppiStack_e + 0x23);
        pppppiStack_10 = (int *****)((int)pppppiStack_10 + 0x23);
      }
      if (((((int)param_2 < (int)ppppppiVar14) || ((int)pppppiStack_e <= unaff_SI)) ||
          ((int)ppppppiStack_a < (int)in_stack_0000fff4)) || ((int)pppppiStack_10 <= (int)unaff_DI))
      {
        param_4 = (int ******)0x0;
      }
      else {
        if ((in_stack_0000ffe8 != 0) && (DAT_5b41_0939 != 9)) {
          iVar7 = ((uint)*(byte *)(param_4 + 0x2d) + in_stack_0000ffea) - (int)param_4[0x2e];
          iVar5 = ((uint)*(byte *)((int)param_4 + 0x5b) + iStack_14) - (int)param_4[0x2e];
          pppppiStack_e = (int *****)((int)param_4[0x2e] * 2 + iVar7);
          iVar8 = (int)param_4[0x2e] * 2 + iVar5;
          if (((int ******)*(undefined2 *)(in_stack_0000ffe8 + 4) == param_3) &&
             ((int ******)*(undefined2 *)(in_stack_0000ffe8 + 2) == param_2)) {
            iVar7 = iVar7 + -0x23;
            iVar5 = iVar5 + -0x23;
            pppppiStack_e = (int *****)((int)pppppiStack_e + 0x23);
          }
          if (((iVar7 <= (int)param_2) && (unaff_SI < (int)pppppiStack_e)) &&
             ((iVar5 <= (int)ppppppiStack_a && ((int)unaff_DI < iVar8)))) {
            if (((int ******)*(undefined2 *)(in_stack_0000ffe8 + 8) == param_5) &&
               ((int ******)*(undefined2 *)(in_stack_0000ffe8 + 6) == param_4)) {
              uVar3 = *(undefined2 *)(in_stack_0000ffe8 + 10);
              *(undefined2 *)(in_stack_0000ffe8 + 8) = *(undefined2 *)(in_stack_0000ffe8 + 0xc);
              *(undefined2 *)(in_stack_0000ffe8 + 6) = uVar3;
              *(undefined2 *)(in_stack_0000ffe8 + 0xc) = param_5;
              *(undefined2 *)(in_stack_0000ffe8 + 10) = param_4;
            }
            return (int *)*(undefined2 *)(in_stack_0000ffe8 + 2);
          }
        }
        pppppiVar11 = pppppiStack_1a;
        for (iStack_12 = 0; iStack_12 < 2; iStack_12 = iStack_12 + 1) {
          if (((pppppiVar11 != (int *****)0x0) && (DAT_5b41_0939 != 9)) &&
             (param_4[4] != (int *****)0x7)) {
            iVar7 = *(char *)(param_4 + iStack_12 + 0x3d) + in_stack_0000ffea;
            iVar8 = iVar7 + -8;
            iVar9 = *(char *)((int)param_4 + iStack_12 * 2 + 0x7b) + iStack_14;
            iVar5 = iVar9 + -4;
            pppppiStack_e = (int *****)(iVar7 + 8);
            pppppiStack_10 = (int *****)(iVar9 + 4);
            if (((int ******)pppppiVar11[1] == param_3) && ((int ******)*pppppiVar11 == param_2)) {
              iVar8 = iVar7 + -0x2b;
              iVar5 = iVar9 + -0x27;
              pppppiStack_e = (int *****)(iVar7 + 0x2b);
            }
            if (((iVar8 <= (int)param_2) && (unaff_SI < (int)pppppiStack_e)) &&
               ((iVar5 <= (int)ppppppiStack_a && ((int)unaff_DI < (int)pppppiStack_10)))) {
              if (((int ******)pppppiVar11[3] == param_5) && ((int ******)pppppiVar11[2] == param_4)
                 ) {
                pppppiStack_e = (int *****)0x9bfe;
                FUN_28eb_08be();
              }
              return (int *)*pppppiVar11;
            }
          }
          pppppiVar11 = pppppiStack_1c;
        }
      }
      DAT_5b41_0c98 = param_2;
      return (int *)param_4;
    }
    ppppppiStack_a = (int ******)&ppppppiStack_a;
    pppppiStack_e = (int *****)0x8b91;
    piVar12 = (int *)FUN_2424_1e00();
    if (param_2[0x5a] == (int *****)0x0) {
      return piVar12;
    }
    ppppppiVar17 = (int ******)param_2[0x5a];
    ppppppiStack_a = (int ******)0x2000;
    pppppiStack_e = (int *****)0x2000;
    pppppiStack_10 = (int *****)0x8bb2;
    FUN_4551_03eb();
    ppppppiStack_a = (int ******)((int)ppppppiStack_a + ((int)param_2[0x11] - DAT_5b41_0925));
    break;
  case 2:
    do {
      ppppppiVar14 = ppppppiVar20;
      ppppppiStack_a = in_stack_0000fff4;
      do {
        pppppiStack_e = pppppiStack_10;
        pppppiStack_10 = (int *****)ppppppiVar14;
        (*DAT_554c_4db2)();
        ppppppiVar20 = (int ******)0x1000;
        FUN_1000_1a00();
        ppppppiStack_a = (int ******)pppppiStack_10;
        pppppiStack_e = (int *****)0x1000;
        pppppiStack_10 = (int *****)0x2c2c;
        iVar5 = FUN_28eb_2aad();
        in_stack_0000fff4 = (int ******)pppppiStack_e;
        if (iVar5 < 1) {
          ppppppiStack_a = (int ******)0x2c3c;
          FUN_28eb_29db();
          bVar21 = true;
          FUN_1000_1821();
          if (!bVar21) {
            ppppppiStack_a = (int ******)0x1000;
            func_0x0002fdf5();
          }
          ppppppiStack_a = (int ******)0x2c6c;
          FUN_1000_130c();
          uRam00055624 = 0;
          uRam00055622 = 0;
          if (pppppiStack_1c == (int *****)0x0) {
            bVar21 = true;
            FUN_1000_1821();
            if (!bVar21) {
              ppppppiStack_a = (int ******)0x1000;
              func_0x0002fdf5();
            }
            if (unaff_DI != (int ******)0x0) {
              ppppppiStack_a = (int ******)0x2caa;
              FUN_28eb_29db();
            }
            ppppppiStack_a = (int ******)0x2cb5;
            FUN_1a9e_82f5();
            ppppppiVar14 = (int ******)0x0;
          }
          if (pppppiStack_1a != (int *****)0x0) {
            ppppppiStack_a = (int ******)0x2cc9;
            FUN_1a9e_6e73();
          }
          return (int *)ppppppiVar14;
        }
        ppppppiVar14 = ppppppiVar20;
        ppppppiStack_a = unaff_DI;
      } while (pppppiStack_1c != (int *****)0x6);
      ppppppiStack_a = (int ******)pppppiStack_10;
      pppppiStack_e = pppppiStack_10;
      pppppiStack_10 = (int *****)0x1000;
      FUN_1a9e_836a();
    } while( true );
  case 3:
    ppppppiVar17 = param_2;
    if (!CARRY2(uVar13,uVar13) && uVar13 != 0) {
      in(ppppppiVar14);
      pppppiStack_1a = (int *****)&pppppiStack_10;
      pppppiStack_1c = (int *****)param_3;
      pppppiStack_1e = (int *****)param_2;
      pppppiStack_20 = (int *****)0x2000;
      pppppiStack_22 = (int *****)0x8c49;
      FUN_4551_03eb();
      pppppiStack_10 = (int *****)((int)pppppiStack_10 + (int)param_4);
      pppppiStack_e = (int *****)((int)pppppiStack_e + (int)param_5);
      puVar19 = DAT_5b41_04b0;
      while( true ) {
        if (puVar19 == (undefined2 *)0x0) {
          pppppiStack_1a = (int *****)0x8d1e;
          piVar12 = (int *)FUN_2424_02ca();
          return piVar12;
        }
        iVar5 = puVar19[1];
        iVar7 = puVar19[2];
        iVar8 = puVar19[3];
        iVar9 = puVar19[4];
        if ((((iVar5 <= (int)pppppiStack_10) &&
             ((int)pppppiStack_10 + (int)in_stack_0000fff4 <= iVar8)) &&
            (iVar7 <= (int)pppppiStack_e)) && ((int)pppppiStack_e + (int)ppppppiStack_a <= iVar9))
        break;
        if (((((int)pppppiStack_10 <= iVar8) &&
             (iVar5 <= (int)pppppiStack_10 + (int)in_stack_0000fff4)) &&
            (((int)pppppiStack_e <= iVar9 &&
             ((iVar7 <= (int)pppppiStack_e + (int)ppppppiStack_a && (iVar5 < iVar8)))))) &&
           (iVar7 <= iVar9)) {
          DAT_554c_42c3 = 1;
          pppppiStack_1a = (int *****)param_5;
          pppppiStack_1c = (int *****)param_4;
          pppppiStack_1e = (int *****)param_3;
          pppppiStack_20 = (int *****)param_2;
          pppppiStack_22 = (int *****)0x4551;
          pppppiStack_24 = (int *****)0x8d0d;
          DAT_554c_42c4 = iVar5;
          DAT_554c_42c6 = iVar8;
          DAT_554c_42c8 = iVar7;
          DAT_554c_42ca = iVar9;
          FUN_4551_01dc();
        }
        puVar19 = (undefined2 *)*puVar19;
      }
      pppppiStack_1a = (int *****)0x8c99;
      FUN_2424_02ca();
      pppppiStack_1a = (int *****)param_5;
      pppppiStack_1c = (int *****)param_4;
      pppppiStack_1e = (int *****)param_3;
      pppppiStack_20 = (int *****)param_2;
      pppppiStack_22 = (int *****)0x4551;
      pppppiStack_24 = (int *****)0x8cad;
      piVar12 = (int *)FUN_4551_01dc();
      return piVar12;
    }
    break;
  case 4:
    goto code_r0x00028bd8;
  }
  ppppppiVar17 = ppppppiVar17 + -1;
  if ((int ******)0xa < ppppppiVar17) {
    ppppppiStack_a = (int ******)&ppppppiStack_a;
    pppppiStack_e = (int *****)0x8c02;
    piVar12 = (int *)FUN_2424_1e00();
    return piVar12;
  }
code_r0x00028bd8:
                    /* WARNING: Could not recover jumptable at 0x00028bda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  piVar12 = (int *)(*(code *)*(undefined2 *)((int)ppppppiVar17 * 2 + 0x49c9))();
  return piVar12;
}

