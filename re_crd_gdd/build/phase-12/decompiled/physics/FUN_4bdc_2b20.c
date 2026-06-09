// TIM2.EXE: FUN_4bdc_2b20 @ file 0x053AE0 Ghidra 0x4E8E0
// Subsystem: physics | Size: 257 bytes


undefined2 __cdecl16far FUN_4bdc_2b20(undefined2 param_1,char param_2)

{
  int iVar1;
  char local_5;
  char local_4;
  char local_3;
  
  iVar1 = FUN_1a9e_0f7d(param_1,&local_5);
  if (iVar1 != 1) {
    return 0;
  }
  if (local_5 != -0x7c) {
    return 0;
  }
  iVar1 = FUN_1a9e_0f7d(param_1,&local_5);
  if (iVar1 != 1) {
    return 0;
  }
  iVar1 = FUN_1a9e_0f7d(param_1,&local_3);
  if (iVar1 == 1) {
    do {
      if (local_3 == param_2) {
        return 1;
      }
      if ((local_3 == -1) || (iVar1 = FUN_1a9e_0f7d(param_1,&local_4), iVar1 != 1)) {
        return 0;
      }
      while (local_4 != -1) {
        FUN_1a9e_109d(param_1,5,0,1);
        iVar1 = FUN_1a9e_0f7d(param_1,&local_4);
        if (iVar1 != 1) {
          return 0;
        }
      }
      iVar1 = FUN_1a9e_0f7d(param_1,&local_3);
    } while (iVar1 == 1);
    return 0;
  }
  return 0;
}

