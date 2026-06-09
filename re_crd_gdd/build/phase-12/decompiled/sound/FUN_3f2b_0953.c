// TIM2.EXE: FUN_3f2b_0953 @ file 0x044E03 Ghidra 0x3FC03
// Subsystem: sound | Size: 119 bytes


undefined2 __cdecl16far FUN_3f2b_0953(undefined2 param_1,undefined2 param_2)

{
  uint uVar1;
  int iVar2;
  int in_DX;
  
  iVar2 = FUN_3f2b_0b8e(param_1,0);
  if ((iVar2 != 0 || in_DX != 0) && (*(int *)(iVar2 + 2) != 0)) {
    *(undefined2 *)(iVar2 + 0x10) = 0;
    *(undefined2 *)(iVar2 + 0xe) = 0;
    *(undefined2 *)(iVar2 + 0xe) = param_2;
    if ((*(int *)(iVar2 + 8) != DAT_5b41_1b4e) || (*(uint *)(iVar2 + 6) != DAT_5b41_1b4c)) {
      uVar1 = DAT_5b41_1b4c + 1;
      DAT_5b41_1b4e = DAT_5b41_1b4e + (uint)(0xfffe < DAT_5b41_1b4c);
      DAT_5b41_1b4c = uVar1;
      *(int *)(iVar2 + 8) = DAT_5b41_1b4e;
      *(uint *)(iVar2 + 6) = uVar1;
    }
    return 1;
  }
  return 0;
}

