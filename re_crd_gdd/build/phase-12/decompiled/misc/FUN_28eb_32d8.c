// TIM2.EXE: FUN_28eb_32d8 @ file 0x031388 Ghidra 0x2C188
// Subsystem: misc | Size: 80 bytes


int __cdecl16far FUN_28eb_32d8(int *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  piVar2 = (int *)param_1;
  if (*param_1 == 0 && piVar2[1] == 0) {
    if ((*(byte *)((int)piVar2 + 0xb) & 0x20) == 0) {
      if (((*(byte *)((int)piVar2 + 0xb) & 0x10) == 0) ||
         (iVar1 = DAT_5b41_055f, (param_2 & 0x800) == 0)) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = FUN_28eb_3287(param_2);
    }
  }
  else {
    iVar1 = *param_1;
  }
  return iVar1;
}

