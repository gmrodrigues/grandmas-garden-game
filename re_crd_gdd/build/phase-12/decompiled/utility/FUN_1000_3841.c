// TIM2.EXE: FUN_1000_3841 @ file 0x018A41 Ghidra 0x13841
// Subsystem: utility | Size: 291 bytes


int __cdecl16far FUN_1000_3841(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  int local_6;
  
  FUN_1000_554f();
  iVar1 = DAT_554c_5e28 + -0x5a00;
  iVar3 = *(int *)param_1;
  iVar2 = FUN_1000_1fce();
  local_6 = FUN_1000_1fce();
  local_6 = iVar1 + iVar2 + local_6;
  if ((iVar3 - 0x7bcU & 3) != 0) {
    local_6 = local_6 + 0x5180;
  }
  iVar1 = 0;
  iVar3 = (int)(char)param_1[3];
  while (local_8 = iVar3 + -1, 0 < local_8) {
    iVar1 = iVar1 + *(char *)(iVar3 + 0x5b7c);
    iVar3 = local_8;
  }
  iVar1 = iVar1 + (char)param_1[2] + -1;
  if (('\x02' < (char)param_1[3]) && ((*param_1 & 3) == 0)) {
    iVar1 = iVar1 + 1;
  }
  if (DAT_554c_5e2c != 0) {
    FUN_1000_570b(*(int *)param_1 + -0x7b2,0,iVar1,*(undefined1 *)(param_2 + 1));
  }
  iVar3 = FUN_1000_1fce();
  iVar1 = FUN_1000_1fce();
  return local_6 + iVar3 + iVar1 + (uint)*(byte *)(param_2 + 3);
}

