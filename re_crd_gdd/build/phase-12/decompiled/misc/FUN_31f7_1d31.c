// TIM2.EXE: FUN_31f7_1d31 @ file 0x038EA1 Ghidra 0x33CA1
// Subsystem: misc | Size: 95 bytes


void __cdecl16far FUN_31f7_1d31(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  iVar3 = DAT_5b41_1994;
  if (DAT_5b41_099f == 0) {
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      iVar1 = iVar3;
      if (iVar3 == 0) break;
      iVar2 = FUN_4551_0308(DAT_5b41_09cc,iVar3);
    } while (iVar2 == 0);
    do {
      DAT_5b41_099f = iVar1;
      iVar3 = iVar3 + 1;
      if (iVar3 == 0) break;
      iVar2 = FUN_4551_0308(DAT_5b41_09cc,iVar3);
      iVar1 = DAT_5b41_099f;
    } while (iVar2 == 0);
  }
  DAT_5b41_1994 = iVar3;
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  *(undefined2 *)((int)param_1 + 0x98) = *(undefined2 *)*(undefined2 *)(iRam000557e0 + 0x46);
  FUN_28eb_3670((int)param_1,uVar4);
  return;
}

