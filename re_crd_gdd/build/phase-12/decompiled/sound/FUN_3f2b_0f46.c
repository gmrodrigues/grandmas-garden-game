// TIM2.EXE: FUN_3f2b_0f46 @ file 0x0453F6 Ghidra 0x401F6
// Subsystem: sound | Size: 91 bytes


void __cdecl16far FUN_3f2b_0f46(int param_1)

{
  code *pcVar1;
  char extraout_AH;
  char extraout_AH_00;
  int iVar2;
  int iVar3;
  
  if (DAT_554c_3d56 != '\0') {
    if (param_1 == 0) {
      iVar2 = 100;
      iVar3 = 0;
      do {
        if (*(int *)((int)(undefined2 *)&DAT_554c_3d7c + iVar3) != 0) {
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH_00 != '\0') {
            return;
          }
          *(undefined2 *)((int)(undefined2 *)&DAT_554c_3d7c + iVar3) = 0;
          DAT_554c_3d7a = DAT_554c_3d7a + -1;
        }
        iVar3 = iVar3 + 2;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    else {
      iVar2 = 100;
      iVar3 = 0;
      do {
        if (*(int *)((int)(undefined2 *)&DAT_554c_3d7c + iVar3) == param_1) {
          pcVar1 = (code *)swi(0x67);
          (*pcVar1)();
          if (extraout_AH != '\0') {
            return;
          }
          *(undefined2 *)((int)(undefined2 *)&DAT_554c_3d7c + iVar3) = 0;
          DAT_554c_3d7a = DAT_554c_3d7a + -1;
          return;
        }
        iVar3 = iVar3 + 2;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}

