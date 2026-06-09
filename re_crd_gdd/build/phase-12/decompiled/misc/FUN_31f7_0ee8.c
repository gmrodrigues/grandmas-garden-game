// TIM2.EXE: FUN_31f7_0ee8 @ file 0x038058 Ghidra 0x32E58
// Subsystem: misc | Size: 115 bytes


void __cdecl16far FUN_31f7_0ee8(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_1976 == 0) {
    DAT_5b41_1976 = FUN_4551_0370(DAT_5b41_09ba,6);
    DAT_5b41_1978 = FUN_4551_0370(DAT_5b41_09ba,0xffff);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    uVar1 = 0x25;
  }
  else {
    uVar1 = 0xb;
  }
  *(undefined1 *)(iVar2 + 0x5a) = uVar1;
  *(undefined1 *)(iVar2 + 0x5b) = 0xb;
  *(undefined2 *)(iVar2 + 0x5c) = 6;
  *(undefined2 *)(iVar2 + 0x98) =
       *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46);
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

