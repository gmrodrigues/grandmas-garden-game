// TIM2.EXE: FUN_4bdc_2689 @ file 0x053649 Ghidra 0x4E449
// Subsystem: physics | Size: 134 bytes


undefined2 __cdecl16far FUN_4bdc_2689(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_5b41_2860 != 0 || DAT_5b41_2862 != 0) {
    return 0;
  }
  iVar4 = 0;
  while( true ) {
    if (6 < iVar4) {
      return 1;
    }
    iVar3 = 0x17a;
    iVar2 = FUN_2e67_0edd(0x17a,0,2);
    ((undefined2 *)&DAT_5b41_2862)[iVar4 * 2] = iVar3;
    ((undefined2 *)&DAT_5b41_2860)[iVar4 * 2] = iVar2;
    if (iVar2 == 0 && iVar3 == 0) break;
    uVar1 = ((undefined2 *)&DAT_5b41_2862)[iVar4 * 2];
    iVar2 = ((undefined2 *)&DAT_5b41_2860)[iVar4 * 2];
    *(undefined1 *)(iVar2 + 0x158) = 0xff;
    *(undefined2 *)(iVar2 + 10) = uVar1;
    *(int *)(iVar2 + 8) = iVar2 + 0x16a;
    iVar4 = iVar4 + 1;
  }
  FUN_4bdc_302e();
  return 0;
}

