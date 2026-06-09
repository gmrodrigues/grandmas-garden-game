// TIM2.EXE: FUN_3e34_0237 @ file 0x043777 Ghidra 0x3E577
// Subsystem: sound | Size: 32 bytes


/* WARNING: Instruction at (ram,0x0003194e) overlaps instruction at (ram,0x0003194d)
    */
/* WARNING: Control flow encountered bad instruction data */

void __cdecl16far FUN_3e34_0237(void)

{
  char *pcVar1;
  undefined2 *puVar2;
  uint *puVar3;
  undefined2 in_DX;
  int iVar4;
  int unaff_SI;
  int unaff_DI;
  int iVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 unaff_SS;
  bool bVar8;
  longdouble in_ST0;
  uint uStack_16;
  uint uStack_14;
  int iStack_12;
  int iStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  int iStack_a;
  uint *puStack_8;
  undefined4 in_stack_0000fffa;
  
  uStack_16 = (int)DAT_554c_42dd - 2;
  if (0xd < uStack_16) {
    DAT_5b41_1ad2 = 1;
    return;
  }
  iVar4 = uStack_16 * 2;
  bVar8 = iVar4 == 0;
  uVar7 = 0x3000;
  switch(uStack_16) {
  case 0:
    goto switchD_3000_e58a_caseD_0;
  case 1:
    goto code_r0x00031a4f;
  case 2:
    *(char *)(unaff_SI + 5) = *(char *)(unaff_SI + 5) + (char)((uint)in_DX >> 8);
    goto code_r0x00031a37;
  case 3:
    iVar5 = *(int *)(iVar4 + unaff_SI + -0x7d) * -0x3c;
    uVar6 = CONCAT11((byte)((uint)iVar5 >> 8) |
                     *(byte *)((int)(undefined2 *)&DAT_554c_42d2 + iVar4 + unaff_DI),(char)iVar5);
    goto code_r0x00031a27;
  case 4:
    unaff_SI = unaff_SI + 1;
    *(char *)(unaff_DI + -0x51) = *(char *)(unaff_DI + -0x51) + '\x01';
    break;
  case 5:
    while( true ) {
      uVar6 = (undefined2)((ulong)in_stack_0000fffa >> 0x10);
      iVar4 = *(int *)((int)in_stack_0000fffa + 8);
      puVar3 = (uint *)*(int *)((int)in_stack_0000fffa + 10);
LAB_311b_084c:
      in_stack_0000fffa = CONCAT22(puVar3,iVar4);
      if (iVar4 == 0 && puVar3 == (uint *)0x0) break;
LAB_311b_0809:
      iVar4 = *(int *)((int)in_stack_0000fffa + 0xe) * 0x12;
      if (*(int *)(iVar4 + 0xda) != 0 || *(int *)(iVar4 + 0xdc) != 0) {
code_r0x000319da:
        puVar2 = (undefined2 *)(*(int *)((int)in_stack_0000fffa + 0xe) * 0x12 + 0xda);
        in_stack_0000fffa = 0x300019ee;
        (*(code *)*puVar2)();
      }
    }
    break;
  case 6:
    if (!CARRY2(uStack_16,uStack_16) && !bVar8) goto code_r0x000319da;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 7:
    *(long *)(&stack0xfffe + unaff_SI) = (long)ROUND(in_ST0);
    goto LAB_311b_0809;
  case 8:
    goto code_r0x000319a5;
  case 9:
    goto code_r0x0003197e;
  case 10:
    while (!bVar8) {
LAB_311b_078f:
      iVar5 = (int)((ulong)in_stack_0000fffa >> 0x10);
      iVar4 = (int)in_stack_0000fffa;
      uStack_c = *(undefined2 *)(iVar4 + 10);
      uStack_e = *(undefined2 *)(iVar4 + 8);
      *(int *)(iVar4 + 10) = (int)puStack_8;
      *(int *)(iVar4 + 8) = iStack_a;
      in_stack_0000fffa = CONCAT22(uStack_c,uStack_e);
      iStack_a = iVar4;
      puStack_8 = (uint *)iVar5;
LAB_311b_07c6:
      bVar8 = (int)in_stack_0000fffa == 0 && (int)((ulong)in_stack_0000fffa >> 0x10) == 0;
    }
code_r0x0003197e:
    DAT_554c_42c8 = 0;
    DAT_554c_42ca = DAT_554c_3e4a + -1;
    DAT_554c_42c4 = 0;
    DAT_554c_42c6 = DAT_554c_49aa + -1;
    DAT_554c_42d8 = DAT_554c_42d2;
    iVar4 = iStack_a;
    puVar3 = puStack_8;
    if (iRam000557c0 == 0) goto LAB_311b_084c;
code_r0x000319a5:
    uVar7 = 0x551a;
    puStack_8 = (uint *)0x19ac;
    func_0x000551c0();
    break;
  case 0xb:
    in_stack_0000fffa = CONCAT22(unaff_SI,(int)in_stack_0000fffa);
    goto LAB_311b_078f;
  case 0xc:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  case 0xd:
    unaff_SI = unaff_SI + 1;
    pcVar1 = (char *)(CONCAT11((char)((uint)iVar4 >> 8) + (char)uStack_16,(char)iVar4) + unaff_SI);
    *pcVar1 = *pcVar1 + (char)uStack_16;
    goto LAB_311b_07c6;
  }
  uVar6 = DAT_554c_42d2;
  if (unaff_SI != 0) {
    puStack_8 = (uint *)DAT_554c_49aa;
    iStack_a = 0;
    uStack_c = 0;
    iStack_10 = 0x1a21;
    uStack_e = uVar7;
    FUN_406b_000c();
    uVar6 = DAT_554c_42d2;
  }
code_r0x00031a27:
  DAT_554c_42d8 = 0xa000;
  DAT_554c_42d6 = uVar6;
  if (DAT_5b41_1b96 != 0) {
code_r0x00031a37:
    FUN_406b_053a();
  }
  FUN_406b_0880();
code_r0x00031a4f:
  uVar7 = 0x406b;
  FUN_406b_04d8();
  DAT_554c_42d6 = DAT_554c_42d4;
  DAT_554c_42d8 = DAT_554c_42d2;
  uStack_16 = 0;
switchD_3000_e58a_caseD_0:
  iStack_12 = DAT_554c_49aa;
  iStack_10 = DAT_554c_3e4a;
  puStack_8 = &uStack_16;
  uStack_c = 0x1a80;
  uStack_14 = uStack_16;
  iStack_a = uVar7;
  FUN_2424_1e00();
  FUN_2424_0304();
  return;
}

