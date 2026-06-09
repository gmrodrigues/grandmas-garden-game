// TIM2.EXE: FUN_1a9e_29f2 @ file 0x0225D2 Ghidra 0x1D3D2
// Subsystem: level | Size: 76 bytes


void __cdecl16near FUN_1a9e_29f2(void)

{
  int *piVar1;
  undefined2 *puVar2;
  int unaff_BP;
  undefined2 *unaff_SI;
  int *unaff_DI;
  
  if (DAT_554c_49a8 == '\0') {
    do {
      piVar1 = unaff_DI;
      puVar2 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      unaff_DI = unaff_DI + 1;
      func_0x00010102(0x1a9e,*unaff_SI,*unaff_DI,*puVar2,*piVar1);
      unaff_BP = unaff_BP + -1;
    } while (unaff_BP != 0);
    return;
  }
  DAT_554c_42c8 = DAT_554c_42c8 >> 1;
  DAT_554c_42ca = DAT_554c_42ca >> 1;
  do {
    piVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    puVar2 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    func_0x00010102(0x1a9e,*unaff_SI,*unaff_DI >> 1,*puVar2,*piVar1 >> 1);
    unaff_BP = unaff_BP + -1;
  } while (unaff_BP != 0);
  DAT_554c_42c8 = DAT_554c_42c8 << 1;
  DAT_554c_42ca = DAT_554c_42ca << 1;
  return;
}

