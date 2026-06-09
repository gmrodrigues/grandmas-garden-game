// TIM2.EXE: FUN_311b_0c10 @ file 0x036FC0 Ghidra 0x31DC0
// Subsystem: misc | Size: 78 bytes


/* WARNING: Control flow encountered bad instruction data */

undefined2 __cdecl16far FUN_311b_0c10(undefined4 param_1)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  int in_CX;
  char cVar5;
  char cVar6;
  int in_DX;
  char cVar9;
  char *pcVar7;
  int iVar8;
  undefined1 *puVar10;
  char *unaff_SI;
  int unaff_DI;
  undefined2 uVar11;
  undefined2 unaff_SS;
  undefined1 auStack_c [2];
  int local_6;
  
  puVar10 = &stack0xfffe;
  uVar11 = (undefined2)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  uVar3 = *(int *)(iVar8 + 0xc) + 0xb1df;
  if (uVar3 < 5) {
    pcVar7 = (char *)(uVar3 * 2);
    switch(uVar3) {
    default:
      if (SCARRY2(uVar3,uVar3) == (int)pcVar7 < 0) {
        iVar8 = *(int *)(unaff_DI + 0x2b);
        bVar4 = (byte)((uint)in_CX >> 8) ^ (&stack0xfffe)[unaff_DI];
        (&stack0xfffe)[unaff_DI] = (&stack0xfffe)[unaff_DI] & bVar4;
        uVar3 = uVar3 - iVar8 | 0xfa2b;
        cVar2 = (char)uVar3;
        cVar6 = bVar4 - cVar2;
        cVar5 = (char)in_DX - cVar6;
        in_DX = CONCAT11((char)((uint)in_DX >> 8) - (pcVar7 + (int)unaff_SI)[-0x62d6],cVar5);
        cVar9 = (char)((uint)pcVar7 >> 8) - *pcVar7;
        in_CX = CONCAT11(cVar6 - *unaff_SI,(char)in_CX - (&stack0x7728)[(int)unaff_SI]);
        pcVar7 = (char *)CONCAT11(cVar9,(char)pcVar7 -
                                        *(char *)(CONCAT11(cVar9,(char)pcVar7) + unaff_DI));
        uVar3 = CONCAT11((char)(uVar3 >> 8) - *(char *)(unaff_DI + 0x2a),
                         (cVar2 - cVar5) - DAT_6000_47ea) - (int)auStack_c;
      }
      puVar10 = &stack0xfffe + -in_CX;
      *(int *)(puVar10 + (int)unaff_SI + -0x58d7) =
           *(int *)(puVar10 + (int)unaff_SI + -0x58d7) - unaff_DI;
      *(int *)(unaff_SI + -0x7ed7) = *(int *)(unaff_SI + -0x7ed7) - in_DX;
      *(int *)(&stack0x0027 + -in_CX) = *(int *)(&stack0x0027 + -in_CX) - (int)puVar10;
      *(uint *)(pcVar7 + 0x29) = *(int *)(pcVar7 + 0x29) - uVar3;
      in_DX = local_6;
switchD_3000_1dd9_caseD_2:
      *(uint *)(pcVar7 + unaff_DI) = *(uint *)(pcVar7 + unaff_DI) & (uint)puVar10;
      cVar6 = (char)in_DX - (char)unaff_DI;
      cVar2 = (char)(uVar3 >> 8);
      iVar8 = CONCAT11((char)((uint)pcVar7 >> 8) - cVar2,(char)pcVar7);
      *(char *)(unaff_DI + -0x66d8) = *(char *)(unaff_DI + -0x66d8) - (char)((uint)in_CX >> 8);
      puVar10[0x7228] = puVar10[0x7228];
      pcVar1 = (char *)(iVar8 + 0x28);
      *pcVar1 = *pcVar1 - (char)pcVar7;
      iVar8 = iVar8 + -1;
      unaff_SI[iVar8] = unaff_SI[iVar8] - (char)((uint)iVar8 >> 8);
      *unaff_SI = *unaff_SI - (cVar2 - cVar6);
      *(char *)(iVar8 + unaff_DI) = *(char *)(iVar8 + unaff_DI) - cVar6;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 2:
      goto switchD_3000_1dd9_caseD_2;
    case 3:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 4:
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  if (*(int *)(iVar8 + 0x2e) != in_CX) {
    *(int *)(iVar8 + 0x2e) = in_CX;
    *(undefined2 *)(iVar8 + 0x26) = 2;
  }
  return 0;
}

