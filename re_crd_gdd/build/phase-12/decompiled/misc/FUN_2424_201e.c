// TIM2.EXE: FUN_2424_201e @ file 0x02B45E Ghidra 0x2625E
// Subsystem: misc | Size: 141 bytes


void __cdecl16far FUN_2424_201e(void)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 local_c;
  int local_a;
  int local_8;
  int local_6;
  undefined2 local_4;
  
  FUN_2424_02e7();
  local_4 = *(undefined2 *)((int)DAT_5b41_0567 + 8);
  uVar5 = FUN_54b4_002f(0x2424,local_4);
  uVar2 = (undefined2)((ulong)uVar5 >> 0x10);
  iVar1 = (int)uVar5;
  DAT_554c_42d8 = DAT_554c_42d2;
  iVar3 = DAT_5b41_1b84 - *(int *)(iVar1 + 6) / 2;
  iVar4 = DAT_5b41_1b86 - *(int *)(iVar1 + 8) / 2;
  FUN_3e34_0160(uVar5,iVar3,iVar4,0);
  local_c = *(undefined2 *)(iVar1 + 6);
  local_a = *(int *)(iVar1 + 8) + 1;
  local_8 = iVar3;
  local_6 = iVar4;
  FUN_2424_1da0(&local_8,&local_c,2);
  return;
}

