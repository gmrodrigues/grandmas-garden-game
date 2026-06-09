// TIM2.EXE: FUN_4a54_10a2 @ file 0x0507E2 Ghidra 0x4B5E2
// Subsystem: misc | Size: 252 bytes


void __cdecl16near FUN_4a54_10a2(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = DAT_5b41_2858;
  if (param_3 != 0 || param_4 != 0) {
    uVar3 = *DAT_5b41_2858;
    uVar1 = DAT_5b41_2858[1];
    *DAT_5b41_2858 = uVar3 + 4;
    puVar2[1] = uVar1 + (0xfffb < uVar3);
    uVar3 = *(uint *)(puVar2[2] +
                     (((uVar3 >> 1 | (uint)((uVar1 & 1) != 0) << 0xf) >> 1 |
                      (uint)((uVar1 >> 1 & 1) != 0) << 0xf) >> 1 |
                     (uint)((uVar1 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar3 & 7);
    if ((uVar3 & 8) == 0) {
      FUN_4a54_119f(param_1,param_2,param_3 >> 1,param_4 >> 1);
    }
    else {
      FUN_4a54_10a2();
    }
    if ((uVar3 & 4) == 0) {
      FUN_4a54_119f((param_3 >> 1) + param_1,param_2,param_3 + 1 >> 1,param_4 >> 1);
    }
    else {
      FUN_4a54_10a2();
    }
    if ((uVar3 & 2) == 0) {
      FUN_4a54_119f(param_1,(param_4 >> 1) + param_2,param_3 >> 1,param_4 + 1 >> 1);
    }
    else {
      FUN_4a54_10a2();
    }
    if ((uVar3 & 1) == 0) {
      FUN_4a54_119f((param_3 >> 1) + param_1,(param_4 >> 1) + param_2,param_3 + 1 >> 1,
                    param_4 + 1 >> 1);
    }
    else {
      FUN_4a54_10a2();
    }
    return;
  }
  return;
}

