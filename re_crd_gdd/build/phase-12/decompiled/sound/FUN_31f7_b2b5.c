// TIM2.EXE: FUN_31f7_b2b5 @ file 0x042425 Ghidra 0x3D225
// Subsystem: sound | Size: 159 bytes


void __cdecl16far FUN_31f7_b2b5(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_4;
  undefined1 local_3;
  
  FUN_2424_2e7d((int)param_1,param_1._2_2_,param_2);
  if (*(int *)((int)param_1 + 0x16) != 0) {
    local_4 = *(undefined1 *)((int)param_1 + 0xae);
    local_3 = 0;
    DAT_554c_42c2 = 1;
    DAT_554c_42c0 = 0xf;
    FUN_4340_08dd(DAT_5b41_1ab8);
    iVar1 = FUN_1a9e_4e39(0);
    iVar2 = FUN_1a9e_4e93(&local_4,iVar1);
    FUN_1a9e_519c(&local_4,(*(int *)((int)param_1 + 0x22) + 0x19) - iVar2 / 2,
                  (*(int *)((int)param_1 + 0x24) + 0xd) - iVar1 / 2);
    FUN_4340_08dd(0xffff);
  }
  return;
}

