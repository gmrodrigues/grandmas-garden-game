// TIM2.EXE: FUN_1000_228c @ file 0x01748C Ghidra 0x1228C
// Subsystem: utility | Size: 48 bytes


void __cdecl16near FUN_1000_228c(void)

{
  int iVar1;
  int unaff_BP;
  int unaff_DI;
  int iVar2;
  undefined2 unaff_SS;
  
  iVar2 = unaff_DI - (unaff_BP + -0x96);
  iVar1 = (*(code *)*(undefined2 *)(unaff_BP + 10))
                    (*(undefined2 *)(unaff_BP + 8),iVar2,unaff_BP + -0x96);
  if (iVar1 == 0) {
    *(undefined2 *)(unaff_BP + -0x16) = 1;
  }
  *(undefined2 *)(unaff_BP + -0x14) = 0x50;
  *(int *)(unaff_BP + -0x12) = *(int *)(unaff_BP + -0x12) + iVar2;
  return;
}

