// TIM2.EXE: FUN_2424_27e0 @ file 0x02BC20 Ghidra 0x26A20
// Subsystem: misc | Size: 218 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00020a62) overlaps instruction at (ram,0x00020a60)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x0002846f) */
/* WARNING: Removing unreachable block (ram,0x00028473) */
/* WARNING: Removing unreachable block (ram,0x00028483) */

uint __cdecl16far FUN_2424_27e0(int *****param_1,uint param_2,int param_3,int param_4)

{
  char *pcVar1;
  byte *pbVar2;
  int *piVar3;
  undefined2 *puVar4;
  code *pcVar5;
  code *pcVar6;
  int *piVar7;
  byte bVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  int ***pppiVar11;
  uint uVar12;
  char cVar15;
  int iVar13;
  int iVar14;
  undefined2 in_CX;
  int iVar16;
  int in_DX;
  uint uVar17;
  char cVar18;
  byte bVar19;
  int ****ppppiVar20;
  char cVar23;
  int *****pppppiVar21;
  int iVar22;
  undefined2 *puVar24;
  int iVar25;
  uint unaff_BP;
  undefined1 *puVar26;
  int *****pppppiVar27;
  uint *puVar28;
  undefined2 uVar29;
  undefined2 uVar30;
  int unaff_SS;
  bool bVar31;
  int ***pppiVar32;
  uint in_stack_00000000;
  int in_stack_00000002;
  int iStack_34;
  int iStack_32;
  int iStack_30;
  uint uStack_2e;
  int iStack_2c;
  int iStack_2a;
  uint uStack_22;
  int ******ppppppiVar33;
  int iVar34;
  uint uStack_1c;
  int ****ppppiStack_1a;
  uint uStack_18;
  int *****pppppiStack_16;
  uint uStack_14;
  int **ppiStack_12;
  undefined1 local_8;
  undefined1 uStack_7;
  byte local_6;
  undefined1 uStack_5;
  
  uVar9 = DAT_5b41_0757;
  bVar8 = DAT_554c_42ce;
  puVar26 = &stack0xfff2;
  uVar12 = DAT_554c_42ce - 0x84;
  if (4 < uVar12) {
    uVar12 = (int)param_1 - param_3 >> 0xf;
    uVar17 = (int)(param_2 - param_4) >> 0xf;
    if ((int)(((int)param_1 - param_3 ^ uVar12) - uVar12) <
        (int)((param_2 - param_4 ^ uVar17) - uVar17)) {
      DAT_554c_42ce = DAT_5b41_0757;
      _ppiStack_12 = (int ***)CONCAT22(param_4,param_3 + -1);
      uStack_14 = param_2;
      pppppiStack_16 = (int *****)((int)param_1 + -1);
      FUN_1a9e_5722();
      _ppiStack_12 = (int ***)CONCAT22(param_4,param_3 + 1);
      uStack_14 = param_2;
      pppppiStack_16 = (int *****)((int)param_1 + 1);
    }
    else {
      DAT_554c_42ce = DAT_5b41_0757;
      _ppiStack_12 = (int ***)CONCAT22(param_4 + -1,param_3);
      uStack_14 = param_2 - 1;
      pppppiStack_16 = param_1;
      FUN_1a9e_5722();
      _ppiStack_12 = (int ***)CONCAT22(param_4 + 1,param_3);
      uStack_14 = param_2 + 1;
      pppppiStack_16 = param_1;
    }
    DAT_554c_42ce = uVar9;
    FUN_1a9e_5722();
    DAT_554c_42ce = uVar9;
    _ppiStack_12 = (int ***)CONCAT22(param_4,param_3);
    uStack_14 = param_2;
    pppppiStack_16 = param_1;
    FUN_1a9e_5722();
    DAT_554c_42ce = bVar8;
    return (uint)bVar8;
  }
  switch(uVar12) {
  case 0:
    pcVar1 = (char *)(CONCAT11(100,(char)(uVar12 * 2)) + (int)param_1);
    *pcVar1 = *pcVar1 + (char)uVar12;
    return uVar12;
  case 1:
    _ppiStack_12 = (int ***)CONCAT22(*(undefined2 *)(uVar12 * 2 + 6),ppiStack_12);
    puVar26 = &stack0xfffe;
    pppppiVar27 = param_1;
code_r0x00027403:
    do {
      FUN_3e34_0ec9();
      pppppiVar27 = (int *****)((int)pppppiVar27 + *(int *)((int)*(undefined4 *)(puVar26 + -4) + 6))
      ;
    } while ((int)pppppiVar27 < *(int *)(puVar26 + -0xc));
    uVar12 = FUN_2424_02ca();
    return uVar12;
  case 3:
LAB_1a9e_6084:
    return uVar12 & 0xff;
  case 4:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ppppiStack_1a = (int ****)param_1;
  uStack_1c = param_2;
  uVar12 = *(uint *)(*(int *)(CONCAT11(uStack_7,local_8) + 8) * 2 + 0x68fe);
  uStack_22 = FUN_4551_0370();
  iVar16 = CONCAT11(uStack_7,local_8);
  uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
  uVar17 = uStack_22;
  if (*(int *)(iVar16 + 0xae) != 0) {
    iVar16 = *(int *)(iVar16 + 0xae);
    ppppppiVar33 = &pppppiStack_16;
    FUN_4551_03eb();
    uVar10 = _ppiStack_12;
    iVar34 = CONCAT11(uStack_7,local_8);
    uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar34)) >> 0x10);
    pppppiStack_16 = (int *****)((int)pppppiStack_16 + (*(int *)(iVar34 + 0x22) - DAT_5b41_0925));
    uVar17 = *(int *)(iVar34 + 0x24) - DAT_5b41_0927;
    uStack_14 = uStack_14 + uVar17;
    if (iVar16 - 1U < 9) {
      piVar7 = (int *)((iVar16 - 1U) * 2);
      pppiVar11 = (int ***)((ulong)_ppiStack_12 >> 0x10);
      switch(iVar16) {
      case 1:
        if ((char)uVar17 != '\0') {
          FUN_2fc8_0364();
          uVar17 = 0;
          if (DAT_554c_5173 < -0x1e) {
            uVar17 = 4;
          }
          else if (0x1d < DAT_554c_5173) {
            uVar17 = 8;
          }
          if (DAT_554c_5175 < -0x1e) {
            uVar17 = uVar17 | 1;
          }
          else if (0x1d < DAT_554c_5175) {
            uVar17 = uVar17 | 2;
          }
        }
        return uVar17;
      case 2:
        cVar18 = (char)((int)uVar17 >> 0xf);
        cVar23 = (char)((uint)piVar7 >> 8) + cVar18;
        *(undefined2 *)(CONCAT11(cVar23,(char)piVar7) + iVar16) = 0x7404;
        uVar17 = uVar17 + 0x1b8;
        cVar15 = (&stack0xfff2)[uVar12];
        bVar19 = cVar18 + (&stack0xfff2)[uVar12];
        pbVar2 = (byte *)(CONCAT11(cVar23,(char)piVar7 + (char)((uint)in_CX >> 8)) + uVar12 +
                         -0x15ba);
        *pbVar2 = *pbVar2 >> 3 | *pbVar2 << 5;
        if (bVar19 != 0 && SCARRY1(cVar18,cVar15) == (int)((uint)bVar19 << 8) < 0) {
          *(char *)(iVar16 + 0xb) = *(char *)(iVar16 + 0xb) + bVar19;
          DAT_5b41_0513 = uStack_14;
          if (DAT_5b41_051d + -0x12 <= (int)uStack_14) {
            DAT_5b41_0513 = (int)pppiVar11 + 0x12;
          }
          if ((uVar12 == 0) || (-0x13 < (int)pppppiStack_16)) {
            uStack_1c = 1;
            DAT_5b41_0515 = (int ******)pppppiStack_16;
          }
          else {
            DAT_5b41_0515 = (int ******)(param_1 + -9);
            DAT_5b41_0513 = (int)pppiVar11 + 0x12;
          }
          ppppppiVar33 = DAT_5b41_0515;
          unaff_SS = 0;
          uStack_22 = DAT_5b41_0513;
          uVar17 = FUN_4551_01dc();
        }
        if (unaff_SS != 0) {
          piVar3 = (int *)(ulong)CONCAT12(bVar8,CONCAT11(uStack_5,local_6));
          *piVar3 = *piVar3 + -0x24;
          piVar3 = (int *)(CONCAT11(uStack_5,local_6) + 4);
          *piVar3 = *piVar3 + 0x24;
        }
        if (uStack_1c != 0) {
          piVar3 = (int *)(CONCAT11(uStack_5,local_6) + 2);
          *piVar3 = *piVar3 + -0x24;
          piVar3 = (int *)(CONCAT11(uStack_5,local_6) + 6);
          *piVar3 = *piVar3 + 0x24;
        }
        if (ppppppiVar33 != (int ******)0x0) {
          piVar3 = (int *)(CONCAT11(uStack_5,local_6) + 4);
          *piVar3 = *piVar3 + 0x24;
        }
        if (uStack_22 != 0) {
          piVar3 = (int *)(CONCAT11(uStack_5,local_6) + 6);
          *piVar3 = *piVar3 + 0x24;
        }
        return uVar17;
      case 3:
        iStack_34 = *piVar7;
        iStack_32 = in_DX;
      case 7:
        uVar17 = uVar12;
        uStack_18 = uStack_22;
        if ((CONCAT11(uStack_7,local_8) != 0 || CONCAT11(uStack_5,local_6) != 0) &&
           (((((CONCAT11(uStack_5,local_6) == unaff_BP &&
               (CONCAT11(uStack_7,local_8) == (uint)bVar8)) ||
              ((CONCAT11(uStack_5,local_6) == iStack_2a && (CONCAT11(uStack_7,local_8) == iStack_2c)
               ))) || ((CONCAT11(uStack_5,local_6) == uStack_2e &&
                       (CONCAT11(uStack_7,local_8) == iStack_30)))) ||
            ((CONCAT11(uStack_5,local_6) == iStack_32 && (CONCAT11(uStack_7,local_8) == iStack_34)))
            ))) {
          uVar17 = uVar12 - 0x23;
          uStack_18 = uStack_22 - 0x23;
          ppppiStack_1a = (int ****)((int)param_1 + 0x23);
          uStack_1c = param_2 + 0x23;
        }
        if (((((int)uStack_14 < (int)uVar17) || ((int)ppppiStack_1a <= (int)pppiVar11)) ||
            ((int)pppppiStack_16 < (int)uStack_18)) ||
           (ppiStack_12 = (int **)uVar10, (int)uStack_1c <= (int)ppiStack_12)) {
          uVar12 = 0;
        }
        else {
          if ((uVar12 != 0) && (DAT_5b41_0939 != 9)) {
            uVar17 = (uint)bVar8;
            iVar34 = (*(byte *)(uVar17 + 0x5a) + uStack_22) - *(int *)(uVar17 + 0x5c);
            uStack_18 = ((uint)*(byte *)(uVar17 + 0x5b) + iVar16) - *(int *)(uVar17 + 0x5c);
            ppppiStack_1a = (int ****)(*(int *)(uVar17 + 0x5c) * 2 + iVar34);
            iVar13 = *(int *)(uVar17 + 0x5c) * 2 + uStack_18;
            if ((*(int *)(uVar12 + 4) == CONCAT11(uStack_5,local_6)) &&
               (*(int *)(uVar12 + 2) == CONCAT11(uStack_7,local_8))) {
              iVar34 = iVar34 + -0x23;
              uStack_18 = uStack_18 + -0x23;
              ppppiStack_1a = (int ****)((int)ppppiStack_1a + 0x23);
            }
            if (((iVar34 <= (int)uStack_14) && ((int)pppiVar11 < (int)ppppiStack_1a)) &&
               (((int)uStack_18 <= (int)pppppiStack_16 && ((int)ppiStack_12 < iVar13)))) {
              if ((*(uint *)(uVar12 + 8) == unaff_BP) && (*(uint *)(uVar12 + 6) == (uint)bVar8)) {
                uVar29 = *(undefined2 *)(uVar12 + 10);
                *(undefined2 *)(uVar12 + 8) = *(undefined2 *)(uVar12 + 0xc);
                *(undefined2 *)(uVar12 + 6) = uVar29;
                *(uint *)(uVar12 + 0xc) = unaff_BP;
                *(uint *)(uVar12 + 10) = (uint)bVar8;
              }
              return *(uint *)(uVar12 + 2);
            }
          }
          puVar28 = (uint *)0x4551;
          for (iVar34 = 0; iVar34 < 2; iVar34 = iVar34 + 1) {
            if (((puVar28 != (uint *)0x0) && (DAT_5b41_0939 != 9)) && (*(int *)(bVar8 + 8) != 7)) {
              iVar22 = (uint)bVar8 + iVar34 * 2;
              iVar13 = (int)*(char *)(iVar22 + 0x7a) + uStack_22;
              iVar14 = iVar13 + -8;
              iVar22 = *(char *)(iVar22 + 0x7b) + iVar16;
              uStack_18 = iVar22 + -4;
              ppppiStack_1a = (int ****)(iVar13 + 8);
              if ((puVar28[1] == CONCAT11(uStack_5,local_6)) &&
                 (*puVar28 == CONCAT11(uStack_7,local_8))) {
                iVar14 = iVar13 + -0x2b;
                uStack_18 = iVar22 + -0x27;
                ppppiStack_1a = (int ****)(iVar13 + 0x2b);
              }
              if (((iVar14 <= (int)uStack_14) && ((int)pppiVar11 < (int)ppppiStack_1a)) &&
                 (((int)uStack_18 <= (int)pppppiStack_16 && ((int)ppiStack_12 < iVar22 + 4)))) {
                if ((puVar28[3] == unaff_BP) && (puVar28[2] == (uint)bVar8)) {
                  FUN_28eb_08be();
                }
                return *puVar28;
              }
            }
            puVar28 = (uint *)0x8b4f;
          }
          uVar12 = (uint)bVar8;
        }
        return uVar12;
      case 4:
        _ppiStack_12 = (int ***)uVar10;
        FUN_1a9e_5ad4();
        FUN_1a9e_5ad4();
        do {
          uVar12 = 32000;
          if (in_stack_00000002 == 0) {
            if (in_stack_00000000 == 0) {
              return (uint)ppiStack_12;
            }
            if ((int)in_stack_00000000 < 0x7d01) {
              uVar12 = in_stack_00000000;
            }
          }
          (*pcRam00025b2d)();
          (*pcRam00025b2d)();
          pppppiStack_16 = (int *****)0x5d2;
          (*pcRam00025b2f)();
          bVar31 = in_stack_00000000 < uVar12;
          in_stack_00000000 = in_stack_00000000 - uVar12;
          in_stack_00000002 = in_stack_00000002 - (uint)bVar31;
        } while( true );
      case 5:
        *(int *)(CONCAT11(uStack_7,local_8) + 0x96) = piVar7[0x11];
        iVar34 = CONCAT11(uStack_7,local_8);
        *(undefined2 *)(iVar34 + 0x3e) = *(undefined2 *)(*(int *)(iVar16 * 2 + 0x302) + 0x38);
        *(undefined2 *)(iVar34 + 0xa4) = 0xffff;
        *(undefined2 *)(iVar34 + 0xa6) = 0xffff;
        uVar30 = *(undefined2 *)(*(int *)(iVar16 * 2 + 0x302) + 0x2a);
        *(int *)(CONCAT11(uStack_7,local_8) + 0x4a) = in_DX;
        *(undefined2 *)(CONCAT11(uStack_7,local_8) + 0x48) = uVar30;
        iVar34 = *(int *)(iVar16 * 2 + 0x302);
        if ((*(int *)(iVar34 + 0x1c) == 0 && *(int *)(iVar34 + 0x1e) == 0) ||
           (puVar4 = (undefined2 *)(*(int *)(iVar16 * 2 + 0x302) + 0x1c),
           iVar34 = (*(code *)*puVar4)(), iVar34 != 0)) {
          puVar4 = (undefined2 *)(*(int *)(iVar16 * 2 + 0x302) + 8);
          (*(code *)*puVar4)();
          iVar16 = CONCAT11(uStack_7,local_8);
          uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
          *(undefined2 *)(iVar16 + 0xac) = *(undefined2 *)(iVar16 + 0xc);
          FUN_28eb_3328();
          uVar12 = 1;
        }
        else {
          uVar12 = 0;
        }
        return uVar12;
      case 6:
        uVar29 = (undefined2)
                 (CONCAT13(uStack_5,CONCAT12(local_6,CONCAT11(uStack_7,local_8))) >> 0x10);
        if ((*(int *)(*(int *)(*(int *)(CONCAT11(uStack_7,local_8) + 8) * 2 + 0x302) + 0x2a) == 0)
           && (*(int *)(*(int *)(*(int *)(CONCAT11(uStack_7,local_8) + 8) * 2 + 0x302) + 0x2c) == 0)
           ) {
          iVar16 = CONCAT11(uStack_7,local_8);
          uVar30 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
          uVar29 = *(undefined2 *)(iVar16 + 0x46);
          uVar12 = *(uint *)(iVar16 + 0x44);
        }
        else {
          iVar16 = *(int *)(*(int *)(CONCAT11(uStack_7,local_8) + 8) * 2 + 0x302);
          uVar29 = *(undefined2 *)(iVar16 + 0x2c);
          uVar12 = *(uint *)(iVar16 + 0x2a);
        }
        iVar16 = CONCAT11(uStack_7,local_8);
        uVar30 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
        *(undefined2 *)(iVar16 + 0x56) = uVar29;
        *(uint *)(iVar16 + 0x54) = uVar12;
        return uVar12;
      case 8:
        if ((piVar7 == (int *)0x0) || ((char)uVar17 == '\0')) {
          if (DAT_554c_559f == '\x03') {
            uVar12 = 0;
          }
          else {
            uVar12 = 1;
          }
        }
        else {
          uVar12 = 3;
        }
        break;
      case 9:
        do {
        } while( true );
      }
      goto LAB_1a9e_6084;
    }
    uVar17 = FUN_2424_1e00();
  }
  iVar16 = CONCAT11(uStack_7,local_8);
  uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
  if (*(int *)(iVar16 + 0xb4) != 0) {
    pppppiVar27 = (int *****)*(undefined2 *)(iVar16 + 0xb4);
    FUN_4551_03eb();
    iVar16 = CONCAT11(uStack_7,local_8);
    uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
    pppppiStack_16 = (int *****)((int)pppppiStack_16 + (*(int *)(iVar16 + 0x22) - DAT_5b41_0925));
    uVar17 = *(int *)(iVar16 + 0x24) - DAT_5b41_0927;
    uStack_14 = uStack_14 + uVar17;
    pppppiVar21 = pppppiVar27 + -1;
    if (pppppiVar21 < (int *****)0xb) {
      ppppiVar20 = (int ****)((int)pppppiVar21 * 2);
      cVar15 = (char)(uVar17 >> 8);
      switch(pppppiVar21) {
      case (int *****)0x0:
        do {
          LOCK();
          uStack_14 = *(uint *)((int)ppppiVar20 + -0x3e17);
          *(uint *)((int)ppppiVar20 + -0x3e17) = uVar17;
          UNLOCK();
          pcVar1 = (char *)((int)ppppiVar20 + (int)(undefined2 *)&DAT_5b41_2839 + uVar12);
          *pcVar1 = *pcVar1 + (char)(uStack_14 >> 8);
          uVar12 = DAT_5b41_2837;
          DAT_5b41_2839 = uStack_14 + ((int)DAT_5b41_2837 >> 4);
          _ppiStack_12 = (int ***)(CONCAT22(DAT_5b41_2839,DAT_5b41_2837) & 0xffff000f);
          if (DAT_554c_42df == '\0') {
            DAT_5b41_2837 = DAT_5b41_2837 & 0xf;
            pppiVar32 = (int ***)FUN_2fc8_00fc();
            FUN_1a9e_74bc();
            ppppiVar20 = *pppppiVar27;
            *ppppiVar20 = (int ***)((ulong)pppiVar32 >> 0x10);
            ppppiVar20[1] = (int ***)pppiVar32;
            FUN_1a9e_7911();
            func_0x0002fdf5();
          }
          else {
            DAT_5b41_2837 = DAT_5b41_2837 & 0xf;
            FUN_1a9e_7911();
          }
          pppiVar32 = _ppiStack_12;
          ppppiVar20 = *pppppiVar27;
          pppiVar11 = (int ***)((ulong)_ppiStack_12 >> 0x10);
          *ppppiVar20 = pppiVar11;
          ppiStack_12 = (int **)pppiVar32;
          ppppiVar20[1] = (int ***)ppiStack_12;
          ppppiVar20[2] = (int ***)0xfffe;
          pppppiVar27 = pppppiVar27 + 1;
          uVar17 = DAT_5b41_2839;
        } while (*pppppiVar27 != (int ****)0x0);
        uStack_14 = DAT_5b41_2839 - DAT_5b41_2835;
        iVar16 = DAT_5b41_2837 - DAT_5b41_2833;
        DAT_5b41_282f = uStack_14 + (iVar16 + 0xf >> 4);
        pppppiStack_16 = (int *****)*(undefined2 *)*(undefined2 *)CONCAT11(uStack_7,local_8);
        pcVar6 = (code *)swi(0x21);
        _ppiStack_12 = pppiVar32;
        (*pcVar6)();
        FUN_1000_130c();
        return uStack_14 * 0x10 + iVar16;
      case (int *****)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (int *****)0x2:
        *(char *)(int *****)((int)ppppiVar20 + (int)pppppiVar27) =
             *(char *)(int *****)((int)ppppiVar20 + (int)pppppiVar27) + '\x01';
        if (uVar17 != 0xf6) {
          ppppiVar20 = ppppiVar20 + -1;
        }
        if (((uint)*ppppiVar20 & 1) == 0) {
          param_2 = (int)param_2 >> 1;
        }
        else {
          param_2 = param_2 >> 1;
        }
        return param_2;
      case (int *****)0x3:
        do {
          iVar16 = 0xb;
          while( true ) {
            while( true ) {
              do {
                uVar29 = (undefined2)((ulong)_ppiStack_12 >> 0x10);
                iVar34 = *(int *)((int)_ppiStack_12 + 0x8e);
                iVar13 = *(int *)((int)_ppiStack_12 + 0x8c);
                _ppiStack_12 = (int ***)CONCAT22(iVar34,iVar13);
                if ((iVar13 == 0 && iVar34 == 0) || (iVar16 != 0)) {
                  iVar34 = CONCAT11(uStack_7,local_8);
                  uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar34)) >> 0x10);
                  if (((int *****)*(undefined2 *)(iVar34 + 0xae) != pppppiVar27) ||
                     (*(int *)(iVar34 + 0xb4) != iVar16)) {
                    FUN_2424_3746();
                    FUN_2424_3746();
                    iVar34 = CONCAT11(uStack_7,local_8);
                    uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar34)) >> 0x10);
                    *(undefined2 *)(iVar34 + 0xae) = pppppiVar27;
                    *(int *)(iVar34 + 0xb4) = iVar16;
                    FUN_2424_3746();
                    FUN_2424_3746();
                  }
                  iVar34 = CONCAT11(uStack_7,local_8);
                  uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar34)) >> 0x10);
                  *(undefined2 *)(iVar34 + 0xae) = pppppiVar27;
                  *(int *)(iVar34 + 0xb4) = iVar16;
                  if ((pppppiVar27 == (int *****)0x0) && (iVar16 == 0)) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = 1;
                  }
                  return uVar12;
                }
              } while ((*(int *)(iVar13 + 0x4a) != 0x10) || (iVar34 = FUN_2424_4087(), iVar34 == 0))
              ;
              uVar29 = (undefined2)((ulong)_ppiStack_12 >> 0x10);
              iVar16 = (int)_ppiStack_12;
              if (*(int *)(iVar16 + 0x22) != *(int *)(CONCAT11(uStack_7,local_8) + 0x22)) break;
              iVar16 = 10;
            }
            iVar34 = CONCAT11(uStack_7,local_8);
            uVar30 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar34)) >> 0x10);
            if (*(int *)(iVar16 + 0x22) + *(int *)(iVar16 + 0x48) !=
                *(int *)(iVar34 + 0x22) + *(int *)(iVar34 + 0x48)) break;
            iVar16 = 0xc;
          }
        } while( true );
      case (int *****)0x4:
        break;
      case (int *****)0x5:
        (&stack0x0e38)[uVar12] =
             (&stack0x0e38)[uVar12] + (char)in_CX + CARRY2((uint)pppppiVar21,(uint)pppppiVar21);
        pppppiStack_16 = (int *****)((int)param_1 + (uint)bVar8 + uVar17 * -2);
        uStack_14 = ((param_2 + unaff_BP + (uint)CARRY2((uint)param_1,(uint)bVar8)) -
                    (in_DX << 1 | (uint)CARRY2(uVar17,uVar17))) -
                    (uint)((int)param_1 + (uint)bVar8 < uVar17 * 2);
        FUN_1000_199e();
        FUN_1000_199e();
        FUN_1000_199e();
        FUN_1000_199e();
        uVar12 = 1 << (local_6 & 0x1f);
        iVar16 = (int)uVar12 >> 0xf;
        pppiVar11 = (int ***)FUN_1000_19bf();
        ppiStack_12 = (int **)FUN_1000_19bf();
        iStack_2c = 0;
        for (uStack_2e = 0; (iStack_2c < iVar16 || ((iStack_2c <= iVar16 && (uStack_2e <= uVar12))))
            ; uStack_2e = uStack_2e + 1) {
          iVar34 = FUN_1000_19bf();
          iVar13 = FUN_1000_19bf();
          if ((pppiVar11 != (int ***)iVar34) || (ppiStack_12 != (int **)iVar13)) {
            FUN_2424_27e0();
            ppiStack_12 = (int **)iVar13;
            pppiVar11 = (int ***)iVar34;
          }
          FUN_1000_180a();
          FUN_1000_180a();
          iStack_2c = iStack_2c + (uint)(0xfffe < uStack_2e);
        }
        return uStack_2e;
      default:
        uVar12 = CONCAT11(cVar15,*(char *)&DAT_554c_5596);
        if (*(char *)&DAT_554c_5596 == '\0') {
          *(undefined1 *)&DAT_554c_5595 = (char)ppppiVar20;
          *(undefined2 *)&DAT_554c_5178 = in_CX;
          *(int *)&DAT_554c_517a = in_DX;
          uVar12 = CONCAT11(cVar15,*(char *)&DAT_554c_5596);
          if ((*(char *)&DAT_554c_5596 == '\0') &&
             (uVar12 = 0, *(int *)&DAT_554c_517c != 0 || *(int *)&DAT_554c_517e != 0)) {
            *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + '\x01';
            *(undefined2 *)&DAT_554c_557e = 0x2000;
            *(undefined2 *)&DAT_554c_557c = 0x2fe;
            FUN_1a9e_5938();
            uVar29 = ((undefined2 *)&DAT_554c_517c)[1];
            pcVar5 = (code *)*(undefined2 *)&DAT_554c_517c;
            *(undefined2 *)&DAT_554c_557e = 0x2000;
            puVar24 = (undefined2 *)&DAT_554c_557c;
            *(undefined2 *)&DAT_554c_557c = 0x303;
            (*pcVar5)();
            *(undefined2 *)((int)puVar24 + -2) = 0x2000;
            *(undefined2 *)((int)puVar24 + -4) = 0x307;
            uVar12 = FUN_1a9e_599d();
            *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + -1;
          }
        }
        return uVar12;
      case (int *****)0x7:
        return uVar17;
      case (int *****)0x8:
        iVar25 = *(int *)(&stack0x6bea + uVar12) * -0x15;
        uVar12 = CONCAT11(uStack_7,local_8);
        if ((CONCAT11(uStack_5,local_6) == DAT_5b41_0ca2) && (uVar12 == DAT_5b41_0ca0)) {
          DAT_5b41_0cb9 = 0;
        }
        else {
          uVar12 = CONCAT11(uStack_7,local_8);
          if ((CONCAT11(uStack_5,local_6) == DAT_5b41_0c9e) && (uVar12 == DAT_5b41_0c9c)) {
            DAT_5b41_0cbb = 0;
          }
          else {
            *(undefined2 *)(iVar25 + -2) = CONCAT11(uStack_5,local_6);
            *(undefined2 *)(iVar25 + -4) = CONCAT11(uStack_7,local_8);
            *(undefined2 *)(iVar25 + -6) = 0x2000;
            *(undefined2 *)(iVar25 + -8) = 0xf845;
            uVar12 = FUN_22de_0351();
          }
        }
        return uVar12;
      case (int *****)0x9:
        *(char *)(int *****)((int)ppppiVar20 + (int)pppppiVar27) =
             *(char *)(int *****)((int)ppppiVar20 + (int)pppppiVar27) + cVar15;
        FUN_2424_4ae2();
        iVar16 = CONCAT11(uStack_7,local_8);
        uVar12 = (uint)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
        while( true ) {
          uVar17 = *(uint *)(iVar16 + 0x8e);
          iVar16 = *(int *)(iVar16 + 0x8c);
          _ppiStack_12 = (int ***)CONCAT22(uVar17,iVar16);
          if ((iVar16 == 0 && uVar17 == 0) || (uStack_14 != 0)) break;
          uVar12 = uVar17;
          if (((*(int *)(iVar16 + 8) == 0x76) && (*(int *)(iVar16 + 0x4a) == 0x20)) &&
             (uStack_14 = uVar17,
             *(int *)(iVar16 + 0x24) == *(int *)(CONCAT11(uStack_7,local_8) + 0x24) + -0x20)) {
            bVar31 = (*(byte *)(iVar16 + 0xc) & 0x30) != 0;
            if (((uStack_22 != 0) || (bVar31)) ||
               (*(int *)(iVar16 + 0x22) != *(int *)(CONCAT11(uStack_7,local_8) + 0x22))) {
              if (((uStack_22 != 0) && (!bVar31)) &&
                 (iVar34 = CONCAT11(uStack_7,local_8),
                 uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar34)) >> 0x10),
                 *(int *)(iVar16 + 0x22) + *(int *)(iVar16 + 0x48) ==
                 *(int *)(iVar34 + 0x22) + *(int *)(iVar34 + 0x48))) {
                uStack_14 = 9;
              }
            }
            else {
              uStack_14 = 7;
            }
          }
        }
        iVar16 = CONCAT11(uStack_7,local_8);
        uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
        uStack_14 = *(int *)(iVar16 + 0x4a) + 0x10;
        pppppiStack_16 = (int *****)*(int *)(iVar16 + 0x4a);
        FUN_2424_4ae2();
        iVar16 = CONCAT11(uStack_7,local_8);
        iVar34 = (int)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
        while( true ) {
          iVar13 = *(int *)(iVar16 + 0x8e);
          iVar16 = *(int *)(iVar16 + 0x8c);
          _ppiStack_12 = (int ***)CONCAT22(iVar13,iVar16);
          if ((iVar16 == 0 && iVar13 == 0) || (pppppiStack_16 != (int *****)0x0)) break;
          iVar34 = iVar13;
          if ((((*(int *)(iVar16 + 8) == 0x76) && (*(int *)(iVar16 + 0x4a) == 0x20)) &&
              (iVar14 = CONCAT11(uStack_7,local_8),
              uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar14)) >> 0x10),
              *(int *)(iVar14 + 0x24) + *(int *)(iVar14 + 0x4a) == *(int *)(iVar16 + 0x24))) &&
             (((*(byte *)(iVar16 + 0xc) & 0x30) != 0 &&
              (iVar14 = CONCAT11(uStack_7,local_8),
              uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar14)) >> 0x10),
              *(int *)(iVar16 + 0x22) + *(int *)(iVar16 + 0x48) ==
              *(int *)(iVar14 + 0x22) + *(int *)(iVar14 + 0x48))))) {
            pppppiStack_16 = (int *****)0xc;
          }
        }
        iVar16 = CONCAT11(uStack_7,local_8);
        uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
        if ((*(int *)(iVar16 + 0xae) != uStack_14) ||
           ((int *****)*(int *)(iVar16 + 0xb4) != pppppiStack_16)) {
          uStack_14 = 1;
          pppppiStack_16 = (int *****)CONCAT11(uStack_5,local_6);
          FUN_2424_3746();
          FUN_2424_3746();
          iVar16 = CONCAT11(uStack_7,local_8);
          uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
          *(int *)(iVar16 + 0xae) = uStack_14;
          *(int *)(iVar16 + 0xb4) = (int)pppppiStack_16;
          FUN_2424_3746();
          FUN_2424_3746();
        }
        iVar16 = CONCAT11(uStack_7,local_8);
        uVar29 = (undefined2)(CONCAT13(uStack_5,CONCAT12(local_6,iVar16)) >> 0x10);
        *(int *)(iVar16 + 0xae) = uStack_14;
        *(int *)(iVar16 + 0xb4) = (int)pppppiStack_16;
        if ((uStack_14 == 0) && (pppppiStack_16 == (int *****)0x0)) {
          uVar12 = 0;
        }
        else {
          uVar12 = 1;
        }
        return uVar12;
      }
      goto code_r0x00027403;
    }
    uVar17 = FUN_2424_1e00();
  }
  return uVar17;
}

