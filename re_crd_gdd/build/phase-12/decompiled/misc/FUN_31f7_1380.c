// TIM2.EXE: FUN_31f7_1380 @ file 0x0384F0 Ghidra 0x332F0
// Subsystem: misc | Size: 113 bytes


undefined2 __cdecl16far FUN_31f7_1380(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar4 + 0x9c);
  iVar2 = *(int *)(iVar4 + 0x9a);
  bVar3 = DAT_5b41_0975 <= *(int *)(iVar2 + 0x10);
  if ((*(int *)(iVar4 + 8) != 0xb) &&
     (*(int *)(iVar2 + 0x10) < (int)((undefined2 *)&DAT_5b41_0977)[bVar3])) {
    *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_0977)[bVar3];
    *(undefined2 *)(iVar2 + 0xae) = 0;
    FUN_28eb_3328(iVar2,uVar1);
  }
  return 1;
}

