// TIM2.EXE: FUN_406b_0198 @ file 0x045A48 Ghidra 0x40848
// Subsystem: sound | Size: 263 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 __cdecl16far FUN_406b_0198(uint param_1,int param_2)

{
  int iVar1;
  undefined2 in_DX;
  undefined2 uVar2;
  
  uVar2 = 0x406b;
  FUN_406b_029f();
  if (DAT_554c_5594 == '\0') {
    uVar2 = 0x1a9e;
    FUN_1a9e_580f();
  }
  if (DAT_554c_4f22 == '\0') {
    uVar2 = 0x1a9e;
    iVar1 = FUN_1a9e_3f33(0xd);
    if (iVar1 != 0) goto LAB_406b_01c9;
LAB_406b_0266:
    uVar2 = 0;
  }
  else {
LAB_406b_01c9:
    if (((param_1 & 1) != 0) && (DAT_554c_4fc2 == '\0')) {
      uVar2 = 0x1a9e;
      iVar1 = FUN_1a9e_48fc(0);
      if (iVar1 == 0) goto LAB_406b_0266;
    }
    if (param_2 == 0) {
      param_2 = FUN_1a9e_5398(uVar2,0x40,0x40);
      in_DX = 0x53bd;
      DAT_53bd_0040 = param_2;
    }
    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
      uVar2 = FUN_22de_01ec(param_2,0,0,0);
      *(undefined2 *)(iVar1 * 0x12 + 0x14) = in_DX;
      *(undefined2 *)(iVar1 * 0x12 + 0x12) = uVar2;
      *(undefined2 *)(iVar1 * 0x12 + 4) = 0xfffe;
      *(undefined2 *)(iVar1 * 0x12 + 6) = 0xfffe;
      if (*(int *)(iVar1 * 0x12 + 0x12) == 0 && *(int *)(iVar1 * 0x12 + 0x14) == 0) {
        FUN_406b_029f();
        goto LAB_406b_0266;
      }
    }
    FUN_1a9e_58c8(0xe1f,0x406b);
    FUN_1a9e_3ec6(0xe67,0x406b,0xc);
    _DAT_53bd_0052 = param_1;
    uVar2 = 1;
  }
  return uVar2;
}

