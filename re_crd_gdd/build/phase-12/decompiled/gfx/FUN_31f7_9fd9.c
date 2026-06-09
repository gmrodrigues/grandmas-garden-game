// TIM2.EXE: FUN_31f7_9fd9 @ file 0x041149 Ghidra 0x3BF49
// Subsystem: gfx | Size: 89 bytes


void __cdecl16far FUN_31f7_9fd9(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 0x98) = *(undefined2 *)*(undefined2 *)(DAT_554c_03c2 + 0x46);
  FUN_28eb_3670(iVar1,uVar2);
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) % 7;
  if (*(int *)(iVar1 + 0x6e) != 0 || *(int *)(iVar1 + 0x70) != 0) {
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 7;
  }
  if (*(int *)(iVar1 + 0x72) != 0 || *(int *)(iVar1 + 0x74) != 0) {
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 0xe;
  }
  return;
}

