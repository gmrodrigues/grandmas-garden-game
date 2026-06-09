// TIM2.EXE: FUN_460e_0120 @ file 0x04B400 Ghidra 0x46200
// Subsystem: misc | Size: 368 bytes


void __cdecl16far FUN_460e_0120(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  undefined2 *local_16;
  undefined4 local_12;
  undefined2 *local_e;
  int local_c;
  undefined4 local_6;
  
  uVar3 = DAT_5b41_1c01;
  local_6 = (undefined2 *)0x0;
  local_12 = (undefined2 *)0x0;
  local_c = 0;
  local_e = (undefined2 *)0x0;
  local_16 = DAT_5b41_1bff;
  do {
    puVar4 = local_6;
    puVar2 = (undefined2 *)local_6;
    iVar1 = local_6._2_2_;
    if (((undefined2 *)local_6 == (undefined2 *)0x0 && local_6._2_2_ == 0) ||
       ((*(byte *)((undefined2 *)local_6 + 3) & 1) == 0)) {
      if ((undefined2 *)local_6 != (undefined2 *)0x0 || local_6._2_2_ != 0) {
        local_6 = (undefined2 *)CONCAT22(((undefined2 *)local_6)[1],(undefined2 *)*local_6);
      }
    }
    else {
      if ((undefined2 *)local_12 == (undefined2 *)0x0 && local_12._2_2_ == 0) {
        local_c = local_6._2_2_;
        local_e = (undefined2 *)local_6;
      }
      else {
        ((undefined2 *)local_12)[1] = local_6._2_2_;
        *local_12 = (undefined2 *)local_6;
      }
      local_12 = local_6;
      local_6 = (undefined2 *)CONCAT22(((undefined2 *)local_6)[1],(undefined2 *)*local_6);
      puVar2[1] = 0;
      *puVar4 = 0;
    }
    if ((undefined2 *)local_6 == (undefined2 *)0x0 && local_6._2_2_ == 0) {
      local_6 = (undefined2 *)CONCAT22(DAT_5b41_1c05,DAT_5b41_1c03);
      if (DAT_5b41_1c03 == (undefined2 *)0x0 && DAT_5b41_1c05 == 0) {
        local_6 = (undefined2 *)CONCAT22(DAT_5b41_1c09,DAT_5b41_1c07);
        if (DAT_5b41_1c07 == (undefined2 *)0x0 && DAT_5b41_1c09 == 0) {
          if (DAT_5b41_1c0b == 0) {
            DAT_5b41_1c0b = 0;
          }
          else {
            local_6 = (undefined2 *)CONCAT22(uVar3,local_16);
            local_16 = local_16 + 4;
            DAT_5b41_1c0b = DAT_5b41_1c0b + -1;
          }
        }
        else {
          DAT_5b41_1c09 = 0;
          DAT_5b41_1c07 = (undefined2 *)0x0;
        }
      }
      else {
        DAT_5b41_1c05 = 0;
        DAT_5b41_1c03 = (undefined2 *)0x0;
      }
    }
  } while ((undefined2 *)local_6 != (undefined2 *)0x0 || local_6._2_2_ != 0);
  while (local_6 = (undefined2 *)CONCAT22(local_c,local_e),
        local_e != (undefined2 *)0x0 || local_c != 0) {
    iVar1 = local_e[1];
    puVar2 = (undefined2 *)*local_6;
    FUN_22de_0351(local_e,local_c);
    local_e = puVar2;
    local_c = iVar1;
  }
  DAT_5b41_1bfb = 0;
  DAT_5b41_1bfd = 0;
  DAT_5b41_1c01 = 0;
  DAT_5b41_1bff = (undefined2 *)0x0;
  return;
}

