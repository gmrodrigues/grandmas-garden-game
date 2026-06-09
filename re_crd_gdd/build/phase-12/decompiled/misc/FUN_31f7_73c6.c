// TIM2.EXE: FUN_31f7_73c6 @ file 0x03E536 Ghidra 0x39336
// Subsystem: misc | Size: 288 bytes


void __cdecl16far FUN_31f7_73c6(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((*(int *)(iVar3 + 0x10) == *(int *)(iVar3 + 0xa8)) ||
     (*(int *)(iVar3 + 0xa8) == DAT_5b41_1a34)) {
    FUN_28eb_51b3(iVar3,iVar4,0x1000,0x12,0x14,0x28,0x32);
    iVar2 = iVar3;
    iVar5 = iVar4;
    while( true ) {
      iVar1 = *(int *)(iVar2 + 0x8e);
      iVar2 = *(int *)(iVar2 + 0x8c);
      if (iVar2 == 0 && iVar1 == 0) break;
      iVar5 = iVar1;
      if ((*(int *)(iVar2 + 8) == 0x36) && (*(int *)(iVar2 + 0x10) < DAT_5b41_09a3)) {
        *(undefined2 *)(iVar3 + 0x16) = 1;
        if ((DAT_5b41_1a34 < *(int *)(iVar3 + 0x10)) && (*(int *)(iVar3 + 0x10) < DAT_5b41_1a3e)) {
          *(int *)(iVar3 + 0x10) = DAT_5b41_1a3e;
        }
        FUN_2424_0f94(iVar2,iVar1,3);
        *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x2000;
      }
    }
  }
  if (*(int *)(iVar3 + 0x16) == 0) {
    return;
  }
  if (*(int *)(iVar3 + 0x16) == 1) {
    *(undefined2 *)(iVar3 + 0x16) = 2;
    if ((*(int *)(iVar3 + 0x10) <= DAT_5b41_1a34) ||
       (iVar2 = DAT_5b41_1a3e, DAT_5b41_1a3e <= *(int *)(iVar3 + 0x10))) {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
      goto LAB_31f7_74d6;
    }
  }
  else {
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    iVar2 = DAT_5b41_1a36;
    if (((*(int *)(iVar3 + 0x10) != DAT_5b41_1a3a) &&
        (iVar2 = DAT_5b41_1a38, *(int *)(iVar3 + 0x10) != DAT_5b41_1a3c)) &&
       (*(int *)(iVar3 + 0x10) != DAT_5b41_1a40)) goto LAB_31f7_74d6;
  }
  *(int *)(iVar3 + 0x10) = iVar2;
LAB_31f7_74d6:
  FUN_28eb_3328(iVar3,iVar4);
  return;
}

