// TIM2.EXE: FUN_4551_0002 @ file 0x04A712 Ghidra 0x45512
// Subsystem: misc | Size: 251 bytes


int __cdecl16far FUN_4551_0002(undefined2 param_1)

{
  int iVar1;
  int in_DX;
  int *piVar2;
  int iVar3;
  undefined1 local_16 [14];
  int local_8;
  int iStack_6;
  int local_4;
  
  iVar1 = FUN_3f2b_0577(param_1,0x554c);
  if (iVar1 == 0) {
    local_4 = FUN_1a9e_69e9(param_1);
    if (local_4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_3f2b_0220(param_1,0x554c,0,0,0,0xfd,0x4551);
      FUN_460e_074f(0x5fc1);
      FUN_460e_07ca(0x5fc1,local_4,0x3fb6);
      FUN_1a9e_6e73(local_4);
      local_8 = FUN_460e_097a(0x5fc1);
      if (local_8 != 0 || in_DX != 0) {
        iVar3 = 0;
        iStack_6 = in_DX;
        while ((iVar3 < 0x40 &&
               (piVar2 = (int *)(local_8 + iVar3 * 4), *piVar2 != 0 || piVar2[1] != 0))) {
          FUN_4340_0a6e(local_16);
          FUN_3e34_0836(local_16,DAT_554c_3d4e);
          iVar3 = iVar3 + 1;
        }
        FUN_22de_0351(local_8,iStack_6);
      }
      FUN_460e_074f(0x5fc1);
    }
  }
  else {
    FUN_3f2b_09ca(iVar1,1);
  }
  return iVar1;
}

