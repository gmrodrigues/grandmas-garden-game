// TIM2.EXE: FUN_3e34_0bf4 @ file 0x044134 Ghidra 0x3EF34
// Subsystem: sound | Size: 322 bytes


undefined2 __cdecl16far FUN_3e34_0bf4(int *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int local_12;
  undefined1 local_a [2];
  int local_8;
  long local_6;
  
  if (param_1 != (int *)0x0) {
    if (*(int *)(*param_1 + 4) != -2) {
      return 2;
    }
    local_6 = (*DAT_554c_4daa)(0x3e34,param_1,local_a);
    iVar7 = (int)((ulong)local_6 >> 0x10);
    if (DAT_5b41_1aea == '\0') {
      pcVar8 = (char *)0x1a9e;
      local_12 = FUN_1a9e_539c(local_6,0,1);
    }
    else {
      if (0xffff < local_6) {
        return 0xffff;
      }
      pcVar8 = (char *)s_PROAUDIO_DRV_554c_3f20 + 0xb;
      local_12 = FUN_3f2b_0fa3(local_6,0,1);
    }
    if (local_12 != 0 || iVar7 != 0) {
      uVar1 = *(undefined2 *)*param_1;
      uVar2 = ((undefined2 *)*param_1)[1];
      while( true ) {
        piVar5 = (int *)*param_1;
        if (piVar5 == (int *)0x0) break;
        iVar6 = (piVar5[3] / 2) * piVar5[4];
        local_8 = iVar6 / 4 + iVar6;
        iVar3 = *piVar5;
        iVar4 = piVar5[1];
        *piVar5 = iVar7;
        piVar5[1] = local_12;
        piVar5[2] = piVar5[1] + iVar6;
        FUN_3e34_0d3e(local_12,iVar7,iVar4,iVar3,piVar5[3],piVar5[4]);
        if (DAT_5b41_1aea == '\0') {
          FUN_1000_1a00(local_8,pcVar8);
          pcVar8 = (char *)0x1000;
          param_1 = param_1 + 1;
        }
        else {
          local_12 = local_12 + local_8;
          param_1 = param_1 + 1;
        }
      }
      FUN_1a9e_5415(uVar2,uVar1);
      return 1;
    }
  }
  return 0;
}

