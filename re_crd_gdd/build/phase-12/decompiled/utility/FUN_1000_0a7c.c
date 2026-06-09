// TIM2.EXE: FUN_1000_0a7c @ file 0x015C7C Ghidra 0x10A7C
// Subsystem: utility | Size: 65 bytes


void __cdecl16far FUN_1000_0a7c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_5b41_0465 * 0x1c;
  if ((*(int *)(iVar1 + 0x6314) != param_2) || (*(int *)(iVar1 + 0x6312) != param_1)) {
    FUN_1000_43c4(*(undefined2 *)(iVar1 + 0x6310),param_1,param_2,0);
    *(int *)(iVar1 + 0x6314) = param_2;
    *(int *)(iVar1 + 0x6312) = param_1;
  }
  return;
}

