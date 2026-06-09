// TIM2.EXE: FUN_2321_0000 @ file 0x028410 Ghidra 0x23210
// Subsystem: misc | Size: 255 bytes


void __cdecl16far FUN_2321_0000(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 in_DX;
  uint extraout_DX;
  uint uVar3;
  undefined2 unaff_SI;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined1 local_56 [80];
  uint local_6;
  uint local_4;
  
  DAT_554c_02ea = 0xc00;
  FUN_1a3f_0001(1);
  uVar1 = FUN_1000_418e(0x1e0,0x1ed);
  uVar4 = 0x1000;
  iVar2 = FUN_1000_3d77(uVar1);
  if (iVar2 != 0) {
    FUN_4340_0a29(local_56);
    uVar5 = 0;
    uVar4 = 0;
    uVar1 = FUN_4340_0d3f(local_56);
    FUN_4340_0a29(uVar1,in_DX,uVar4,uVar5);
    uVar4 = 0x49fc;
    FUN_49fc_0004(local_56);
  }
  uVar1 = 0x1f0;
  FUN_42da_0206(uVar4,0x1f0);
  uVar3 = extraout_DX;
  FUN_2321_046d(param_1,param_2);
  DAT_554c_3d52 = (uint)(DAT_554c_3e66 == 0);
  local_6 = FUN_22de_000a(0xc000,8,0,4,DAT_554c_3e70);
  local_4 = uVar3;
  if ((((DAT_554c_3d52 == 0) && (DAT_554c_3d57 != '\0')) && (5 < uVar3)) &&
     ((6 < uVar3 || (0x1a80 < local_6)))) {
    FUN_4fd6_08ee(0,0,0);
  }
  FUN_2321_00ff();
  iVar2 = FUN_5517_0025(uVar1,unaff_SI);
  if (iVar2 == 0) {
    iVar2 = func_0x00055190();
    if (iVar2 == 0) {
      FUN_552e_0034();
    }
  }
  FUN_2321_06e4();
  FUN_2321_0425();
  return;
}

