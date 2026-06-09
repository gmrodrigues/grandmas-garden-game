// TIM2.EXE: FUN_2321_0bd2 @ file 0x028FE2 Ghidra 0x23DE2
// Subsystem: misc | Size: 81 bytes


undefined2 * __cdecl16far FUN_2321_0bd2(void)

{
  int *piVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *local_a;
  undefined4 local_6;
  
  puVar2 = DAT_5b41_04fd;
  local_6 = (undefined2 *)CONCAT22(DAT_5b41_04ff,DAT_5b41_04fd);
  if (DAT_5b41_04fd != (undefined2 *)0x0 || DAT_5b41_04ff != 0) {
    piVar1 = DAT_5b41_04fd + 1;
    local_a = (undefined2 *)CONCAT22(DAT_5b41_04ff,DAT_5b41_04fd);
    DAT_5b41_04fd = (undefined2 *)*local_6;
    DAT_5b41_04ff = *piVar1;
    for (iVar3 = 0xba; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)local_a = 0;
      local_a = (undefined2 *)CONCAT22(local_a._2_2_,(undefined2 *)((int)(undefined2 *)local_a + 1))
      ;
    }
  }
  return puVar2;
}

