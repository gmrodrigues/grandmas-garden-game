// TIM2.EXE: FUN_31f7_7311 @ file 0x03E481 Ghidra 0x39281
// Subsystem: misc | Size: 33 bytes


void __cdecl16far FUN_31f7_7311(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) != 0) {
    *(undefined2 *)(iVar1 + 0x10) = 0;
    FUN_28eb_3328(iVar1,uVar2);
  }
  return;
}

