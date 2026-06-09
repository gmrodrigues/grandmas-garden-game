// TIM2.EXE: FUN_31f7_86d9 @ file 0x03F849 Ghidra 0x3A649
// Subsystem: misc | Size: 170 bytes


void __cdecl16far FUN_31f7_86d9(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  iVar4 = (int)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x40;
  if ((*(int *)(iVar2 + 0x16) != 0) && (*(int *)(iVar2 + 0x10) != DAT_5b41_1a6c)) {
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
    if (*(int *)(iVar2 + 0x10) == 2) {
      FUN_28eb_4f3d(iVar2,iVar4,0x1000,0,0,0,0x30);
      iVar3 = iVar2;
      iVar5 = iVar4;
      uVar6 = 0x28eb;
      while( true ) {
        iVar1 = *(int *)(iVar3 + 0x8e);
        iVar3 = *(int *)(iVar3 + 0x8c);
        if (iVar3 == 0 && iVar1 == 0) break;
        *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x3c) + 0x800;
        FUN_549b_007a(uVar6,iVar3,iVar1);
        iVar5 = iVar1;
        uVar6 = 0x549b;
        if (*(int *)(iVar3 + 8) == 0x36) {
          *(undefined2 *)(iVar3 + 0xae) = 1;
        }
      }
      FUN_31f7_8634(iVar2,iVar4);
    }
    FUN_28eb_3328(iVar2,iVar4);
  }
  return;
}

