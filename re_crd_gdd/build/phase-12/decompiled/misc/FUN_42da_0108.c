// TIM2.EXE: FUN_42da_0108 @ file 0x0480A8 Ghidra 0x42EA8
// Subsystem: misc | Size: 254 bytes


/* WARNING: Removing unreachable block (ram,0x00042f18) */

undefined2 __cdecl16far FUN_42da_0108(undefined2 param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int in_DX;
  int iVar5;
  uint local_8;
  
  if ((DAT_53c5_0000 != 0) && ((uVar4 = FUN_1000_0f2a(param_1), in_DX != -1 || (uVar4 != 0xffff))))
  {
    iVar5 = (DAT_53c5_0000 + -1) * 4;
    puVar1 = (uint *)(iVar5 + 6);
    uVar2 = *puVar1;
    local_8 = (in_DX - *(int *)(iVar5 + 8)) - (uint)(uVar4 < *puVar1);
    if ((-1 < (int)local_8) &&
       (iVar5 = (DAT_53c5_0000 + -1) * 4, uVar3 = *(uint *)(iVar5 + 6),
       iVar5 = FUN_1000_0e6d(param_1,uVar3 - 4,*(int *)(iVar5 + 8) - (uint)(uVar3 < 4),0),
       iVar5 == 0)) {
      if (*(int *)((DAT_53c5_0000 + -1) * 2 + 2) != 0) {
        local_8 = local_8 | 0x8000;
      }
      iVar5 = FUN_42da_05f8(param_1,uVar4 - uVar2,local_8);
      if (iVar5 != 0) {
        FUN_1000_0e6d(param_1,uVar4,in_DX,0);
        DAT_53c5_0000 = DAT_53c5_0000 + -1;
        return 1;
      }
    }
  }
  return 0;
}

