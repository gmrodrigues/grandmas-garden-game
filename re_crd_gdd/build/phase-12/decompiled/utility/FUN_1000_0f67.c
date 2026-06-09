// TIM2.EXE: FUN_1000_0f67 @ file 0x016167 Ghidra 0x10F67
// Subsystem: utility | Size: 48 bytes


undefined2 __cdecl16far FUN_1000_0f67(undefined2 param_1)

{
  int iVar1;
  
  if (((DAT_5b41_0469 != 0) && (iVar1 = FUN_1000_0abd(param_1), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x10) == 0)) {
    return *(undefined2 *)(iVar1 + 2);
  }
  return 0;
}

