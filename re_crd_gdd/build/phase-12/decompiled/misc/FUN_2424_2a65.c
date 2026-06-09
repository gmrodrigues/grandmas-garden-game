// TIM2.EXE: FUN_2424_2a65 @ file 0x02BEA5 Ghidra 0x26CA5
// Subsystem: misc | Size: 150 bytes


void __cdecl16far FUN_2424_2a65(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x58);
  if ((*(int *)(iVar1 + 6) != 0 || *(int *)(iVar1 + 8) != 0) &&
     (*(int *)(iVar1 + 10) != 0 || *(int *)(iVar1 + 0xc) != 0)) {
    DAT_554c_42ce = 0x84;
    FUN_2424_27e0(*(int *)(iVar1 + 0xe) - DAT_5b41_0925,*(int *)(iVar1 + 0x10) - DAT_5b41_0927,
                  *(int *)(iVar1 + 0x12) - DAT_5b41_0925,*(int *)(iVar1 + 0x14) - DAT_5b41_0927);
    DAT_554c_42ce = 0x84;
    FUN_2424_27e0(*(int *)(iVar1 + 0x16) - DAT_5b41_0925,*(int *)(iVar1 + 0x18) - DAT_5b41_0927,
                  *(int *)(iVar1 + 0x1a) - DAT_5b41_0925,*(int *)(iVar1 + 0x1c) - DAT_5b41_0927);
  }
  return;
}

