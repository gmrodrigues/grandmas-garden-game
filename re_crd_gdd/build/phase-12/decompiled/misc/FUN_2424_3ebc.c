// TIM2.EXE: FUN_2424_3ebc @ file 0x02D2FC Ghidra 0x280FC
// Subsystem: misc | Size: 263 bytes


/* WARNING: Instruction at (ram,0x0002549d) overlaps instruction at (ram,0x0002549c)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Type propagation algorithm not settling */

int * __cdecl16far FUN_2424_3ebc(int *param_1,int param_2,int *param_3,int param_4)

{
  uint *puVar1;
  char *pcVar2;
  byte *pbVar3;
  undefined2 *puVar4;
  code *pcVar5;
  code *pcVar6;
  int *piVar7;
  undefined1 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined2 uVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  undefined4 *puVar16;
  char cVar17;
  uint uVar18;
  int *in_CX;
  char cVar19;
  byte bVar20;
  undefined4 *in_DX;
  int *piVar21;
  uint *puVar22;
  char cVar25;
  int *piVar23;
  uint uVar24;
  undefined2 *puVar26;
  int iVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined2 *puVar31;
  int unaff_SI;
  int iVar32;
  undefined4 *puVar33;
  int *piVar34;
  int *piVar35;
  undefined4 *puVar36;
  int *piVar37;
  int *piVar38;
  undefined2 *unaff_SS;
  bool bVar39;
  undefined4 uVar40;
  undefined2 *puVar41;
  int *in_stack_0000ffd6;
  int *in_stack_0000ffd8;
  int *in_stack_0000ffda;
  int *in_stack_0000ffdc;
  int *in_stack_0000ffde;
  int *in_stack_0000ffe0;
  undefined2 uVar42;
  int *piStack_1c;
  int *piStack_1a;
  int *piStack_18;
  undefined4 local_e;
  undefined4 uStack_a;
  undefined4 local_6;
  
  piVar37 = (int *)0x2424;
  puVar30 = &stack0xfffe;
  puVar36 = (undefined4 *)((ulong)param_1 >> 0x10);
  piVar23 = (int *)param_1;
  piVar15 = (int *)*(undefined2 *)(piVar23[4] * 2 + 0x68fe);
  local_6 = (int *)CONCAT22(local_6._2_2_,piVar15);
  piVar35 = (int *)0x0;
  for (iVar32 = 2; piStack_18 = piVar37, iVar32 != 0; iVar32 = iVar32 + -1) {
    do {
      piVar35 = (int *)((int)piVar35 + 1);
      piVar37 = (int *)0x4551;
      piStack_1a = (int *)0x8127;
      piVar15 = (int *)FUN_4551_0308();
      piStack_18 = piVar37;
    } while (piVar15 == (int *)0x0);
  }
  piVar38 = piVar37;
  if (piVar23[0x57] != 0) {
    local_6 = (int *)CONCAT22(piVar23[0x57],(int *)local_6);
    puVar16 = &local_e;
    piStack_18 = (int *)((int)piVar35 + piVar23[0x57] + -1);
    piStack_1a = (int *)local_6;
    piVar38 = (int *)0x4551;
    uVar42 = 0x815a;
    piStack_1c = piVar37;
    FUN_4551_03eb();
    piVar37 = (int *)((int)(int *)local_e + (piVar23[0x11] - DAT_5b41_0925));
    piVar15 = (int *)(piVar23[0x12] - DAT_5b41_0927);
    iVar32 = (int)local_e._2_2_ + (int)piVar15;
    local_e = (int *)CONCAT22(iVar32,piVar37);
    uVar24 = (int)local_6._2_2_ - 1;
    if (8 < uVar24) {
      piStack_18 = (int *)&local_e;
      piStack_1a = (int *)0x4551;
      piStack_1c = (int *)0x819d;
      piVar15 = (int *)FUN_2424_1e00();
      goto LAB_2424_3f60;
    }
    piVar21 = (int *)(uVar24 * 2);
    piVar38 = (int *)0x2000;
    iVar9 = 0;
    puVar30 = &stack0xfffe;
    piVar34 = piVar35;
    switch(uVar24) {
    case 0:
      goto switchD_2000_8181_caseD_0;
    case 1:
      iVar32 = piVar21[0x25];
code_r0x000254a4:
      iVar32 = iVar32 + (int)(int *)local_e;
      puVar31 = DAT_5b41_04ac;
      piVar15 = piVar38;
      do {
        while (piVar38 = piVar15, puVar31 == (undefined2 *)0x0) {
LAB_2424_12ce:
          while( true ) {
            do {
              do {
                do {
                  while( true ) {
                    do {
                      while( true ) {
                        while( true ) {
                          puVar31 = (undefined2 *)((int *)local_6)[1];
                          piVar15 = (int *)*local_6;
                          local_6 = (int *)CONCAT22(puVar31,piVar15);
                          if (piVar15 != (int *)0x0 || puVar31 != (undefined2 *)0x0) break;
                          unaff_SS = (undefined2 *)((int)unaff_SS + 1);
                          if (1 < (int)unaff_SS) {
                            return (int *)(undefined4 *)0x0;
                          }
                          if (unaff_SS == (undefined2 *)0x0) {
                            piVar15 = (int *)&DAT_5b41_054f;
                          }
                          else {
                            piVar15 = (int *)&DAT_5b41_0557;
                          }
                          local_6 = (int *)CONCAT22(0x554c,piVar15);
                        }
                        if (DAT_5b41_04b4 == 0) break;
                        DAT_5b41_04b4 = 0;
                        local_6 = &DAT_5b41_054f;
                        unaff_SS = (undefined2 *)0x0;
                      }
                      if ((char)piVar15[0xc] == -0x80) {
                        *(undefined1 *)(piVar15 + 0xc) = 0;
                      }
                      if ((*(byte *)((int)piVar15 + 0xf) & 0x20) == 0) {
                        iVar32 = 0;
                        piVar23 = (int *)0x0;
                      }
                      else {
                        piVar23 = (int *)piVar15[0x57];
                        iVar32 = piVar15[0x5a];
                      }
                      uStack_a = (int *)CONCAT22(iVar32,piVar23);
                    } while ((((char)piVar15[0xc] != '\0') ||
                             ((*(byte *)((int)piVar15 + 0xd) & 0x20) != 0)) ||
                            ((*(byte *)((int)piVar15 + 0xf) & 0x40) != 0));
                    if ((piVar15[4] != 10) && (piVar15[4] != 0x4c)) break;
                    piStack_1a = (int *)0x53a6;
                    piStack_18 = piVar38;
                    FUN_2424_12f5();
                    unaff_SS = puVar31;
                  }
                } while (piVar15[4] == 0x31);
                if (piVar15[4] != 8) {
                  local_e = (int *)CONCAT22(piVar15[0x17] - DAT_5b41_0925,
                                            (int *)(piVar15[0x18] - DAT_5b41_0927));
                  unaff_SI = piVar15[0x24] + (piVar15[0x17] - DAT_5b41_0925);
                  iVar32 = piVar15[0x25];
                  goto code_r0x000254a4;
                }
                puVar4 = (undefined2 *)piVar15[0x2c];
              } while (puVar4 == (undefined2 *)0x0);
              piVar38 = (int *)0x28eb;
              piStack_18 = (int *)0x53d7;
              iVar32 = FUN_28eb_1c08();
              unaff_SS = puVar4;
            } while (iVar32 == 0);
            if (DAT_5b41_0939 != 9) break;
            if ((((undefined4 *)puVar4[4] != DAT_5b41_0567._2_2_) ||
                ((int *)puVar4[3] != (int *)DAT_5b41_0567)) &&
               (((undefined4 *)puVar4[6] != DAT_5b41_0567._2_2_ ||
                ((int *)puVar4[5] != (int *)DAT_5b41_0567)))) break;
            unaff_SS = (undefined2 *)0x28eb;
            piVar38 = (int *)0x28eb;
            iVar32 = FUN_28eb_4d94();
            if (iVar32 != 0) break;
          }
          piVar15 = (int *)0x28eb;
          if ((int)puVar4[7] < (int)puVar4[9]) {
            iVar32 = puVar4[7] - DAT_5b41_0925;
            iVar9 = puVar4[0xd] - puVar4[7];
          }
          else {
            iVar32 = puVar4[9] - DAT_5b41_0925;
            iVar9 = puVar4[0xb] - puVar4[9];
          }
          unaff_SI = iVar32 + iVar9;
          puVar31 = DAT_5b41_04ac;
          if ((int)puVar4[8] < (int)puVar4[10]) {
            piVar23 = (int *)(puVar4[8] - DAT_5b41_0927);
            local_e = (int *)CONCAT22(iVar32,piVar23);
            iVar32 = (int)piVar23 + (puVar4[0xe] - puVar4[8]);
          }
          else {
            local_e = (int *)CONCAT22(iVar32,(int *)(puVar4[10] - DAT_5b41_0927));
            iVar32 = (puVar4[10] - DAT_5b41_0927) + (puVar4[0xc] - puVar4[10]);
          }
        }
        if (puVar31[6] == 1) {
          if (((((int)puVar31[1] < unaff_SI) && ((int)local_e._2_2_ <= (int)puVar31[3])) &&
              ((int)puVar31[2] < iVar32)) && ((int)(int *)local_e <= (int)puVar31[4])) {
LAB_2424_12b5:
            piStack_18 = (int *)local_6;
            piVar38 = (int *)0x28eb;
            piStack_1c = (int *)0x5503;
            piStack_1a = piVar15;
            FUN_28eb_2d82();
            unaff_SS = (undefined2 *)0x81;
            goto LAB_2424_12ce;
          }
          if ((uStack_a._2_2_ != (int *)0x0) || ((int *)uStack_a != (int *)0x0)) {
            piStack_18 = (int *)local_6;
            piStack_1c = (int *)0x54ee;
            piStack_1a = piVar15;
            iVar9 = FUN_2424_36fe();
            unaff_SS = puVar31;
            if (iVar9 != 0) goto LAB_2424_12b5;
          }
        }
        puVar31 = (undefined2 *)*puVar31;
      } while( true );
    case 2:
      piVar21[0x1e] = (int)piVar15 - piVar21[0x14];
      piVar21[0x1e] = piVar21[0x1e] << (9U - (char)param_3 & 0x1f);
      piStack_18 = (int *)0x2000;
      piStack_1a = (int *)0xcb79;
      puVar36 = (undefined4 *)FUN_549b_007a();
      return (int *)puVar36;
    case 3:
switchD_2000_e962_caseD_1:
      piVar35 = in_stack_0000ffde;
      *(int *)(puVar30 + -8) = *(int *)(puVar30 + -8) + (piVar21[0x11] - DAT_5b41_0925);
      puVar16 = (undefined4 *)(piVar21[0x12] - DAT_5b41_0927);
      *(int *)(puVar30 + -6) = *(int *)(puVar30 + -6) + (int)puVar16;
      if (8 < iVar9 - 1U) {
        puVar36 = (undefined4 *)FUN_2424_1e00(puVar30 + -8);
        goto LAB_2424_4954;
      }
      puVar31 = (undefined2 *)((iVar9 - 1U) * 2);
      switch(iVar9) {
      case 1:
        if ((char)puVar16 == '\0') {
          return (int *)puVar16;
        }
        piVar15 = *(int **)(puVar30 + 6);
switchD_2000_8181_caseD_0:
        FUN_2fc8_0364(0x2000,piVar15);
        puVar36 = (undefined4 *)0x0;
        if (DAT_554c_5173 < -0x1e) {
          puVar36 = (undefined4 *)0x4;
        }
        else if (0x1d < DAT_554c_5173) {
          puVar36 = (undefined4 *)0x8;
        }
        if (DAT_554c_5175 < -0x1e) {
          puVar36 = (undefined4 *)((uint)puVar36 | 1);
        }
        else if (0x1d < DAT_554c_5175) {
          puVar36 = (undefined4 *)((uint)puVar36 | 2);
        }
        return (int *)puVar36;
      case 2:
        cVar19 = (char)((int)puVar16 >> 0xf);
        cVar25 = (char)((uint)puVar31 >> 8) + cVar19;
        *(undefined2 *)(CONCAT11(cVar25,(char)puVar31) + iVar9) = 0x7404;
        puVar16 = puVar16 + 0x6e;
        cVar17 = puVar30[(int)piVar34];
        bVar20 = cVar19 + puVar30[(int)piVar34];
        pbVar3 = (byte *)((int)piVar34 +
                         CONCAT11(cVar25,(char)puVar31 + (char)((uint)in_CX >> 8)) + -0x15ba);
        *pbVar3 = *pbVar3 >> 3 | *pbVar3 << 5;
        if (bVar20 == 0 || SCARRY1(cVar19,cVar17) != (int)((uint)bVar20 << 8) < 0)
        goto LAB_2424_355a;
        *(char *)(iVar9 + 0xb) = *(char *)(iVar9 + 0xb) + bVar20;
code_r0x00027717:
        puVar29 = puVar30;
        if (*(int *)(puVar30 + -6) < DAT_5b41_051d + -0x12) goto LAB_2424_34e2;
        DAT_5b41_0513 = *(int *)(puVar30 + -2) + 0x12;
        *(undefined2 *)(puVar30 + -0x10) = 1;
        goto LAB_2424_34fd;
      case 3:
        uVar42 = *puVar31;
        *(undefined4 **)(puVar30 + -0x24) = in_DX;
        *(undefined2 *)(puVar30 + -0x26) = uVar42;
        break;
      case 4:
        uVar40 = FUN_1a9e_5ad4();
        *(int *)(puVar30 + 6) = (int)uVar40;
        *(int *)(puVar30 + 8) = (int)((ulong)uVar40 >> 0x10);
        FUN_1a9e_5ad4();
        do {
          uVar24 = 32000;
          if (*(int *)(puVar30 + 0x10) == 0) {
            uVar18 = *(uint *)(puVar30 + 0xe);
            if (uVar18 == 0) {
              return (int *)*(undefined4 **)(puVar30 + -4);
            }
            if ((int)uVar18 < 0x7d01) {
              uVar24 = uVar18;
            }
          }
          (*pcRam00025b2d)();
          (*pcRam00025b2d)();
          piStack_1c = (int *)0x5d2;
          (*pcRam00025b2f)();
          puVar1 = (uint *)(puVar30 + 0xe);
          uVar18 = *puVar1;
          *puVar1 = *puVar1 - uVar24;
          *(uint *)(puVar30 + 0x10) = *(int *)(puVar30 + 0x10) - (uint)(uVar18 < uVar24);
        } while( true );
      case 5:
        *(undefined2 *)(*(int *)(puVar30 + 6) + 0x96) = puVar31[0x11];
        iVar32 = *(int *)(puVar30 + 6);
        *(undefined2 *)(iVar32 + 0x3e) = *(undefined2 *)(*(int *)(iVar9 * 2 + 0x302) + 0x38);
        *(undefined2 *)(iVar32 + 0xa4) = 0xffff;
        *(undefined2 *)(iVar32 + 0xa6) = 0xffff;
        uVar42 = *(undefined2 *)(*(int *)(iVar9 * 2 + 0x302) + 0x2a);
        iVar32 = *(int *)(puVar30 + 6);
        *(uint *)(iVar32 + 0x4a) = (uint)in_DX;
        *(undefined2 *)(iVar32 + 0x48) = uVar42;
        iVar32 = *(int *)(iVar9 * 2 + 0x302);
        if ((*(int *)(iVar32 + 0x1c) == 0 && *(int *)(iVar32 + 0x1e) == 0) ||
           (puVar41 = (undefined2 *)(*(int *)(iVar9 * 2 + 0x302) + 0x1c),
           iVar32 = (*(code *)*puVar41)(0x2000,*(undefined2 *)(puVar30 + 6),
                                        *(undefined2 *)(puVar30 + 8)), iVar32 != 0)) {
          puVar41 = (undefined2 *)(*(int *)(iVar9 * 2 + 0x302) + 8);
          (*(code *)*puVar41)(0x2000,*(undefined2 *)(puVar30 + 6),*(undefined2 *)(puVar30 + 8));
          uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
          iVar32 = (int)*(undefined4 *)(puVar30 + 6);
          *(undefined2 *)(iVar32 + 0xac) = *(undefined2 *)(iVar32 + 0xc);
          FUN_28eb_3328(iVar32,*(undefined2 *)(puVar30 + 8));
          puVar36 = (undefined4 *)0x1;
        }
        else {
          puVar36 = (undefined4 *)0x0;
        }
        return (int *)puVar36;
      case 6:
        uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
        if ((*(int *)(*(int *)(*(int *)((int)*(undefined4 *)(puVar30 + 6) + 8) * 2 + 0x302) + 0x2a)
             == 0) &&
           (*(int *)(*(int *)(*(int *)(*(int *)(puVar30 + 6) + 8) * 2 + 0x302) + 0x2c) == 0)) {
          uVar12 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
          iVar32 = (int)*(undefined4 *)(puVar30 + 6);
          uVar42 = *(undefined2 *)(iVar32 + 0x46);
          puVar36 = (undefined4 *)*(undefined2 *)(iVar32 + 0x44);
        }
        else {
          iVar32 = *(int *)(*(int *)((int)*(undefined4 *)(puVar30 + 6) + 8) * 2 + 0x302);
          uVar42 = *(undefined2 *)(iVar32 + 0x2c);
          puVar36 = (undefined4 *)*(undefined2 *)(iVar32 + 0x2a);
        }
        uVar12 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
        iVar32 = (int)*(undefined4 *)(puVar30 + 6);
        *(undefined2 *)(iVar32 + 0x56) = uVar42;
        *(undefined2 *)(iVar32 + 0x54) = puVar36;
        return (int *)puVar36;
      case 8:
        if ((puVar31 == (undefined2 *)0x0) || ((char)puVar16 == '\0')) {
          if (DAT_554c_559f == '\x03') {
            puVar36 = (undefined4 *)0x0;
          }
          else {
            puVar36 = (undefined4 *)0x1;
          }
        }
        else {
          puVar36 = (undefined4 *)0x3;
        }
        return (int *)puVar36;
      case 9:
        do {
        } while( true );
      }
      if ((*(int *)(puVar30 + 6) == 0 && *(int *)(puVar30 + 8) == 0) ||
         (((((*(int *)(puVar30 + 8) != *(int *)(puVar30 + 0xc) ||
             (*(int *)(puVar30 + 6) != *(int *)(puVar30 + 10))) &&
            ((*(int *)(puVar30 + 8) != *(int *)(puVar30 + -0x1c) ||
             (*(int *)(puVar30 + 6) != *(int *)(puVar30 + -0x1e))))) &&
           ((*(int *)(puVar30 + 8) != *(int *)(puVar30 + -0x20) ||
            (*(int *)(puVar30 + 6) != *(int *)(puVar30 + -0x22))))) &&
          ((*(int *)(puVar30 + 8) != *(int *)(puVar30 + -0x24) ||
           (*(int *)(puVar30 + 6) != *(int *)(puVar30 + -0x26))))))) goto LAB_28eb_0bc1;
      piVar35 = (int *)((int)piVar34 + -0x23);
      *(int *)(puVar30 + -10) = *(int *)(puVar30 + -10) + -0x23;
      goto code_r0x00029a69;
    case 4:
      bVar39 = (byte)((byte)piVar15 | 1) == 0;
      puVar31 = (undefined2 *)0x0;
      do {
        if (((!bVar39) || (unaff_SI < (int)puVar31[1])) ||
           (((int)puVar31[3] < (int)local_e._2_2_ ||
            (((int)piVar35 < (int)puVar31[2] || ((int)puVar31[4] < (int)(int *)local_e)))))) {
          puVar31 = (undefined2 *)*puVar31;
          goto LAB_2424_14ee;
        }
        piStack_1c = (int *)0x571b;
        piStack_1a = piVar38;
        piStack_18 = piVar23;
        FUN_28eb_2d82();
        piVar15 = (int *)0x28eb;
        in_stack_0000ffde = in_stack_0000ffd6;
        in_stack_0000ffe0 = in_stack_0000ffd8;
        puVar16 = puVar36;
        do {
          if ((in_stack_0000ffe0 == in_stack_0000ffd8) && (in_stack_0000ffde == in_stack_0000ffd6))
          {
            piStack_1c = (int *)0x0;
            piVar35 = (int *)0x0;
            piVar37 = (int *)0x0;
            piVar34 = (int *)0x0;
          }
          else {
            piVar35 = (int *)in_stack_0000ffde[0x2f];
            piVar37 = (int *)in_stack_0000ffde[0x30];
            piVar34 = in_stack_0000ffde;
            piStack_1c = in_stack_0000ffe0;
          }
          in_stack_0000ffe0 = piVar37;
          in_stack_0000ffde = piVar35;
          if ((piVar34 == (int *)0x0 && piStack_1c == (int *)0x0) ||
             (in_stack_0000ffde == (int *)0x0 && in_stack_0000ffe0 == (int *)0x0)) {
            return (int *)(undefined4 *)0x0;
          }
          if ((piStack_1c != in_stack_0000ffdc) || (piVar34 != in_stack_0000ffda)) {
            piStack_18 = (int *)0x1;
            puVar16 = (undefined4 *)0x0;
          }
          local_6 = (int *)CONCAT22(piVar34[0x17] + (int)(char)piVar34[(int)piStack_18 + 0x3d],
                                    (int *)(piVar34[0x18] +
                                           (int)*(char *)((int)piVar34 + (int)piStack_18 * 2 + 0x7b)
                                           ));
          piVar38 = piVar15;
          if ((in_stack_0000ffe0 == in_stack_0000ffd8) && (in_stack_0000ffde == in_stack_0000ffd6))
          {
            piStack_18 = piStack_1c;
            piVar38 = (int *)0x28eb;
            piStack_1c = piVar15;
            piStack_1a = piVar34;
            puVar16 = (undefined4 *)FUN_28eb_3b36();
          }
          iVar32 = in_stack_0000ffde[0x17] + (int)(char)in_stack_0000ffde[(int)piStack_1a + 0x3d];
          piVar15 = (int *)(in_stack_0000ffde[0x18] +
                           (int)*(char *)((int)in_stack_0000ffde + (int)piStack_1a * 2 + 0x7b));
          uStack_a = (int *)CONCAT22(iVar32,piVar15);
          if ((int)local_6._2_2_ < iVar32) {
            iVar9 = (int)local_6._2_2_ - DAT_5b41_0925;
          }
          else {
            iVar9 = iVar32 - DAT_5b41_0925;
            iVar32 = (int)local_6._2_2_;
          }
          if ((int)(int *)local_6 < (int)piVar15) {
            iVar10 = (int)(int *)local_6 - DAT_5b41_0927;
          }
          else {
            iVar10 = (int)piVar15 - DAT_5b41_0927;
            piVar15 = (int *)local_6;
          }
          iVar11 = (int)piVar15 - DAT_5b41_0927;
          if (0 < (int)puVar16) {
            iVar11 = iVar11 + ((int)puVar16 >> 1);
          }
          uVar24 = (uint)((iVar32 - DAT_5b41_0925) - iVar9 < iVar11 - iVar10);
          unaff_SI = (iVar32 - DAT_5b41_0925) + uVar24;
          local_e = (int *)CONCAT22(iVar9 - uVar24,(int *)(iVar10 - (uint)(uVar24 == 0)));
          piVar35 = (int *)(iVar11 + (uint)(uVar24 == 0));
          puVar31 = DAT_5b41_04ac;
LAB_2424_14ee:
          piVar15 = piVar38;
        } while (puVar31 == (undefined2 *)0x0);
        bVar39 = puVar31[6] == 1;
      } while( true );
    case 5:
      puVar16 = (undefined4 *)FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e6);
      if (((uint)piVar35 & 0x80) != 0) {
        FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e2,uStack_a._2_2_,local_e._2_2_,0);
        puVar16 = (undefined4 *)0x1;
      }
      if (((uint)piVar35 & 0x800) != 0) {
        FUN_4551_01dc(DAT_5b41_050d,DAT_5b41_04e2,(int)local_6._2_2_ + 0x10,(int *)local_e + -4,0);
        puVar16 = (undefined4 *)0x1;
      }
      puVar30 = &stack0xfffe;
      if (((uint)piVar35 & 0x410) == 0) goto LAB_2424_355a;
      piStack_18 = (int *)(uint)(((uint)piVar35 & 0x400) != 0);
      puVar30 = &stack0xfffe;
      puVar29 = &stack0xfffe;
      if (piStack_18 != (int *)0x0) goto code_r0x00027717;
LAB_2424_34e2:
      DAT_5b41_0513 = *(int *)(puVar29 + -6);
      *(undefined2 *)(puVar29 + -0x12) = 1;
      puVar30 = puVar29;
LAB_2424_34fd:
      if ((*(int *)(puVar30 + -0x16) == 0) || (-0x13 < *(int *)(puVar30 + -8))) {
        DAT_5b41_0515 = *(int *)(puVar30 + -8);
        *(undefined2 *)(puVar30 + -0xe) = 1;
      }
      else {
        DAT_5b41_0515 = *(int *)(puVar30 + -0xc) + -0x12;
        DAT_5b41_0513 = *(int *)(puVar30 + -2) + 0x12;
        *(undefined2 *)(puVar30 + -0x10) = 1;
        *(undefined2 *)(puVar30 + -0x14) = 1;
      }
      uVar42 = DAT_5b41_04dc;
      if (*(int *)(puVar30 + -0x16) != 0) {
        uVar42 = DAT_5b41_04de;
      }
      *(undefined2 *)(puVar30 + -0x18) = uVar42;
      puVar16 = (undefined4 *)FUN_4551_01dc(DAT_5b41_050d,uVar42,DAT_5b41_0513,DAT_5b41_0515,0);
LAB_2424_355a:
      if (*(int *)(puVar30 + -0x10) != 0) {
        piVar7 = *(int **)(puVar30 + 8);
        *piVar7 = *piVar7 + -0x24;
        ((int *)piVar7)[2] = ((int *)piVar7)[2] + 0x24;
      }
      if (*(int *)(puVar30 + -0xe) != 0) {
        uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 8) >> 0x10);
        iVar32 = (int)*(undefined4 *)(puVar30 + 8);
        piVar7 = (int *)(iVar32 + 2);
        *piVar7 = *piVar7 + -0x24;
        piVar7 = (int *)(iVar32 + 6);
        *piVar7 = *piVar7 + 0x24;
      }
      if (*(int *)(puVar30 + -0x12) != 0) {
        piVar7 = (int *)((int)*(undefined4 *)(puVar30 + 8) + 4);
        *piVar7 = *piVar7 + 0x24;
      }
      if (*(int *)(puVar30 + -0x14) != 0) {
        piVar7 = (int *)((int)*(undefined4 *)(puVar30 + 8) + 6);
        *piVar7 = *piVar7 + 0x24;
      }
      return (int *)puVar16;
    case 6:
      in_CX = (int *)CONCAT11((char)((uint)in_CX >> 8),
                              (char)in_CX + (char)piVar21[7] + CARRY2(uVar24,uVar24));
      puVar30 = &stack0xffec;
      piVar34 = (int *)*(undefined2 *)(piVar37[4] * 2 + 0x68fe);
      puVar36 = (undefined4 *)FUN_4551_0370(piVar34,3,piVar35,0,uVar42);
      uVar42 = (undefined2)((ulong)local_e >> 0x10);
      if (((int *)local_e)[0x57] != 0) {
        iVar9 = ((int *)local_e)[0x57];
        FUN_4551_03eb(piVar34,puVar36,&piStack_1c);
        puVar36 = (undefined4 *)((ulong)local_e >> 0x10);
        piVar21 = (int *)local_e;
        puVar30 = &stack0xffec;
        in_stack_0000ffde = piVar35;
        goto switchD_2000_e962_caseD_1;
      }
