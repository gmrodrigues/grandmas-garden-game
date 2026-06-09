// TIM2.EXE: FUN_1a9e_5c9e @ file 0x02587E Ghidra 0x2067E
// Subsystem: level | Size: 35 bytes


int FUN_1a9e_5c9e(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar4 = FUN_1a9e_5aa5();
  uVar5 = FUN_1a9e_5aa5();
  uVar1 = (uint)((ulong)uVar4 >> 0x10);
  uVar2 = (uint)((ulong)uVar5 >> 0x10);
  bVar3 = uVar1 < uVar2;
  if ((!bVar3) &&
     ((uVar2 < uVar1 || (bVar3 = (uint)uVar4 < (uint)uVar5, (uint)uVar5 < (uint)uVar4)))) {
    return 1;
  }
  return -(uint)bVar3;
}

