// TIM2.EXE: FUN_28eb_2550 @ file 0x030600 Ghidra 0x2B400
// Subsystem: misc | Size: 143 bytes


void __cdecl16far FUN_28eb_2550(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  iVar1 = *(int *)(iVar4 + 0x58);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    iVar3 = *(int *)(iVar1 + 6);
    if (iVar3 != 0 || iVar2 != 0) {
      *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xfffd;
      *(undefined2 *)(iVar3 + 0xac) = *(undefined2 *)(iVar3 + 0xc);
      *(undefined2 *)(iVar3 + 0x58) = 0;
      *(undefined2 *)(iVar1 + 8) = 0;
      *(undefined2 *)(iVar1 + 6) = 0;
    }
    iVar2 = *(int *)(iVar1 + 0xc);
    iVar3 = *(int *)(iVar1 + 10);
    if (iVar3 != 0 || iVar2 != 0) {
      *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xfffd;
      *(undefined2 *)(iVar3 + 0xac) = *(undefined2 *)(iVar3 + 0xc);
      *(undefined2 *)(iVar3 + 0x58) = 0;
      *(undefined2 *)(iVar1 + 0xc) = 0;
      *(undefined2 *)(iVar1 + 10) = 0;
    }
    if ((*(byte *)(iVar4 + 0xb) & 8) == 0) {
      FUN_28eb_2ca2(iVar4,uVar5);
    }
  }
  return;
}

