// TIM2.EXE: FUN_4340_07f3 @ file 0x048DF3 Ghidra 0x43BF3
// Subsystem: misc | Size: 86 bytes


int __cdecl16far FUN_4340_07f3(uint param_1)

{
  int iVar1;
  int local_6;
  
  local_6 = DAT_53c6_0002;
  iVar1 = DAT_53c6_0000;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*(uint *)(local_6 + 8) == param_1 / 1000) break;
    local_6 = local_6 + 0xe;
    iVar1 = iVar1 + -1;
  }
  return local_6;
}

