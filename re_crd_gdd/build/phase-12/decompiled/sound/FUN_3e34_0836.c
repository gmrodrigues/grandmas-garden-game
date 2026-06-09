// TIM2.EXE: FUN_3e34_0836 @ file 0x043D76 Ghidra 0x3EB76
// Subsystem: sound | Size: 185 bytes


int __cdecl16far FUN_3e34_0836(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    DAT_5b41_1ad2 = 2;
    return 0;
  }
  iVar1 = FUN_3f2b_0577(param_1,0x554c);
  iVar2 = FUN_3f2b_0811(iVar1);
  uVar3 = iVar2 - 1;
  if (uVar3 < 500) {
    FUN_3f2b_09ca(iVar1,1);
  }
  else {
    uVar3 = 0;
    while ((uVar3 < 500 && (*(int *)(uVar3 * 8 + 0x74) != 0))) {
      uVar3 = uVar3 + 1;
    }
    if (499 < uVar3) {
      DAT_5b41_1ad2 = 0xc;
      return 0;
    }
    iVar1 = FUN_3f2b_0220(param_1,0x554c,0,0,uVar3 + 1,0xa69,0x3e34);
    if (iVar1 == 0) {
      return 0;
    }
  }
  *(uint *)(uVar3 * 8 + 0x74) = param_2 | 8;
  if (DAT_5b41_1ae8 <= uVar3) {
    DAT_5b41_1ae8 = uVar3 + 1;
  }
  return iVar1;
}

