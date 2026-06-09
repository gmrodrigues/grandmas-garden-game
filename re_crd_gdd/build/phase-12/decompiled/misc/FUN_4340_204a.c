// TIM2.EXE: FUN_4340_204a @ file 0x04A64A Ghidra 0x4544A
// Subsystem: misc | Size: 54 bytes


undefined2 __cdecl16far FUN_4340_204a(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined2 local_4;
  
  FUN_4340_08dd(*(undefined2 *)((int)param_1 + 2));
  iVar1 = FUN_1a9e_5320(param_2,&local_4,0);
  if (iVar1 != 0) {
    return local_4;
  }
  return 0;
}

