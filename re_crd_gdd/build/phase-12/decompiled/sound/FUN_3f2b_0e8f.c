// TIM2.EXE: FUN_3f2b_0e8f @ file 0x04533F Ghidra 0x4013F
// Subsystem: sound | Size: 183 bytes


undefined2 __cdecl16far FUN_3f2b_0e8f(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  code *pcVar3;
  char extraout_AH;
  char extraout_AH_00;
  undefined2 uVar4;
  char extraout_AH_01;
  char extraout_AH_02;
  int iVar5;
  undefined2 extraout_DX;
  int in_BX;
  char *pcVar6;
  char *pcVar7;
  int unaff_ES;
  bool bVar8;
  
  if (DAT_554c_3d52 == 0) {
    pcVar3 = (code *)swi(0x21);
    (*pcVar3)();
    bVar8 = unaff_ES == 0;
    if (!bVar8) {
      pcVar7 = "HECK";
      pcVar6 = (char *)s_EMMXXXX0_EMM_fatal_error_554c_3d5c;
      iVar5 = 8;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar2 = pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar1 = pcVar6;
        pcVar6 = pcVar6 + 1;
        bVar8 = *pcVar1 == *pcVar2;
      } while (bVar8);
      if (bVar8) {
        pcVar3 = (code *)swi(0x67);
        (*pcVar3)();
        if (extraout_AH == '\0') {
          pcVar3 = (code *)swi(0x67);
          (*pcVar3)();
          if (extraout_AH_00 == '\0') {
            pcVar3 = (code *)swi(0x67);
            DAT_554c_3d5a = in_BX;
            uVar4 = (*pcVar3)();
            if (((char)((uint)uVar4 >> 8) == '\0') && (0x31 < (byte)uVar4)) {
              pcVar3 = (code *)swi(0x67);
              DAT_554c_3d56 = (byte)uVar4;
              (*pcVar3)();
              if ((extraout_AH_01 == '\0') &&
                 ((DAT_554c_3d54 = in_BX, in_BX != 0 && (iVar5 = 100, DAT_554c_3d7a != 100)))) {
                DAT_554c_3e44 = 0;
                do {
                  if (*(int *)((int)(undefined2 *)&DAT_554c_3d7c + DAT_554c_3e44) == 0) break;
                  DAT_554c_3e44 = DAT_554c_3e44 + 2;
                  iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
                if ((param_1 != 0) && (param_1 <= in_BX)) {
                  pcVar3 = (code *)swi(0x67);
                  iVar5 = param_1;
                  (*pcVar3)();
                  if (extraout_AH_02 == '\0') {
                    DAT_554c_3d54 = DAT_554c_3d54 - iVar5;
                    *(undefined2 *)((int)(undefined2 *)&DAT_554c_3d7c + DAT_554c_3e44) = extraout_DX
                    ;
                    DAT_554c_3d7a = DAT_554c_3d7a + 1;
                    FUN_3f2b_0e3a();
                    *(int *)0x0 = param_1;
                    return extraout_DX;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

