// TIM2.EXE: FUN_1000_41cb @ file 0x0193CB Ghidra 0x141CB
// Subsystem: utility | Size: 72 bytes


uint __cdecl16far FUN_1000_41cb(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (iVar1 = FUN_1000_54d4(param_1), iVar1 != 0)) {
    iVar2 = FUN_1000_4ed6(param_2,iVar1,param_1);
    if (iVar2 != 0) {
      return (uint)*(byte *)(param_1 + iVar1 + -1);
    }
    return 0xffff;
  }
  return 0;
}

