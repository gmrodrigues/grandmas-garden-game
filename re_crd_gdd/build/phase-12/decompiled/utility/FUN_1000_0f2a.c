// TIM2.EXE: FUN_1000_0f2a @ file 0x01612A Ghidra 0x10F2A
// Subsystem: utility | Size: 61 bytes


undefined2 __cdecl16far FUN_1000_0f2a(undefined2 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if ((DAT_5b41_0469 != 0) && (iVar1 = FUN_1000_0abd(param_1), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x10) == 0) {
      return *(undefined2 *)(iVar1 + 10);
    }
    param_1 = *(undefined2 *)(iVar1 + 0x10);
  }
  uVar2 = FUN_1000_4431(param_1);
  return uVar2;
}

