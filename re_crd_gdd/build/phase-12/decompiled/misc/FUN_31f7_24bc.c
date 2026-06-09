// TIM2.EXE: FUN_31f7_24bc @ file 0x03962C Ghidra 0x3442C
// Subsystem: misc | Size: 47 bytes


undefined2 __cdecl16far FUN_31f7_24bc(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 8) == 0x14) {
    FUN_31f7_25cf(*(undefined2 *)(iVar1 + 0x9a),*(undefined2 *)(iVar1 + 0x9c),
                  *(undefined2 *)(iVar1 + 0x9a),*(undefined2 *)(iVar1 + 0x9c));
  }
  return 1;
}

