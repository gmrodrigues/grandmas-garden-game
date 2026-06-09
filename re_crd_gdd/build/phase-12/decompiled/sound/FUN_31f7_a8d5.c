// TIM2.EXE: FUN_31f7_a8d5 @ file 0x041A45 Ghidra 0x3C845
// Subsystem: sound | Size: 80 bytes


void __cdecl16far FUN_31f7_a8d5(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(int *)(iVar1 + 0x10) == DAT_5b41_1ab0) || (*(int *)(iVar1 + 0x10) == DAT_5b41_1aae)) {
    *(undefined2 *)(iVar1 + 0x10) = *(undefined2 *)(iVar1 + 0x12);
  }
  if (param_2 == 0) {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x10;
  }
  else if (param_2 == 1) {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xffef;
  }
  FUN_31f7_a534(iVar1,uVar2);
  return;
}

