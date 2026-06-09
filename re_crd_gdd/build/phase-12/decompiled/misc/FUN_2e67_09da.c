// TIM2.EXE: FUN_2e67_09da @ file 0x03424A Ghidra 0x2F04A
// Subsystem: misc | Size: 69 bytes


void __cdecl16far FUN_2e67_09da(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 local_6;
  
  if (DAT_5b41_0bec != 0) {
    local_6 = &DAT_5b41_0c48;
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      uVar3 = (undefined2)((ulong)local_6 >> 0x10);
      puVar1 = (undefined2 *)local_6;
      if ((puVar1[3] == 0) || (puVar1[3] == 1)) {
        *local_6 = 0;
      }
      local_6 = (undefined2 *)CONCAT22(uVar3,puVar1 + 4);
    }
    FUN_2e67_0a1f();
  }
  return;
}

