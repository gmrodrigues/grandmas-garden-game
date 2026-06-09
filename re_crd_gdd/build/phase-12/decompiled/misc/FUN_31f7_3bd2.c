// TIM2.EXE: FUN_31f7_3bd2 @ file 0x03AD42 Ghidra 0x35B42
// Subsystem: misc | Size: 390 bytes


void __cdecl16far FUN_31f7_3bd2(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int in_DX;
  
  iVar1 = FUN_28eb_3783((int)param_1,param_1._2_2_);
  if ((iVar1 != 0 || in_DX != 0) && ((*(byte *)(iVar1 + 0xd) & 8) == 0)) {
    if ((*(int *)((int)param_1 + 0x10) < DAT_5b41_19ce) ||
       (DAT_5b41_19d2 <= *(int *)((int)param_1 + 0x10))) {
      *(undefined2 *)(iVar1 + 0x16) = 0;
    }
    else {
      *(int *)(iVar1 + 0x16) = *(int *)((int)param_1 + 0x16) * 2;
    }
  }
  if (*(int *)((int)param_1 + 0xae) == 0) {
    if (*(int *)((int)param_1 + 0x16) != 0) {
      if (*(int *)((int)param_1 + 0x10) < DAT_5b41_19cc) {
        *(int *)((int)param_1 + 0x10) = DAT_5b41_19cc + -1;
      }
      *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1;
      if (*(int *)((int)param_1 + 0x10) == DAT_5b41_19d2) {
        *(undefined2 *)((int)param_1 + 0x10) = DAT_5b41_19d0;
      }
      goto LAB_31f7_3d33;
    }
    if ((DAT_5b41_051f & 1) == 0) goto LAB_31f7_3d33;
    if (*(int *)((int)param_1 + 0x10) == 0) {
      DAT_554c_3aec = DAT_554c_3aec + -1;
      if (DAT_554c_3aec < 0) {
        *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1;
        uVar2 = FUN_460e_1a42();
        DAT_554c_3aec = uVar2 % 200 + 0x28;
      }
      goto LAB_31f7_3d33;
    }
    if ((DAT_5b41_19cc <= *(int *)((int)param_1 + 0x10)) ||
       (*(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1,
       *(int *)((int)param_1 + 0x10) != DAT_5b41_19cc)) goto LAB_31f7_3d33;
  }
  else {
    *(int *)((int)param_1 + 0xae) = *(int *)((int)param_1 + 0xae) + -1;
    if (*(int *)((int)param_1 + 0xae) != 0) {
      *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1;
      if (*(int *)((int)param_1 + 0x10) == DAT_5b41_19d4) {
        *(int *)((int)param_1 + 0x10) = DAT_5b41_19d2;
      }
      else if (*(int *)((int)param_1 + 0x10) == DAT_5b41_19d6) {
        *(int *)((int)param_1 + 0x10) = DAT_5b41_19d4;
      }
      goto LAB_31f7_3d33;
    }
    if (*(int *)((int)param_1 + 0x10) < DAT_5b41_19d4) {
      if ((*(byte *)((int)param_1 + 0xc) & 0x10) == 0) {
        *(undefined2 *)((int)param_1 + 0x16) = 0xffff;
      }
      else {
        *(undefined2 *)((int)param_1 + 0x16) = 1;
      }
      *(undefined2 *)((int)param_1 + 0x10) = DAT_5b41_19d0;
      goto LAB_31f7_3d33;
    }
  }
  *(undefined2 *)((int)param_1 + 0x10) = 0;
LAB_31f7_3d33:
  if (*(int *)((int)param_1 + 0x10) != *(int *)((int)param_1 + 0x12)) {
    FUN_31f7_3aab((int)param_1,param_1._2_2_);
    FUN_28eb_3328((int)param_1,param_1._2_2_);
  }
  return;
}

