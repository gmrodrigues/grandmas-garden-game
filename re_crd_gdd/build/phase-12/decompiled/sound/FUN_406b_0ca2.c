// TIM2.EXE: FUN_406b_0ca2 @ file 0x046552 Ghidra 0x41352
// Subsystem: sound | Size: 113 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_406b_0ca2(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined4 local_6;
  
  local_6 = &DAT_53bd_0028;
  for (iVar1 = 2; iVar1 != 0; iVar1 = iVar1 + -1) {
    uVar3 = (undefined2)((ulong)local_6 >> 0x10);
    puVar2 = (undefined2 *)local_6;
    *local_6 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    local_6 = (undefined2 *)CONCAT22(uVar3,puVar2 + 4);
  }
  DAT_53bd_0050 = 0;
  DAT_53bd_004e = 0;
  DAT_5b41_1b8a = 0;
  _DAT_5b41_1b88 = 0;
  _DAT_53bd_004a = 0;
  return;
}

