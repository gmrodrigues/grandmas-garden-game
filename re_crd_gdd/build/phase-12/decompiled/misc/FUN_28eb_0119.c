// TIM2.EXE: FUN_28eb_0119 @ file 0x02E1C9 Ghidra 0x28FC9
// Subsystem: misc | Size: 309 bytes


undefined2 __cdecl16far FUN_28eb_0119(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_DX;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = (int)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  if ((*(byte *)(iVar8 + 0xf) & 0x10) == 0) {
    iVar1 = *(int *)(iVar8 + 0x22);
    iVar2 = *(int *)(iVar8 + 0x24);
    iVar3 = *(int *)(iVar8 + 0x54);
    iVar4 = *(int *)(iVar8 + 0x56);
    iVar5 = FUN_28eb_3287(0x3000);
    while (iVar5 != 0 || in_DX != 0) {
      iVar7 = in_DX;
      iVar6 = FUN_28eb_00cb(*(undefined2 *)(iVar8 + 8),*(undefined2 *)(iVar5 + 8));
      if ((iVar6 == 0) &&
         ((((in_DX != iVar9 || (iVar7 = in_DX, iVar5 != iVar8)) &&
           (iVar7 = in_DX, (*(byte *)(iVar5 + 0xd) & 0x20) == 0)) &&
          ((*(byte *)(iVar5 + 0xf) & 0x50) == 0)))) {
        if (((((*(int *)(iVar5 + 0x22) < iVar3 + iVar1) &&
              (iVar1 < *(int *)(iVar5 + 0x54) + *(int *)(iVar5 + 0x22))) &&
             (*(int *)(iVar5 + 0x24) < iVar4 + iVar2)) &&
            (iVar2 < *(int *)(iVar5 + 0x56) + *(int *)(iVar5 + 0x24))) &&
           (((iVar6 = FUN_28eb_024e(iVar8,iVar9,iVar5,in_DX), iVar6 != 0 ||
             (iVar6 = FUN_28eb_03ff(iVar8,iVar9,iVar5,in_DX), iVar6 != 0)) ||
            (iVar6 = FUN_28eb_03ff(iVar5,in_DX,iVar8,iVar9), iVar6 != 0)))) {
          return 1;
        }
      }
      iVar5 = FUN_28eb_32d8(iVar5,in_DX,0x1000);
      in_DX = iVar7;
    }
  }
  return 0;
}

