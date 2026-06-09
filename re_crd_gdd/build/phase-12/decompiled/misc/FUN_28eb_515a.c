// TIM2.EXE: FUN_28eb_515a @ file 0x03320A Ghidra 0x2E00A
// Subsystem: misc | Size: 89 bytes


undefined2 __cdecl16far FUN_28eb_515a(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 8);
  if (iVar1 == 6) {
    uVar3 = FUN_31f7_1148(iVar2,uVar3);
  }
  else if (iVar1 == 0xc) {
    uVar3 = FUN_31f7_19d9(iVar2,uVar3);
  }
  else if (iVar1 == 0x2a) {
    uVar3 = FUN_31f7_5efc(iVar2,uVar3);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

