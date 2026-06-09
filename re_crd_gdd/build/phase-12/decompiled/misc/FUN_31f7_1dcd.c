// TIM2.EXE: FUN_31f7_1dcd @ file 0x038F3D Ghidra 0x33D3D
// Subsystem: misc | Size: 107 bytes


void __cdecl16far FUN_31f7_1dcd(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) < DAT_5b41_099f) {
    if (((DAT_5b41_051f & 1) != 0) &&
       (*(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1, *(int *)(iVar1 + 0x10) == DAT_5b41_099f
       )) {
      *(undefined2 *)(iVar1 + 0x10) = 0;
    }
  }
  else if (*(int *)(iVar1 + 0x10) != DAT_5b41_1994) {
    if (*(int *)(iVar1 + 0xb4) != 0) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    }
    *(undefined2 *)(iVar1 + 0xb4) = 1;
  }
  if (*(int *)(iVar1 + 0x10) != *(int *)(iVar1 + 0x12)) {
    FUN_28eb_3328(iVar1,uVar2);
  }
  return;
}

