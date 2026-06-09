// TIM2.EXE: FUN_28eb_1e42 @ file 0x02FEF2 Ghidra 0x2ACF2
// Subsystem: misc | Size: 180 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00021f80) overlaps instruction at (ram,0x00021f7f)
    */

int * __cdecl16far FUN_28eb_1e42(int *param_1,int *param_2)

{
  char *pcVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  bool bVar18;
  undefined4 uVar19;
  int local_a;
  uint local_8;
  undefined4 local_6;
  
  piVar17 = (int *)((ulong)param_1 >> 0x10);
  piVar13 = (int *)param_1;
  iVar4 = piVar13[0x32];
  if (piVar13[0x31] == 0 && iVar4 == 0) {
    piVar6 = (int *)0x0;
  }
  else {
    iVar16 = piVar13[0x30];
    iVar10 = piVar13[0x2f];
    iVar15 = iVar16;
    local_6._2_2_ = FUN_28eb_1cb7(piVar13,piVar17,piVar13[0x31],iVar4);
    local_6._2_2_ = local_6._2_2_ + 0x2000;
    local_6._0_2_ = FUN_28eb_1cb7(piVar13,piVar17,iVar10,iVar16);
    local_6._0_2_ = (int)local_6 + 0x2000;
    uVar5 = (int)local_6 - local_6._2_2_;
    if (uVar5 < 0x8000) {
      local_8 = (uVar5 >> 1) + local_6._2_2_;
    }
    else {
      local_8 = (-uVar5 >> 1) + (int)local_6;
    }
    piVar6 = (int *)(local_8 >> 0xe);
    if (piVar6 < (int *)0x4) {
      piVar12 = (int *)((int)piVar6 * 2);
      switch(piVar6) {
      case (int *)0x0:
        in(iVar15);
        iVar4 = piVar13[1] - piVar13[3] >> 0xf;
        local_6 = (int *)(long)(piVar13[1] - piVar13[3]);
        local_a = *piVar13 - piVar13[2];
        local_8 = local_a >> 0xf;
        uVar7 = FUN_1000_180a(uVar5,piVar6);
        uVar5 = local_8;
        uVar8 = FUN_1000_180a(iVar4,uVar7);
        iVar14 = (iVar4 - uVar5) - (uint)(uVar7 < uVar8);
        iVar9 = piVar17[3] - piVar17[1] >> 0xf;
        iVar10 = piVar17[2] - *piVar17 >> 0xf;
        iVar4 = iVar9;
        uVar5 = FUN_1000_180a();
        iVar16 = iVar10;
        uVar7 = FUN_1000_180a(iVar4,uVar5);
        iVar15 = (iVar4 - iVar10) - (uint)(uVar5 < uVar7);
        uVar5 = local_8;
        uVar7 = FUN_1000_180a();
        iVar4 = iVar16;
        uVar8 = FUN_1000_180a();
        iVar10 = uVar7 - uVar8;
        iVar16 = (uVar5 - iVar16) - (uint)(uVar7 < uVar8);
        if (iVar10 == 0 && iVar16 == 0) {
          uVar5 = FUN_1000_180a();
          uVar7 = FUN_1000_180a();
          if (uVar5 + uVar7 == 0 && iVar9 + iVar4 + (uint)CARRY2(uVar5,uVar7) == 0) {
            iVar4 = piVar13[2];
            iVar16 = piVar13[3];
          }
          else {
            iVar4 = 0;
            iVar16 = 0;
          }
        }
        else {
          uVar5 = local_8;
          uVar7 = FUN_1000_180a();
          uVar8 = FUN_1000_180a(uVar5,uVar7);
          iVar4 = FUN_1000_18f0(0x1000,uVar7 - uVar8,(uVar5 - iVar4) - (uint)(uVar7 < uVar8),iVar10)
          ;
          uVar5 = FUN_1000_180a(iVar16);
          uVar7 = FUN_1000_180a(iVar15,uVar5);
          iVar16 = FUN_1000_18f0(0x1000,uVar5 - uVar7,(iVar15 - iVar14) - (uint)(uVar5 < uVar7),
                                 iVar10);
        }
        *param_2 = iVar4;
        param_2[1] = iVar16;
        iVar10 = FUN_2e67_1398(iVar4,*piVar13,piVar13[2]);
        if ((((iVar10 == 0) || (iVar4 = FUN_2e67_1398(iVar4,*piVar17,piVar17[2]), iVar4 == 0)) ||
            (iVar4 = FUN_2e67_1398(iVar16,piVar13[1],piVar13[3]), iVar4 == 0)) ||
           (iVar4 = FUN_2e67_1398(iVar16,piVar17[1],piVar17[3]), iVar4 == 0)) {
          piVar13 = (int *)0x0;
        }
        else {
          piVar13 = (int *)0x1;
        }
        return piVar13;
      case (int *)0x1:
        LOCK();
        *(undefined1 *)(uVar5 - 0x50) = (char)iVar15;
        UNLOCK();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (int *)0x2:
        iVar4 = ((int *)((int)piVar6 * 2))[0x12] - DAT_5b41_0927;
        local_8 = local_8 + iVar4;
        if (piVar6 + -1 < (int *)0xb) {
          puVar11 = (undefined2 *)((int)(piVar6 + -1) * 2);
          switch(piVar6) {
          case (int *)0x3:
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          do {
            LOCK();
            local_8 = *(int *)((int)puVar11 + -0x3e17);
            *(int *)((int)puVar11 + -0x3e17) = iVar4;
            UNLOCK();
            pcVar1 = (char *)((int)puVar11 + (int)(undefined2 *)&DAT_5b41_2839 + uVar5);
            *pcVar1 = *pcVar1 + (char)(local_8 >> 8);
            uVar5 = DAT_5b41_2837;
            DAT_5b41_2839 = local_8 + ((int)DAT_5b41_2837 >> 4);
            local_6 = (int *)(CONCAT22(DAT_5b41_2839,DAT_5b41_2837) & 0xffff000f);
            if (DAT_554c_42df == '\0') {
              uVar7 = *(int *)(*piVar6 + 6) * *(int *)(*piVar6 + 8);
              DAT_5b41_2837 = DAT_5b41_2837 & 0xf;
              uVar19 = FUN_2fc8_00fc(0x2000,uVar7,0,0,0);
              FUN_1a9e_74bc(uVar19,*(undefined2 *)*piVar6,((undefined2 *)*piVar6)[1],uVar7 >> 3);
              puVar11 = (undefined2 *)*piVar6;
              *puVar11 = (int)((ulong)uVar19 >> 0x10);
              puVar11[1] = (int)uVar19;
              FUN_1a9e_7911(puVar11);
              func_0x0002fdf5(0x2000,uVar19);
            }
            else {
              DAT_5b41_2837 = DAT_5b41_2837 & 0xf;
              FUN_1a9e_7911(*piVar6);
            }
            puVar11 = (undefined2 *)*piVar6;
            *puVar11 = local_6._2_2_;
            puVar11[1] = (int)local_6;
            puVar11[2] = 0xfffe;
            piVar6 = piVar6 + 1;
            iVar4 = DAT_5b41_2839;
          } while (*piVar6 != 0);
          local_8 = DAT_5b41_2839 - DAT_5b41_2835;
          iVar4 = DAT_5b41_2837 - DAT_5b41_2833;
          DAT_5b41_282f = local_8 + (iVar4 + 0xf >> 4);
          local_a = *(int *)*piVar13;
          pcVar3 = (code *)swi(0x21);
          (*pcVar3)();
          FUN_1000_130c(DAT_5b41_283f);
          return (int *)(local_8 * 0x10 + iVar4);
        }
        piVar13 = (int *)FUN_2424_1e00(&local_a);
        return piVar13;
      }
      do {
        if (piVar6 == (int *)(piVar12[0x11] + piVar12[0x24])) {
          local_8 = 9;
        }
        do {
          while( true ) {
            do {
              iVar16 = *(int *)((int)local_6 + 0x8e);
              local_6._0_2_ = *(int *)((int)local_6 + 0x8c);
              local_6._2_2_ = iVar16;
              if (((int)local_6 == 0 && iVar16 == 0) || (local_8 != 0)) {
                FUN_2424_4ae2(piVar13,piVar17,0x2000,0,0x10,piVar13[0x25],piVar13[0x25] + 0x10);
                piVar6 = piVar13;
                piVar12 = piVar17;
                while( true ) {
                  piVar2 = (int *)piVar6[0x47];
                  piVar6 = (int *)piVar6[0x46];
                  local_6 = (int *)CONCAT22(piVar2,piVar6);
                  if ((piVar6 == (int *)0x0 && piVar2 == (int *)0x0) || (local_a != 0)) break;
                  piVar12 = piVar2;
                  if (((piVar6[4] == 0x76) && (piVar6[0x25] == 0x20)) &&
                     (piVar13[0x12] + piVar13[0x25] == piVar6[0x12])) {
                    bVar18 = (*(byte *)(piVar6 + 6) & 0x30) == 0;
                    if (((iVar4 != 0) || (bVar18)) || (piVar6[0x11] != piVar13[0x11])) {
                      if (((iVar4 != 0) && (!bVar18)) &&
                         (piVar6[0x11] + piVar6[0x24] == piVar13[0x11] + piVar13[0x24])) {
                        local_a = 0xc;
                      }
                    }
                    else {
                      local_a = 10;
                    }
                  }
                }
                if ((piVar13[0x57] != local_8) || (piVar13[0x5a] != local_a)) {
                  FUN_2424_3746(piVar13,piVar17,1);
                  FUN_2424_3746(piVar13,piVar17,2);
                  piVar13[0x57] = local_8;
                  piVar13[0x5a] = local_a;
                  FUN_2424_3746(piVar13,piVar17,1);
                  FUN_2424_3746(piVar13,piVar17,2);
                }
                piVar13[0x57] = local_8;
                piVar13[0x5a] = local_a;
                if ((local_8 == 0) && (local_a == 0)) {
                  piVar13 = (int *)0x0;
                }
                else {
                  piVar13 = (int *)0x1;
                }
                return piVar13;
              }
            } while (((*(int *)((int)local_6 + 8) != 0x76) ||
                     (*(int *)((int)local_6 + 0x4a) != 0x20)) ||
                    (*(int *)((int)local_6 + 0x24) != piVar13[0x12] + -0x20));
            bVar18 = (*(byte *)((int)local_6 + 0xc) & 0x30) != 0;
            if (((iVar4 != 0) || (bVar18)) || (*(int *)((int)local_6 + 0x22) != piVar13[0x11]))
            break;
            local_8 = 7;
          }
        } while ((iVar4 == 0) || (bVar18));
        piVar6 = (int *)(*(int *)((int)local_6 + 0x22) + *(int *)((int)local_6 + 0x48));
        piVar12 = piVar13;
      } while( true );
    }
    piVar13[8] = (int)piVar6;
    piVar13[0x54] = (int)piVar6;
  }
  return piVar6;
}

