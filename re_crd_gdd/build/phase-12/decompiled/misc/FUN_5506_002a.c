// TIM2.EXE: FUN_5506_002a @ file 0x05A28A Ghidra 0x5508A
// Subsystem: misc | Size: 50 bytes


/* WARNING: Control flow encountered bad instruction data */

void FUN_5506_002a(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  byte bVar5;
  char cVar6;
  int in_CX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int iVar7;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined1 in_AF;
  undefined4 uVar8;
  
  pcVar4 = (code *)swi(0x3f);
  cVar6 = (*pcVar4)();
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar6;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar6;
  pcVar4 = (code *)swi(0x3f);
  uVar8 = (*pcVar4)();
  cVar6 = (char)uVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar6;
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) >> 1;
  puVar1 = (uint *)(in_BX + unaff_SI);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + (uint)uVar8;
  bVar5 = ((byte)in_CX & 0x1f) % 0x11;
  uVar3 = *(uint *)(unaff_BP + unaff_DI);
  *(uint *)(unaff_BP + unaff_DI) =
       uVar3 << bVar5 | (uint)(CONCAT12(CARRY2(uVar2,(uint)uVar8),uVar3) >> 0x11 - bVar5);
  iVar7 = unaff_SI + 1;
  *(int *)(in_BX + unaff_DI) = *(int *)(in_BX + unaff_DI) + in_CX;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(char *)(in_BX + iVar7) = *(char *)(in_BX + iVar7) + cVar6;
  *(uint *)(unaff_BP + unaff_DI) = *(uint *)(unaff_BP + unaff_DI) ^ (uint)((ulong)uVar8 >> 0x10);
  uVar2 = *(uint *)(unaff_BP + iVar7);
  *(uint *)(unaff_BP + iVar7) = uVar2 | (uint)(CONCAT12(in_AF,uVar2) >> 0x11);
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

