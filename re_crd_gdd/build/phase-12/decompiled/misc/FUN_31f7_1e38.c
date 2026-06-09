// TIM2.EXE: FUN_31f7_1e38 @ file 0x038FA8 Ghidra 0x33DA8
// Subsystem: misc | Size: 44 bytes


void __cdecl16far FUN_31f7_1e38(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) < DAT_5b41_099f) {
    *(int *)(iVar1 + 0x10) = DAT_5b41_099f;
    *(undefined2 *)(iVar1 + 0x98) = 0;
    FUN_28eb_3328(iVar1,uVar2);
  }
  return;
}

