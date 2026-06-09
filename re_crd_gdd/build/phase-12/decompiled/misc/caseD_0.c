// TIM2.EXE: caseD_0 @ file 0x0358C4 Ghidra 0x306C4
// Subsystem: misc | Size: 193 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0003072c) overlaps instruction at (ram,0x0003072b)
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

void switchD_3000:8798::caseD_0(undefined2 *param_1)

{
  unkbyte10 Var1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  uint in_AX;
  uint uVar5;
  uint uVar6;
  int in_CX;
  int iVar7;
  int iVar8;
  uint in_DX;
  int in_BX;
  undefined1 *unaff_BP;
  int unaff_SI;
  int iVar9;
  int unaff_DI;
  byte in_CF;
  bool bVar10;
  bool bVar11;
  longdouble in_ST0;
  unkbyte10 in_ST1;
  unkbyte10 in_ST3;
  unkbyte10 in_ST6;
  uint in_stack_00000000;
  
code_r0x000306c4:
  bVar2 = (byte)in_AX - 0x1b;
  bVar10 = 0x1a < (byte)in_AX || CARRY1(bVar2,in_CF);
  cVar3 = bVar2 + in_CF;
  uVar5 = CONCAT11((char)(in_AX >> 8),cVar3);
  bVar11 = cVar3 == '\0';
  iVar9 = unaff_SI;
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
    in_AX = CONCAT11((char)(uVar6 >> 8),uVar4);
    in_DX = uVar5;
LAB_2fc8_0a5f:
    uVar5 = in_DX;
    in_DX = uVar5;
    if (in_CX == 0) {
      bVar11 = (in_stack_00000000 & 0x40) != 0;
      bVar10 = (in_stack_00000000 & 1) != 0;
    }
    else {
      unaff_SI = iVar9;
      if (in_CX != 0) {
        iVar7 = 0;
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
              *(unkbyte10 *)(in_BX + iVar9 + -0x6521) = Var1;
              in_ST0 = (longdouble)*(int *)(iVar9 + 0x6fdf);
LAB_2fc8_0abf_3:
              param_1 = (undefined2 *)&DAT_554c_2fc8;
              func_0x000782cf();
              *(int *)(in_BX + unaff_DI + -0x21) = (int)ROUND(in_ST0);
              halt_baddata();
            }
            if (in_CX == 0) {
              in_DX = CONCAT11(0xe0,(char)uVar5);
              uVar5 = (uint)bRam0005dfa0;
              in_CX = 0;
              goto code_r0x0003072d;
            }
            in_DX = in_AX;
            if (in_CX == 0) goto code_r0x00030715;
            if (in_CX == 0) goto LAB_2fc8_0a7f;
            if (in_CX != 0) {
              in_CX = in_CX + -1;
              iVar8 = 0;
              in_DX = uVar5;
              if (in_CX == 0) goto LAB_2fc8_0a77;
              uVar6 = in_AX - 1;
              bVar11 = uVar6 == 0;
              goto LAB_2fc8_0a4f;
            }
          } while( true );
        }
LAB_2fc8_0a0f:
        out(0x6a,in_AX);
        out(0x53,in_AX);
        out(0x3c,in_AX);
        out(0x25,in_AX);
        out(0xe,in_AX);
LAB_2fc8_0a19:
        out(0xf7,in_AX);
        uVar4 = (undefined1)in_AX;
        out(0xdf,uVar4);
        out(200,uVar4);
        out(0xb1,uVar4);
        out(0x9a,uVar4);
        in_CX = iVar7;
      }
      out(0x83,(char)in_AX);
      out(0x6c,(char)in_AX);
LAB_2fc8_0a27:
      uVar4 = (undefined1)in_AX;
      out(0x55,uVar4);
      out(0x3e,uVar4);
      out(0x27,uVar4);
      out(0x10,uVar4);
      out(0xf9,uVar4);
      in(0xe2);
      in(0xcb);
      in(0xb4);
      iVar9 = unaff_SI;
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
  if (bVar11) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar7 = -3;
  while( true ) {
    if (iVar7 != 1 && bVar11) {
      return;
    }
    if (iVar7 != 2 && bVar11) goto LAB_2fc8_0abf_3;
    iVar8 = iVar7 + -3;
    if (iVar8 != 0 && bVar11) goto LAB_2fc8_0aad_1;
    iVar8 = iVar7 + -4;
    if (iVar8 == 0 || !bVar11) break;
    unaff_DI = unaff_DI + -1;
    bVar11 = unaff_DI == 0;
    iVar7 = iVar8;
  }
  if (iVar8 == 1 || bVar11) {
    if (iVar8 != 2 && !bVar11) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    in_CX = iVar7 + -7;
    in_AX = uVar5;
    if (in_CX == 0 || bVar11) {
      in_CX = iVar7 + -8;
      if (in_CX == 0 || bVar11) {
        in_CX = iVar7 + -9;
        if (in_CX == 0 || bVar11) goto code_r0x0003072d;
        goto LAB_2fc8_0a37;
      }
      goto LAB_2fc8_0a4b;
    }
    goto LAB_2fc8_0a5f;
  }
  bVar10 = uVar5 < 0x17e2;
  in_AX = uVar5 + 0xe81e;
  bVar11 = in_AX == 0;
  if (iVar8 != 2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar8 = -1;
  unaff_SI = iVar9;
LAB_2fc8_0a77:
  in_CX = iVar8 + -1;
  if (in_CX == 0) {
    in_CX = iVar8 + -2;
    if (in_CX == 0) {
      iVar7 = iVar8 + -3;
      if (iVar7 == 0) {
        iVar7 = iVar8 + -4;
        if (iVar7 == 0) {
LAB_2fc8_0a7f:
          *(double *)(in_BX + unaff_SI + -0x7d23) = (double)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        out(0xdf,in_AX);
        out(199,in_AX);
        out(0xb0,in_AX);
        out(0x99,in_AX);
        out(0x82,in_AX);
        goto LAB_2fc8_0a0f;
      }
      goto LAB_2fc8_0a19;
    }
    cVar3 = (char)(in_DX >> 8) + (char)(in_AX >> 8) + bVar10;
    in_DX = CONCAT11(cVar3,(char)in_DX);
    bVar11 = cVar3 == '\0';
    bVar10 = true;
    goto LAB_2fc8_0a27;
  }
  in_CF = &param_1 < unaff_BP;
  goto code_r0x000306c4;
code_r0x0003072d:
  if (in_CX != 1 && !bVar11) {
    *(long *)((int)(undefined2 *)&DAT_5b41_198a + iVar9 + 1) = (long)in_ST0;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar8 = in_CX + -2;
  if (iVar8 != 0 && !bVar11) {
    halt_baddata();
  }
  do {
    if (iVar8 != 1 && !bVar11) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (iVar8 != 2 && !bVar11) goto LAB_2fc8_0ae7;
    if (iVar8 != 3 && !bVar11) {
      return;
    }
    if (iVar8 != 4 && !bVar11) goto LAB_2fc8_0abf_3;
    iVar8 = iVar8 + -5;
    if (iVar8 == 0 || bVar11) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar5 = CONCAT11((char)uVar5,(char)uVar5);
LAB_2fc8_0aad_1:
  } while (!bVar11);
  unaff_SI = -0x571f;
  iVar9 = -0x571f;
  in_CX = iVar8 + -1;
  in_AX = uVar5;
  if (in_CX != 0) goto LAB_2fc8_0a27;
  goto code_r0x00030715;
}

