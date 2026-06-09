// TIM2.EXE: FUN_31f7_7b9d @ file 0x03ED0D Ghidra 0x39B0D
// Subsystem: misc | Size: 232 bytes


undefined2 __cdecl16far FUN_31f7_7b9d(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar4 + 0x9c);
  iVar2 = *(int *)(iVar4 + 0x9a);
  uVar3 = FUN_28eb_0008(iVar2,uVar1,iVar4,uVar5);
  FUN_28eb_3c0f(0x28eb,iVar4,uVar5,uVar3,0x1c00);
  if ((*(int *)(iVar4 + 8) == 0x36) && (*(int *)(iVar4 + 0x10) < DAT_5b41_09a3)) {
    *(int *)(iVar4 + 0x10) = DAT_5b41_09a3;
  }
  *(undefined2 *)(iVar2 + 0x16) = 1;
  return 0;
}

