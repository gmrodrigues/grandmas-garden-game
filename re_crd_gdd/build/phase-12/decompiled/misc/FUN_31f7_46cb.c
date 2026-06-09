// TIM2.EXE: FUN_31f7_46cb @ file 0x03B83B Ghidra 0x3663B
// Subsystem: misc | Size: 200 bytes


undefined2 __cdecl16far FUN_31f7_46cb(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar4 + 0x9c);
  iVar2 = *(int *)(iVar4 + 0x9a);
  if ((*(int *)(iVar2 + 0x10) == 0) ||
     ((*(int *)(iVar2 + 8) == 0x25 && (*(uint *)(iVar2 + 0x10) < DAT_5b41_19ee)))) {
    iVar3 = *(int *)(iVar4 + 0xa2);
    if (((*(byte *)(iVar2 + 0xc) & 0x10) != 0) &&
       (iVar3 = (*(int *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x22) - iVar3) + -2, iVar3 < 0
       )) {
      iVar3 = iVar3 + *(int *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x22);
    }
    if ((((iVar3 == 0) || (iVar3 == 1)) || (iVar3 == 5)) || (iVar3 == 6)) {
      *(undefined2 *)(iVar2 + 0x16) = 1;
    }
    else if (iVar3 == 3) {
      if ((*(int *)(iVar4 + 8) == 4) || (*(int *)(iVar4 + 8) == 0x6d)) {
        *(undefined2 *)(iVar4 + 0x16) = 1;
      }
      else if (*(int *)(iVar4 + 8) == 0x4f) {
        *(undefined2 *)(iVar4 + 0x16) = 2;
      }
    }
  }
  return 1;
}

