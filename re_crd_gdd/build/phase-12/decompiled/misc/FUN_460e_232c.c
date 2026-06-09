// TIM2.EXE: FUN_460e_232c @ file 0x04D60C Ghidra 0x4840C
// Subsystem: misc | Size: 85 bytes


bool __cdecl16far FUN_460e_232c(int param_1)

{
  bool bVar1;
  int iVar2;
  int in_DX;
  
  if ((DAT_5b41_1cea == '\0') || ((param_1 != 0 && (param_1 != DAT_5b41_1ceb)))) {
    if ((DAT_5b41_1cea == '\0') && (DAT_5b41_1ceb != 0)) {
      bVar1 = DAT_5b41_1ce6 != 0 || DAT_5b41_1ce8 != 0;
    }
    else {
      bVar1 = false;
    }
  }
  else {
    iVar2 = FUN_1000_13a4();
    if ((in_DX == -1) && (iVar2 == -1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  return bVar1;
}

