// TIM2.EXE: FUN_460e_2581 @ file 0x04D861 Ghidra 0x48661
// Subsystem: misc | Size: 264 bytes


uint __cdecl16far FUN_460e_2581(char param_1,byte param_2)

{
  undefined1 *puVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  char *local_a;
  undefined4 local_6;
  
  pcVar4 = (char *)((uint)DAT_5b41_1cf4 | DAT_5b41_1cf6);
  if ((pcVar4 != (char *)0x0) && (param_1 != '\0')) {
    if (7 < DAT_5b41_1d02) {
      DAT_5b41_1d02 = 0;
    }
    if (((param_2 & 8) != 0) && (DAT_5b41_1d02 == 0)) {
      DAT_5b41_1cf8 = 4;
      DAT_5b41_1d02 = 1;
    }
    ((undefined1 *)&DAT_5b41_1cf8)[DAT_5b41_1d02] = param_1;
    puVar1 = (undefined1 *)&DAT_5b41_1cf9 + DAT_5b41_1d02;
    DAT_5b41_1d02 = DAT_5b41_1d02 + 1;
    *puVar1 = 0;
    iVar7 = 0;
    local_6 = (char *)CONCAT22(DAT_5b41_1cf6,DAT_5b41_1cf4);
    pcVar4 = DAT_5b41_1cf4;
    while (*local_6 != '\0') {
      local_a = &DAT_5b41_1cf8;
      for (iVar6 = 0; pcVar3 = local_6, pcVar2 = local_a, iVar6 < DAT_5b41_1d02; iVar6 = iVar6 + 1)
      {
        local_a = (char *)CONCAT22(local_a._2_2_,(char *)local_a + 1);
        pcVar4 = (char *)CONCAT11((char)((uint)pcVar4 >> 8),*pcVar2);
        local_6 = (char *)CONCAT22(local_6._2_2_,(char *)local_6 + 1);
        if ((*pcVar2 != *pcVar3) && (*pcVar3 != '\x01')) break;
      }
      if (iVar6 == DAT_5b41_1d02) {
        if ((*local_6 == '\0') || (((char *)local_6)[1] == '\0')) {
          iVar7 = 0;
          bVar5 = (byte)((uint)pcVar4 >> 8);
          if (*local_6 == '\x02') {
            pcVar4 = (char *)((uint)bVar5 << 8);
          }
          else {
            pcVar4 = (char *)CONCAT11(bVar5,*local_6);
          }
          param_1 = (char)pcVar4;
          break;
        }
      }
      if (iVar7 < iVar6) {
        iVar7 = iVar6;
      }
      do {
        pcVar2 = local_6;
        local_6 = (char *)CONCAT22(local_6._2_2_,(char *)local_6 + 1);
      } while (*pcVar2 != '\0');
    }
    if (iVar7 != 0) {
      if (iVar7 < DAT_5b41_1d02) {
        DAT_5b41_1d02 = 0;
      }
      return (uint)pcVar4 & 0xff00;
    }
    DAT_5b41_1d02 = 0;
  }
  return CONCAT11((char)((uint)pcVar4 >> 8),param_1);
}

