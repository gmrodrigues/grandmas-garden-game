// TIM2.EXE: FUN_1000_127a @ file 0x01647A Ghidra 0x1127A
// Subsystem: utility | Size: 69 bytes


int __cdecl16far FUN_1000_127a(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1000_3226(param_1);
  if (-DAT_554c_02ea - 1U < (uint)(iVar1 + param_1)) {
    FUN_1000_3157(iVar1);
    iVar1 = 0;
  }
  return iVar1;
}

