// TIM2.EXE: FUN_4551_0177 @ file 0x04A887 Ghidra 0x45687
// Subsystem: misc | Size: 101 bytes


void __cdecl16far FUN_4551_0177(undefined2 param_1)

{
  int iVar1;
  int local_82 [64];
  
  iVar1 = FUN_3f2b_09ca(param_1,0xffff);
  if (iVar1 == 0) {
    iVar1 = FUN_4551_0b02(param_1,local_82);
    if (iVar1 != 0) {
      for (iVar1 = 0; iVar1 < 0x40; iVar1 = iVar1 + 1) {
        if (local_82[iVar1] != 0) {
          FUN_3f2b_09ca(local_82[iVar1],0xffff);
        }
      }
    }
    FUN_3f2b_042f(param_1,1);
  }
  return;
}

