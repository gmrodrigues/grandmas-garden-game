// TIM2.EXE: FUN_460e_0006 @ file 0x04B2E6 Ghidra 0x460E6
// Subsystem: misc | Size: 282 bytes


undefined2 __cdecl16far FUN_460e_0006(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 local_6;
  
  if (DAT_5b41_1bff == (undefined2 *)0x0 && DAT_5b41_1c01 == 0) {
    if (param_1 == 0) {
      param_1 = 1;
    }
  }
  else {
    param_1 = 0;
  }
  iVar5 = param_3 * 0x1c;
  puVar3 = (undefined2 *)FUN_22de_01ec(param_1 * 8 + param_2 * 0x14 + iVar5,0,0xb,1);
  local_6 = (undefined2 *)CONCAT22(iVar5,puVar3);
  if (puVar3 == (undefined2 *)0x0 && iVar5 == 0) {
    uVar4 = 0;
  }
  else {
    *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 1;
    iVar2 = param_1;
    if (param_1 != 0) {
      while (DAT_5b41_1c0b = iVar2, DAT_5b41_1c01 = iVar5, DAT_5b41_1bff = puVar3, param_1 != 0) {
        uVar4 = (undefined2)((ulong)local_6 >> 0x10);
        pbVar1 = (byte *)((undefined2 *)local_6 + 3);
        *pbVar1 = *pbVar1 | 0x10;
        local_6 = (undefined2 *)CONCAT22(uVar4,(undefined2 *)local_6 + 4);
        param_1 = param_1 + -1;
        puVar3 = DAT_5b41_1bff;
        iVar5 = DAT_5b41_1c01;
        iVar2 = DAT_5b41_1c0b;
      }
    }
    DAT_5b41_1bfb = DAT_5b41_1bfb + param_2;
    while (param_2 != 0) {
      uVar4 = (undefined2)((ulong)local_6 >> 0x10);
      puVar3 = (undefined2 *)local_6;
      *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 2;
      puVar3[1] = DAT_5b41_1c05;
      *local_6 = DAT_5b41_1c03;
      local_6 = (undefined2 *)CONCAT22(uVar4,puVar3 + 10);
      param_2 = param_2 + -1;
      DAT_5b41_1c03 = puVar3;
      DAT_5b41_1c05 = uVar4;
    }
    DAT_5b41_1bfd = DAT_5b41_1bfd + param_3;
    while (param_3 != 0) {
      uVar4 = (undefined2)((ulong)local_6 >> 0x10);
      puVar3 = (undefined2 *)local_6;
      *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 4;
      puVar3[1] = DAT_5b41_1c09;
      *local_6 = DAT_5b41_1c07;
      local_6 = (undefined2 *)CONCAT22(uVar4,puVar3 + 0xe);
      DAT_5b41_1c07 = puVar3;
      DAT_5b41_1c09 = uVar4;
      param_3 = param_3 + -1;
    }
    uVar4 = 1;
  }
  return uVar4;
}

