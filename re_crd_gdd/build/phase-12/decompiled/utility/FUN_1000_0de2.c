// TIM2.EXE: FUN_1000_0de2 @ file 0x015FE2 Ghidra 0x10DE2
// Subsystem: utility | Size: 139 bytes


void __cdecl16far
FUN_1000_0de2(undefined1 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6,undefined2 param_7)

{
  int iVar1;
  bool bVar2;
  long lVar3;
  undefined1 local_10;
  undefined4 local_e;
  uint local_a;
  int local_8;
  int local_6;
  int local_4;
  
  lVar3 = FUN_1000_1fce();
  local_8 = 0;
  local_a = 0;
  local_e = (undefined1 *)CONCAT22(param_2,param_1);
  while( true ) {
    local_4 = (int)((ulong)lVar3 >> 0x10);
    local_6 = (int)lVar3;
    if (lVar3 == 0) break;
    iVar1 = FUN_1000_0fdc(param_7);
    if (iVar1 == -1) break;
    local_10 = (undefined1)iVar1;
    *local_e = local_10;
    FUN_1000_19fd();
    bVar2 = 0xfffe < local_a;
    local_a = local_a + 1;
    local_8 = local_8 + (uint)bVar2;
    lVar3 = CONCAT22(local_4 - (uint)(local_6 == 0),local_6 + -1);
  }
  FUN_1000_18f4(local_a,local_8,param_3,param_4);
  return;
}

