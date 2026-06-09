// TIM2.EXE: FUN_31f7_532c @ file 0x03C49C Ghidra 0x3729C
// Subsystem: misc | Size: 59 bytes


void __cdecl16far FUN_31f7_532c(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(int *)(iVar1 + 0x16) != 0) && (*(int *)(iVar1 + 0x10) != DAT_5b41_19fc)) {
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
    if (*(int *)(iVar1 + 0x10) == DAT_5b41_19fc) {
      *(undefined2 *)(iVar1 + 0x16) = 0;
    }
    FUN_28eb_3328(iVar1,uVar2);
  }
  return;
}

