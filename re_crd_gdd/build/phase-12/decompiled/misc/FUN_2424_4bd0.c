// TIM2.EXE: FUN_2424_4bd0 @ file 0x02E010 Ghidra 0x28E10
// Subsystem: misc | Size: 168 bytes


void __cdecl16far FUN_2424_4bd0(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 in_DX;
  int iVar5;
  undefined2 uVar6;
  
  iVar1 = DAT_554c_42c4;
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  if (((*(byte *)(iVar5 + 0x24) & 8) == 0) && (DAT_5b41_0937 != 0x2000)) {
    if (DAT_554c_42c4 < DAT_5b41_0537) {
      if (DAT_554c_42c6 < DAT_5b41_0537) {
        return;
      }
      DAT_554c_42c4 = DAT_5b41_0537;
    }
    if (*(uint *)(iVar5 + 0xe) < 2) {
      uVar2 = 0x29;
    }
    else {
      uVar2 = 0x2a;
    }
    if ((*(byte *)(iVar5 + 0xe) & 1) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 2;
    }
    if (iVar3 == 0) {
      iVar4 = *(int *)(iVar5 + 0x14);
    }
    else {
      iVar4 = *(int *)(iVar5 + 0x14) + -4;
    }
    uVar6 = FUN_3e34_0ad5(DAT_5b41_0523,uVar2,iVar4,*(undefined2 *)(iVar5 + 0x16),iVar3);
    FUN_3e34_0160(uVar6,in_DX);
  }
  DAT_554c_42c4 = iVar1;
  return;
}

