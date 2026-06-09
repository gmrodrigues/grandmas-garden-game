// TIM2.EXE: FUN_49fc_044a @ file 0x04F60A Ghidra 0x4A40A
// Subsystem: misc | Size: 63 bytes


undefined2 __cdecl16far FUN_49fc_044a(undefined2 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 local_52 [80];
  
  if (param_2 != 0 || param_3 != 0) {
    iVar1 = FUN_1000_4906(param_1,local_52,0x50);
    if (iVar1 != 0) {
      FUN_4340_0a29(param_2,param_3,local_52);
      return 1;
    }
  }
  return 0;
}

