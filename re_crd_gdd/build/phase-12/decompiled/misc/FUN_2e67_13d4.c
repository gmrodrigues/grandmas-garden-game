// TIM2.EXE: FUN_2e67_13d4 @ file 0x034C44 Ghidra 0x2FA44
// Subsystem: misc | Size: 529 bytes


undefined2 __cdecl16far FUN_2e67_13d4(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_22;
  int local_20;
  
  iVar5 = param_1[1] - param_1[3] >> 0xf;
  iVar6 = *param_1 - param_1[2] >> 0xf;
  uVar1 = FUN_1000_180a();
  iVar11 = iVar6;
  uVar2 = FUN_1000_180a(iVar5,uVar1);
  iVar9 = (iVar5 - iVar11) - (uint)(uVar1 < uVar2);
  iVar7 = param_2[3] - param_2[1] >> 0xf;
  iVar8 = param_2[2] - *param_2 >> 0xf;
  iVar11 = iVar7;
  uVar1 = FUN_1000_180a();
  iVar5 = iVar8;
  uVar2 = FUN_1000_180a(iVar11,uVar1);
  iVar10 = (iVar11 - iVar5) - (uint)(uVar1 < uVar2);
  iVar11 = iVar6;
  uVar1 = FUN_1000_180a();
  iVar5 = iVar8;
  uVar2 = FUN_1000_180a();
  iVar4 = uVar1 - uVar2;
  iVar11 = (iVar11 - iVar5) - (uint)(uVar1 < uVar2);
  if (iVar4 == 0 && iVar11 == 0) {
    uVar1 = FUN_1000_180a();
    uVar2 = FUN_1000_180a();
    if (uVar1 + uVar2 == 0 && iVar7 + iVar8 + (uint)CARRY2(uVar1,uVar2) == 0) {
      local_20 = param_1[2];
      local_22 = param_1[3];
    }
    else {
      local_20 = 0;
      local_22 = 0;
    }
  }
  else {
    uVar1 = FUN_1000_180a();
    uVar2 = FUN_1000_180a(iVar6,uVar1);
    local_20 = FUN_1000_18f0(0x1000,uVar1 - uVar2,(iVar6 - iVar8) - (uint)(uVar1 < uVar2),iVar4);
    uVar1 = FUN_1000_180a(iVar11);
    uVar2 = FUN_1000_180a(iVar10,uVar1);
    local_22 = FUN_1000_18f0(0x1000,uVar1 - uVar2,(iVar10 - iVar9) - (uint)(uVar1 < uVar2),iVar4);
  }
  *param_3 = local_20;
  param_3[1] = local_22;
  iVar11 = FUN_2e67_1398(local_20,*param_1,param_1[2]);
  if ((((iVar11 == 0) || (iVar11 = FUN_2e67_1398(local_20,*param_2,param_2[2]), iVar11 == 0)) ||
      (iVar11 = FUN_2e67_1398(local_22,param_1[1],param_1[3]), iVar11 == 0)) ||
     (iVar11 = FUN_2e67_1398(local_22,param_2[1],param_2[3]), iVar11 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

