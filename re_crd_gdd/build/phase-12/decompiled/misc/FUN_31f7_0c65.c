// TIM2.EXE: FUN_31f7_0c65 @ file 0x037DD5 Ghidra 0x32BD5
// Subsystem: misc | Size: 138 bytes


void __cdecl16far FUN_31f7_0c65(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar2 = (*(int *)(iVar3 + 0x54) + -0x20) / 0x10;
  uVar1 = ((undefined2 *)&DAT_5b41_1960)[iVar2];
  *(undefined2 *)(iVar3 + 0x10) = uVar1;
  *(undefined2 *)(iVar3 + 0xa8) = uVar1;
  *(undefined2 *)(iVar3 + 0x5c) = *(undefined2 *)(iVar2 * 2 + 0x3a26);
  *(undefined2 *)(iVar3 + 0x16) = 0;
  *(undefined2 *)(iVar3 + 0xaa) = 0;
  *(undefined1 *)(iVar3 + 0x5a) = *(undefined1 *)(iVar2 * 4 + 0x3a12);
  *(undefined1 *)(iVar3 + 0x5b) = *(undefined1 *)(iVar2 * 4 + 0x3a14);
  *(undefined2 *)(iVar3 + 0x98) = *(undefined2 *)(iVar2 * 2 + *(int *)(iRam000557cc + 0x46));
  FUN_28eb_3670(iVar3,uVar4);
  return;
}

