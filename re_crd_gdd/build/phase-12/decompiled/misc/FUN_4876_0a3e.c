// TIM2.EXE: FUN_4876_0a3e @ file 0x04E39E Ghidra 0x4919E
// Subsystem: misc | Size: 311 bytes


void __cdecl16far FUN_4876_0a3e(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  *(undefined2 *)((int)param_1 + 0x38) = *(undefined2 *)((int)param_1 + 0x14);
  *(undefined2 *)((int)param_1 + 0x3a) = *(undefined2 *)((int)param_1 + 0x16);
  *(undefined2 *)((int)param_1 + 0x3c) = *(undefined2 *)((int)param_1 + 0x18);
  *(undefined2 *)((int)param_1 + 0x3e) = *(undefined2 *)((int)param_1 + 0x1a);
  if (3 < *(uint *)((int)param_1 + 0x2c)) {
    *(undefined2 *)((int)param_1 + 0x2e) = 3;
  }
  if ((param_2 == 0) || (DAT_5b41_1d04 < 0x44d)) {
    *(undefined2 *)((int)param_1 + 0x42) = 0xf;
    *(undefined2 *)((int)param_1 + 0x46) = 0x554c;
    *(undefined2 *)((int)param_1 + 0x44) = 0x3fea;
    iVar1 = FUN_4340_0a09(*(undefined2 *)((int)param_1 + 0x44),*(undefined2 *)((int)param_1 + 0x46))
    ;
    *(int *)((int)param_1 + 0x48) = iVar1 + 1;
    *(uint *)((int)param_1 + 0x40) = *(uint *)((int)param_1 + 0x40) | 0x200;
  }
  else {
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x4c) = uVar2;
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x4e) = uVar2;
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x34) = uVar2;
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x38) = uVar2;
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x3a) = uVar2;
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x3c) = uVar2;
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x3e) = uVar2;
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x40) = uVar2;
    uVar2 = FUN_42da_04b8(param_2);
    *(undefined2 *)((int)param_1 + 0x42) = uVar2;
  }
  return;
}

