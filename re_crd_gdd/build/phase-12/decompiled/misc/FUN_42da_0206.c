// TIM2.EXE: FUN_42da_0206 @ file 0x0481A6 Ghidra 0x42FA6
// Subsystem: misc | Size: 373 bytes


undefined2 * __cdecl16near
FUN_42da_0206(undefined2 param_1,char *param_2,int param_3,undefined2 param_4,undefined2 param_5)

{
  char *pcVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  uint *puVar7;
  char cVar8;
  int *piVar9;
  int iVar10;
  undefined2 *puVar11;
  uint in_CX;
  char *in_DX;
  char *extraout_DX;
  undefined1 auVar12 [2];
  int *piVar13;
  char *pcVar14;
  char *pcVar15;
  undefined2 unaff_ES;
  undefined2 uVar16;
  char *pcVar17;
  undefined2 unaff_SS;
  bool bVar18;
  undefined2 *puVar19;
  int aiStack_82 [12];
  undefined2 uStack_6a;
  undefined2 uStack_68;
  char *pcStack_66;
  undefined2 uStack_64;
  undefined1 uStack_62;
  undefined1 auStack_61 [2];
  undefined1 uStack_5f;
  int local_5a [38];
  undefined4 uStack_e;
  undefined4 local_a;
  int *local_6;
  char *local_4;
  
  auVar12 = (undefined1  [2])&stack0xfffe;
  local_a = (int *)((ulong)local_a & 0xffff0000);
  if (param_2 == (char *)0x0) {
    param_2 = (char *)s_RESOURCE_CFG_554c_3f69;
  }
  auStack_61[1] = 0x76;
  uStack_5f = 0x3f;
  uStack_62 = SUB21(param_2,0);
  auStack_61[0] = (undefined1)((uint)param_2 >> 8);
  uStack_64._0_1_ = 0xda;
  uStack_64._1_1_ = 0x42;
  pcStack_66 = (char *)0x2fc9;
  local_4 = (char *)FUN_1000_418e();
  if (local_4 != (char *)0x0) {
    while( true ) {
      auStack_61[1] = SUB21(local_4,0);
      uStack_5f = (undefined1)((uint)local_4 >> 8);
      uStack_62 = 0x50;
      auStack_61[0] = 0;
      uStack_64 = local_5a;
      pcStack_66 = (char *)0x1000;
      uStack_68 = 0x31fa;
      iVar10 = FUN_1000_3eac();
      if (iVar10 == 0) break;
      piVar9 = local_5a;
      for (local_6 = piVar9; (piVar13 = local_6, (char)*local_6 != '\0' && ((char)*local_6 < '!'));
          local_6 = (int *)((int)local_6 + 1)) {
      }
      for (; ((char)*piVar13 != '\0' && (' ' < (char)*piVar13)); piVar13 = (int *)((int)piVar13 + 1)
          ) {
      }
      *(char *)piVar13 = '\0';
      pcVar15 = (char *)((int)piVar13 + 1);
      do {
        pcVar14 = pcVar15;
        if (*pcVar15 == '\0') break;
        pcVar14 = pcVar15 + 1;
        pcVar1 = pcVar15;
        pcVar15 = pcVar14;
      } while (*pcVar1 != '=');
      for (; (*pcVar14 != '\0' && (*pcVar14 < '!')); pcVar14 = pcVar14 + 1) {
      }
      for (local_a._2_2_ = pcVar14; (*local_a._2_2_ != '\0' && (' ' < *local_a._2_2_));
          local_a._2_2_ = local_a._2_2_ + 1) {
      }
      *local_a._2_2_ = '\0';
      for (pcVar15 = (char *)0x0; (int)pcVar15 < 9; pcVar15 = pcVar15 + 1) {
        auStack_61[1] = SUB21(local_6,0);
        uStack_5f = (undefined1)((uint)local_6 >> 8);
        uStack_62 = (undefined1)((undefined2 *)&DAT_554c_3e74)[(int)pcVar15];
        auStack_61[0] = (undefined1)((uint)((undefined2 *)&DAT_554c_3e74)[(int)pcVar15] >> 8);
        uStack_64._0_1_ = 0;
        uStack_64._1_1_ = 0x10;
        pcStack_66 = (char *)0x3056;
        piVar9 = (int *)FUN_1000_5494();
        if (piVar9 == (int *)0x0) break;
      }
      puVar11 = (int *)local_a;
      local_a._0_2_ = (int *)((int)(int *)local_a + 1);
      if (pcVar15 < "CHECK") {
        puVar11 = (undefined2 *)((int)pcVar15 * 2);
        pcVar17 = (char *)0x4000;
        switch(pcVar15) {
        case (char *)0x0:
          cVar8 = (char)((uint)piVar9 >> 8) + cRam00057349;
          ((char *)((int)puVar11 + (int)pcVar14))[0x40] =
               ((char *)((int)puVar11 + (int)pcVar14))[0x40] + (char)puVar11;
          *puVar11 = CONCAT11(cVar8,(char)piVar9);
          return (undefined2 *)CONCAT22(in_DX,puVar11 + 2);
        case "":
          cVar8 = (char)piVar9 + -0x5f;
          bVar18 = cVar8 == '\0';
          *pcVar15 = *pcVar14;
          if ((POPCOUNT(cVar8) & 1U) != 0) {
            if ((POPCOUNT(pcVar14[1] - pcVar15[1]) & 1U) == 0) {
              pcVar15[-0x33] = pcVar15[-0x33] + (char)puVar11;
              DAT_5b41_1b60 = DAT_554c_3d57;
              DAT_5b41_1b61 = DAT_554c_3d56;
              DAT_5b41_1b62 = DAT_554c_3d52;
              DAT_5b41_1b5e = DAT_554c_3d5a;
              DAT_5b41_1b5c = DAT_554c_3d58;
              DAT_554c_3d57 = 1;
              DAT_554c_3d56 = 1;
              DAT_554c_3d52 = 0;
              DAT_554c_3d5a = DAT_5b41_1b56;
              DAT_554c_3d58 = DAT_5b41_1b54;
              return (undefined2 *)CONCAT22(DAT_5b41_1b56,DAT_5b41_1b54);
            }
            bVar18 = param_2 == (char *)0x0 && param_3 == 0;
          }
          if (((!bVar18) && (param_3 == 0)) && (param_2 < (char *)0xffdd)) {
            auStack_61[1] = 0;
            uStack_5f = 0x40;
            uStack_62 = 0x2d;
            auStack_61[0] = 0;
            FUN_3f2b_0dd2();
            auStack_61[1] = (undefined1)param_5;
            uStack_5f = (undefined1)((uint)param_5 >> 8);
            uStack_62 = (undefined1)param_4;
            auStack_61[0] = (undefined1)((uint)param_4 >> 8);
            uStack_64._0_1_ = 0;
            uStack_64._1_1_ = 0;
            pcStack_66 = param_2;
            uStack_68 = 0x4000;
            uStack_6a = 0x3e;
            local_6 = (int *)FUN_3f2b_0fa3();
            auStack_61[1] = 0;
            uStack_5f = 0x40;
            uStack_62 = 0x4c;
            auStack_61[0] = 0;
            local_4 = in_DX;
            FUN_3f2b_0e15();
            return (undefined2 *)CONCAT22(local_4,local_6);
          }
          return (undefined2 *)0x0;
        case "":
          uStack_62 = 0;
          auStack_61[0] = 0x40;
          uStack_64._0_1_ = 0x6c;
          uStack_64._1_1_ = 0xc3;
          unique0x100002a0 = &stack0xfffe;
          puVar19 = (undefined2 *)(*pcRam000556ad)();
          return puVar19;
        case "":
          goto switchD_4000_306c_caseD_3;
        case "NULL CHECK":
          iRam00050011 = *(int *)0x8a + 0x10;
          uVar16 = 0x5464;
          pcVar15 = (char *)0x0;
          puVar11 = (undefined2 *)0x1a0;
          do {
            if (((puVar11[2] & 2) != 0) && (puVar11[1] != 0)) {
              uVar5 = *puVar11;
              *(undefined2 *)0x12 = uVar5;
              if (*"Borland C++ - Copyright 1993 Borland Intl." == -1) {
                *(undefined2 *)0x12 = 0;
              }
              else {
                *(undefined2 *)0x18 = 0x4c9;
                iVar10 = iRam000555d6;
                puVar2 = (uint *)0x4;
                bVar18 = CARRY2(*puVar2,uRam000555d4);
                *puVar2 = *puVar2 + uRam000555d4;
                *(int *)0x6 = *(int *)0x6 + iVar10 + (uint)bVar18;
                uStack_64._1_1_ = 99;
                uStack_62 = 0;
                auStack_61 = auVar12;
                FUN_4fd6_07b0();
                in_DX = extraout_DX;
                uVar16 = uVar5;
                auVar12 = auStack_61;
                if (pcVar15 < extraout_DX) {
                  in_DX = pcVar15;
                  pcVar15 = extraout_DX;
                }
              }
            }
            puVar11 = puVar11 + 4;
          } while (puVar11 < (undefined2 *)0x470);
          pcRam000555da = pcVar15 + 2;
          return (undefined2 *)(ZEXT24(in_DX) << 0x10);
        case "ULL CHECK":
          goto switchD_4000_306c_caseD_5;
        case "L CHECK":
          goto switchD_4000_306c_caseD_7;
        case " CHECK":
          DAT_53bd_003a = (int)*(undefined4 *)(&stack0xfffe + (int)pcVar14);
          DAT_53bd_003c._2_2_ = param_4;
          DAT_53bd_003c._0_2_ = param_3;
          return (undefined2 *)CONCAT22(param_4,(undefined2 *)(uint)(DAT_53bd_0038 != 0));
        }
        if (piVar9 == (int *)0x0 && in_DX == (char *)0x0) {
          puVar11 = (undefined2 *)0x0;
        }
        else {
          local_a = (int *)CONCAT22(in_DX,piVar9);
          iVar10 = 0;
          local_6 = piVar9;
          local_4 = in_DX;
          while( true ) {
            if (((int *)local_a == (int *)0x0 && local_a._2_2_ == (char *)0x0) || (iVar10 != 0))
            break;
            uStack_e = (int *)CONCAT22(local_a._2_2_,(int *)local_a + 0x14);
            iVar10 = *uStack_e;
            if (iVar10 != 0) {
              pcVar17 = (char *)0x4551;
              auStack_61[1] = 0x9a;
              uStack_5f = 0x8b;
              FUN_4551_0177();
            }
            in_DX = (char *)((int *)local_a)[1];
            local_a = (int *)CONCAT22(in_DX,(int *)*local_a);
          }
          auStack_61[1] = SUB21(local_4,0);
          uStack_5f = (undefined1)((uint)local_4 >> 8);
          uStack_62 = SUB21(local_6,0);
          auStack_61[0] = (undefined1)((uint)local_6 >> 8);
          uStack_64._0_1_ = SUB21(pcVar17,0);
          uStack_64._1_1_ = (undefined1)((uint)pcVar17 >> 8);
          pcVar17 = (char *)0x460e;
          pcStack_66 = (char *)0x8bc8;
          local_a._0_2_ = (int *)FUN_460e_141e();
          local_a._2_2_ = in_DX;
switchD_4000_306c_caseD_7:
          while (_local_6 = CONCAT22(local_a._2_2_,(int *)local_a),
                (int *)local_a != (int *)0x0 || local_a._2_2_ != (char *)0x0) {
            puVar11 = (undefined2 *)((int)(int *)local_a + 10);
            local_a._0_2_ = (int *)*(int *)((int)(int *)local_a + 8);
            auStack_61[1] = SUB21(pcVar17,0);
            uStack_5f = (undefined1)((uint)pcVar17 >> 8);
            pcVar17 = (char *)0x22de;
            uStack_62 = 0xed;
            auStack_61[0] = 0x8b;
            local_a._2_2_ = (char *)*puVar11;
            FUN_22de_0351();
            DAT_5b41_0be0 = DAT_5b41_0be0 + -1;
          }
          if (pcVar15 == DAT_554c_2f1c) {
            DAT_554c_2f1c = DAT_554c_2f1c + -100;
          }
          puVar11 = (undefined2 *)0x1;
          in_DX = local_a._2_2_;
        }
        return (undefined2 *)CONCAT22(in_DX,puVar11);
      }
      local_a = (int *)CONCAT22(local_a._2_2_,puVar11);
    }
    auStack_61[1] = SUB21(local_4,0);
    uStack_5f = (undefined1)((uint)local_4 >> 8);
    uStack_62 = 0;
    auStack_61[0] = 0x10;
    uStack_64._0_1_ = 0xc;
    uStack_64._1_1_ = 0x32;
    FUN_1000_3d77();
  }
  return (undefined2 *)CONCAT22(in_DX,(int *)local_a);
switchD_4000_306c_caseD_3:
  while( true ) {
    puVar6 = DAT_554c_42d8;
    out(0x3c4,CONCAT11('\x01' << (sbyte)(in_CX & 0xff03),2));
    *(char *)puVar11 = (char)((in_CX & 0xff03) >> 8);
    puVar7 = DAT_5b41_2858;
    pcVar14 = pcVar14 + 1;
    if ((uStack_e._2_2_ <= (int)pcVar14) &&
       (pcVar15 = pcVar15 + 1, pcVar14 = param_2, (int)(int *)local_a <= (int)pcVar15)) break;
    uVar3 = *DAT_5b41_2858;
    uVar4 = DAT_5b41_2858[1];
    *DAT_5b41_2858 = uVar3 + 8;
    puVar7[1] = uVar4 + (0xfff7 < uVar3);
    in_CX = CONCAT11((char)(*(uint *)(puVar7[2] +
                                     (((uVar3 >> 1 | (uint)((uVar4 & 1) != 0) << 0xf) >> 1 |
                                      (uint)((uVar4 >> 1 & 1) != 0) << 0xf) >> 1 |
                                     (uint)((uVar4 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar3 & 7)),
                     (char)pcVar15);
    puVar11 = (undefined2 *)(*(int *)((int)pcVar14 * 2 + 0x49b2) + ((uint)pcVar15 >> 2));
  }
  return (undefined2 *)CONCAT22(0x3c4,puVar6);
switchD_4000_306c_caseD_5:
  while( true ) {
    if (puVar11 != (undefined2 *)0x0) {
      auStack_61[1] = 0xff;
      uStack_5f = 0xff;
      uStack_62 = (undefined1)piVar9[(int)pcVar14];
      auStack_61[0] = (undefined1)((uint)piVar9[(int)pcVar14] >> 8);
      uStack_64._0_1_ = SUB21(pcVar17,0);
      uStack_64._1_1_ = (undefined1)((uint)pcVar17 >> 8);
      pcVar17 = (char *)s_PROAUDIO_DRV_554c_3f20 + 0xb;
      pcStack_66 = (char *)0x56d4;
      FUN_3f2b_09ca();
    }
    pcVar14 = pcVar14 + 1;
    if (0x3f < (int)pcVar14) break;
    piVar9 = aiStack_82;
    puVar11 = (undefined2 *)piVar9[(int)pcVar14];
  }
  auStack_61[1] = 1;
  uStack_5f = 0;
  uStack_62 = SUB21(pcVar15,0);
  auStack_61[0] = (undefined1)((uint)pcVar15 >> 8);
  uStack_64._0_1_ = SUB21(pcVar17,0);
  uStack_64._1_1_ = (undefined1)((uint)pcVar17 >> 8);
  pcStack_66 = (char *)0x56e5;
  puVar11 = (undefined2 *)FUN_3f2b_042f();
  return (undefined2 *)CONCAT22(in_DX,puVar11);
}

