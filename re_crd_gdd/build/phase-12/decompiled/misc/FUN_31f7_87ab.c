// TIM2.EXE: FUN_31f7_87ab @ file 0x03F91B Ghidra 0x3A71B
// Subsystem: misc | Size: 110 bytes


void __cdecl16far FUN_31f7_87ab(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if ((*(int *)(iVar4 + 0x9a) != 0 || *(int *)(iVar4 + 0x9c) != 0) &&
     (uVar2 = (int)*(uint *)(iVar4 + 0x3a) >> 0xf, uVar3 = (int)*(uint *)(iVar4 + 0x3c) >> 0xf,
     0x200 < (int)(((*(uint *)(iVar4 + 0x3a) ^ uVar2) - uVar2) +
                  ((*(uint *)(iVar4 + 0x3c) ^ uVar3) - uVar3)))) {
    FUN_31f7_883d(iVar4,uVar5);
  }
  if (((*(byte *)(iVar4 + 0xd) & 0x20) == 0) && ((DAT_5b41_051f & 1) != 0)) {
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
    iVar1 = FUN_4551_0308(DAT_5b41_0a42,*(undefined2 *)(iVar4 + 0x10));
    if (iVar1 != 0) {
      *(undefined2 *)(iVar4 + 0x10) = 1;
    }
  }
  return;
}