LAB_2424_4954:
      uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
      iVar32 = (int)*(undefined4 *)(puVar30 + 6);
      if (*(int *)(iVar32 + 0xb4) == 0) {
        return (int *)puVar36;
      }
      piVar15 = (int *)*(undefined2 *)(iVar32 + 0xb4);
      FUN_4551_03eb(piVar34,*(undefined2 *)(puVar30 + -10),puVar30 + -8);
      uVar24 = (uint)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
      iVar32 = (int)*(undefined4 *)(puVar30 + 6);
      *(int *)(puVar30 + -8) = *(int *)(puVar30 + -8) + (*(int *)(iVar32 + 0x22) - DAT_5b41_0925);
      puVar36 = (undefined4 *)(*(int *)(iVar32 + 0x24) - DAT_5b41_0927);
      *(int *)(puVar30 + -6) = *(int *)(puVar30 + -6) + (int)puVar36;
      piVar23 = piVar15 + -1;
      if ((int *)0xa < piVar23) {
        puVar36 = (undefined4 *)FUN_2424_1e00(puVar30 + -8);
        return (int *)puVar36;
      }
      puVar22 = (uint *)((int)piVar23 * 2);
      cVar17 = (char)((uint)puVar36 >> 8);
      switch(piVar23) {
      case (int *)0x0:
        do {
          LOCK();
          uVar24 = *(uint *)((int)puVar22 + -0x3e17);
          *(uint *)((int)puVar22 + -0x3e17) = (uint)puVar36;
          UNLOCK();
          pcVar2 = (char *)((int)(undefined2 *)&DAT_5b41_2839 + (int)puVar22 + (int)piVar34);
          *pcVar2 = *pcVar2 + (char)(uVar24 >> 8);
          piVar34 = DAT_5b41_2837;
          *(uint *)(puVar30 + -6) = uVar24;
          DAT_5b41_2839 = (undefined4 *)(*(int *)(puVar30 + -6) + ((int)DAT_5b41_2837 >> 4));
          DAT_5b41_2837 = (int *)((uint)DAT_5b41_2837 & 0xf);
          *(undefined4 **)(puVar30 + -2) = DAT_5b41_2839;
          *(int **)(puVar30 + -4) = DAT_5b41_2837;
          if (DAT_554c_42df == '\0') {
            *(int *)(puVar30 + -10) = *(int *)(*piVar15 + 6) * *(int *)(*piVar15 + 8);
            uVar40 = FUN_2fc8_00fc(0x2000,*(undefined2 *)(puVar30 + -10),0,0,0);
            *(int *)(puVar30 + -0xc) = (int)((ulong)uVar40 >> 0x10);
            *(int *)(puVar30 + -0xe) = (int)uVar40;
            *(uint *)(puVar30 + -10) = *(uint *)(puVar30 + -10) >> 1;
            *(uint *)(puVar30 + -10) = *(uint *)(puVar30 + -10) >> 1;
            *(uint *)(puVar30 + -10) = *(uint *)(puVar30 + -10) >> 1;
            FUN_1a9e_74bc(*(undefined2 *)(puVar30 + -0xe),*(undefined2 *)(puVar30 + -0xc),
                          *(undefined2 *)*piVar15,((undefined2 *)*piVar15)[1],
                          *(undefined2 *)(puVar30 + -10));
            puVar31 = (undefined2 *)*piVar15;
            *puVar31 = *(undefined2 *)(puVar30 + -0xc);
            puVar31[1] = *(undefined2 *)(puVar30 + -0xe);
            FUN_1a9e_7911(puVar31);
            func_0x0002fdf5(0x2000,*(undefined2 *)(puVar30 + -0xe),*(undefined2 *)(puVar30 + -0xc));
          }
          else {
            FUN_1a9e_7911(*piVar15);
          }
          puVar22 = (uint *)*piVar15;
          *puVar22 = *(uint *)(puVar30 + -2);
          puVar22[1] = *(uint *)(puVar30 + -4);
          puVar22[2] = 0xfffe;
          piVar23 = DAT_5b41_2837;
          iVar32 = DAT_5b41_2833;
          piVar15 = piVar15 + 1;
          puVar36 = DAT_5b41_2839;
        } while (*piVar15 != 0);
        *(int *)(puVar30 + -6) = (int)DAT_5b41_2839 - DAT_5b41_2835;
        DAT_5b41_282f = *(int *)(puVar30 + -6) + ((int)DAT_5b41_2837 + (0xf - DAT_5b41_2833) >> 4);
        *(undefined2 *)(puVar30 + -8) = *(undefined2 *)**(undefined2 **)(puVar30 + 6);
        pcVar6 = (code *)swi(0x21);
        (*pcVar6)();
        FUN_1000_130c(DAT_5b41_283f);
        return (int *)(undefined4 *)((int)piVar23 + (*(int *)(puVar30 + -6) * 0x10 - iVar32));
      case (int *)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (int *)0x2:
        *(char *)(int *)((int)puVar22 + (int)piVar15) =
             (char)*(int *)((int)puVar22 + (int)piVar15) + '\x01';
        if (puVar36 != (undefined4 *)0xf6) {
          puVar22 = puVar22 + -1;
          *(uint **)(puVar30 + 2) = puVar22;
        }
        if ((*puVar22 & 1) == 0) {
          puVar36 = (undefined4 *)((int)piVar35 >> 1);
        }
        else {
          puVar36 = (undefined4 *)((uint)piVar35 >> 1 | (uint)(((uint)in_DX & 1) != 0) << 0xf);
        }
        return (int *)puVar36;
      case (int *)0x3:
        do {
          iVar32 = 0xb;
          while( true ) {
            while( true ) {
              do {
                uVar12 = (undefined2)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10);
                iVar9 = (int)*(undefined4 *)(puVar30 + -4);
                uVar42 = *(undefined2 *)(iVar9 + 0x8c);
                *(undefined2 *)(puVar30 + -2) = *(undefined2 *)(iVar9 + 0x8e);
                *(undefined2 *)(puVar30 + -4) = uVar42;
                if ((*(int *)(puVar30 + -4) == 0 && *(int *)(puVar30 + -2) == 0) || (iVar32 != 0)) {
                  uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
                  iVar9 = (int)*(undefined4 *)(puVar30 + 6);
                  if (((int *)*(undefined2 *)(iVar9 + 0xae) != piVar15) ||
                     (*(int *)(iVar9 + 0xb4) != iVar32)) {
                    FUN_2424_3746(*(undefined2 *)(puVar30 + 6),*(undefined2 *)(puVar30 + 8),1);
                    FUN_2424_3746(*(undefined2 *)(puVar30 + 6),*(undefined2 *)(puVar30 + 8),2);
                    uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
                    iVar9 = (int)*(undefined4 *)(puVar30 + 6);
                    *(undefined2 *)(iVar9 + 0xae) = piVar15;
                    *(int *)(iVar9 + 0xb4) = iVar32;
                    FUN_2424_3746(iVar9,*(undefined2 *)(puVar30 + 8),1);
                    FUN_2424_3746(*(undefined2 *)(puVar30 + 6),*(undefined2 *)(puVar30 + 8),2);
                  }
                  uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
                  iVar9 = (int)*(undefined4 *)(puVar30 + 6);
                  *(undefined2 *)(iVar9 + 0xae) = piVar15;
                  *(int *)(iVar9 + 0xb4) = iVar32;
                  if ((piVar15 == (int *)0x0) && (iVar32 == 0)) {
                    puVar36 = (undefined4 *)0x0;
                  }
                  else {
                    puVar36 = (undefined4 *)0x1;
                  }
                  return (int *)puVar36;
                }
                iVar9 = (int)*(undefined4 *)(puVar30 + -4);
              } while ((*(int *)(iVar9 + 0x4a) != 0x10) ||
                      (iVar9 = FUN_2424_4087(iVar9,*(undefined2 *)(puVar30 + -2)), iVar9 == 0));
              if (*(int *)((int)*(undefined4 *)(puVar30 + -4) + 0x22) !=
                  *(int *)((int)*(undefined4 *)(puVar30 + 6) + 0x22)) break;
              iVar32 = 10;
            }
            uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10);
            iVar32 = (int)*(undefined4 *)(puVar30 + -4);
            uVar12 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
            iVar9 = (int)*(undefined4 *)(puVar30 + 6);
            if (*(int *)(iVar32 + 0x22) + *(int *)(iVar32 + 0x48) !=
                *(int *)(iVar9 + 0x22) + *(int *)(iVar9 + 0x48)) break;
            iVar32 = 0xc;
          }
        } while( true );
      case (int *)0x4:
        while( true ) {
          FUN_3e34_0ec9(puVar22,*(undefined2 *)(puVar30 + -2),piVar15,piVar34,0,uVar24);
          piVar15 = (int *)((int)piVar15 + *(int *)((int)*(undefined4 *)(puVar30 + -4) + 6));
          if (*(int *)(puVar30 + -0xc) <= (int)piVar15) break;
          puVar22 = (uint *)*(uint **)(puVar30 + -4);
          uVar24 = puVar22[3];
        }
        puVar36 = (undefined4 *)FUN_2424_02ca();
        return (int *)puVar36;
      case (int *)0x5:
        (puVar30 + (int)piVar34)[0xe46] =
             (puVar30 + (int)piVar34)[0xe46] + (char)in_CX + CARRY2((uint)piVar23,(uint)piVar23);
        uVar24 = *(uint *)(puVar30 + 0x12) + *(uint *)(puVar30 + 10);
        *(uint *)(puVar30 + -6) =
             ((*(int *)(puVar30 + 0x14) + *(int *)(puVar30 + 0xc) +
              (uint)CARRY2(*(uint *)(puVar30 + 0x12),*(uint *)(puVar30 + 10))) -
             ((int)in_DX << 1 | (uint)CARRY2((uint)puVar36,(uint)puVar36))) -
             (uint)(uVar24 < (uint)((int)puVar36 * 2));
        *(uint *)(puVar30 + -8) = uVar24 + (int)puVar36 * -2;
        uVar24 = *(uint *)(puVar30 + 0x1a);
        uVar18 = *(uint *)(puVar30 + 0x1e) + *(uint *)(puVar30 + 0x16);
        *(uint *)(puVar30 + -10) =
             ((*(int *)(puVar30 + 0x20) + *(int *)(puVar30 + 0x18) +
              (uint)CARRY2(*(uint *)(puVar30 + 0x1e),*(uint *)(puVar30 + 0x16))) -
             (*(int *)(puVar30 + 0x1c) << 1 | (uint)CARRY2(uVar24,uVar24))) -
             (uint)(uVar18 < uVar24 * 2);
        *(uint *)(puVar30 + -0xc) = uVar18 + uVar24 * -2;
        iVar32 = (*(int *)(puVar30 + 0x10) - *(int *)(puVar30 + 0xc)) -
                 (uint)(*(uint *)(puVar30 + 0xe) < *(uint *)(puVar30 + 10));
        uVar42 = FUN_1000_199e();
        *(int *)(puVar30 + -0xe) = iVar32;
        *(undefined2 *)(puVar30 + -0x10) = uVar42;
        in_DX = (undefined4 *)
                ((*(int *)(puVar30 + 0x1c) - *(int *)(puVar30 + 0x18)) -
                (uint)(*(uint *)(puVar30 + 0x1a) < *(uint *)(puVar30 + 0x16)));
        puVar29 = puVar30;
        break;
      default:
        puVar16 = (undefined4 *)CONCAT11(cVar17,*(char *)&DAT_554c_5596);
        if (*(char *)&DAT_554c_5596 == '\0') {
          *(undefined1 *)&DAT_554c_5595 = (char)puVar22;
          *(undefined2 *)&DAT_554c_5178 = in_CX;
          *(uint *)&DAT_554c_517a = (uint)in_DX;
          puVar16 = (undefined4 *)CONCAT11(cVar17,*(char *)&DAT_554c_5596);
          if ((*(char *)&DAT_554c_5596 == '\0') &&
             (puVar16 = (undefined4 *)0x0,
             *(int *)&DAT_554c_517c != 0 || *(int *)&DAT_554c_517e != 0)) {
            *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + '\x01';
            *(undefined2 *)&DAT_554c_557e = 0x2000;
            *(undefined2 *)&DAT_554c_557c = 0x2fe;
            FUN_1a9e_5938();
            uVar42 = ((undefined2 *)&DAT_554c_517c)[1];
            pcVar5 = (code *)*(undefined2 *)&DAT_554c_517c;
            *(undefined2 *)&DAT_554c_557e = 0x2000;
            puVar26 = (undefined2 *)&DAT_554c_557c;
            *(undefined2 *)&DAT_554c_557c = 0x303;
            (*pcVar5)();
            *(undefined2 *)((int)puVar26 + -2) = 0x2000;
            *(undefined2 *)((int)puVar26 + -4) = 0x307;
            puVar16 = (undefined4 *)FUN_1a9e_599d();
            *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + -1;
          }
        }
        return (int *)puVar16;
      case (int *)0x7:
        return (int *)puVar36;
      case (int *)0x8:
        iVar27 = *(int *)(puVar30 + (int)piVar34 + 0x6bf8) * -0x15;
        puVar36 = *(undefined4 **)(puVar30 + 6);
        if ((*(int *)(puVar30 + 8) == DAT_5b41_0ca2) && (puVar36 == DAT_5b41_0ca0)) {
          DAT_5b41_0cb9 = 0;
        }
        else {
          puVar36 = *(undefined4 **)(puVar30 + 6);
          if ((*(int *)(puVar30 + 8) == DAT_5b41_0c9e) && (puVar36 == DAT_5b41_0c9c)) {
            DAT_5b41_0cbb = 0;
          }
          else {
            *(undefined2 *)(iVar27 + -2) = *(undefined2 *)(puVar30 + 8);
            *(undefined2 *)(iVar27 + -4) = *(undefined2 *)(puVar30 + 6);
            *(undefined2 *)(iVar27 + -6) = 0x2000;
            *(undefined2 *)(iVar27 + -8) = 0xf845;
            puVar36 = (undefined4 *)FUN_22de_0351();
          }
        }
        return (int *)puVar36;
      case (int *)0x9:
        *(char *)(int *)((int)puVar22 + (int)piVar15) =
             (char)*(int *)((int)puVar22 + (int)piVar15) + cVar17;
        FUN_2424_4ae2(puVar22,*(undefined2 *)(puVar30 + 8));
        uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
        iVar32 = (int)*(undefined4 *)(puVar30 + 6);
        while( true ) {
          uVar12 = *(undefined2 *)(iVar32 + 0x8c);
          *(undefined2 *)(puVar30 + -2) = *(undefined2 *)(iVar32 + 0x8e);
          *(undefined2 *)(puVar30 + -4) = uVar12;
          if ((*(int *)(puVar30 + -4) == 0 && *(int *)(puVar30 + -2) == 0) ||
             (*(int *)(puVar30 + -6) != 0)) break;
          piStack_1a = (int *)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10);
          iVar32 = (int)*(undefined4 *)(puVar30 + -4);
          if (((*(int *)(iVar32 + 8) == 0x76) && (*(int *)(iVar32 + 0x4a) == 0x20)) &&
             (*(int *)(iVar32 + 0x24) == *(int *)((int)*(undefined4 *)(puVar30 + 6) + 0x24) + -0x20)
             ) {
            bVar39 = (*(byte *)(iVar32 + 0xc) & 0x30) != 0;
            if (((*(int *)(puVar30 + -10) != 0) || (bVar39)) ||
               (*(int *)((int)*(undefined4 *)(puVar30 + -4) + 0x22) !=
                *(int *)((int)*(undefined4 *)(puVar30 + 6) + 0x22))) {
              if (((*(int *)(puVar30 + -10) != 0) && (!bVar39)) &&
                 (uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10),
                 iVar32 = (int)*(undefined4 *)(puVar30 + -4),
                 uVar12 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10),
                 iVar9 = (int)*(undefined4 *)(puVar30 + 6),
                 *(int *)(iVar32 + 0x22) + *(int *)(iVar32 + 0x48) ==
                 *(int *)(iVar9 + 0x22) + *(int *)(iVar9 + 0x48))) {
                *(undefined2 *)(puVar30 + -6) = 9;
              }
            }
            else {
              *(undefined2 *)(puVar30 + -6) = 7;
            }
          }
          uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10);
          iVar32 = (int)*(undefined4 *)(puVar30 + -4);
        }
        uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
        iVar32 = (int)*(undefined4 *)(puVar30 + 6);
        piStack_1a = (int *)(*(int *)(iVar32 + 0x4a) + 0x10);
        piStack_1c = (int *)*(undefined2 *)(iVar32 + 0x4a);
        FUN_2424_4ae2(iVar32,*(undefined2 *)(puVar30 + 8),0x2000,0,0x10);
        uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
        iVar32 = (int)*(undefined4 *)(puVar30 + 6);
        while( true ) {
          uVar12 = *(undefined2 *)(iVar32 + 0x8c);
          *(undefined2 *)(puVar30 + -2) = *(undefined2 *)(iVar32 + 0x8e);
          *(undefined2 *)(puVar30 + -4) = uVar12;
          if ((*(int *)(puVar30 + -4) == 0 && *(int *)(puVar30 + -2) == 0) ||
             (*(int *)(puVar30 + -8) != 0)) break;
          uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10);
          iVar32 = (int)*(undefined4 *)(puVar30 + -4);
          if ((*(int *)(iVar32 + 8) == 0x76) && (*(int *)(iVar32 + 0x4a) == 0x20)) {
            uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
            iVar32 = (int)*(undefined4 *)(puVar30 + 6);
            uVar12 = (undefined2)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10);
            iVar9 = (int)*(undefined4 *)(puVar30 + -4);
            if (*(int *)(iVar32 + 0x24) + *(int *)(iVar32 + 0x4a) == *(int *)(iVar9 + 0x24)) {
              bVar39 = (*(byte *)(iVar9 + 0xc) & 0x30) == 0;
              if (((*(int *)(puVar30 + -10) != 0) || (bVar39)) ||
                 (*(int *)((int)*(undefined4 *)(puVar30 + -4) + 0x22) !=
                  *(int *)((int)*(undefined4 *)(puVar30 + 6) + 0x22))) {
                if (((*(int *)(puVar30 + -10) != 0) && (!bVar39)) &&
                   (uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10),
                   iVar32 = (int)*(undefined4 *)(puVar30 + -4),
                   uVar12 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10),
                   iVar9 = (int)*(undefined4 *)(puVar30 + 6),
                   *(int *)(iVar32 + 0x22) + *(int *)(iVar32 + 0x48) ==
                   *(int *)(iVar9 + 0x22) + *(int *)(iVar9 + 0x48))) {
                  *(undefined2 *)(puVar30 + -8) = 0xc;
                }
              }
              else {
                *(undefined2 *)(puVar30 + -8) = 10;
              }
            }
          }
          uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + -4) >> 0x10);
          iVar32 = (int)*(undefined4 *)(puVar30 + -4);
        }
        uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
        iVar32 = (int)*(undefined4 *)(puVar30 + 6);
        if ((*(int *)(iVar32 + 0xae) != *(int *)(puVar30 + -6)) ||
           (*(int *)(iVar32 + 0xb4) != *(int *)(puVar30 + -8))) {
          piStack_1a = (int *)0x1;
          piStack_1c = *(int **)(puVar30 + 8);
          FUN_2424_3746(*(undefined2 *)(puVar30 + 6));
          FUN_2424_3746(*(undefined2 *)(puVar30 + 6),*(undefined2 *)(puVar30 + 8),2);
          uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
          iVar32 = (int)*(undefined4 *)(puVar30 + 6);
          *(undefined2 *)(iVar32 + 0xae) = *(undefined2 *)(puVar30 + -6);
          *(undefined2 *)(iVar32 + 0xb4) = *(undefined2 *)(puVar30 + -8);
          FUN_2424_3746(iVar32,*(undefined2 *)(puVar30 + 8),1);
          FUN_2424_3746(*(undefined2 *)(puVar30 + 6),*(undefined2 *)(puVar30 + 8),2);
        }
        uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 6) >> 0x10);
        iVar32 = (int)*(undefined4 *)(puVar30 + 6);
        *(undefined2 *)(iVar32 + 0xae) = *(undefined2 *)(puVar30 + -6);
        *(undefined2 *)(iVar32 + 0xb4) = *(undefined2 *)(puVar30 + -8);
        if ((*(int *)(puVar30 + -6) == 0) && (*(int *)(puVar30 + -8) == 0)) {
          puVar36 = (undefined4 *)0x0;
        }
        else {
          puVar36 = (undefined4 *)0x1;
        }
        return (int *)puVar36;
      }
      break;
    case 7:
      while (piVar15 != piVar21) {
        if ((int)piVar15 <= (int)in_CX) {
          in_CX = piVar15;
        }
        do {
          piVar23 = in_CX;
          puVar41 = (undefined2 *)FUN_1a9e_5aa5();
          uVar42 = (undefined2)((ulong)puVar41 >> 0x10);
          puVar31 = (undefined2 *)puVar41;
          if (9 < (int)in_CX) {
            if ((POPCOUNT((uint)puVar31 & 0xff) & 1U) != 0) {
              puVar31 = (undefined2 *)((int)puVar31 + 1);
              *(undefined1 *)puVar41 = 0;
              in_CX = (int *)((int)in_CX + -1);
            }
            for (uVar24 = (uint)in_CX >> 1; uVar24 != 0; uVar24 = uVar24 - 1) {
              puVar41 = puVar31;
              puVar31 = puVar31 + 1;
              *puVar41 = 0;
            }
            in_CX = (int *)(uint)(((uint)in_CX & 1) != 0);
          }
          for (; in_CX != (int *)0x0; in_CX = (int *)((int)in_CX + -1)) {
            puVar41 = puVar31;
            puVar31 = (undefined2 *)((int)puVar31 + 1);
            *(undefined1 *)puVar41 = 0;
          }
          piVar15 = (int *)((int)param_3 - (int)piVar23);
          param_4 = param_4 - (uint)(param_3 < piVar23);
          piVar21 = (int *)0x0;
          in_CX = (int *)0x7d00;
          param_3 = piVar15;
        } while (param_4 != 0);
      }
      return piVar15;
    case 8:
      piStack_18 = (int *)0x0;
      piStack_1a = (int *)0x2000;
      piStack_1c = (int *)0x4616;
      func_0x00054aef();
      FUN_311b_0244();
      local_6 = DAT_5b41_0567;
      if (5000 < DAT_554c_2f1c) {
        DAT_5b41_0567 = (int *)0x0;
      }
      if (iRam000557bc != 7) {
        FUN_2424_10b2();
      }
      FUN_2424_0ff3();
      if (iRam000557bc != 7) {
        piStack_18 = (int *)0x465e;
        FUN_2424_20ab();
      }
      piStack_18 = (int *)0x4668;
      FUN_2424_184a();
      DAT_5b41_0505 = DAT_5b41_0505 + 1;
      if (((int *)DAT_5b41_0567 == (int *)0x0 && DAT_5b41_0567._2_2_ == (undefined4 *)0x0) ||
         (LAB_554c_02ee == -1)) {
        FUN_54f1_0043();
      }
      else {
        piStack_18 = (int *)DAT_5b41_0567._2_2_;
        piStack_1a = (int *)DAT_5b41_0567;
        piStack_1c = (int *)((char *)s_SIGNIN_RES_554c_3111 + 10);
        FUN_2424_2165();
        uVar42 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
        piVar15 = (int *)DAT_5b41_0567;
        if (((piVar15[4] == 0x16) || (piVar15[4] == 0x37)) &&
           (piVar15[0x31] != 0 || piVar15[0x32] != 0)) {
          piStack_18 = (int *)piVar15[0x32];
          piStack_1a = (int *)piVar15[0x31];
          piStack_1c = (int *)((char *)s_SIGNIN_RES_554c_3111 + 10);
          FUN_2424_2165();
        }
      }
      if (DAT_554c_02f0 != -1) {
        DAT_554c_42ce = (undefined1)DAT_554c_02f0;
        piStack_18 = (int *)(DAT_5b41_054b - DAT_5b41_0925);
        piStack_1a = (int *)(DAT_5b41_0549 - DAT_5b41_0927);
        piStack_1c = (int *)(DAT_5b41_0547 - DAT_5b41_0925);
        FUN_2424_276e();
        FUN_2424_1a04((undefined2 *)&DAT_5b41_0547,(undefined2 *)&DAT_5b41_054b,2);
      }
      if (5000 < DAT_554c_2f1c) {
        FUN_2424_196d();
        piStack_18 = (int *)0x4728;
        FUN_2424_184a();
      }
      FUN_2424_0304();
      piStack_18 = (int *)0x4736;
      FUN_460e_1314();
      FUN_2424_1650();
      DAT_5b41_0567 = local_6;
      return (int *)local_6;
    }
