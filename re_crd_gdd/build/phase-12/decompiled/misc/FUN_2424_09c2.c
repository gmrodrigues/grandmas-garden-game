// TIM2.EXE: FUN_2424_09c2 @ file 0x029E02 Ghidra 0x24C02
// Subsystem: misc | Size: 97 bytes


void __cdecl16far FUN_2424_09c2(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x58);
  if ((param_2 & 1) != 0) {
    FUN_2424_1a04(iVar1 + 0x2e,iVar1 + 0x32,1);
    FUN_2424_1a04(iVar1 + 0x36,iVar1 + 0x3a,1);
  }
  if ((param_2 & 2) != 0) {
    FUN_2424_1a04(iVar1 + 0x1e,iVar1 + 0x22,2);
    FUN_2424_1a04(iVar1 + 0x26,iVar1 + 0x2a,2);
  }
  return;
}

