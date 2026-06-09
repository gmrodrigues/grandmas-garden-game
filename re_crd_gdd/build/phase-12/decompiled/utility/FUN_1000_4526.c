// TIM2.EXE: FUN_1000_4526 @ file 0x019726 Ghidra 0x14526
// Subsystem: utility | Size: 498 bytes


int __cdecl16far FUN_1000_4526(int param_1,char *param_2,uint param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int local_e;
  int local_c;
  int local_a;
  char *local_8;
  char *local_6;
  char *local_4;
  
  local_4 = (char *)FUN_1000_3226(0xa1);
  if (local_4 == (char *)0x0) {
    return 0;
  }
  local_8 = param_2;
  if (((*(byte *)(*param_2 + 0x59c1) & 0xc) == 0) || (param_2[1] != ':')) {
    FUN_1000_1710(&local_e);
    local_c = local_e + 0x40;
  }
  else {
    local_c = (int)*param_2;
    local_e = FUN_1000_21fa(local_c);
    local_e = local_e + -0x40;
    local_8 = local_8 + 2;
  }
  iVar3 = FUN_1000_4507((int)*local_8);
  if (iVar3 == 0) {
    iVar3 = FUN_1000_4906(local_e,local_4,0xa1);
    if (iVar3 == 0) {
      FUN_1000_3157(local_4);
      return 0;
    }
    iVar3 = FUN_1000_54d4(local_4);
    local_6 = local_4 + iVar3;
    iVar3 = FUN_1000_4507((int)local_6[-1]);
    if (iVar3 != 0) goto LAB_1000_45fd;
    *local_6 = '\\';
  }
  else {
    *local_4 = (char)local_c;
    local_6 = local_4 + 1;
    *local_6 = ':';
  }
  local_6 = local_6 + 1;
LAB_1000_45fd:
  FUN_1000_5472(local_6,local_8);
  local_6 = local_4;
  local_8 = local_4;
  do {
    pcVar1 = local_8 + 1;
    local_a = (int)*local_8;
    local_8 = pcVar1;
    if ((local_a == 0) || (iVar3 = FUN_1000_4507(local_a), iVar3 != 0)) {
      if ((local_6[-1] == '.') && (iVar3 = FUN_1000_4507((int)local_6[-2]), iVar3 != 0)) {
        local_6 = local_6 + -2;
      }
      else if (((local_6[-1] == '.') && (local_6[-2] == '.')) &&
              (iVar3 = FUN_1000_4507((int)local_6[-3]), iVar3 != 0)) {
        pcVar2 = local_6 + -3;
        pcVar1 = local_6 + -4;
        local_6 = pcVar2;
        if (*pcVar1 == ':') {
          FUN_1000_3157(local_4);
          return 0;
        }
        do {
          local_6 = local_6 + -1;
          iVar3 = FUN_1000_4507((int)*local_6);
        } while (iVar3 == 0);
      }
      if (local_a == 0) {
        iVar3 = FUN_1000_4507((int)local_6[-1]);
        if (iVar3 != 0) {
          local_6 = local_6 + -1;
        }
        if (local_6[-1] == ':') {
          *local_6 = '\\';
          local_6 = local_6 + 1;
        }
        *local_6 = '\0';
        iVar3 = FUN_1000_54d4(local_4);
        if (param_1 != 0) {
          if (param_3 < iVar3 + 1U) {
            FUN_1000_3157(local_4);
            return 0;
          }
          FUN_1000_5472(param_1,local_4);
          FUN_1000_3157(local_4);
          return param_1;
        }
        iVar3 = FUN_1000_337f(local_4,iVar3 + 1U);
        return iVar3;
      }
    }
    *local_6 = (char)local_a;
    local_6 = local_6 + 1;
  } while( true );
}

