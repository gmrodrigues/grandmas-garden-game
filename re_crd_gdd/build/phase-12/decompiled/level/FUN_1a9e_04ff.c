// TIM2.EXE: FUN_1a9e_04ff @ file 0x0200DF Ghidra 0x1AEDF
// Subsystem: level | Size: 78 bytes


int __cdecl16near FUN_1a9e_04ff(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  for (iVar3 = 0; (iVar3 < 4 && (((undefined2 *)&DAT_5b41_0051)[iVar3] != 0)); iVar3 = iVar3 + 1) {
  }
  if (iVar3 == 4) {
    iVar3 = -1;
  }
  else {
    puVar1 = (undefined1 *)(iVar3 * 0x21 + 0x5fa9);
    DAT_5b41_0042 = puVar1;
    for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
    ((undefined2 *)&DAT_5b41_0051)[iVar3] = DAT_5b41_0042;
  }
  return iVar3;
}

