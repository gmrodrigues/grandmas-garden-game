// TIM2.EXE: FUN_1000_1135 @ file 0x016335 Ghidra 0x11135
// Subsystem: utility | Size: 82 bytes


int __cdecl16far FUN_1000_1135(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  
  if ((DAT_5b41_0469 != 0) && (iVar1 = FUN_1000_0abd(param_2), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x10) == 0) {
      iVar1 = -1;
      goto LAB_1000_1171;
    }
    param_2 = *(undefined2 *)(iVar1 + 0x10);
  }
  iVar1 = FUN_1000_4d6f(param_1,param_2);
LAB_1000_1171:
  DAT_5b41_02f6 = DAT_5b41_02f6 | iVar1 == -1;
  return iVar1;
}

