// TIM2.EXE: FUN_31f7_7cc0 @ file 0x03EE30 Ghidra 0x39C30
// Subsystem: misc | Size: 46 bytes


undefined2 __cdecl16far FUN_31f7_7cc0(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  uVar1 = *(undefined2 *)((int)param_1 + 0x9c);
  iVar2 = *(int *)((int)param_1 + 0x9a);
  *(undefined2 *)(iVar2 + 0x16) = 1;
  *(undefined2 *)(iVar2 + 0xb4) = 4;
  return 1;
}

