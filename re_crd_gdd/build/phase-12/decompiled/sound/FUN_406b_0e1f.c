// TIM2.EXE: FUN_406b_0e1f @ file 0x0466CF Ghidra 0x414CF
// Subsystem: sound | Size: 72 bytes


void __cdecl16far FUN_406b_0e1f(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = DAT_554c_3e4c + 1;
  bVar2 = DAT_554c_3e4c == 0;
  DAT_554c_3e4c = iVar1;
  if ((bVar2) && ((DAT_53bd_004a & 1) == 0)) {
    FUN_406b_111b(0);
  }
  DAT_554c_3e4c = DAT_554c_3e4c + -1;
  DAT_53bd_004c = 1;
  FUN_406b_0e67();
  DAT_53bd_004c = 0;
  return;
}

