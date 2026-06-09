// TIM2.EXE: FUN_460e_174c @ file 0x04CA2C Ghidra 0x4782C
// Subsystem: misc | Size: 355 bytes


int __cdecl16far FUN_460e_174c(int param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int in_DX;
  int iVar3;
  
  if (param_1 == 0) {
    param_1 = DAT_5b41_1c1e;
  }
  if (param_1 == 0) {
    param_1 = FUN_460e_18af(0,0);
  }
  if (param_1 == 0) {
    param_1 = DAT_5408_0000;
  }
  for (iVar3 = 0; (iVar3 < 0x200 && (*(int *)(iVar3 * 2) != param_1)); iVar3 = iVar3 + 1) {
  }
  if (iVar3 < 0x200) {
    if (param_2 != 0) {
      if (param_2 < 0) {
        iVar2 = -1;
      }
      else {
        iVar2 = 1;
      }
      do {
        iVar3 = iVar3 + iVar2;
        if (iVar3 < 0) {
          do {
            iVar3 = iVar3 + 1;
            if (0x1fd < iVar3) break;
          } while (*(int *)(iVar3 * 2 + 2) != 0);
        }
        else if ((iVar3 == 0x200) || (*(int *)(iVar3 * 2) == 0)) {
          iVar3 = 0;
        }
      } while ((*(int *)(iVar3 * 2) != param_1) &&
              (((iVar1 = FUN_460e_0f42(*(undefined2 *)(iVar3 * 2)), iVar1 == 0 && in_DX == 0 ||
                (*(uint *)(iVar1 + 0x10) < param_3)) || ((*(byte *)(iVar1 + 0x24) & 8) != 0))));
    }
    DAT_5b41_1c1e = *(int *)(iVar3 * 2);
    iVar3 = DAT_5b41_1c1e;
    if ((((param_4 != 0) &&
         (iVar2 = FUN_460e_0f42(DAT_5b41_1c1e), iVar3 = DAT_5b41_1c1e, iVar2 != 0 || in_DX != 0)) &&
        (param_3 <= *(uint *)(iVar2 + 0x10))) && ((*(byte *)(iVar2 + 0x24) & 8) == 0)) {
      FUN_406b_0c62(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x18) / 2,
                    *(int *)(iVar2 + 0x16) + *(int *)(iVar2 + 0x1a) / 2);
      iVar3 = DAT_5b41_1c1e;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

