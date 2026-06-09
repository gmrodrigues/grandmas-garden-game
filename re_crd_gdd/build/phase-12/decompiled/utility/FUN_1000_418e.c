// TIM2.EXE: FUN_1000_418e @ file 0x01938E Ghidra 0x1418E
// Subsystem: utility | Size: 35 bytes


undefined2 __cdecl16far FUN_1000_418e(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = FUN_1000_414d();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_1000_4099(0,param_2,param_1,iVar1);
  }
  return uVar2;
}

