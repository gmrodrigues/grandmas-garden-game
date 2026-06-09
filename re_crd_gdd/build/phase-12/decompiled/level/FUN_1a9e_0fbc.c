// TIM2.EXE: FUN_1a9e_0fbc @ file 0x020B9C Ghidra 0x1B99C
// Subsystem: level | Size: 189 bytes


undefined2 __cdecl16far
FUN_1a9e_0fbc(undefined2 param_1,undefined1 *param_2,undefined2 param_3,uint param_4)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  undefined2 uVar7;
  uint local_8;
  undefined4 local_6;
  
  uVar7 = 0x1a9e;
  iVar6 = FUN_1a9e_03bd(param_1);
  piVar5 = DAT_5b41_0042;
  if (iVar6 == 0) {
    return 0xffff;
  }
  DAT_5b41_02e5 = 0;
  puVar1 = (uint *)(DAT_5b41_0042 + 9);
  uVar3 = *puVar1;
  *puVar1 = *puVar1 + param_4;
  piVar2 = piVar5 + 10;
  *piVar2 = *piVar2 + (uint)CARRY2(uVar3,param_4);
  iVar6 = *piVar5;
  local_6 = (undefined1 *)CONCAT22(param_3,param_2);
  do {
    if (param_4 == 0) {
      return DAT_5b41_02e5;
    }
    local_8 = (uint)*(byte *)(DAT_5b41_0042 + 0xd);
    bVar4 = *(byte *)((int)DAT_5b41_0042 + 0x1b);
    do {
      *(undefined1 *)(local_8 + iVar6) = *local_6;
      FUN_1000_1a00(param_1,uVar7);
      param_4 = param_4 - 1;
      local_8 = local_8 + 1 & 0x7f;
      if (local_8 == (bVar4 - 1 & 0x7f)) break;
      uVar7 = 0x1000;
    } while (param_4 != 0);
    *(undefined1 *)(DAT_5b41_0042 + 0xd) = (undefined1)local_8;
    uVar7 = 0x1000;
    (*(code *)*(undefined2 *)((uint)DAT_5b41_0046 * 0xe + 0x16e))(0);
  } while( true );
}

