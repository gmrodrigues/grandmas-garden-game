// TIM2.EXE: FUN_31f7_9a4b @ file 0x040BBB Ghidra 0x3B9BB
// Subsystem: gfx | Size: 63 bytes


undefined2 __cdecl16far
FUN_31f7_9a4b(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
             uint param_5)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar2 = (int)param_3;
  uVar3 = (undefined2)((ulong)param_3 >> 0x10);
  if (param_5 == 1) {
    piVar1 = (int *)(*(int *)(iVar2 + 0x76) + 0x18);
    *piVar1 = *piVar1 + 1;
    return 0;
  }
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    if ((param_5 & 0x18) != 0x10) {
      return 0;
    }
  }
  else if ((param_5 & 0x18) != 8) {
    return 0;
  }
  *(undefined2 *)(iVar2 + 0x16) = 1;
  return 0;
}

