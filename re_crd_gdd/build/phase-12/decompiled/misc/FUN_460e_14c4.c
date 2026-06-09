// TIM2.EXE: FUN_460e_14c4 @ file 0x04C7A4 Ghidra 0x475A4
// Subsystem: misc | Size: 185 bytes


bool __cdecl16far FUN_460e_14c4(undefined2 param_1,undefined2 param_2,code *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int extraout_DX;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_5b41_1ae4;
  iVar1 = DAT_5b41_1ae2;
  iVar3 = DAT_5b41_1ae4;
  if ((DAT_5b41_1ae2 != 0 || DAT_5b41_1ae4 != 0) &&
     (*(int *)(DAT_5b41_1ae2 + 0x20) != 0 || *(int *)(DAT_5b41_1ae2 + 0x22) != 0)) {
    uVar4 = (*(code *)*(undefined2 *)(DAT_5b41_1ae2 + 0x20))(0x460e,DAT_5b41_1ae2,DAT_5b41_1ae4,2);
    iVar3 = (int)((ulong)uVar4 >> 0x10);
    if (((int)uVar4 == 2) && (param_3 != (code *)0x0 || param_4 != 0)) {
      (*param_3)(0x460e,*(undefined2 *)(iVar1 + 0xc));
      iVar3 = extraout_DX;
    }
  }
  if (DAT_5b41_1ae2 != 0 || DAT_5b41_1ae4 != 0) {
    return false;
  }
  iVar1 = FUN_460e_0f42(param_1);
  DAT_5b41_1ae6 = param_2;
  if ((((iVar1 != 0 || iVar3 != 0) && (*(int *)(iVar1 + 0x20) != 0 || *(int *)(iVar1 + 0x22) != 0))
      && (iVar2 = (*(code *)*(undefined2 *)(iVar1 + 0x20))(0x460e,iVar1,iVar3,3), iVar2 == 2)) &&
     (param_3 != (code *)0x0 || param_4 != 0)) {
    (*param_3)(0x460e,*(undefined2 *)(iVar1 + 0xc));
  }
  return DAT_5b41_1ae2 != 0 || DAT_5b41_1ae4 != 0;
}

