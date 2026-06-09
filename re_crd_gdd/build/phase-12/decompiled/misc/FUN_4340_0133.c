// TIM2.EXE: FUN_4340_0133 @ file 0x048733 Ghidra 0x43533
// Subsystem: misc | Size: 232 bytes


undefined2 __cdecl16far FUN_4340_0133(uint param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  int in_DX;
  int local_6;
  
  iVar1 = FUN_4340_07f3(param_1);
  if (iVar1 != 0 || in_DX != 0) {
    uVar2 = FUN_3f2b_0718(*(undefined2 *)(iVar1 + 10),0x554c);
    iVar3 = FUN_4340_0b8a(param_2,0x554c,uVar2);
    if (iVar3 == 0) {
      return 1;
    }
    FUN_4340_04aa(param_1);
    FUN_3f2b_042f(*(undefined2 *)(iVar1 + 10),0);
    *(undefined2 *)(iVar1 + 10) = 0;
  }
  uVar2 = DAT_53c6_0004;
  if (param_2 != 0) {
    iVar1 = DAT_53c6_0000;
    for (local_6 = DAT_53c6_0002; (iVar1 != 0 && (*(int *)(local_6 + 10) != 0));
        local_6 = local_6 + 0xe) {
      iVar1 = iVar1 + -1;
    }
    if (iVar1 != 0) {
      *(uint *)(local_6 + 8) = param_1 / 1000;
      uVar4 = FUN_3f2b_0220(param_2,0x554c,local_6,uVar2,0,0x520,0x4340);
      *(undefined2 *)(local_6 + 10) = uVar4;
      if (*(int *)(local_6 + 10) != 0) {
        return 1;
      }
      return 0;
    }
  }
  return 0;
}

