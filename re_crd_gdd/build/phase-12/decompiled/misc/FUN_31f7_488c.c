// TIM2.EXE: FUN_31f7_488c @ file 0x03B9FC Ghidra 0x367FC
// Subsystem: misc | Size: 330 bytes


void __cdecl16far FUN_31f7_488c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if (*(int *)(iVar4 + 0x16) == 0) {
    if (((DAT_5b41_051f & 1) != 0) && (*(int *)(iVar4 + 8) == 0x25)) {
      if (*(int *)(iVar4 + 0x10) == 0) {
        DAT_554c_3b40 = DAT_554c_3b40 + -1;
        if (DAT_554c_3b40 < 1) {
          *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
          uVar3 = FUN_460e_1a42();
          DAT_554c_3b40 = uVar3 % 200 + 0x28;
        }
      }
      else {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
        if (*(int *)(iVar4 + 0x10) == DAT_5b41_19ee) {
          *(undefined2 *)(iVar4 + 0x10) = 0;
        }
      }
    }
  }
  else {
    if (((*(int *)(iVar4 + 8) == 0x4d) && (*(uint *)(iVar4 + 0x10) < DAT_5b41_19f8)) ||
       ((*(int *)(iVar4 + 8) == 0x25 && (*(uint *)(iVar4 + 0x10) < DAT_5b41_19ec)))) {
      if (*(int *)(iVar4 + 8) == 0x4d) {
        if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
          uVar6 = 0x3b30;
        }
        else {
          uVar6 = 0x3b38;
        }
        FUN_31f7_4a9d(iVar4,uVar5,uVar6);
        uVar3 = DAT_5b41_19f8;
      }
      else {
        if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
          uVar6 = 0x3b20;
        }
        else {
          uVar6 = 0x3b28;
        }
        FUN_31f7_4a9d(iVar4,uVar5,uVar6);
        uVar3 = DAT_5b41_19ec;
      }
      *(uint *)(iVar4 + 0x10) = uVar3;
      FUN_31f7_4793(iVar4,uVar5);
    }
    else {
      iVar1 = DAT_5b41_19fa;
      if (*(int *)(iVar4 + 8) == 0x25) {
        iVar1 = DAT_5b41_19f0;
      }
      if (*(int *)(iVar4 + 0x10) == iVar1) {
        return;
      }
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      iVar2 = FUN_4551_0308(*(undefined2 *)(*(int *)(iVar4 + 8) * 2 + 0x68fe),
                            *(undefined2 *)(iVar4 + 0x10));
      if (iVar2 != 0) {
        *(int *)(iVar4 + 0x10) = iVar1;
      }
    }
    FUN_28eb_3328(iVar4,uVar5);
  }
  return;
}

