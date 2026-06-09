// TIM2.EXE: FUN_31f7_b291 @ file 0x042401 Ghidra 0x3D201
// Subsystem: sound | Size: 36 bytes


void __cdecl16far FUN_31f7_b291(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  *(undefined2 *)((int)param_1 + 0x98) = *(undefined2 *)*(undefined2 *)(DAT_554c_0412 + 0x46);
  FUN_28eb_3670((int)param_1,uVar1);
  return;
}

