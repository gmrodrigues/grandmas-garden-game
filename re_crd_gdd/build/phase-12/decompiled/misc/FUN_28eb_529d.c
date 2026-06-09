// TIM2.EXE: FUN_28eb_529d @ file 0x03334D Ghidra 0x2E14D
// Subsystem: misc | Size: 331 bytes


void __cdecl16far FUN_28eb_529d(undefined4 param_1,uint param_2,undefined2 param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  int iVar4;
  int iVar5;
  int *unaff_SI;
  int iVar6;
  undefined2 uVar7;
  undefined1 local_1a [4];
  int local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  *(undefined2 *)(iVar5 + 0x8e) = 0;
  *(undefined2 *)(iVar5 + 0x8c) = 0;
  iVar2 = FUN_28eb_3287(param_2);
  while( true ) {
    if (iVar2 == 0 && in_DX == 0) {
      return;
    }
    iVar6 = 1;
    iVar4 = in_DX;
    if (*(int *)(iVar2 + 0x98) != 0) break;
    while (unaff_SI != (int *)0x0) {
      local_16 = local_4 - *(int *)(iVar5 + 0x22);
      local_14 = local_a - *(int *)(iVar5 + 0x24);
      local_12 = local_6 - *(int *)(iVar5 + 0x22);
      local_10 = local_c - *(int *)(iVar5 + 0x24);
      iVar3 = FUN_2e67_13d4(param_3,&local_16,local_1a);
      if (iVar3 != 0) {
        uVar1 = *(undefined2 *)(iVar5 + 0x8c);
        *(undefined2 *)(iVar2 + 0x8e) = *(undefined2 *)(iVar5 + 0x8e);
        *(undefined2 *)(iVar2 + 0x8c) = uVar1;
        *(int *)(iVar5 + 0x8e) = in_DX;
        *(int *)(iVar5 + 0x8c) = iVar2;
        iVar6 = *(int *)(iVar2 + 0x96);
        iVar4 = in_DX;
      }
      iVar6 = iVar6 + 1;
      if (*(int *)(iVar2 + 0x96) < iVar6) {
        unaff_SI = (int *)0x0;
      }
      else {
        unaff_SI = unaff_SI + 3;
        local_4 = local_6;
        local_a = local_c;
        if (*(int *)(iVar2 + 0x96) == iVar6) {
          local_6 = local_8;
          local_c = local_e;
        }
        else {
LAB_28eb_53a0:
          local_6 = *(int *)(iVar2 + 0x22) + unaff_SI[3];
          local_c = *(int *)(iVar2 + 0x24) + unaff_SI[4];
        }
      }
    }
    iVar2 = FUN_28eb_32d8(iVar2,in_DX,param_2 & 0x1000);
    in_DX = iVar4;
  }
  unaff_SI = (int *)*(int *)(iVar2 + 0x98);
  local_8 = *(int *)(iVar2 + 0x22) + *unaff_SI;
  local_e = *(int *)(iVar2 + 0x24) + unaff_SI[1];
  local_a = local_e;
  local_4 = local_8;
  goto LAB_28eb_53a0;
}

