// TIM2.EXE: FUN_4340_1a32 @ file 0x04A032 Ghidra 0x44E32
// Subsystem: misc | Size: 543 bytes


char * __cdecl16far FUN_4340_1a32(undefined4 param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined2 uVar7;
  undefined1 local_1e [4];
  int local_1a;
  int local_18;
  int *local_14;
  undefined2 local_12;
  byte local_f;
  int local_e;
  int local_c;
  undefined4 local_a;
  undefined4 local_6;
  
  if ((((int)param_1 == 0 && param_1._2_2_ == 0) ||
      (*(int *)((int)param_1 + 0x10) == 0 && *(int *)((int)param_1 + 0x12) == 0)) ||
     (iVar4 = FUN_4340_10fe((int)param_1,param_1._2_2_,local_1e), iVar4 == 0)) {
    return (char *)0x0;
  }
  local_c = *(int *)((int)param_1 + 4);
  iVar4 = *(int *)((int)param_1 + 6);
  if ((*(byte *)((int)param_1 + 0xd) & 0x11) != 0) {
    local_c = local_c + (*(int *)((int)param_1 + 8) - local_1a) / 2;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 2) != 0) {
    iVar4 = iVar4 + (*(int *)((int)param_1 + 10) - local_18) / 2;
  }
  local_6 = (int *)CONCAT22(local_12,local_14);
  while( true ) {
    uVar7 = (undefined2)((ulong)local_6 >> 0x10);
    piVar6 = (int *)local_6;
    local_a = (byte *)CONCAT22(piVar6[3],(byte *)piVar6[2]);
    if (((byte *)piVar6[2] == (byte *)0x0 && piVar6[3] == 0) || (*local_a == 0)) break;
    local_f = *local_a;
    *local_a = 0;
    iVar5 = FUN_4340_1640((int)param_1,param_1._2_2_,*local_6,piVar6[1]);
    iVar4 = iVar4 + iVar5;
    *local_a = local_f;
    if (param_3 < iVar4) break;
    local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 2);
  }
  uVar7 = (undefined2)((ulong)local_6 >> 0x10);
  piVar6 = (int *)local_6;
  local_a = (byte *)CONCAT22(piVar6[3],(byte *)piVar6[2]);
  if ((byte *)piVar6[2] != (byte *)0x0 || piVar6[3] != 0) {
    do {
      pbVar2 = local_a;
      pbVar1 = (byte *)local_a + -1;
      local_a = (byte *)CONCAT22(local_a._2_2_,pbVar1);
      if (pbVar1 <= (byte *)*local_6) break;
    } while (*local_a < 0x21);
    local_f = *pbVar2;
    *pbVar2 = 0;
    local_a = pbVar2;
  }
  iVar4 = 0;
  if ((*(byte *)((int)param_1 + 0xd) & 0x18) != 0) {
    iVar4 = FUN_4340_1602((int)param_1,param_1._2_2_,*local_6,piVar6[1]);
    iVar4 = local_1a - iVar4;
    if ((*(byte *)((int)param_1 + 0xd) & 0x10) == 0) {
      if ((*(byte *)((int)param_1 + 0xd) & 1) == 0) {
        iVar4 = iVar4 + (*(int *)((int)param_1 + 8) - local_1a);
      }
    }
    else {
      iVar4 = iVar4 / 2;
    }
  }
  if ((byte *)local_a != (byte *)0x0 || local_a._2_2_ != 0) {
    *local_a = local_f;
  }
  if ((param_2 < local_c + iVar4) || (**(char **)local_6 == '\0')) {
    return (char *)*local_6;
  }
  local_a = (byte *)CONCAT22(((int *)local_6)[1],(char *)(*local_6 + 1));
  do {
    pcVar3 = (char *)local_a;
    local_a = (byte *)CONCAT22(local_a._2_2_,(byte *)local_a + 1);
    if (*pcVar3 == '\0') break;
    local_f = *local_a;
    *local_a = '\0';
    local_e = FUN_4340_1602((int)param_1,param_1._2_2_,*local_6,((int *)local_6)[1]);
    *local_a = local_f;
    if (param_2 < local_c + iVar4 + local_e) break;
    uVar7 = (undefined2)((ulong)local_6 >> 0x10);
    piVar6 = (int *)local_6;
  } while ((piVar6[2] == 0 && piVar6[3] == 0) || ((byte *)local_a < (char *)piVar6[2]));
  return (char *)((byte *)local_a + -1);
}

