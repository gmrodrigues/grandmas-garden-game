// TIM2.EXE: FUN_2424_3c0a @ file 0x02D04A Ghidra 0x27E4A
// Subsystem: misc | Size: 405 bytes


/* WARNING: Instruction at (ram,0x00028361) overlaps instruction at (ram,0x0002835f)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x00020615) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * FUN_2424_3c0a(undefined2 param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5,
                    int param_6,int param_7)

{
  byte *pbVar1;
  int *piVar2;
  char *pcVar3;
  uint *puVar4;
  uint *puVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  code *pcVar10;
  code *pcVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  undefined1 uVar19;
  undefined1 uVar20;
  undefined1 uVar21;
  undefined1 uVar22;
  byte bVar23;
  char cVar24;
  uint *puVar25;
  uint *puVar26;
  uint *puVar27;
  uint *puVar28;
  byte bVar30;
  uint uVar29;
  uint uVar31;
  uint *in_CX;
  byte *pbVar32;
  byte bVar35;
  uint uVar33;
  uint uVar34;
  byte bVar36;
  char cVar37;
  byte bVar38;
  char cVar39;
  undefined2 extraout_DX;
  uint *in_DX;
  byte bVar40;
  char cVar41;
  uint *puVar42;
  int iVar43;
  byte *pbVar44;
  char cVar45;
  undefined2 *puVar46;
  int iVar47;
  undefined1 *puVar48;
  int unaff_BP;
  undefined2 *puVar49;
  undefined1 *puVar50;
  int iVar51;
  undefined1 uVar55;
  uint *puVar52;
  uint *unaff_SI;
  int iVar53;
  byte *pbVar54;
  byte *pbVar56;
  uint *unaff_DI;
  uint *puVar57;
  undefined2 uVar58;
  char *pcVar59;
  undefined2 uVar60;
  uint *unaff_SS;
  undefined2 in_GS;
  byte in_AF;
  bool bVar61;
  uint *puVar62;
  undefined2 *puVar63;
  undefined4 uVar64;
  ulong uVar65;
  char acStack_174 [304];
  uint *puStack_44;
  undefined2 *puStack_42;
  uint *puStack_40;
  int iStack_3e;
  undefined2 *puStack_3c;
  undefined2 uStack_3a;
  int iStack_38;
  undefined2 uStack_36;
  uint *puStack_34;
  uint *puStack_32;
  byte *pbStack_30;
  uint *puStack_2e;
  uint *puStack_2c;
  uint *in_stack_0000ffd6;
  byte *in_stack_0000ffd8;
  uint *puStack_26;
  undefined2 uStack_24;
  uint *in_stack_0000ffde;
  byte *pbStack_20;
  uint *puStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined4 local_12;
  undefined4 uStack_e;
  uint *local_a;
  uint *local_8;
  undefined4 local_6;
  
  uVar60 = 0x2424;
  puVar49 = (undefined2 *)&stack0xfffe;
  puVar48 = &stack0xfffe;
  puVar50 = &stack0xfffe;
  puVar25 = (uint *)*(undefined2 *)(param_2[4] * 2 + 0x68fe);
  local_6 = (uint *)CONCAT22(local_6._2_2_,puVar25);
  puVar57 = (uint *)0x0;
  iVar53 = 2;
  puVar26 = (uint *)CONCAT11(uStack_18._1_1_,(byte)uStack_18);
  while( true ) {
    uVar16 = uStack_1a._1_1_;
    uVar14 = (char)uStack_1a;
    uVar55 = uStack_1c._1_1_;
    uVar22 = (char)uStack_1c;
    puVar42 = (uint *)CONCAT11(uStack_1a._1_1_,(char)uStack_1a);
    puVar28 = (uint *)CONCAT11(uStack_1c._1_1_,(char)uStack_1c);
    if (iVar53 == 0) break;
    do {
      puVar57 = (uint *)((int)puVar57 + 1);
      uStack_1a._0_1_ = (char)local_6;
      uStack_1a._1_1_ = (char)((ulong)local_6 >> 8);
      uStack_1c._0_1_ = (char)uVar60;
      uStack_1c._1_1_ = (char)((uint)uVar60 >> 8);
      uVar60 = 0x4551;
      puStack_1e = (uint *)0x7e75;
      uStack_18 = puVar57;
      puVar25 = (uint *)FUN_4551_0308();
    } while (puVar25 == (uint *)0x0);
    iVar53 = iVar53 + -1;
    puVar26 = uStack_18;
  }
  uStack_1c._0_1_ = (char)param_2;
  uVar12 = (char)uStack_1c;
  uStack_1c._1_1_ = (char)((uint)param_2 >> 8);
  uVar13 = uStack_1c._1_1_;
  uStack_1a._0_1_ = (char)param_3;
  uVar15 = (char)uStack_1a;
  uStack_1a._1_1_ = (char)((uint)param_3 >> 8);
  uVar17 = uStack_1a._1_1_;
  uStack_18._0_1_ = (byte)param_4;
  uVar18 = (byte)uStack_18;
  uStack_18._1_1_ = (byte)((uint)param_4 >> 8);
  uVar20 = uStack_18._1_1_;
  uStack_18._0_1_ = (byte)unaff_SS;
  uVar19 = (byte)uStack_18;
  uStack_18._1_1_ = (byte)((uint)unaff_SS >> 8);
  uVar21 = uStack_18._1_1_;
  puVar52 = (uint *)0x0;
  uStack_1c = puVar28;
  uStack_1a = (uint **)puVar42;
  puVar28 = puVar57;
  if (param_2[0x57] != 0) {
    uVar31 = param_2[0x57];
    local_6 = (uint *)CONCAT22(uVar31,(uint *)local_6);
    local_8 = (uint *)(param_2[0x11] - DAT_5b41_0925);
    puVar25 = (uint *)(param_2[0x12] - DAT_5b41_0927);
    local_a = puVar25;
    if (8 < uVar31 - 1) {
      uStack_1a = (uint **)&local_12;
      uStack_1c = (uint *)((int)puVar57 + (uVar31 - 1));
      puStack_1e = (uint *)local_6;
      FUN_4551_03eb();
      local_12 = (uint *)CONCAT22((byte *)((int)local_12._2_2_ + (int)local_a),
                                  (uint *)((int)(uint *)local_12 + (int)local_8));
      pbStack_20 = (byte *)0x2;
      uStack_24 = &local_12;
      puStack_26 = (uint *)0x4551;
      in_stack_0000ffd8 = (byte *)0x7ef0;
      puVar25 = (uint *)FUN_2424_1e00();
      puVar26 = (uint *)CONCAT11(uStack_18._1_1_,(byte)uStack_18);
      in_stack_0000ffde = unaff_SS;
      goto LAB_2424_3cb3;
    }
    puVar42 = (uint *)((uVar31 - 1) * 2);
    pbVar56 = (byte *)0x2000;
    bVar36 = (byte)((uint)puVar42 >> 8);
    puVar49 = (undefined2 *)&stack0xfffe;
    uStack_18 = puVar26;
    uStack_1a._0_1_ = uVar14;
    uStack_1a._1_1_ = uVar16;
    uStack_1c._0_1_ = uVar22;
    uStack_1c._1_1_ = uVar55;
    switch(uVar31) {
    case 1:
      iVar53 = ((uint)puVar25 & 0xff26) + puVar42[0x25];
      do {
        uStack_18 = puVar26;
        if (iVar53 == param_2[0x12] + param_2[0x25]) {
          iVar53 = 6;
        }
        else {
          iVar53 = 4;
        }
        while( true ) {
          do {
            do {
              uVar60 = (undefined2)((ulong)local_6 >> 0x10);
              uVar31 = ((uint *)local_6)[0x47];
              puVar57 = (uint *)((uint *)local_6)[0x46];
              local_6 = (uint *)CONCAT22(uVar31,puVar57);
              puVar49 = (undefined2 *)&stack0xfffe;
              uStack_1c = (uint *)CONCAT11(uStack_1c._1_1_,(char)uStack_1c);
              uStack_1a = (uint **)CONCAT11(uStack_1a._1_1_,(char)uStack_1a);
              if ((puVar57 == (uint *)0x0 && uVar31 == 0) ||
                 (puVar49 = (undefined2 *)&stack0xfffe,
                 uStack_1c = (uint *)CONCAT11(uStack_1c._1_1_,(char)uStack_1c),
                 uStack_1a = (uint **)CONCAT11(uStack_1a._1_1_,(char)uStack_1a), iVar53 != 0))
              goto LAB_2424_39fc;
            } while (puVar57[0x25] == 0x10);
            uStack_18._0_1_ = (byte)uVar31;
            uStack_18._1_1_ = (byte)(uVar31 >> 8);
            uStack_1a._0_1_ = (char)puVar57;
            uStack_1a._1_1_ = (char)((uint)puVar57 >> 8);
            uStack_1c._0_1_ = 0;
            uStack_1c._1_1_ = 0x20;
            iVar43 = FUN_2424_4087();
            puVar26 = (uint *)CONCAT11(uStack_18._1_1_,(byte)uStack_18);
            uStack_18 = puVar26;
          } while (iVar43 == 0);
          uVar60 = (undefined2)((ulong)local_6 >> 0x10);
          puVar57 = (uint *)local_6;
          if (puVar57[0x12] != param_2[0x12]) break;
          iVar53 = 2;
        }
        iVar53 = puVar57[0x12] + puVar57[0x25];
      } while( true );
    case 2:
      uStack_18._0_1_ = 0;
      uStack_18._1_1_ = 0x20;
      uStack_1a._0_1_ = 0xf5;
      uStack_1a._1_1_ = 0x5e;
      puVar57 = (uint *)FUN_1000_19bf();
      local_6 = (uint *)CONCAT22(local_6._2_2_,puVar57);
      uStack_18._0_1_ = 0;
      uStack_18._1_1_ = 0x10;
      uStack_1a._0_1_ = 6;
      uStack_1a._1_1_ = 0x5f;
      puVar57 = (uint *)FUN_1000_19bf();
      iStack_3e = 0;
      local_6._2_2_ = puVar57;
      for (puStack_40 = (uint *)0x0;
          (iStack_3e < (int)puStack_42 ||
          ((iStack_3e <= (int)puStack_42 && (puStack_40 <= puStack_44))));
          puStack_40 = (uint *)((int)puStack_40 + 1)) {
        uStack_18._0_1_ = 0;
        uStack_18._1_1_ = 0x10;
        uStack_1a._0_1_ = 0x24;
        uStack_1a._1_1_ = 0x5f;
        local_a = (uint *)FUN_1000_19bf();
        uStack_18._0_1_ = 0;
        uStack_18._1_1_ = 0x10;
        uStack_1a._0_1_ = 0x35;
        uStack_1a._1_1_ = 0x5f;
        local_8 = (uint *)FUN_1000_19bf();
        if (((uint *)local_6 != local_a) || (local_6._2_2_ != local_8)) {
          uStack_1a = &local_a;
          uStack_1c = (uint *)&local_6;
          uStack_18._0_1_ = uVar18;
          uStack_18._1_1_ = uVar20;
          FUN_2424_1a04();
          local_6._0_2_ = local_a;
          local_6._2_2_ = local_8;
        }
        uStack_18._0_1_ = 0;
        uStack_18._1_1_ = 0x10;
        uStack_1a._0_1_ = 0x85;
        uStack_1a._1_1_ = 0x5f;
        FUN_1000_180a();
        uStack_18._0_1_ = 0;
        uStack_18._1_1_ = 0x10;
        uStack_1a._0_1_ = 0xb0;
        uStack_1a._1_1_ = 0x5f;
        FUN_1000_180a();
        iStack_3e = iStack_3e + (uint)((uint *)0xfffe < puStack_40);
      }
      return puStack_40;
    case 3:
      goto switchD_2000_eb7b_caseD_1;
    case 5:
      bVar30 = (byte)((uint)puVar25 >> 8) ^ bRam000554f2;
      uStack_18._0_1_ = (byte)&stack0xfffe;
      uStack_18._1_1_ = (byte)((uint)&stack0xfffe >> 8);
      uVar33 = puVar57[0x19];
      bVar23 = *(byte *)0x1632;
      uVar34 = *puVar42;
      bVar38 = (byte)in_DX;
      bVar40 = (byte)((uint)in_DX >> 8) ^ bVar36;
      iVar43 = CONCAT11(bVar40,bVar38);
      puVar57 = (uint *)((uint)puVar57 ^ (uint)&uStack_18);
      *(uint *)((int)puVar42 + -0x57cf) = *(uint *)((int)puVar42 + -0x57cf) ^ (uint)puVar57;
      *(uint *)((int)puVar42 + -0x77cf) = *(uint *)((int)puVar42 + -0x77cf) ^ (uint)puVar42;
      puVar62 = (uint *)((int)((int)puVar42 + (int)puVar57) + 0x31);
      *puVar62 = *puVar62 ^ (uint)puVar57;
      uVar31 = *(uint *)((int)puVar42 + (int)puVar57);
      pbVar54 = (byte *)(uVar31 * 0x3159);
      pbVar32 = (byte *)((int)in_CX + -1);
      *(uint *)((int)puVar42 + (int)pbVar54) =
           *(uint *)((int)puVar42 + (int)pbVar54) ^ (uint)puVar57;
      *(uint *)((int)puVar42 + (int)pbVar54) =
           *(uint *)((int)puVar42 + (int)pbVar54) ^ (uint)&stack0xfffe;
      *(uint *)((int)puVar42 + (int)pbVar54) =
           *(uint *)((int)puVar42 + (int)pbVar54) ^ (uint)puVar42;
      *(uint *)((int)puVar42 + (int)pbVar54) =
           *(uint *)((int)puVar42 + (int)pbVar54) ^ (uint)pbVar32;
      uVar29 = CONCAT11(bVar30 ^ bVar23,(byte)puVar25 ^ (byte)uVar33 ^ (byte)uVar34) ^ (uint)puVar42
               ^ (uint)in_CX ^ (uint)puVar57;
      bVar30 = (byte)(uVar29 >> 8);
      bVar35 = (byte)((uint)pbVar32 >> 8);
      bVar23 = (byte)uVar29 ^ bVar35 ^ (byte)puVar42;
      pbVar44 = (byte *)CONCAT11(bVar36 ^ bVar23,(byte)puVar42);
      pbVar44[-0x58d0] = pbVar44[-0x58d0] ^ bVar40;
      *(byte *)(puVar57 + 0x18) = (byte)puVar57[0x18] ^ bVar38;
      *pbVar54 = *pbVar54 ^ bVar40;
      (&stack0xfffe)[(int)puVar57] = (&stack0xfffe)[(int)puVar57] ^ bVar30;
      (&stack0xfffe)[(int)puVar57] = (&stack0xfffe)[(int)puVar57] ^ bVar38;
      (&stack0xfffe)[(int)pbVar54] = (&stack0xfffe)[(int)pbVar54] ^ bVar23;
      bVar40 = (byte)pbVar32 ^ bVar40;
      iVar53 = CONCAT11(bVar35,bVar40);
      bVar36 = 9 < (bVar23 & 0xf) | in_AF;
      bVar23 = bVar23 + bVar36 * -6;
      bVar23 = bVar23 + (0x9f < bVar23 | bVar36 * (bVar23 < 6)) * -0x60;
      uVar33 = iVar53 - 1;
      uVar34 = uVar33;
      if (uVar33 == 0 || bVar40 != 0) {
        pbVar1 = pbVar44;
        bVar40 = *pbVar1;
        *pbVar1 = *pbVar1 >> 1;
        puVar57 = (uint *)0xaf2f;
        bVar36 = 9 < (bVar23 & 0xf) | bVar36;
        bVar23 = bVar23 + bVar36 * -6;
        bVar23 = bVar23 + (0x9f < bVar23 | bVar40 & 1 | bVar36 * (bVar23 < 6)) * -0x60;
        bVar61 = 9 < (bVar23 & 0xf) || (uVar29 & 0x1000) != 0;
        bVar23 = bVar23 + bVar61 * -6;
        bVar23 = bVar23 + (0x9f < bVar23 | (uVar29 & 0x100) != 0 | bVar61 * (bVar23 < 6)) * -0x60;
        if ((uVar29 & 0x8000) != 0) {
          uVar34 = CONCAT11(bVar30,bVar23) + 0xd232;
          pbVar32 = pbVar44;
          goto code_r0x00030083;
        }
        pbVar32 = (byte *)(byte *)((long)*(int *)pbVar44 * 0x5a);
        bVar61 = 9 < (bVar23 & 0xf) || bVar61;
        bVar23 = bVar23 + bVar61 * -6;
        bVar36 = 0x9f < bVar23 |
                 (byte *)(long)(int)pbVar32 != (byte *)((long)*(int *)pbVar44 * 0x5a) |
                 bVar61 * (bVar23 < 6);
        bVar23 = bVar23 + bVar36 * -0x60;
        uVar34 = iVar53 - 2;
        bVar61 = 9 < (bVar23 & 0xf) || bVar61;
        bVar23 = bVar23 + bVar61 * -6;
        bVar23 = bVar23 + (0x9f < bVar23 | bVar36 | bVar61 * (bVar23 < 6)) * -0x60;
        pbVar1 = pbVar44;
        bVar40 = *pbVar1;
        bVar35 = (byte)(uVar34 >> 8);
        *pbVar1 = *pbVar1 - bVar35;
        bVar36 = 9 < (bVar23 & 0xf) || bVar61;
        bVar23 = bVar23 + bVar36 * -6;
        uVar29 = CONCAT11(bVar30,bVar23 + (0x9f < bVar23 | bVar40 < bVar35 | bVar36 * (bVar23 < 6))
                                          * -0x60);
        uVar33 = 0;
        uStack_1a._1_1_ = uVar19;
        puVar48 = (undefined1 *)CONCAT11(uStack_18._1_1_,uVar21);
        if (uVar34 != 0) {
          bVar23 = (byte)uVar34 & 0x1f;
          bVar40 = bRam00058381 >> bVar23;
          bVar9 = (uVar34 & 0x1f) != 0;
          bVar61 = (uVar34 & 0x1f) != 0;
          bVar30 = bVar36 << 4 |
                   (!bVar61 && (POPCOUNT(uVar29 - 0xbd1 & 0xff) & 1U) == 0 ||
                   bVar61 && (POPCOUNT(bVar40) & 1U) == 0) << 2 | 2 |
                   (!bVar9 && 0xbd0 < uVar29 || bVar9 && (bRam00058381 >> bVar23 - 1 & 1) != 0);
          bVar23 = 0x2e;
          puVar50 = (undefined1 *)(DAT_554c_2e5a * 0x48);
          bRam00058381 = bVar40;
          uStack_18._0_1_ = uVar21;
          goto LAB_2fc8_03f1;
        }
LAB_2fc8_040e:
        uVar33 = uVar33 + 1;
        uStack_1c._1_1_ = 0x9b;
        uStack_1a._0_1_ = 0;
        uStack_18 = (uint *)puVar48;
        uVar60 = FUN_31f7_b757();
        uVar29 = CONCAT11((char)((uint)uVar60 >> 8),(char)uVar60 + -0x26);
      }
      else {
LAB_2fc8_03f1:
        bVar36 = 9 < (bVar23 & 0xf) | bVar36;
        uVar33 = CONCAT11(bVar30 + bVar36,bVar23 + bVar36 * '\x06');
        uVar29 = uVar33 & 0x140e;
        uVar65 = CONCAT22(iVar43,uVar33) & 0xffff140e;
        pbVar56 = (byte *)((char *)s__N0N_N_N_N_N_N_N_N_554c_2ff6 + 10);
        pbVar32 = puVar50 + iRam00032df1;
        uVar33 = uVar34 - 1;
        if (uVar33 == 0 || pbVar32 == (byte *)0x0) {
          pcVar11 = (code *)swi(4);
          if (SCARRY2((int)puVar50,iRam00032df1)) {
            uVar65 = (*pcVar11)();
          }
          iVar43 = (int)(uVar65 >> 0x10);
          puVar48 = (undefined1 *)CONCAT11(uStack_18._1_1_,(byte)uStack_18);
          uVar34 = (int)uVar65 + 0xd244;
          puVar62 = puVar57;
          puVar57 = puVar57 + 1;
          *puVar62 = uVar34;
code_r0x00030083:
          iVar53 = uVar34 + 0xd267;
          *(char *)puVar57 = (char)(uVar33 >> 8);
          if (uVar34 < 0x2d99 || iVar53 == 0) goto LAB_2fc8_0437;
          goto LAB_2fc8_040e;
        }
      }
      iVar53 = CONCAT11((char)(uVar29 >> 8),(char)uVar29 + -0x5f);
      pbVar32 = pbVar32 + -iVar43;
      pbVar44 = pbVar44 + -iVar53;
LAB_2fc8_0437:
      pbVar54 = pbVar54 + -*(int *)(pbVar32 + (int)puVar57 + -0x5ed5);
      iVar7 = *(int *)(pbVar32 + 0x7c2b);
      iVar51 = (int)pbVar32 - *(int *)(pbVar32 + (int)pbVar54 + 0x2b);
      uStack_1a._1_1_ = (char)puVar57;
      uStack_18._0_1_ = (byte)((uint)puVar57 >> 8);
      iVar8 = *(int *)((int)puVar57 + 0x2b);
      bVar36 = (byte)(uVar33 - iVar7 >> 8) ^ *(byte *)(iVar51 + (int)puVar57);
      *(byte *)(iVar51 + (int)puVar57) = *(byte *)(iVar51 + (int)puVar57) & bVar36;
      uVar31 = (iVar53 + uVar31 * -0x3159) - iVar8 | 0xfa2b;
      cVar24 = (char)uVar31;
      cVar37 = bVar36 - cVar24;
      cVar39 = (char)iVar43 - cVar37;
      uStack_1a._0_1_ = (char)((uint)iVar43 >> 8) - (pbVar44 + (int)pbVar54)[-0x62d6];
      uStack_1c._1_1_ = cVar39;
      cVar45 = (char)((uint)pbVar44 >> 8) - *pbVar44;
      cVar37 = cVar37 - *pbVar54;
      cVar41 = (char)pbVar44 - *(char *)(CONCAT11(cVar45,(char)pbVar44) + (int)puVar57);
      iVar53 = CONCAT11((char)(uVar31 >> 8) - (char)puVar57[0x15],(cVar24 - cVar39) - DAT_6000_47ea)
               - ((int)&uStack_1c + 1);
      uVar31 = iVar51 - CONCAT11(cVar37,(char)(uVar33 - iVar7) - pbVar54[iVar51 + 0x772a]);
      *(int *)(pbVar54 + uVar31 + 0xa729) = *(int *)(pbVar54 + uVar31 + 0xa729) - (int)puVar57;
      *(int *)(pbVar54 + -0x7ed7) = *(int *)(pbVar54 + -0x7ed7) - CONCAT11((char)uStack_1a,cVar39);
      *(int *)(uVar31 + 0x29) = *(int *)(uVar31 + 0x29) - uVar31;
      piVar2 = (int *)(CONCAT11(cVar45,cVar41) + 0x29);
      *piVar2 = *piVar2 - iVar53;
      puVar62 = (uint *)(CONCAT11(cVar45,cVar41) + (int)puVar57);
      *puVar62 = *puVar62 & uVar31;
      uStack_1c._1_1_ = (char)pbVar56;
      uStack_1a._0_1_ = (char)((uint)pbVar56 >> 8);
      cVar24 = (char)((uint)iVar53 >> 8);
      iVar53 = CONCAT11(cVar45 - cVar24,cVar41);
      *(char *)(puVar57 + -0x336c) = (char)puVar57[-0x336c] - cVar37;
      *(undefined1 *)(uVar31 + 0x7228) = *(undefined1 *)(uVar31 + 0x7228);
      pcVar3 = (char *)(iVar53 + 0x28);
      *pcVar3 = *pcVar3 - cVar41;
      iVar53 = iVar53 + -1;
      pbVar54[iVar53] = pbVar54[iVar53] - (char)((uint)iVar53 >> 8);
      *pbVar54 = *pbVar54 - (cVar24 - (cVar39 - uStack_1a._1_1_));
      *(char *)(iVar53 + (int)puVar57) =
           *(char *)(iVar53 + (int)puVar57) - (cVar39 - uStack_1a._1_1_);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 6:
      uVar60 = 0xffff;
      puVar25 = param_5;
      goto LAB_1a9e_5c59;
    case 7:
      while( true ) {
        uVar22 = 0;
        uStack_1a._1_1_ = (char)((uint)pbVar56 >> 8);
        uVar55 = uStack_1a._1_1_;
        puVar57 = local_a;
        if ((local_12._2_2_ != (uint *)0x0) ||
           (puVar57 = (uint *)((uint)local_a >> 1), puVar57 < unaff_DI)) break;
        uStack_18._0_1_ = (byte)puVar57;
        uStack_18._1_1_ = (byte)((uint)local_a >> 9);
        pbVar56 = (byte *)0x1000;
        uStack_1c._0_1_ = 0x92;
        uStack_1c._1_1_ = 0x25;
        uStack_1a._0_1_ = uVar22;
        local_a = puVar57;
        uVar60 = FUN_1000_127a();
        uStack_e._0_2_ = (uint *)0x554c;
        local_12 = (uint *)CONCAT22(uVar60,(uint *)local_12);
      }
      local_a = puVar57;
      if (local_12._2_2_ != (uint *)0x0) {
        pbVar56 = (byte *)0x0;
        puVar57 = (uint *)((uint)local_a / (uint)unaff_DI);
        puVar62 = (uint *)CONCAT22((uint)local_a % (uint)unaff_DI,local_a);
        if ((int)unaff_SI < (int)((uint)local_a / (uint)unaff_DI)) {
          puVar57 = unaff_SI;
          puVar62 = (uint *)CONCAT22((uint)local_a % (uint)unaff_DI,local_a);
        }
        while( true ) {
          iVar53 = (int)((ulong)puVar62 >> 0x10);
          uStack_e._2_2_ = (uint *)puVar62;
          if ((int)unaff_SI <= (int)pbVar56) break;
          uStack_18._0_1_ = (byte)puVar62;
          uStack_18._1_1_ = (byte)((ulong)puVar62 >> 8);
          uStack_1a._0_1_ = (char)(uint *)uStack_e;
          uStack_1a._1_1_ = (char)((uint)(uint *)uStack_e >> 8);
          uStack_1c._0_1_ = (char)((ulong)local_12 >> 0x10);
          uStack_1c._1_1_ = (char)((ulong)local_12 >> 0x18);
          FUN_28eb_2aad();
          uStack_18._0_1_ = (byte)puVar57;
          uStack_18._1_1_ = (byte)((uint)puVar57 >> 8);
          uStack_1a._0_1_ = (char)((int)unaff_DI << 1);
          uStack_1a._1_1_ = (char)((uint)((int)unaff_DI << 1) >> 8);
          uStack_1c._0_1_ = (char)pbVar56;
          uStack_1c._1_1_ = (char)((uint)pbVar56 >> 8);
          func_0x0002ea8b();
          puVar62 = (uint *)CONCAT22(extraout_DX,uStack_e._2_2_);
          pbVar56 = pbVar56 + (int)puVar57;
          if ((int)unaff_SI < (int)(pbVar56 + (int)puVar57)) {
            puVar57 = (uint *)((int)unaff_SI - (int)pbVar56);
            puVar62 = (uint *)((long)(int)puVar57 * (long)(int)unaff_DI);
          }
        }
        local_8 = (uint *)0x1;
        if (DAT_554c_42df != '\0') {
          uStack_18._0_1_ = (byte)((ulong)local_6 >> 0x10);
          uStack_18._1_1_ = (byte)((ulong)local_6 >> 0x18);
          uStack_1c._0_1_ = 0x34;
          uStack_1c._1_1_ = 0x26;
          uStack_1a._0_1_ = uVar22;
          uStack_1a._1_1_ = uVar55;
          FUN_28eb_29db();
          uStack_18._0_1_ = 0;
          uStack_18._1_1_ = 0;
          uStack_1a._0_1_ = 0x2c;
          uStack_1a._1_1_ = 0x56;
          uStack_1c._0_1_ = uVar12;
          uStack_1c._1_1_ = uVar13;
          iVar43 = FUN_1a9e_6a85();
          if ((iVar53 == -1) && (iVar43 == -1)) {
            uStack_18._0_1_ = 0;
            uStack_18._1_1_ = 0;
            uStack_1a._0_1_ = 0x35;
            uStack_1a._1_1_ = 0x56;
            uStack_1c._0_1_ = uVar12;
            uStack_1c._1_1_ = uVar13;
            iVar43 = FUN_1a9e_6a85();
            if ((iVar53 != -1) || (iVar43 != -1)) {
              local_8 = (uint *)0x6;
            }
          }
          else {
            local_8 = (uint *)0x5;
          }
          if (4 < (int)local_8) {
            uStack_1c._0_1_ = 0x8c;
            uStack_1c._1_1_ = 0x26;
            uStack_1a._0_1_ = uVar22;
            uStack_1a._1_1_ = uVar55;
            uStack_18._0_1_ = uVar12;
            uStack_18._1_1_ = uVar13;
            uVar60 = FUN_1a9e_6e3d();
            uStack_18._0_1_ = (byte)iVar53;
            uStack_18._1_1_ = (byte)((uint)iVar53 >> 8);
            uStack_1a._0_1_ = (char)uVar60;
            uStack_1a._1_1_ = (char)((uint)uVar60 >> 8);
            uStack_1c._0_1_ = 0x3e;
            uStack_1c._1_1_ = 0x56;
            iVar53 = FUN_28eb_2779();
            local_6 = (uint *)CONCAT22(iVar53,(uint *)local_6);
            if (-1 < iVar53) {
              pbVar56 = (byte *)0x0;
              puVar57 = (uint *)((uint)local_a / (uint)unaff_DI);
              if (local_8 == (uint *)0x6) {
                local_a = (uint *)((uint)local_a >> 2);
              }
              uStack_e._2_2_ = local_a;
              if ((int)unaff_SI < (int)puVar57) {
                puVar57 = unaff_SI;
              }
              while ((int)pbVar56 < (int)unaff_SI) {
                uStack_18._0_1_ = (byte)uStack_e._2_2_;
                uStack_18._1_1_ = (byte)((uint)uStack_e._2_2_ >> 8);
                uStack_1a._0_1_ = (char)(uint *)uStack_e;
                uStack_1a._1_1_ = (char)((uint)(uint *)uStack_e >> 8);
                uStack_1c._0_1_ = (char)((ulong)local_12 >> 0x10);
                uStack_1c._1_1_ = (char)((ulong)local_12 >> 0x18);
                FUN_28eb_2aad();
                if (local_8 == (uint *)0x6) {
                  uStack_18._0_1_ = (byte)uStack_e._2_2_;
                  uStack_18._1_1_ = (byte)((uint)uStack_e._2_2_ >> 8);
                  uStack_1a._0_1_ = (char)(uint *)uStack_e;
                  uStack_1a._1_1_ = (char)((uint)(uint *)uStack_e >> 8);
                  uStack_1c._0_1_ = (char)((ulong)local_12 >> 0x10);
                  uStack_1c._1_1_ = (char)((ulong)local_12 >> 0x18);
                  FUN_1a9e_836a();
                }
                uStack_18._0_1_ = (byte)puVar57;
                uStack_18._1_1_ = (byte)((uint)puVar57 >> 8);
                uStack_1a._0_1_ = (char)((int)unaff_DI << 1);
                uStack_1a._1_1_ = (char)((uint)((int)unaff_DI << 1) >> 8);
                uStack_1c._0_1_ = (char)pbVar56;
                uStack_1c._1_1_ = (char)((uint)pbVar56 >> 8);
                func_0x0002ea8f();
                pbVar56 = pbVar56 + (int)puVar57;
                if ((int)unaff_SI < (int)(pbVar56 + (int)puVar57)) {
                  puVar57 = (uint *)((int)unaff_SI - (int)pbVar56);
                  uStack_e._2_2_ = (uint *)((int)puVar57 * (int)unaff_DI);
                  if (local_8 == (uint *)0x6) {
                    uStack_e._2_2_ = (uint *)((uint)uStack_e._2_2_ >> 2);
                  }
                }
              }
            }
          }
        }
        uStack_18._0_1_ = (byte)((ulong)local_12 >> 0x10);
        uStack_18._1_1_ = (byte)((ulong)local_12 >> 0x18);
        uStack_1c._0_1_ = 0x52;
        uStack_1c._1_1_ = 0x27;
        uStack_1a._0_1_ = uVar22;
        uStack_1a._1_1_ = uVar55;
        FUN_1000_130c();
        uVar55 = 0x10;
      }
      uStack_18._0_1_ = (byte)((ulong)local_6 >> 0x10);
      uStack_18._1_1_ = (byte)((ulong)local_6 >> 0x18);
      uStack_1c._0_1_ = 0x5d;
      uStack_1c._1_1_ = 0x27;
      uStack_1a._0_1_ = 0;
      uStack_1a._1_1_ = uVar55;
      FUN_28eb_29db();
      if ((uint *)local_6 != (uint *)0x0) {
        uStack_1c._0_1_ = 0x6e;
        uStack_1c._1_1_ = 0x27;
        uStack_1a._0_1_ = 0;
        uStack_1a._1_1_ = uVar55;
        uStack_18._0_1_ = uVar12;
        uStack_18._1_1_ = uVar13;
        FUN_1a9e_6e73();
      }
      return local_8;
    case 8:
      uStack_18._0_1_ = 0xb;
      uStack_18._1_1_ = 6;
      puVar62 = (uint *)FUN_1a9e_5aa5();
      uVar60 = (undefined2)((ulong)puVar62 >> 0x10);
      puVar57 = (uint *)puVar62;
      for (uVar31 = (uint)in_CX >> 1; uVar31 != 0; uVar31 = uVar31 - 1) {
        puVar5 = puVar57;
        puVar57 = puVar57 + 1;
        puVar4 = puVar25;
        puVar25 = puVar25 + 1;
        *puVar5 = *puVar4;
      }
      for (uVar31 = (uint)(((uint)in_CX & 1) != 0); uVar31 != 0; uVar31 = uVar31 - 1) {
        puVar5 = puVar57;
        puVar57 = (uint *)((int)puVar57 + 1);
        puVar4 = puVar25;
        puVar25 = (uint *)((int)puVar25 + 1);
        *(byte *)puVar5 = (byte)*puVar4;
      }
      return (uint *)puVar62;
    case 9:
      puVar49 = (undefined2 *)&stack0xfffe;
      if (bVar36 == 0) {
        uStack_18 = (uint *)0x2000;
        puVar49 = (undefined2 *)&stack0xfffe;
      }
      goto code_r0x00028359;
    }
    goto switchD_2000_e962_caseD_1;
  }
LAB_2424_3cb3:
  if (param_2[0x5a] == 0) {
    return puVar25;
  }
  uVar31 = param_2[0x5a];
  local_6 = (uint *)CONCAT22(uVar31,(uint *)local_6);
  local_8 = (uint *)(param_2[0x11] - DAT_5b41_0925);
  puVar25 = (uint *)(param_2[0x12] - DAT_5b41_0927);
  local_a = puVar25;
  uStack_18._0_1_ = uVar19;
  uStack_18._1_1_ = uVar21;
  if (10 < uVar31 - 2) {
    uStack_1a = (uint **)&local_12;
    uStack_1c = (uint *)((int)puVar57 + (uVar31 - 1));
    FUN_4551_03eb();
    local_12 = (uint *)CONCAT22((byte *)((int)local_12._2_2_ + (int)local_a),
                                (byte *)((int)(uint *)local_12 + (int)local_8));
    puVar57 = (uint *)FUN_2424_1e00();
    return puVar57;
  }
  puVar42 = (uint *)((uVar31 - 2) * 2);
  pbVar56 = (byte *)0x2000;
  pbVar32 = pbVar56;
  puVar27 = uStack_1c;
  uStack_18 = puVar26;
  uVar22 = 0;
  uVar55 = 0;
  switch(uVar31) {
  case 2:
    do {
      uStack_1c._1_1_ = (char)((uint)puVar27 >> 8);
      uStack_1c._0_1_ = (char)puVar27;
      uVar60 = (undefined2)(CONCAT13(uStack_1c._1_1_,CONCAT12((char)uStack_1c,puStack_1e)) >> 0x10);
      local_6 = (uint *)CONCAT22(puStack_1e[0x17] +
                                 (int)(char)(byte)puStack_1e[(int)((int)puVar26 + 0x3d)],
                                 (uint *)(puStack_1e[0x18] +
                                         (int)(char)*(byte *)((int)puStack_1e +
                                                             puStack_1e[0x17] * 2 + 0x7b)));
      if ((pbStack_20 == in_stack_0000ffd8) &&
         (puVar42 = puStack_2c, pbVar32 = pbVar56, in_stack_0000ffde == in_stack_0000ffd6)) {
switchD_2000_7f29_caseD_6:
        uStack_18._0_1_ = 3;
        uStack_18._1_1_ = 0;
        uStack_1a._0_1_ = (char)puVar42;
        uStack_1a._1_1_ = (char)((uint)puVar42 >> 8);
        pbVar56 = (byte *)0x28eb;
        in_stack_0000ffde = (uint *)0x561b;
        uStack_1c = puVar27;
        unaff_DI = (uint *)FUN_28eb_3b36();
        pbStack_20 = pbVar32;
      }
      local_8 = (uint *)(in_stack_0000ffde[0x17] +
                        (int)(char)(byte)in_stack_0000ffde[(int)((int)uStack_1a + 0x3d)]);
      uVar31 = in_stack_0000ffde[0x18];
      uStack_18._0_1_ = (byte)uVar31;
      uStack_18._1_1_ = (byte)(uVar31 >> 8);
      local_a = (uint *)(uVar31 + (int)(char)*(byte *)((int)in_stack_0000ffde +
                                                      (int)uStack_1a * 2 + 0x7b));
      if ((int)local_6._2_2_ < (int)local_8) {
        uStack_e._2_2_ = (uint *)((int)local_6._2_2_ - DAT_5b41_0925);
        puVar57 = local_8;
      }
      else {
        uStack_e._2_2_ = (uint *)((int)local_8 - DAT_5b41_0925);
        puVar57 = local_6._2_2_;
      }
      if ((int)(uint *)local_6 < (int)local_a) {
        uStack_e._0_2_ = (uint *)((int)(uint *)local_6 - DAT_5b41_0927);
        puVar25 = local_a;
      }
      else {
        uStack_e._0_2_ = (uint *)((int)local_a - DAT_5b41_0927);
        puVar25 = (uint *)local_6;
      }
      iVar53 = (int)puVar25 - DAT_5b41_0927;
      if (0 < (int)unaff_DI) {
        iVar53 = iVar53 + ((int)unaff_DI >> 1);
      }
      puVar25 = (uint *)(uint)(((int)puVar57 - DAT_5b41_0925) - (int)uStack_e._2_2_ <
                              iVar53 - (int)(uint *)uStack_e);
      uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ - (int)puVar25);
      local_12 = (uint *)CONCAT22((byte *)(((int)puVar57 - DAT_5b41_0925) + (int)puVar25),puVar25);
      uStack_e._0_2_ = (uint *)((int)(uint *)uStack_e - (uint)(puVar25 == (uint *)0x0));
      puVar57 = (uint *)(iVar53 + (uint)(puVar25 == (uint *)0x0));
      for (puVar49 = DAT_5b41_04ac; puStack_1e = in_stack_0000ffde, puVar49 != (undefined2 *)0x0;
          puVar49 = (undefined2 *)*puVar49) {
LAB_2424_14aa:
        if ((((puVar49[6] == 1) && ((int)puVar49[1] <= (int)local_12._2_2_)) &&
            ((int)uStack_e._2_2_ <= (int)puVar49[3])) &&
           (((int)puVar49[2] <= (int)puVar57 && ((int)(uint *)uStack_e <= (int)puVar49[4])))) {
          uStack_18._0_1_ = 0x81;
          uStack_18._1_1_ = 0;
          pbVar56 = (byte *)0x28eb;
          uStack_1c._0_1_ = uVar12;
          uStack_1c._1_1_ = uVar13;
          uStack_1a._0_1_ = uVar15;
          uStack_1a._1_1_ = uVar17;
          FUN_28eb_2d82();
          puStack_1e = in_stack_0000ffd6;
          pbStack_20 = in_stack_0000ffd8;
          break;
        }
      }
      puVar26 = (uint *)CONCAT11(uStack_18._1_1_,(byte)uStack_18);
      if ((pbStack_20 == in_stack_0000ffd8) && (puStack_1e == in_stack_0000ffd6)) {
        pbStack_20 = (byte *)0x0;
        in_stack_0000ffde = (uint *)0x0;
        uStack_1c._0_1_ = 0;
        uStack_1c._1_1_ = 0;
        puStack_1e = (uint *)0x0;
      }
      else {
        uStack_1c._0_1_ = (char)pbStack_20;
        uStack_1c._1_1_ = (char)((uint)pbStack_20 >> 8);
        in_stack_0000ffde = (uint *)puStack_1e[0x2f];
        pbStack_20 = (byte *)puStack_1e[0x30];
      }
      puVar27 = (uint *)CONCAT11(uStack_1c._1_1_,(char)uStack_1c);
      if ((puStack_1e == (uint *)0x0 && puVar27 == (uint *)0x0) ||
         (in_stack_0000ffde == (uint *)0x0 && pbStack_20 == (byte *)0x0)) {
        return (uint *)0x0;
      }
      if (((undefined4 *)CONCAT11(uStack_1c._1_1_,(char)uStack_1c) != uStack_24) ||
         (puStack_1e != puStack_26)) {
        puVar26 = (uint *)0x1;
        unaff_DI = (uint *)0x0;
      }
    } while( true );
  case 3:
    uStack_18._0_1_ = 0x8e;
    uStack_18._1_1_ = 0xec;
    iVar53 = FUN_2e67_07f1();
    if (iVar53 != 0 || in_DX != (uint *)0x0) goto LAB_2e67_069a;
    if ((DAT_5b41_0be6 != 0) && ((DAT_5b41_0be6 != 0 || (param_4 != (uint *)0x0)))) {
      uStack_18._0_1_ = 0xb0;
      uStack_18._1_1_ = 0xec;
      FUN_2e67_03fe();
    }
    if (DAT_5b41_0be4 != 0) {
      uStack_18._0_1_ = 0xc2;
      uStack_18._1_1_ = 0xec;
      FUN_2e67_03fe();
    }
    uStack_18._0_1_ = 0xca;
    uStack_18._1_1_ = 0xec;
    FUN_2e67_02b5();
    uStack_18._0_1_ = 0xd2;
    uStack_18._1_1_ = 0xec;
    FUN_460e_2140();
    uStack_18._0_1_ = 1;
    uStack_18._1_1_ = 0;
    uStack_1a._0_1_ = 0;
    uStack_1a._1_1_ = 0;
    uStack_1c._0_1_ = 0xe;
    uStack_1c._1_1_ = 0x46;
    iVar53 = FUN_460e_22ac();
    if (iVar53 == 0) {
      uStack_18._0_1_ = 0xe;
      uStack_18._1_1_ = 0x46;
      uStack_1a._0_1_ = 0xe9;
      uStack_1a._1_1_ = 0xec;
      iVar53 = FUN_4bdc_3a34();
      if (iVar53 != 0) goto LAB_2e67_0680;
      uVar31 = 0;
    }
    else {
LAB_2e67_0680:
      uVar31 = 1;
    }
    local_6 = (uint *)((ulong)uVar31 << 0x10);
    if (uVar31 != 0) {
      DAT_5b41_0be8 = param_3;
      DAT_5b41_0be6 = 0;
    }
LAB_2e67_069a:
    return local_6._2_2_;
  case 4:
    uStack_18._0_1_ = 0x59;
    uStack_18._1_1_ = 0x33;
    FUN_2321_0b53();
    local_6 = (uint *)0xd2000;
    local_8 = (uint *)((char *)s_SOUND_RES_554c_3365 + 4);
    iVar53 = FUN_1a9e_5dc8();
    if (iVar53 == 0) {
      local_6 = (uint *)CONCAT22(0x3377,(uint *)local_6);
      FUN_3f2b_0f46();
      local_6 = (uint *)0x3f2b337e;
      FUN_1000_17bf();
    }
    local_6 = (uint *)CONCAT22(0x3389,(uint *)local_6);
    DAT_5b41_0527 = FUN_1a9e_213d();
    local_6 = (uint *)CONCAT22((char *)s_GRAVITY_ITF_554c_3396 + 5,(uint *)local_6);
    DAT_5b41_0529 = in_DX;
    DAT_5b41_052b = FUN_1a9e_213d();
    local_6 = (uint *)CONCAT22(0x33ad,(uint *)local_6);
    DAT_5b41_052d = in_DX;
    DAT_5b41_052f = FUN_1a9e_213d();
    local_6 = (uint *)0x1a9e33c4;
    DAT_5b41_0531 = in_DX;
    FUN_1a9e_2342();
    local_6 = (uint *)0x1a9e;
    local_8 = (uint *)0x33cb;
    FUN_1a9e_48fc();
    local_6._0_2_ = (uint *)0x1a9e;
    local_8 = (uint *)0x33d0;
    FUN_1a9e_5cd8();
    local_6 = (uint *)CONCAT22(local_6._2_2_,0xd);
    local_8 = (uint *)0x1a9e;
    local_a = (uint *)0x33d7;
    FUN_1a9e_3f33();
    local_8 = (uint *)0x4;
    local_a = (uint *)0x2321;
    uStack_e._2_2_ = (uint *)0x4db;
    uStack_e._0_2_ = (uint *)0x1a9e;
    local_12 = (uint *)CONCAT22(0x33e4,(uint *)local_12);
    FUN_1a9e_3ec6();
    uStack_e._0_2_ = (uint *)0x222;
    local_12 = (uint *)0xc3501a9e;
    FUN_4340_0133();
    for (iVar53 = 0; iVar53 < 0x32; iVar53 = iVar53 + 1) {
      local_6 = (uint *)CONCAT22((char *)s_PROFESOR_RES_554c_33f9 + 7,(uint *)local_6);
      FUN_4340_06ef();
      local_6._0_2_ = (uint *)((char *)s_HELP_RES_554c_340f + 1);
      local_6._2_2_ = (uint *)0x4340;
      uVar60 = FUN_4340_0d94();
      *(undefined2 *)(iVar53 << 2) = uVar60;
      local_6 = (uint *)CONCAT22((uint *)local_6,0x4340);
      local_8 = (uint *)0x342f;
      FUN_4340_0caf();
      local_6 = (uint *)0x4340343a;
      uVar60 = FUN_4340_0d94();
      *(undefined2 *)(iVar53 * 4 + 2) = uVar60;
    }
    local_6 = (uint *)0x4340345c;
    FUN_4340_0133();
    local_6 = (uint *)0x1;
    local_8 = (uint *)0x4340;
    local_a = (uint *)0x3465;
    FUN_406b_0198();
    local_8 = (uint *)0x3;
    local_a = (uint *)0x406b;
    uStack_e._2_2_ = (uint *)0x346c;
    FUN_406b_0e04();
    local_a = (uint *)(DAT_554c_49ac / 2);
    uStack_e._2_2_ = (uint *)(DAT_554c_49aa / 2);
    uStack_e._0_2_ = (uint *)0x406b;
    local_12 = (uint *)CONCAT22(0x3483,(uint *)local_12);
    FUN_406b_0c62();
    uStack_e._0_2_ = (uint *)0x51a7;
    local_12 = (uint *)0x22d;
    FUN_406b_02f2();
    uStack_18._0_1_ = 0x6b;
    uStack_18._1_1_ = 0x40;
    uStack_1a._0_1_ = 0x9a;
    uStack_1a._1_1_ = 0x34;
    FUN_406b_03cb();
    uStack_18._0_1_ = 0x40;
    uStack_18._1_1_ = 2;
    uStack_1a._0_1_ = 0x39;
    uStack_1a._1_1_ = 2;
    uStack_1c._0_1_ = (char)DAT_554c_3e64;
    uStack_1c._1_1_ = (char)((uint)DAT_554c_3e64 >> 8);
    FUN_2e67_00fd();
    FUN_2e67_08c9();
    DAT_554c_02e8 = FUN_2321_05a9();
    for (iVar53 = 1; iVar53 < 999; iVar53 = iVar53 + 1) {
      local_6 = (uint *)CONCAT22(0x34ca,(uint *)local_6);
      FUN_2e67_02b5();
    }
    local_6 = (uint *)CONCAT22(0x34dc,(uint *)local_6);
    DAT_5b41_0533 = FUN_4340_0849();
    local_6 = (uint *)CONCAT22(0x34ea,(uint *)local_6);
    DAT_5b41_0535 = FUN_4340_0849();
    DAT_554c_3d4e = 0;
    if (((DAT_554c_3d52 == 0) && (DAT_554c_3d57 != '\0')) && (DAT_554c_3d4e = 1, 8 < DAT_554c_3d54))
    {
      DAT_554c_3d4e = 5;
    }
    local_6 = (uint *)0x43403522;
    DAT_5b41_0523 = FUN_3e34_0836();
    local_6 = (uint *)CONCAT22(0x3530,(uint *)local_6);
    DAT_5b41_050d = FUN_4551_0002();
    local_6 = (uint *)CONCAT22((char *)s_PROG_d_ITF_554c_3538 + 5,(uint *)local_6);
    FUN_1a3f_0001();
    local_6 = (uint *)CONCAT22((char *)s_PROG_d_ITF_554c_3538 + 10,(uint *)local_6);
    func_0x00054aab();
    local_6 = (uint *)CONCAT22((char *)s_PROGPART_ANM_554c_3543 + 4,(uint *)local_6);
    FUN_28eb_4dea();
    local_6 = (uint *)0x28eb354f;
    FUN_2424_087c();
    local_6 = (uint *)0x2424;
    local_8 = (uint *)0x3556;
    func_0x00055048();
    DAT_5b41_096b = 0;
    local_6 = (uint *)0x54fb3568;
    DAT_5b41_0472 = (uint *)FUN_1000_12bf();
    puVar57 = DAT_5b41_0472;
    DAT_5b41_096d = DAT_5b41_0472;
    for (iVar53 = 0x13; iVar53 != 0; iVar53 = iVar53 + -1) {
      *puVar57 = (uint)(puVar57 + 5);
      puVar57 = puVar57 + 5;
    }
    return puVar57;
  case 5:
    return (uint *)(unaff_BP * -0x3b7d);
  case 6:
    goto switchD_2000_7f29_caseD_6;
  case 7:
    uVar22 = 1;
    uVar55 = 0;
    in_CX = (uint *)(uint)(byte)((byte)in_CX | (byte)((uint)in_CX >> 8));
    do {
      local_6 = (uint *)((ulong)local_6 & 0x3fffff);
      uStack_18._0_1_ = (byte)((ulong)local_6 >> 0x10);
      uStack_18._1_1_ = 0;
      uStack_1a._0_1_ = 0;
      uStack_1a._1_1_ = 0x20;
      uStack_1c._0_1_ = -0x60;
      uStack_1c._1_1_ = '\x0e';
      puVar25 = (uint *)FUN_1a9e_60f0();
      local_6 = (uint *)CONCAT22(local_6._2_2_,puVar25);
      DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc + (int)local_6._2_2_);
      uStack_24 = (undefined4 *)((uint)uStack_24 & 0xff00);
      uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + 1);
      uStack_18._0_1_ = (byte)puVar57;
      uStack_18._1_1_ = (byte)((uint)puVar57 >> 8);
      if (((uint)param_5 & 2) != 0) {
        unaff_DI = (uint *)((int)param_3 - (int)puVar25);
        if ((char)uStack_1c != '\0') {
          if (uStack_1c._1_1_ == '\0') goto LAB_1a9e_62c7;
          if (((int)unaff_DI < DAT_554c_42c4) || (DAT_554c_42c6 <= (int)param_3)) {
            if ((int)unaff_DI < DAT_554c_42c4) {
              puVar26 = (uint *)((int)puVar25 - (DAT_554c_42c4 - (int)unaff_DI));
              local_6 = (uint *)CONCAT22(local_6._2_2_,puVar26);
              if (puVar26 != (uint *)0x0 && DAT_554c_42c4 - (int)unaff_DI <= (int)puVar25)
              goto LAB_1a9e_650e;
            }
            else {
              puVar26 = (uint *)((int)puVar25 - ((int)param_3 - DAT_554c_42c6));
              local_6 = (uint *)CONCAT22(local_6._2_2_,puVar26);
              if (puVar26 != (uint *)0x0 && (int)param_3 - DAT_554c_42c6 <= (int)puVar25)
              goto LAB_1a9e_650e;
            }
            goto LAB_1a9e_62c7;
          }
        }
LAB_1a9e_650e:
        in_CX = (uint *)(uint)(byte)local_6;
        uStack_1a._0_1_ = 0;
        uStack_1a._1_1_ = 0x20;
        uStack_1c._0_1_ = 0xf;
        uStack_1c._1_1_ = 0xf;
        (*DAT_554c_4d9e)();
        puVar57 = (uint *)CONCAT11(uStack_18._1_1_,(byte)uStack_18);
        goto LAB_1a9e_62c7;
      }
      unaff_DI = (uint *)((int)param_3 + (int)puVar25);
      if ((char)uStack_1c == '\0') {
LAB_1a9e_659b:
        in_CX = (uint *)(uint)(byte)local_6;
        uStack_1a._0_1_ = 0;
        uStack_1a._1_1_ = 0x20;
        uStack_1c._0_1_ = 0x99;
        uStack_1c._1_1_ = 0xf;
        (*DAT_554c_4d9e)();
        puVar57 = (uint *)CONCAT11(uStack_18._1_1_,(byte)uStack_18);
      }
      else {
        if (uStack_1c._1_1_ == '\0') goto LAB_1a9e_62c7;
        if ((DAT_554c_42c4 <= (int)param_3) && ((int)unaff_DI <= DAT_554c_42c6)) goto LAB_1a9e_659b;
        if ((int)param_3 < DAT_554c_42c4) {
          puVar26 = (uint *)((int)puVar25 - (DAT_554c_42c4 - (int)param_3));
          local_6 = (uint *)CONCAT22(local_6._2_2_,puVar26);
          if (puVar26 != (uint *)0x0 && DAT_554c_42c4 - (int)param_3 <= (int)puVar25)
          goto LAB_1a9e_659b;
        }
        else {
          pbVar56 = (byte *)((int)unaff_DI + (-1 - DAT_554c_42c6));
          puVar26 = (uint *)((int)puVar25 - (int)pbVar56);
          local_6 = (uint *)CONCAT22(local_6._2_2_,puVar26);
          if (puVar26 != (uint *)0x0 && (int)pbVar56 <= (int)puVar25) goto LAB_1a9e_659b;
        }
      }
LAB_1a9e_62c7:
      param_3 = unaff_DI;
      bVar36 = (byte)*(uint *)CONCAT22(local_a,uStack_e._2_2_);
      local_6 = (uint *)(ulong)CONCAT12(bVar36,(uint *)local_6);
      uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + 1);
      if ((bVar36 & 0x80) == 0) {
        if ((bVar36 & 0x40) == 0) {
          local_6 = (uint *)((ulong)local_6 & 0x3fffff);
          uStack_18 = (uint *)-(int)local_6._2_2_;
          uStack_1a._0_1_ = 0;
          uStack_1a._1_1_ = 0x20;
          uStack_1c._0_1_ = ',';
          uStack_1c._1_1_ = 0x10;
          uVar31 = FUN_1a9e_60f0();
          iVar43 = (uVar31 ^ (int)uVar31 >> 0xf) - ((int)uVar31 >> 0xf);
          DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc - (int)local_6._2_2_);
          iVar53 = iVar43;
          if (((uint)param_5 & 2) == 0) {
            iVar53 = -iVar43;
          }
          param_3 = (uint *)((int)param_3 + iVar53);
          bVar36 = (byte)*(uint *)CONCAT22(local_a,uStack_e._2_2_);
          local_6 = (uint *)(ulong)CONCAT12(bVar36,iVar43);
          if ((bVar36 & 0xc0) == 0) {
            local_12 = (uint *)(CONCAT22(local_12._2_2_,(uint)bVar36) & 0xffff003f);
            if ((bVar36 & 0x3f) != 0) {
              uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + 1);
              in_CX = (uint *)0x6;
              puVar25 = (uint *)((int)(uint *)local_12 << 6);
              local_12 = (uint *)CONCAT22(local_12._2_2_,puVar25);
              uStack_18._0_1_ = (byte)puVar25;
              uStack_18._1_1_ = (byte)((uint)puVar25 >> 8);
              uStack_1a._0_1_ = 0;
              uStack_1a._1_1_ = 0x20;
              uStack_1c._0_1_ = '{';
              uStack_1c._1_1_ = 0x10;
              uVar31 = FUN_1a9e_60f0();
              local_6 = (uint *)(ulong)uVar31;
              DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc - (int)(uint *)local_12);
              if (((uint)param_5 & 2) == 0) {
                param_3 = (uint *)((int)param_3 + -uVar31);
              }
              else {
                param_3 = (uint *)((int)param_3 + uVar31);
              }
            }
          }
          bVar61 = CARRY2((uint)puStack_2c,(uint)in_stack_0000ffd8);
          puStack_2c = (uint *)((int)puStack_2c + (int)in_stack_0000ffd8);
          in_stack_0000ffd6 = (uint *)((byte *)((int)in_stack_0000ffd6 + (int)puStack_26) + bVar61);
          if (puStack_2e == in_stack_0000ffd6) {
            local_a = (uint *)uStack_e;
            uStack_e._2_2_ = local_12._2_2_;
            param_3 = (uint *)pbStack_30;
            DAT_5b41_26dc = puStack_34;
          }
          else {
            uVar31 = (int)in_stack_0000ffd6 - (int)puStack_2e >> 0xf;
            iVar53 = (((int)in_stack_0000ffd6 - (int)puStack_2e ^ uVar31) - uVar31) + -1;
            if (iVar53 != 0) {
              while (iVar53 != 0) {
                bVar36 = (byte)*(uint *)CONCAT22(local_a,uStack_e._2_2_);
                uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + 1);
                uStack_18._0_1_ = bVar36 & 0x3f;
                local_6 = (uint *)((ulong)CONCAT12(bVar36,(uint)bVar36) & 0xffff003f);
                uStack_18._1_1_ = 0;
                uStack_1a._0_1_ = 0;
                uStack_1a._1_1_ = 0x20;
                uStack_1c._0_1_ = '\x06';
                uStack_1c._1_1_ = 0x11;
                local_8 = (uint *)FUN_1a9e_60f0();
                iVar53 = CONCAT11(uStack_18._1_1_,(byte)uStack_18);
                if (((uint)param_5 & 2) != 0) {
                  local_8 = (uint *)-(int)local_8;
                }
                if (((ulong)local_6 & 0x800000) == 0) {
                  if (((ulong)local_6 & 0x400000) == 0) {
                    DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc - (int)(uint *)local_6);
                    param_3 = (uint *)((int)param_3 + -(int)local_8);
                    bVar36 = (byte)*(uint *)CONCAT22(local_a,uStack_e._2_2_);
                    local_6 = (uint *)(ulong)CONCAT12(bVar36,(uint *)local_6);
                    if ((bVar36 & 0xc0) == 0) {
                      local_12 = (uint *)(CONCAT22(local_12._2_2_,(uint)bVar36) & 0xffff003f);
                      if ((bVar36 & 0x3f) != 0) {
                        uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + 1);
                        in_CX = (uint *)0x6;
                        puVar25 = (uint *)((int)(uint *)local_12 << 6);
                        local_12 = (uint *)CONCAT22(local_12._2_2_,puVar25);
                        uStack_18._0_1_ = (byte)puVar25;
                        uStack_18._1_1_ = (byte)((uint)puVar25 >> 8);
                        uStack_1a._0_1_ = 0;
                        uStack_1a._1_1_ = 0x20;
                        uStack_1c._0_1_ = -0x56;
                        uStack_1c._1_1_ = 0x11;
                        uVar31 = FUN_1a9e_60f0();
                        local_6 = (uint *)(ulong)uVar31;
                        DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc - (int)(uint *)local_12);
                        if (((uint)param_5 & 2) == 0) {
                          param_3 = (uint *)((int)param_3 + -uVar31);
                        }
                        else {
                          param_3 = (uint *)((int)param_3 + uVar31);
                        }
                      }
                    }
                    iVar53 = CONCAT11(uStack_18._1_1_,(byte)uStack_18) + -1;
                  }
                  else {
                    if ((uint *)local_6 == (uint *)0x0) {
                      return local_8;
                    }
                    DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc + (int)(uint *)local_6);
                    param_3 = (uint *)((int)param_3 + (int)local_8);
                  }
                }
                else {
                  DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc + (int)(uint *)local_6);
                  if (((ulong)local_6 & 0x400000) == 0) {
                    param_3 = (uint *)((int)param_3 + (int)local_8);
                    uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + 1);
                    iVar53 = CONCAT11(uStack_18._1_1_,(byte)uStack_18);
                  }
                  else {
                    param_3 = (uint *)((int)param_3 + (int)local_8);
                    uStack_e._2_2_ =
                         (uint *)((int)uStack_e._2_2_ + ((int)((int)(uint *)local_6 + 1) >> 1));
                    iVar53 = CONCAT11(uStack_18._1_1_,(byte)uStack_18);
                  }
                }
              }
            }
          }
          uStack_e._0_2_ = local_a;
          local_12 = (uint *)CONCAT22(uStack_e._2_2_,(uint *)local_12);
          pbStack_30 = (byte *)param_3;
          puStack_34 = DAT_5b41_26dc;
          param_7 = param_7 + -1;
          if (param_7 == 0) {
            return DAT_5b41_26dc;
          }
          if (((uint)param_5 & 2) == 0) {
            iVar53 = ((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc];
          }
          else {
            iVar53 = -((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc];
          }
          param_4 = (uint *)((int)param_4 + (int)unaff_SI);
          unaff_DI = (uint *)((int)puStack_32 + iVar53);
          puStack_2e = in_stack_0000ffd6;
          if ((char)uStack_1c != '\0') {
            if ((DAT_554c_42ca < (int)param_4) || ((int)param_4 < DAT_554c_42c8)) {
              bVar61 = false;
            }
            else {
              bVar61 = true;
            }
            if (!bVar61) goto LAB_1a9e_62c7;
          }
          goto LAB_1a9e_62c7;
        }
        uStack_18._0_1_ = bVar36 & 0x3f;
        local_6 = (uint *)((ulong)local_6 & 0x3fffff);
        if ((bVar36 & 0x3f) == 0) {
          return (uint *)(uint)bVar36;
        }
        uStack_18._1_1_ = 0;
        uStack_1a._0_1_ = 0;
        uStack_1a._1_1_ = 0x20;
        uStack_1c._0_1_ = 0xed;
        uStack_1c._1_1_ = 0xf;
        puVar25 = (uint *)FUN_1a9e_60f0();
        local_6 = (uint *)CONCAT22(local_6._2_2_,puVar25);
        DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc + (int)local_6._2_2_);
        if (((uint)param_5 & 2) == 0) {
          unaff_DI = (uint *)((int)param_3 + (int)puVar25);
        }
        else {
          unaff_DI = (uint *)((int)param_3 - (int)puVar25);
        }
        goto LAB_1a9e_62c7;
      }
      if ((bVar36 & 0x40) != 0) {
        local_6._2_2_ = (uint *)(bVar36 & 0x3f);
        local_6._0_2_ = local_6._2_2_;
        uStack_18._0_1_ = (byte)local_6._2_2_;
        uStack_18._1_1_ = 0;
        uStack_1a._0_1_ = 0;
        uStack_1a._1_1_ = 0x20;
        uStack_1c._0_1_ = -0x28;
        uStack_1c._1_1_ = '\f';
        puVar25 = (uint *)FUN_1a9e_60f0();
        local_6 = (uint *)CONCAT22(local_6._2_2_,puVar25);
        uStack_18._0_1_ = uVar22;
        uStack_18._1_1_ = uVar55;
        if (local_6._2_2_ != (uint *)0x0) {
          local_12 = (uint *)CONCAT22(local_12._2_2_,
                                      (uint *)*(undefined2 *)
                                               (((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc] *
                                                2 + 0x7cf2));
          uStack_18._0_1_ = (byte)puVar57;
          uStack_18._1_1_ = (byte)((uint)puVar57 >> 8);
          pcVar59 = acStack_174;
          iVar53 = ((undefined2 *)&DAT_5b41_20c2)[(int)DAT_5b41_26dc] << 1;
          uStack_1a._0_1_ = uVar22;
          uStack_1a._1_1_ = uVar55;
          if (0 < (int)puVar25) {
            puVar57 = puVar25;
            do {
              while( true ) {
                uVar31 = *(int *)(iVar53 + 0x7cf2) - (int)(uint *)local_12;
                uVar33 = uVar31 >> 1;
                if ((uVar31 & 1) == 0) break;
                pcVar3 = pcVar59;
                pcVar59 = pcVar59 + 1;
                *pcVar3 = (*(byte *)((int)uStack_e._2_2_ + uVar33) & 0xf) + uStack_24._1_1_;
                iVar53 = iVar53 + 2;
                puVar57 = (uint *)((int)puVar57 + -1);
                if (puVar57 == (uint *)0x0) {
                  puVar25 = (uint *)0x0;
                  goto LAB_1a9e_6371;
                }
              }
              pcVar3 = pcVar59;
              pcVar59 = pcVar59 + 1;
              *pcVar3 = (*(byte *)((int)uStack_e._2_2_ + uVar33) >> 4) + uStack_24._1_1_;
              iVar53 = iVar53 + 2;
              puVar57 = (uint *)((int)puVar57 + -1);
              puVar25 = (uint *)0x0;
            } while (puVar57 != (uint *)0x0);
          }
LAB_1a9e_6371:
          puVar57 = (uint *)CONCAT11(uStack_18._1_1_,(byte)uStack_18);
          uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + ((int)local_6._2_2_ + 1 >> 1));
          in_CX = puVar25;
          uStack_18._0_1_ = (char)uStack_1a;
          uStack_18._1_1_ = uStack_1a._1_1_;
        }
        DAT_5b41_26dc = (uint *)((int)DAT_5b41_26dc + (int)local_6._2_2_);
        puVar26 = (uint *)local_6;
        unaff_DI = param_3;
        uVar22 = (byte)uStack_18;
        uVar55 = uStack_18._1_1_;
        if ((uint *)local_6 != (uint *)0x0) {
          uStack_1a._0_1_ = (char)acStack_174;
          uStack_1a._1_1_ = (char)((uint)acStack_174 >> 8);
          if (((uint)param_5 & 2) != 0) {
            unaff_DI = (uint *)((int)param_3 - (int)(uint *)local_6);
            if ((char)uStack_1c != '\0') {
              if (uStack_1c._1_1_ == '\0') goto LAB_1a9e_62c7;
              if (((int)unaff_DI < DAT_554c_42c4) || (DAT_554c_42c6 <= (int)param_3)) {
                puVar25 = param_3;
                if ((int)unaff_DI < DAT_554c_42c4) {
                  local_6._0_2_ = (uint *)((int)(uint *)local_6 - (DAT_554c_42c4 - (int)unaff_DI));
                  if ((uint *)local_6 == (uint *)0x0 || (int)puVar26 < DAT_554c_42c4 - (int)unaff_DI
                     ) goto LAB_1a9e_62c7;
                }
                else {
switchD_2000_7f29_caseD_8:
                  uStack_18._1_1_ = uVar55;
                  uStack_18._0_1_ = uVar22;
                  (&stack0x0844)[(int)puVar57] = (&stack0x0844)[(int)puVar57] + (char)in_CX;
                  puVar28 = (uint *)local_6;
                  puVar26 = (uint *)((int)(uint *)local_6 - ((int)puVar25 + DAT_554c_42c6));
                  local_6 = (uint *)CONCAT22(local_6._2_2_,puVar26);
                  uVar22 = (byte)uStack_18;
                  uVar55 = uStack_18._1_1_;
                  if (puVar26 == (uint *)0x0 || (int)puVar28 < (int)((int)puVar25 + DAT_554c_42c6))
                  goto LAB_1a9e_62c7;
                }
              }
            }
            uStack_1a._0_1_ = (char)puVar57;
            uStack_1a._1_1_ = (char)((uint)puVar57 >> 8);
            in_CX = (uint *)(uint)(byte)local_6;
            uStack_1c._0_1_ = 0;
            uStack_1c._1_1_ = 0x20;
            (*DAT_554c_4e0e)();
            puVar57 = (uint *)CONCAT11(uStack_1a._1_1_,(char)uStack_1a);
            uVar22 = (byte)uStack_18;
            uVar55 = uStack_18._1_1_;
            goto LAB_1a9e_62c7;
          }
          unaff_DI = (uint *)((int)param_3 + (int)(uint *)local_6);
          if ((char)uStack_1c != '\0') {
            if (uStack_1c._1_1_ == '\0') goto LAB_1a9e_62c7;
            if (((int)param_3 < DAT_554c_42c4) || (DAT_554c_42c6 < (int)unaff_DI)) {
              if ((int)param_3 < DAT_554c_42c4) {
                local_6._0_2_ = (uint *)((int)(uint *)local_6 - (DAT_554c_42c4 - (int)param_3));
                if ((uint *)local_6 == (uint *)0x0 || (int)puVar26 < DAT_554c_42c4 - (int)param_3)
                goto LAB_1a9e_62c7;
              }
              else {
                pbVar56 = (byte *)((int)unaff_DI + (-1 - DAT_554c_42c6));
                local_6._0_2_ = (uint *)((int)(uint *)local_6 - (int)pbVar56);
                if ((uint *)local_6 == (uint *)0x0 || (int)puVar26 < (int)pbVar56)
                goto LAB_1a9e_62c7;
              }
            }
          }
          uStack_1a._0_1_ = (char)puVar57;
          uStack_1a._1_1_ = (char)((uint)puVar57 >> 8);
          in_CX = (uint *)(uint)(byte)local_6;
          uStack_1c._0_1_ = 0;
          uStack_1c._1_1_ = 0x20;
          (*DAT_554c_4e0e)();
          puVar57 = (uint *)CONCAT11(uStack_1a._1_1_,(char)uStack_1a);
          uVar22 = (byte)uStack_18;
          uVar55 = uStack_18._1_1_;
        }
        goto LAB_1a9e_62c7;
      }
    } while( true );
  case 8:
    goto switchD_2000_7f29_caseD_8;
  case 9:
    cRam000554cc = cRam000554cc + (char)((uint)in_DX >> 8);
    if (puVar25 == (uint *)0x54) {
      return (uint *)0x1;
    }
    return (uint *)0x0;
  case 10:
    goto switchD_2000_8bda_caseD_6;
  case 0xc:
    if (puVar25 == (uint *)0x0) {
      uStack_18._0_1_ = 0;
      uStack_18._1_1_ = 0;
      uStack_1a._0_1_ = 0;
      uStack_1a._1_1_ = 0;
      uStack_1c._0_1_ = 0;
      uStack_1c._1_1_ = 0;
      uStack_e = (uint *)FUN_2fc8_00fc();
      local_a = (uint *)(uint)(uStack_e == (uint *)0x0);
    }
    puVar62 = uStack_e;
    if (local_a == (uint *)0x0) {
      uStack_18._0_1_ = (byte)local_6;
      uStack_18._1_1_ = (byte)((ulong)local_6 >> 8);
      uStack_1a._0_1_ = (char)((ulong)uStack_e >> 0x10);
      uStack_1a._1_1_ = (char)((ulong)uStack_e >> 0x18);
      uStack_1c._0_1_ = (char)uStack_e;
      uStack_1c._1_1_ = (char)((ulong)uStack_e >> 8);
      puVar25 = (uint *)FUN_28eb_2aad();
      local_a = (uint *)(uint)(puVar25 != (uint *)local_6);
      puVar62 = uStack_e;
    }
    uStack_e._2_2_ = (uint *)((ulong)puVar62 >> 0x10);
    uStack_e._0_2_ = (uint *)puVar62;
    puVar4 = (uint *)CONCAT22(DAT_5b41_2678,DAT_5b41_2676);
    if (local_a == (uint *)0x0) {
      DAT_5b41_2626 = (uint *)uStack_e + (byte)DAT_554c_4330;
      _DAT_5b41_2628 = (int)uStack_e._2_2_;
      uStack_e._0_2_ = (uint *)((int)DAT_5b41_2626 + (uint)(byte)DAT_554c_4330);
      DAT_5b41_25d8 = (int)uStack_e._2_2_;
      DAT_5b41_25d6 = (uint *)uStack_e;
      puVar4 = puVar62;
    }
    DAT_5b41_2678 = (undefined2)((ulong)puVar4 >> 0x10);
    DAT_5b41_2676 = (uint *)puVar4;
    uStack_18._0_1_ = (byte)local_8;
    uStack_18._1_1_ = (byte)((uint)local_8 >> 8);
    uStack_1a._0_1_ = 0;
    uStack_1a._1_1_ = 0x20;
    uStack_1c._0_1_ = 0xb6;
    uStack_1c._1_1_ = 0x1a;
    FUN_28eb_29db();
    if ((local_a != (uint *)0x0) &&
       ((uint *)uStack_e != (uint *)0x0 || uStack_e._2_2_ != (uint *)0x0)) {
      uStack_18._0_1_ = (byte)uStack_e._2_2_;
      uStack_18._1_1_ = (byte)((uint)uStack_e._2_2_ >> 8);
      uStack_1a._0_1_ = (char)(uint *)uStack_e;
      uStack_1a._1_1_ = (char)((uint)(uint *)uStack_e >> 8);
      uStack_1c._0_1_ = 0;
      uStack_1c._1_1_ = 0x20;
      func_0x0002fdf5();
    }
    if (local_6._2_2_ != (uint *)0x0) {
      uStack_18._0_1_ = (byte)puVar57;
      uStack_18._1_1_ = (byte)((uint)puVar57 >> 8);
      uStack_1a._0_1_ = 0;
      uStack_1a._1_1_ = 0x20;
      uStack_1c._0_1_ = 0xf;
      uStack_1c._1_1_ = 0x1c;
      FUN_1a9e_6e73();
    }
    return (uint *)0x0;
  }
  uStack_1a = (uint **)&uStack_e;
  uStack_1c = (uint *)((int)puVar57 + (uVar31 - 1));
  pbStack_20 = (byte *)0x2000;
  in_stack_0000ffde = (uint *)0x815a;
  FUN_4551_03eb();
  uStack_e._0_2_ = (uint *)((int)(uint *)uStack_e + (param_2[0x11] - DAT_5b41_0925));
  puVar25 = (uint *)(param_2[0x12] - DAT_5b41_0927);
  uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + (int)puVar25);
  uVar31 = (int)local_6._2_2_ - 1;
  if (uVar31 < 9) {
    puVar42 = (uint *)(uVar31 * 2);
    pbVar56 = (byte *)0x2000;
    uVar60 = 0;
    puVar49 = (undefined2 *)&stack0xfffe;
    puVar26 = param_5;
    switch(uVar31) {
    case 0:
      uStack_1a._0_1_ = 0;
      uStack_1a._1_1_ = 0x20;
      uStack_1c._0_1_ = 0x84;
      uStack_1c._1_1_ = 0;
      uStack_18 = puVar25;
      FUN_2fc8_0364();
      puVar57 = (uint *)0x0;
      if (DAT_554c_5173 < -0x1e) {
        puVar57 = (uint *)0x4;
      }
      else if (0x1d < DAT_554c_5173) {
        puVar57 = (uint *)0x8;
      }
      if (DAT_554c_5175 < -0x1e) {
        puVar57 = (uint *)((uint)puVar57 | 1);
      }
      else if (0x1d < DAT_554c_5175) {
        puVar57 = (uint *)((uint)puVar57 | 2);
      }
      return puVar57;
    case 1:
      uVar31 = puVar42[0x25];
code_r0x000254a4:
      puVar49 = DAT_5b41_04ac;
      local_12._0_2_ = (uint *)(uVar31 + (int)(uint *)uStack_e);
      do {
        while (puVar49 == (undefined2 *)0x0) {
LAB_2424_12ce:
          while( true ) {
            do {
              do {
                do {
                  while( true ) {
                    do {
                      while( true ) {
                        while( true ) {
                          uVar31 = ((uint *)local_6)[1];
                          puVar57 = (uint *)*local_6;
                          local_6 = (uint *)CONCAT22(uVar31,puVar57);
                          if (puVar57 != (uint *)0x0 || uVar31 != 0) break;
                          unaff_SI = (uint *)((int)unaff_SI + 1);
                          if (1 < (int)unaff_SI) {
                            return (uint *)0x0;
                          }
                          if (unaff_SI == (uint *)0x0) {
                            puVar57 = (uint *)&DAT_5b41_054f;
                          }
                          else {
                            puVar57 = (uint *)&DAT_5b41_0557;
                          }
                          local_6 = (uint *)CONCAT22(0x554c,puVar57);
                        }
                        if (DAT_5b41_04b4 == 0) break;
                        DAT_5b41_04b4 = 0;
                        unaff_SI = (uint *)0x0;
                        local_6 = &DAT_5b41_054f;
                      }
                      if ((byte)puVar57[0xc] == 0x80) {
                        *(byte *)(puVar57 + 0xc) = 0;
                      }
                      if ((*(byte *)((int)puVar57 + 0xf) & 0x20) == 0) {
                        local_8 = (uint *)0x0;
                        local_a = (uint *)0x0;
                      }
                      else {
                        local_a = (uint *)puVar57[0x57];
                        local_8 = (uint *)puVar57[0x5a];
                      }
                    } while ((((byte)puVar57[0xc] != 0) ||
                             ((*(byte *)((int)puVar57 + 0xd) & 0x20) != 0)) ||
                            ((*(byte *)((int)puVar57 + 0xf) & 0x40) != 0));
                    uStack_1c._0_1_ = (char)pbVar56;
                    uStack_1a._0_1_ = (char)uStack_1c;
                    uStack_1c._1_1_ = (char)((uint)pbVar56 >> 8);
                    uStack_1a._1_1_ = uStack_1c._1_1_;
                    if ((puVar57[4] != 10) && (puVar57[4] != 0x4c)) break;
                    uStack_18._0_1_ = (byte)uVar31;
                    uStack_18._1_1_ = (byte)(uVar31 >> 8);
                    uStack_1a._0_1_ = (char)puVar57;
                    uStack_1a._1_1_ = (char)((uint)puVar57 >> 8);
                    FUN_2424_12f5();
                  }
                } while (puVar57[4] == 0x31);
                if (puVar57[4] != 8) {
                  uStack_e._2_2_ = (uint *)(puVar57[0x17] - DAT_5b41_0925);
                  uStack_e._0_2_ = (uint *)(puVar57[0x18] - DAT_5b41_0927);
                  local_12 = (uint *)(ZEXT24((byte *)(puVar57[0x24] + (int)uStack_e._2_2_)) << 0x10)
                  ;
                  uVar31 = puVar57[0x25];
                  goto code_r0x000254a4;
                }
                uVar31 = puVar57[0x2c];
              } while (uVar31 == 0);
              uStack_18._0_1_ = (byte)uVar31;
              uStack_18._1_1_ = (byte)(uVar31 >> 8);
              pbVar56 = (byte *)0x28eb;
              uStack_1c._0_1_ = 0xd7;
              uStack_1c._1_1_ = 0x53;
              iVar53 = FUN_28eb_1c08();
            } while (iVar53 == 0);
            if (DAT_5b41_0939 != 9) break;
            if ((((uint *)*(int *)(uVar31 + 8) != DAT_5b41_0567._2_2_) ||
                ((uint *)*(int *)(uVar31 + 6) != (uint *)DAT_5b41_0567)) &&
               (((uint *)*(int *)(uVar31 + 0xc) != DAT_5b41_0567._2_2_ ||
                ((uint *)*(int *)(uVar31 + 10) != (uint *)DAT_5b41_0567)))) break;
            uStack_18._0_1_ = 0xeb;
            uStack_18._1_1_ = 0x28;
            pbVar56 = (byte *)0x28eb;
            uStack_1a._0_1_ = 0x11;
            uStack_1a._1_1_ = 0x54;
            iVar53 = FUN_28eb_4d94();
            if (iVar53 != 0) break;
          }
          pbVar56 = (byte *)0x28eb;
          if (*(int *)(uVar31 + 0xe) < *(int *)(uVar31 + 0x12)) {
            local_12._2_2_ = (uint *)(*(int *)(uVar31 + 0xe) - DAT_5b41_0925);
            iVar53 = *(int *)(uVar31 + 0x1a) - *(int *)(uVar31 + 0xe);
          }
          else {
            local_12._2_2_ = (uint *)(*(int *)(uVar31 + 0x12) - DAT_5b41_0925);
            iVar53 = *(int *)(uVar31 + 0x16) - *(int *)(uVar31 + 0x12);
          }
          puVar49 = DAT_5b41_04ac;
          uStack_e._2_2_ = local_12._2_2_;
          if (*(int *)(uVar31 + 0x10) < *(int *)(uVar31 + 0x14)) {
            uStack_e._0_2_ = (uint *)(*(int *)(uVar31 + 0x10) - DAT_5b41_0927);
            local_12._0_2_ =
                 (uint *)((int)(uint *)uStack_e +
                         (*(int *)(uVar31 + 0x1c) - *(int *)(uVar31 + 0x10)));
            local_12._2_2_ = (uint *)((int)local_12._2_2_ + iVar53);
          }
          else {
            uStack_e._0_2_ = (uint *)(*(int *)(uVar31 + 0x14) - DAT_5b41_0927);
            local_12._0_2_ =
                 (uint *)((int)(uint *)uStack_e +
                         (*(int *)(uVar31 + 0x18) - *(int *)(uVar31 + 0x14)));
            local_12._2_2_ = (uint *)((int)local_12._2_2_ + iVar53);
          }
        }
        if (puVar49[6] == 1) {
          if (((((int)puVar49[1] < (int)local_12._2_2_) && ((int)uStack_e._2_2_ <= (int)puVar49[3]))
              && ((int)puVar49[2] < (int)(uint *)local_12)) &&
             ((int)(uint *)uStack_e <= (int)puVar49[4])) {
LAB_2424_12b5:
            uStack_18._0_1_ = 0x81;
            uStack_18._1_1_ = 0;
            uStack_1a._0_1_ = (char)((ulong)local_6 >> 0x10);
            uStack_1a._1_1_ = (char)((ulong)local_6 >> 0x18);
            uStack_1c._0_1_ = (char)local_6;
            uStack_1c._1_1_ = (char)((ulong)local_6 >> 8);
            pbVar56 = (byte *)0x28eb;
            FUN_28eb_2d82();
            goto LAB_2424_12ce;
          }
          if ((local_8 != (uint *)0x0) || (local_a != (uint *)0x0)) {
            uStack_18._0_1_ = (byte)puVar49;
            uStack_18._1_1_ = (byte)((uint)puVar49 >> 8);
            uStack_1a._0_1_ = (char)((ulong)local_6 >> 0x10);
            uStack_1a._1_1_ = (char)((ulong)local_6 >> 0x18);
            uStack_1c._0_1_ = (char)local_6;
            uStack_1c._1_1_ = (char)((ulong)local_6 >> 8);
            iVar53 = FUN_2424_36fe();
            if (iVar53 != 0) goto LAB_2424_12b5;
          }
        }
        puVar49 = (undefined2 *)*puVar49;
      } while( true );
    case 2:
switchD_2000_eb7b_caseD_1:
      puVar42[0x1e] = (int)puVar25 - puVar42[0x14];
      puVar42[0x1e] = puVar42[0x1e] << (9U - (char)param_5 & 0x1f);
      uStack_1c._0_1_ = 0;
      uStack_1c._1_1_ = 0x20;
      uStack_1a._0_1_ = uVar12;
      uStack_1a._1_1_ = uVar13;
      uStack_18._0_1_ = uVar15;
      uStack_18._1_1_ = uVar17;
      puVar57 = (uint *)FUN_549b_007a();
      return puVar57;
    case 3:
switchD_2000_e962_caseD_1:
      *(int *)((int)puVar49 + -8) = *(int *)((int)puVar49 + -8) + (puVar42[0x11] - DAT_5b41_0925);
      *(int *)((int)puVar49 + -6) = *(int *)((int)puVar49 + -6) + (puVar42[0x12] - DAT_5b41_0927);
      if ((int)puVar52 - 1U < 9) {
                    /* WARNING: Could not recover jumptable at 0x00028b75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        puVar57 = (uint *)(*(code *)*(undefined2 *)(((int)puVar52 - 1U) * 2 + 0x49df))();
        return puVar57;
      }
      puStack_2c = (uint *)((int)puVar49 + -8);
      pbStack_30 = (byte *)0x8b91;
      puStack_2e = (uint *)pbVar56;
      puStack_2c = (uint *)FUN_2424_1e00();
      break;
    case 4:
      puVar49 = (undefined2 *)0x0;
      goto LAB_2424_14aa;
    case 5:
      uStack_18._0_1_ = (byte)DAT_5b41_04e6;
      uStack_18._1_1_ = (byte)((uint)DAT_5b41_04e6 >> 8);
      uStack_1a._0_1_ = (char)DAT_5b41_050d;
      uStack_1a._1_1_ = (char)((uint)DAT_5b41_050d >> 8);
      uStack_1c._0_1_ = 0;
      uStack_1c._1_1_ = 0x20;
      puVar25 = (uint *)FUN_4551_01dc();
      local_12._2_2_ = (uint *)0x1;
      if (((uint)puVar57 & 0x80) != 0) {
        local_12._0_2_ = (uint *)0x0;
        local_12._2_2_ = (uint *)0x1;
        uStack_18._0_1_ = (byte)DAT_5b41_04e2;
        uStack_18._1_1_ = (byte)((uint)DAT_5b41_04e2 >> 8);
        uStack_1a._0_1_ = (char)DAT_5b41_050d;
        uStack_1a._1_1_ = (char)((uint)DAT_5b41_050d >> 8);
        uStack_1c._0_1_ = 0x51;
        uStack_1c._1_1_ = 0x45;
        FUN_4551_01dc();
        puVar25 = (uint *)0x1;
        unaff_DI = (uint *)0x1;
        unaff_SI = (uint *)0x1;
      }
      if (((uint)puVar57 & 0x800) != 0) {
        local_12._0_2_ = (uint *)0x0;
        unaff_SI = (uint *)uStack_e + -4;
        uStack_18._0_1_ = (byte)DAT_5b41_04e2;
        uStack_18._1_1_ = (byte)((uint)DAT_5b41_04e2 >> 8);
        uStack_1a._0_1_ = (char)DAT_5b41_050d;
        uStack_1a._1_1_ = (char)((uint)DAT_5b41_050d >> 8);
        uStack_1c._0_1_ = 0x51;
        uStack_1c._1_1_ = 0x45;
        FUN_4551_01dc();
        puVar25 = (uint *)0x1;
        local_12._0_2_ = (uint *)0x1;
        unaff_DI = (uint *)0x1;
      }
      if (((uint)puVar57 & 0x410) != 0) {
        bVar61 = ((uint)puVar57 & 0x400) == 0;
        if ((bVar61) || ((int)local_8 < DAT_5b41_051d + -0x12)) {
          DAT_5b41_0513 = local_8;
        }
        else {
          DAT_5b41_0513 = (uint *)((int)local_6._2_2_ + 0x12);
        }
        if ((bVar61) || (-0x13 < (int)local_a)) {
          DAT_5b41_0515 = local_a;
          local_12._2_2_ = (uint *)0x1;
        }
        else {
          DAT_5b41_0515 = (uint *)uStack_e + -9;
          DAT_5b41_0513 = (uint *)((int)local_6._2_2_ + 0x12);
        }
        unaff_SI = DAT_5b41_0515;
        unaff_DI = DAT_5b41_0513;
        uVar60 = DAT_5b41_04dc;
        if (!bVar61) {
          uVar60 = DAT_5b41_04de;
        }
        uStack_1a._0_1_ = (char)uVar60;
        uStack_18._0_1_ = (char)uStack_1a;
        uStack_1a._1_1_ = (char)((uint)uVar60 >> 8);
        uStack_18._1_1_ = uStack_1a._1_1_;
        local_12._0_2_ = (uint *)0x0;
        uStack_1a._0_1_ = (char)DAT_5b41_050d;
        uStack_1a._1_1_ = (char)((uint)DAT_5b41_050d >> 8);
        uStack_1c._0_1_ = 0x51;
        uStack_1c._1_1_ = 0x45;
        puVar25 = (uint *)FUN_4551_01dc();
      }
      if ((uint *)local_12 != (uint *)0x0) {
        *(uint *)CONCAT22(param_4,param_3) = *(uint *)CONCAT22(param_4,param_3) - 0x24;
        param_3[2] = param_3[2] + 0x24;
      }
      if (local_12._2_2_ != (uint *)0x0) {
        param_3[1] = param_3[1] - 0x24;
        param_3[3] = param_3[3] + 0x24;
      }
      if (unaff_SI != (uint *)0x0) {
        param_3[2] = param_3[2] + 0x24;
      }
      if (unaff_DI != (uint *)0x0) {
        param_3[3] = param_3[3] + 0x24;
      }
      return puVar25;
    case 6:
      in_CX = (uint *)CONCAT11((char)((uint)in_CX >> 8),
                               (char)in_CX + (byte)puVar42[7] + CARRY2(uVar31,uVar31));
      puVar49 = &uStack_18;
      puVar28 = (uint *)*(undefined2 *)(((uint *)local_12)[4] * 2 + 0x68fe);
      puStack_2c = (uint *)0x2000;
      pbVar56 = (byte *)0x4551;
      puStack_2e = (uint *)0x8b2b;
      uStack_18 = (uint *)&stack0xfffe;
      puStack_2c = (uint *)FUN_4551_0370();
      uVar60 = (undefined2)((ulong)local_12 >> 0x10);
      puStack_26 = puVar57;
      if (((uint *)local_12)[0x57] != 0) {
        puVar52 = (uint *)((uint *)local_12)[0x57];
        pbStack_30 = (byte *)0x4551;
        pbVar56 = (byte *)0x4551;
        puStack_32 = (uint *)0x8b4f;
        puStack_2e = puVar28;
        FUN_4551_03eb();
        param_3 = (uint *)((ulong)local_12 >> 0x10);
        puVar42 = (uint *)local_12;
        puVar49 = &uStack_18;
        goto switchD_2000_e962_caseD_1;
      }
      break;
    case 7:
      while (puVar25 != puVar42) {
        if ((int)puVar25 <= (int)in_CX) {
          in_CX = puVar25;
        }
        do {
          uStack_18._0_1_ = 0x59;
          uStack_18._1_1_ = 6;
          puVar57 = in_CX;
          puVar63 = (undefined2 *)FUN_1a9e_5aa5();
          uVar58 = (undefined2)((ulong)puVar63 >> 0x10);
          puVar49 = (undefined2 *)puVar63;
          if (9 < (int)in_CX) {
            if ((POPCOUNT((uint)puVar49 & 0xff) & 1U) != 0) {
              puVar49 = (undefined2 *)((int)puVar49 + 1);
              *(char *)puVar63 = (char)uVar60;
              in_CX = (uint *)((int)in_CX + -1);
            }
            for (uVar31 = (uint)in_CX >> 1; uVar31 != 0; uVar31 = uVar31 - 1) {
              puVar63 = puVar49;
              puVar49 = puVar49 + 1;
              *puVar63 = uVar60;
            }
            in_CX = (uint *)(uint)(((uint)in_CX & 1) != 0);
          }
          for (; in_CX != (uint *)0x0; in_CX = (uint *)((int)in_CX + -1)) {
            puVar63 = puVar49;
            puVar49 = (undefined2 *)((int)puVar49 + 1);
            *(char *)puVar63 = (char)uVar60;
          }
          puVar25 = (uint *)((int)puVar26 - (int)puVar57);
          param_6 = param_6 - (uint)(puVar26 < puVar57);
LAB_1a9e_5c59:
          puVar42 = (uint *)0x0;
          in_CX = (uint *)0x7d00;
          puVar26 = puVar25;
        } while (param_6 != 0);
      }
      return puVar25;
    case 8:
      uStack_18._0_1_ = 0;
      uStack_18._1_1_ = 0;
      uStack_1a._0_1_ = 0;
      uStack_1a._1_1_ = 0;
      uStack_1c._0_1_ = 0;
      uStack_1c._1_1_ = 0;
      func_0x00054aef();
      uStack_18._0_1_ = 0xac;
      uStack_18._1_1_ = 0x54;
      pcVar59 = (char *)s_SIGNIN_RES_554c_3111 + 10;
      uStack_1a._0_1_ = 0x1e;
      uStack_1a._1_1_ = 0x46;
      FUN_311b_0244();
      local_6 = DAT_5b41_0567;
      if (5000 < DAT_554c_2f1c) {
        DAT_5b41_0567 = (uint *)0x0;
      }
      if (iRam000557bc != 7) {
        uStack_18._0_1_ = 0x1b;
        uStack_18._1_1_ = 0x31;
        uStack_1a._0_1_ = 0x4b;
        uStack_1a._1_1_ = 0x46;
        FUN_2424_10b2();
      }
      uStack_18._0_1_ = 0x1b;
      uStack_18._1_1_ = 0x31;
      uStack_1a._0_1_ = 0x50;
      uStack_1a._1_1_ = 0x46;
      FUN_2424_0ff3();
      if (iRam000557bc != 7) {
        uStack_18._0_1_ = 0;
        uStack_18._1_1_ = 0;
        uStack_1a._0_1_ = 0x1b;
        uStack_1a._1_1_ = 0x31;
        uStack_1c._0_1_ = 0x5e;
        uStack_1c._1_1_ = 0x46;
        FUN_2424_20ab();
      }
      uStack_18._0_1_ = 0;
      uStack_18._1_1_ = 0;
      uStack_1a._0_1_ = 0x1b;
      uStack_1a._1_1_ = 0x31;
      uStack_1c._0_1_ = 0x68;
      uStack_1c._1_1_ = 0x46;
      FUN_2424_184a();
      DAT_5b41_0505 = DAT_5b41_0505 + 1;
      if (((uint *)DAT_5b41_0567 == (uint *)0x0 && DAT_5b41_0567._2_2_ == (uint *)0x0) ||
         (LAB_554c_02ee == -1)) {
        uStack_18._0_1_ = 0x1b;
        uStack_18._1_1_ = 0x31;
        pcVar59 = (char *)0x54f1;
        uStack_1a._0_1_ = 0xd0;
        uStack_1a._1_1_ = 0x46;
        FUN_54f1_0043();
      }
      else {
        uStack_18._0_1_ = 1;
        uStack_18._1_1_ = 0;
        uStack_1a._0_1_ = (char)LAB_554c_02ee;
        uStack_1a._1_1_ = (char)((uint)LAB_554c_02ee >> 8);
        uStack_1c._0_1_ = (char)((ulong)DAT_5b41_0567 >> 0x10);
        uStack_1c._1_1_ = (char)((ulong)DAT_5b41_0567 >> 0x18);
        FUN_2424_2165();
        uVar60 = (undefined2)((ulong)DAT_5b41_0567 >> 0x10);
        puVar57 = (uint *)DAT_5b41_0567;
        if (((puVar57[4] == 0x16) || (puVar57[4] == 0x37)) &&
           (puVar57[0x31] != 0 || puVar57[0x32] != 0)) {
          uStack_18._0_1_ = 0;
          uStack_18._1_1_ = 0;
          uStack_1a._0_1_ = 0;
          uStack_1a._1_1_ = 0;
          uStack_1c._0_1_ = (char)puVar57[0x32];
          uStack_1c._1_1_ = (char)(puVar57[0x32] >> 8);
          FUN_2424_2165();
        }
      }
      if (DAT_554c_02f0 != -1) {
        DAT_554c_42ce = (undefined1)DAT_554c_02f0;
        uStack_18._0_1_ = 0;
        uStack_18._1_1_ = 0;
        uStack_1a = (uint **)(DAT_5b41_054d - DAT_5b41_0927);
        uStack_1c = (uint *)(DAT_5b41_054b - DAT_5b41_0925);
        FUN_2424_276e();
        FUN_2424_1a04();
      }
      uStack_18._0_1_ = (byte)pcVar59;
      uVar22 = (byte)uStack_18;
      uStack_18._1_1_ = (byte)((uint)pcVar59 >> 8);
      uVar55 = uStack_18._1_1_;
      if (5000 < DAT_554c_2f1c) {
        uStack_1a._0_1_ = 0x21;
        uStack_1a._1_1_ = 0x47;
        FUN_2424_196d();
        uStack_18._0_1_ = 1;
        uStack_18._1_1_ = 0;
        uStack_1c._0_1_ = 0x28;
        uStack_1c._1_1_ = 0x47;
        uStack_1a._0_1_ = uVar22;
        uStack_1a._1_1_ = uVar55;
        FUN_2424_184a();
      }
      uStack_1a._0_1_ = 0x2f;
      uStack_1a._1_1_ = 0x47;
      uStack_18._0_1_ = uVar22;
      uStack_18._1_1_ = uVar55;
      FUN_2424_0304();
      uStack_18._0_1_ = 0;
      uStack_18._1_1_ = 0;
      uStack_1c._0_1_ = 0x36;
      uStack_1c._1_1_ = 0x47;
      uStack_1a._0_1_ = uVar22;
      uStack_1a._1_1_ = uVar55;
      FUN_460e_1314();
      uStack_18._0_1_ = 0xe;
      uStack_18._1_1_ = 0x46;
      uStack_1a._0_1_ = 0x3e;
      uStack_1a._1_1_ = 0x47;
      FUN_2424_1650();
      DAT_5b41_0567 = local_6;
      return (uint *)local_6;
    }
    uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
    iVar53 = (int)*(undefined4 *)((int)puVar49 + 6);
    if (*(int *)(iVar53 + 0xb4) == 0) {
      return puStack_2c;
    }
    puVar52 = (uint *)*(undefined2 *)(iVar53 + 0xb4);
    puStack_2c = (uint *)*(int *)((int)puVar49 + -10);
    puStack_32 = (uint *)0x8bb2;
    pbStack_30 = pbVar56;
    puStack_2e = puVar28;
    FUN_4551_03eb();
    uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
    iVar53 = (int)*(undefined4 *)((int)puVar49 + 6);
    *(int *)((int)puVar49 + -8) =
         *(int *)((int)puVar49 + -8) + (*(int *)(iVar53 + 0x22) - DAT_5b41_0925);
    puVar25 = (uint *)(*(int *)(iVar53 + 0x24) - DAT_5b41_0927);
    *(int *)((int)puVar49 + -6) = (int)(*(int *)((int)puVar49 + -6) + (int)puVar25);
    puVar57 = puVar52 + -1;
    if ((uint *)0xa < puVar57) {
      puStack_2c = (uint *)((int)puVar49 + -8);
      puStack_2e = (uint *)0x4551;
      pbStack_30 = (byte *)0x8c02;
      puVar57 = (uint *)FUN_2424_1e00();
      return puVar57;
    }
    puVar42 = (uint *)((int)puVar57 * 2);
    switch(puVar57) {
    case (uint *)0x0:
      do {
        LOCK();
        uVar60 = *(undefined2 *)(byte *)((int)puVar42 + -0x3e17);
        *(uint **)(byte *)((int)puVar42 + -0x3e17) = puVar25;
        UNLOCK();
        ((byte *)((int)puVar42 + (int)puVar28))[-0x7877] =
             ((byte *)((int)puVar42 + (int)puVar28))[-0x7877] + (char)((uint)uVar60 >> 8);
        puVar28 = DAT_5b41_2837;
        *(undefined2 *)((int)puVar49 + -6) = uVar60;
        DAT_5b41_2839 = (uint *)(*(int *)((int)puVar49 + -6) + ((int)DAT_5b41_2837 >> 4));
        DAT_5b41_2837 = (uint *)((uint)DAT_5b41_2837 & 0xf);
        *(undefined2 *)((int)puVar49 + -2) = DAT_5b41_2839;
        *(undefined2 *)((int)puVar49 + -4) = DAT_5b41_2837;
        if (DAT_554c_42df == '\0') {
          *(int *)((int)puVar49 + -10) = *(int *)(*puVar52 + 6) * *(int *)(*puVar52 + 8);
          puStack_2c = (uint *)0x0;
          puStack_2e = (uint *)0x0;
          pbStack_30 = (byte *)*(undefined2 *)((int)puVar49 + -10);
          puStack_32 = (uint *)0x2000;
          puStack_34 = (uint *)0x1fcc;
          uVar64 = FUN_2fc8_00fc();
          *(undefined2 *)((int)puVar49 + -0xc) = (int)((ulong)uVar64 >> 0x10);
          *(undefined2 *)((int)puVar49 + -0xe) = (int)uVar64;
          *(uint *)((int)puVar49 + -10) = *(uint *)((int)puVar49 + -10) >> 1;
          *(uint *)((int)puVar49 + -10) = *(uint *)((int)puVar49 + -10) >> 1;
          *(uint *)((int)puVar49 + -10) = *(uint *)((int)puVar49 + -10) >> 1;
          puStack_2e = (uint *)*(undefined2 *)*puVar52;
          puStack_2c = (uint *)((undefined2 *)*puVar52)[1];
          pbStack_30 = (byte *)*(undefined2 *)((int)puVar49 + -0xc);
          puStack_32 = (uint *)*(int *)((int)puVar49 + -0xe);
          puStack_34 = (uint *)0x2000;
          uStack_36 = 0x1ff9;
          FUN_1a9e_74bc();
          puVar6 = (undefined2 *)*puVar52;
          *puVar6 = *(undefined2 *)((int)puVar49 + -0xc);
          puVar6[1] = *(undefined2 *)((int)puVar49 + -0xe);
          puStack_2c = (uint *)0x2000;
          puStack_2e = (uint *)0x200f;
          FUN_1a9e_7911();
          puStack_2c = (uint *)*(undefined2 *)((int)puVar49 + -0xe);
          puStack_2e = (uint *)0x2000;
          pbStack_30 = (byte *)0x201d;
          func_0x0002fdf5();
        }
        else {
          puStack_2c = (uint *)0x2000;
          puStack_2e = (uint *)0x2029;
          FUN_1a9e_7911();
        }
        puVar42 = (uint *)*puVar52;
        *puVar42 = *(uint *)((int)puVar49 + -2);
        puVar42[1] = *(uint *)((int)puVar49 + -4);
        puVar42[2] = 0xfffe;
        puVar57 = DAT_5b41_2837;
        iVar53 = DAT_5b41_2833;
        puVar52 = puVar52 + 1;
        puVar25 = DAT_5b41_2839;
      } while (*puVar52 != 0);
      *(int *)((int)puVar49 + -6) = (int)DAT_5b41_2839 - DAT_5b41_2835;
      DAT_5b41_282f =
           *(int *)((int)puVar49 + -6) + ((int)DAT_5b41_2837 + (0xf - DAT_5b41_2833) >> 4);
      *(undefined2 *)((int)puVar49 + -8) =
           *(undefined2 *)*(undefined2 *)*(undefined2 *)((int)puVar49 + 6);
      pcVar11 = (code *)swi(0x21);
      (*pcVar11)();
      FUN_1000_130c();
      return (uint *)((int)puVar57 + (*(int *)((int)puVar49 + -6) * 0x10 - iVar53));
    case (uint *)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case (uint *)0x2:
      *(byte *)(uint *)((int)puVar42 + (int)puVar52) =
           (byte)*(uint *)((int)puVar42 + (int)puVar52) + 1;
      if (puVar25 != (uint *)0xf6) {
        puVar42 = puVar42 + -1;
        *(undefined2 *)((int)puVar49 + 2) = puVar42;
      }
      if ((*puVar42 & 1) == 0) {
        puVar57 = (uint *)((int)puStack_26 >> 1);
      }
      else {
        puVar57 = (uint *)((uint)puStack_26 >> 1 | (uint)(((uint)in_DX & 1) != 0) << 0xf);
      }
      return puVar57;
    case (uint *)0x3:
      do {
        iVar53 = 0xb;
LAB_2424_38a7:
        do {
          do {
            uVar58 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10);
            iVar43 = (int)*(undefined4 *)((int)puVar49 + -4);
            uVar60 = *(undefined2 *)(iVar43 + 0x8c);
            *(undefined2 *)((int)puVar49 + -2) = *(undefined2 *)(iVar43 + 0x8e);
            *(undefined2 *)((int)puVar49 + -4) = uVar60;
            if ((*(int *)((int)puVar49 + -4) == 0 && *(int *)((int)puVar49 + -2) == 0) ||
               (iVar53 != 0)) {
LAB_2424_39fc:
              uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
              iVar43 = (int)*(undefined4 *)((int)puVar49 + 6);
              if (((uint *)*(undefined2 *)(iVar43 + 0xae) != puVar52) ||
                 (*(int *)(iVar43 + 0xb4) != iVar53)) {
                puStack_2c = (uint *)*(undefined2 *)((int)puVar49 + 6);
                puStack_2e = (uint *)0x2000;
                pbStack_30 = (byte *)0x7c59;
                FUN_2424_3746();
                puStack_2e = (uint *)0x2;
                pbStack_30 = (byte *)*(undefined2 *)((int)puVar49 + 8);
                puStack_32 = (uint *)*(undefined2 *)((int)puVar49 + 6);
                puStack_34 = (uint *)0x2000;
                uStack_36 = 0x7c65;
                FUN_2424_3746();
                uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
                iStack_38 = (int)*(undefined4 *)((int)puVar49 + 6);
                *(undefined2 *)(iStack_38 + 0xae) = puVar52;
                *(int *)(iStack_38 + 0xb4) = iVar53;
                puStack_34 = (uint *)0x1;
                uStack_36 = *(undefined2 *)((int)puVar49 + 8);
                uStack_3a = 0x2000;
                puStack_3c = (undefined2 *)&DAT_5b41_1d2c;
                FUN_2424_3746();
                uStack_3a = 2;
                puStack_3c = (undefined2 *)*(undefined2 *)((int)puVar49 + 8);
                iStack_3e = *(undefined2 *)((int)puVar49 + 6);
                puStack_40 = (uint *)0x2000;
                puStack_42 = (undefined2 *)&DAT_5b41_1d38;
                FUN_2424_3746();
              }
              uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
              iVar43 = (int)*(undefined4 *)((int)puVar49 + 6);
              *(undefined2 *)(iVar43 + 0xae) = puVar52;
              *(int *)(iVar43 + 0xb4) = iVar53;
              if ((puVar52 == (uint *)0x0) && (iVar53 == 0)) {
                puVar57 = (uint *)0x0;
              }
              else {
                puVar57 = (uint *)0x1;
              }
              return puVar57;
            }
          } while (*(int *)((int)*(undefined4 *)((int)puVar49 + -4) + 0x4a) != 0x10);
          puStack_2c = (uint *)0x2000;
          puStack_2e = (uint *)0x7aa9;
          iVar43 = FUN_2424_4087();
        } while (iVar43 == 0);
        if (*(int *)((int)*(undefined4 *)((int)puVar49 + -4) + 0x22) ==
            *(int *)((int)*(undefined4 *)((int)puVar49 + 6) + 0x22)) {
          iVar53 = 10;
          goto LAB_2424_38a7;
        }
        uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10);
        iVar53 = (int)*(undefined4 *)((int)puVar49 + -4);
        uVar58 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
        iVar43 = (int)*(undefined4 *)((int)puVar49 + 6);
        if (*(int *)(iVar53 + 0x22) + *(int *)(iVar53 + 0x48) ==
            *(int *)(iVar43 + 0x22) + *(int *)(iVar43 + 0x48)) {
          iVar53 = 0xc;
          goto LAB_2424_38a7;
        }
      } while( true );
    case (uint *)0x4:
      puStack_34 = (uint *)0x2000;
      while( true ) {
        pbStack_30 = (byte *)*(undefined2 *)((int)puVar49 + -2);
        uStack_36 = 0x7410;
        puStack_32 = puVar42;
        puStack_2e = puVar52;
        puStack_2c = puVar28;
        FUN_3e34_0ec9();
        puVar52 = (uint *)((int)puVar52 + *(int *)((int)*(undefined4 *)((int)puVar49 + -4) + 6));
        if (*(int *)((int)puVar49 + -0xc) <= (int)puVar52) break;
        puVar42 = (uint *)(uint *)*(undefined4 *)((int)puVar49 + -4);
        puStack_34 = (uint *)0x3e34;
      }
      puVar57 = (uint *)FUN_2424_02ca();
      return puVar57;
    case (uint *)0x5:
      ((undefined1 *)((int)puVar49 + (int)puVar28))[0xe46] =
           ((undefined1 *)((int)puVar49 + (int)puVar28))[0xe46] + (char)in_CX +
           CARRY2((uint)puVar57,(uint)puVar57);
      uVar31 = *(uint *)((int)puVar49 + 0x12) + *(uint *)((int)puVar49 + 10);
      *(int *)((int)puVar49 + -6) =
           ((*(int *)((int)puVar49 + 0x14) + *(int *)((int)puVar49 + 0xc) +
            (uint)CARRY2(*(uint *)((int)puVar49 + 0x12),*(uint *)((int)puVar49 + 10))) -
           ((int)in_DX << 1 | (uint)CARRY2((uint)puVar25,(uint)puVar25))) -
           (uint)(uVar31 < (uint)((int)puVar25 * 2));
      *(int *)((int)puVar49 + -8) = uVar31 + (int)puVar25 * -2;
      uVar31 = *(uint *)((int)puVar49 + 0x1a);
      uVar33 = *(uint *)((int)puVar49 + 0x1e) + *(uint *)((int)puVar49 + 0x16);
      *(int *)((int)puVar49 + -10) =
           ((*(int *)((int)puVar49 + 0x20) + *(int *)((int)puVar49 + 0x18) +
            (uint)CARRY2(*(uint *)((int)puVar49 + 0x1e),*(uint *)((int)puVar49 + 0x16))) -
           (*(int *)((int)puVar49 + 0x1c) << 1 | (uint)CARRY2(uVar31,uVar31))) -
           (uint)(uVar33 < uVar31 * 2);
      *(int *)((int)puVar49 + -0xc) = uVar33 + uVar31 * -2;
      iVar53 = (*(int *)((int)puVar49 + 0x10) - *(int *)((int)puVar49 + 0xc)) -
               (uint)(*(uint *)((int)puVar49 + 0xe) < *(uint *)((int)puVar49 + 10));
      puStack_2c = (uint *)0x6860;
      uVar60 = FUN_1000_199e();
      *(int *)((int)puVar49 + -0xe) = iVar53;
      *(undefined2 *)((int)puVar49 + -0x10) = uVar60;
      in_DX = (uint *)((*(int *)((int)puVar49 + 0x1c) - *(int *)((int)puVar49 + 0x18)) -
                      (uint)(*(uint *)((int)puVar49 + 0x1a) < *(uint *)((int)puVar49 + 0x16)));
      break;
    default:
switchD_2000_8bda_caseD_6:
      uVar22 = (undefined1)((uint)puVar25 >> 8);
      puVar57 = (uint *)CONCAT11(uVar22,*(char *)&DAT_554c_5596);
      if (*(char *)&DAT_554c_5596 == '\0') {
        *(undefined1 *)&DAT_554c_5595 = (char)puVar42;
        *(undefined2 *)&DAT_554c_5178 = in_CX;
        *(undefined2 *)&DAT_554c_517a = in_DX;
        puVar57 = (uint *)CONCAT11(uVar22,*(char *)&DAT_554c_5596);
        if ((*(char *)&DAT_554c_5596 == '\0') &&
           (puVar57 = (uint *)0x0, *(int *)&DAT_554c_517c != 0 || *(int *)&DAT_554c_517e != 0)) {
          *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + '\x01';
          *(undefined2 *)&DAT_554c_557e = 0x2000;
          *(undefined2 *)&DAT_554c_557c = 0x2fe;
          FUN_1a9e_5938();
          uVar60 = ((undefined2 *)&DAT_554c_517c)[1];
          pcVar10 = (code *)*(undefined2 *)&DAT_554c_517c;
          *(undefined2 *)&DAT_554c_557e = 0x2000;
          puVar46 = (undefined2 *)&DAT_554c_557c;
          *(undefined2 *)&DAT_554c_557c = 0x303;
          (*pcVar10)();
          *(undefined2 *)((int)puVar46 + -2) = 0x2000;
          *(undefined2 *)((int)puVar46 + -4) = 0x307;
          puVar57 = (uint *)FUN_1a9e_599d();
          *(char *)&DAT_554c_5596 = *(char *)&DAT_554c_5596 + -1;
        }
      }
      return puVar57;
    case (uint *)0x7:
      return puVar25;
    case (uint *)0x8:
      iVar47 = *(int *)((undefined1 *)((int)puVar49 + (int)puVar28) + 0x6bf8) * -0x15;
      puVar57 = (uint *)*(int *)((int)puVar49 + 6);
      if ((*(int *)((int)puVar49 + 8) == DAT_5b41_0ca2) && (puVar57 == DAT_5b41_0ca0)) {
        DAT_5b41_0cb9 = 0;
      }
      else {
        puVar57 = (uint *)*(int *)((int)puVar49 + 6);
        if ((*(int *)((int)puVar49 + 8) == DAT_5b41_0c9e) && (puVar57 == DAT_5b41_0c9c)) {
          DAT_5b41_0cbb = 0;
        }
        else {
          *(undefined2 *)(iVar47 + -2) = *(undefined2 *)((int)puVar49 + 8);
          *(undefined2 *)(iVar47 + -4) = *(undefined2 *)((int)puVar49 + 6);
          *(undefined2 *)(iVar47 + -6) = 0x2000;
          *(undefined2 *)(iVar47 + -8) = 0xf845;
          puVar57 = (uint *)FUN_22de_0351();
        }
      }
      return puVar57;
    case (uint *)0x9:
      *(byte *)(uint *)((int)puVar42 + (int)puVar52) =
           (byte)*(uint *)((int)puVar42 + (int)puVar52) + (char)((uint)puVar25 >> 8);
code_r0x00028359:
      puStack_2c = (uint *)0x2000;
      puStack_2e = (uint *)0x835f;
      FUN_2424_4ae2();
      uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
      iVar53 = (int)*(undefined4 *)((int)puVar49 + 6);
      while( true ) {
        uVar58 = *(undefined2 *)(iVar53 + 0x8c);
        *(undefined2 *)((int)puVar49 + -2) = *(undefined2 *)(iVar53 + 0x8e);
        *(undefined2 *)((int)puVar49 + -4) = uVar58;
        if ((*(int *)((int)puVar49 + -4) == 0 && *(int *)((int)puVar49 + -2) == 0) ||
           (*(int *)((int)puVar49 + -6) != 0)) break;
        uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10);
        iVar53 = (int)*(undefined4 *)((int)puVar49 + -4);
        if (((*(int *)(iVar53 + 8) == 0x76) && (*(int *)(iVar53 + 0x4a) == 0x20)) &&
           (*(int *)(iVar53 + 0x24) ==
            *(int *)((int)*(undefined4 *)((int)puVar49 + 6) + 0x24) + -0x20)) {
          bVar61 = (*(byte *)(iVar53 + 0xc) & 0x30) != 0;
          if (((*(int *)((int)puVar49 + -10) != 0) || (bVar61)) ||
             (*(int *)((int)*(undefined4 *)((int)puVar49 + -4) + 0x22) !=
              *(int *)((int)*(undefined4 *)((int)puVar49 + 6) + 0x22))) {
            if (((*(int *)((int)puVar49 + -10) != 0) && (!bVar61)) &&
               (uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10),
               iVar53 = (int)*(undefined4 *)((int)puVar49 + -4),
               uVar58 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10),
               iVar43 = (int)*(undefined4 *)((int)puVar49 + 6),
               *(int *)(iVar53 + 0x22) + *(int *)(iVar53 + 0x48) ==
               *(int *)(iVar43 + 0x22) + *(int *)(iVar43 + 0x48))) {
              *(undefined2 *)((int)puVar49 + -6) = 9;
            }
          }
          else {
            *(undefined2 *)((int)puVar49 + -6) = 7;
          }
        }
        uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10);
        iVar53 = (int)*(undefined4 *)((int)puVar49 + -4);
      }
      puStack_2c = (uint *)0x2000;
      puStack_2e = (uint *)0x842b;
      FUN_2424_4ae2();
      uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
      iVar53 = (int)*(undefined4 *)((int)puVar49 + 6);
      while( true ) {
        uVar58 = *(undefined2 *)(iVar53 + 0x8c);
        *(undefined2 *)((int)puVar49 + -2) = *(undefined2 *)(iVar53 + 0x8e);
        *(undefined2 *)((int)puVar49 + -4) = uVar58;
        if ((*(int *)((int)puVar49 + -4) == 0 && *(int *)((int)puVar49 + -2) == 0) ||
           (*(int *)((int)puVar49 + -8) != 0)) break;
        uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10);
        iVar53 = (int)*(undefined4 *)((int)puVar49 + -4);
        if ((*(int *)(iVar53 + 8) == 0x76) && (*(int *)(iVar53 + 0x4a) == 0x20)) {
          uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
          iVar53 = (int)*(undefined4 *)((int)puVar49 + 6);
          uVar58 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10);
          iVar43 = (int)*(undefined4 *)((int)puVar49 + -4);
          if (*(int *)(iVar53 + 0x24) + *(int *)(iVar53 + 0x4a) == *(int *)(iVar43 + 0x24)) {
            bVar61 = (*(byte *)(iVar43 + 0xc) & 0x30) == 0;
            if (((*(int *)((int)puVar49 + -10) != 0) || (bVar61)) ||
               (*(int *)((int)*(undefined4 *)((int)puVar49 + -4) + 0x22) !=
                *(int *)((int)*(undefined4 *)((int)puVar49 + 6) + 0x22))) {
              if (((*(int *)((int)puVar49 + -10) != 0) && (!bVar61)) &&
                 (uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10),
                 iVar53 = (int)*(undefined4 *)((int)puVar49 + -4),
                 uVar58 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10),
                 iVar43 = (int)*(undefined4 *)((int)puVar49 + 6),
                 *(int *)(iVar53 + 0x22) + *(int *)(iVar53 + 0x48) ==
                 *(int *)(iVar43 + 0x22) + *(int *)(iVar43 + 0x48))) {
                *(undefined2 *)((int)puVar49 + -8) = 0xc;
              }
            }
            else {
              *(undefined2 *)((int)puVar49 + -8) = 10;
            }
          }
        }
        uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + -4) >> 0x10);
        iVar53 = (int)*(undefined4 *)((int)puVar49 + -4);
      }
      uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
      iVar53 = (int)*(undefined4 *)((int)puVar49 + 6);
      if ((*(int *)(iVar53 + 0xae) != *(int *)((int)puVar49 + -6)) ||
         (*(int *)(iVar53 + 0xb4) != *(int *)((int)puVar49 + -8))) {
        FUN_2424_3746();
        puStack_2c = (uint *)0x86a5;
        FUN_2424_3746();
        uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
        puStack_2e = (uint *)*(undefined4 *)((int)puVar49 + 6);
        *(undefined2 *)((int)puStack_2e + 0xae) = *(undefined2 *)((int)puVar49 + -6);
        *(undefined2 *)((int)puStack_2e + 0xb4) = *(undefined2 *)((int)puVar49 + -8);
        puStack_2c = (uint *)*(undefined2 *)((int)puVar49 + 8);
        pbStack_30 = (byte *)0x2000;
        puStack_32 = (uint *)0x86c2;
        FUN_2424_3746();
        pbStack_30 = (byte *)0x2;
        puStack_32 = (uint *)*(undefined2 *)((int)puVar49 + 8);
        puStack_34 = (uint *)*(undefined2 *)((int)puVar49 + 6);
        uStack_36 = 0x2000;
        iStack_38 = 0x86ce;
        FUN_2424_3746();
      }
      uVar60 = (undefined2)((ulong)*(undefined4 *)((int)puVar49 + 6) >> 0x10);
      iVar53 = (int)*(undefined4 *)((int)puVar49 + 6);
      *(undefined2 *)(iVar53 + 0xae) = *(undefined2 *)((int)puVar49 + -6);
      *(undefined2 *)(iVar53 + 0xb4) = *(undefined2 *)((int)puVar49 + -8);
      if ((*(int *)((int)puVar49 + -6) == 0) && (*(int *)((int)puVar49 + -8) == 0)) {
        puVar57 = (uint *)0x0;
      }
      else {
        puVar57 = (uint *)0x1;
      }
      return puVar57;
    }
switchD_2000_81f0_caseD_7:
    puVar48 = (undefined1 *)puVar49;
    goto switchD_2000_81f0_caseD_a;
  }
  uStack_1c = (uint *)&uStack_e;
  uStack_1a._0_1_ = uVar19;
  uStack_1a._1_1_ = uVar21;
  uStack_18._0_1_ = uVar18;
  uStack_18._1_1_ = uVar20;
  puVar25 = (uint *)FUN_2424_1e00();
  if (param_2[0x5a] == 0) {
    return puVar25;
  }
  puVar25 = (uint *)local_6;
  local_6 = (uint *)CONCAT22(param_2[0x5a],(uint *)local_6);
  uStack_1a = (uint **)&uStack_e;
  uStack_1c = (uint *)((int)puVar57 + (param_2[0x5a] - 1));
  uStack_18._0_1_ = uVar19;
  uStack_18._1_1_ = uVar21;
  FUN_4551_03eb();
  uStack_e._0_2_ = (uint *)((int)(uint *)uStack_e + (param_2[0x11] - DAT_5b41_0925));
  puVar26 = (uint *)(param_2[0x12] - DAT_5b41_0927);
  uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + (int)puVar26);
  if (10 < (int)local_6._2_2_ - 2U) {
    uStack_1c = (uint *)&uStack_e;
    uStack_1a._0_1_ = uVar19;
    uStack_1a._1_1_ = uVar21;
    uStack_18._0_1_ = uVar18;
    uStack_18._1_1_ = uVar20;
    puVar57 = (uint *)FUN_2424_1e00();
    return puVar57;
  }
  puVar48 = &stack0xfffe;
  switch(local_6._2_2_) {
  case (uint *)0x2:
    uVar22 = in(0x7a);
    *(undefined2 *)(byte *)((int)puVar57 + 3) = *(undefined2 *)(byte *)((int)puVar57 + 3);
    return (uint *)CONCAT11((char)((uint)puVar26 >> 8),uVar22);
  case (uint *)0x3:
    if (((uint **)unaff_DI == uStack_1a) &&
       ((uint *)CONCAT11(uStack_18._1_1_,(byte)uStack_18) == uStack_1c)) {
      uStack_e._0_2_ = (uint *)0x0;
      uVar31 = 0;
      local_a = in_CX;
      local_8 = puVar57;
    }
    else {
      uStack_e._0_2_ = (uint *)uStack_1c[0x3b];
      uVar31 = puVar26[0x3b];
      local_8 = (uint *)(1 - (int)in_CX);
      local_a = (uint *)(1 - (int)puVar57);
    }
    if (*(int *)((int)local_a * 4 + uVar31 + 0x1e) < *(int *)((int)puVar57 * 4 + 0x1e)) {
      uStack_e._2_2_ = (uint *)0x8;
    }
    else {
      uStack_e._2_2_ = (uint *)0x10;
    }
    if (param_4 == (uint *)0x0) {
      if (*(int *)((int)local_8 * 4 + (int)(uint *)uStack_e + 0x20) <
          *(int *)((int)in_CX * 4 + 0x20)) {
        return (uint *)0x1;
      }
      if (*(int *)((int)puVar57 * 4 + 0x20) < *(int *)((int)local_a * 4 + uVar31 + 0x20)) {
LAB_28eb_391e:
        return (uint *)((uint)uStack_e._2_2_ | 4);
      }
    }
    else {
      if (*(int *)((int)in_CX * 4 + 0x20) <
          *(int *)((int)local_8 * 4 + (int)(uint *)uStack_e + 0x20)) {
        return (uint *)0x1;
      }
      if (*(int *)((int)puVar57 * 4 + 0x20) <= *(int *)((int)local_a * 4 + uVar31 + 0x20))
      goto LAB_28eb_391e;
    }
    return (uint *)((uint)uStack_e._2_2_ | 2);
  case (uint *)0x4:
    do {
      uStack_18._0_1_ = 0;
      uStack_18._1_1_ = 0x20;
      uStack_1a._0_1_ = 10;
      uStack_1a._1_1_ = 0x9f;
      iVar53 = FUN_28eb_03ff();
      puVar57 = in_DX;
      puVar25 = DAT_5b41_04ec;
      puVar26 = DAT_5b41_04ee;
      puVar28 = (uint *)uStack_e;
      puVar42 = uStack_e._2_2_;
      if (iVar53 == 0) {
        local_12 = (uint *)CONCAT22(local_8,local_a);
        uStack_18._0_1_ = 0;
        uStack_18._1_1_ = 0x20;
        uStack_1a._0_1_ = 0x24;
        uStack_1a._1_1_ = 0x9f;
        puVar25 = (uint *)FUN_28eb_0728();
        puVar57 = in_DX;
        puVar26 = in_DX;
        puVar28 = puVar25;
        puVar42 = in_DX;
      }
      do {
        do {
          while( true ) {
            while( true ) {
              while( true ) {
                do {
                  while( true ) {
                    uStack_e._2_2_ = puVar42;
                    uStack_e._0_2_ = puVar28;
                    DAT_5b41_04ee = puVar26;
                    DAT_5b41_04ec = puVar25;
                    local_12 = (uint *)CONCAT22(0x1000,local_6._2_2_);
                    uStack_18._0_1_ = 0xb7;
                    uStack_18._1_1_ = 0x9f;
                    puVar25 = (uint *)FUN_28eb_32d8();
                    local_6 = (uint *)CONCAT22(puVar57,puVar25);
                    if (puVar25 == (uint *)0x0 && puVar57 == (uint *)0x0) {
                      if ((uint *)uStack_e == (uint *)0x0 && uStack_e._2_2_ == (uint *)0x0) {
                        return (uint *)0x0;
                      }
                      return (uint *)uStack_e;
                    }
                    local_12 = (uint *)CONCAT22(puVar57,puVar25);
                    uStack_18._0_1_ = 0;
                    uStack_18._1_1_ = 0x20;
                    uStack_1a._0_1_ = 0xc5;
                    uStack_1a._1_1_ = 0x9c;
                    local_a = (uint *)FUN_28eb_0a36();
                    puVar52 = puVar57;
                    local_8 = puVar57;
                    if (((((local_a != (uint *)0x0 || puVar57 != (uint *)0x0) &&
                          ((*(byte *)((int)local_a + 0xb) & 0x80) != 0)) && (iRam000557bc != 3)) &&
                        (param_2 != (uint *)0x0 || param_3 != (uint *)0x0)) &&
                       ((puVar52 = param_3, param_3 != puVar57 || (param_2 != local_a)))) {
                      local_8 = (uint *)0x0;
                      local_a = (uint *)0x0;
                    }
                    if (((local_a == (uint *)0x0 && local_8 == (uint *)0x0) || (local_a[0x4c] != 0))
                       || (((uint *)uStack_e == (uint *)0x0 && uStack_e._2_2_ == (uint *)0x0 ||
                           (((uint *)uStack_e)[0x4c] != 0)))) break;
                    if ((((uint *)uStack_e == (uint *)0x0 && uStack_e._2_2_ == (uint *)0x0) ||
                        (puVar52 = uStack_e._2_2_, uStack_e._2_2_ != DAT_5b41_0567._2_2_)) ||
                       ((uint *)uStack_e != (uint *)DAT_5b41_0567)) {
                      if (((local_a == (uint *)0x0 && local_8 == (uint *)0x0) ||
                          (puVar52 = local_8, local_8 != DAT_5b41_0567._2_2_)) ||
                         (local_a != (uint *)DAT_5b41_0567)) {
                        local_12 = (uint *)CONCAT22(local_8,local_a);
                        local_12._2_2_ = (uint *)FUN_28eb_0d77();
                        uStack_18._0_1_ = 0;
                        uStack_18._1_1_ = 0x20;
                        uStack_1a._0_1_ = 0xfd;
                        uStack_1a._1_1_ = 0x9d;
                        local_12._0_2_ = puVar52;
                        puVar27 = (uint *)FUN_28eb_0d77();
                        puVar57 = local_12._2_2_;
                        puVar25 = DAT_5b41_04ec;
                        puVar26 = DAT_5b41_04ee;
                        puVar28 = (uint *)uStack_e;
                        puVar42 = uStack_e._2_2_;
                        if (((int)(uint *)local_12 <= (int)puVar52) &&
                           (((int)(uint *)local_12 < (int)puVar52 ||
                            (puVar57 = local_12._2_2_, local_12._2_2_ < puVar27)))) {
                          DAT_5b41_04ee = local_8;
                          DAT_5b41_04ec = local_a;
                          puVar57 = local_8;
                          puVar25 = DAT_5b41_04ec;
                          puVar26 = DAT_5b41_04ee;
                          puVar28 = local_a;
                          puVar42 = local_8;
                        }
                      }
                      else {
                        local_12 = (uint *)CONCAT22(local_8,local_a);
                        local_12._2_2_ = (uint *)FUN_28eb_0d77();
                        uStack_18._0_1_ = 0;
                        uStack_18._1_1_ = 0x20;
                        uStack_1a._0_1_ = 0xbf;
                        uStack_1a._1_1_ = 0x9d;
                        local_12._0_2_ = puVar52;
                        uVar31 = FUN_28eb_0d77();
                        puVar57 = local_8;
                        puVar25 = DAT_5b41_04ec;
                        puVar26 = DAT_5b41_04ee;
                        puVar28 = local_a;
                        puVar42 = local_8;
                        if (((int)(uint *)local_12 <= (int)puVar52) &&
                           (((int)(uint *)local_12 < (int)puVar52 ||
                            (puVar28 = local_a, puVar42 = local_8, local_12._2_2_ < uVar31)))) {
                          DAT_5b41_04ee = local_8;
                          DAT_5b41_04ec = local_a;
                          puVar25 = DAT_5b41_04ec;
                          puVar26 = DAT_5b41_04ee;
                          puVar28 = local_a;
                          puVar42 = local_8;
                        }
                      }
                    }
                    else {
                      local_12 = (uint *)CONCAT22(local_8,local_a);
                      local_12._2_2_ = (uint *)FUN_28eb_0d77();
                      uStack_18._0_1_ = 0;
                      uStack_18._1_1_ = 0x20;
                      uStack_1a._0_1_ = 0x6b;
                      uStack_1a._1_1_ = 0x9d;
                      local_12._0_2_ = puVar52;
                      puVar27 = (uint *)FUN_28eb_0d77();
                      puVar57 = local_12._2_2_;
                      puVar25 = DAT_5b41_04ec;
                      puVar26 = DAT_5b41_04ee;
                      puVar28 = (uint *)uStack_e;
                      puVar42 = uStack_e._2_2_;
                      if (((int)(uint *)local_12 <= (int)puVar52) &&
                         (((int)(uint *)local_12 < (int)puVar52 ||
                          (puVar57 = local_12._2_2_, local_12._2_2_ < puVar27)))) {
                        DAT_5b41_04ee = local_8;
                        DAT_5b41_04ec = local_a;
                        puVar57 = local_8;
                        puVar25 = DAT_5b41_04ec;
                        puVar26 = DAT_5b41_04ee;
                      }
                    }
                  }
                  puVar57 = puVar52;
                  puVar25 = DAT_5b41_04ec;
                  puVar26 = DAT_5b41_04ee;
                  puVar28 = (uint *)uStack_e;
                  puVar42 = uStack_e._2_2_;
                } while (local_a == (uint *)0x0 && local_8 == (uint *)0x0);
                if ((((uint *)uStack_e == (uint *)0x0 && uStack_e._2_2_ == (uint *)0x0) ||
                    (uStack_e._2_2_ != DAT_5b41_0567._2_2_)) ||
                   ((uint *)uStack_e != (uint *)DAT_5b41_0567)) break;
                local_12 = (uint *)CONCAT22(local_8,local_a);
                uStack_18._0_1_ = 0;
                uStack_18._1_1_ = 0x20;
                uStack_1a._0_1_ = 0x55;
                uStack_1a._1_1_ = 0x9e;
                puVar57 = uStack_e._2_2_;
                iVar53 = FUN_28eb_03ff();
                puVar25 = DAT_5b41_04ec;
                puVar26 = DAT_5b41_04ee;
                puVar28 = (uint *)uStack_e;
                puVar42 = uStack_e._2_2_;
                if (iVar53 != 0) {
                  local_12 = (uint *)CONCAT22(local_8,local_a);
                  uStack_18._0_1_ = 0;
                  uStack_18._1_1_ = 0x20;
                  uStack_1a._0_1_ = 0x71;
                  uStack_1a._1_1_ = 0x9e;
                  puVar25 = (uint *)FUN_28eb_0728();
                  puVar26 = puVar57;
                  puVar28 = (uint *)uStack_e;
                  puVar42 = uStack_e._2_2_;
                }
              }
              if ((local_8 != DAT_5b41_0567._2_2_) || (local_a != (uint *)DAT_5b41_0567)) break;
              local_12 = (uint *)CONCAT22(uStack_e._2_2_,(uint *)uStack_e);
              uStack_18._0_1_ = 0;
              uStack_18._1_1_ = 0x20;
              uStack_1a._0_1_ = 0x9e;
              uStack_1a._1_1_ = 0x9e;
              iVar53 = FUN_28eb_03ff();
              puVar57 = local_8;
              puVar25 = DAT_5b41_04ec;
              puVar26 = DAT_5b41_04ee;
              puVar28 = local_a;
              puVar42 = local_8;
              if (iVar53 == 0) {
                DAT_5b41_04ee = local_8;
                DAT_5b41_04ec = local_a;
                puVar25 = DAT_5b41_04ec;
                puVar26 = DAT_5b41_04ee;
                puVar28 = local_a;
                puVar42 = local_8;
              }
            }
            puVar57 = local_8;
            if (((uint *)uStack_e != (uint *)0x0 || uStack_e._2_2_ != (uint *)0x0) &&
               ((*(byte *)((int)local_a + 0xb) & 0x80) == 0)) break;
            DAT_5b41_04ee = local_8;
            DAT_5b41_04ec = local_a;
            if ((((((*(byte *)((int)local_a + 0xb) & 0x80) == 0) || (iRam000557bc == 3)) ||
                 (((uint *)DAT_5b41_0567 != (uint *)0x0 || DAT_5b41_0567._2_2_ != (uint *)0x0 &&
                  (((uint *)DAT_5b41_0567)[4] == 10)))) ||
                (((uint *)DAT_5b41_0567 != (uint *)0x0 || DAT_5b41_0567._2_2_ != (uint *)0x0 &&
                 (((uint *)DAT_5b41_0567)[4] == 0x4c)))) ||
               ((puVar25 = DAT_5b41_04ec, puVar26 = DAT_5b41_04ee,
                (uint *)DAT_5b41_0567 != (uint *)0x0 || DAT_5b41_0567._2_2_ != (uint *)0x0 &&
                (((uint *)DAT_5b41_0567)[4] == 8)))) {
              local_12 = (uint *)CONCAT22(local_8,local_a);
              uStack_18._0_1_ = 0;
              uStack_18._1_1_ = 0x20;
              uStack_1a._0_1_ = 0xa0;
              uStack_1a._1_1_ = 0x9f;
              puVar28 = (uint *)FUN_28eb_0728();
              puVar25 = DAT_5b41_04ec;
              puVar26 = DAT_5b41_04ee;
              puVar42 = puVar57;
            }
          }
          puVar25 = local_a;
          puVar26 = local_8;
          puVar28 = local_a;
          puVar42 = local_8;
        } while (local_a[0x4c] == 0);
        local_12 = (uint *)CONCAT22(local_8,local_a);
        uStack_18._0_1_ = 0;
        uStack_18._1_1_ = 0x20;
        uStack_1a._0_1_ = 0xe1;
        uStack_1a._1_1_ = 0x9e;
        in_DX = local_8;
        iVar53 = FUN_28eb_03ff();
        puVar57 = local_8;
        puVar25 = local_a;
        puVar26 = local_8;
        puVar28 = local_a;
        puVar42 = local_8;
      } while ((iVar53 != 0) ||
              (puVar57 = in_DX, puVar25 = DAT_5b41_04ec, puVar26 = DAT_5b41_04ee,
              puVar28 = (uint *)uStack_e, puVar42 = uStack_e._2_2_, ((uint *)uStack_e)[0x4c] == 0));
      local_12 = (uint *)CONCAT22(uStack_e._2_2_,(uint *)uStack_e);
    } while( true );
  case (uint *)0x5:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case (uint *)0x6:
    return puVar26;
  case (uint *)0x7:
    goto switchD_2000_81f0_caseD_7;
  case (uint *)0x8:
switchD_2000_81f0_caseD_8:
    puVar52 = (uint *)((uint)puVar52 | 0x3000);
    break;
  case (uint *)0x9:
    if ((*(byte *)((int)param_2 + 0xf) & 0x10) == 0) {
      if ((param_2[7] & 0x40) == 0) {
        puVar52 = (uint *)0x10;
      }
      else {
        puVar52 = (uint *)0x400;
      }
    }
    if (((*(byte *)((int)param_2 + 0xf) & 0x10) == 0) && ((DAT_5b41_051f & 0x10) == 0)) {
      puVar52 = (uint *)((uint)puVar52 | 0x20);
    }
    if ((*(byte *)((int)param_2 + 0xf) & 0x10) != 0) goto switchD_2000_81f0_caseD_8;
    break;
  case (uint *)0xa:
    goto switchD_2000_81f0_caseD_a;
  case (uint *)0xb:
    puVar57 = (uint *)0x0;
    puVar25 = (uint *)(((int)local_6._2_2_ - 2U) * 2);
    puVar26 = SUB42(s_String_reference_out_of_range_554c_5eb4._16_4_,2);
    goto code_r0x0002a3ab;
  case (uint *)0xc:
    out(uRam000554c0,in_DX);
    if (((((int)local_8 < (int)puVar57) ||
         ((int)((int)(uint *)uStack_e + 0x23) <= (int)local_6._2_2_)) ||
        ((int)local_a < (int)uStack_e._2_2_)) ||
       ((int)local_12._2_2_ + 0x23 <= (int)(uint *)local_6)) {
      param_4 = (uint *)0x0;
    }
    else {
      if ((CONCAT11(uStack_18._1_1_,(byte)uStack_18) != 0) && (DAT_5b41_0939 != 9)) {
        uVar60 = (undefined2)(CONCAT13(param_5._1_1_,CONCAT12((char)param_5,param_4)) >> 0x10);
        pbVar56 = (byte *)((int)unaff_DI + ((uint)(byte)param_4[0x2d] - param_4[0x2e]));
        uStack_e._2_2_ =
             (uint *)((int)unaff_SI + ((uint)*(byte *)((int)param_4 + 0x5b) - param_4[0x2e]));
        uStack_e._0_2_ = (uint *)(pbVar56 + param_4[0x2e] * 2);
        pbVar32 = (byte *)((int)uStack_e._2_2_ + param_4[0x2e] * 2);
        if (((uint *)*(undefined2 *)(CONCAT11(uStack_18._1_1_,(byte)uStack_18) + 4) == param_3) &&
           ((uint *)*(undefined2 *)(CONCAT11(uStack_18._1_1_,(byte)uStack_18) + 2) == param_2)) {
          pbVar56 = pbVar56 + -0x23;
          uStack_e._2_2_ = (uint *)((int)uStack_e._2_2_ + -0x23);
          uStack_e._0_2_ = (uint *)((int)(uint *)uStack_e + 0x23);
        }
        if ((((int)pbVar56 <= (int)local_8) && ((int)local_6._2_2_ < (int)(uint *)uStack_e)) &&
           (((int)uStack_e._2_2_ <= (int)local_a && ((int)(uint *)local_6 < (int)pbVar32)))) {
          iVar53 = CONCAT11(uStack_18._1_1_,(byte)uStack_18);
          if (((uint *)*(undefined2 *)(iVar53 + 8) == param_5) &&
             ((uint *)*(undefined2 *)(iVar53 + 6) == param_4)) {
            uVar60 = *(undefined2 *)(iVar53 + 10);
            *(undefined2 *)(iVar53 + 8) = *(undefined2 *)(iVar53 + 0xc);
            *(undefined2 *)(iVar53 + 6) = uVar60;
            *(undefined2 *)(iVar53 + 0xc) = param_5;
            *(undefined2 *)(iVar53 + 10) = param_4;
          }
          return (uint *)*(int *)(CONCAT11(uStack_18._1_1_,(byte)uStack_18) + 2);
        }
      }
      puVar57 = (uint *)uStack_1a;
      for (local_12._0_2_ = (uint *)0x0; (int)(uint *)local_12 < 2;
          local_12._0_2_ = (uint *)((int)(uint *)local_12 + 1)) {
        if (((puVar57 != (uint *)0x0) && (DAT_5b41_0939 != 9)) &&
           (uVar60 = (undefined2)(CONCAT13(param_5._1_1_,CONCAT12((char)param_5,param_4)) >> 0x10),
           param_4[4] != 7)) {
          bVar36 = (byte)param_4[(int)(uint *)local_12 + 0x3d];
          pbVar56 = (byte *)((int)unaff_DI + (char)bVar36 + -8);
          bVar23 = *(byte *)((int)param_4 + (int)(uint *)local_12 * 2 + 0x7b);
          uStack_e._2_2_ = (uint *)((int)unaff_SI + (char)bVar23 + -4);
          uStack_e._0_2_ = (uint *)((int)unaff_DI + (char)bVar36 + 8);
          local_12._2_2_ = (uint *)((int)unaff_SI + (char)bVar23 + 4);
          if (((uint *)puVar57[1] == param_3) && ((uint *)*puVar57 == param_2)) {
            pbVar56 = (byte *)((int)unaff_DI + (char)bVar36 + -0x2b);
            uStack_e._2_2_ = (uint *)((int)unaff_SI + (char)bVar23 + -0x27);
            uStack_e._0_2_ = (uint *)((int)unaff_DI + (char)bVar36 + 0x2b);
          }
          if ((((int)pbVar56 <= (int)local_8) && ((int)local_6._2_2_ < (int)(uint *)uStack_e)) &&
             (((int)uStack_e._2_2_ <= (int)local_a && ((int)(uint *)local_6 < (int)local_12._2_2_)))
             ) {
            if (((uint *)puVar57[3] == param_5) && ((uint *)puVar57[2] == param_4)) {
              uStack_18._0_1_ = (byte)puVar57;
              uStack_18._1_1_ = (byte)((uint)puVar57 >> 8);
              uStack_1a._0_1_ = 0;
              uStack_1a._1_1_ = 0x20;
              uStack_1c._0_1_ = 0xfe;
              uStack_1c._1_1_ = 0x9b;
              FUN_28eb_08be();
            }
            return (uint *)*puVar57;
          }
        }
        puVar57 = uStack_1c;
      }
    }
    return param_4;
  }
  if ((param_2[7] & 0x40) != 0) {
    return puVar52;
  }
  puVar57 = (uint *)((uint)puVar52 | 0x140);
  if (param_2[4] == 8) {
    return puVar57;
  }
  if (param_2[4] == 10) {
    return puVar57;
  }
  if (param_2[4] == 0x4c) {
    return puVar57;
  }
  if ((param_2[6] & 0x80) != 0) {
    puVar57 = (uint *)((uint)puVar52 | 0x141);
  }
  if ((*(byte *)((int)param_2 + 0xd) & 1) != 0) {
    puVar57 = (uint *)((uint)puVar57 | 2);
  }
  if (((*(byte *)((int)param_2 + 0xb) & 4) == 0) || ((*(byte *)((int)param_2 + 0xb) & 2) == 0)) {
    if ((*(byte *)((int)param_2 + 0xb) & 4) != 0) {
      if (DAT_5b41_0939 == 9) {
        puVar57 = (uint *)((uint)puVar57 | 4);
      }
      else {
        DAT_5b41_050f = 1;
        uStack_18._0_1_ = 1;
        uStack_18._1_1_ = 0;
        puVar63 = (undefined2 *)(*(int *)(param_2[4] * 2 + 0x302) + 0xc);
        uStack_1c._0_1_ = uVar12;
        uStack_1c._1_1_ = uVar13;
        uStack_1a._0_1_ = uVar15;
        uStack_1a._1_1_ = uVar17;
        (*(code *)*puVar63)();
        param_2[0x56] = param_2[6];
        uStack_1c._0_1_ = 0;
        uStack_1c._1_1_ = 0x20;
        uStack_1a._0_1_ = uVar12;
        uStack_1a._1_1_ = uVar13;
        uStack_18._0_1_ = uVar15;
        uStack_18._1_1_ = uVar17;
        iVar53 = FUN_28eb_0119();
        if (iVar53 == 0) {
          if (param_2[0x2c] != 0) {
            uStack_18._0_1_ = (byte)param_2[0x2c];
            uStack_18._1_1_ = (byte)(param_2[0x2c] >> 8);
            uStack_1a._0_1_ = 0;
            uStack_1a._1_1_ = 0x20;
            uStack_1c._0_1_ = 0x36;
            uStack_1c._1_1_ = 0xa3;
            iVar53 = FUN_28eb_1c08();
            if (iVar53 == 0) goto LAB_28eb_1490;
          }
          puVar57 = (uint *)((uint)puVar57 | 4);
        }
LAB_28eb_1490:
        uStack_18._0_1_ = 1;
        uStack_18._1_1_ = 0;
        puVar63 = (undefined2 *)(*(int *)(param_2[4] * 2 + 0x302) + 0xc);
        uStack_1c._0_1_ = uVar12;
        uStack_1c._1_1_ = uVar13;
        uStack_1a._0_1_ = uVar15;
        uStack_1a._1_1_ = uVar17;
        (*(code *)*puVar63)();
        param_2[0x56] = param_2[6];
        DAT_5b41_050f = 0;
      }
    }
    if ((*(byte *)((int)param_2 + 0xb) & 2) == 0) goto LAB_28eb_155d;
    if (DAT_5b41_0939 == 9) {
      puVar57 = (uint *)((uint)puVar57 | 8);
      goto LAB_28eb_155d;
    }
    DAT_5b41_050f = 1;
    uStack_18._0_1_ = 2;
    uStack_18._1_1_ = 0;
    puVar63 = (undefined2 *)(*(int *)(param_2[4] * 2 + 0x302) + 0xc);
    uStack_1c._0_1_ = uVar12;
    uStack_1c._1_1_ = uVar13;
    uStack_1a._0_1_ = uVar15;
    uStack_1a._1_1_ = uVar17;
    (*(code *)*puVar63)();
    puVar25 = param_2;
    puVar26 = param_3;
code_r0x0002a3ab:
    puVar25[0x56] = puVar25[6];
    uStack_1a._0_1_ = (char)puVar25;
    uStack_1a._1_1_ = (char)((uint)puVar25 >> 8);
    uStack_1c._0_1_ = 0;
    uStack_1c._1_1_ = 0x20;
    uStack_18._0_1_ = uVar15;
    uStack_18._1_1_ = uVar17;
    iVar53 = FUN_28eb_0119();
    if (iVar53 == 0) {
      if (param_2[0x2c] != 0) {
        uStack_18._0_1_ = (byte)param_2[0x2c];
        uStack_18._1_1_ = (byte)(param_2[0x2c] >> 8);
        uStack_1a._0_1_ = 0;
        uStack_1a._1_1_ = 0x20;
        uStack_1c._0_1_ = 0xd6;
        uStack_1c._1_1_ = 0xa3;
        iVar53 = FUN_28eb_1c08();
        if (iVar53 == 0) goto LAB_28eb_1530;
      }
      puVar57 = (uint *)((uint)puVar57 | 8);
    }
LAB_28eb_1530:
    uStack_18._0_1_ = 2;
    uStack_18._1_1_ = 0;
    puVar63 = (undefined2 *)(*(int *)(param_2[4] * 2 + 0x302) + 0xc);
    uStack_1c._0_1_ = uVar12;
    uStack_1c._1_1_ = uVar13;
    uStack_1a._0_1_ = uVar15;
    uStack_1a._1_1_ = uVar17;
    (*(code *)*puVar63)();
    param_2[0x56] = param_2[6];
  }
  else {
    if (DAT_5b41_0939 == 9) {
      puVar57 = (uint *)((uint)puVar57 | 0xc);
      goto LAB_28eb_155d;
    }
    local_6._2_2_ = (uint *)param_2[8];
    local_6._0_2_ = (uint *)param_2[6];
    DAT_5b41_050f = 1;
    bVar61 = false;
    do {
      uStack_18._0_1_ = 0xf;
      uStack_18._1_1_ = 0;
      puVar63 = (undefined2 *)(*(int *)(param_2[4] * 2 + 0x302) + 0xc);
      uStack_1c._0_1_ = uVar12;
      uStack_1c._1_1_ = uVar13;
      uStack_1a._0_1_ = uVar15;
      uStack_1a._1_1_ = uVar17;
      (*(code *)*puVar63)();
      param_2[0x56] = param_2[6];
      if (((uint *)param_2[8] == local_6._2_2_) && ((uint *)param_2[6] == (uint *)local_6)) {
LAB_28eb_13e7:
        bVar61 = true;
      }
      else {
        uStack_1c._0_1_ = 0;
        uStack_1c._1_1_ = 0x20;
        uStack_1a._0_1_ = uVar12;
        uStack_1a._1_1_ = uVar13;
        uStack_18._0_1_ = uVar15;
        uStack_18._1_1_ = uVar17;
        iVar53 = FUN_28eb_0119();
        if (iVar53 == 0) {
          if (param_2[0x2c] != 0) {
            uStack_18._0_1_ = (byte)param_2[0x2c];
            uStack_18._1_1_ = (byte)(param_2[0x2c] >> 8);
            uStack_1a._0_1_ = 0;
            uStack_1a._1_1_ = 0x20;
            uStack_1c._0_1_ = 0x8d;
            uStack_1c._1_1_ = 0xa2;
            iVar53 = FUN_28eb_1c08();
            if (iVar53 == 0) goto LAB_28eb_13ea;
          }
          puVar57 = (uint *)((uint)puVar57 | 0xc);
          goto LAB_28eb_13e7;
        }
      }
LAB_28eb_13ea:
    } while (!bVar61);
    param_2[8] = (uint)local_6._2_2_;
    param_2[6] = (uint)(uint *)local_6;
    param_2[0x56] = (uint)(uint *)local_6;
    uStack_18._0_1_ = 0;
    uStack_18._1_1_ = 0;
    puVar63 = (undefined2 *)(*(int *)(param_2[4] * 2 + 0x302) + 0xc);
    uStack_1c._0_1_ = uVar12;
    uStack_1c._1_1_ = uVar13;
    uStack_1a._0_1_ = uVar15;
    uStack_1a._1_1_ = uVar17;
    (*(code *)*puVar63)();
  }
  DAT_5b41_050f = 0;
LAB_28eb_155d:
  if ((*(byte *)((int)param_2 + 0xf) & 4) != 0) {
    if (((uint)puVar57 & 1) == 0) {
      puVar57 = (uint *)((uint)puVar57 | 0x80);
    }
    else {
      puVar57 = (uint *)((uint)puVar57 | 0x800);
    }
  }
  if (((iRam000557bc == 1) || (iRam000557bc == 6)) && ((*(byte *)((int)param_2 + 0xf) & 0x80) != 0))
  {
    puVar57 = (uint *)((uint)puVar57 | 0x200);
  }
  return puVar57;
switchD_2000_81f0_caseD_a:
  puStack_2c = (uint *)0x687c;
  uVar60 = FUN_1000_199e();
  *(uint **)(puVar48 + -0x12) = in_DX;
  *(undefined2 *)(puVar48 + -0x14) = uVar60;
  iVar53 = *(int *)(puVar48 + 8);
  *(int *)(puVar48 + -0x26) = iVar53 * 2 >> 0xf;
  *(int *)(puVar48 + -0x28) = iVar53 * 2;
  uVar60 = *(undefined2 *)(puVar48 + 0xc);
  puStack_2c = (uint *)0x689c;
  uVar58 = FUN_1000_199e();
  *(undefined2 *)(puVar48 + -0x16) = uVar60;
  *(undefined2 *)(puVar48 + -0x18) = uVar58;
  uVar60 = *(undefined2 *)(puVar48 + 0x18);
  puStack_2c = (uint *)0x68b0;
  uVar58 = FUN_1000_199e();
  *(undefined2 *)(puVar48 + -0x1a) = uVar60;
  *(undefined2 *)(puVar48 + -0x1c) = uVar58;
  iVar53 = 1 << (puVar48[8] & 0x1f);
  *(int *)(puVar48 + -0x22) = iVar53 >> 0xf;
  *(int *)(puVar48 + -0x24) = iVar53;
  puStack_2c = (uint *)&DAT_5b41_0983;
  uVar60 = FUN_1000_19bf();
  *(undefined2 *)(puVar48 + -2) = uVar60;
  puStack_2c = (uint *)0x68e4;
  uVar60 = FUN_1000_19bf();
  *(undefined2 *)(puVar48 + -4) = uVar60;
  *(undefined2 *)(puVar48 + -0x1e) = 0;
  *(undefined2 *)(puVar48 + -0x20) = 0;
  while( true ) {
    if ((*(int *)(puVar48 + -0x22) <= *(int *)(puVar48 + -0x1e)) &&
       ((*(int *)(puVar48 + -0x22) < *(int *)(puVar48 + -0x1e) ||
        (*(uint **)(puVar48 + -0x24) < *(uint **)(puVar48 + -0x20))))) break;
    puStack_2c = (uint *)0x6902;
    iVar53 = FUN_1000_19bf();
    puStack_2c = (uint *)0x6912;
    iVar43 = FUN_1000_19bf();
    if ((*(int *)(puVar48 + -2) != iVar53) || (*(int *)(puVar48 + -4) != iVar43)) {
      puStack_2e = *(uint **)(puVar48 + -4);
      pbStack_30 = *(byte **)(puVar48 + -2);
      puStack_32 = (uint *)0x1000;
      puStack_34 = (uint *)((int)(undefined2 *)&DAT_5b41_09da + 1);
      puStack_2c = (uint *)iVar53;
      FUN_2424_27e0();
      *(int *)(puVar48 + -2) = iVar53;
      *(int *)(puVar48 + -4) = iVar43;
    }
    iVar53 = *(int *)(puVar48 + -6);
    puStack_2c = (uint *)0x6953;
    uVar34 = FUN_1000_180a();
    uVar33 = *(uint *)(puVar48 + -0x10);
    uVar29 = uVar34 + *(uint *)(puVar48 + -0x10);
    iVar43 = *(int *)(puVar48 + -0xe);
    puVar62 = (uint *)(puVar48 + -0x18);
    uVar31 = *puVar62;
    *puVar62 = *puVar62 + uVar29;
    *(uint *)(puVar48 + -0x16) =
         *(int *)(puVar48 + -0x16) + iVar53 + iVar43 + (uint)CARRY2(uVar34,uVar33) +
         (uint)CARRY2(uVar31,uVar29);
    iVar53 = *(int *)(puVar48 + -10);
    puStack_2c = (uint *)0x697e;
    uVar34 = FUN_1000_180a();
    uVar33 = *(uint *)(puVar48 + -0x14);
    uVar29 = uVar34 + *(uint *)(puVar48 + -0x14);
    iVar43 = *(int *)(puVar48 + -0x12);
    puVar62 = (uint *)(puVar48 + -0x1c);
    uVar31 = *puVar62;
    *puVar62 = *puVar62 + uVar29;
    *(uint *)(puVar48 + -0x1a) =
         *(int *)(puVar48 + -0x1a) + iVar53 + iVar43 + (uint)CARRY2(uVar34,uVar33) +
         (uint)CARRY2(uVar31,uVar29);
    puVar62 = (uint *)(puVar48 + -0x20);
    uVar31 = *puVar62;
    *puVar62 = *puVar62 + 1;
    *(uint *)(puVar48 + -0x1e) = *(int *)(puVar48 + -0x1e) + (uint)(0xfffe < uVar31);
  }
  return *(uint **)(puVar48 + -0x20);
}

