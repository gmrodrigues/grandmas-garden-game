// TIM2.EXE: FUN_1000_0abd @ file 0x015CBD Ghidra 0x10ABD
// Subsystem: utility | Size: 99 bytes


undefined2 * __cdecl16far FUN_1000_0abd(undefined2 *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (param_1 == (undefined2 *)0x0) {
    DAT_5b41_02f2 = (undefined2 *)0x0;
    DAT_5b41_02f4 = (undefined2 *)0x0;
    puVar1 = (undefined2 *)0x0;
  }
  else if (DAT_5b41_0469 == 0) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    puVar1 = DAT_5b41_02f4;
    if (param_1 != DAT_5b41_02f2) {
      DAT_5b41_02f2 = param_1;
      iVar2 = 10;
      for (DAT_5b41_02f4 = (undefined2 *)&DAT_5b41_02fc; (iVar2 != 0 && (DAT_5b41_02f4 != param_1));
          DAT_5b41_02f4 = DAT_5b41_02f4 + 9) {
        iVar2 = iVar2 + -1;
      }
      if ((iVar2 == 0) || (puVar1 = DAT_5b41_02f4, DAT_5b41_02f4[7] == 0)) {
        DAT_5b41_02f4 = (undefined2 *)0x0;
        DAT_5b41_02f2 = (undefined2 *)0x0;
        puVar1 = DAT_5b41_02f4;
      }
    }
  }
  return puVar1;
}

