// TIM2.EXE: FUN_3f2b_1074 @ file 0x045524 Ghidra 0x40324
// Subsystem: sound | Size: 114 bytes


uint __cdecl16far FUN_3f2b_1074(int param_1,uint param_2,int param_3)

{
  code *pcVar1;
  char extraout_AH;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((DAT_554c_3d56 != '\0') && (param_1 != 0)) {
    iVar2 = 100;
    iVar4 = 0;
    do {
      if (param_1 == *(int *)((int)(undefined2 *)&DAT_554c_3d7c + iVar4)) {
        uVar3 = (param_3 << 1 | (uint)((int)param_2 < 0)) << 1 | (uint)((int)(param_2 << 1) < 0);
        iVar2 = 4;
        goto LAB_3f2b_10ad;
      }
      iVar4 = iVar4 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
  while( true ) {
    if (extraout_AH != '\0') {
      return 0;
    }
    uVar3 = uVar3 + 1;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) break;
LAB_3f2b_10ad:
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH == -0x76) break;
  }
  DAT_554c_3e46 = (uVar3 - 4) + iVar2;
  DAT_554c_3d78 = param_1;
  DAT_554c_3d57 = 1;
  return param_2 & 0x3fff;
}

