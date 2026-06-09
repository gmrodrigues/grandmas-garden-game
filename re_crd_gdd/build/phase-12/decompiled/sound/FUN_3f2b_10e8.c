// TIM2.EXE: FUN_3f2b_10e8 @ file 0x045598 Ghidra 0x40398
// Subsystem: sound | Size: 111 bytes


uint __cdecl16far FUN_3f2b_10e8(int param_1,uint param_2)

{
  code *pcVar1;
  char extraout_AH;
  int iVar2;
  int iVar3;
  
  if ((DAT_554c_3d56 != '\0') && (param_1 != 0)) {
    iVar2 = 100;
    iVar3 = 0;
    do {
      if (param_1 == *(int *)((int)(undefined2 *)&DAT_554c_3d7c + iVar3)) {
        iVar2 = 2;
        goto LAB_3f2b_1121;
      }
      iVar3 = iVar3 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
  while( true ) {
    if (extraout_AH != '\0') {
      return 0;
    }
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) break;
LAB_3f2b_1121:
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH == -0x76) break;
  }
  DAT_554c_3d78 = param_1;
  DAT_554c_3d57 = 1;
  return param_2 & 0x3fff;
}

