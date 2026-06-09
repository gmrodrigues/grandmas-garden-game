// TIM2.EXE: FUN_31f7_7ff2 @ file 0x03F162 Ghidra 0x39F62
// Subsystem: misc | Size: 412 bytes


void __cdecl16far FUN_31f7_7ff2(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = (uint)(DAT_5b41_0989 <= *(int *)(iVar2 + 0xa8)) +
          (uint)(DAT_5b41_098b <= *(int *)(iVar2 + 0xa8));
  if ((*(int *)(iVar2 + 0x16) == 0) && (0x14 < *(int *)(iVar2 + 0xb4))) {
    *(undefined2 *)(iVar2 + 0x16) = 1;
  }
  if (*(int *)(iVar2 + 0x16) != 0) {
    if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_1a64)[iVar1]) {
      FUN_2424_0f94(iVar2,uVar3,3);
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x2000;
    }
    else {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
      if (*(int *)(iVar2 + 0x10) == ((undefined2 *)&DAT_5b41_1a64)[iVar1]) {
        *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_1a5e)[iVar1];
      }
      if (*(int *)(iVar2 + 0x16) < 2) {
        if ((((int)((undefined2 *)&DAT_5b41_1a5e)[iVar1] <= *(int *)(iVar2 + 0x10)) &&
            (*(int *)(iVar2 + 0x9a) != 0 || *(int *)(iVar2 + 0x9c) != 0)) &&
           ((*(byte *)(iVar2 + 10) & 1) == 0)) {
          FUN_31f7_8315(iVar2,uVar3);
        }
      }
      else {
        *(int *)(iVar2 + 0x16) = *(int *)(iVar2 + 0x16) + -1;
      }
      if ((int)((undefined2 *)&DAT_5b41_098d)[iVar1] <= *(int *)(iVar2 + 0x10)) {
        if (iVar1 == 0) {
          *(undefined2 *)(iVar2 + 0x9c) = 0;
          *(undefined2 *)(iVar2 + 0x9a) = 0;
          *(int *)(iVar2 + 0x3c) = *(int *)(iVar2 + 0x3c) + -0x400;
        }
        else if (iVar1 == 1) {
          *(int *)(iVar2 + 0x3a) = *(int *)(iVar2 + 0x3a) + 0x400;
        }
        else if (iVar1 == 2) {
          *(int *)(iVar2 + 0x3a) = *(int *)(iVar2 + 0x3a) + -0x400;
        }
        FUN_549b_007a(0x31f7,iVar2,uVar3);
      }
      FUN_28eb_3328(iVar2,uVar3);
      if ((int)((undefined2 *)&DAT_5b41_098d)[iVar1] <= *(int *)(iVar2 + 0x10)) {
        FUN_553b_00b6(0x28eb,iVar2,uVar3,*(undefined2 *)(iVar1 * 8 + 0x3bf8),
                      *(undefined2 *)(iVar1 * 8 + 0x3bfa),*(undefined2 *)(iVar1 * 8 + 0x3bfc));
      }
    }
  }
  return;
}

