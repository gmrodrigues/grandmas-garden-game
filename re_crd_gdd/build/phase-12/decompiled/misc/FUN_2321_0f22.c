// TIM2.EXE: FUN_2321_0f22 @ file 0x029332 Ghidra 0x24132
// Subsystem: misc | Size: 212 bytes


undefined2 * __cdecl16far FUN_2321_0f22(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 *local_a;
  undefined4 local_6;
  
  puVar1 = DAT_5b41_0557;
  iVar2 = DAT_5b41_0559;
  while( true ) {
    local_6 = (undefined2 *)CONCAT22(iVar2,puVar1);
    if (puVar1 == (undefined2 *)0x0 && iVar2 == 0) break;
    if ((((*(byte *)((int)puVar1 + 0xd) & 0x20) != 0) && ((*(byte *)(puVar1 + 5) & 0x10) != 0)) &&
       (puVar1[4] == param_1)) break;
    iVar2 = puVar1[1];
    puVar1 = (undefined2 *)*local_6;
  }
  iVar3 = iVar2;
  if (puVar1 != (undefined2 *)0x0 || iVar2 != 0) {
    FUN_28eb_2a23(puVar1,iVar2);
    local_a = (undefined2 *)CONCAT22(iVar2,puVar1);
    for (iVar4 = 0xba; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)local_a = 0;
      local_a = (undefined2 *)CONCAT22(local_a._2_2_,(undefined2 *)((int)(undefined2 *)local_a + 1))
      ;
    }
    iVar4 = FUN_2321_0deb(puVar1,iVar2,param_1);
    if (iVar4 == 0) {
      puVar1[6] = puVar1[6] | 0x2000;
      puVar1[5] = puVar1[5] | 0x10;
      local_6 = (undefined2 *)0x0;
    }
  }
  if ((undefined2 *)local_6 == (undefined2 *)0x0 && local_6._2_2_ == 0) {
    puVar1 = (undefined2 *)FUN_2321_0ff6(param_1);
    local_6 = (undefined2 *)CONCAT22(iVar3,puVar1);
  }
  if ((undefined2 *)local_6 != (undefined2 *)0x0 || local_6._2_2_ != 0) {
    ((undefined2 *)local_6)[5] = ((undefined2 *)local_6)[5] | 0x10;
  }
  return (undefined2 *)local_6;
}

