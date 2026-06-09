// TIM2.EXE: FUN_31f7_8783 @ file 0x03F8F3 Ghidra 0x3A6F3
// Subsystem: misc | Size: 40 bytes


undefined2 __cdecl16far FUN_31f7_8783(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  uVar1 = *(undefined2 *)((int)param_1 + 0x9c);
  uVar2 = *(undefined2 *)((int)param_1 + 0x9a);
  FUN_31f7_883d(uVar2,uVar1,uVar2,uVar1);
  return 1;
}

