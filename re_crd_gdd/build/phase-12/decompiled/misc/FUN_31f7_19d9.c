// TIM2.EXE: FUN_31f7_19d9 @ file 0x038B49 Ghidra 0x33949
// Subsystem: misc | Size: 62 bytes


undefined2 __cdecl16far FUN_31f7_19d9(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  bVar2 = DAT_5b41_0975 <= *(int *)((int)param_1 + 0x10);
  iVar1 = *(int *)((int)param_1 + 0x10);
  if ((iVar1 < (int)((undefined2 *)&DAT_5b41_197a)[bVar2]) ||
     ((int)((undefined2 *)&DAT_5b41_1986)[bVar2] <= iVar1)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

