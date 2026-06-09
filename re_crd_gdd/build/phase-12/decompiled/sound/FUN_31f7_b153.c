// TIM2.EXE: FUN_31f7_b153 @ file 0x0422C3 Ghidra 0x3D0C3
// Subsystem: sound | Size: 64 bytes


void __cdecl16far FUN_31f7_b153(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  puVar1 = (uint *)((int)param_1 + 0xc);
  *puVar1 = *puVar1 | 0x40;
  for (iVar3 = 4; iVar3 < 6; iVar3 = iVar3 + 1) {
    iVar4 = (int)param_1 + iVar3 * 4;
    iVar2 = *(int *)(iVar4 + 0x60);
    iVar4 = *(int *)(iVar4 + 0x5e);
    if (iVar4 != 0 || iVar2 != 0) {
      *(undefined2 *)(iVar4 + 0x16) = 1;
    }
  }
  return;
}

