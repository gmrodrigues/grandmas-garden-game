// TIM2.EXE: FUN_31f7_b1ab @ file 0x04231B Ghidra 0x3D11B
// Subsystem: sound | Size: 83 bytes


void __cdecl16far FUN_31f7_b1ab(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0xae) == 0) {
    *(undefined2 *)(iVar1 + 0xae) = 5;
  }
  if ((DAT_5b41_051f & 4) != 0) {
    DAT_554c_42cc = 1;
    DAT_554c_42cd = *(undefined1 *)(iVar1 + 0xae);
    DAT_554c_42ce = DAT_554c_42cd;
    FUN_1a9e_3854(*(int *)(iVar1 + 0x22) - DAT_5b41_0925,*(int *)(iVar1 + 0x24) - DAT_5b41_0927,
                  *(undefined2 *)(iVar1 + 0x48),*(undefined2 *)(iVar1 + 0x4a));
  }
  return;
}

