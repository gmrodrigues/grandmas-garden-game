// TIM2.EXE: FUN_1000_1187 @ file 0x016387 Ghidra 0x11187
// Subsystem: utility | Size: 59 bytes


void __cdecl16far FUN_1000_1187(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  
  if ((DAT_5b41_0469 != 0) && (iVar1 = FUN_1000_0abd(param_1), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x10) == 0) {
      return;
    }
    param_1 = *(undefined2 *)(iVar1 + 0x10);
  }
  FUN_1000_2050(param_1,param_2);
  return;
}

