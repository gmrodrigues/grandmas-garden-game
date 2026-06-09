// TIM2.EXE: FUN_1000_10d5 @ file 0x0162D5 Ghidra 0x110D5
// Subsystem: utility | Size: 96 bytes


int __cdecl16far FUN_1000_10d5(undefined2 param_1,undefined2 param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  
  if ((DAT_5b41_0469 != 0) && (iVar1 = FUN_1000_0abd(param_4), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x10) == 0) {
      iVar1 = 0;
      goto LAB_1000_111f;
    }
    param_4 = *(undefined2 *)(iVar1 + 0x10);
  }
  iVar1 = FUN_1000_4718(param_1,param_2,param_3,param_4);
LAB_1000_111f:
  DAT_5b41_02f6 = DAT_5b41_02f6 | iVar1 != param_3;
  return iVar1;
}

