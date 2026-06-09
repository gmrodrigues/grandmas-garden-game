// TIM2.EXE: FUN_1000_1cde @ file 0x016EDE Ghidra 0x11CDE
// Subsystem: utility | Size: 73 bytes


undefined2 FUN_1000_1cde(int *param_1,undefined2 param_2)

{
  int iVar1;
  undefined1 local_4 [2];
  
  do {
    if (*param_1 == -1) {
      iVar1 = 2;
    }
    else {
      iVar1 = 1;
    }
    *param_1 = *param_1 + iVar1;
    param_2 = FUN_1000_1c97(*param_1,0,param_2);
    iVar1 = FUN_1000_16d0(param_2,local_4);
  } while (iVar1 == 0);
  return param_2;
}

