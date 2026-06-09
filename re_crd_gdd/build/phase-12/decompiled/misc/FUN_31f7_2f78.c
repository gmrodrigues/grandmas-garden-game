// TIM2.EXE: FUN_31f7_2f78 @ file 0x03A0E8 Ghidra 0x34EE8
// Subsystem: misc | Size: 153 bytes


void __cdecl16far FUN_31f7_2f78(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  if (DAT_5b41_19bc == 0) {
    iVar2 = 3;
    for (iVar3 = 0; iVar3 < 5; iVar3 = iVar3 + 1) {
      do {
        iVar2 = iVar2 + 1;
        if (iVar2 == 0) break;
        iVar1 = FUN_4551_0308(DAT_5b41_09e2,iVar2);
      } while (iVar1 == 0);
      ((undefined2 *)&DAT_5b41_19ba)[iVar3] = iVar2;
    }
  }
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  *(undefined1 *)(iVar2 + 0x5a) = 0x49;
  *(undefined1 *)(iVar2 + 0x5b) = 0xe;
  *(undefined2 *)(iVar2 + 0x5c) = 8;
  *(undefined2 *)(iVar2 + 0x98) =
       *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46);
  FUN_28eb_3670(iVar2,uVar4);
  *(undefined2 *)(iVar2 + 0x10) = 0;
  if (*(int *)(iVar2 + 0x6e) != 0 || *(int *)(iVar2 + 0x70) != 0) {
    *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | 1;
  }
  if (*(int *)(iVar2 + 0x72) != 0 || *(int *)(iVar2 + 0x74) != 0) {
    *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | 2;
  }
  return;
}

