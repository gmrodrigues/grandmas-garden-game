// TIM2.EXE: FUN_31f7_3192 @ file 0x03A302 Ghidra 0x35102
// Subsystem: misc | Size: 59 bytes


void __cdecl16far FUN_31f7_3192(undefined4 param_1)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar1 = (uint)(*(int *)(iVar3 + 0x10) == 1);
  if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
    uVar2 = *(undefined2 *)(uVar1 * 2 + 0x3adc);
  }
  else {
    uVar2 = ((undefined2 *)&DAT_554c_3ae0)[uVar1];
  }
  *(undefined2 *)(iVar3 + 0x7a) = uVar2;
  return;
}

