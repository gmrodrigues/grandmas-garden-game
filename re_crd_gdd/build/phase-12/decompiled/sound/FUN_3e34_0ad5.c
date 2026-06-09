// TIM2.EXE: FUN_3e34_0ad5 @ file 0x044015 Ghidra 0x3EE15
// Subsystem: sound | Size: 156 bytes


undefined2 __cdecl16far FUN_3e34_0ad5(undefined2 param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_3f2b_0811(param_1);
  uVar3 = iVar2 - 1;
  if ((uVar3 < 500) && (*(int *)(uVar3 * 8 + 0x74) != 0)) {
    if ((*(int *)(uVar3 * 8 + 0x70) != 0 || *(int *)(uVar3 * 8 + 0x72) != 0) ||
       (iVar2 = FUN_3e34_0959(param_1), iVar2 != 0)) {
      if (param_2 < *(uint *)(uVar3 * 8 + 0x76)) {
        uVar1 = *(undefined4 *)(uVar3 * 8 + 0x70);
        return *(undefined2 *)((int)uVar1 + param_2 * 4);
      }
      DAT_5b41_1ad2 = 0xe;
    }
    return 0;
  }
  DAT_5b41_1ad2 = 0xd;
  return 0;
}

