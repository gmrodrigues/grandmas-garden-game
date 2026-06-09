// TIM2.EXE: FUN_460e_07ca @ file 0x04BAAA Ghidra 0x468AA
// Subsystem: misc | Size: 156 bytes


int __cdecl16far FUN_460e_07ca(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_DX;
  undefined1 local_206 [512];
  undefined2 local_6;
  int local_4;
  
  if (((param_1 == 0) || (param_2 == 0)) ||
     ((param_3 != 0 && ((iVar1 = FUN_1a9e_6a85(param_2,param_3,0), in_DX == -1 && (iVar1 == -1))))))
  {
    iVar1 = 0;
  }
  else {
    local_4 = FUN_42da_04d6(param_2);
    iVar1 = 0;
    do {
      while( true ) {
        if (local_4 == 0) {
          return iVar1;
        }
        local_4 = local_4 + -1;
        local_6 = FUN_42da_04d6(param_2);
        iVar2 = FUN_42da_0536(param_2,local_206);
        if (iVar2 == 0x200) {
          return iVar1;
        }
        iVar2 = FUN_460e_0290(param_1,local_6,local_206);
        if (iVar2 == 0) break;
        iVar1 = iVar1 + 1;
      }
    } while (DAT_5b41_1ad2 == 0xb);
  }
  return iVar1;
}

