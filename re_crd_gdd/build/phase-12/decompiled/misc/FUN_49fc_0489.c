// TIM2.EXE: FUN_49fc_0489 @ file 0x04F649 Ghidra 0x4A449
// Subsystem: misc | Size: 56 bytes


bool __cdecl16far FUN_49fc_0489(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_52 [80];
  
  if (param_1 == 0 && param_2 == 0) {
    return false;
  }
  FUN_4340_0a29(local_52);
  iVar1 = FUN_1000_2036(local_52);
  return iVar1 == 0;
}

