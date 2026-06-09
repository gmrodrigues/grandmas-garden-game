// TIM2.EXE: FUN_1a9e_0da6 @ file 0x020986 Ghidra 0x1B786
// Subsystem: level | Size: 261 bytes


int __cdecl16far
FUN_1a9e_0da6(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined2 uVar6;
  
  iVar2 = FUN_1a9e_04ff(param_4);
  iVar3 = DAT_5b41_0042;
  if (iVar2 == -1) {
    return -1;
  }
  *(undefined2 *)(DAT_5b41_0042 + 8) = param_3;
  *(undefined2 *)(iVar3 + 6) = param_2;
  *(undefined1 *)(iVar3 + 0x20) = (undefined1)param_1;
  *(undefined2 *)(iVar3 + 0xc) = 0;
  *(undefined2 *)(iVar3 + 10) = 5;
  iVar3 = FUN_1a9e_0446(param_4);
  if (iVar3 == 0) {
    iVar3 = FUN_1a9e_054d(param_1,param_4);
    if (iVar3 == -1) {
      iVar3 = FUN_1a9e_047d(iVar2);
      return iVar3;
    }
    *(undefined1 *)*(undefined4 *)(DAT_5b41_0042 + 6) = (undefined1)param_1;
  }
  else {
    uVar6 = 0;
    pbVar4 = (byte *)FUN_1000_1ae8(param_4);
    bVar1 = *pbVar4;
    *(byte *)(DAT_5b41_0042 + 0x20) = bVar1;
    uVar5 = (uint)bVar1;
    iVar3 = FUN_1a9e_054d(uVar5);
    if (iVar3 == -1) {
      iVar3 = FUN_1a9e_047d(iVar2);
      return iVar3;
    }
    FUN_1000_05ea(DAT_5b41_0042 + 0x12,0x554c,param_2,param_3,4);
    iVar3 = DAT_5b41_0042;
    *(undefined2 *)(DAT_5b41_0042 + 0x10) = param_6;
    *(undefined2 *)(iVar3 + 0xe) = param_5;
    if (*(int *)(uVar5 * 0xe + 0x172) != 0) {
      (*(code *)*(undefined2 *)(uVar5 * 0xe + 0x172))();
    }
    *(byte *)(DAT_5b41_0042 + 0x20) = *(byte *)(DAT_5b41_0042 + 0x20) | 0x40;
  }
  return iVar2;
}

