// TIM2.EXE: FUN_4fd6_0e40 @ file 0x055DA0 Ghidra 0x50BA0
// Subsystem: misc | Size: 99 bytes


undefined2 __stdcall16far FUN_4fd6_0e40(undefined2 param_1,undefined2 param_2,int param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  char extraout_AH;
  char extraout_AH_00;
  undefined1 extraout_AH_01;
  int extraout_DX;
  
  uVar2 = uRam00050008;
  if ((*(byte *)0x38 & 1) != 0) {
    if ((*(byte *)0x38 & 2) != 0) {
      return 0;
    }
    *(byte *)0x38 = *(byte *)0x38 | 2;
    *(undefined2 *)0x34 = param_2;
    *(undefined2 *)0x36 = param_1;
    if (param_3 == 0) {
      pcVar1 = (code *)swi(0x67);
      (*pcVar1)();
      if (extraout_AH != '\0') {
        return 0xffff;
      }
      *(byte *)0x38 = *(byte *)0x38 | 4;
      param_3 = extraout_DX;
    }
    *(int *)0x32 = param_3;
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    if (extraout_AH_00 == '\0') {
      pcVar1 = (code *)swi(0x67);
      (*pcVar1)();
      return CONCAT11(extraout_AH_01,extraout_AH_01);
    }
  }
  return 0xffff;
}

