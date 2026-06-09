// TIM2.EXE: FUN_31f7_a080 @ file 0x0411F0 Ghidra 0x3BFF0
// Subsystem: gfx | Size: 111 bytes


undefined2 __cdecl16far FUN_31f7_a080(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  uVar3 = *(undefined2 *)(iVar4 + 0x9c);
  iVar1 = *(int *)(iVar4 + 0x9a);
  iVar2 = *(int *)(iVar4 + 0xa2);
  if ((iVar2 == 0) || (iVar2 == 4)) {
    if (*(int *)(iVar1 + 0x4a) < *(int *)(iVar1 + 0x48)) {
      if (iVar2 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
    }
    else if (iVar2 == 0) {
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
    }
    FUN_553b_00cf(0x31f7,iVar4,uVar6,iVar1,uVar3,uVar5);
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

