// TIM2.EXE: caseD_8003 @ file 0x036247 Ghidra 0x31047
// Subsystem: misc | Size: 72 bytes


undefined4 switchD_3000:c154::caseD_8003(void)

{
  uint uVar1;
  int in_CX;
  int in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int iVar2;
  int unaff_DI;
  int iVar3;
  undefined2 unaff_SS;
  
  iVar2 = unaff_SI + unaff_BP * 4;
  iVar3 = unaff_DI + unaff_BP * 8 + iVar2 * 4;
  *(int *)((char *)s_c__config_sys_554c_36d6 + 6 + unaff_BP * 4 + iVar2 + iVar3 * 3) =
       *(int *)((char *)s_c__config_sys_554c_36d6 + 6 + unaff_BP * 4 + iVar2 + iVar3 * 3) +
       in_CX + unaff_BP + iVar2 * 2 + iVar3;
  uVar1 = *(int *)(in_BX + unaff_BP + iVar2 * 2 + iVar3 + 4) + 0xc000U >> 4;
  if ((uVar1 & 0x800) != 0) {
    uVar1 = 0x1000 - uVar1;
  }
  return CONCAT22(in_DX + unaff_BP * 2 + iVar2 + iVar3 * 2,*(undefined2 *)(uVar1 * 2 + 0xe));
}

