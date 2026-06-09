// TIM2.EXE: FUN_22de_000a @ file 0x027FEA Ghidra 0x22DEA
// Subsystem: physics | Size: 307 bytes


uint __cdecl16far FUN_22de_000a(uint param_1,int param_2,uint param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int in_DX;
  int iVar7;
  int iVar8;
  uint local_12;
  int local_10;
  
  uVar1 = FUN_1a9e_539c(0xffff,0xffff,0,0);
  iVar7 = in_DX;
  uVar2 = FUN_1a9e_539c(uVar1,in_DX,0,0);
  FUN_1a9e_5415(uVar2,iVar7,uVar2);
  uVar3 = FUN_1000_19df();
  uVar4 = uVar3 + 0x120;
  iVar7 = iVar7 + (uint)(0xfedf < uVar3);
  iVar8 = 0x1000;
  uVar3 = FUN_1000_19df();
  uVar5 = (uVar4 - uVar3) + uVar1;
  uVar6 = uVar5 - param_1;
  iVar8 = ((((iVar7 - iVar8) - (uint)(uVar4 < uVar3)) + in_DX + (uint)CARRY2(uVar4 - uVar3,uVar1)) -
          param_2) - (uint)(uVar5 < param_1);
  local_12 = -param_3;
  local_10 = -(uint)(param_3 != 0) - param_4;
  FUN_3f2b_1159(4);
  iVar7 = FUN_3f2b_118f();
  if (iVar7 != 0) {
    iVar7 = DAT_554c_3d54 + 4 >> 0xf;
    uVar1 = FUN_1000_199e();
    local_12 = uVar1 - param_3;
    local_10 = (iVar7 - param_4) - (uint)(uVar1 < param_3);
  }
  if (((iVar8 < 0) || ((local_10 < 1 && (local_10 < 0)))) && (param_5 == 0)) {
    FUN_1000_4d37(DAT_5b41_17d2);
    FUN_1000_4d37(DAT_5b41_17d4,uVar6 + param_1,iVar8 + param_2 + (uint)CARRY2(uVar6,param_1),
                  local_12 + param_3,local_10 + param_4 + (uint)CARRY2(local_12,param_3));
    FUN_1000_4d37(DAT_5b41_17d6,param_1,param_2,param_3,param_4);
    FUN_22de_03d9(0x1000);
  }
  return local_12;
}

