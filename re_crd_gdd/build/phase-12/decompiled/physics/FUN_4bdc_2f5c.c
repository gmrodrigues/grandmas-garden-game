// TIM2.EXE: FUN_4bdc_2f5c @ file 0x053F1C Ghidra 0x4ED1C
// Subsystem: physics | Size: 71 bytes


int __cdecl16far FUN_4bdc_2f5c(undefined4 param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  int in_DX;
  
  iVar1 = FUN_4bdc_2fa3((undefined2)param_1,param_1._2_2_,param_2);
  if (iVar1 != 0 || in_DX != 0) {
    *(undefined1 *)(iVar1 + 0x15e) = param_3;
    FUN_4bdc_22fd(iVar1,in_DX,1);
    return iVar1;
  }
  return 0;
}

