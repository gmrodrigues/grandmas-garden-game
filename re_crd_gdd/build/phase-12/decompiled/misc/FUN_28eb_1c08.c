// TIM2.EXE: FUN_28eb_1c08 @ file 0x02FCB8 Ghidra 0x2AAB8
// Subsystem: misc | Size: 175 bytes


undefined2 __cdecl16far FUN_28eb_1c08(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int local_a;
  int iStack_8;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 6);
  if (iVar1 == 0 && iVar3 == 0) {
    DAT_5b41_04f0 = 2;
    iVar1 = FUN_28eb_0ddb(0,0);
    if (((iVar1 != 0 || iVar3 != 0) && ((*(byte *)(iVar1 + 0xc) & 2) == 0)) &&
       ((*(byte *)(iVar1 + 0xc) & 1) != 0)) {
      DAT_5b41_04f0 = 0;
      return 1;
    }
    DAT_5b41_04f0 = 0;
    return 0;
  }
  iStack_8 = *(int *)(param_1 + 0xc);
  local_a = *(int *)(param_1 + 10);
  if (local_a == 0 && iStack_8 == 0) {
    DAT_5b41_04f0 = 2;
    local_a = FUN_28eb_0ddb(0,0);
    DAT_5b41_04f0 = 0;
    if (local_a == 0 && iStack_8 == 0) {
      DAT_5b41_04f0 = 0;
      return 0;
    }
    if ((*(byte *)(local_a + 0xc) & 2) != 0) {
      DAT_5b41_04f0 = 0;
      return 0;
    }
    if ((*(byte *)(local_a + 0xc) & 1) == 0) {
      DAT_5b41_04f0 = 0;
      return 0;
    }
  }
  uVar2 = FUN_28eb_1b82(iVar1,iVar3,local_a,iStack_8);
  return uVar2;
}

