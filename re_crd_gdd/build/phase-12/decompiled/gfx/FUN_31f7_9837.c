// TIM2.EXE: FUN_31f7_9837 @ file 0x0409A7 Ghidra 0x3B7A7
// Subsystem: gfx | Size: 58 bytes


void __cdecl16far FUN_31f7_9837(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if ((DAT_5b41_051f & 1) != 0) {
    uVar2 = (undefined2)((ulong)param_1 >> 0x10);
    iVar1 = (int)param_1;
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    if (*(int *)(iVar1 + 0x10) == DAT_5b41_09ab) {
      *(undefined2 *)(iVar1 + 0x10) = 1;
      return;
    }
    if (*(int *)(iVar1 + 0x10) == DAT_5b41_1aa0) {
      *(int *)(iVar1 + 0x10) = DAT_5b41_09ab + 1;
    }
  }
  return;
}

