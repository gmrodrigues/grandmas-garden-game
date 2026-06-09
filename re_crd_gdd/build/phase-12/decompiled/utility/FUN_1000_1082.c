// TIM2.EXE: FUN_1000_1082 @ file 0x016282 Ghidra 0x11082
// Subsystem: utility | Size: 83 bytes


uint __cdecl16far FUN_1000_1082(int param_1)

{
  int iVar1;
  
  if ((DAT_5b41_0469 == 0) || (iVar1 = FUN_1000_0abd(param_1), iVar1 == 0)) {
    return *(uint *)(param_1 + 2) & 0x20;
  }
  if (*(int *)(iVar1 + 0x10) != 0) {
    return *(uint *)(*(int *)(iVar1 + 0x10) + 2) & 0x20;
  }
  if ((*(uint *)(iVar1 + 8) <= *(uint *)(iVar1 + 0xc)) &&
     ((*(uint *)(iVar1 + 0xc) != *(uint *)(iVar1 + 8) ||
      (*(uint *)(iVar1 + 6) <= *(uint *)(iVar1 + 10))))) {
    return 1;
  }
  return 0;
}

