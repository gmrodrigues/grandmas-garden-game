// TIM2.EXE: FUN_1000_7920 @ file 0x01CB20 Ghidra 0x17920
// Subsystem: utility | Size: 423 bytes


void __cdecl16near FUN_1000_7920(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined2 uVar8;
  undefined2 unaff_SS;
  undefined2 uVar9;
  
  uVar9 = 0x554c;
  puVar7 = &stack0xfffe;
  *(undefined2 *)((int)*(undefined4 *)0x16 + 6) = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)((int)*(undefined4 *)0x16 + 8) = *(undefined2 *)(param_1 + 0x10);
  uVar5 = *(undefined2 *)(param_1 + 0xc);
  while ((*(undefined2 *)(puVar7 + -6) = uVar5, *(int *)(puVar7 + -6) != 0 &&
         (*(int *)(puVar7 + -6) != *(int *)(puVar7 + 6)))) {
    *(undefined2 *)(puVar7 + -0x10) = *(undefined2 *)(puVar7 + -6);
    *(undefined2 *)(puVar7 + -8) =
         *(undefined2 *)((int)*(undefined4 *)(puVar7 + -4) + *(int *)(puVar7 + -0x10));
    *(int *)(puVar7 + -0x10) = *(int *)(puVar7 + -0x10) + 2;
    *(undefined2 *)(puVar7 + -0xe) =
         *(undefined2 *)((int)*(undefined4 *)(puVar7 + -4) + *(int *)(puVar7 + -0x10));
    *(int *)(puVar7 + -0x10) = *(int *)(puVar7 + -0x10) + 2;
    *(undefined2 *)(*(int *)(puVar7 + 4) + 0xc) = *(undefined2 *)(puVar7 + -8);
    switch(*(undefined2 *)(puVar7 + -0xe)) {
    case 0:
      uVar8 = (undefined2)((ulong)*(undefined4 *)(puVar7 + -4) >> 0x10);
      iVar6 = (int)*(undefined4 *)(puVar7 + -4) + *(int *)(puVar7 + -0x10);
      uVar5 = *(undefined2 *)(iVar6 + 4);
      *(undefined2 *)&DAT_5dfa_0004 = *(undefined2 *)(iVar6 + 6);
      *(undefined2 *)&DAT_5dfa_0002 = uVar5;
      *(undefined2 *)(*(int *)(puVar7 + 4) + 0x12) = 1;
      (*(code *)*(undefined2 *)&DAT_5dfa_0002)(0x1000);
      *(undefined2 *)(*(int *)(puVar7 + 4) + 0x12) = 0;
      break;
    case 4:
      uVar8 = *(undefined2 *)0x18;
      uVar5 = *(undefined2 *)0x16;
      while( true ) {
        *(undefined2 *)(puVar7 + -0x16) = uVar8;
        *(undefined2 *)(puVar7 + -0x18) = uVar5;
        piVar2 = *(int **)(puVar7 + -0x18);
        iVar6 = ((int *)piVar2)[1];
        iVar1 = *piVar2;
        *(int *)(puVar7 + -0x12) = iVar6;
        *(int *)(puVar7 + -0x14) = iVar1;
        if ((iVar1 == 0 && iVar6 == 0) ||
           ((*(int *)((int)*(undefined4 *)(puVar7 + -0x14) + 0x22) == *(int *)(puVar7 + 4) &&
            (*(int *)((int)*(undefined4 *)(puVar7 + -0x14) + 0x28) == *(int *)(puVar7 + -6)))))
        break;
        uVar8 = *(undefined2 *)(puVar7 + -0x12);
        uVar5 = *(undefined2 *)(puVar7 + -0x14);
      }
      puVar3 = *(undefined2 **)(puVar7 + -0x14);
      uVar5 = *puVar3;
      puVar4 = *(undefined2 **)(puVar7 + -0x18);
      ((undefined2 *)puVar4)[1] = ((undefined2 *)puVar3)[1];
      *puVar4 = uVar5;
      FUN_1000_73f2(*(undefined2 *)(puVar7 + -0x14),*(undefined2 *)(puVar7 + -0x12));
      puVar3 = (undefined2 *)((int)*(undefined4 *)(puVar7 + -0x14) + 0x18);
      (*(code *)*puVar3)(0x1000,*(undefined2 *)(puVar7 + -0x14),*(undefined2 *)(puVar7 + -0x12));
      break;
    case 5:
      *(undefined2 *)(puVar7 + -0x1a) =
           *(undefined2 *)((int)*(undefined4 *)(puVar7 + -4) + *(int *)(puVar7 + -0x10));
      *(int *)(puVar7 + -0x10) = *(int *)(puVar7 + -0x10) + 2;
      uVar5 = *(undefined2 *)((int)*(undefined4 *)(puVar7 + -4) + *(int *)(puVar7 + -0x10));
      *(undefined2 *)(puVar7 + -0x1c) = uVar9;
      *(undefined2 *)(puVar7 + -0x1e) = uVar5;
      uVar5 = *(undefined2 *)(puVar7 + -0x1e);
      *(undefined2 *)(puVar7 + -0x1c) = *(undefined2 *)(puVar7 + -2);
      *(undefined2 *)(puVar7 + -0x1e) = uVar5;
      FUN_1000_84f2(*(undefined2 *)(puVar7 + -0x1e),*(undefined2 *)(puVar7 + -0x1c),
                    *(int *)(puVar7 + -0x1a),*(int *)(puVar7 + -0x1a) >> 0xf,
                    *(undefined2 *)(puVar7 + 4),*(undefined2 *)(puVar7 + -10));
    }
    uVar5 = *(undefined2 *)(puVar7 + -8);
  }
  return;
}

