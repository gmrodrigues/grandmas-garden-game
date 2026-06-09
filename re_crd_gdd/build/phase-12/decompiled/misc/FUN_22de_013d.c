// TIM2.EXE: FUN_22de_013d @ file 0x02811D Ghidra 0x22F1D
// Subsystem: misc | Size: 73 bytes


int __cdecl16far FUN_22de_013d(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  int local_6;
  int local_4;
  
  local_8 = 0;
  iVar2 = 0;
  iVar3 = 0;
  while( true ) {
    iVar1 = FUN_1000_9ada(&local_8);
    if (iVar1 != 2) break;
    iVar3 = local_8 + local_6;
    if (local_4 == 0) {
      iVar2 = iVar2 + local_6 + -4;
    }
  }
  return iVar2 + (-iVar3 - DAT_554c_02ea);
}

