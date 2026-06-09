// TIM2.EXE: FUN_31f7_6801 @ file 0x03D971 Ghidra 0x38771
// Subsystem: misc | Size: 166 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0003a10e) overlaps instruction at (ram,0x0003a10d)
    */
/* WARNING: Removing unreachable block (ram,0x00030703) */
/* WARNING: Removing unreachable block (ram,0x00030705) */
/* WARNING: Removing unreachable block (ram,0x00030734) */
/* WARNING: Removing unreachable block (ram,0x00030707) */
/* WARNING: Removing unreachable block (ram,0x00030720) */
/* WARNING: Removing unreachable block (ram,0x00030748) */
/* WARNING: Removing unreachable block (ram,0x0003070d) */
/* WARNING: Removing unreachable block (ram,0x0003070f) */
/* WARNING: Removing unreachable block (ram,0x00030711) */
/* WARNING: Removing unreachable block (ram,0x00030701) */
/* WARNING: Removing unreachable block (ram,0x0003076a) */
/* WARNING: Removing unreachable block (ram,0x0003077f) */

uint __cdecl16far FUN_31f7_6801(undefined4 param_1,int param_2)

{
  unkbyte10 Var1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined2 uVar10;
  int iVar11;
  int in_CX;
  uint in_DX;
  char *pcVar12;
  char *unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  bool bVar13;
  bool bVar14;
  longdouble in_ST0;
  unkbyte10 in_ST1;
  unkbyte10 in_ST3;
  unkbyte10 in_ST6;
  ulong uVar15;
  undefined4 uVar16;
  
  if ((param_2 != 0xf) || (uVar8 = FUN_31f7_688a(), 3 < uVar8)) {
    *(undefined2 *)((int)param_1 + 0xa8) = *(undefined2 *)((int)param_1 + 0x10);
    uVar15 = (ulong)param_1._2_2_;
    iVar9 = (int)param_1;
    FUN_31f7_677c();
    FUN_2424_0f94((int)param_1,param_1._2_2_,3,iVar9,uVar15);
    uVar8 = FUN_28eb_2d82((int)param_1,param_1._2_2_,2);
    return uVar8;
  }
  bVar14 = CARRY2(uVar8,uVar8);
  uVar7 = uVar8 * 2;
  uVar6 = uVar8;
  switch(uVar8) {
  case 1:
    in(in_DX);
    if (*(int *)(uVar7 + 8) == 0x21) {
      *(uint *)(uVar7 + 0xc) = *(uint *)(uVar7 + 0xc) ^ 0x10;
      FUN_31f7_3f13();
      uVar7 = *(int *)((int)param_1 + 0xa0) + 0x8000;
      iVar11 = *(int *)((int)param_1 + 0x9a);
      uVar6 = *(uint *)((int)param_1 + 0x9c);
      iVar9 = (int)param_1;
      uVar8 = param_1._2_2_;
    }
    else {
      uVar8 = *(uint *)((int)param_1 + 0x9c);
      iVar9 = *(int *)((int)param_1 + 0x9a);
      uVar7 = *(uint *)((int)param_1 + 0xa0);
      iVar11 = (int)param_1;
      uVar6 = param_1._2_2_;
    }
    if (((*(int *)(iVar11 + 8) == 4) || (*(int *)(iVar11 + 8) == 0x4f)) ||
       (*(int *)(iVar11 + 8) == 0x6d)) {
      if ((*(byte *)(iVar9 + 0xc) & 0x10) == 0) {
        if ((uVar7 & 0x8000) == 0) {
          return 1;
        }
        iVar9 = *(int *)(iVar11 + 8);
      }
      else {
        if ((uVar7 & 0x8000) != 0) {
          return 1;
        }
        iVar9 = *(int *)(iVar11 + 8);
      }
      if (iVar9 == 0x4f) {
        *(undefined2 *)(iVar11 + 0x16) = 2;
      }
      else {
        *(undefined2 *)(iVar11 + 0x16) = 1;
      }
    }
    return 1;
  case 2:
    uVar16 = CONCAT22(uVar8,0x7500);
    if ((POPCOUNT(uVar7 & 0xff) & 1U) == 0) {
      while( true ) {
        ((undefined2 *)&DAT_5b41_098d)[(int)unaff_SI] = uVar8;
        uVar10 = FUN_4551_0370(DAT_5b41_0a3a,((undefined2 *)&DAT_554c_3be6)[(int)unaff_SI],uVar16);
        ((undefined2 *)&DAT_5b41_1a5e)[(int)unaff_SI] = uVar10;
        uVar10 = FUN_4551_0370();
        ((undefined2 *)&DAT_5b41_1a64)[(int)unaff_SI] = uVar10;
        unaff_SI = unaff_SI + 1;
        if (2 < (int)unaff_SI) break;
        uVar10 = FUN_4551_0370(DAT_5b41_0a3a);
        ((undefined2 *)&DAT_5b41_0987)[(int)unaff_SI] = uVar10;
        uVar8 = FUN_4551_0370();
      }
      iVar9 = (uint)(DAT_5b41_0989 <= *(int *)((int)param_1 + 0xa8)) +
              (uint)(DAT_5b41_098b <= *(int *)((int)param_1 + 0xa8));
      *(undefined2 *)((int)param_1 + 0x82) = *(undefined2 *)(iVar9 * 2 + 0x3bf2);
      *(undefined2 *)((int)param_1 + 0x98) =
           *(undefined2 *)
            (*(int *)(*(int *)(*(int *)((int)param_1 + 8) * 2 + 0x302) + 0x46) + iVar9 * 2);
      uVar8 = FUN_28eb_3670((int)param_1,param_1._2_2_);
      return uVar8;
    }
    iVar9 = (int)(char)uVar8 * (int)(char)uVar7;
    cVar3 = (char)iVar9;
    if (cVar3 == iVar9) {
      *unaff_SI = *unaff_SI + cVar3;
      FUN_549b_007a(0x3000,(int)param_1,param_1._2_2_);
      FUN_28eb_3328((int)param_1,param_1._2_2_);
      uVar8 = *(uint *)((int)param_1 + 0x10);
      if ((int)((undefined2 *)&DAT_5b41_098d)[(int)unaff_SI] <= (int)uVar8) {
        uVar8 = FUN_553b_00b6(0x28eb,(int)param_1,param_1._2_2_,
                              *(undefined2 *)((int)unaff_SI * 8 + 0x3bf8),
                              *(undefined2 *)((int)unaff_SI * 8 + 0x3bfa),
                              *(undefined2 *)((int)unaff_SI * 8 + 0x3bfc));
      }
      return uVar8;
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 3:
    unaff_SI[3] = unaff_SI[3] + (char)(in_DX >> 8);
    *(undefined2 *)((int)param_1 + 0x98) =
         *(undefined2 *)
          ((uint)((*(byte *)((int)param_1 + 0xc) & 0x10) != 0) * 2 + *(int *)(iRam00055816 + 0x46));
    uVar8 = FUN_28eb_3670();
    return uVar8;
  }
switchD_3000_8798_caseD_0:
  bVar2 = (byte)uVar6 - 0x1b;
  bVar13 = 0x1a < (byte)uVar6 || CARRY1(bVar2,bVar14);
  cVar3 = bVar2 + bVar14;
  uVar5 = CONCAT11((char)(uVar6 >> 8),cVar3);
  bVar14 = cVar3 == '\0';
  pcVar12 = unaff_SI;
  do {
    in(0xe7);
    in(0xd0);
    uVar5 = uVar5 & 0xff00;
LAB_2fc8_0a4b:
    in(0xb9);
    in(0xa2);
    uVar6 = uVar5 & 0xff00;
    uVar5 = in_DX;
LAB_2fc8_0a4f:
    in(0x8c);
    in(0x75);
    in(0x5e);
    in(0x48);
    in(0x31);
    in(0x1a);
    in(4);
    uVar4 = in(0xed);
    uVar6 = CONCAT11((char)(uVar6 >> 8),uVar4);
    in_DX = uVar5;
LAB_2fc8_0a5f:
    uVar5 = in_DX;
    in_DX = uVar5;
    if (in_CX == 0) {
      bVar14 = (uVar8 & 0x40) != 0;
      bVar13 = (uVar8 & 1) != 0;
    }
    else {
      unaff_SI = pcVar12;
      if (in_CX != 0) {
        iVar9 = 0;
        if (in_CX != 0) {
          if (in_CX == 0) {
            func_0x0003eebc();
            func_0x0003ee7c();
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          if (in_CX == 0) {
LAB_2fc8_0ae7:
            ffree(in_ST3);
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          if (in_CX == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          do {
            if (in_CX == 0) {
              ffree(in_ST6);
              Var1 = to_bcd(in_ST1);
              *(unkbyte10 *)(pcVar12 + uVar7 + 0x9adf) = Var1;
              in_ST0 = (longdouble)*(int *)(pcVar12 + 0x6fdf);
LAB_2fc8_0abf_3:
              func_0x000782cf(0x3000);
              *(int *)(uVar7 + unaff_DI + -0x21) = (int)ROUND(in_ST0);
              halt_baddata();
            }
            if (in_CX == 0) {
              in_DX = CONCAT11(0xe0,(char)uVar5);
              uVar5 = (uint)bRam0005dfa0;
              in_CX = 0;
              goto code_r0x0003072d;
            }
            in_DX = uVar6;
            if (in_CX == 0) goto code_r0x00030715;
            if (in_CX == 0) goto LAB_2fc8_0a7f;
            if (in_CX != 0) {
              in_CX = in_CX + -1;
              iVar11 = 0;
              in_DX = uVar5;
              if (in_CX == 0) goto LAB_2fc8_0a77;
              uVar6 = uVar6 - 1;
              bVar14 = uVar6 == 0;
              goto LAB_2fc8_0a4f;
            }
          } while( true );
        }
LAB_2fc8_0a0f:
        out(0x6a,uVar6);
        out(0x53,uVar6);
        out(0x3c,uVar6);
        out(0x25,uVar6);
        out(0xe,uVar6);
LAB_2fc8_0a19:
        out(0xf7,uVar6);
        uVar4 = (undefined1)uVar6;
        out(0xdf,uVar4);
        out(200,uVar4);
        out(0xb1,uVar4);
        out(0x9a,uVar4);
        in_CX = iVar9;
      }
      out(0x83,(char)uVar6);
      out(0x6c,(char)uVar6);
LAB_2fc8_0a27:
      uVar4 = (undefined1)uVar6;
      out(0x55,uVar4);
      out(0x3e,uVar4);
      out(0x27,uVar4);
      out(0x10,uVar4);
      out(0xf9,uVar4);
      in(0xe2);
      in(0xcb);
      in(0xb4);
      pcVar12 = unaff_SI;
    }
LAB_2fc8_0a37:
    in(0x9d);
    in(0x86);
    in(0x70);
    in(0x59);
    in(0x42);
    in(0x2b);
    in(0x14);
    uVar5 = in(0xfd);
  } while( true );
code_r0x00030715:
  if (bVar14) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar9 = -3;
  while( true ) {
    if (iVar9 != 1 && bVar14) {
      return uVar5;
    }
    if (iVar9 != 2 && bVar14) goto LAB_2fc8_0abf_3;
    in_CX = iVar9 + -3;
    if (in_CX != 0 && bVar14) goto LAB_2fc8_0aad_1;
    iVar11 = iVar9 + -4;
    if (iVar11 == 0 || !bVar14) break;
    unaff_DI = unaff_DI + -1;
    bVar14 = unaff_DI == 0;
    iVar9 = iVar11;
  }
  if (iVar11 == 1 || bVar14) {
    if (iVar11 != 2 && !bVar14) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    in_CX = iVar9 + -7;
    uVar6 = uVar5;
    if (in_CX == 0 || bVar14) {
      in_CX = iVar9 + -8;
      if (in_CX == 0 || bVar14) {
        in_CX = iVar9 + -9;
        if (in_CX == 0 || bVar14) goto code_r0x0003072d;
        goto LAB_2fc8_0a37;
      }
      goto LAB_2fc8_0a4b;
    }
    goto LAB_2fc8_0a5f;
  }
  bVar13 = uVar5 < 0x17e2;
  uVar6 = uVar5 + 0xe81e;
  bVar14 = uVar6 == 0;
  if (iVar11 != 2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar11 = -1;
  unaff_SI = pcVar12;
LAB_2fc8_0a77:
  in_CX = iVar11 + -1;
  if (in_CX == 0) {
    in_CX = iVar11 + -2;
    if (in_CX == 0) {
      iVar9 = iVar11 + -3;
      if (iVar9 == 0) {
        iVar9 = iVar11 + -4;
        if (iVar9 == 0) {
LAB_2fc8_0a7f:
          *(double *)(unaff_SI + uVar7 + 0x82dd) = (double)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        out(0xdf,uVar6);
        out(199,uVar6);
        out(0xb0,uVar6);
        out(0x99,uVar6);
        out(0x82,uVar6);
        goto LAB_2fc8_0a0f;
      }
      goto LAB_2fc8_0a19;
    }
    cVar3 = (char)(in_DX >> 8) + (char)(uVar6 >> 8) + bVar13;
    in_DX = CONCAT11(cVar3,(char)in_DX);
    bVar14 = cVar3 == '\0';
    bVar13 = true;
    goto LAB_2fc8_0a27;
  }
  bVar14 = false;
  goto switchD_3000_8798_caseD_0;
code_r0x0003072d:
  if (in_CX != 1 && !bVar14) {
    *(long *)(pcVar12 + 0x78db) = (long)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  in_CX = in_CX + -2;
  if (in_CX != 0 && !bVar14) {
    halt_baddata();
  }
  do {
    if (in_CX != 1 && !bVar14) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (in_CX != 2 && !bVar14) goto LAB_2fc8_0ae7;
    if (in_CX != 3 && !bVar14) {
      return uVar5;
    }
    if (in_CX != 4 && !bVar14) goto LAB_2fc8_0abf_3;
    in_CX = in_CX + -5;
    if (in_CX == 0 || bVar14) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar5 = CONCAT11((char)uVar5,(char)uVar5);
LAB_2fc8_0aad_1:
  } while (!bVar14);
  unaff_SI = (char *)0xa8e1;
  pcVar12 = (char *)0xa8e1;
  in_CX = in_CX + -1;
  uVar6 = uVar5;
  if (in_CX != 0) goto LAB_2fc8_0a27;
  goto code_r0x00030715;
}

