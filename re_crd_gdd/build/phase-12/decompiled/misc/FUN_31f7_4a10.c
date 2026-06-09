// TIM2.EXE: FUN_31f7_4a10 @ file 0x03BB80 Ghidra 0x36980
// Subsystem: misc | Size: 72 bytes


void __cdecl16far FUN_31f7_4a10(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar2 + 0x10);
  if (param_2 == 0) {
    if (DAT_5b41_19ee <= *(uint *)(iVar2 + 0x10)) goto LAB_31f7_4a4b;
    *(uint *)(iVar2 + 0x10) = DAT_5b41_19ee;
  }
  FUN_2424_2e7d(iVar2,uVar3,param_2);
LAB_31f7_4a4b:
  *(undefined2 *)(iVar2 + 0x10) = uVar1;
  return;
}

