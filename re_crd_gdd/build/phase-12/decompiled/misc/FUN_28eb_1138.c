// TIM2.EXE: FUN_28eb_1138 @ file 0x02F1E8 Ghidra 0x29FE8
// Subsystem: misc | Size: 156 bytes


int __cdecl16far FUN_28eb_1138(int *param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int in_DX;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  DAT_5b41_04f0 = 1;
  iVar1 = FUN_28eb_0ddb(param_2,param_3);
  if (iVar1 == 0 && in_DX == 0) {
    DAT_5b41_04f0 = 0;
    return iVar1;
  }
  if ((*(byte *)(iVar1 + 0xc) & 4) != 0) {
    if (((*(byte *)(iVar1 + 0xc) & 8) == 0) ||
       (iVar2 = *(int *)(iVar1 + 0x22) - DAT_5b41_0925,
       iVar3 = *(int *)(iVar1 + 0x24) - DAT_5b41_0927,
       uVar4 = DAT_5b41_1b84 - (iVar2 + *(char *)(iVar1 + 0x7a)), uVar8 = (int)uVar4 >> 0xf,
       uVar5 = DAT_5b41_1b86 - (iVar3 + *(char *)(iVar1 + 0x7b)), uVar9 = (int)uVar5 >> 0xf,
       uVar6 = DAT_5b41_1b84 - (iVar2 + *(char *)(iVar1 + 0x7c)), uVar10 = (int)uVar6 >> 0xf,
       uVar7 = DAT_5b41_1b86 - (iVar3 + *(char *)(iVar1 + 0x7d)), uVar11 = (int)uVar7 >> 0xf,
       (int)(((uVar4 ^ uVar8) - uVar8) + ((uVar5 ^ uVar9) - uVar9)) <
       (int)(((uVar6 ^ uVar10) - uVar10) + ((uVar7 ^ uVar11) - uVar11)))) {
      *param_1 = 0;
    }
    else {
      *param_1 = 1;
    }
    if (*(int *)(iVar1 + 8) == 7) {
      if (*(int *)(iVar1 + 0x5e) == 0 && *(int *)(iVar1 + 0x60) == 0) {
        DAT_5b41_04f0 = 0;
        return iVar1;
      }
    }
    else if (*(int *)(iVar1 + *param_1 * 2 + 0x76) == 0) {
      DAT_5b41_04f0 = 0;
      return iVar1;
    }
  }
  DAT_5b41_04f0 = 0;
  return 0;
}

