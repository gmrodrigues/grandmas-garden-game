// TIM2.EXE: FUN_31f7_537f @ file 0x03C4EF Ghidra 0x372EF
// Subsystem: misc | Size: 223 bytes


void __cdecl16far FUN_31f7_537f(undefined4 param_1)

{
  int iVar1;
  int in_DX;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  *(undefined2 *)(iVar2 + 0x16) = 0;
  if ((*(int *)(iVar2 + 0xb4) != 0) &&
     (*(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + -1, *(int *)(iVar2 + 0xb4) != 0)) {
    *(undefined2 *)(iVar2 + 0x16) = 1;
  }
  iVar1 = FUN_28eb_3783(iVar2,uVar3);
  if ((iVar1 != 0 || in_DX != 0) && ((*(byte *)(iVar1 + 0xd) & 8) == 0)) {
    if (*(int *)(iVar2 + 0x16) == 0) {
      *(undefined2 *)(iVar1 + 0x16) = 0;
    }
    else if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
      *(undefined2 *)(iVar1 + 0x16) = 2;
    }
    else {
      *(undefined2 *)(iVar1 + 0x16) = 0xfffe;
    }
  }
  if (*(int *)(iVar2 + 0x16) == 0) {
    *(undefined2 *)(iVar2 + 0x10) = 0;
  }
  else {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    iVar1 = FUN_4551_0308(DAT_5b41_09fe,*(undefined2 *)(iVar2 + 0x10));
    if (iVar1 == -1) {
      if ((DAT_5b41_051f & 1) == 0) {
        *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -2;
      }
      else {
        *(undefined2 *)(iVar2 + 0x10) = 1;
      }
    }
  }
  if (*(int *)(iVar2 + 0x10) != *(int *)(iVar2 + 0x12)) {
    FUN_28eb_3328(iVar2,uVar3);
  }
  return;
}

