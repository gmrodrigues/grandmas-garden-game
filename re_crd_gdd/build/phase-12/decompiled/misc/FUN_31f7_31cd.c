// TIM2.EXE: FUN_31f7_31cd @ file 0x03A33D Ghidra 0x3513D
// Subsystem: misc | Size: 371 bytes


void __cdecl16far FUN_31f7_31cd(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int in_DX;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  if ((*(int *)(iVar4 + 0x16) != 0) && (*(int *)(iVar4 + 0xb4) != 0)) {
    if (*(int *)(iVar4 + 0x10) == DAT_5b41_19c6) {
      *(int *)(iVar4 + 0xb4) = *(int *)(iVar4 + 0xb4) + -1;
      *(undefined2 *)(iVar4 + 0x10) = 0;
      *(undefined2 *)(iVar4 + 0x16) = 0;
    }
    else {
      *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      FUN_28eb_3328(iVar4,uVar5);
      FUN_31f7_3192(iVar4,uVar5);
      if ((*(int *)(iVar4 + 0x10) == DAT_5b41_19c4) &&
         (iVar1 = FUN_2321_0f22(0x14), iVar1 != 0 || in_DX != 0)) {
        FUN_28eb_2a59(iVar1,in_DX,(undefined2 *)&DAT_5b41_0557,0);
        *(uint *)(iVar1 + 10) = *(uint *)(iVar1 + 10) | 0x10;
        if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) {
          *(int *)(iVar1 + 0x22) = *(int *)(iVar4 + 0x22) + 0x42;
          iVar2 = *(int *)(iVar1 + 0x22) + -0x18;
          *(int *)(iVar1 + 0x2a) = iVar2;
          *(int *)(iVar1 + 0x26) = iVar2;
          *(undefined2 *)(iVar1 + 0x3a) = 0x3000;
        }
        else {
          *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x10;
          FUN_31f7_2732(iVar1,in_DX);
          *(int *)(iVar1 + 0x22) = *(int *)(iVar4 + 0x22) + -0x1a;
          iVar2 = *(int *)(iVar1 + 0x22) + 0x18;
          *(int *)(iVar1 + 0x2a) = iVar2;
          *(int *)(iVar1 + 0x26) = iVar2;
          *(undefined2 *)(iVar1 + 0x3a) = 0xd000;
        }
        iVar4 = *(int *)(iVar4 + 0x24) + 0xd;
        *(int *)(iVar1 + 0x2c) = iVar4;
        *(int *)(iVar1 + 0x28) = iVar4;
        *(int *)(iVar1 + 0x24) = iVar4;
        FUN_549b_007a(0x28eb,iVar1,in_DX);
        iVar4 = *(int *)(iVar1 + 0x22);
        *(int *)(iVar1 + 0x1c) = iVar4 >> 0xf;
        *(int *)(iVar1 + 0x1a) = iVar4;
        uVar5 = *(undefined2 *)(iVar1 + 0x1c);
        uVar3 = FUN_1000_199e();
        *(undefined2 *)(iVar1 + 0x1c) = uVar5;
        *(undefined2 *)(iVar1 + 0x1a) = uVar3;
        iVar4 = *(int *)(iVar1 + 0x24);
        *(int *)(iVar1 + 0x20) = iVar4 >> 0xf;
        *(int *)(iVar1 + 0x1e) = iVar4;
        uVar5 = *(undefined2 *)(iVar1 + 0x20);
        uVar3 = FUN_1000_199e();
        *(undefined2 *)(iVar1 + 0x20) = uVar5;
        *(undefined2 *)(iVar1 + 0x1e) = uVar3;
        FUN_28eb_3328(iVar1,in_DX);
        return;
      }
    }
  }
  return;
}

