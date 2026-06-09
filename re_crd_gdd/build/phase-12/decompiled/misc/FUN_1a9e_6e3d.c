// TIM2.EXE: FUN_1a9e_6e3d @ file 0x026A1D Ghidra 0x2181D
// Subsystem: misc | Size: 54 bytes


undefined2 __cdecl16far FUN_1a9e_6e3d(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = FUN_1a9e_6886(param_1);
    if (iVar1 != 0) {
      return *(undefined2 *)(iVar1 + 0x3f);
    }
  }
  return 0xffff;
}

