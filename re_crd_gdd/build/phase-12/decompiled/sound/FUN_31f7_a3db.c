// TIM2.EXE: FUN_31f7_a3db @ file 0x04154B Ghidra 0x3C34B
// Subsystem: sound | Size: 178 bytes


void __cdecl16far FUN_31f7_a3db(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  if (*(int *)(iVar3 + 0x10) != DAT_5b41_1aa2) {
    if (*(int *)(iVar3 + 0xb4) == 0) {
      iVar4 = 0;
    }
    else if (*(int *)(iVar3 + 0xb4) < 100) {
      iVar4 = 1;
    }
    else if (*(int *)(iVar3 + 0xb4) < 200) {
      iVar4 = 2;
    }
    else if (*(int *)(iVar3 + 0xb4) < 300) {
      iVar4 = 3;
    }
    else if (*(int *)(iVar3 + 0xb4) < 500) {
      iVar4 = 4;
    }
    else {
      iVar4 = 5;
    }
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    iVar2 = FUN_4551_0308(DAT_5b41_0a86,*(undefined2 *)(iVar3 + 0x10));
    if (iVar2 != 0) {
      *(undefined2 *)(iVar3 + 0x10) = ((undefined2 *)&DAT_5b41_1aa2)[iVar4];
    }
    piVar1 = (int *)(iVar3 + 0xb4);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (SBORROW2(iVar4,1) != *piVar1 < 0) {
      *(undefined2 *)(iVar3 + 0xb4) = 0;
    }
    FUN_28eb_3328(iVar3,uVar5);
  }
  return;
}

