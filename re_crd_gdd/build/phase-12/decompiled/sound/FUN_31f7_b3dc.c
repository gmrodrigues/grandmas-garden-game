// TIM2.EXE: FUN_31f7_b3dc @ file 0x04254C Ghidra 0x3D34C
// Subsystem: sound | Size: 131 bytes


void __cdecl16far FUN_31f7_b3dc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_1aba == 0) {
    DAT_5b41_1aba = FUN_4551_0370(DAT_5b41_0ac0,0x23);
    iVar1 = FUN_4551_0370(DAT_5b41_0ac0,0x13);
    DAT_5b41_1abc = iVar1 + 1;
    DAT_5b41_1abe = FUN_4551_0370(DAT_5b41_0ac0,0x14);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if ((*(byte *)(iVar1 + 0xc) & 0x10) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 2;
  }
  if (*(int *)(iVar1 + 0x16) != 0) {
    iVar2 = iVar2 + 1;
  }
  *(undefined2 *)(iVar1 + 0x98) = *(undefined2 *)(iVar2 * 2 + *(int *)(DAT_554c_0414 + 0x46));
  FUN_28eb_3670(iVar1,uVar3);
  return;
}

