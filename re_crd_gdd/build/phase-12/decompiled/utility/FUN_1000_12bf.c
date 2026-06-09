// TIM2.EXE: FUN_1000_12bf @ file 0x0164BF Ghidra 0x112BF
// Subsystem: utility | Size: 77 bytes


int __cdecl16far FUN_1000_12bf(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000_2af6(param_1,param_2);
  if (-DAT_554c_02ea - 1U < (uint)(param_2 * param_1 + iVar1)) {
    FUN_1000_3157(iVar1);
    iVar1 = 0;
  }
  return iVar1;
}

