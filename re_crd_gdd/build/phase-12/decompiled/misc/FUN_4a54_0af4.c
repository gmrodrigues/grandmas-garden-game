// TIM2.EXE: FUN_4a54_0af4 @ file 0x050234 Ghidra 0x4B034
// Subsystem: misc | Size: 293 bytes


undefined2 __cdecl16far FUN_4a54_0af4(int param_1)

{
  int iVar1;
  int in_DX;
  undefined2 uVar2;
  bool bVar3;
  undefined1 local_50 [68];
  undefined2 local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  local_6 = 0;
  local_8 = 0;
  local_4 = 0;
  uVar2 = 0;
  iVar1 = FUN_1a9e_6ea7(param_1);
  if (iVar1 == 0) {
    local_4 = 1;
    param_1 = FUN_1a9e_69e9(param_1);
    if (param_1 != 0) goto LAB_4a54_0b34;
  }
  else {
LAB_4a54_0b34:
    FUN_1a9e_693e(local_50,param_1);
    iVar1 = FUN_1a9e_6a85(param_1,0x56aa,0);
    if ((in_DX == -1) && (iVar1 == -1)) {
      FUN_1a9e_6988(local_50);
      uVar2 = FUN_1a9e_7ac4(param_1);
      goto LAB_4a54_0be7;
    }
    local_c = FUN_1a9e_6e3d(param_1);
    local_a = in_DX;
    local_8 = FUN_1a9e_539c(local_c,in_DX,0,0);
    local_6 = in_DX;
    if (local_8 != 0 || in_DX != 0) {
      FUN_4a54_0c1d(local_8,in_DX,local_c,local_a,param_1);
      DAT_5b41_2858 = FUN_4a54_0005(local_8,local_6);
      if (DAT_5b41_2858 != 0) {
        FUN_4a54_10a2(0,0,0x140,200);
        FUN_4a54_0037();
        goto LAB_4a54_0be7;
      }
    }
  }
  uVar2 = 0xffff;
LAB_4a54_0be7:
  if (local_4 != 0) {
    FUN_1a9e_6e73(param_1);
  }
  bVar3 = true;
  FUN_1000_1821();
  if (!bVar3) {
    FUN_1a9e_5415(local_8,local_6);
  }
  return uVar2;
}

