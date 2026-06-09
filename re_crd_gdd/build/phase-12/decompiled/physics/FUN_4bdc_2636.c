// TIM2.EXE: FUN_4bdc_2636 @ file 0x0535F6 Ghidra 0x4E3F6
// Subsystem: physics | Size: 83 bytes


undefined2 __cdecl16far FUN_4bdc_2636(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = 0;
  while( true ) {
    if (6 < iVar1) {
      return 0;
    }
    uVar3 = (undefined2)((ulong)*(undefined4 *)((undefined2 *)&DAT_5b41_2860 + iVar1 * 2) >> 0x10);
    iVar2 = (int)*(undefined4 *)((undefined2 *)&DAT_5b41_2860 + iVar1 * 2);
    if (((*(int *)(iVar2 + 0x168) == param_2) && (*(int *)(iVar2 + 0x166) == param_1)) &&
       (*(char *)(((undefined2 *)&DAT_5b41_2860)[iVar1 * 2] + 0x158) != -1)) break;
    iVar1 = iVar1 + 1;
  }
  return ((undefined2 *)&DAT_5b41_2860)[iVar1 * 2];
}

