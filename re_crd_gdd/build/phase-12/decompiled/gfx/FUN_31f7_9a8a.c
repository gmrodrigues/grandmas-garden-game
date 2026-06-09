// TIM2.EXE: FUN_31f7_9a8a @ file 0x040BFA Ghidra 0x3B9FA
// Subsystem: gfx | Size: 637 bytes


void __cdecl16far FUN_31f7_9a8a(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int in_DX;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 local_6;
  
  iVar9 = (int)((ulong)param_1 >> 0x10);
  iVar8 = (int)param_1;
  if ((*(int *)(iVar8 + 0x16) != 0) || (*(int *)(iVar8 + 0x10) != 0)) {
    *(int *)(iVar8 + 0x10) = *(int *)(iVar8 + 0x10) + 1;
    if (6 < *(int *)(iVar8 + 0x10)) {
      if ((*(byte *)(iVar8 + 0xc) & 0x10) == 0) {
        FUN_28eb_51b3(iVar8,iVar9,0x1000,*(undefined2 *)(*(int *)(iVar8 + 0x10) * 2 + 0x3c98),0x14,7
                      ,0x12);
        iVar3 = -0x1000;
      }
      else {
        FUN_28eb_51b3(iVar8,iVar9,0x1000,0x40,*(undefined2 *)(*(int *)(iVar8 + 0x10) * 2 + 0x3c9e),7
                      ,0x12);
        iVar3 = 0x1000;
      }
      iVar6 = iVar8;
      iVar4 = iVar9;
      uVar5 = 0x28eb;
      while( true ) {
        in_DX = *(int *)(iVar6 + 0x8e);
        iVar6 = *(int *)(iVar6 + 0x8c);
        if (iVar6 == 0 && in_DX == 0) break;
        iVar4 = in_DX;
        if ((*(byte *)(iVar6 + 0xb) & 0x10) == 0) {
          iVar7 = *(int *)(iVar6 + 8);
          if (iVar7 == 6) {
            FUN_31f7_111e(iVar6,in_DX);
          }
          else if (iVar7 == 0xf) {
            FUN_31f7_1e38(iVar6,in_DX);
          }
          else if (iVar7 == 0x4e) {
            *(undefined2 *)(iVar6 + 0x16) = 1;
          }
        }
        else {
          *(int *)(iVar6 + 0x3a) = *(int *)(iVar6 + 0x3a) + iVar3;
          FUN_549b_007a(uVar5,iVar6,in_DX);
          uVar5 = 0x549b;
          if (*(int *)(iVar6 + 8) == 0x36) {
            *(undefined2 *)(iVar6 + 0xae) = 1;
          }
        }
      }
    }
    if (*(int *)(iVar8 + 0x10) < 9) {
      FUN_31f7_995b(iVar8,iVar9);
      iVar3 = FUN_28eb_3783(iVar8,iVar9);
      if (iVar3 != 0 || in_DX != 0) {
        if ((*(int *)(iVar8 + 0x10) < 2) || (7 < *(int *)(iVar8 + 0x10))) {
          *(undefined2 *)(iVar3 + 0x16) = 0;
        }
        else if ((*(byte *)(iVar8 + 0xc) & 0x10) == 0) {
          if ((*(byte *)(iVar3 + 0xd) & 8) == 0) {
            *(undefined2 *)(iVar3 + 0x16) = 2;
          }
        }
        else if ((*(byte *)(iVar3 + 0xd) & 8) == 0) {
          *(undefined2 *)(iVar3 + 0x16) = 0xfffe;
        }
      }
      iVar3 = *(int *)(iVar8 + 0x76);
      if (iVar3 != 0) {
        if ((*(int *)(iVar3 + 6) == iVar9) && (*(int *)(iVar3 + 4) == iVar8)) {
          local_6 = 0;
          uVar2 = *(undefined1 *)(iVar3 + 0x15);
        }
        else {
          local_6 = 1;
          uVar2 = *(undefined1 *)(iVar3 + 0x14);
        }
        if ((*(int *)(iVar8 + 0x42) < 0) ||
           ((*(int *)(iVar8 + 0x42) < 1 && (*(int *)(iVar8 + 0x40) == 0)))) {
          iVar4 = -*(int *)(iVar8 + 0x40);
          iVar6 = -(uint)(*(int *)(iVar8 + 0x40) != 0) - *(int *)(iVar8 + 0x42);
        }
        else {
          iVar6 = *(int *)(iVar8 + 0x42);
          iVar4 = *(int *)(iVar8 + 0x40);
        }
        iVar7 = iVar6;
        uVar5 = FUN_28eb_37bb(iVar3,local_6,0xffff);
        iVar3 = FUN_28eb_396b(iVar8,iVar9,iVar3);
        puVar1 = (undefined2 *)(*(int *)(*(int *)(iVar3 + 8) * 2 + 0x302) + 0x14);
        (*(code *)*puVar1)(0x28eb,iVar8,iVar9,iVar3,iVar7,uVar2,uVar5,0,iVar4,iVar6);
      }
    }
    else {
      *(undefined2 *)(iVar8 + 0xae) = 0;
      *(undefined2 *)(iVar8 + 0x16) = 0;
      *(undefined2 *)(iVar8 + 0x10) = 0;
      FUN_31f7_995b(iVar8,iVar9);
    }
  }
  return;
}

