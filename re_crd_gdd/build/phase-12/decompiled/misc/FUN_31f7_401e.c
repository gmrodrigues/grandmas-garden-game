// TIM2.EXE: FUN_31f7_401e @ file 0x03B18E Ghidra 0x35F8E
// Subsystem: misc | Size: 69 bytes


void __cdecl16far FUN_31f7_401e(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    *(undefined2 *)(iVar2 + 0x3a) = 0xfe00;
  }
  else {
    *(undefined2 *)(iVar2 + 0x3a) = 0x200;
  }
  *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
  iVar1 = FUN_4551_0308(DAT_5b41_09f0,*(undefined2 *)(iVar2 + 0x10));
  if (iVar1 == -1) {
    *(undefined2 *)(iVar2 + 0x10) = 0;
  }
  return;
}

