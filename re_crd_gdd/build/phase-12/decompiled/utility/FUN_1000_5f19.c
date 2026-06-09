// TIM2.EXE: FUN_1000_5f19 @ file 0x01B119 Ghidra 0x15F19
// Subsystem: utility | Size: 88 bytes


char * __cdecl16far FUN_1000_5f19(undefined4 param_1)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 local_6;
  
  if ((int)param_1 == 0 && param_1._2_2_ == 0) {
    pcVar2 = (char *)s_<notype>_554c_5e3a;
  }
  else {
    local_6 = (char *)CONCAT22(param_1._2_2_,(char *)((int)param_1 + *(int *)((int)param_1 + 4)));
    pcVar2 = (char *)&DAT_5b41_2a92;
    do {
      pcVar1 = local_6;
      if (pcVar2 == (char *)0x8ae1) {
        uRam0005dfa1 = 0;
        break;
      }
      *pcVar2 = *local_6;
      pcVar2 = pcVar2 + 1;
      local_6 = (char *)CONCAT22(local_6._2_2_,(char *)local_6 + 1);
    } while (*pcVar1 != '\0');
    pcVar2 = (char *)&DAT_5b41_2a92;
  }
  return pcVar2;
}

