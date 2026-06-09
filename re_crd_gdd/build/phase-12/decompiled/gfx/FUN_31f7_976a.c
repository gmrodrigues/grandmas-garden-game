// TIM2.EXE: FUN_31f7_976a @ file 0x0408DA Ghidra 0x3B6DA
// Subsystem: gfx | Size: 88 bytes


undefined2 __cdecl16far FUN_31f7_976a(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  uVar3 = *(undefined2 *)(iVar4 + 0x9c);
  uVar1 = *(undefined2 *)(iVar4 + 0x9a);
  if ((*(int *)(iVar4 + 0xa2) == 0) || (*(int *)(iVar4 + 0xa2) == 4)) {
    uVar2 = FUN_553b_00ca(0x31f7,uVar1,uVar3);
    FUN_553b_00cf(0x553b,iVar4,uVar5,uVar1,uVar3,uVar2);
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

