// TIM2.EXE: FUN_2321_0ff6 @ file 0x029406 Ghidra 0x24206
// Subsystem: misc | Size: 70 bytes


int __cdecl16far FUN_2321_0ff6(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  int in_DX;
  
  iVar1 = FUN_2321_0bd2();
  if ((iVar1 != 0 || in_DX != 0) && (iVar2 = FUN_2321_0deb(iVar1,in_DX,param_1), iVar2 != 0)) {
    return iVar1;
  }
  FUN_2321_0c23(iVar1,in_DX);
  return 0;
}

