// TIM2.EXE: FUN_31f7_b9c5 @ file 0x042B35 Ghidra 0x3D935
// Subsystem: sound | Size: 48 bytes


void __cdecl16far FUN_31f7_b9c5(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  DAT_5b41_1aca = *(int *)(iVar1 + 0x22) + param_2;
  DAT_5b41_1acc = *(int *)(iVar1 + 0x22) + param_3;
  DAT_5b41_1ace = *(int *)(iVar1 + 0x24) + param_4;
  DAT_5b41_1ad0 = *(int *)(iVar1 + 0x24) + param_5;
  return;
}

