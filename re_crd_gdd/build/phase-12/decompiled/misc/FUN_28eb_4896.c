// TIM2.EXE: FUN_28eb_4896 @ file 0x032946 Ghidra 0x2D746
// Subsystem: misc | Size: 373 bytes


void __cdecl16far FUN_28eb_4896(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar3 + 0x26);
  *(undefined2 *)(iVar3 + 0x2c) = *(undefined2 *)(iVar3 + 0x28);
  *(undefined2 *)(iVar3 + 0x2a) = uVar1;
  uVar1 = *(undefined2 *)(iVar3 + 0x22);
  *(undefined2 *)(iVar3 + 0x28) = *(undefined2 *)(iVar3 + 0x24);
  *(undefined2 *)(iVar3 + 0x26) = uVar1;
  uVar1 = *(undefined2 *)(iVar3 + 0x32);
  *(undefined2 *)(iVar3 + 0x38) = *(undefined2 *)(iVar3 + 0x34);
  *(undefined2 *)(iVar3 + 0x36) = uVar1;
  uVar1 = *(undefined2 *)(iVar3 + 0x2e);
  *(undefined2 *)(iVar3 + 0x34) = *(undefined2 *)(iVar3 + 0x30);
  *(undefined2 *)(iVar3 + 0x32) = uVar1;
  uVar1 = *(undefined2 *)(iVar3 + 0x4c);
  *(undefined2 *)(iVar3 + 0x52) = *(undefined2 *)(iVar3 + 0x4e);
  *(undefined2 *)(iVar3 + 0x50) = uVar1;
  uVar1 = *(undefined2 *)(iVar3 + 0x48);
  *(undefined2 *)(iVar3 + 0x4e) = *(undefined2 *)(iVar3 + 0x4a);
  *(undefined2 *)(iVar3 + 0x4c) = uVar1;
  *(undefined2 *)(iVar3 + 0x14) = *(undefined2 *)(iVar3 + 0x12);
  *(undefined2 *)(iVar3 + 0x12) = *(undefined2 *)(iVar3 + 0x10);
  if ((*(int *)(iVar3 + 8) == 8) && (DAT_5b41_0937 == 0x1000)) {
    iVar2 = *(int *)(iVar3 + 0x58);
    uVar1 = *(undefined2 *)(iVar2 + 0x1e);
    *(undefined2 *)(iVar2 + 0x30) = *(undefined2 *)(iVar2 + 0x20);
    *(undefined2 *)(iVar2 + 0x2e) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0xe);
    *(undefined2 *)(iVar2 + 0x20) = *(undefined2 *)(iVar2 + 0x10);
    *(undefined2 *)(iVar2 + 0x1e) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x22);
    *(undefined2 *)(iVar2 + 0x34) = *(undefined2 *)(iVar2 + 0x24);
    *(undefined2 *)(iVar2 + 0x32) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x12);
    *(undefined2 *)(iVar2 + 0x24) = *(undefined2 *)(iVar2 + 0x14);
    *(undefined2 *)(iVar2 + 0x22) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x26);
    *(undefined2 *)(iVar2 + 0x38) = *(undefined2 *)(iVar2 + 0x28);
    *(undefined2 *)(iVar2 + 0x36) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x16);
    *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(iVar2 + 0x18);
    *(undefined2 *)(iVar2 + 0x26) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x2a);
    *(undefined2 *)(iVar2 + 0x3c) = *(undefined2 *)(iVar2 + 0x2c);
    *(undefined2 *)(iVar2 + 0x3a) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x1a);
    *(undefined2 *)(iVar2 + 0x2c) = *(undefined2 *)(iVar2 + 0x1c);
    *(undefined2 *)(iVar2 + 0x2a) = uVar1;
  }
  if (((*(int *)(iVar3 + 8) == 10) || (*(int *)(iVar3 + 8) == 7)) || (*(int *)(iVar3 + 8) == 0x4c))
  {
    iVar2 = *(int *)(iVar3 + 0x76);
    *(undefined2 *)(iVar2 + 0x1c) = *(undefined2 *)(iVar2 + 0x1a);
    *(undefined2 *)(iVar2 + 0x1a) = *(undefined2 *)(iVar2 + 0x18);
    uVar1 = *(undefined2 *)(iVar2 + 0x26);
    *(undefined2 *)(iVar2 + 0x30) = *(undefined2 *)(iVar2 + 0x28);
    *(undefined2 *)(iVar2 + 0x2e) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x1e);
    *(undefined2 *)(iVar2 + 0x28) = *(undefined2 *)(iVar2 + 0x20);
    *(undefined2 *)(iVar2 + 0x26) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x2a);
    *(undefined2 *)(iVar2 + 0x34) = *(undefined2 *)(iVar2 + 0x2c);
    *(undefined2 *)(iVar2 + 0x32) = uVar1;
    uVar1 = *(undefined2 *)(iVar2 + 0x22);
    *(undefined2 *)(iVar2 + 0x2c) = *(undefined2 *)(iVar2 + 0x24);
    *(undefined2 *)(iVar2 + 0x2a) = uVar1;
  }
  *(undefined2 *)(iVar3 + 0xb2) = *(undefined2 *)(iVar3 + 0xb0);
  *(undefined2 *)(iVar3 + 0xb0) = *(undefined2 *)(iVar3 + 0xae);
  *(undefined2 *)(iVar3 + 0xb8) = *(undefined2 *)(iVar3 + 0xb6);
  *(undefined2 *)(iVar3 + 0xb6) = *(undefined2 *)(iVar3 + 0xb4);
  return;
}

