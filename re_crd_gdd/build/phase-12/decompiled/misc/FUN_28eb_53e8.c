// TIM2.EXE: FUN_28eb_53e8 @ file 0x033498 Ghidra 0x2E298
// Subsystem: misc | Size: 266 bytes


void __cdecl16far FUN_28eb_53e8(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  bool bVar4;
  int iVar5;
  uint in_DX;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar10 = (uint)((ulong)param_1 >> 0x10);
  iVar9 = (int)param_1;
  *(undefined2 *)(iVar9 + 0x8e) = 0;
  *(undefined2 *)(iVar9 + 0x8c) = 0;
  iVar1 = *(int *)(iVar9 + 0x22);
  iVar2 = *(int *)(iVar9 + 0x24);
  iVar5 = FUN_28eb_3287(0x3000);
  while (iVar5 != 0 || in_DX != 0) {
    uVar8 = uVar10;
    if ((((uVar10 != in_DX) || (iVar9 != iVar5)) && ((*(byte *)(iVar5 + 0xd) & 0x20) == 0)) &&
       (((*(byte *)(iVar5 + 0xf) & 0x40) == 0 && ((*(byte *)(iVar5 + 0xe) & 4) != 0)))) {
      iVar6 = *(int *)(iVar5 + 0x22) + (int)*(char *)(iVar5 + 0x82);
      uVar7 = *(int *)(iVar5 + 0x24) + (int)*(char *)(iVar5 + 0x83);
      uVar8 = uVar7;
      if ((param_2 + iVar1 <= iVar6) &&
         ((iVar6 <= param_3 + iVar1 &&
          (bVar4 = param_4 + iVar2 <= (int)uVar7, uVar8 = (uint)bVar4,
          (int)uVar7 <= param_5 + iVar2 && bVar4)))) {
        uVar3 = *(undefined2 *)(iVar9 + 0x8c);
        *(undefined2 *)(iVar5 + 0x8e) = *(undefined2 *)(iVar9 + 0x8e);
        *(undefined2 *)(iVar5 + 0x8c) = uVar3;
        *(uint *)(iVar9 + 0x8e) = in_DX;
        *(int *)(iVar9 + 0x8c) = iVar5;
        uVar8 = in_DX;
      }
    }
    iVar5 = FUN_28eb_32d8(iVar5,in_DX,0x1000);
    in_DX = uVar8;
  }
  return;
}

