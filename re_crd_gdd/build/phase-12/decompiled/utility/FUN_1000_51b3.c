// TIM2.EXE: FUN_1000_51b3 @ file 0x01A3B3 Ghidra 0x151B3
// Subsystem: utility | Size: 241 bytes


void __cdecl16far FUN_1000_51b3(undefined2 param_1,char *param_2,undefined1 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_1000_4906(0,param_3,0x50);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_1000_54d4(param_3);
  }
  while( true ) {
    param_3[iVar1] = 0;
    if (((iVar1 != 0) && (param_3[iVar1 + -1] != '\\')) && (param_3[iVar1 + -1] != '/')) {
      FUN_1000_5401(param_3,0x5e04);
    }
    FUN_1000_5401(param_3,param_1);
    iVar1 = FUN_1000_380a(param_3,0);
    if (iVar1 == 0) break;
    if (*param_2 == '\0') {
      *param_3 = 0;
      return;
    }
    iVar1 = 0;
    for (; (*param_2 != ';' && (*param_2 != '\0')); param_2 = param_2 + 1) {
      param_3[iVar1] = *param_2;
      iVar1 = iVar1 + 1;
    }
    if (*param_2 != '\0') {
      param_2 = param_2 + 1;
    }
  }
  iVar1 = FUN_1000_4526(0,param_3,0x50);
  if (iVar1 == 0) {
    return;
  }
  FUN_1000_5472(param_3,iVar1);
  FUN_1000_3157(iVar1);
  return;
}

