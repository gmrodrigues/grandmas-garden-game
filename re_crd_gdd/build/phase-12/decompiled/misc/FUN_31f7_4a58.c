// TIM2.EXE: FUN_31f7_4a58 @ file 0x03BBC8 Ghidra 0x369C8
// Subsystem: misc | Size: 69 bytes


void __cdecl16far FUN_31f7_4a58(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar2 + 0x10);
  if (param_2 == 0) {
    if (*(int *)(iVar2 + 0x10) != 0) goto LAB_31f7_4a90;
    *(undefined2 *)(iVar2 + 0x10) = DAT_5b41_19f6;
  }
  FUN_2424_2e7d(iVar2,uVar3,param_2);
LAB_31f7_4a90:
  *(undefined2 *)(iVar2 + 0x10) = uVar1;
  return;
}

