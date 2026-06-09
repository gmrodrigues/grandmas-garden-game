// TIM2.EXE: FUN_31f7_7e92 @ file 0x03F002 Ghidra 0x39E02
// Subsystem: misc | Size: 241 bytes


void __cdecl16far FUN_31f7_7e92(undefined4 param_1)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 local_6;
  undefined2 uStack_4;
  
  FUN_28eb_51b3((int)param_1,param_1._2_2_,0x1000,0,0x1f,0xfe70,1);
  bVar2 = false;
  local_6 = *(int *)((int)param_1 + 0x8c);
  uStack_4 = *(int *)((int)param_1 + 0x8e);
  while (local_6 != 0 || uStack_4 != 0) {
    uVar3 = (*(int *)((int)param_1 + 0x22) + (*(int *)((int)param_1 + 0x54) >> 1)) -
            (*(int *)(local_6 + 0x22) + (*(int *)(local_6 + 0x54) >> 1));
    uVar5 = (int)uVar3 >> 0xf;
    if (((int)((uVar3 ^ uVar5) - uVar5) <= *(int *)((int)param_1 + 0x54) >> 1) ||
       ((int)((uVar3 ^ uVar5) - uVar5) <= *(int *)(local_6 + 0x54) >> 1)) {
      *(uint *)(local_6 + 0xe) = *(uint *)(local_6 + 0xe) | 0x800;
      bVar2 = true;
    }
    piVar1 = (int *)(local_6 + 0x8e);
    local_6 = *(int *)(local_6 + 0x8c);
    uStack_4 = *piVar1;
  }
  if (bVar2) {
    *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + 1;
    iVar4 = FUN_4551_0308(DAT_5b41_0a38,*(undefined2 *)((int)param_1 + 0x10));
    if (iVar4 == -1) {
      if ((DAT_5b41_051f & 1) == 0) {
        *(int *)((int)param_1 + 0x10) = *(int *)((int)param_1 + 0x10) + -2;
      }
      else {
        *(undefined2 *)((int)param_1 + 0x10) = 1;
      }
    }
  }
  else {
    *(undefined2 *)((int)param_1 + 0x10) = 0;
  }
  return;
}

