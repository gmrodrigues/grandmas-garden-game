// TIM2.EXE: FUN_31f7_925f @ file 0x0403CF Ghidra 0x3B1CF
// Subsystem: gfx | Size: 432 bytes


void __cdecl16far FUN_31f7_925f(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (int)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x10) < DAT_5b41_0999) {
    iVar4 = 0;
  }
  else if (*(int *)(iVar2 + 0x10) < DAT_5b41_099b) {
    iVar4 = 1;
  }
  else {
    iVar4 = 2;
  }
  if ((*(int *)(iVar2 + 0x16) == 0) && (0x14 < *(int *)(iVar2 + 0xb4))) {
    *(undefined2 *)(iVar2 + 0x16) = 1;
  }
  if (*(int *)(iVar2 + 0x16) != 0) {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_1a88)[iVar4]) {
      *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_1a82)[iVar4];
    }
    if (*(int *)(iVar2 + 0x10) < (int)((undefined2 *)&DAT_5b41_1a88)[iVar4]) {
      if ((int)((undefined2 *)&DAT_5b41_0993)[iVar4] <= *(int *)(iVar2 + 0x10)) {
        *(undefined2 *)(iVar2 + 0x9c) = 0;
        *(undefined2 *)(iVar2 + 0x9a) = 0;
        *(int *)(iVar2 + 0x3c) = *(int *)(iVar2 + 0x3c) + -0x800;
        if (*(int *)(iVar2 + 0x3c) < -0x2000) {
          *(undefined2 *)(iVar2 + 0x3c) = 0xe000;
        }
        if (*(int *)(iVar2 + 0x24) < 0x28) {
          *(undefined2 *)(iVar2 + 0x24) = 0x27;
          *(undefined2 *)(iVar2 + 0x16) = 0x28;
        }
        *(int *)(iVar2 + 0x16) = *(int *)(iVar2 + 0x16) + 1;
        if (0x14 < *(int *)(iVar2 + 0x16)) {
          *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_1a88)[iVar4];
        }
        FUN_553b_00b6(0x31f7,iVar2,iVar5,5,0x15,0x38);
      }
    }
    else {
      FUN_28eb_3328(iVar2,iVar5);
      FUN_28eb_4f3d(iVar2,iVar5,0x1000,0xfff6,10,0xfff6,10);
      iVar3 = iVar2;
      iVar6 = iVar5;
      while( true ) {
        iVar1 = *(int *)(iVar3 + 0x8e);
        iVar3 = *(int *)(iVar3 + 0x8c);
        if (iVar3 == 0 && iVar1 == 0) break;
        iVar6 = iVar1;
        if (*(int *)(iVar3 + 8) == 6) {
          FUN_31f7_111e(iVar3,iVar1);
        }
      }
      *(undefined2 *)(iVar2 + 0x3c) = 0;
      *(undefined2 *)(iVar2 + 0x3a) = 0;
      if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_0999)[iVar4]) {
        *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
        FUN_2424_0f94(iVar2,iVar5,3);
        *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x2000;
      }
    }
    FUN_28eb_3328(iVar2);
  }
  return;
}

