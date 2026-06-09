// TIM2.EXE: FUN_3f2b_0a39 @ file 0x044EE9 Ghidra 0x3FCE9
// Subsystem: sound | Size: 110 bytes


undefined2 __cdecl16far FUN_3f2b_0a39(undefined2 param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  int in_DX;
  undefined2 uVar4;
  
  uVar4 = 0;
  iVar3 = FUN_3f2b_0b8e(param_1,0);
  if (iVar3 != 0 || in_DX != 0) {
    if (*(int *)(iVar3 + 2) != 0) {
      uVar1 = DAT_5b41_1b4c + 1;
      DAT_5b41_1b4e = DAT_5b41_1b4e + (uint)(0xfffe < DAT_5b41_1b4c);
      DAT_5b41_1b4c = uVar1;
      *(int *)(iVar3 + 8) = DAT_5b41_1b4e;
      *(uint *)(iVar3 + 6) = uVar1;
      if (*(int *)(iVar3 + 4) != 0) {
        puVar2 = (undefined2 *)((int)DAT_5b41_1b3e + *(int *)(iVar3 + 4) * 4);
        iVar3 = (*(code *)*puVar2)((char *)s_PROAUDIO_DRV_554c_3f20 + 0xb,param_1);
        if (iVar3 != 0) {
          uVar4 = 1;
        }
      }
    }
  }
  return uVar4;
}

