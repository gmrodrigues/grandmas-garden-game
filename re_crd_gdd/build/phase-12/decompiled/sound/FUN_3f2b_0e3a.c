// TIM2.EXE: FUN_3f2b_0e3a @ file 0x0452EA Ghidra 0x400EA
// Subsystem: sound | Size: 83 bytes


void __cdecl16far FUN_3f2b_0e3a(int param_1)

{
  code *pcVar1;
  char extraout_AH;
  int iVar2;
  undefined2 extraout_DX;
  int iVar3;
  
  if (DAT_554c_3d56 != '\0') {
    if (param_1 == 0) {
      return;
    }
    iVar2 = 100;
    iVar3 = 0;
    DAT_554c_3e46 = 0;
    do {
      if (param_1 == *(int *)((int)(undefined2 *)&DAT_554c_3d7c + iVar3)) {
        iVar2 = 4;
        while( true ) {
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH == -0x76) {
            DAT_554c_3d57 = 1;
            DAT_554c_3d78 = extraout_DX;
            return;
          }
          if (extraout_AH != '\0') break;
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) {
            DAT_554c_3d57 = 1;
            DAT_554c_3d78 = extraout_DX;
            return;
          }
        }
        DAT_554c_3d78 = 0;
        return;
      }
      iVar3 = iVar3 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  DAT_554c_3d78 = 0;
  return;
}

