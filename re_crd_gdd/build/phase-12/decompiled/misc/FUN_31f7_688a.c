// TIM2.EXE: FUN_31f7_688a @ file 0x03D9FA Ghidra 0x387FA
// Subsystem: misc | Size: 63 bytes


undefined2 __cdecl16far FUN_31f7_688a(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) < DAT_5b41_1a1a) {
    uVar2 = 0;
  }
  else if (*(int *)(iVar1 + 0x10) < DAT_5b41_1a1c) {
    uVar2 = 1;
  }
  else if (*(int *)(iVar1 + 0x10) < DAT_5b41_1a1e) {
    uVar2 = 2;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

