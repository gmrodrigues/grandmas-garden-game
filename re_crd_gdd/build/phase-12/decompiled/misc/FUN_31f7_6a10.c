// TIM2.EXE: FUN_31f7_6a10 @ file 0x03DB80 Ghidra 0x38980
// Subsystem: misc | Size: 260 bytes


void __cdecl16far FUN_31f7_6a10(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_1a24 == 0) {
    DAT_5b41_1a20 = FUN_4551_0370(DAT_5b41_0a1a,0x14);
    DAT_5b41_1a22 = FUN_4551_0370(DAT_5b41_0a1a,0x19);
    DAT_5b41_1a24 = FUN_4551_0370(DAT_5b41_0a1a,3);
    DAT_5b41_1a26 = FUN_4551_0370(DAT_5b41_0a1a,0xf);
    DAT_5b41_1a28 = FUN_4551_0370(DAT_5b41_0a1a,0x10);
    DAT_5b41_09a3 = FUN_4551_0370(DAT_5b41_0a1a,8);
    DAT_5b41_1a2a = FUN_4551_0370(DAT_5b41_0a1a,9);
    DAT_5b41_1a2c = FUN_4551_0370(DAT_5b41_0a1a,0xb);
    DAT_5b41_1a2e = FUN_4551_0370(DAT_5b41_0a1a,0x33);
    DAT_5b41_1a30 = FUN_4551_0370(DAT_5b41_0a1a,0xffff);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0x10);
  *(int *)(iVar2 + 0xae) = iVar1;
  *(undefined2 *)(iVar2 + 0x16) = 0;
  *(undefined2 *)(iVar2 + 0x98) =
       *(undefined2 *)
        (*(int *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46) +
        (uint)(iVar1 == DAT_5b41_1a30) * 2);
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

