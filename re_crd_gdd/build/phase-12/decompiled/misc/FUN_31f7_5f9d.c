// TIM2.EXE: FUN_31f7_5f9d @ file 0x03D10D Ghidra 0x37F0D
// Subsystem: misc | Size: 274 bytes


void __cdecl16far FUN_31f7_5f9d(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((*(int *)(iVar3 + 0x16) == 0) && (0x14 < *(int *)(iVar3 + 0xb4))) {
    *(undefined2 *)(iVar3 + 0x16) = 1;
  }
  if (*(int *)(iVar3 + 0x16) == 0) {
    if ((DAT_5b41_051f & 1) != 0) {
      if (*(int *)(iVar3 + 0x10) == 0) {
        DAT_554c_3b68 = DAT_554c_3b68 + -1;
        if (0 < DAT_554c_3b68) {
          return;
        }
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
        uVar2 = FUN_460e_1a42();
        DAT_554c_3b68 = uVar2 % 200 + 0x28;
      }
      else {
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
        if (*(int *)(iVar3 + 0x10) == DAT_5b41_1a14) {
          *(undefined2 *)(iVar3 + 0x10) = 0;
        }
      }
      FUN_28eb_3328(iVar3,uVar4);
    }
    return;
  }
  if ((DAT_5b41_051f & 1) == 0) {
    if (*(int *)(iVar3 + 0x10) == 4) {
      *(undefined2 *)(iVar3 + 0x10) = 6;
    }
    else {
      *(undefined2 *)(iVar3 + 0x10) = 4;
    }
  }
  else {
    if (DAT_5b41_1a14 <= *(int *)(iVar3 + 0x10)) {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
      iVar1 = FUN_4551_0308(DAT_5b41_0a08,*(undefined2 *)(iVar3 + 0x10));
      if (iVar1 != -1) goto LAB_31f7_6019;
    }
    *(int *)(iVar3 + 0x10) = DAT_5b41_1a14;
  }
LAB_31f7_6019:
  FUN_28eb_3328(iVar3,uVar4);
  if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
    uVar6 = 0x37;
    uVar5 = 0x28;
  }
  else {
    uVar6 = 10;
    uVar5 = 0xfffb;
  }
  FUN_553b_00b6(0x28eb,iVar3,uVar4,uVar5,uVar6,0xffe8);
  return;
}

