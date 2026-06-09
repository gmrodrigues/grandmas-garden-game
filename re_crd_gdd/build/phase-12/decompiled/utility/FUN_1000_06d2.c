// TIM2.EXE: FUN_1000_06d2 @ file 0x0158D2 Ghidra 0x106D2
// Subsystem: utility | Size: 265 bytes


bool __cdecl16far
FUN_1000_06d2(undefined2 param_1,undefined2 param_2,int *param_3,undefined2 *param_4)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 in_DX;
  bool bVar3;
  int local_1a;
  uint local_18;
  int local_16;
  int local_8;
  uint local_6;
  int local_4;
  
  local_8 = 0;
  if (DAT_5b41_0469 != 0) {
    FUN_1000_05f4(param_1);
    local_8 = FUN_1000_07db(&local_1a);
  }
  if (local_8 == 0) {
    iVar1 = FUN_1000_418e(param_1,0x1ce);
    if (iVar1 != 0) {
      FUN_1000_5472(param_2,param_1);
      param_3[1] = 0;
      *param_3 = 0;
      FUN_1000_43c4(iVar1,0,0,2);
      uVar2 = FUN_1000_4431(iVar1);
      param_4[1] = in_DX;
      *param_4 = uVar2;
      FUN_1000_3d77(iVar1);
    }
    bVar3 = iVar1 != 0;
  }
  else {
    FUN_1000_5472(param_2,local_1a * 0x1c + 0x6300);
    local_4 = local_16;
    local_6 = local_18;
    uVar2 = FUN_1000_418e(param_2,0x1d1);
    FUN_1000_43c4(uVar2,local_6 + 0xd,local_4 + (uint)(0xfff2 < local_6),0);
    FUN_1000_4306(param_4,4,1,uVar2);
    param_3[1] = local_4 + (uint)(0xffee < local_6);
    *param_3 = local_6 + 0x11;
    FUN_1000_3d77(uVar2);
    bVar3 = true;
  }
  return bVar3;
}

