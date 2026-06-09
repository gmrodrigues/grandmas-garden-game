// TIM2.EXE: FUN_28eb_51b3 @ file 0x033263 Ghidra 0x2E063
// Subsystem: misc | Size: 234 bytes


void __cdecl16far
FUN_28eb_51b3(undefined4 param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int in_DX;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = (int)((ulong)param_1 >> 0x10);
  iVar6 = (int)param_1;
  *(undefined2 *)(iVar6 + 0x8e) = 0;
  *(undefined2 *)(iVar6 + 0x8c) = 0;
  iVar1 = *(int *)(iVar6 + 0x22);
  iVar2 = *(int *)(iVar6 + 0x24);
  iVar4 = FUN_28eb_3287(param_2);
  while( true ) {
    if (iVar4 == 0 && in_DX == 0) break;
    iVar5 = iVar7;
    if ((iVar7 != in_DX) || (iVar6 != iVar4)) {
      if (((*(byte *)(iVar4 + 0xd) & 0x20) == 0) && ((*(byte *)(iVar4 + 0xf) & 0x40) == 0)) {
        if ((((*(int *)(iVar4 + 0x22) < param_4 + iVar1) &&
             (param_3 + iVar1 < *(int *)(iVar4 + 0x54) + *(int *)(iVar4 + 0x22))) &&
            (*(int *)(iVar4 + 0x24) < param_6 + iVar2)) &&
           (param_5 + iVar2 < *(int *)(iVar4 + 0x56) + *(int *)(iVar4 + 0x24))) {
          uVar3 = *(undefined2 *)(iVar6 + 0x8c);
          *(undefined2 *)(iVar4 + 0x8e) = *(undefined2 *)(iVar6 + 0x8e);
          *(undefined2 *)(iVar4 + 0x8c) = uVar3;
          *(int *)(iVar6 + 0x8e) = in_DX;
          *(int *)(iVar6 + 0x8c) = iVar4;
          iVar5 = in_DX;
        }
      }
    }
    iVar4 = FUN_28eb_32d8(iVar4,in_DX,param_2 & 0x1000);
    in_DX = iVar5;
  }
  return;
}

