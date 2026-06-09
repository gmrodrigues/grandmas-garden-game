// TIM2.EXE: FUN_28eb_2779 @ file 0x030829 Ghidra 0x2B629
// Subsystem: misc | Size: 69 bytes


void __cdecl16far FUN_28eb_2779(void)

{
  int in_AX;
  int in_BX;
  int unaff_BP;
  int iVar1;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  *(undefined2 *)(in_BX + in_AX + 0x68) = 0;
  *(undefined2 *)(in_BX + in_AX + 0x66) = 0;
  iVar1 = *(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -2) * 4;
  *(undefined2 *)(iVar1 + 0x60) = 0;
  *(undefined2 *)(iVar1 + 0x5e) = 0;
  iVar1 = (int)*(undefined4 *)(unaff_BP + 6);
  if ((*(byte *)(iVar1 + 0xb) & 8) == 0) {
    FUN_28eb_2ca2(iVar1,*(undefined2 *)(unaff_BP + 8));
  }
  if (unaff_DI + 1 < 2) {
    FUN_28eb_25ec();
    return;
  }
  return;
}

