// TIM2.EXE: FUN_31f7_8d55 @ file 0x03FEC5 Ghidra 0x3ACC5
// Subsystem: misc | Size: 169 bytes


void __cdecl16far FUN_31f7_8d55(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x16) != 0) {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x40;
    if (*(int *)(iVar1 + 0x10) == 0) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
      FUN_31f7_8cef(iVar1,uVar2);
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
    }
    if ((*(int *)(iVar1 + 0x10) < DAT_5b41_09a7) || ((DAT_5b41_051f & 1) != 0)) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
      if (*(int *)(iVar1 + 0x10) == DAT_5b41_1a72) {
        *(int *)(iVar1 + 0x10) = DAT_5b41_09a7;
      }
    }
    else if (*(int *)(iVar1 + 0x10) == 0x1c) {
      *(undefined2 *)(iVar1 + 0x10) = 0x1e;
    }
    else {
      *(undefined2 *)(iVar1 + 0x10) = 0x1c;
    }
    if (DAT_5b41_09a7 <= *(int *)(iVar1 + 0x10)) {
      FUN_553b_00b6(0x31f7,iVar1,uVar2,0x10,0x1e,0xfff4);
    }
    FUN_28eb_3328();
  }
  return;
}

