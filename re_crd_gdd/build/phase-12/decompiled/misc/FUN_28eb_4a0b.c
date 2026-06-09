// TIM2.EXE: FUN_28eb_4a0b @ file 0x032ABB Ghidra 0x2D8BB
// Subsystem: misc | Size: 564 bytes


void __cdecl16far FUN_28eb_4a0b(void)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int in_DX;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  int local_4;
  
  iVar2 = FUN_28eb_3287(0x3000);
  while (iVar2 != 0 || in_DX != 0) {
    iVar5 = in_DX;
    iVar3 = FUN_28eb_32d8(iVar2,in_DX,0x1000);
    if ((*(byte *)(iVar2 + 10) & 0x10) == 0) {
      *(uint *)(iVar2 + 10) = *(uint *)(iVar2 + 10) & 0xfff0;
      *(undefined2 *)(iVar2 + 0xc) = *(undefined2 *)(iVar2 + 0xac);
      *(uint *)(iVar2 + 0xe) = *(uint *)(iVar2 + 0xe) & 0xbfef;
      uVar6 = *(undefined2 *)(iVar2 + 0xa4);
      *(undefined2 *)(iVar2 + 0x2a) = uVar6;
      *(undefined2 *)(iVar2 + 0x26) = uVar6;
      *(undefined2 *)(iVar2 + 0x22) = uVar6;
      uVar6 = *(undefined2 *)(iVar2 + 0xa6);
      *(undefined2 *)(iVar2 + 0x2c) = uVar6;
      *(undefined2 *)(iVar2 + 0x28) = uVar6;
      *(undefined2 *)(iVar2 + 0x24) = uVar6;
      iVar7 = *(int *)(iVar2 + 0x22);
      *(int *)(iVar2 + 0x1c) = iVar7 >> 0xf;
      *(int *)(iVar2 + 0x1a) = iVar7;
      iVar7 = *(int *)(iVar2 + 0x24);
      *(int *)(iVar2 + 0x20) = iVar7 >> 0xf;
      *(int *)(iVar2 + 0x1e) = iVar7;
      uVar6 = *(undefined2 *)(iVar2 + 0x1c);
      uVar4 = FUN_1000_199e();
      *(undefined2 *)(iVar2 + 0x1c) = uVar6;
      *(undefined2 *)(iVar2 + 0x1a) = uVar4;
      uVar6 = *(undefined2 *)(iVar2 + 0x20);
      uVar4 = FUN_1000_199e();
      *(undefined2 *)(iVar2 + 0x20) = uVar6;
      *(undefined2 *)(iVar2 + 0x1e) = uVar4;
      *(undefined2 *)(iVar2 + 0x10) = *(undefined2 *)(iVar2 + 0xa8);
      uVar6 = *(undefined2 *)(iVar2 + 0x10);
      *(undefined2 *)(iVar2 + 0x12) = uVar6;
      *(undefined2 *)(iVar2 + 0x14) = uVar6;
      FUN_28eb_3328(iVar2,in_DX);
      uVar6 = *(undefined2 *)(iVar2 + 0x30);
      uVar4 = *(undefined2 *)(iVar2 + 0x2e);
      *(undefined2 *)(iVar2 + 0x34) = uVar6;
      *(undefined2 *)(iVar2 + 0x32) = uVar4;
      *(undefined2 *)(iVar2 + 0x38) = uVar6;
      *(undefined2 *)(iVar2 + 0x36) = uVar4;
      uVar6 = *(undefined2 *)(iVar2 + 0x4a);
      uVar4 = *(undefined2 *)(iVar2 + 0x48);
      *(undefined2 *)(iVar2 + 0x4e) = uVar6;
      *(undefined2 *)(iVar2 + 0x4c) = uVar4;
      *(undefined2 *)(iVar2 + 0x52) = uVar6;
      *(undefined2 *)(iVar2 + 0x50) = uVar4;
      if (*(int *)(iVar2 + 8) != 0x57) {
        *(undefined2 *)(iVar2 + 0x3e) =
             *(undefined2 *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x38);
      }
      *(undefined2 *)(iVar2 + 0x9c) = 0;
      *(undefined2 *)(iVar2 + 0x9a) = 0;
      *(undefined2 *)(iVar2 + 0x16) = *(undefined2 *)(iVar2 + 0xaa);
      *(undefined2 *)(iVar2 + 0x3c) = 0;
      *(undefined2 *)(iVar2 + 0x3a) = 0;
      if (((*(int *)(iVar2 + 8) != 0x1b) && (*(int *)(iVar2 + 8) != 0x88)) &&
         (*(int *)(iVar2 + 8) != 0x7f)) {
        *(undefined2 *)(iVar2 + 0xae) = 0;
      }
      uVar6 = *(undefined2 *)(iVar2 + 0xae);
      *(undefined2 *)(iVar2 + 0xb2) = uVar6;
      *(undefined2 *)(iVar2 + 0xb0) = uVar6;
      *(undefined2 *)(iVar2 + 0xb8) = 0;
      *(undefined2 *)(iVar2 + 0xb6) = 0;
      *(undefined2 *)(iVar2 + 0xb4) = 0;
      if ((*(int *)(iVar2 + 8) != 0xe) && (*(int *)(iVar2 + 8) != 0x56)) {
        for (local_4 = 0; local_4 < 2; local_4 = local_4 + 1) {
          iVar7 = iVar2 + local_4 * 4;
          uVar6 = *(undefined2 *)(iVar7 + 0x66);
          iVar8 = iVar2 + local_4 * 4;
          *(undefined2 *)(iVar8 + 0x60) = *(undefined2 *)(iVar7 + 0x68);
          *(undefined2 *)(iVar8 + 0x5e) = uVar6;
        }
      }
      puVar1 = (undefined2 *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 8);
      (*(code *)*puVar1)(0x1000,iVar2,in_DX);
      *(undefined2 *)(iVar2 + 0xa8) = *(undefined2 *)(iVar2 + 0x10);
      iVar2 = iVar3;
      in_DX = iVar5;
    }
    else {
      FUN_28eb_2a23(iVar2,in_DX);
      FUN_2321_0c23(iVar2,in_DX);
      iVar2 = iVar3;
      in_DX = iVar5;
    }
  }
  iVar2 = FUN_28eb_3287(0x3000);
  if (iVar2 == 0 && in_DX == 0) {
    return;
  }
  FUN_28eb_4c3f();
  return;
}

