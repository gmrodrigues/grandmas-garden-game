// TIM2.EXE: FUN_28eb_2ca2 @ file 0x030D52 Ghidra 0x2BB52
// Subsystem: misc | Size: 171 bytes


void __cdecl16far FUN_28eb_2ca2(undefined4 param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  iVar2 = (int)param_1;
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  if (((DAT_5b41_0939 != 8) && (DAT_5b41_0939 != 7)) || (DAT_5b41_0937 != 0x1000)) {
    if ((*(int *)(iVar2 + 0x58) != 0) && (*(int *)(iVar2 + 8) != 8)) {
      FUN_28eb_2550(*(undefined2 *)(*(int *)(iVar2 + 0x58) + 2),
                    *(undefined2 *)(*(int *)(iVar2 + 0x58) + 4));
    }
    if (((*(int *)(iVar2 + 8) != 10) && (*(int *)(iVar2 + 8) != 7)) && (*(int *)(iVar2 + 8) != 0x4c)
       ) {
      for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
        iVar3 = iVar2 + iVar4 * 2;
        if (*(int *)(iVar3 + 0x76) != 0) {
          puVar1 = (undefined2 *)*(int *)(iVar3 + 0x76);
          FUN_28eb_25df(*puVar1,puVar1[1],0);
        }
      }
    }
  }
  *(uint *)(iVar2 + 10) = *(uint *)(iVar2 + 10) & 0x7fff;
  *(uint *)(iVar2 + 0xe) = *(uint *)(iVar2 + 0xe) & 0xffbf;
  FUN_28eb_2a23(iVar2,uVar5);
  FUN_28eb_2a59(iVar2,uVar5,(undefined2 *)&DAT_5b41_055f,0);
  return;
}

