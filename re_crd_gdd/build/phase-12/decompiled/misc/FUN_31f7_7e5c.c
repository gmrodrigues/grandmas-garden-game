// TIM2.EXE: FUN_31f7_7e5c @ file 0x03EFCC Ghidra 0x39DCC
// Subsystem: misc | Size: 54 bytes


void __cdecl16far FUN_31f7_7e5c(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(int *)(iVar1 + 0x16) != 0) || (DAT_5b41_1a5c <= *(uint *)(iVar1 + 0x10))) {
    if (*(int *)(iVar1 + 0x10) != DAT_5b41_09a1) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
      FUN_28eb_3328(iVar1,uVar2);
    }
  }
  return;
}

