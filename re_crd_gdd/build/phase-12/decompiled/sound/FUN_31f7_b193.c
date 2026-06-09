// TIM2.EXE: FUN_31f7_b193 @ file 0x042303 Ghidra 0x3D103
// Subsystem: sound | Size: 24 bytes


void __cdecl16far FUN_31f7_b193(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x48) = *(undefined2 *)(iVar1 + 0x54);
  *(undefined2 *)(iVar1 + 0x4a) = *(undefined2 *)(iVar1 + 0x56);
  return;
}

