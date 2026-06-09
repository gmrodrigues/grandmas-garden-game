// TIM2.EXE: FUN_31f7_2982 @ file 0x039AF2 Ghidra 0x348F2
// Subsystem: misc | Size: 94 bytes


void __cdecl16far FUN_31f7_2982(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) < 4) {
    *(undefined2 *)(iVar1 + 0x10) = 4;
  }
  else {
    *(undefined2 *)(iVar1 + 0x10) = 0;
  }
  *(undefined2 *)(iVar1 + 0xa8) = *(undefined2 *)(iVar1 + 0x10);
  FUN_31f7_28c4(iVar1,uVar2);
  FUN_2424_0915(iVar1,uVar2,3);
  FUN_2424_0f94(iVar1,uVar2,3);
  FUN_28eb_2d82(iVar1,uVar2,2);
  return;
}

