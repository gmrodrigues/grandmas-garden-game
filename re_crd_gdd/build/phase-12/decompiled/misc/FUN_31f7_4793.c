// TIM2.EXE: FUN_31f7_4793 @ file 0x03B903 Ghidra 0x36703
// Subsystem: misc | Size: 249 bytes


void __cdecl16far FUN_31f7_4793(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_19ec == 0) {
    DAT_5b41_19f2 = FUN_4551_0370(DAT_5b41_09f8,8);
    DAT_5b41_19ee = FUN_4551_0370(DAT_5b41_09f8,0xb);
    DAT_5b41_19ec = FUN_4551_0370(DAT_5b41_09f8,3);
    DAT_5b41_19f0 = FUN_4551_0370(DAT_5b41_09f8,4);
    DAT_5b41_19f4 = FUN_4551_0370(DAT_5b41_09f8,9);
    DAT_5b41_19f6 = FUN_4551_0370(DAT_5b41_0a48,5);
    DAT_5b41_19f8 = FUN_4551_0370(DAT_5b41_0a48,6);
    DAT_5b41_19fa = FUN_4551_0370(DAT_5b41_0a48,3);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 2;
  }
  if (*(int *)(iVar2 + 8) == 0x25) {
    if (*(uint *)(iVar2 + 0x10) <= DAT_5b41_19ee) goto LAB_31f7_485d;
  }
  else if (*(int *)(iVar2 + 0x10) == 0) goto LAB_31f7_485d;
  iVar1 = iVar1 + 1;
LAB_31f7_485d:
  *(undefined2 *)(iVar2 + 0x98) =
       *(undefined2 *)(*(int *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46) + iVar1 * 2);
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

