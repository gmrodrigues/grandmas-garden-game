// TIM2.EXE: FUN_31f7_b66d @ file 0x0427DD Ghidra 0x3D5DD
// Subsystem: sound | Size: 72 bytes


void __cdecl16far FUN_31f7_b66d(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_5b41_1ac0 == 0) {
    DAT_5b41_1ac0 = FUN_4551_0370(DAT_5b41_0ac2,2);
  }
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined1 *)(iVar1 + 0x82) = 0xc;
  *(undefined1 *)(iVar1 + 0x83) = 1;
  *(undefined2 *)(iVar1 + 0x98) = *(undefined2 *)*(undefined2 *)(DAT_554c_0416 + 0x46);
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

