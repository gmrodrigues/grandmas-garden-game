// TIM2.EXE: FUN_31f7_410e @ file 0x03B27E Ghidra 0x3607E
// Subsystem: misc | Size: 337 bytes


void __cdecl16far FUN_31f7_410e(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  iVar5 = (int)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((*(int *)(iVar3 + 0x16) != 0) && (*(int *)(iVar3 + 0x10) != DAT_5b41_19d8)) {
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    FUN_31f7_425f(iVar3,iVar5);
    FUN_28eb_3328(iVar3,iVar5);
  }
  if ((*(int *)(iVar3 + 0x10) == 4) || (*(int *)(iVar3 + 0x10) == 5)) {
    if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
      uVar8 = 0;
      uVar7 = ((undefined2 *)&DAT_554c_3ae6)[*(int *)(iVar3 + 0x10)];
    }
    else {
      uVar8 = ((undefined2 *)&DAT_554c_3aec)[*(int *)(iVar3 + 0x10)];
      uVar7 = 0x30;
    }
    FUN_28eb_51b3(iVar3,iVar5,0x3000,uVar7,uVar8,0,0x1f);
    iVar4 = iVar3;
    iVar6 = iVar5;
    while( true ) {
      iVar1 = *(int *)(iVar4 + 0x8e);
      iVar4 = *(int *)(iVar4 + 0x8c);
      if (iVar4 == 0 && iVar1 == 0) break;
      iVar6 = iVar1;
      if ((*(byte *)(iVar4 + 0xb) & 0x10) == 0) {
        iVar2 = *(int *)(iVar4 + 8);
        if (iVar2 == 6) {
          FUN_31f7_111e(iVar4,iVar1);
        }
        else if (iVar2 == 0xf) {
          FUN_31f7_1e38(iVar4,iVar1);
        }
        else if (iVar2 == 0x4e) {
          *(undefined2 *)(iVar4 + 0x16) = 1;
        }
      }
      else {
        iVar2 = FUN_31f7_4313(iVar4,iVar1);
        if ((*(byte *)(iVar3 + 0xc) & 0x10) == 0) {
          *(int *)(iVar4 + 0x3a) = -iVar2;
        }
        else {
          *(int *)(iVar4 + 0x3a) = iVar2;
        }
        if ((*(int *)(iVar4 + 8) == 0x36) && (*(int *)(iVar4 + 0x10) < DAT_5b41_09a3)) {
          *(int *)(iVar4 + 0x10) = DAT_5b41_09a3;
        }
      }
    }
  }
  return;
}

