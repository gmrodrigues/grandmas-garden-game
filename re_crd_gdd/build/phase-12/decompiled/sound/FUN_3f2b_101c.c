// TIM2.EXE: FUN_3f2b_101c @ file 0x0454CC Ghidra 0x402CC
// Subsystem: sound | Size: 86 bytes


undefined2 __cdecl16far FUN_3f2b_101c(int param_1,undefined2 param_2)

{
  code *pcVar1;
  char extraout_AH;
  int iVar2;
  int iVar3;
  
  if (DAT_554c_3d56 != '\0') {
    if (param_1 == 0) {
      return DAT_554c_3e46;
    }
    iVar2 = 100;
    iVar3 = 0;
    do {
      if (param_1 == *(int *)((int)(undefined2 *)&DAT_554c_3d7c + iVar3)) {
        iVar2 = 4;
        while( true ) {
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH == -0x76) {
            DAT_554c_3d57 = 1;
            DAT_554c_3d78 = param_1;
            DAT_554c_3e46 = param_2;
            return param_2;
          }
          if (extraout_AH != '\0') break;
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) {
            DAT_554c_3e46 = param_2;
            DAT_554c_3d78 = param_1;
            DAT_554c_3d57 = 1;
            return param_2;
          }
        }
        return 0;
      }
      iVar3 = iVar3 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}

