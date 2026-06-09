// TIM2.EXE: FUN_2e67_06ab @ file 0x033F1B Ghidra 0x2ED1B
// Subsystem: misc | Size: 75 bytes


/* WARNING: Removing unreachable block (ram,0x00022ca4) */

undefined2 * __cdecl16far FUN_2e67_06ab(ulong param_1,ulong param_2)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  ulong uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined2 *unaff_SI;
  int unaff_DI;
  undefined2 uVar14;
  bool bVar15;
  int iStackY_2c;
  int iStackY_2a;
  int iStackY_28;
  int iStackY_26;
  int iStackY_24;
  undefined4 uStackY_22;
  undefined4 uStackY_1e;
  uint uStackY_1a;
  int iStackY_18;
  uint uStackY_16;
  int iStackY_12;
  undefined2 in_stack_0000fff0;
  undefined2 in_stack_0000fff2;
  
  if (DAT_5b41_0bec == 0) {
    puVar10 = (undefined2 *)0xffff;
  }
  else if (DAT_5b41_0bee == 0) {
    uVar5 = (param_1 & 0xffff) / 1000;
    uStackY_16 = (uint)uVar5;
    uVar12 = (uint)param_1 % 1000;
    if (uStackY_16 < 5) {
      puVar10 = (undefined2 *)(uStackY_16 * 2);
      cVar6 = (char)uVar5;
      switch(uStackY_16) {
      case 0:
        do {
          if ((int)uStackY_1e == 0 && uStackY_1e._2_2_ == 0) {
            return (undefined2 *)0x0;
          }
          if ((int)uStackY_22 == 0 && uStackY_22._2_2_ == 0) {
            return (undefined2 *)0x0;
          }
          if ((uStackY_1e._2_2_ != iStackY_24) || ((int)uStackY_1e != iStackY_26)) {
            iStackY_18 = 1;
            uStackY_16 = 0;
          }
          iVar13 = *(int *)((int)uStackY_1e + 0x2e) +
                   (int)*(char *)((int)uStackY_1e + iStackY_18 * 2 + 0x7a);
          iVar8 = *(int *)((int)uStackY_1e + 0x30) +
                  (int)*(char *)((int)uStackY_1e + iStackY_18 * 2 + 0x7b);
          if ((uStackY_22._2_2_ == iStackY_28) && ((int)uStackY_22 == iStackY_2a)) {
            uStackY_1a = (uint)*(byte *)(iStackY_2c + 0x15);
            uStackY_16 = FUN_28eb_3b36((int)uStackY_1e,uStackY_1e._2_2_,iStackY_2c,3);
          }
          iVar9 = *(int *)((int)uStackY_22 + 0x30);
          iVar11 = iVar9 + *(char *)((int)uStackY_22 + uStackY_1a * 2 + 0x7b);
          if (iVar13 < iVar9) {
            iVar7 = iVar13 - DAT_5b41_0925;
            iVar13 = iVar9;
          }
          else {
            iVar7 = iVar9 - DAT_5b41_0925;
          }
          if (iVar8 < iVar11) {
            iVar9 = iVar8 - DAT_5b41_0927;
            iVar8 = iVar11;
          }
          else {
            iVar9 = iVar11 - DAT_5b41_0927;
          }
          iVar8 = iVar8 - DAT_5b41_0927;
          if (0 < (int)uStackY_16) {
            iVar8 = iVar8 + ((int)uStackY_16 >> 1);
          }
          uVar12 = (uint)((iVar13 - DAT_5b41_0925) - iVar7 < iVar8 - iVar9);
          for (puVar10 = DAT_5b41_04ac; puVar10 != (undefined2 *)0x0;
              puVar10 = (undefined2 *)*puVar10) {
            if ((((puVar10[6] == 1) && ((int)puVar10[1] <= (int)((iVar13 - DAT_5b41_0925) + uVar12))
                 ) && ((int)(iVar7 - uVar12) <= (int)puVar10[3])) &&
               (((int)puVar10[2] <= (int)(iVar8 + (uint)(uVar12 == 0)) &&
                ((int)(iVar9 - (uint)(uVar12 == 0)) <= (int)puVar10[4])))) {
              FUN_28eb_2d82((uint)param_1,param_1._2_2_,0x81);
              uStackY_22 = CONCAT22(iStackY_28,iStackY_2a);
              break;
            }
          }
          if ((uStackY_22._2_2_ == iStackY_28) && ((int)uStackY_22 == iStackY_2a)) {
            uStackY_22 = 0;
            uStackY_1e = 0;
          }
          else {
            uStackY_1e = uStackY_22;
            uStackY_22 = CONCAT22(*(undefined2 *)((int)uStackY_22 + 0x60),
                                  *(undefined2 *)((int)uStackY_22 + 0x5e));
          }
        } while( true );
      case 2:
        puVar10[6] = (uint)(byte)(cVar6 + 0x89);
        puVar10[5] = in_stack_0000fff2;
        puVar10[4] = in_stack_0000fff0;
        puVar10[9] = in_stack_0000fff2;
        puVar10[8] = in_stack_0000fff0;
        uVar2 = *(undefined1 *)(puVar10 + 10);
        uVar3 = *(undefined1 *)((int)puVar10 + 0x15);
        *(undefined1 *)(puVar10 + 10) = uVar3;
        *(undefined1 *)(puVar10 + 0xb) = uVar3;
        *(undefined1 *)((int)puVar10 + 0x15) = uVar2;
        *(undefined1 *)((int)puVar10 + 0x17) = uVar2;
        puVar10 = (undefined2 *)FUN_2424_0f94(*puVar10,puVar10[1],3,0x2000,0);
        return puVar10;
      case 3:
        out(6,cVar6);
        bVar15 = true;
        FUN_1000_1821();
        if (!bVar15) {
          func_0x0002fdf5(0x1000,in_stack_0000fff0,in_stack_0000fff2);
        }
        if (iStackY_12 != 0) {
          FUN_1000_130c(iStackY_12);
          uRam00055624 = 0;
          uRam00055622 = 0;
        }
        if (uStackY_1e._2_2_ == 0) {
          bVar15 = true;
          FUN_1000_1821();
          if (!bVar15) {
            func_0x0002fdf5(0x1000,unaff_DI);
          }
          FUN_1a9e_82f5(unaff_SI);
          unaff_SI = (undefined2 *)0x0;
        }
        if (uStackY_1a != 0) {
          FUN_1a9e_6e73((uint)param_1 + 1);
        }
        return unaff_SI;
      case 4:
        if (*(int *)((uint)param_1 + 8) == 0x4f) {
          iVar8 = *(int *)((uint)param_1 + 0x24) + 0x13;
        }
        else if (*(int *)((uint)param_1 + 8) == 0xb) {
          iVar8 = *(int *)((uint)param_1 + 0x24) + 0x10;
        }
        else {
          iVar8 = *(int *)((uint)param_1 + 0x24) + (*(int *)((uint)param_1 + 0x56) >> 1);
        }
        uVar14 = (undefined2)(param_2 >> 0x10);
        iVar13 = (int)param_2;
        if (*(int *)(iVar13 + 8) == 0x4f) {
          iVar9 = *(int *)(iVar13 + 0x24) + 0x13;
        }
        else if (*(int *)(iVar13 + 8) == 0xb) {
          iVar9 = *(int *)(iVar13 + 0x24) + 0x10;
        }
        else {
          iVar9 = *(int *)(iVar13 + 0x24) + (*(int *)(iVar13 + 0x56) >> 1);
        }
        iVar9 = iVar9 - iVar8;
        puVar10 = (undefined2 *)
                  FUN_2e67_1277(iVar9,iVar9,iVar9,iVar9 >> 0xf,
                                *(int *)(iVar13 + 0x22) + (*(int *)(iVar13 + 0x54) >> 1),
                                *(int *)((uint)param_1 + 0x22) +
                                (*(int *)((uint)param_1 + 0x54) >> 1));
        return puVar10;
      }
      while( true ) {
        *(uint *)((int)unaff_SI + ((int)puVar10 >> 1) * 4 + 0x1d) = uStackY_16;
        *(uint *)((int)unaff_SI + ((int)puVar10 >> 1) * 4 + 0x1b) = uVar12;
        *(undefined2 *)((int)unaff_SI + 0x3f) = *(undefined2 *)((int)unaff_SI + 0x3f);
        *(uint *)((int)unaff_SI + 0x41) = *(uint *)((int)unaff_SI + 0x41) & 0x7fff;
        if (*(int *)((int)unaff_SI + 0x41) < 0) break;
        uVar12 = *(uint *)((int)unaff_SI + 0x1d) & 0x7fff;
        if ((uVar12 <= *(uint *)((int)unaff_SI + 0x41)) &&
           ((*(uint *)((int)unaff_SI + 0x41) != uVar12 ||
            (*(uint *)((int)unaff_SI + 0x1b) <= *(uint *)((int)unaff_SI + 0x3f))))) break;
        iVar8 = unaff_DI;
        if ((*(int *)((int)unaff_SI + 0x37) == unaff_DI) &&
           (iVar13 = FUN_1a9e_6904(unaff_SI + 1,param_1._2_2_), iVar13 != 0)) {
          iVar13 = (int)param_2;
          param_2 = (ulong)((int)param_2 - 1);
          if (iVar13 == 0) {
            *(int *)((int)unaff_SI + 0x39) = unaff_DI;
            return (undefined2 *)*(undefined2 *)((int)unaff_SI + 0x3b);
          }
        }
        while( true ) {
          while ((unaff_DI = iVar8, iVar8 = *(int *)((int)unaff_SI + 0x37) >> 2,
                 (*(uint *)((int)unaff_SI + iVar8 * 4 + 0x1d) & 0x7fff) ==
                 *(uint *)((int)unaff_SI + 0x3d) &&
                 (*(int *)((int)unaff_SI + iVar8 * 4 + 0x1b) == *(int *)((int)unaff_SI + 0x3b)))) {
            if (*(int *)((int)unaff_SI + 0x37) == 0) {
              puVar10 = (undefined2 *)FUN_1a9e_6a52(unaff_SI);
              return puVar10;
            }
            *(int *)((int)unaff_SI + 0x37) = *(int *)((int)unaff_SI + 0x37) + -4;
            iVar8 = unaff_DI;
          }
          if ((*(uint *)((int)unaff_SI + (*(int *)((int)unaff_SI + 0x37) >> 2) * 4 + 0x1d) & 0x8000)
              != 0) break;
          iVar8 = *(int *)((int)unaff_SI + 0x41);
          uVar4 = *(uint *)((int)unaff_SI + 0x3f);
          puVar1 = (uint *)((int)unaff_SI + 0x3b);
          uVar12 = *puVar1;
          *puVar1 = *puVar1 + uVar4;
          *(int *)((int)unaff_SI + 0x3d) =
               *(int *)((int)unaff_SI + 0x3d) + iVar8 + (uint)CARRY2(uVar12,uVar4);
          FUN_1000_0e6d(*unaff_SI,*(undefined2 *)((int)unaff_SI + 0x3b),
                        *(undefined2 *)((int)unaff_SI + 0x3d),0);
          iVar8 = unaff_DI;
        }
        iVar8 = FUN_1000_0d10((int)unaff_SI + *(int *)((int)unaff_SI + 0x37) + 2,1,4,*unaff_SI);
        if (iVar8 != 4) {
          puVar10 = (undefined2 *)FUN_1a9e_6a52(unaff_SI);
          return puVar10;
        }
        *(int *)((int)unaff_SI + 0x37) = *(int *)((int)unaff_SI + 0x37) + 4;
        if (0x17 < *(int *)((int)unaff_SI + 0x37)) {
          puVar10 = (undefined2 *)FUN_1a9e_6a52(unaff_SI);
          return puVar10;
        }
        *(undefined1 *)((int)unaff_SI + *(int *)((int)unaff_SI + 0x37) + 2) = 0;
        puVar1 = (uint *)((int)unaff_SI + 0x3b);
        uVar12 = *puVar1;
        *puVar1 = *puVar1 + 8;
        *(int *)((int)unaff_SI + 0x3d) = *(int *)((int)unaff_SI + 0x3d) + (uint)(0xfff7 < uVar12);
        iVar8 = FUN_1000_0d10((int)unaff_SI + 0x3f,4,1,*unaff_SI);
        if (iVar8 != 1) {
          puVar10 = (undefined2 *)FUN_1a9e_6a52(unaff_SI);
          return puVar10;
        }
        uVar12 = *(uint *)((int)unaff_SI + 0x3b) + *(uint *)((int)unaff_SI + 0x3f);
        uStackY_16 = *(int *)((int)unaff_SI + 0x3d) + *(int *)((int)unaff_SI + 0x41) +
                     (uint)CARRY2(*(uint *)((int)unaff_SI + 0x3b),*(uint *)((int)unaff_SI + 0x3f));
        puVar10 = (undefined2 *)(*(int *)((int)unaff_SI + 0x37) >> 1);
      }
      puVar10 = (undefined2 *)FUN_1a9e_6a52(unaff_SI);
      return puVar10;
    }
    puVar10 = (undefined2 *)0x0;
  }
  else {
    puVar10 = (undefined2 *)FUN_2e67_08ed((uint)param_1,0,0,0);
  }
  return puVar10;
}

