// TIM2.EXE: FUN_4bdc_049f @ file 0x05145F Ghidra 0x4C25F
// Subsystem: misc | Size: 37 bytes


undefined2 __cdecl16far FUN_4bdc_049f(void)

{
  undefined2 uVar1;
  undefined2 in_CX;
  undefined2 unaff_BP;
  
  uVar1 = (*pcRam000556ad)(0x4bdc);
  uRam00040200 = (undefined1)in_CX;
  uRam00040201 = (undefined1)((uint)in_CX >> 8);
  (*pcRam000556ad)(0x4000,unaff_BP);
  return uVar1;
}

