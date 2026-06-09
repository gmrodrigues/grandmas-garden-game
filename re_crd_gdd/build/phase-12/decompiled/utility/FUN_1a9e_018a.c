// TIM2.EXE: FUN_1a9e_018a @ file 0x01FD6A Ghidra 0x1AB6A
// Subsystem: utility | Size: 155 bytes


uint __cdecl16near FUN_1a9e_018a(undefined2 param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = DAT_5b41_0042;
  uVar4 = *(uint *)(DAT_5b41_0042 + 0xe) - *(uint *)(DAT_5b41_0042 + 10);
  uVar5 = (*(int *)(DAT_5b41_0042 + 0x10) - *(int *)(DAT_5b41_0042 + 0xc)) -
          (uint)(*(uint *)(DAT_5b41_0042 + 0xe) < *(uint *)(DAT_5b41_0042 + 10));
  if (uVar4 == 0 && uVar5 == 0) {
    uVar4 = 0;
  }
  else {
    if ((0 < (int)uVar5) || ((uVar5 < 0x8000 && (param_2 <= uVar4)))) {
      uVar5 = 0;
      uVar4 = param_2;
    }
    puVar1 = (uint *)(DAT_5b41_0042 + 10);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar4;
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + uVar5 + (uint)CARRY2(uVar2,uVar4);
    if ((DAT_5b41_02ea & 0x20) == 0) {
      FUN_1000_05ea(param_1,0x554c,(undefined2)DAT_5b41_02eb,DAT_5b41_02eb._2_2_,uVar4);
      FUN_1000_1a00(0x1a9e);
    }
    else {
      uVar4 = FUN_1000_0d10(param_1,1,uVar4,DAT_5b41_0047);
    }
  }
  return uVar4;
}

