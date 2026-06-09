// TIM2.EXE: FUN_31f7_0f78 @ file 0x0380E8 Ghidra 0x32EE8
// Subsystem: misc | Size: 351 bytes


void __cdecl16far FUN_31f7_0f78(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int in_DX;
  int iVar3;
  int iVar4;
  int local_6;
  int iStack_4;
  
  iVar4 = (int)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if (*(int *)(iVar3 + 0x16) == 0) {
    FUN_28eb_4f3d(iVar3,iVar4,0x1000,0xfff0,0x10,0,0);
    local_6 = iVar3;
    iStack_4 = iVar4;
    do {
      in_DX = *(int *)(local_6 + 0x8e);
      local_6 = *(int *)(local_6 + 0x8c);
      iStack_4 = in_DX;
      while( true ) {
        if (local_6 == 0 && iStack_4 == 0) goto LAB_31f7_0fe3;
        if (*(int *)(local_6 + 8) != 0xc) break;
        FUN_31f7_111e(iVar3,iVar4);
        local_6 = 0;
        iStack_4 = 0;
      }
    } while( true );
  }
LAB_31f7_0fe3:
  iVar1 = FUN_28eb_3783(iVar3,iVar4);
  if ((iVar1 != 0 || in_DX != 0) && ((*(byte *)(iVar1 + 0xd) & 8) == 0)) {
    *(int *)(iVar1 + 0x16) = *(int *)(iVar3 + 0x16) * 2;
  }
  if (*(int *)(iVar3 + 0x16) == 0) {
    if ((DAT_5b41_051f & 1) == 0) goto LAB_31f7_10bc;
    if (*(int *)(iVar3 + 0x10) == 0) {
      DAT_554c_3a30 = DAT_554c_3a30 + -1;
      if (DAT_554c_3a30 < 1) {
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
        uVar2 = FUN_460e_1a42();
        DAT_554c_3a30 = uVar2 % 200 + 0x28;
      }
      goto LAB_31f7_10bc;
    }
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    if (*(int *)(iVar3 + 0x10) != DAT_5b41_1976) goto LAB_31f7_10bc;
  }
  else {
    if (*(int *)(iVar3 + 0x10) < DAT_5b41_1976) {
LAB_31f7_1041:
      *(int *)(iVar3 + 0x10) = DAT_5b41_1976;
    }
    else {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
      if (*(int *)(iVar3 + 0x10) == DAT_5b41_1978) {
        if ((DAT_5b41_051f & 1) != 0) goto LAB_31f7_1041;
        *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -2;
      }
    }
    *(int *)(iVar3 + 0xae) = *(int *)(iVar3 + 0xae) + -1;
    if (*(int *)(iVar3 + 0xae) != 0) goto LAB_31f7_10bc;
    *(undefined2 *)(iVar3 + 0x16) = 0;
  }
  *(undefined2 *)(iVar3 + 0x10) = 0;
LAB_31f7_10bc:
  if (*(int *)(iVar3 + 0x10) != *(int *)(iVar3 + 0x12)) {
    FUN_28eb_3328(iVar3,iVar4);
  }
  return;
}