switchD_2000_81f0_caseD_7:
    puVar28 = puVar29;
    goto switchD_2000_81f0_caseD_a;
  }
LAB_2424_3f60:
  if (piVar23[0x5a] == 0) {
    return piVar15;
  }
  local_6 = (int *)CONCAT22(piVar23[0x5a],(int *)local_6);
  piStack_18 = (int *)((int)piVar35 + piVar23[0x5a] + -1);
  piStack_1a = (int *)local_6;
  uVar42 = 0x81c7;
  piStack_1c = piVar38;
  FUN_4551_03eb();
  puVar16 = (undefined4 *)(piVar23[0x12] - DAT_5b41_0927);
  local_e = (int *)CONCAT22((int)local_e._2_2_ + (int)puVar16,
                            (int *)((int)(int *)local_e + (piVar23[0x11] - DAT_5b41_0925)));
  if (10 < (int)local_6._2_2_ - 2U) {
    piStack_18 = (int *)&local_e;
    piStack_1a = (int *)0x4551;
    piStack_1c = (int *)0x8218;
    puVar36 = (undefined4 *)FUN_2424_1e00();
    return (int *)puVar36;
  }
  puVar33 = (undefined4 *)0x0;
  puVar29 = &stack0xfffe;
  puVar28 = &stack0xfffe;
  switch(local_6._2_2_) {
  case (undefined4 *)0x2:
    uVar8 = in(0x7a);
    *(undefined2 *)((int)piVar35 + 3) = *(undefined2 *)((int)piVar35 + 3);
    return (int *)CONCAT11((char)((uint)puVar16 >> 8),uVar8);
  case (undefined4 *)0x3:
    if (((int *)&local_e == piStack_1a) && (piStack_18 == piStack_1c)) {
      iVar9 = 0;
      iVar32 = 0;
      uStack_a._0_2_ = in_CX;
      uStack_a._2_2_ = piVar35;
    }
    else {
      iVar32 = piStack_1c[0x3b];
      iVar9 = *(int *)((int)puVar16 + 0x76);
      uStack_a._2_2_ = (int *)(1 - (int)in_CX);
      uStack_a._0_2_ = (int *)(1 - (int)piVar35);
    }
    if (*(int *)((int)(int *)uStack_a * 4 + iVar9 + 0x1e) < *(int *)((int)piVar35 * 4 + 0x1e)) {
      local_e._2_2_ = (undefined4 *)0x8;
    }
    else {
      local_e._2_2_ = (undefined4 *)0x10;
    }
    if (param_2 == 0) {
      if (*(int *)((int)uStack_a._2_2_ * 4 + iVar32 + 0x20) < *(int *)((int)in_CX * 4 + 0x20)) {
        return (int *)(undefined4 *)0x1;
      }
      if (*(int *)((int)piVar35 * 4 + 0x20) < *(int *)((int)(int *)uStack_a * 4 + iVar9 + 0x20)) {
LAB_28eb_391e:
        return (int *)(undefined4 *)((uint)local_e._2_2_ | 4);
      }
    }
    else {
      if (*(int *)((int)in_CX * 4 + 0x20) < *(int *)((int)uStack_a._2_2_ * 4 + iVar32 + 0x20)) {
        return (int *)(undefined4 *)0x1;
      }
      if (*(int *)((int)piVar35 * 4 + 0x20) <= *(int *)((int)(int *)uStack_a * 4 + iVar9 + 0x20))
      goto LAB_28eb_391e;
    }
    return (int *)(undefined4 *)((uint)local_e._2_2_ | 2);
  case (undefined4 *)0x4:
    do {
      iVar32 = FUN_28eb_03ff();
      if (iVar32 == 0) {
        local_e = uStack_a;
        DAT_5b41_04ec = (int *)FUN_28eb_0728();
        DAT_5b41_04ee = in_DX;
      }
      do {
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                do {
                  while( true ) {
                    local_e._2_2_ = (undefined4 *)0x1000;
                    local_e._0_2_ = (int *)local_6._2_2_;
                    piVar15 = (int *)FUN_28eb_32d8();
                    local_6 = (int *)CONCAT22(in_DX,piVar15);
                    if (piVar15 == (int *)0x0 && in_DX == (undefined4 *)0x0) {
                      if ((int *)local_e != (int *)0x0 || local_e._2_2_ != (undefined4 *)0x0) {
                        return (int *)(undefined4 *)(int *)local_e;
                      }
                      return (int *)(undefined4 *)0x0;
                    }
                    local_e._0_2_ = piVar15;
                    local_e._2_2_ = in_DX;
                    piVar15 = (int *)FUN_28eb_0a36();
                    puVar16 = local_e._2_2_;
                    uStack_a = (int *)CONCAT22(in_DX,piVar15);
                    if (((((piVar15 != (int *)0x0 || in_DX != (undefined4 *)0x0) &&
                          ((*(byte *)((int)piVar15 + 0xb) & 0x80) != 0)) && (iRam000557bc != 3)) &&
                        (piVar23 != (int *)0x0 || puVar36 != (undefined4 *)0x0)) &&
                       ((puVar36 != in_DX || (in_DX = puVar36, piVar23 != piVar15)))) {
                      uStack_a = (int *)0x0;
                      in_DX = puVar36;
                    }
                    if ((((int *)uStack_a == (int *)0x0 && uStack_a._2_2_ == (int *)0x0) ||
                        (((int *)uStack_a)[0x4c] != 0)) ||
                       (((int *)local_e == (int *)0x0 && local_e._2_2_ == (undefined4 *)0x0 ||
                        (((int *)local_e)[0x4c] != 0)))) break;
                    if ((((int *)local_e == (int *)0x0 && local_e._2_2_ == (undefined4 *)0x0) ||
                        (in_DX = local_e._2_2_, local_e._2_2_ != DAT_5b41_0567._2_2_)) ||
                       ((int *)local_e != (int *)DAT_5b41_0567)) {
                      puVar16 = in_DX;
                      if ((((int *)uStack_a == (int *)0x0 && uStack_a._2_2_ == (int *)0x0) ||
                          (puVar16 = (undefined4 *)uStack_a._2_2_,
                          uStack_a._2_2_ != (int *)DAT_5b41_0567._2_2_)) ||
                         ((int *)uStack_a != (int *)DAT_5b41_0567)) {
                        local_e = uStack_a;
                        local_e._2_2_ = (undefined4 *)FUN_28eb_0d77();
                        local_e._0_2_ = (int *)puVar16;
                        puVar33 = (undefined4 *)FUN_28eb_0d77();
                        in_DX = local_e._2_2_;
                        if (((int)(int *)local_e <= (int)puVar16) &&
                           (((int)(int *)local_e < (int)puVar16 ||
                            (in_DX = local_e._2_2_, local_e._2_2_ < puVar33)))) {
                          DAT_5b41_04ee = (undefined4 *)uStack_a._2_2_;
                          DAT_5b41_04ec = (int *)uStack_a;
                          in_DX = (undefined4 *)uStack_a._2_2_;
                        }
                      }
                      else {
                        local_e = uStack_a;
                        local_e._2_2_ = (undefined4 *)FUN_28eb_0d77();
                        local_e._0_2_ = (int *)puVar16;
                        uVar24 = FUN_28eb_0d77();
                        in_DX = (undefined4 *)uStack_a._2_2_;
                        if (((int)(int *)local_e <= (int)puVar16) &&
                           (((int)(int *)local_e < (int)puVar16 || (local_e._2_2_ < uVar24)))) {
                          DAT_5b41_04ee = (undefined4 *)uStack_a._2_2_;
                          DAT_5b41_04ec = (int *)uStack_a;
                        }
                      }
                    }
                    else {
                      local_e = uStack_a;
                      local_e._2_2_ = (undefined4 *)FUN_28eb_0d77();
                      local_e._0_2_ = (int *)puVar16;
                      puVar33 = (undefined4 *)FUN_28eb_0d77();
                      in_DX = local_e._2_2_;
                      if (((int)(int *)local_e <= (int)puVar16) &&
                         (((int)(int *)local_e < (int)puVar16 ||
                          (in_DX = local_e._2_2_, local_e._2_2_ < puVar33)))) {
                        DAT_5b41_04ee = (undefined4 *)uStack_a._2_2_;
                        DAT_5b41_04ec = (int *)uStack_a;
                        in_DX = (undefined4 *)uStack_a._2_2_;
                      }
                    }
                  }
                } while ((int *)uStack_a == (int *)0x0 && uStack_a._2_2_ == (int *)0x0);
                if ((((int *)local_e == (int *)0x0 && local_e._2_2_ == (undefined4 *)0x0) ||
                    (local_e._2_2_ != DAT_5b41_0567._2_2_)) ||
                   ((int *)local_e != (int *)DAT_5b41_0567)) break;
                local_e = uStack_a;
                iVar32 = FUN_28eb_03ff();
                in_DX = puVar16;
                if (iVar32 != 0) {
                  local_e = uStack_a;
                  DAT_5b41_04ec = (int *)FUN_28eb_0728();
                  in_DX = puVar16;
                  DAT_5b41_04ee = puVar16;
                }
              }
              if ((uStack_a._2_2_ != (int *)DAT_5b41_0567._2_2_) ||
                 ((int *)uStack_a != (int *)DAT_5b41_0567)) break;
              iVar32 = FUN_28eb_03ff();
              in_DX = (undefined4 *)uStack_a._2_2_;
              if (iVar32 == 0) {
                DAT_5b41_04ee = (undefined4 *)uStack_a._2_2_;
                DAT_5b41_04ec = (int *)uStack_a;
              }
            }
            in_DX = (undefined4 *)uStack_a._2_2_;
            if (((int *)local_e != (int *)0x0 || local_e._2_2_ != (undefined4 *)0x0) &&
               ((*(byte *)((int)(int *)uStack_a + 0xb) & 0x80) == 0)) break;
            DAT_5b41_04ee = (undefined4 *)uStack_a._2_2_;
            DAT_5b41_04ec = (int *)uStack_a;
            if ((((((*(byte *)((int)(int *)uStack_a + 0xb) & 0x80) == 0) || (iRam000557bc == 3)) ||
                 (((int *)DAT_5b41_0567 != (int *)0x0 || DAT_5b41_0567._2_2_ != (undefined4 *)0x0 &&
                  (((int *)DAT_5b41_0567)[4] == 10)))) ||
                (((int *)DAT_5b41_0567 != (int *)0x0 || DAT_5b41_0567._2_2_ != (undefined4 *)0x0 &&
                 (((int *)DAT_5b41_0567)[4] == 0x4c)))) ||
               (((int *)DAT_5b41_0567 != (int *)0x0 || DAT_5b41_0567._2_2_ != (undefined4 *)0x0 &&
                (((int *)DAT_5b41_0567)[4] == 8)))) {
              local_e = uStack_a;
              FUN_28eb_0728();
            }
          }
          if (((int *)uStack_a)[0x4c] != 0) break;
