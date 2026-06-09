// TIM2.EXE: FUN_406b_2111 @ file 0x0479C1 Ghidra 0x427C1
// Subsystem: misc | Size: 613 bytes


void __cdecl16far FUN_406b_2111(void)

{
  char *pcVar1;
  bool bVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  int in_DX;
  int unaff_SS;
  char *pcStack0004;
  char local_5a [80];
  undefined4 local_a;
  undefined4 local_6;
  
  FUN_4340_0a29(local_5a);
  puVar3 = (undefined1 *)FUN_4340_0d3f(local_5a);
  local_6 = (undefined1 *)CONCAT22(in_DX,puVar3);
  if (puVar3 != (undefined1 *)0x0 || in_DX != 0) {
    puVar3 = (undefined1 *)FUN_4340_0d3f(local_5a);
    if (puVar3 < (char *)local_6) {
      *local_6 = 0;
    }
  }
  pcStack0004 = (char *)FUN_4340_0d3f(local_5a);
  if (pcStack0004 == (char *)0x0 && in_DX == 0) {
    pcStack0004 = (char *)FUN_4340_0d3f(local_5a);
  }
  bVar2 = pcStack0004 == (char *)0x0;
  pcStack0004 = (char *)((int)pcStack0004 + 1);
  if (bVar2 && in_DX == 0) {
    pcStack0004 = local_5a;
    in_DX = unaff_SS;
  }
  iVar4 = FUN_4340_0a09(pcStack0004,in_DX);
  local_6._0_2_ = pcStack0004 + iVar4;
  if ((-1 < (int)-(uint)((char *)local_6 < pcStack0004)) &&
     ((-(uint)((char *)local_6 < pcStack0004) != 0 ||
      (7 < (uint)((int)(char *)local_6 - (int)pcStack0004))))) {
    local_6._0_2_ = pcStack0004 + 7;
  }
  local_6._2_2_ = in_DX;
  for (iVar4 = 0; iVar4 < 10000; iVar4 = iVar4 + 1) {
    if (iVar4 == 10) {
      if ((-1 < (int)-(uint)((char *)local_6 < pcStack0004)) &&
         ((-(uint)((char *)local_6 < pcStack0004) != 0 ||
          (6 < (uint)((int)(char *)local_6 - (int)pcStack0004))))) {
        local_6._0_2_ = (char *)local_6 + -1;
      }
    }
    if (iVar4 == 100) {
      if ((-1 < (int)-(uint)((char *)local_6 < pcStack0004)) &&
         ((-(uint)((char *)local_6 < pcStack0004) != 0 ||
          (5 < (uint)((int)(char *)local_6 - (int)pcStack0004))))) {
        local_6._0_2_ = (char *)local_6 + -1;
      }
    }
    if (iVar4 == 1000) {
      if ((-1 < (int)-(uint)((char *)local_6 < pcStack0004)) &&
         (((char *)local_6 < pcStack0004 != 0 ||
          (4 < (uint)((int)(char *)local_6 - (int)pcStack0004))))) {
        local_6._0_2_ = (char *)local_6 + -1;
      }
    }
    local_a = (char *)CONCAT22(local_6._2_2_,(char *)local_6);
    if (1000 < iVar4) {
      *local_a = (char)(iVar4 / 1000) + '0';
      local_a = (char *)CONCAT22(local_6._2_2_,(char *)local_6 + 1);
    }
    if (100 < iVar4) {
      *local_a = (char)((iVar4 % 1000) / 100) + '0';
      local_a = (char *)CONCAT22(local_a._2_2_,(char *)local_a + 1);
    }
    if (10 < iVar4) {
      *local_a = (char)((iVar4 % 100) / 10) + '0';
      local_a = (char *)CONCAT22(local_a._2_2_,(char *)local_a + 1);
    }
    *local_a = (char)(iVar4 % 10) + '0';
    pcVar1 = (char *)local_a + 1;
    local_a = (char *)CONCAT22(local_a._2_2_,pcVar1);
    FUN_4340_0a29(pcVar1,local_a._2_2_,0x3e52,0x554c);
    uVar5 = FUN_1000_418e(local_5a,0x3e57);
    iVar6 = FUN_1000_3d77(uVar5);
    if (iVar6 != 0) break;
  }
  if (iVar4 < 10000) {
    if (DAT_554c_42d6 == DAT_554c_42d4) {
      FUN_406b_053a();
    }
    iVar4 = DAT_554c_3e4a;
    if (((DAT_554c_3e4a != 0) && (DAT_5b41_1ae0 != 0)) && (DAT_554c_3e4a = 0, DAT_5b41_1b98 != 0)) {
      FUN_406b_0c62(DAT_554c_49aa / 2,DAT_554c_49ac / 2);
    }
    FUN_406b_19d7(local_5a);
    DAT_554c_3e4a = iVar4;
    if (DAT_554c_42d6 == DAT_554c_42d4) {
      FUN_406b_04d8(0);
    }
  }
  return;
}

