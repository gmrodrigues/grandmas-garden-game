// TIM2.EXE: FUN_4340_08ad @ file 0x048EAD Ghidra 0x43CAD
// Subsystem: misc | Size: 48 bytes


void __cdecl16far FUN_4340_08ad(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_3f2b_09ca(param_1,0xffff);
  if (iVar1 == 0) {
    if (param_1 == DAT_5b41_1ba6) {
      DAT_5b41_1ba6 = 0;
    }
    FUN_3f2b_042f(param_1,1);
  }
  return;
}

