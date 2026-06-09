// TIM2.EXE: FUN_31f7_a032 @ file 0x0411A2 Ghidra 0x3BFA2
// Subsystem: gfx | Size: 78 bytes


void __cdecl16far FUN_31f7_a032(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 0x40;
  for (iVar2 = 4; iVar2 < 6; iVar2 = iVar2 + 1) {
    iVar4 = iVar3 + iVar2 * 4;
    iVar1 = *(int *)(iVar4 + 0x60);
    iVar4 = *(int *)(iVar4 + 0x5e);
    if (iVar4 != 0 || iVar1 != 0) {
      *(undefined2 *)(iVar4 + 0x16) = *(undefined2 *)(iVar3 + 0x16);
    }
  }
  *(undefined2 *)(iVar3 + 0x16) = 0;
  return;
}

