// TIM2.EXE: FUN_31f7_436d @ file 0x03B4DD Ghidra 0x362DD
// Subsystem: misc | Size: 467 bytes


uint __cdecl16far FUN_31f7_436d(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((*(int *)(iVar3 + 0x16) == 0) && (0x14 < *(int *)(iVar3 + 0xb4))) {
    *(undefined2 *)(iVar3 + 0x16) = 1;
  }
  uVar1 = (uint)(DAT_5b41_097f <= *(int *)(iVar3 + 0xa8));
  uVar2 = (DAT_5b41_097d <= *(int *)(iVar3 + 0xa8)) + uVar1;
  if (*(int *)(iVar3 + 0x16) == 0) {
    if ((DAT_5b41_051f & 1) != 0) {
      uVar1 = *(uint *)(iVar3 + 0x10);
      if (uVar1 != ((undefined2 *)&DAT_5b41_097b)[uVar2]) {
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
        uVar1 = *(uint *)(iVar3 + 0x10);
        if (uVar1 == ((undefined2 *)&DAT_5b41_19da)[uVar2]) {
          uVar1 = ((undefined2 *)&DAT_5b41_097b)[uVar2];
          *(uint *)(iVar3 + 0x10) = uVar1;
        }
      }
      DAT_554c_3afa = DAT_554c_3afa + -1;
      if (DAT_554c_3afa < 1) {
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
        uVar2 = FUN_460e_1a42();
        uVar1 = uVar2 / 200;
        DAT_554c_3afa = uVar2 % 200 + 0x28;
      }
    }
  }
  else {
    if (*(int *)(iVar3 + 0x10) < (int)((undefined2 *)&DAT_5b41_19da)[uVar2]) {
      *(undefined2 *)(iVar3 + 0x10) = ((undefined2 *)&DAT_5b41_19da)[uVar2];
    }
    else {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    }
    if (*(int *)(iVar3 + 0x10) == ((undefined2 *)&DAT_5b41_19e6)[uVar2]) {
      if ((DAT_5b41_051f & 1) == 0) {
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -2;
      }
      else {
        *(undefined2 *)(iVar3 + 0x10) = ((undefined2 *)&DAT_5b41_19e0)[uVar2];
      }
    }
    if ((int)((undefined2 *)&DAT_5b41_0981)[uVar2] <= *(int *)(iVar3 + 0x10)) {
      if (uVar2 == 0) {
        *(undefined2 *)(iVar3 + 0x9c) = 0;
        *(undefined2 *)(iVar3 + 0x9a) = 0;
        *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x3c) + -0x400;
      }
      else if (uVar2 == 1) {
        *(int *)(iVar3 + 0x3a) = *(int *)(iVar3 + 0x3a) + 0x400;
      }
      else if (uVar2 == 2) {
        *(int *)(iVar3 + 0x3a) = *(int *)(iVar3 + 0x3a) + -0x400;
      }
      FUN_549b_007a(0x31f7,iVar3,uVar4);
    }
    FUN_28eb_3328(iVar3,uVar4);
    uVar1 = *(uint *)(iVar3 + 0x10);
    if ((int)((undefined2 *)&DAT_5b41_0981)[uVar2] <= (int)uVar1) {
      if (uVar2 == 0) {
        uVar7 = 0x3c;
        uVar6 = 0x31;
        uVar5 = 0x22;
      }
      else if (uVar2 == 1) {
        uVar7 = 0x23;
        uVar6 = 0x17;
        uVar5 = 0xfff6;
      }
      else {
        if (uVar2 != 2) {
          return uVar2;
        }
        uVar7 = 0x22;
        uVar6 = 0x60;
        uVar5 = 0x3c;
      }
      uVar1 = FUN_553b_00b6(0x28eb,iVar3,uVar4,uVar5,uVar6,uVar7);
    }
  }
  return uVar1;
}

