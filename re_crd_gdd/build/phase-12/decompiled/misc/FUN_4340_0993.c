// TIM2.EXE: FUN_4340_0993 @ file 0x048F93 Ghidra 0x43D93
// Subsystem: misc | Size: 57 bytes


undefined2 __cdecl16far FUN_4340_0993(int param_1)

{
  int iVar1;
  
  if ((param_1 != DAT_5b41_1ba6) && (iVar1 = FUN_3f2b_0811(param_1), iVar1 != 0)) {
    FUN_1a9e_7240(iVar1);
    FUN_3f2b_0953(param_1,0);
    return 1;
  }
  return 0;
}

