// TIM2.EXE: FUN_31f7_a336 @ file 0x0414A6 Ghidra 0x3C2A6
// Subsystem: sound | Size: 165 bytes


void __cdecl16far FUN_31f7_a336(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_1aa2 == 0) {
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      uVar3 = FUN_4551_0370(DAT_5b41_0a86,((undefined2 *)&DAT_554c_3cd0)[iVar1]);
      ((undefined2 *)&DAT_5b41_1aa2)[iVar1] = uVar3;
    }
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) == 0) {
    *(undefined2 *)(iVar1 + 0x10) = 1;
    *(undefined2 *)(iVar1 + 0xa8) = 1;
  }
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    if (*(int *)(iVar1 + 0x10) == ((undefined2 *)&DAT_5b41_1aa2)[iVar2]) {
      *(undefined2 *)(iVar1 + 0xb4) = ((undefined2 *)&DAT_554c_3cc4)[iVar2];
    }
  }
  *(undefined1 *)(iVar1 + 0x7a) = 0x10;
  *(undefined1 *)(iVar1 + 0x7b) = 1;
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46);
  FUN_28eb_3670(iVar1,uVar3);
  return;
}

