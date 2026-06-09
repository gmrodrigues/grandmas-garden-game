// TIM2.EXE: FUN_460e_194a @ file 0x04CC2A Ghidra 0x47A2A
// Subsystem: misc | Size: 206 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far FUN_460e_194a(uint param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int in_DX;
  undefined4 local_a;
  int local_6;
  int iStack_4;
  
  uVar2 = FUN_460e_0f42(0,0,0x20);
  local_6 = FUN_460e_141e(uVar2,in_DX);
  local_a = 0;
  iStack_4 = in_DX;
  while( true ) {
    if (local_6 == 0 && iStack_4 == 0) break;
    if ((param_1 <= *(uint *)(local_6 + 0x10)) &&
       (((int)local_a == 0 && local_a._2_2_ == 0 ||
        (*(uint *)((int)local_a + 0x10) < *(uint *)(local_6 + 0x10))))) {
      local_a = CONCAT22(iStack_4,local_6);
    }
    piVar1 = (int *)(local_6 + 10);
    local_6 = *(int *)(local_6 + 8);
    iStack_4 = *piVar1;
  }
  if (((int)local_a != 0 || local_a._2_2_ != 0) && ((*(byte *)((int)local_a + 0x24) & 8) == 0)) {
    FUN_406b_0c62(*(int *)((int)local_a + 0x14) + *(int *)((int)local_a + 0x18) / 2,
                  *(int *)((int)local_a + 0x16) + *(int *)((int)local_a + 0x1a) / 2);
    FUN_406b_0a39();
    _DAT_5b41_1b88 = 2;
    return *(undefined2 *)((int)local_a + 0xc);
  }
  return 0;
}

