// TIM2.EXE: FUN_31f7_8997 @ file 0x03FB07 Ghidra 0x3A907
// Subsystem: misc | Size: 578 bytes


void __cdecl16far FUN_31f7_8997(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_DX;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  
  uVar7 = 0x31f7;
  iVar6 = (int)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if (*(int *)(iVar4 + 0x16) != 0) {
    *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) | 0x40;
    if ((*(int *)(iVar4 + 0x10) < DAT_5b41_09a5) || ((DAT_5b41_051f & 1) != 0)) {
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
    }
    else if (*(int *)(iVar4 + 0x10) == 0x1b) {
      *(undefined2 *)(iVar4 + 0x10) = 0x20;
    }
    else {
      *(undefined2 *)(iVar4 + 0x10) = 0x1b;
    }
    if (*(int *)(iVar4 + 0x10) < DAT_5b41_1a6e) {
      FUN_31f7_891e(iVar4,iVar6);
    }
    if (*(int *)(iVar4 + 0x10) == DAT_5b41_1a6e) {
      iVar3 = *(int *)(iVar4 + 0x76);
      uVar7 = 0x2321;
      iVar1 = FUN_2321_0f22(0x48);
      if (iVar1 != 0 || in_DX != 0) {
        FUN_28eb_2a59(iVar1,in_DX,(undefined2 *)&DAT_5b41_0557,0);
        *(uint *)(iVar1 + 10) = *(uint *)(iVar1 + 10) | 0x10;
        *(int *)(iVar1 + 0x76) = iVar3;
        uVar7 = *(undefined2 *)(iVar4 + 0x5e);
        *(undefined2 *)(iVar1 + 0x60) = *(undefined2 *)(iVar4 + 0x60);
        *(undefined2 *)(iVar1 + 0x5e) = uVar7;
        uVar7 = *(undefined2 *)(iVar1 + 0x60);
        iVar5 = *(int *)(iVar1 + 0x5e);
        iVar2 = FUN_28eb_3930(iVar4,iVar6,iVar5,uVar7);
        if (iVar2 != -1) {
          iVar5 = iVar5 + iVar2 * 4;
          *(int *)(iVar5 + 0x60) = in_DX;
          *(int *)(iVar5 + 0x5e) = iVar1;
        }
        if ((*(int *)(iVar3 + 6) == iVar6) && (*(int *)(iVar3 + 4) == iVar4)) {
          *(int *)(iVar3 + 6) = in_DX;
          *(int *)(iVar3 + 4) = iVar1;
        }
        else {
          *(int *)(iVar3 + 10) = in_DX;
          *(int *)(iVar3 + 8) = iVar1;
        }
        if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
          iVar3 = *(int *)(iVar4 + 0x22) + 0x1c;
        }
        else {
          *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x10;
          iVar3 = *(int *)(iVar4 + 0x22) + -6;
        }
        *(int *)(iVar1 + 0x22) = iVar3;
        iVar3 = *(int *)(iVar1 + 0x22);
        *(int *)(iVar1 + 0x26) = iVar3;
        *(int *)(iVar1 + 0x1c) = iVar3 >> 0xf;
        *(int *)(iVar1 + 0x1a) = iVar3;
        uVar7 = *(undefined2 *)(iVar1 + 0x1c);
        uVar8 = FUN_1000_199e();
        *(undefined2 *)(iVar1 + 0x1c) = uVar7;
        *(undefined2 *)(iVar1 + 0x1a) = uVar8;
        uVar7 = *(undefined2 *)(iVar4 + 0x24);
        *(undefined2 *)(iVar1 + 0x24) = uVar7;
        *(undefined2 *)(iVar1 + 0x28) = uVar7;
        iVar3 = *(int *)(iVar1 + 0x24);
        *(int *)(iVar1 + 0x20) = iVar3 >> 0xf;
        *(int *)(iVar1 + 0x1e) = iVar3;
        uVar7 = *(undefined2 *)(iVar1 + 0x20);
        uVar8 = FUN_1000_199e();
        *(undefined2 *)(iVar1 + 0x20) = uVar7;
        *(undefined2 *)(iVar1 + 0x1e) = uVar8;
        uVar7 = 0x28eb;
        FUN_28eb_3328(iVar1,in_DX);
        FUN_31f7_8503(iVar1,in_DX);
        *(undefined2 *)(iVar4 + 0x76) = 0;
        *(undefined2 *)(iVar4 + 0x60) = 0;
        *(undefined2 *)(iVar4 + 0x5e) = 0;
      }
    }
    if (*(int *)(iVar4 + 0x10) == DAT_5b41_1a70) {
      *(int *)(iVar4 + 0x10) = DAT_5b41_09a5;
    }
    if (DAT_5b41_09a5 <= *(int *)(iVar4 + 0x10)) {
      if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
        uVar9 = 10;
        uVar8 = 0xfffb;
      }
      else {
        uVar9 = 0x28;
        uVar8 = 0x19;
      }
      FUN_553b_00b6(uVar7,iVar4,iVar6,uVar8,uVar9,0xffe0);
    }
    FUN_28eb_3328(iVar4,iVar6);
  }
  return;
}

