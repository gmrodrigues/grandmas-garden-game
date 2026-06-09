// TIM2.EXE: FUN_1000_305a @ file 0x01825A Ghidra 0x1305A
// Subsystem: utility | Size: 67 bytes


undefined2 __cdecl16near FUN_1000_305a(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined1 in_CF;
  undefined1 in_ZF;
  
  FUN_1000_1fe5();
  if (((!(bool)in_CF) && (FUN_1000_1fe5(), (bool)in_CF || (bool)in_ZF)) &&
     (iVar1 = FUN_1000_2fcc(param_1,param_2), iVar1 != 0)) {
    return 0;
  }
  return 0xffff;
}

