// TIM2.EXE: FUN_1000_0624 @ file 0x015824 Ghidra 0x10624
// Subsystem: utility | Size: 173 bytes


void __cdecl16far FUN_1000_0624(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_BP;
  byte *unaff_SI;
  int iVar4;
  undefined2 unaff_SS;
  long lVar5;
  
  do {
    if ((0x60 < *unaff_SI) && (*unaff_SI < 0x7b)) {
      *unaff_SI = *unaff_SI ^ 0x20;
    }
    *(int *)(unaff_BP + -8) =
         *(int *)(unaff_BP + -8) + (uint)*unaff_SI * (uint)*(byte *)*(undefined2 *)(unaff_BP + -2);
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
    *(uint *)(unaff_BP + -10) = *(uint *)(unaff_BP + -10) ^ (uint)*unaff_SI;
    if ((*unaff_SI == 0x5c) || (*unaff_SI == 0x3a)) {
      *(undefined2 *)(unaff_BP + -10) = 0;
      *(undefined2 *)(unaff_BP + -8) = 0;
      *(int *)(unaff_BP + 6) = (int)(unaff_SI + 1);
    }
    unaff_SI = unaff_SI + 1;
  } while (*unaff_SI != 0);
  FUN_1000_54f0(unaff_BP + -0x18,*(undefined2 *)(unaff_BP + 6),0xd);
  *(undefined2 *)(unaff_BP + -4) = 0;
  *(undefined2 *)(unaff_BP + -6) = 0;
  for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
    lVar5 = FUN_1000_199b();
    lVar5 = lVar5 + (ulong)*(byte *)((uint)*(byte *)(iVar4 + 0x1aa) + unaff_BP + -0x18);
    *(undefined2 *)(unaff_BP + -4) = (int)((ulong)lVar5 >> 0x10);
    *(undefined2 *)(unaff_BP + -6) = (int)lVar5;
  }
  uVar3 = *(int *)(unaff_BP + -8) * *(int *)(unaff_BP + -10);
  puVar1 = (uint *)(unaff_BP + -6);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar3;
  *(int *)(unaff_BP + -4) =
       *(int *)(unaff_BP + -4) + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
  DAT_5b41_0463 = *(undefined2 *)(unaff_BP + -4);
  DAT_5b41_0461 = *(undefined2 *)(unaff_BP + -6);
  return;
}

