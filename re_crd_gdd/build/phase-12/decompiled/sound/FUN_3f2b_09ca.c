// TIM2.EXE: FUN_3f2b_09ca @ file 0x044E7A Ghidra 0x3FC7A
// Subsystem: sound | Size: 111 bytes


undefined2 __cdecl16far FUN_3f2b_09ca(undefined2 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int in_DX;
  
  iVar2 = FUN_3f2b_0b8e(param_1,0);
  if ((iVar2 != 0 || in_DX != 0) && (*(int *)(iVar2 + 2) != 0)) {
    *(int *)(iVar2 + 10) = *(int *)(iVar2 + 10) + param_2;
    if ((*(int *)(iVar2 + 8) != DAT_5b41_1b4e) || (*(uint *)(iVar2 + 6) != DAT_5b41_1b4c)) {
      uVar1 = DAT_5b41_1b4c + 1;
      DAT_5b41_1b4e = DAT_5b41_1b4e + (uint)(0xfffe < DAT_5b41_1b4c);
      DAT_5b41_1b4c = uVar1;
      *(int *)(iVar2 + 8) = DAT_5b41_1b4e;
      *(uint *)(iVar2 + 6) = uVar1;
    }
    return *(undefined2 *)(iVar2 + 10);
  }
  return 0;
}

