// TIM2.EXE: FUN_1000_0c9d @ file 0x015E9D Ghidra 0x10C9D
// Subsystem: utility | Size: 115 bytes


int __cdecl16far FUN_1000_0c9d(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 == 0) {
    iVar2 = -1;
  }
  else {
    if ((DAT_5b41_0469 == 0) || (iVar1 = FUN_1000_0abd(param_1), iVar1 == 0)) {
      iVar2 = FUN_1000_3d77(param_1);
    }
    else {
      FUN_1000_0abd(0);
      if (*(int *)(iVar1 + 0x10) != 0) {
        iVar2 = FUN_1000_3d77(*(undefined2 *)(iVar1 + 0x10));
      }
      *(undefined2 *)(iVar1 + 0xe) = 0;
      DAT_5b41_0460 = DAT_5b41_0460 + -1;
    }
    DAT_5b41_02f6 = DAT_5b41_02f6 | iVar2 == -1;
  }
  return iVar2;
}

