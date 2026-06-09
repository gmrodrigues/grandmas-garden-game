// TIM2.EXE: FUN_31f7_39ff @ file 0x03AB6F Ghidra 0x3596F
// Subsystem: misc | Size: 172 bytes


undefined2 __cdecl16far FUN_31f7_39ff(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar4 + 0x9c);
  iVar3 = *(int *)(iVar4 + 0x9a);
  iVar2 = *(int *)(iVar4 + 0xa2);
  if ((*(byte *)(iVar3 + 0xc) & 0x10) != 0) {
    iVar2 = (*(int *)(iRam00055800 + 0x22) - iVar2) + -2;
    if (iVar2 < 0) {
      iVar2 = iVar2 + *(int *)(iRam00055800 + 0x22);
    }
  }
  if (*(int *)(iVar3 + 0xae) == 0) {
    if (iVar2 < 5) {
      *(undefined2 *)(iVar3 + 0xae) = 0x30;
      *(undefined2 *)(iVar3 + 0x16) = 0;
      if (*(int *)(iVar3 + 0x10) < DAT_5b41_19cc) {
        *(undefined2 *)(iVar3 + 0x10) = DAT_5b41_19d4;
      }
      else {
        *(int *)(iVar3 + 0x10) = DAT_5b41_19d2;
      }
    }
    else if (iVar2 == 5) {
      if ((DAT_5b41_19ce <= *(int *)(iVar3 + 0x10)) && (*(int *)(iVar3 + 0x10) < DAT_5b41_19d2)) {
        if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
          iVar3 = -0x800;
        }
        else {
          iVar3 = 0x800;
        }
        *(int *)(iVar4 + 0x3a) = *(int *)(iVar4 + 0x3a) + iVar3;
      }
    }
  }
  return 1;
}

