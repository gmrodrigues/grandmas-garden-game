// TIM2.EXE: FUN_3e34_0959 @ file 0x043E99 Ghidra 0x3EC99
// Subsystem: sound | Size: 272 bytes


undefined2 __cdecl16far FUN_3e34_0959(undefined2 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  int in_DX;
  int local_6;
  int local_4;
  
  iVar2 = FUN_3f2b_0811(param_1);
  uVar3 = iVar2 - 1;
  if ((uVar3 < 500) && (*(int *)(uVar3 * 8 + 0x74) != 0)) {
    if (*(int *)(uVar3 * 8 + 0x70) == 0 && *(int *)(uVar3 * 8 + 0x72) == 0) {
      iVar2 = FUN_3f2b_0718(param_1);
      if (iVar2 == 0) {
        DAT_5b41_1ad2 = 0xd;
        uVar4 = 0;
      }
      else {
        local_4 = 0;
        local_6 = 0;
        uVar1 = *(uint *)(uVar3 * 8 + 0x74);
        do {
          if (local_6 != 0 || local_4 != 0) {
            *(int *)(uVar3 * 8 + 0x72) = local_4;
            *(int *)(uVar3 * 8 + 0x70) = local_6;
            uVar4 = FUN_3e34_013c(local_6,local_4);
            *(undefined2 *)(uVar3 * 8 + 0x76) = uVar4;
            goto LAB_3e34_0a62;
          }
          uVar4 = FUN_3f2b_0718(param_1);
          local_6 = FUN_3e34_000e(uVar4,uVar1 & 0xfff7);
          local_4 = in_DX;
        } while ((local_6 != 0 || in_DX != 0) ||
                (((DAT_5b41_1ad2 != 2 && (DAT_5b41_1ad2 != 4)) &&
                 (iVar2 = FUN_3f2b_0aa7(), iVar2 != 0))));
        uVar4 = 0;
      }
    }
    else {
LAB_3e34_0a62:
      uVar4 = 1;
    }
  }
  else {
    DAT_5b41_1ad2 = 0xd;
    uVar4 = 0;
  }
  return uVar4;
}

