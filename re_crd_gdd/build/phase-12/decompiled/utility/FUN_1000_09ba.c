// TIM2.EXE: FUN_1000_09ba @ file 0x015BBA Ghidra 0x109BA
// Subsystem: utility | Size: 194 bytes


void __cdecl16far FUN_1000_09ba(int param_1)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = false;
  if ((DAT_5b41_0460 == '\0') && (param_1 != 0)) {
    uVar2 = FUN_1000_418e(param_1 * 0x1c + 0x6300,0x1d4);
    iVar3 = FUN_1000_3d77(uVar2);
    if (iVar3 != 0) {
      bVar1 = true;
    }
  }
  if (((param_1 != DAT_5b41_0465) || (bVar1)) || (DAT_5b41_045f != '\0')) {
    iVar3 = DAT_5b41_0465 * 0x1c;
    if (*(int *)(iVar3 + 0x6310) != 0) {
      FUN_1000_3d77(*(undefined2 *)(iVar3 + 0x6310));
      *(undefined2 *)(iVar3 + 0x6310) = 0;
    }
    DAT_5b41_0465 = param_1;
    iVar3 = param_1 * 0x1c;
    if (param_1 != 0) {
      DAT_5b41_045d = 1;
      do {
        iVar4 = FUN_1000_418e(iVar3 + 0x6300,0x1d7);
        *(int *)(iVar3 + 0x6310) = iVar4;
      } while (iVar4 == 0);
      DAT_5b41_045d = 0;
    }
    *(undefined2 *)(iVar3 + 0x6314) = 0;
    *(undefined2 *)(iVar3 + 0x6312) = 0;
    FUN_1000_0abd(0);
    DAT_5b41_045f = '\0';
  }
  return;
}

