// TIM2.EXE: FUN_31f7_b45f @ file 0x0425CF Ghidra 0x3D3CF
// Subsystem: sound | Size: 391 bytes


void FUN_31f7_b45f(undefined2 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (int)((ulong)param_2 >> 0x10);
  iVar4 = (int)param_2;
  if (*(int *)(iVar4 + 0x16) == 0) {
    FUN_31f7_b5ec();
    return;
  }
  if (*(int *)(iVar4 + 0x16) < 3) {
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
    *(int *)(iVar4 + 0x16) = *(int *)(iVar4 + 0x16) + 1;
    *(undefined2 *)(iVar4 + 0xae) = 0x14;
    FUN_31f7_b5ec();
    return;
  }
  if (*(int *)(iVar4 + 0x10) < DAT_5b41_1aba) {
    *(int *)(iVar4 + 0xae) = *(int *)(iVar4 + 0xae) + -1;
    if (*(int *)(iVar4 + 0xae) == 0) {
      *(undefined2 *)(iVar4 + 0xae) = 0x14;
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 3;
      FUN_2e67_045f(0xc41,0,1,1);
      FUN_31f7_b5ec();
      return;
    }
    FUN_31f7_b5ec();
    return;
  }
  if (*(int *)(iVar4 + 0x10) != DAT_5b41_1abe) {
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
    iVar2 = *(int *)(iVar4 + 0x10) - DAT_5b41_1abc;
    if (iVar2 < 0) {
      FUN_31f7_b5ec();
      return;
    }
    if (iVar2 < 3) {
      if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
        iVar6 = *(int *)(iVar2 * 2 + 0x3d48) + 0x30;
        iVar2 = 0x30;
      }
      else {
        iVar6 = 0;
        iVar2 = -*(int *)(iVar2 * 2 + 0x3d48);
      }
      FUN_28eb_51b3(iVar4,iVar5,0x3000,iVar2,iVar6,0x10,0x24);
      iVar2 = iVar4;
      iVar6 = iVar5;
      while( true ) {
        iVar1 = *(int *)(iVar2 + 0x8e);
        iVar2 = *(int *)(iVar2 + 0x8c);
        if (iVar2 == 0 && iVar1 == 0) break;
        iVar6 = iVar1;
        if ((*(byte *)(iVar2 + 0xb) & 0x10) == 0) {
          iVar3 = *(int *)(iVar2 + 8);
          if (iVar3 == 6) {
            FUN_31f7_111e(iVar2,iVar1);
          }
          else if (iVar3 == 0xf) {
            FUN_31f7_1e38(iVar2,iVar1);
          }
          else if (iVar3 == 0x4e) {
            *(undefined2 *)(iVar2 + 0x16) = 1;
          }
        }
        else {
          iVar3 = FUN_31f7_b609(iVar2,iVar1);
          if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
            *(int *)(iVar2 + 0x3a) = iVar3;
          }
          else {
            *(int *)(iVar2 + 0x3a) = -iVar3;
          }
          if ((*(int *)(iVar2 + 8) == 0x36) && (*(int *)(iVar2 + 0x10) < DAT_5b41_09a3)) {
            *(int *)(iVar2 + 0x10) = DAT_5b41_09a3;
          }
        }
      }
      if (*(int *)(iVar4 + 0x10) != *(int *)(iVar4 + 0x12)) {
        FUN_28eb_3328(iVar4,iVar5);
      }
      return;
    }
    FUN_31f7_b5ec();
    return;
  }
  FUN_31f7_b5ec();
  return;
}

