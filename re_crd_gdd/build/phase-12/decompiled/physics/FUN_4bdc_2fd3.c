// TIM2.EXE: FUN_4bdc_2fd3 @ file 0x053F93 Ghidra 0x4ED93
// Subsystem: physics | Size: 91 bytes


void __cdecl16far FUN_4bdc_2fd3(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (6 < iVar3) {
      return;
    }
    uVar1 = ((undefined2 *)&DAT_5b41_2862)[iVar3 * 2];
    iVar2 = ((undefined2 *)&DAT_5b41_2860)[iVar3 * 2];
    if ((*(int *)(iVar2 + 0x168) == param_2) && (*(int *)(iVar2 + 0x166) == param_1)) break;
    iVar3 = iVar3 + 1;
  }
  FUN_4bdc_2371(iVar2,uVar1);
  *(undefined1 *)(iVar2 + 0x158) = 0xff;
  return;
}

