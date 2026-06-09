// TIM2.EXE: FUN_406b_0d37 @ file 0x0465E7 Ghidra 0x413E7
// Subsystem: sound | Size: 205 bytes


void __cdecl16far FUN_406b_0d37(uint param_1)

{
  int iVar1;
  
  if ((((param_1 < DAT_53bd_003a) && (DAT_53bd_0004 != 0xfffe)) &&
      (*(int *)(*(int *)(param_1 * 2 + DAT_53bd_0038) + 6) ==
       *(int *)(*(int *)(DAT_53bd_0004 * 2 + DAT_53bd_0038) + 6))) &&
     (*(int *)(*(int *)(param_1 * 2 + DAT_53bd_0038) + 8) ==
      *(int *)(*(int *)(DAT_53bd_0004 * 2 + DAT_53bd_0038) + 8))) {
    DAT_53bd_0004 = param_1;
    DAT_53bd_0006 = param_1;
    DAT_53bd_0056 = 1;
    iVar1 = DAT_554c_49ac;
    if (DAT_5b41_1b96 == 0) {
      iVar1 = 0;
    }
    FUN_1a9e_5a40(DAT_5b41_1b7c,iVar1 + DAT_5b41_1b7e);
    DAT_53bd_0056 = 0;
  }
  return;
}

