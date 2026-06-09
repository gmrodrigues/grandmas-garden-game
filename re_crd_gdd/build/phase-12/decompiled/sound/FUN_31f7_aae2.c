// TIM2.EXE: FUN_31f7_aae2 @ file 0x041C52 Ghidra 0x3CA52
// Subsystem: sound | Size: 59 bytes


void __cdecl16far FUN_31f7_aae2(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x16) == 0) {
    if (*(int *)(iVar1 + 0x10) == 0) {
      return;
    }
    *(undefined2 *)(iVar1 + 0x10) = 0;
  }
  else {
    *(undefined2 *)(iVar1 + 0x10) = 1;
    *(undefined2 *)(iVar1 + 0x16) = 0;
  }
  FUN_28eb_3328(iVar1,uVar2);
  return;
}

