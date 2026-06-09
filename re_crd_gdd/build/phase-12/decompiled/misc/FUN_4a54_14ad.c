// TIM2.EXE: FUN_4a54_14ad @ file 0x050BED Ghidra 0x4B9ED
// Subsystem: misc | Size: 252 bytes


void __cdecl16near FUN_4a54_14ad(int param_1,int param_2,uint param_3,uint param_4)

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
      FUN_4a54_15aa(param_1,param_2,param_3 >> 1,param_4 >> 1);
    }
    else {
      FUN_4a54_14ad();
    }
    if ((uVar3 & 4) == 0) {
      FUN_4a54_15aa((param_3 >> 1) + param_1,param_2,param_3 + 1 >> 1,param_4 >> 1);
    }
    else {
      FUN_4a54_14ad();
    }
    if ((uVar3 & 2) == 0) {
      FUN_4a54_15aa(param_1,(param_4 >> 1) + param_2,param_3 >> 1,param_4 + 1 >> 1);
    }
    else {
      FUN_4a54_14ad();
    }
    if ((uVar3 & 1) == 0) {
      FUN_4a54_15aa((param_3 >> 1) + param_1,(param_4 >> 1) + param_2,param_3 + 1 >> 1,
                    param_4 + 1 >> 1);
    }
    else {
      FUN_4a54_14ad();
    }
    return;
  }
  return;
}

