// TIM2.EXE: FUN_49fc_04c1 @ file 0x04F681 Ghidra 0x4A481
// Subsystem: misc | Size: 87 bytes


bool __cdecl16far FUN_49fc_04c1(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 local_a2 [80];
  undefined1 local_52 [80];
  
  if ((param_1 != 0 || param_2 != 0) && (param_3 != 0 || param_4 != 0)) {
    FUN_4340_0a29(local_52);
    FUN_4340_0a29(local_a2);
    iVar1 = FUN_1000_516a(local_52,local_a2);
    return iVar1 == 0;
  }
  return false;
}

