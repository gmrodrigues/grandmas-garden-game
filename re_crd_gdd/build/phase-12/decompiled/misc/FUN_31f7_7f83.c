// TIM2.EXE: FUN_31f7_7f83 @ file 0x03F0F3 Ghidra 0x39EF3
// Subsystem: misc | Size: 111 bytes


undefined2 __cdecl16far FUN_31f7_7f83(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  uVar1 = *(undefined2 *)((int)param_1 + 0x9c);
  iVar2 = *(int *)((int)param_1 + 0x9a);
  if ((int)((undefined2 *)&DAT_5b41_1a5e)
           [(uint)(DAT_5b41_0989 <= *(int *)(iVar2 + 0xa8)) +
            (uint)(DAT_5b41_098b <= *(int *)(iVar2 + 0xa8))] < *(int *)(iVar2 + 0x10)) {
    FUN_31f7_8315(iVar2,uVar1);
  }
  return 1;
}

