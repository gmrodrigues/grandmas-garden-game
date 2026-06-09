// TIM2.EXE: FUN_31f7_66af @ file 0x03D81F Ghidra 0x3861F
// Subsystem: misc | Size: 60 bytes


void __cdecl16far FUN_31f7_66af(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 8) != 4) {
    FUN_2424_0f94(iVar1,uVar2,3);
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x2000;
    return;
  }
  *(undefined2 *)(iVar1 + 0x16) = 1;
  return;
}

