// TIM2.EXE: FUN_1a9e_0c49 @ file 0x020829 Ghidra 0x1B629
// Subsystem: level | Size: 349 bytes


int __cdecl16far
FUN_1a9e_0c49(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined1 local_8 [4];
  int local_4;
  
  uVar7 = FUN_1a9e_04ff(param_3);
  uVar6 = (undefined2)((ulong)uVar7 >> 0x10);
  local_4 = (int)uVar7;
  if (local_4 == -1) {
    return -1;
  }
  *(undefined2 *)(DAT_5b41_0042 + 6) = param_2;
  uVar2 = FUN_1000_0f2a(param_2);
  iVar3 = DAT_5b41_0042;
  *(undefined2 *)(DAT_5b41_0042 + 0x1e) = uVar6;
  *(undefined2 *)(iVar3 + 0x1c) = uVar2;
  *(undefined2 *)(iVar3 + 0xc) = 0;
  *(undefined2 *)(iVar3 + 10) = 5;
  iVar3 = FUN_1a9e_0446(param_3);
  if (iVar3 == 0) {
    iVar3 = FUN_1a9e_054d(param_1,param_3);
    if (iVar3 == -1) {
      iVar3 = FUN_1a9e_047d(local_4);
      return iVar3;
    }
    FUN_1000_1135(param_1,param_2);
    FUN_1000_10d5(local_8,1,4,param_2);
    if (*(int *)(param_1 * 0xe + 0x170) != 0) {
      (*(code *)*(undefined2 *)(param_1 * 0xe + 0x170))();
    }
  }
  else {
    bVar1 = FUN_1000_0fdc(param_2,param_3);
    *(byte *)(DAT_5b41_0042 + 0x20) = bVar1;
    uVar4 = (uint)bVar1;
    iVar5 = FUN_1a9e_054d(uVar4);
    iVar3 = DAT_5b41_0042;
    if (iVar5 == -1) {
      FUN_1000_0e6d(param_2,0xffff,0xffff,1);
      iVar3 = FUN_1a9e_047d(local_4);
      return iVar3;
    }
    *(undefined2 *)(DAT_5b41_0042 + 0x10) = param_5;
    *(undefined2 *)(iVar3 + 0xe) = param_4;
    FUN_1000_0d10(DAT_5b41_0042 + 0x12,1,4,param_2);
    if (*(int *)(uVar4 * 0xe + 0x172) != 0) {
      (*(code *)*(undefined2 *)(uVar4 * 0xe + 0x172))();
    }
    *(byte *)(DAT_5b41_0042 + 0x20) = *(byte *)(DAT_5b41_0042 + 0x20) | 0x40;
  }
  *(byte *)(DAT_5b41_0042 + 0x20) = *(byte *)(DAT_5b41_0042 + 0x20) | 0x20;
  return local_4;
}