LAB_28eb_1038:
          in_DX = (undefined4 *)uStack_a._2_2_;
          DAT_5b41_04ec = (int *)uStack_a;
          DAT_5b41_04ee = (undefined4 *)uStack_a._2_2_;
        }
        local_e._0_2_ = (int *)uStack_a;
        local_e._2_2_ = (undefined4 *)uStack_a._2_2_;
        iVar32 = FUN_28eb_03ff();
        if (iVar32 != 0) goto LAB_28eb_1038;
      } while (((int *)local_e)[0x4c] == 0);
    } while( true );
  case (undefined4 *)0x5:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (undefined4 *)0x6:
    return (int *)puVar16;
  case (undefined4 *)0x7:
    goto switchD_2000_81f0_caseD_7;
  case (undefined4 *)0x8:
switchD_2000_81f0_caseD_8:
    puVar33 = (undefined4 *)((uint)puVar33 | 0x3000);
    break;
  case (undefined4 *)0x9:
    if ((*(byte *)((int)piVar23 + 0xf) & 0x10) == 0) {
      if ((*(byte *)(piVar23 + 7) & 0x40) == 0) {
        puVar33 = (undefined4 *)0x10;
      }
      else {
        puVar33 = (undefined4 *)0x400;
      }
    }
    if (((*(byte *)((int)piVar23 + 0xf) & 0x10) == 0) && ((DAT_5b41_051f & 0x10) == 0)) {
      puVar33 = (undefined4 *)((uint)puVar33 | 0x20);
    }
    if ((*(byte *)((int)piVar23 + 0xf) & 0x10) != 0) goto switchD_2000_81f0_caseD_8;
    break;
  case (undefined4 *)0xa:
    goto switchD_2000_81f0_caseD_a;
  case (undefined4 *)0xb:
    puVar16 = (undefined4 *)0x0;
    piVar15 = (int *)(((int)local_6._2_2_ - 2U) * 2);
    puVar33 = SUB42(s_String_reference_out_of_range_554c_5eb4._16_4_,2);
    goto code_r0x0002a3ab;
  case (undefined4 *)0xc:
    out(uRam000554c0,in_DX);
