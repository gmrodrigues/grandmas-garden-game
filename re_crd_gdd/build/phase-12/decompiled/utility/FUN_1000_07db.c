// TIM2.EXE: FUN_1000_07db @ file 0x0159DB Ghidra 0x107DB
// Subsystem: utility | Size: 479 bytes


undefined2 __cdecl16far FUN_1000_07db(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int local_c;
  undefined4 local_6;
  
  if (DAT_5b41_0467 != 0) {
    local_6 = (int *)CONCAT22(((undefined2 *)&DAT_5b41_03ca)[DAT_5b41_0467 * 0xe],
                              (int *)((undefined2 *)&DAT_5b41_03c8)[DAT_5b41_0467 * 0xe]);
    while( true ) {
      uVar5 = (undefined2)((ulong)local_6 >> 0x10);
      piVar2 = (int *)local_6;
      if ((*local_6 == 0 && piVar2[1] == 0) ||
         ((piVar2[1] == DAT_5b41_0463 && (*local_6 == DAT_5b41_0461)))) break;
      local_6 = (int *)CONCAT22(uVar5,piVar2 + 4);
    }
    if ((piVar2[1] == DAT_5b41_0463) && (*local_6 == DAT_5b41_0461)) {
      *param_1 = DAT_5b41_0467;
      iVar1 = piVar2[2];
      param_1[2] = piVar2[3];
      param_1[1] = iVar1;
      param_1[6] = 0;
      param_1[5] = 0;
      param_1[4] = 0;
      param_1[3] = 0;
      return 1;
    }
  }
  iVar1 = DAT_5b41_0465;
  if (DAT_5b41_0465 == 0) {
    iVar1 = 1;
  }
  local_6 = (int *)CONCAT22(((undefined2 *)&DAT_5b41_03ca)[iVar1 * 0xe],
                            (int *)((undefined2 *)&DAT_5b41_03c8)[iVar1 * 0xe]);
  while( true ) {
    uVar5 = (undefined2)((ulong)local_6 >> 0x10);
    piVar2 = (int *)local_6;
    if ((*local_6 == 0 && piVar2[1] == 0) ||
       ((piVar2[1] == DAT_5b41_0463 && (*local_6 == DAT_5b41_0461)))) break;
    local_6 = (int *)CONCAT22(uVar5,piVar2 + 4);
  }
  iVar4 = DAT_5b41_0465 + 1;
  iVar3 = DAT_5b41_0465 + -1;
  while( true ) {
    local_c = iVar3;
    uVar5 = (undefined2)((ulong)local_6 >> 0x10);
    piVar2 = (int *)local_6;
    if (((piVar2[1] == DAT_5b41_0463) && (*local_6 == DAT_5b41_0461)) ||
       ((local_c < 1 && (DAT_5b41_0469 < iVar4)))) break;
    iVar3 = iVar4;
    if (iVar4 <= DAT_5b41_0469) {
      iVar3 = iVar4 + 1;
      local_6 = (int *)CONCAT22(((undefined2 *)&DAT_5b41_03ca)[iVar4 * 0xe],
                                (int *)((undefined2 *)&DAT_5b41_03c8)[iVar4 * 0xe]);
      while( true ) {
        uVar5 = (undefined2)((ulong)local_6 >> 0x10);
        piVar2 = (int *)local_6;
        iVar1 = iVar4;
        if ((*local_6 == 0 && piVar2[1] == 0) ||
           ((piVar2[1] == DAT_5b41_0463 && (*local_6 == DAT_5b41_0461)))) break;
        local_6 = (int *)CONCAT22(uVar5,piVar2 + 4);
      }
    }
    iVar4 = iVar3;
    iVar3 = local_c;
    if (((((int *)local_6)[1] != DAT_5b41_0463) || (*local_6 != DAT_5b41_0461)) && (0 < local_c)) {
      local_6 = (int *)CONCAT22(((undefined2 *)&DAT_5b41_03ca)[local_c * 0xe],
                                (int *)((undefined2 *)&DAT_5b41_03c8)[local_c * 0xe]);
      while( true ) {
        uVar5 = (undefined2)((ulong)local_6 >> 0x10);
        piVar2 = (int *)local_6;
        iVar1 = local_c;
        iVar3 = local_c + -1;
        if ((*local_6 == 0 && piVar2[1] == 0) ||
           ((piVar2[1] == DAT_5b41_0463 && (*local_6 == DAT_5b41_0461)))) break;
        local_6 = (int *)CONCAT22(uVar5,piVar2 + 4);
      }
    }
  }
  if ((piVar2[1] == DAT_5b41_0463) && (*local_6 == DAT_5b41_0461)) {
    *param_1 = iVar1;
    iVar1 = piVar2[2];
    param_1[2] = piVar2[3];
    param_1[1] = iVar1;
    param_1[6] = 0;
    param_1[5] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

