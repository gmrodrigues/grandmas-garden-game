// TIM2.EXE: FUN_2424_49f1 @ file 0x02DE31 Ghidra 0x28C31
// Subsystem: misc | Size: 241 bytes


void __cdecl16far
FUN_2424_49f1(undefined2 param_1,undefined2 param_2,int param_3,int param_4,undefined2 param_5)

{
  int iVar1;
  undefined2 *puVar2;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  FUN_4551_03eb(param_1,param_2,&local_10);
  local_10 = local_10 + param_3;
  local_e = local_e + param_4;
  puVar2 = DAT_5b41_04b0;
  while( true ) {
    if (puVar2 == (undefined2 *)0x0) {
      FUN_2424_02ca();
      return;
    }
    iVar1 = puVar2[1];
    local_4 = puVar2[2];
    local_6 = puVar2[3];
    local_8 = puVar2[4];
    if ((((iVar1 <= local_10) && (local_10 + local_c <= local_6)) && (local_4 <= local_e)) &&
       (local_e + local_a <= local_8)) break;
    if ((((local_10 <= local_6) && (iVar1 <= local_10 + local_c)) &&
        ((local_e <= local_8 && ((local_4 <= local_e + local_a && (iVar1 < local_6)))))) &&
       (local_4 <= local_8)) {
      DAT_554c_42c3 = 1;
      DAT_554c_42c4 = iVar1;
      DAT_554c_42c6 = local_6;
      DAT_554c_42c8 = local_4;
      DAT_554c_42ca = local_8;
      FUN_4551_01dc(param_1,param_2,param_3,param_4,param_5);
    }
    puVar2 = (undefined2 *)*puVar2;
  }
  FUN_2424_02ca();
  FUN_4551_01dc(param_1,param_2,param_3,param_4,param_5);
  return;
}

