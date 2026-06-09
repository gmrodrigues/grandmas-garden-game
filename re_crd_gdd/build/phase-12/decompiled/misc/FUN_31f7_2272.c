// TIM2.EXE: FUN_31f7_2272 @ file 0x0393E2 Ghidra 0x341E2
// Subsystem: misc | Size: 415 bytes


void __cdecl16far FUN_31f7_2272(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  int in_DX;
  int iVar3;
  int iVar4;
  int unaff_DI;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if ((*(int *)(iVar3 + 0x16) == 0) && (0x14 < *(int *)(iVar3 + 0xb4))) {
    *(undefined2 *)(iVar3 + 0x16) = 1;
  }
  if (*(int *)(iVar3 + 0x16) != 0) {
    for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
      if (*(int *)(iVar3 + 0xa8) == ((undefined2 *)&DAT_5b41_1996)[iVar4]) {
        unaff_DI = iVar4;
      }
    }
    if (*(int *)(iVar3 + 0x10) != ((undefined2 *)&DAT_5b41_19ae)[unaff_DI]) {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
      FUN_28eb_3328(iVar3,uVar5);
      if ((*(int *)(iVar3 + 0x10) == ((undefined2 *)&DAT_5b41_19a2)[unaff_DI]) &&
         (iVar4 = FUN_2321_0f22(0x2b), iVar4 != 0 || in_DX != 0)) {
        FUN_28eb_2a59(iVar4,in_DX,(undefined2 *)&DAT_5b41_0557,0);
        *(uint *)(iVar4 + 10) = *(uint *)(iVar4 + 10) | 0x10;
        *(int *)(iVar4 + 0x22) =
             *(int *)(iVar3 + 0x22) + ((undefined2 *)&DAT_554c_3a88)[unaff_DI * 2];
        iVar1 = *(int *)(iVar4 + 0x22) - ((undefined2 *)&DAT_554c_3ab8)[unaff_DI * 2];
        *(int *)(iVar4 + 0x2a) = iVar1;
        *(int *)(iVar4 + 0x26) = iVar1;
        *(undefined2 *)(iVar4 + 0x3a) = ((undefined2 *)&DAT_554c_3aa0)[unaff_DI * 2];
        *(int *)(iVar4 + 0x24) =
             *(int *)(iVar3 + 0x24) + ((undefined2 *)&DAT_554c_3a8a)[unaff_DI * 2];
        iVar3 = *(int *)(iVar4 + 0x24) + ((undefined2 *)&DAT_554c_3aba)[unaff_DI * 2];
        *(int *)(iVar4 + 0x2c) = iVar3;
        *(int *)(iVar4 + 0x28) = iVar3;
        *(int *)(iVar4 + 0x3c) = -((undefined2 *)&DAT_554c_3aa2)[unaff_DI * 2];
        FUN_549b_007a(0x28eb,iVar4,in_DX);
        iVar3 = *(int *)(iVar4 + 0x22);
        *(int *)(iVar4 + 0x1c) = iVar3 >> 0xf;
        *(int *)(iVar4 + 0x1a) = iVar3;
        uVar5 = *(undefined2 *)(iVar4 + 0x1c);
        uVar2 = FUN_1000_199e();
        *(undefined2 *)(iVar4 + 0x1c) = uVar5;
        *(undefined2 *)(iVar4 + 0x1a) = uVar2;
        iVar3 = *(int *)(iVar4 + 0x24);
        *(int *)(iVar4 + 0x20) = iVar3 >> 0xf;
        *(int *)(iVar4 + 0x1e) = iVar3;
        uVar5 = *(undefined2 *)(iVar4 + 0x20);
        uVar2 = FUN_1000_199e();
        *(undefined2 *)(iVar4 + 0x20) = uVar5;
        *(undefined2 *)(iVar4 + 0x1e) = uVar2;
        FUN_28eb_3328(iVar4,in_DX);
      }
    }
  }
  return;
}

