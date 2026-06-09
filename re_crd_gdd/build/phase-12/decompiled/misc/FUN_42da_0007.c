// TIM2.EXE: FUN_42da_0007 @ file 0x047FA7 Ghidra 0x42DA7
// Subsystem: misc | Size: 257 bytes


undefined2 __cdecl16far FUN_42da_0007(int param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int in_DX;
  int iVar5;
  
  if ((((param_1 != 0) && (param_2 != 0)) && (iVar4 = FUN_4340_0a09(param_2,0x554c), iVar4 == 4)) &&
     (DAT_53c5_0000 < 2)) {
    iVar4 = FUN_1000_0f2a(param_1);
    iVar5 = DAT_53c5_0000 * 4;
    *(int *)(iVar5 + 8) = in_DX;
    *(int *)(iVar5 + 6) = iVar4;
    if (((in_DX != -1) || (iVar4 != -1)) &&
       ((iVar4 = FUN_42da_0610(param_1,param_2,0x554c,4), iVar4 == 4 &&
        (iVar4 = FUN_42da_0610(param_1,0x3e5a,0x554c,4), iVar4 == 4)))) {
      if (DAT_53c5_0000 != 0) {
        *(undefined2 *)((DAT_53c5_0000 - 1) * 2 + 2) = 1;
      }
      *(undefined2 *)(DAT_53c5_0000 * 2 + 2) = 0;
      iVar4 = DAT_53c5_0000 * 4;
      puVar1 = (uint *)(iVar4 + 6);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + 8;
      piVar2 = (int *)(iVar4 + 8);
      *piVar2 = *piVar2 + (uint)(0xfff7 < uVar3);
      DAT_53c5_0000 = DAT_53c5_0000 + 1;
      return 1;
    }
  }
  return 0;
}

