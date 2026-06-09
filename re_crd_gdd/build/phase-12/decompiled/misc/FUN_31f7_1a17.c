// TIM2.EXE: FUN_31f7_1a17 @ file 0x038B87 Ghidra 0x33987
// Subsystem: misc | Size: 132 bytes


void __cdecl16far FUN_31f7_1a17(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_198e == 0) {
    DAT_5b41_198e = FUN_4551_0370(DAT_5b41_09c8,4);
    DAT_5b41_1990 = FUN_4551_0370(DAT_5b41_09c8,5);
    DAT_5b41_1992 = FUN_4551_0370(DAT_5b41_09c8,0xd);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    uVar1 = 0xc;
  }
  else {
    uVar1 = 0x12;
  }
  *(undefined1 *)(iVar2 + 0x5a) = uVar1;
  *(undefined1 *)(iVar2 + 0x5b) = 0x12;
  *(undefined2 *)(iVar2 + 0x5c) = 8;
  *(undefined2 *)(iVar2 + 0x98) =
       *(undefined2 *)*(undefined2 *)(*(int *)(*(int *)(iVar2 + 8) * 2 + 0x302) + 0x46);
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