code_r0x00029a69:
    *(int *)(puVar30 + -0xc) = *(int *)(puVar30 + -0xc) + 0x23;
    *(int *)(puVar30 + -0xe) = *(int *)(puVar30 + -0xe) + 0x23;
    piVar34 = piVar35;
LAB_28eb_0bc1:
    if ((((*(int *)(puVar30 + -6) < (int)piVar34) ||
         (*(int *)(puVar30 + -0xc) <= *(int *)(puVar30 + -2))) ||
        (*(int *)(puVar30 + -8) < *(int *)(puVar30 + -10))) ||
       (*(int *)(puVar30 + -0xe) <= *(int *)(puVar30 + -4))) {
      puVar36 = (undefined4 *)0x0;
    }
    else {
      if ((*(int *)(puVar30 + -0x16) != 0) && (DAT_5b41_0939 != 9)) {
        uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 10) >> 0x10);
        iVar9 = (int)*(undefined4 *)(puVar30 + 10);
        iVar32 = ((uint)*(byte *)(iVar9 + 0x5a) + *(int *)(puVar30 + -0x14)) -
                 *(int *)(iVar9 + 0x5c);
        *(uint *)(puVar30 + -10) =
             ((uint)*(byte *)(iVar9 + 0x5b) + *(int *)(puVar30 + -0x12)) - *(int *)(iVar9 + 0x5c);
        *(int *)(puVar30 + -0xc) = *(int *)(iVar9 + 0x5c) * 2 + iVar32;
        *(int *)(puVar30 + -0xe) = *(int *)(iVar9 + 0x5c) * 2 + *(int *)(puVar30 + -10);
        if ((*(int *)(*(int *)(puVar30 + -0x16) + 4) == *(int *)(puVar30 + 8)) &&
           (*(int *)(*(int *)(puVar30 + -0x16) + 2) == *(int *)(puVar30 + 6))) {
          iVar32 = iVar32 + -0x23;
          *(int *)(puVar30 + -10) = *(int *)(puVar30 + -10) + -0x23;
          *(int *)(puVar30 + -0xc) = *(int *)(puVar30 + -0xc) + 0x23;
        }
        if (((iVar32 <= *(int *)(puVar30 + -6)) &&
            (*(int *)(puVar30 + -2) < *(int *)(puVar30 + -0xc))) &&
           ((*(int *)(puVar30 + -10) <= *(int *)(puVar30 + -8) &&
            (*(int *)(puVar30 + -4) < *(int *)(puVar30 + -0xe))))) {
          iVar32 = *(int *)(puVar30 + -0x16);
          if ((*(int *)(iVar32 + 8) == *(int *)(puVar30 + 0xc)) &&
             (*(int *)(iVar32 + 6) == *(int *)(puVar30 + 10))) {
            uVar42 = *(undefined2 *)(iVar32 + 10);
            *(undefined2 *)(iVar32 + 8) = *(undefined2 *)(iVar32 + 0xc);
            *(undefined2 *)(iVar32 + 6) = uVar42;
            uVar42 = *(undefined2 *)(puVar30 + 10);
            *(undefined2 *)(iVar32 + 0xc) = *(undefined2 *)(puVar30 + 0xc);
            *(undefined2 *)(iVar32 + 10) = uVar42;
          }
          return (int *)(undefined4 *)*(undefined2 *)(*(int *)(puVar30 + -0x16) + 2);
        }
      }
      piVar15 = *(int **)(puVar30 + -0x18);
      *(undefined2 *)(puVar30 + -0x10) = 0;
      while (*(int *)(puVar30 + -0x10) < 2) {
        if ((piVar15 != (int *)0x0) && (DAT_5b41_0939 != 9)) {
          uVar42 = (undefined2)((ulong)*(undefined4 *)(puVar30 + 10) >> 0x10);
          iVar32 = (int)*(undefined4 *)(puVar30 + 10);
          if (*(int *)(iVar32 + 8) != 7) {
            iVar32 = iVar32 + *(int *)(puVar30 + -0x10) * 2;
            iVar9 = (int)*(char *)(iVar32 + 0x7a) + *(int *)(puVar30 + -0x14);
            iVar10 = iVar9 + -8;
            *(int *)(puVar30 + -10) = (int)*(char *)(iVar32 + 0x7b) + *(int *)(puVar30 + -0x12) + -4
            ;
            *(int *)(puVar30 + -0xc) = iVar9 + 8;
            *(int *)(puVar30 + -0xe) = *(int *)(puVar30 + -10) + 8;
            if ((piVar15[1] == *(int *)(puVar30 + 8)) && (*piVar15 == *(int *)(puVar30 + 6))) {
              iVar10 = iVar9 + -0x2b;
              *(int *)(puVar30 + -10) = *(int *)(puVar30 + -10) + -0x23;
              *(int *)(puVar30 + -0xc) = *(int *)(puVar30 + -0xc) + 0x23;
            }
            if ((((iVar10 <= *(int *)(puVar30 + -6)) &&
                 (*(int *)(puVar30 + -2) < *(int *)(puVar30 + -0xc))) &&
                (*(int *)(puVar30 + -10) <= *(int *)(puVar30 + -8))) &&
               (*(int *)(puVar30 + -4) < *(int *)(puVar30 + -0xe))) {
              if ((piVar15[3] == *(int *)(puVar30 + 0xc)) && (piVar15[2] == *(int *)(puVar30 + 10)))
              {
                FUN_28eb_08be(piVar15);
              }
              return (int *)(undefined4 *)*piVar15;
            }
          }
        }
        piVar15 = *(int **)(puVar30 + -0x1a);
        *(int *)(puVar30 + -0x10) = *(int *)(puVar30 + -0x10) + 1;
      }
      puVar36 = *(undefined4 **)(puVar30 + 10);
    }
    return (int *)puVar36;
  }
  if ((*(byte *)(piVar23 + 7) & 0x40) != 0) {
    return (int *)puVar33;
  }
  puVar16 = (undefined4 *)((uint)puVar33 | 0x140);
  if (piVar23[4] == 8) {
    return (int *)puVar16;
  }
  if (piVar23[4] == 10) {
    return (int *)puVar16;
  }
  if (piVar23[4] == 0x4c) {
    return (int *)puVar16;
  }
  if ((*(byte *)(piVar23 + 6) & 0x80) != 0) {
    puVar16 = (undefined4 *)((uint)puVar33 | 0x141);
  }
  if ((*(byte *)((int)piVar23 + 0xd) & 1) != 0) {
    puVar16 = (undefined4 *)((uint)puVar16 | 2);
  }
  if (((*(byte *)((int)piVar23 + 0xb) & 4) == 0) || ((*(byte *)((int)piVar23 + 0xb) & 2) == 0)) {
    if ((*(byte *)((int)piVar23 + 0xb) & 4) != 0) {
      if (DAT_5b41_0939 == 9) {
        puVar16 = (undefined4 *)((uint)puVar16 | 4);
      }
      else {
        DAT_5b41_050f = 1;
        puVar41 = (undefined2 *)(*(int *)(piVar23[4] * 2 + 0x302) + 0xc);
        piStack_1a = (int *)0x2000;
        piStack_1c = (int *)0xa305;
        piStack_18 = piVar23;
        (*(code *)*puVar41)();
        piVar23[0x56] = piVar23[6];
        piStack_18 = (int *)0x2000;
        piStack_1a = (int *)0xa31c;
        iVar32 = FUN_28eb_0119();
        if (iVar32 == 0) {
          if (piVar23[0x2c] != 0) {
            piStack_18 = (int *)0xa336;
            iVar32 = FUN_28eb_1c08();
            if (iVar32 == 0) goto LAB_28eb_1490;
          }
          puVar16 = (undefined4 *)((uint)puVar16 | 4);
        }
LAB_28eb_1490:
        puVar41 = (undefined2 *)(*(int *)(piVar23[4] * 2 + 0x302) + 0xc);
        piStack_1a = (int *)0x2000;
        piStack_1c = (int *)0xa358;
        piStack_18 = piVar23;
        (*(code *)*puVar41)();
        piVar23[0x56] = piVar23[6];
        DAT_5b41_050f = 0;
      }
    }
    if ((*(byte *)((int)piVar23 + 0xb) & 2) == 0) goto LAB_28eb_155d;
    if (DAT_5b41_0939 == 9) {
      puVar16 = (undefined4 *)((uint)puVar16 | 8);
      goto LAB_28eb_155d;
    }
    DAT_5b41_050f = 1;
    puVar41 = (undefined2 *)(*(int *)(piVar23[4] * 2 + 0x302) + 0xc);
    piStack_1a = (int *)0x2000;
    piStack_1c = (int *)0xa3a5;
    piStack_18 = piVar23;
    (*(code *)*puVar41)();
    piVar15 = piVar23;
    puVar33 = puVar36;
code_r0x0002a3ab:
    piVar15[0x56] = piVar15[6];
    piStack_18 = (int *)0x2000;
    piStack_1a = (int *)0xa3bc;
    iVar32 = FUN_28eb_0119();
    if (iVar32 == 0) {
      if (piVar23[0x2c] != 0) {
        piStack_18 = (int *)0xa3d6;
        iVar32 = FUN_28eb_1c08();
        if (iVar32 == 0) goto LAB_28eb_1530;
      }
      puVar16 = (undefined4 *)((uint)puVar16 | 8);
    }
LAB_28eb_1530:
    puVar41 = (undefined2 *)(*(int *)(piVar23[4] * 2 + 0x302) + 0xc);
    piStack_1a = (int *)0x2000;
    piStack_1c = (int *)0xa3f8;
    piStack_18 = piVar23;
    (*(code *)*puVar41)();
    piVar23[0x56] = piVar23[6];
  }
  else {
    if (DAT_5b41_0939 == 9) {
      puVar16 = (undefined4 *)((uint)puVar16 | 0xc);
      goto LAB_28eb_155d;
    }
    local_6._2_2_ = (undefined4 *)piVar23[8];
    local_6._0_2_ = (int *)piVar23[6];
    DAT_5b41_050f = 1;
    bVar39 = false;
    do {
      puVar41 = (undefined2 *)(*(int *)(piVar23[4] * 2 + 0x302) + 0xc);
      piStack_1a = (int *)0x2000;
      piStack_1c = (int *)0xa248;
      piStack_18 = piVar23;
      (*(code *)*puVar41)();
      piVar23[0x56] = piVar23[6];
      if (((undefined4 *)piVar23[8] == local_6._2_2_) && ((int *)piVar23[6] == (int *)local_6)) {
LAB_28eb_13e7:
        bVar39 = true;
      }
      else {
        piStack_18 = (int *)0x2000;
        piStack_1a = (int *)0xa273;
        iVar32 = FUN_28eb_0119();
        if (iVar32 == 0) {
          if (piVar23[0x2c] != 0) {
            piStack_18 = (int *)0xa28d;
            iVar32 = FUN_28eb_1c08();
            if (iVar32 == 0) goto LAB_28eb_13ea;
          }
          puVar16 = (undefined4 *)((uint)puVar16 | 0xc);
          goto LAB_28eb_13e7;
        }
      }
LAB_28eb_13ea:
    } while (!bVar39);
    piVar23[8] = (int)local_6._2_2_;
    piVar23[6] = (int)(int *)local_6;
    piVar23[0x56] = (int)(int *)local_6;
    puVar41 = (undefined2 *)(*(int *)(piVar23[4] * 2 + 0x302) + 0xc);
    piStack_1a = (int *)0x2000;
    piStack_1c = (int *)0xa2c7;
    piStack_18 = piVar23;
    (*(code *)*puVar41)();
  }
  DAT_5b41_050f = 0;
