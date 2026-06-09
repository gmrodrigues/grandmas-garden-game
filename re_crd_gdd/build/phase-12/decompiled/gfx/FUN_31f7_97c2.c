// TIM2.EXE: FUN_31f7_97c2 @ file 0x040932 Ghidra 0x3B732
// Subsystem: gfx | Size: 117 bytes


void __cdecl16far FUN_31f7_97c2(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_09ab == 0) {
    DAT_5b41_09ab = FUN_4551_0370(DAT_5b41_0a5e,0x15);
    DAT_5b41_1aa0 = FUN_4551_0370(DAT_5b41_0a5e,0xffff);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x10) < DAT_5b41_09ab) {
    uVar1 = *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46);
  }
  else {
    uVar1 = *(undefined2 *)(*(int *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46) + 2);
  }
  *(undefined2 *)(iVar2 + 0x98) = uVar1;
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

