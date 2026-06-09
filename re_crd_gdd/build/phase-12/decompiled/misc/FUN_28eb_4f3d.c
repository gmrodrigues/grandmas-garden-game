// TIM2.EXE: FUN_28eb_4f3d @ file 0x032FED Ghidra 0x2DDED
// Subsystem: misc | Size: 541 bytes


void __cdecl16far
FUN_28eb_4f3d(undefined4 param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int in_DX;
  int iVar9;
  int iVar10;
  uint local_18;
  uint local_16;
  int local_10;
  int local_e;
  int local_c;
  int local_8;
  int local_6;
  int local_4;
  
  iVar10 = (int)((ulong)param_1 >> 0x10);
  iVar9 = (int)param_1;
  *(undefined2 *)(iVar9 + 0x8e) = 0;
  *(undefined2 *)(iVar9 + 0x8c) = 0;
  iVar2 = FUN_28eb_515a(iVar9,iVar10);
  if (iVar2 == 0) {
    local_4 = *(int *)(iVar9 + 0x2e);
    local_6 = *(int *)(iVar9 + 0x48) + local_4;
    local_8 = *(int *)(iVar9 + 0x30);
    iVar2 = *(int *)(iVar9 + 0x4a);
  }
  else {
    local_4 = *(int *)(iVar9 + 0x22);
    local_6 = *(int *)(iVar9 + 0x54) + local_4;
    local_8 = *(int *)(iVar9 + 0x24);
    iVar2 = *(int *)(iVar9 + 0x56);
  }
  iVar3 = FUN_28eb_3287(param_2);
  while (iVar3 != 0 || in_DX != 0) {
    iVar7 = iVar10;
    if ((((iVar10 != in_DX) || (iVar9 != iVar3)) && ((*(byte *)(iVar3 + 0xd) & 0x20) == 0)) &&
       ((*(byte *)(iVar3 + 0xf) & 0x40) == 0)) {
      iVar4 = FUN_28eb_515a(iVar3,in_DX);
      if (iVar4 == 0) {
        local_c = *(int *)(iVar3 + 0x2e);
        local_e = *(int *)(iVar3 + 0x48) + local_c;
        local_10 = *(int *)(iVar3 + 0x30);
        iVar4 = *(int *)(iVar3 + 0x4a);
      }
      else {
        local_c = *(int *)(iVar3 + 0x22);
        local_e = *(int *)(iVar3 + 0x54) + local_c;
        local_10 = *(int *)(iVar3 + 0x24);
        iVar4 = *(int *)(iVar3 + 0x56);
      }
      uVar5 = local_e - local_4;
      if (param_3 <= (int)uVar5) {
        local_16 = uVar5;
        if (-1 < (int)uVar5) {
          local_16 = 0xffff;
        }
        uVar6 = local_c - local_6;
        if ((int)uVar6 <= param_4) {
          local_18 = uVar6;
          if ((int)uVar6 < 1) {
            local_18 = 1;
          }
          iVar7 = (uVar6 ^ (int)uVar6 >> 0xf) - ((int)uVar6 >> 0xf);
          uVar6 = local_16;
          if (iVar7 < (int)((uVar5 ^ (int)uVar5 >> 0xf) - ((int)uVar5 >> 0xf))) {
            uVar6 = local_18;
          }
          uVar5 = (iVar4 + local_10) - local_8;
          if (param_5 <= (int)uVar5) {
            local_16 = uVar5;
            if (-1 < (int)uVar5) {
              local_16 = 0xffff;
            }
            uVar8 = local_10 - (iVar2 + local_8);
            if ((int)uVar8 <= param_6) {
              local_18 = uVar8;
              if ((int)uVar8 < 1) {
                local_18 = 1;
              }
              if ((int)((uVar8 ^ (int)uVar8 >> 0xf) - ((int)uVar8 >> 0xf)) <
                  (int)((uVar5 ^ (int)uVar5 >> 0xf) - ((int)uVar5 >> 0xf))) {
                local_16 = local_18;
              }
              uVar1 = *(undefined2 *)(iVar9 + 0x8c);
              *(undefined2 *)(iVar3 + 0x8e) = *(undefined2 *)(iVar9 + 0x8e);
              *(undefined2 *)(iVar3 + 0x8c) = uVar1;
              *(int *)(iVar9 + 0x8e) = in_DX;
              *(int *)(iVar9 + 0x8c) = iVar3;
              *(uint *)(iVar3 + 0x90) = uVar6;
              *(uint *)(iVar3 + 0x92) = local_16;
              iVar7 = in_DX;
            }
          }
        }
      }
    }
    iVar3 = FUN_28eb_32d8(iVar3,in_DX,param_2 & 0x1000);
    in_DX = iVar7;
  }
  return;
}

