// TIM2.EXE: FUN_460e_0d51 @ file 0x04C031 Ghidra 0x46E31
// Subsystem: misc | Size: 497 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __cdecl16far FUN_460e_0d51(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined2 uVar8;
  int local_16 [2];
  int *local_12;
  int local_10;
  int *local_e;
  int local_c;
  undefined4 local_a;
  undefined4 local_6;
  
  local_10 = 0;
  local_12 = (int *)0x0;
  local_c = DAT_5b41_1c10;
  local_e = DAT_5b41_1c0e;
  local_a = (int *)0x0;
  piVar2 = local_e;
  iVar1 = local_c;
  while( true ) {
    local_c = iVar1;
    local_e = piVar2;
    local_6 = (int *)CONCAT22(local_c,local_e);
    if (local_e == (int *)0x0 && local_c == 0) break;
    iVar1 = local_e[1];
    piVar2 = (int *)*local_6;
    if ((local_e[6] == param_1) || (((param_1 == 0 && (param_2 != 0)) && (local_e[8] == param_2))))
    {
      if ((local_c == DAT_5b41_1c18) && (local_e == DAT_5b41_1c16)) {
        DAT_5b41_1c18 = local_e[3];
        DAT_5b41_1c16 = (int *)local_e[2];
        DAT_5b41_1c1a = 1;
      }
      if (local_e[2] == 0 && local_e[3] == 0) {
        iVar3 = local_e[1];
        piVar4 = (int *)*local_6;
        _DAT_5b41_1c0e = (int *)CONCAT22(iVar3,piVar4);
        if (piVar4 == (int *)0x0 && iVar3 == 0) {
          _DAT_5b41_1c12 = (undefined2 *)0x0;
        }
        else {
          piVar4[3] = 0;
          piVar4[2] = 0;
        }
      }
      else if (*local_6 == 0 && local_e[1] == 0) {
        _DAT_5b41_1c12 = (undefined2 *)CONCAT22(local_e[3],(undefined2 *)local_e[2]);
        puVar6 = _DAT_5b41_1c12;
        ((undefined2 *)local_e[2])[1] = 0;
        *puVar6 = 0;
      }
      else {
        iVar3 = *local_6;
        piVar5 = *(int **)(local_e + 2);
        ((int *)piVar5)[1] = local_e[1];
        *piVar5 = iVar3;
        iVar3 = local_e[2];
        uVar8 = (undefined2)((ulong)*(undefined4 *)local_6 >> 0x10);
        iVar7 = (int)*(undefined4 *)local_6;
        *(int *)(iVar7 + 6) = local_e[3];
        *(int *)(iVar7 + 4) = iVar3;
      }
      if ((int *)local_a == (int *)0x0 && local_a._2_2_ == 0) {
        local_10 = local_c;
        local_e[3] = 0;
        local_e[2] = 0;
        local_e[1] = 0;
        *(int *)CONCAT22(local_c,local_e) = 0;
        local_12 = local_e;
      }
      else {
        ((int *)local_a)[1] = local_c;
        *local_a = (int)local_e;
        local_e[3] = local_a._2_2_;
        local_e[2] = (int)(int *)local_a;
        local_e[1] = 0;
        *local_6 = 0;
      }
      local_a = (int *)CONCAT22(local_c,local_e);
      if ((DAT_5b41_1ae4 == local_c) && (DAT_5b41_1ae2 == local_e)) {
        DAT_5b41_1ae4 = 0;
        DAT_5b41_1ae2 = (int *)0x0;
      }
      local_16[0] = local_e[6];
      local_16[1] = 0;
      local_e = piVar2;
      local_c = iVar1;
      FUN_460e_1692(local_16);
      piVar2 = local_e;
      iVar1 = local_c;
      if (param_1 != 0) {
        local_c = 0;
        local_e = (int *)0x0;
        piVar2 = local_e;
        iVar1 = local_c;
      }
    }
  }
  return local_12;
}

