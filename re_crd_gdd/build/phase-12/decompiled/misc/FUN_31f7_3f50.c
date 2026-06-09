// TIM2.EXE: FUN_31f7_3f50 @ file 0x03B0C0 Ghidra 0x35EC0
// Subsystem: misc | Size: 206 bytes


undefined2 __cdecl16far FUN_31f7_3f50(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  int local_a;
  undefined2 uStack_8;
  int local_6;
  undefined2 uStack_4;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 8) == 0x21) {
    *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) ^ 0x10;
    FUN_31f7_3f13(iVar2,uVar3);
    uVar1 = *(int *)(iVar2 + 0xa0) + 0x8000;
    local_a = *(int *)(iVar2 + 0x9a);
    uStack_8 = *(undefined2 *)(iVar2 + 0x9c);
    local_6 = iVar2;
    uStack_4 = uVar3;
  }
  else {
    uStack_4 = *(undefined2 *)(iVar2 + 0x9c);
    local_6 = *(int *)(iVar2 + 0x9a);
    uVar1 = *(uint *)(iVar2 + 0xa0);
    local_a = iVar2;
    uStack_8 = uVar3;
  }
  if (((*(int *)(local_a + 8) == 4) || (*(int *)(local_a + 8) == 0x4f)) ||
     (*(int *)(local_a + 8) == 0x6d)) {
    if ((*(byte *)(local_6 + 0xc) & 0x10) == 0) {
      if ((uVar1 & 0x8000) == 0) {
        return 1;
      }
      iVar2 = *(int *)(local_a + 8);
    }
    else {
      if ((uVar1 & 0x8000) != 0) {
        return 1;
      }
      iVar2 = *(int *)(local_a + 8);
    }
    if (iVar2 == 0x4f) {
      *(undefined2 *)(local_a + 0x16) = 2;
    }
    else {
      *(undefined2 *)(local_a + 0x16) = 1;
    }
  }
  return 1;
}

