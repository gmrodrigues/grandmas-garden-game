// TIM2.EXE: FUN_49fc_0070 @ file 0x04F230 Ghidra 0x4A030
// Subsystem: misc | Size: 915 bytes


int * __cdecl16far FUN_49fc_0070(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined1 local_a2;
  char local_a1 [14];
  char acStack_93 [81];
  undefined1 local_42 [21];
  byte local_2d;
  char local_24 [14];
  int local_16;
  int local_14;
  int *local_12;
  int local_10;
  int local_e;
  int local_c;
  undefined4 local_a;
  undefined4 local_6;
  
  if (DAT_5452_0000 == (int *)0x0 && DAT_5452_0002 == 0) {
    FUN_460e_074f(0x5fc2);
    if ((param_4 & 0x80) != 0) {
      for (local_16 = 1; local_16 < 0x1b; local_16 = local_16 + 1) {
        iVar1 = FUN_49fc_0518(local_16);
        if (iVar1 != 0) {
          FUN_4340_0a29(&local_a2);
          local_a1[0] = (char)local_16 + '@';
          FUN_460e_0290(0x5fc2,0,&local_a2);
        }
      }
    }
    iVar1 = (int)param_1;
    uVar5 = (undefined2)((ulong)param_1 >> 0x10);
    if ((param_4 & 1) != 0) {
      FUN_4340_0a29(acStack_93 + 1);
      if ((acStack_93[1] != '\0') &&
         (iVar3 = FUN_4340_0a09(acStack_93 + 1), acStack_93[iVar3] != '\\')) {
        FUN_4340_0abb(acStack_93 + 1);
      }
      FUN_4340_0abb(acStack_93 + 1);
      if ((*(char *)(iVar1 + 1) != ':') ||
         (((*(char *)(iVar1 + 2) != '\0' && (*(char *)(iVar1 + 2) != '\\')) ||
          (*(char *)(iVar1 + 3) != '\0')))) {
        FUN_460e_0290(0x5fc2,0,0x3ffb,0x554c);
      }
      local_14 = FUN_1000_3f20(acStack_93 + 1,local_42,0x10);
      while (local_14 == 0) {
        if (((local_2d & 0x10) != 0) && (local_24[0] != '.')) {
          local_a2 = 0x3c;
          FUN_4340_0a29(local_a1);
          FUN_4340_0abb(&local_a2);
          FUN_460e_0290(0x5fc2,0,&local_a2);
        }
        local_14 = FUN_1000_3f57(local_42);
      }
    }
    FUN_4340_0a29(acStack_93 + 1);
    if ((acStack_93[1] != '\0') &&
       (iVar1 = FUN_4340_0a09(acStack_93 + 1), acStack_93[iVar1] != '\\')) {
      FUN_4340_0abb(acStack_93 + 1);
    }
    if (param_2 == 0 && param_3 == 0) {
      param_3 = 0x554c;
    }
    FUN_4340_0abb(acStack_93 + 1);
    local_14 = FUN_1000_3f20(acStack_93 + 1,local_42,0);
    while (local_14 == 0) {
      FUN_460e_0290(0x5fc2,0,local_24);
      local_14 = FUN_1000_3f57(local_42);
    }
    DAT_5452_0000 = (int *)FUN_460e_097a(0x5fc2);
    DAT_5452_0002 = param_3;
    if (DAT_5452_0000 != (int *)0x0 || param_3 != 0) {
      if ((param_4 & 0x30) == 0) {
        return DAT_5452_0000;
      }
      local_6 = (int *)CONCAT22(param_3,DAT_5452_0000);
      local_12 = DAT_5452_0000;
      local_10 = param_3;
      while( true ) {
        iVar1 = (int)((ulong)local_6 >> 0x10);
        if (*local_6 == 0 && ((int *)local_6)[1] == 0) break;
        local_a = (int *)CONCAT22(iVar1,(int *)local_6 + 2);
        while( true ) {
          uVar5 = (undefined2)((ulong)local_a >> 0x10);
          if (*local_a == 0 && ((int *)local_a)[1] == 0) break;
          iVar3 = 0;
          if ((**(char **)local_6 == '<') && (**(char **)local_a != '<')) {
            if (**(char **)local_a == '[') {
              iVar3 = 1;
            }
            else {
              iVar3 = -1;
            }
          }
          if ((**(char **)local_6 == '[') && (**(char **)local_a != '[')) {
            iVar3 = -1;
          }
          if ((iVar3 == 0) && ((param_4 & 0x20) != 0)) {
            uVar5 = FUN_4340_0d3f(*local_a,((int *)local_a)[1],0x2e);
            uVar5 = FUN_4340_0d3f(*local_6,((int *)local_6)[1],0x2e,uVar5,iVar1);
            iVar3 = FUN_4340_0b8a(uVar5,iVar1);
          }
          if (iVar3 == 0) {
            iVar3 = FUN_4340_0b8a(*local_6,((int *)local_6)[1],*local_a,((int *)local_a)[1]);
          }
          piVar2 = (int *)local_a;
          uVar5 = (undefined2)((ulong)local_a >> 0x10);
          if (0 < iVar3) {
            uVar4 = (undefined2)((ulong)local_6 >> 0x10);
            iVar1 = ((int *)local_6)[1];
            local_e = *local_6;
            iVar3 = *local_a;
            ((int *)local_6)[1] = piVar2[1];
            *local_6 = iVar3;
            piVar2[1] = iVar1;
            *local_a = local_e;
            local_c = iVar1;
          }
          local_a = (int *)CONCAT22(uVar5,piVar2 + 2);
        }
        local_6 = (int *)CONCAT22(local_6._2_2_,(int *)local_6 + 2);
      }
      return local_12;
    }
  }
  return (int *)0x0;
}