LAB_28eb_155d:
  if ((*(byte *)((int)piVar23 + 0xf) & 4) != 0) {
    if (((uint)puVar16 & 1) == 0) {
      puVar16 = (undefined4 *)((uint)puVar16 | 0x80);
    }
    else {
      puVar16 = (undefined4 *)((uint)puVar16 | 0x800);
    }
  }
  if (((iRam000557bc == 1) || (iRam000557bc == 6)) && ((*(byte *)((int)piVar23 + 0xf) & 0x80) != 0))
  {
    puVar16 = (undefined4 *)((uint)puVar16 | 0x200);
  }
  return (int *)puVar16;
switchD_2000_81f0_caseD_a:
  uVar42 = FUN_1000_199e();
  *(undefined4 **)(puVar28 + -0x12) = in_DX;
  *(undefined2 *)(puVar28 + -0x14) = uVar42;
  iVar32 = *(int *)(puVar28 + 8);
  *(int *)(puVar28 + -0x26) = iVar32 * 2 >> 0xf;
  *(int *)(puVar28 + -0x28) = iVar32 * 2;
  uVar42 = *(undefined2 *)(puVar28 + 0xc);
  uVar12 = FUN_1000_199e();
  *(undefined2 *)(puVar28 + -0x16) = uVar42;
  *(undefined2 *)(puVar28 + -0x18) = uVar12;
  uVar42 = *(undefined2 *)(puVar28 + 0x18);
  uVar12 = FUN_1000_199e();
  *(undefined2 *)(puVar28 + -0x1a) = uVar42;
  *(undefined2 *)(puVar28 + -0x1c) = uVar12;
  iVar32 = 1 << (puVar28[8] & 0x1f);
  *(int *)(puVar28 + -0x22) = iVar32 >> 0xf;
  *(int *)(puVar28 + -0x24) = iVar32;
  uVar42 = FUN_1000_19bf();
  *(undefined2 *)(puVar28 + -2) = uVar42;
  uVar42 = FUN_1000_19bf();
  *(undefined2 *)(puVar28 + -4) = uVar42;
  *(undefined2 *)(puVar28 + -0x1e) = 0;
  *(undefined2 *)(puVar28 + -0x20) = 0;
  while( true ) {
    if ((*(int *)(puVar28 + -0x22) <= *(int *)(puVar28 + -0x1e)) &&
       ((*(int *)(puVar28 + -0x22) < *(int *)(puVar28 + -0x1e) ||
        (*(undefined4 **)(puVar28 + -0x24) < *(undefined4 **)(puVar28 + -0x20))))) break;
    iVar32 = FUN_1000_19bf();
    iVar9 = FUN_1000_19bf();
    if ((*(int *)(puVar28 + -2) != iVar32) || (*(int *)(puVar28 + -4) != iVar9)) {
      FUN_2424_27e0(*(undefined2 *)(puVar28 + -2),*(undefined2 *)(puVar28 + -4),iVar32,iVar9);
      *(int *)(puVar28 + -2) = iVar32;
      *(int *)(puVar28 + -4) = iVar9;
    }
    iVar32 = *(int *)(puVar28 + -6);
    uVar13 = FUN_1000_180a();
    uVar18 = *(uint *)(puVar28 + -0x10);
    uVar14 = uVar13 + *(uint *)(puVar28 + -0x10);
    iVar9 = *(int *)(puVar28 + -0xe);
    puVar1 = (uint *)(puVar28 + -0x18);
    uVar24 = *puVar1;
    *puVar1 = *puVar1 + uVar14;
    *(uint *)(puVar28 + -0x16) =
         *(int *)(puVar28 + -0x16) + iVar32 + iVar9 + (uint)CARRY2(uVar13,uVar18) +
         (uint)CARRY2(uVar24,uVar14);
    iVar32 = *(int *)(puVar28 + -10);
    uVar13 = FUN_1000_180a();
    uVar18 = *(uint *)(puVar28 + -0x14);
    uVar14 = uVar13 + *(uint *)(puVar28 + -0x14);
    iVar9 = *(int *)(puVar28 + -0x12);
    puVar1 = (uint *)(puVar28 + -0x1c);
    uVar24 = *puVar1;
    *puVar1 = *puVar1 + uVar14;
    *(uint *)(puVar28 + -0x1a) =
         *(int *)(puVar28 + -0x1a) + iVar32 + iVar9 + (uint)CARRY2(uVar13,uVar18) +
         (uint)CARRY2(uVar24,uVar14);
    puVar1 = (uint *)(puVar28 + -0x20);
    uVar24 = *puVar1;
    *puVar1 = *puVar1 + 1;
    *(uint *)(puVar28 + -0x1e) = *(int *)(puVar28 + -0x1e) + (uint)(0xfffe < uVar24);
  }
  return (int *)*(undefined4 **)(puVar28 + -0x20);
}

