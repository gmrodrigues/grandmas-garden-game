// TIM2.EXE: FUN_1000_144e @ file 0x01664E Ghidra 0x1144E
// Subsystem: utility | Size: 23 bytes


bool __cdecl16far FUN_1000_144e(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = DAT_554c_57c6 != 0x20;
  if (bVar2) {
    iVar1 = DAT_554c_57c6 * 4;
    *(undefined2 *)(iVar1 + -0x782a) = param_2;
    *(undefined2 *)(iVar1 + -0x782c) = param_1;
    DAT_554c_57c6 = DAT_554c_57c6 + 1;
  }
  return !bVar2;
}

