// TIM2.EXE: FUN_31f7_0bf4 @ file 0x037D64 Ghidra 0x32B64
// Subsystem: misc | Size: 113 bytes


undefined2 __cdecl16far FUN_31f7_0bf4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_5b41_196a;
  if (DAT_5b41_1962 == 0) {
    iVar2 = 0;
    for (iVar3 = 0; iVar3 < 5; iVar3 = iVar3 + 1) {
      ((undefined2 *)&DAT_5b41_1960)[iVar3] = iVar2;
      do {
        iVar2 = iVar2 + 1;
        if (iVar2 == 0) break;
        iVar1 = FUN_4551_0308(DAT_5b41_09b8,iVar2);
      } while (iVar1 == 0);
      ((undefined2 *)&DAT_5b41_196c)[iVar3] = iVar2;
      do {
        iVar2 = iVar2 + 1;
        if (iVar2 == 0) break;
        iVar1 = FUN_4551_0308(DAT_5b41_09b8,iVar2);
      } while (iVar1 == 0);
    }
  }
  DAT_5b41_196a = iVar2;
  if (param_1 != 0 || param_2 != 0) {
    FUN_31f7_0c65(param_1,param_2);
  }
  return 1;
}

