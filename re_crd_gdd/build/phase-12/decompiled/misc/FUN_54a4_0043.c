// TIM2.EXE: FUN_54a4_0043 @ file 0x059C83 Ghidra 0x54A83
// Subsystem: misc | Size: 96 bytes


void __cdecl16far FUN_54a4_0043(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  undefined2 uVar6;
  byte in_CL;
  int in_BX;
  uint uVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int unaff_SI;
  undefined2 unaff_SS;
  byte in_CF;
  byte in_AF;
  undefined2 *in_stack_0000000e;
  undefined2 uStack_e;
  
  pcVar2 = (code *)swi(0x3f);
  iVar5 = (*pcVar2)();
  uVar7 = in_BX + 1;
  *(int *)(uVar7 + unaff_SI) = *(int *)(uVar7 + unaff_SI) + iVar5 + (uint)in_CF;
  pcVar2 = (code *)swi(0x3f);
  bVar3 = (*pcVar2)();
  puVar9 = (undefined2 *)TaskRegister();
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  in_AF = 9 < (bVar3 + in_AF * -6 & 0xf) | in_AF;
  iVar5 = unaff_SI + 2;
  pcVar2 = (code *)swi(0x3f);
  (*pcVar2)();
  pcVar2 = (code *)swi(0x3f);
  bVar3 = (*pcVar2)();
  puVar8 = &stack0x000e;
  in_stack_0000000e = puVar9;
  cVar4 = '\f';
  do {
    puVar9 = puVar9 + -1;
    puVar8 = puVar8 + -1;
    *puVar8 = *puVar9;
    cVar4 = cVar4 + -1;
  } while ('\0' < cVar4);
  in_AF = 9 < (bVar3 & 0xf) | in_AF;
  bVar3 = bVar3 + in_AF * -6 & 0xf;
  pbVar1 = (byte *)(uVar7 + iVar5);
  *pbVar1 = *pbVar1 << (in_CL & 7) | *pbVar1 >> 8 - (in_CL & 7);
  in_AF = 9 < bVar3 | in_AF;
  bVar3 = bVar3 + in_AF * -6 & 0xf;
  in_AF = 9 < bVar3 | in_AF;
  bVar3 = bVar3 + in_AF * -6 & 0xf;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + bVar3;
  in_AF = 9 < bVar3 | in_AF;
  bVar3 = bVar3 + in_AF * -6 & 0xf;
  *(uint *)(&stack0x0010 + unaff_SI) = *(uint *)(&stack0x0010 + unaff_SI) & uVar7;
  in_AF = 9 < bVar3 | in_AF;
  bVar3 = bVar3 + in_AF * -6 & 0xf;
  *(char *)(uVar7 + iVar5) = (*(char *)(uVar7 + iVar5) - bVar3) - in_AF;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + bVar3;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + bVar3;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + bVar3;
  pcVar2 = (code *)swi(0x3f);
  uVar6 = (*pcVar2)();
  cVar4 = (char)uVar6;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(byte *)(uVar7 + iVar5) = *(byte *)(uVar7 + iVar5) | (byte)((uint)uVar6 >> 8);
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  *(char *)(uVar7 + iVar5) = *(char *)(uVar7 + iVar5) + cVar4;
  pcVar2 = (code *)swi(0x3f);
  (*pcVar2)();
  return;
}

