// TIM2.EXE: FUN_31f7_66eb @ file 0x03D85B Ghidra 0x3865B
// Subsystem: misc | Size: 145 bytes


undefined2 __cdecl16far FUN_31f7_66eb(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar1 = *(int *)(iVar3 + 0xa2);
  if (((*(int *)(iVar3 + 8) == 4) || (*(int *)(iVar3 + 8) == 0x4f)) || (*(int *)(iVar3 + 8) == 0x6d)
     ) {
    iVar2 = FUN_31f7_688a(*(undefined2 *)(iVar3 + 0x9a),*(undefined2 *)(iVar3 + 0x9c));
    if ((((*(int *)(iVar2 * 2 + 0x3b6a) + *(int *)(iVar3 + 0xa0) & 0x8000U) == 0) && (iVar1 == 2))
       && ((*(byte *)(iVar3 + 0xd) & 0x10) != 0)) {
      if (*(int *)(iVar3 + 8) == 0x4f) {
        *(undefined2 *)(iVar3 + 0x16) = 2;
      }
      else {
        *(undefined2 *)(iVar3 + 0x16) = 1;
      }
    }
  }
  return 1;
}

