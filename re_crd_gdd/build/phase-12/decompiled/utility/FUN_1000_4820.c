// TIM2.EXE: FUN_1000_4820 @ file 0x019A20 Ghidra 0x14820
// Subsystem: utility | Size: 216 bytes


uint __cdecl16far FUN_1000_4820(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 0xffff;
  }
  if (*param_1 < 1) {
    if (((*param_1 < 0) || ((param_1[1] & 0x110U) != 0)) || ((*(byte *)(param_1 + 1) & 1) == 0)) {
      param_1[1] = param_1[1] | 0x10;
      return 0xffff;
    }
    param_1[1] = param_1[1] | 0x80;
    if (param_1[3] == 0) {
      do {
        if ((*(byte *)((int)param_1 + 3) & 2) != 0) {
          FUN_1000_4764();
        }
        iVar3 = FUN_1000_509b((int)(char)param_1[2],(undefined1 *)&DAT_5b41_2a70,1);
        if (iVar3 == 0) {
          iVar3 = FUN_1000_3cfa((int)(char)param_1[2]);
          if (iVar3 != 1) {
            param_1[1] = param_1[1] | 0x10;
            return 0xffff;
          }
          param_1[1] = param_1[1] & 0xfe7fU | 0x20;
          return 0xffff;
        }
      } while ((DAT_5b41_2a70 == 0xd) && ((*(byte *)(param_1 + 1) & 0x40) == 0));
      param_1[1] = param_1[1] & 0xffdf;
      bVar2 = DAT_5b41_2a70;
      goto LAB_1000_48f2;
    }
    iVar3 = FUN_1000_47a1(param_1);
    if (iVar3 != 0) {
      return 0xffff;
    }
    *param_1 = *param_1 + -1;
  }
  else {
    *param_1 = *param_1 + -1;
  }
  pbVar1 = (byte *)param_1[5];
  param_1[5] = param_1[5] + 1;
  bVar2 = *pbVar1;
LAB_1000_48f2:
  return (uint)bVar2;
}

