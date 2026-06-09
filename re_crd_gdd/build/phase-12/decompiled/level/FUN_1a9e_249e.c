// TIM2.EXE: FUN_1a9e_249e @ file 0x02207E Ghidra 0x1CE7E
// Subsystem: level | Size: 214 bytes


void __cdecl16far FUN_1a9e_249e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  
  uVar6 = DAT_554c_4460;
  iVar5 = DAT_554c_445e;
  if (DAT_554c_42df != '\0') {
    iVar1 = DAT_554c_445e + 0x300;
    FUN_1a9e_2574(iVar1,DAT_554c_4460,DAT_554c_445e,DAT_554c_4460,0x300);
    for (iVar7 = 0; iVar7 < DAT_554c_4e8e; iVar7 = iVar7 + 1) {
      iVar2 = ((undefined2 *)&DAT_5b41_1d8e)[iVar7];
      iVar3 = ((undefined2 *)&DAT_5b41_1d7a)[iVar7];
      iVar4 = ((undefined2 *)&DAT_5b41_1d66)[iVar7];
      FUN_1a9e_2574(iVar5 + iVar2,uVar6,iVar2 + iVar4 + iVar1,uVar6,(iVar3 - iVar2) - iVar4);
      FUN_1a9e_2574(iVar5 + (iVar3 - iVar4),uVar6,iVar1 + iVar2,uVar6,iVar4);
    }
    if (DAT_554c_4e8e != 0) {
      (*DAT_554c_4dfe)(0x1a9e,0,0x100,DAT_554c_4e92,DAT_554c_4e90);
    }
  }
  return;
}

