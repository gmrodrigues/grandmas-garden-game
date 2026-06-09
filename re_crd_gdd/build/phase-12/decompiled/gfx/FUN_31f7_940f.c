// TIM2.EXE: FUN_31f7_940f @ file 0x04057F Ghidra 0x3B37F
// Subsystem: gfx | Size: 135 bytes


undefined2 __cdecl16far FUN_31f7_940f(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar3 + 0x9c);
  iVar2 = *(int *)(iVar3 + 0x9a);
  iVar3 = *(int *)(iVar3 + 0xa2);
  if (*(int *)(iVar2 + 0x10) < DAT_5b41_1a9a) {
    iVar4 = 0;
  }
  else if (*(int *)(iVar2 + 0x10) < DAT_5b41_1a9c) {
    iVar4 = 1;
  }
  else {
    iVar4 = 2;
  }
  if ((*(byte *)(iVar2 + 0xc) & 0x10) != 0) {
    iVar3 = (*(int *)(DAT_554c_03a4 + 0x22) - iVar3) + -2;
    if (iVar3 < 0) {
      iVar3 = iVar3 + *(int *)(DAT_554c_03a4 + 0x22);
    }
  }
  if ((*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_1a8e)[iVar4]) && (iVar3 == 2)) {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
  }
  return 1;
}

