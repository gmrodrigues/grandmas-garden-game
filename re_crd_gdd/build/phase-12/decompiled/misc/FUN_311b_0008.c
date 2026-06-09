// TIM2.EXE: FUN_311b_0008 @ file 0x0363B8 Ghidra 0x311B8
// Subsystem: misc | Size: 212 bytes


void __cdecl16far FUN_311b_0008(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int in_DX;
  char *pcVar4;
  
  uVar2 = DAT_554c_2f1c;
  DAT_554c_2f1c = uVar2;
  if (DAT_5b41_0d12 == 0) {
    DAT_554c_2f1c = 4000;
    if (iRam000557bc == 2) {
      pcVar4 = (char *)s_GOALHBAR_ITF_554c_2fe0;
    }
    else {
      pcVar4 = (char *)s__GOALBAR_ITF_554c_2fd3 + 1;
    }
    DAT_5b41_0d12 = FUN_4876_0009(pcVar4,0);
    DAT_554c_2f1c = uVar2;
    if (DAT_5b41_0d12 != 0) {
      if ((iRam000557bc == 1) || (iRam000557bc == 6)) {
        FUN_460e_15eb(0x232a,0,0,0);
      }
      uVar2 = FUN_460e_0f42(0,DAT_5b41_0d12,0);
      iVar3 = FUN_460e_141e(uVar2,in_DX);
      while (iVar3 != 0 || in_DX != 0) {
        *(undefined2 *)(iVar3 + 0x1e) = (char *)s_SIGNIN_RES_554c_3111 + 10;
        *(undefined2 *)(iVar3 + 0x1c) = 0xfc;
        *(undefined2 *)(iVar3 + 0x26) = 1;
        piVar1 = (int *)(iVar3 + 10);
        iVar3 = *(int *)(iVar3 + 8);
        in_DX = *piVar1;
      }
      if (iRam000557bc == 2) {
        FUN_311b_02be();
      }
      FUN_460e_101b(0,DAT_5b41_0d12,0);
      DAT_5b41_0d14 = 1;
    }
  }
  return;
}

