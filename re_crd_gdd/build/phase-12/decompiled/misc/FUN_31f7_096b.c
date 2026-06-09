// TIM2.EXE: FUN_31f7_096b @ file 0x037ADB Ghidra 0x328DB
// Subsystem: misc | Size: 476 bytes


void __cdecl16far FUN_31f7_096b(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int in_DX;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = (int)((ulong)param_1 >> 0x10);
  iVar6 = (int)param_1;
  if (*(int *)(iVar6 + 0x16) != 0) {
    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 0x40;
    if (*(int *)(iVar6 + 0x10) == *(int *)(iVar6 + 0xa8)) {
      *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + 1;
    }
    else {
      *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + 1;
      iVar1 = FUN_4551_0308(DAT_5b41_09b6,*(undefined2 *)(iVar6 + 0x10));
      if (iVar1 != 0) {
        *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + -1;
        FUN_2424_0f94(iVar6,iVar8,3);
        *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 0x2000;
      }
    }
    if ((*(byte *)(iVar6 + 0xd) & 0x20) == 0) {
      if (((*(int *)(iVar6 + 0x16) == 1) && (iVar1 = *(int *)(iVar6 + 0x76), iVar1 != 0)) &&
         (iVar2 = FUN_2321_0f22(0x31), iVar2 != 0 || in_DX != 0)) {
        FUN_28eb_2a59(iVar2,in_DX,(undefined2 *)&DAT_5b41_0557,0);
        *(uint *)(iVar2 + 10) = *(uint *)(iVar2 + 10) | 0x10;
        *(int *)(iVar2 + 0x76) = iVar1;
        uVar4 = *(undefined2 *)(iVar6 + 0x5e);
        *(undefined2 *)(iVar2 + 0x60) = *(undefined2 *)(iVar6 + 0x60);
        *(undefined2 *)(iVar2 + 0x5e) = uVar4;
        uVar4 = *(undefined2 *)(iVar2 + 0x60);
        iVar7 = *(int *)(iVar2 + 0x5e);
        iVar3 = FUN_28eb_3930(iVar6,iVar8,iVar7,uVar4);
        if (iVar3 != -1) {
          iVar7 = iVar7 + iVar3 * 4;
          *(int *)(iVar7 + 0x60) = in_DX;
          *(int *)(iVar7 + 0x5e) = iVar2;
        }
        if ((*(int *)(iVar1 + 6) == iVar8) && (*(int *)(iVar1 + 4) == iVar6)) {
          *(int *)(iVar1 + 6) = in_DX;
          *(int *)(iVar1 + 4) = iVar2;
          *(undefined2 *)(iVar2 + 0x22) = *(undefined2 *)(iVar1 + 0x1e);
          uVar4 = *(undefined2 *)(iVar1 + 0x20);
        }
        else {
          *(int *)(iVar1 + 10) = in_DX;
          *(int *)(iVar1 + 8) = iVar2;
          *(undefined2 *)(iVar2 + 0x22) = *(undefined2 *)(iVar1 + 0x22);
          uVar4 = *(undefined2 *)(iVar1 + 0x24);
        }
        *(undefined2 *)(iVar2 + 0x24) = uVar4;
        iVar1 = *(int *)(iVar2 + 0x22);
        *(int *)(iVar2 + 0x1c) = iVar1 >> 0xf;
        *(int *)(iVar2 + 0x1a) = iVar1;
        uVar4 = *(undefined2 *)(iVar2 + 0x1c);
        uVar5 = FUN_1000_199e();
        *(undefined2 *)(iVar2 + 0x1c) = uVar4;
        *(undefined2 *)(iVar2 + 0x1a) = uVar5;
        iVar1 = *(int *)(iVar2 + 0x24);
        *(int *)(iVar2 + 0x20) = iVar1 >> 0xf;
        *(int *)(iVar2 + 0x1e) = iVar1;
        uVar4 = *(undefined2 *)(iVar2 + 0x20);
        uVar5 = FUN_1000_199e();
        *(undefined2 *)(iVar2 + 0x20) = uVar4;
        *(undefined2 *)(iVar2 + 0x1e) = uVar5;
        FUN_28eb_3328(iVar2,in_DX);
        *(undefined2 *)(iVar6 + 0x76) = 0;
        *(undefined2 *)(iVar6 + 0x60) = 0;
        *(undefined2 *)(iVar6 + 0x5e) = 0;
      }
      FUN_28eb_3328(iVar6,iVar8);
    }
  }
  return;
}

