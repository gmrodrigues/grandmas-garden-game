// TIM2.EXE: FUN_31f7_6f49 @ file 0x03E0B9 Ghidra 0x38EB9
// Subsystem: misc | Size: 260 bytes


/* WARNING: Instruction at (ram,0x00030211) overlaps instruction at (ram,0x0003020e)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */

uint __cdecl16far FUN_31f7_6f49(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  byte *pbVar2;
  int *piVar3;
  undefined2 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  uint uVar7;
  code *pcVar8;
  byte *pbVar9;
  byte bVar10;
  byte bVar15;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  byte bVar16;
  byte bVar21;
  byte *pbVar17;
  uint uVar18;
  int iVar19;
  byte *pbVar20;
  uint in_CX;
  byte bVar22;
  byte bVar23;
  undefined1 uVar24;
  byte bVar30;
  uint *puVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  int iVar29;
  uint uVar31;
  undefined2 *puVar32;
  undefined2 *puVar33;
  undefined2 *puVar34;
  undefined2 *puVar35;
  uint uVar36;
  int iVar37;
  byte *pbVar38;
  byte *unaff_SI;
  int *piVar39;
  uint *puVar40;
  int *unaff_DI;
  undefined2 uVar41;
  undefined2 uVar42;
  undefined2 in_GS;
  bool bVar43;
  bool bVar44;
  byte in_AF;
  bool bVar45;
  undefined4 uVar46;
  uint in_stack_00007921;
  int iStack_2c;
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined1 *puStack_1a;
  int iStack_18;
  uint uStack_16;
  int iStack_14;
  uint uStack_a;
  int iStack_8;
  uint uStack_6;
  uint local_4;
  
  uVar41 = (undefined2)((ulong)param_1 >> 0x10);
  iVar29 = (int)param_1;
  uVar13 = *(uint *)(iVar29 + 0x10);
  if (uVar13 == DAT_5b41_1a2a) {
    uVar13 = *(uint *)(iVar29 + 0x12);
    *(uint *)(iVar29 + 0x10) = uVar13;
  }
  if (param_2 < 4) {
    uVar12 = param_2 * 2;
    bVar15 = (byte)(uVar13 >> 8);
    switch(param_2) {
    case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 1:
      uVar13 = FUN_1000_180a();
      uVar13 = uVar13 >> 1 | (uint)((param_2 & 1) != 0) << 0xf;
      uStack_16 = uVar13 + (uStack_a - uStack_6);
      if (((param_2 >> 1) + ((iStack_8 - local_4) - (uint)(uStack_a < uStack_6)) +
           (uint)CARRY2(uVar13,uStack_a - uStack_6) == 0) && (uStack_16 < 0xffdd)) {
        iStack_18 = 0;
        puStack_1a = (undefined1 *)0x0;
        for (iStack_2c = 1;
            ((iStack_2c < 0x32 && (puStack_1a == (undefined1 *)0x0 && iStack_18 == 0)) &&
            (*(int *)(iStack_2c * 2) != 0)); iStack_2c = iStack_2c + 1) {
          FUN_3f2b_0e3a();
          puStack_1a = (undefined1 *)FUN_3f2b_0fa3();
        }
        if ((puStack_1a == (undefined1 *)0x0 && iStack_18 == 0) && (iStack_2c < 0x32)) {
          FUN_3f2b_1159();
          uVar41 = FUN_3f2b_0e8f();
          iVar29 = 0x52bc;
          *(undefined2 *)(iStack_2c * 2) = uVar41;
          if (*(int *)(iStack_2c * 2) != 0) {
            FUN_3f2b_0e3a();
            puStack_1a = (undefined1 *)FUN_3f2b_0fa3();
            iStack_18 = iVar29;
            if (puStack_1a == (undefined1 *)0x0 && iVar29 == 0) {
              FUN_3f2b_0f46();
              *(undefined2 *)(iStack_2c * 2) = 0;
            }
          }
        }
        else {
          iStack_2c = iStack_2c + -1;
        }
        if (puStack_1a == (undefined1 *)0x0 && iStack_18 == 0) {
          FUN_3f2b_118f();
          DAT_5b41_1ad2 = 8;
          DAT_5b41_1ade = 0;
          DAT_5b41_1adc = uStack_16;
        }
        else {
          uStack_22 = (undefined1 *)CONCAT22(iStack_18,puStack_1a);
          uStack_1e = (undefined1 *)
                      CONCAT22(*(undefined2 *)*unaff_DI,(undefined1 *)((undefined2 *)*unaff_DI)[1]);
          iStack_14 = 0;
          while( true ) {
            bVar45 = uStack_16 == 0;
            if (uStack_16 == 0 && iStack_14 == 0) break;
            *uStack_22 = *uStack_1e;
            uStack_1e = (undefined1 *)CONCAT22(uStack_1e._2_2_,(undefined1 *)uStack_1e + 1);
            uStack_22 = (undefined1 *)CONCAT22(uStack_22._2_2_,(undefined1 *)uStack_22 + 1);
            uStack_16 = uStack_16 - 1;
            iStack_14 = iStack_14 - (uint)bVar45;
          }
          FUN_3f2b_118f();
          iStack_2c = DAT_554c_3d5a + iStack_2c;
          iVar29 = FUN_1000_199e();
          iVar29 = iVar29 + *(int *)(*unaff_DI + 2);
          for (piVar39 = unaff_DI; *piVar39 != 0; piVar39 = piVar39 + 1) {
            iVar27 = FUN_1000_199e();
            iVar14 = *(int *)(*piVar39 + 2);
            iVar37 = FUN_1000_199e();
            piVar5 = (int *)*piVar39;
            iVar19 = piVar5[2];
            *piVar5 = iStack_2c;
            piVar5[1] = (int)(puStack_1a + ((iVar27 + iVar14) - iVar29));
            if (*(int *)(*unaff_DI + 4) != -2) {
              *(undefined2 *)(*piVar39 + 4) = puStack_1a + ((iVar37 + iVar19) - iVar29);
            }
          }
          uStack_16 = FUN_22de_0351();
        }
      }
      else {
        DAT_5b41_1ad2 = 5;
      }
      return uStack_16;
    case 2:
      out(param_2,3);
      uVar13 = in_CX & (uint)&stack0xfffe & in_stack_00007921;
      puVar40 = (uint *)(((uint)unaff_DI & *(uint *)(unaff_SI + uVar12 + 0xa323)) - 1 &
                        *(uint *)(&stack0xfffe + (int)unaff_SI));
      uVar31 = (uint)&stack0xfffe & in_CX & *(uint *)(unaff_SI + 0x23) & *puVar40;
      puVar40 = (uint *)((uint)puVar40 & uVar12);
      bVar23 = (byte)((param_2 & *(uint *)(unaff_SI + uVar12)) >> 8);
      bVar16 = (byte)uVar13;
      uVar24 = (undefined1)uVar12;
      bVar30 = (byte)(uVar12 >> 8) & unaff_SI[-0x58de];
      bVar22 = (byte)(param_2 & *(uint *)(unaff_SI + uVar12)) & bVar16 &
               (&stack0x7d20)[(int)unaff_SI];
      bVar10 = *(byte *)(CONCAT11(bVar30,uVar24) + 0x22);
      *(undefined2 *)(uVar31 - 2) = CONCAT11(bVar23,bVar22);
      bVar30 = bVar30 & (byte)*puVar40;
      bVar21 = (byte)(uVar13 >> 8) & unaff_SI[CONCAT11(bVar30,uVar24)];
      bVar22 = bVar22 & (&stack0xfffe)[(int)unaff_SI];
      uVar13 = CONCAT11(bVar23,bVar22);
      bVar30 = bVar30 & bVar21;
      puVar25 = (uint *)CONCAT11(bVar30,uVar24);
      bVar15 = bVar15 & 0x25 & bVar23 & bVar10 & (byte)((uint)&stack0xfffe >> 8);
      *(uint *)((int)puVar40 + -0x57df) = *(uint *)((int)puVar40 + -0x57df) & (uint)puVar40;
      *(uint *)(&stack0x7d1f + (int)unaff_SI) = *(uint *)(&stack0x7d1f + (int)unaff_SI) & uVar13;
      puVar1 = (uint *)((byte *)((int)puVar25 + (int)unaff_SI) + 0x21);
      *puVar1 = *puVar1 & (uint)&stack0xfffe;
      *(uint *)(uVar31 - 4) = uVar13;
      *puVar40 = *puVar40 & (uint)puVar40;
      puVar1 = puVar25;
      *puVar1 = *puVar1 & uVar31 - 4;
      *(uint *)(&stack0xfffe + (int)unaff_SI) = *(uint *)(&stack0xfffe + (int)unaff_SI) & uVar13;
      puVar32 = (undefined2 *)(uVar31 - 4 & (uint)puVar40);
      bVar30 = bVar30 & bVar15;
      pbVar20 = (byte *)CONCAT11(bVar30,uVar24);
      bVar16 = bVar16 & bVar22;
      (&stack0xa61e)[(int)puVar40] = (&stack0xa61e)[(int)puVar40] & bVar30;
      (pbVar20 + (int)unaff_SI)[0x7b20] = (pbVar20 + (int)unaff_SI)[0x7b20] & bVar22;
      *(byte *)(puVar40 + 0x10) = (byte)puVar40[0x10] & bVar15;
      pbVar20[(int)puVar40 + -1] = pbVar20[(int)puVar40 + -1] & bVar30;
      *unaff_SI = *unaff_SI & bVar15;
      DAT_6000_4ce0 = DAT_6000_4ce0 & bVar16;
      bVar45 = DAT_6000_4ce0 == 0;
      uVar42 = *puVar32;
      puVar33 = puVar32 + 1;
      pbVar17 = (byte *)(CONCAT11(bVar21,bVar16) + -1);
      if (pbVar17 == (byte *)0x0) {
        pcVar8 = (code *)swi(0x1f);
        (*pcVar8)();
        pbVar20 = (byte *)CONCAT11(0x1f,(char)pbVar20);
        puVar34 = puVar33 + 1;
        if (!bVar45) {
          *puVar33 = *puVar33;
          puVar34 = puVar33;
        }
      }
      else {
        *puVar32 = uVar42;
        uVar4 = in(uVar13);
        *(undefined2 *)((int)puVar40 + -1) = uVar4;
        puVar32[-1] = uVar42;
        puVar34 = puVar32 + -2;
        puVar32[-2] = (int)puVar40 + 1;
      }
      pbVar9 = (byte *)*puVar34;
      puVar34[2] = puVar34[2];
      uVar42 = puVar34[2];
      *pbVar20 = *pbVar20 | (byte)pbVar20;
      puVar34[2] = uVar42;
      puVar34[1] = uVar42;
      *(int *)0x1e6d = *(int *)0x1e6d + -0x57;
      *puVar34 = uVar42;
      puVar35 = puVar34 + -1;
      puVar34[-1] = uVar42;
      bVar15 = pbVar20 < (byte *)*(int *)0x1e15;
      uVar26 = (int)pbVar20 - *(int *)0x1e15;
      *pbVar9 = *pbVar9 + 1;
      puVar34[-2] = 0x217;
      uVar46 = FUN_31f7_b4c4();
      uVar12 = ((int)uVar46 + -0x1dbc) - (uint)bVar15;
      puVar25 = (uint *)(pbVar9 + 1);
      pbVar20 = unaff_SI + 1;
      uVar13 = uVar12 + 0xe271;
      bVar45 = uVar12 < 0x1d8f || uVar13 < (*unaff_SI < *pbVar9);
      iVar29 = uVar13 - (*unaff_SI < *pbVar9);
      if (iVar29 < 0) {
        puVar1 = puVar25;
        *puVar1 = *puVar1 + (uint)bVar45 * ((uVar26 & 3) - (*puVar1 & 3));
        puVar35 = (undefined2 *)((int)puVar34 + -3);
        iVar29 = (iVar29 + -0x1d36) - (uint)bVar45;
        *(byte *)puVar25 = (byte)*puVar25 & (byte)uVar26;
        *puVar25 = *puVar25 | uVar26;
        bVar15 = (byte)iVar29;
        bVar45 = (byte)(bVar15 + 0x24) < 0xc6 || (byte)(bVar15 + 0x5e) < (bVar15 < 0xdc);
        bVar10 = (bVar15 + 0x5e) - (bVar15 < 0xdc);
        bVar15 = bVar10 + 0x51;
        bVar43 = bVar10 < 0xaf || bVar15 < bVar45;
        bVar15 = bVar15 - bVar45;
        bVar10 = bVar15 + 0x67;
        bVar45 = bVar15 < 0x99 || bVar10 < bVar43;
        bVar10 = bVar10 - bVar43;
        bVar15 = bVar10 + 0x7d;
        bVar43 = bVar10 < 0x83 || bVar15 < bVar45;
        bVar15 = bVar15 - bVar45;
        bVar10 = bVar15 + 0x94;
        bVar45 = bVar15 < 0x6c || bVar10 < bVar43;
        bVar10 = bVar10 - bVar43;
        bVar15 = bVar10 + 0xab;
        bVar43 = bVar10 < 0x55 || bVar15 < bVar45;
        bVar15 = bVar15 - bVar45;
        bVar10 = bVar15 - 0x3f;
        bVar44 = bVar15 < 0x3f || bVar10 < bVar43;
        bVar10 = bVar10 - bVar43;
        bVar15 = bVar10 - 0x28;
        bVar45 = bVar10 < 0x28 || bVar15 < bVar44;
        iVar29 = CONCAT11((char)((uint)iVar29 >> 8),bVar15 - bVar44);
      }
      bVar15 = (byte)iVar29 - 0x12;
      bVar43 = (byte)iVar29 < 0x12 || bVar15 < bVar45;
      bVar15 = bVar15 - bVar45;
      bVar10 = bVar15 + 5;
      uVar11 = CONCAT11((char)((uint)iVar29 >> 8),bVar10 - bVar43);
      uVar13 = (uint)(bVar15 < 0xfb || bVar10 < bVar43);
      uVar7 = (int)puVar35 - (int)&stack0xfffe;
      iVar14 = -uVar13;
      uVar13 = (uint)(puVar35 < &stack0xfffe || uVar7 < uVar13);
      uVar18 = ((int)pbVar17 - (int)pbVar20) - uVar13;
      uVar13 = (uint)(pbVar17 < pbVar20 || (uint)((int)pbVar17 - (int)pbVar20) < uVar13);
      uVar12 = (int)pbVar20 - *(int *)(uVar26 + 0xa11b);
      iVar37 = uVar12 - uVar13;
      uVar13 = (uint)(pbVar20 < (byte *)*(int *)(uVar26 + 0xa11b) || uVar12 < uVar13);
      uVar12 = uVar18 - *(uint *)(&stack0x7319 + iVar37);
      iVar19 = uVar12 - uVar13;
      uVar13 = (uint)(uVar18 < *(uint *)(&stack0x7319 + iVar37) || uVar12 < uVar13);
      uVar12 = uVar26 - *(uint *)(pbVar9 + 0x1c);
      puVar40 = (uint *)(uVar12 - uVar13);
      pbVar38 = (byte *)(iVar37 + 1);
      puVar6 = (undefined1 *)(uint)(uVar26 < *(uint *)(pbVar9 + 0x1c) || uVar12 < uVar13);
      uVar36 = (int)(&stack0xfffe + -*puVar40) - (int)puVar6;
      uVar13 = (uint)(&stack0xfffe < (undefined1 *)*puVar40 || &stack0xfffe + -*puVar40 < puVar6);
      uVar12 = (int)puVar40 - *(int *)(byte *)((int)puVar40 + (int)pbVar38);
      uVar18 = uVar12 - uVar13;
      uVar13 = (uint)(puVar40 < *(uint **)(byte *)((int)puVar40 + (int)pbVar38) || uVar12 < uVar13);
      uVar12 = uVar11 - *(uint *)(pbVar38 + uVar36);
      iVar29 = uVar12 - uVar13;
      uVar26 = (uint)(uVar11 < *(uint *)(pbVar38 + uVar36) || uVar12 < uVar13);
      bVar45 = uVar36 < uVar18 || uVar36 - uVar18 < uVar26;
      uVar26 = (uVar36 - uVar18) - uVar26;
      bVar16 = (byte)((uint)iVar29 >> 8);
      bVar10 = (byte)((ulong)uVar46 >> 0x10);
      bVar15 = bVar10 - bVar16;
      bVar43 = bVar10 < bVar16 || bVar15 < bVar45;
      bVar23 = (byte)((ulong)uVar46 >> 0x18);
      bVar15 = bVar15 - bVar45;
      bVar21 = (byte)(uVar18 >> 8);
      bVar10 = bVar21 - pbVar9[-0x59e5];
      bVar45 = bVar21 < pbVar9[-0x59e5] || bVar10 < bVar43;
      iVar27 = CONCAT11(bVar10 - bVar43,(char)uVar18);
      pbVar2 = (byte *)((int)(undefined2 *)&DAT_5b41_19ca + iVar27);
      bVar21 = (byte)iVar19;
      bVar10 = bVar21 - *pbVar2;
      bVar43 = bVar21 < *pbVar2 || bVar10 < bVar45;
      uVar36 = CONCAT11((char)((uint)iVar19 >> 8),bVar10 - bVar45);
      bVar10 = bVar16 - pbVar38[uVar26 + 0x1a];
      bVar22 = (byte)iVar29;
      iVar27 = iVar27 + -1;
      bVar45 = bVar23 < *pbVar38 ||
               (byte)(bVar23 - *pbVar38) < (bVar16 < pbVar38[uVar26 + 0x1a] || bVar10 < bVar43);
      bVar21 = (byte)iVar27;
      bVar16 = bVar21 - (byte)*puVar25;
      bVar44 = bVar21 < (byte)*puVar25 || bVar16 < bVar45;
      bVar23 = (byte)((uint)iVar27 >> 8);
      bVar16 = bVar16 - bVar45;
      uVar28 = CONCAT11(bVar23,bVar16);
      bVar21 = bVar22 - *(byte *)0xef1a;
      uVar11 = CONCAT11(bVar10 - bVar43,bVar21 - bVar44);
      uVar13 = (uint)(bVar22 < *(byte *)0xef1a || bVar21 < bVar44);
      uVar12 = uVar11 - uVar28;
      uVar18 = uVar12 - uVar13;
      uVar13 = (uint)(uVar11 < uVar28 || uVar12 < uVar13);
      uVar12 = uVar36 - uVar18;
      pbVar20 = (byte *)(uVar12 - uVar13);
      puVar1 = (uint *)(pbVar38 + uVar26 + 0x9319);
      uVar11 = (uint)(uVar36 < uVar18 || uVar12 < uVar13);
      uVar12 = *puVar1;
      uVar13 = *puVar1;
      *puVar1 = (uVar13 - uVar26) - uVar11;
      piVar3 = (int *)(iVar37 + 0x1a);
      uVar13 = (uint)(uVar12 < uVar26 || uVar13 - uVar26 < uVar11);
      puVar40 = (uint *)*piVar3;
      iVar29 = *piVar3;
      *piVar3 = (iVar29 - (int)puVar25) - uVar13;
      *(int *)(uVar26 + 0x19) =
           (*(int *)(uVar26 + 0x19) - (int)pbVar20) -
           (uint)(puVar40 < puVar25 || (uint)(iVar29 - (int)puVar25) < uVar13);
      in_AF = 9 < ((byte)uVar18 & 0xf) | in_AF;
      bVar22 = (byte)uVar18 + in_AF * '\x06';
      bVar10 = bVar22 & 0xf;
      puVar1 = (uint *)(pbVar38 + uVar28);
      puVar6 = (undefined1 *)*puVar1;
      uVar13 = *puVar1 - (uVar7 + iVar14);
      *puVar1 = uVar13 - in_AF;
      puVar1 = (uint *)(pbVar38 + uVar28);
      uVar12 = (uint)(puVar6 < (undefined1 *)(uVar7 + iVar14) || uVar13 < in_AF);
      pbVar17 = (byte *)*puVar1;
      uVar13 = *puVar1;
      *puVar1 = (uVar13 - (int)pbVar20) - uVar12;
      uVar13 = (uint)(pbVar17 < pbVar20 || uVar13 - (int)pbVar20 < uVar12);
      iVar29 = ((int)pbVar20 - (int)pbVar38) - uVar13;
      bVar45 = bVar15 < bVar16 ||
               (byte)(bVar15 - bVar16) <
               (pbVar20 < pbVar38 || (uint)((int)pbVar20 - (int)pbVar38) < uVar13);
      bVar21 = bVar16 - bVar10;
      bVar43 = bVar16 < bVar10 || bVar21 < bVar45;
      bVar21 = bVar21 - bVar45;
      uVar13 = CONCAT11(bVar23,bVar21);
      pbVar2 = (byte *)(iVar37 + -0x6ae7);
      bVar10 = (byte)((uint)iVar29 >> 8);
      bVar15 = *pbVar2 - bVar10;
      bVar45 = *pbVar2 < bVar10 || bVar15 < bVar43;
      *pbVar2 = bVar15 - bVar43;
      pbVar2 = pbVar9 + 0x19;
      bVar15 = *pbVar2;
      bVar10 = *pbVar2;
      *pbVar2 = (bVar10 - bVar23) - bVar45;
      *(char *)(uVar13 + 0x18) =
           (*(char *)(uVar13 + 0x18) - (char)iVar29) -
           (bVar15 < bVar23 || (byte)(bVar10 - bVar23) < bVar45);
      pbVar38[uVar13] = pbVar38[uVar13] & bVar21;
      *(uint *)(pbVar38 + uVar13) = *(uint *)(pbVar38 + uVar13) | uVar13;
      return CONCAT11((char)(uVar18 >> 8) + in_AF,bVar22) & 0xff0f;
    case 3:
      uVar13 = CONCAT11(bVar15,(char)uVar13 + 'V');
      if (*(int *)(iVar29 + 0x16) != 0) {
        uVar12 = FUN_28eb_3783();
        uVar13 = uVar12 | param_2;
        if ((uVar13 != 0) &&
           (((*(int *)(uVar12 + 8) == 0xe || (*(int *)(uVar12 + 8) == 0x56)) &&
            (uVar13 = *(uint *)(uVar12 + 0x12), uVar13 == *(uint *)(uVar12 + 0x14))))) {
          *(undefined2 *)(iVar29 + 0x16) = 0;
        }
      }
    }
    if (*(int *)(iVar29 + 0x16) != 0) {
      iVar14 = (*(int *)(iVar29 + 0x48) + -0x20) / 0x10;
      if (*(int *)(iVar29 + 0x16) < 1) {
        uVar13 = *(uint *)(iVar29 + 0x10);
        if ((uVar13 == ((undefined2 *)&DAT_5b41_196c)[iVar14]) ||
           (uVar13 == ((undefined2 *)&DAT_5b41_1960)[iVar14])) {
          if ((DAT_5b41_051f & 1) == 0) {
            uVar13 = ((undefined2 *)&DAT_5b41_1960)[iVar14] + 2;
            *(uint *)(iVar29 + 0x10) = uVar13;
          }
          else {
            uVar13 = ((undefined2 *)&DAT_5b41_1962)[iVar14] - 1;
            *(uint *)(iVar29 + 0x10) = uVar13;
          }
        }
        else {
          *(int *)(iVar29 + 0x10) = *(int *)(iVar29 + 0x10) + -1;
        }
      }
      else {
        *(int *)(iVar29 + 0x10) = *(int *)(iVar29 + 0x10) + 1;
        uVar13 = *(uint *)(iVar29 + 0x10);
        if (uVar13 == ((undefined2 *)&DAT_5b41_1962)[iVar14]) {
          if ((DAT_5b41_051f & 1) == 0) {
            *(int *)(iVar29 + 0x10) = *(int *)(iVar29 + 0x10) + -2;
          }
          else {
            uVar13 = ((undefined2 *)&DAT_5b41_196c)[iVar14];
            *(uint *)(iVar29 + 0x10) = uVar13;
          }
        }
      }
    }
    return uVar13;
  }
  return uVar13;
}

