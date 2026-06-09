// TIM2.EXE: FUN_406b_0a39 @ file 0x0462E9 Ghidra 0x410E9
// Subsystem: sound | Size: 356 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_406b_0a39(void)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 local_6;
  undefined2 local_4;
  
  if (DAT_554c_5594 == '\0') {
    DAT_5b41_1b84 = DAT_5b41_1b7c;
    local_6 = DAT_5b41_1b7e;
  }
  else {
    FUN_406b_0b9d(&local_4,&local_6);
    DAT_5b41_1b84 = local_4;
  }
  _DAT_5b41_1b88 = DAT_53bd_004e;
  DAT_5b41_1b8a = DAT_53bd_0050;
  DAT_53bd_004e = DAT_53bd_004e & 9;
  DAT_53bd_0050 = DAT_53bd_0050 & 9;
  DAT_5b41_1b98 = DAT_5b41_1b96;
  _DAT_53bd_004a = 0;
  DAT_5b41_1b86 = local_6;
  DAT_5b41_1b92 = FUN_1a9e_4cb7();
  DAT_5b41_1b8e = DAT_5b41_1b92 & 0x7f;
  DAT_5b41_1b90 = DAT_5b41_1b92 >> 8;
  _DAT_5b41_1b94 = 0;
  iVar2 = FUN_1a9e_4d00(0x1d);
  if ((iVar2 != 0) || ((DAT_5b41_1b92 & 0x80) != 0)) {
    _DAT_5b41_1b94 = _DAT_5b41_1b94 | 1;
  }
  iVar2 = FUN_1a9e_4d00(0x38);
  if (iVar2 != 0) {
    _DAT_5b41_1b94 = _DAT_5b41_1b94 | 2;
    iVar2 = FUN_1a9e_4d00(0xe0);
    if (iVar2 != 0) {
      _DAT_5b41_1b94 = _DAT_5b41_1b94 | 8;
    }
  }
  iVar2 = FUN_1a9e_4d00(0x2a);
  if (iVar2 == 0) {
    iVar2 = FUN_1a9e_4d00(0x36);
    if (iVar2 == 0) goto LAB_406b_0b38;
  }
  _DAT_5b41_1b94 = _DAT_5b41_1b94 | 4;
LAB_406b_0b38:
  uVar3 = 0x1a9e;
  if (((DAT_5b41_1b92 & 0x80) == 0) || (DAT_5b41_1b8e < 0x41)) {
    uVar3 = 0x460e;
    bVar1 = FUN_460e_2581(DAT_5b41_1b8e,_DAT_5b41_1b94);
    DAT_5b41_1b8e = (uint)bVar1;
  }
  else {
    DAT_5b41_1b8e = DAT_5b41_1b8e - 0x40;
  }
  if (((_DAT_5b41_1b88 == 0) && (DAT_5b41_1b8a == 0)) && (DAT_5b41_1b92 == 0)) {
    DAT_5b41_1b9c = 0;
  }
  else {
    DAT_5b41_1b9c = 1;
  }
  if (DAT_5b41_1ba2 != (code *)0x0 || DAT_5b41_1ba4 != 0) {
    (*DAT_5b41_1ba2)(uVar3);
  }
  if (DAT_5b41_1b9e != (code *)0x0 || DAT_5b41_1ba0 != 0) {
    (*DAT_5b41_1b9e)(uVar3);
  }
  return;
}

