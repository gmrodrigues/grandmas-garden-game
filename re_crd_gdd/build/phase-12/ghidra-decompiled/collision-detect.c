// TIM2.EXE decompiled function: FUN_4bdc_3427
// Source: file offset 0x054459 → Ghidra 0x4F259
// Body: 0x4F1E7 - 0x4F388
// Size: 416 bytes


undefined2 __cdecl16far FUN_4bdc_3427(int param_1)

{
  int iVar1;
  int in_DX;
  int local_6;
  int iStack_4;
  
  if (param_1 != -2) {
    if ((param_1 != -1) && (param_1 != 0)) {
      iVar1 = FUN_4bdc_3951(param_1);
      if (iVar1 != 0 || in_DX != 0) {
        *(uint *)(iVar1 + 0x12) = *(uint *)(iVar1 + 0x12) & 0xffef;
        if ((*(uint *)(iVar1 + 0x12) & 1) == 0) {
          FUN_4bdc_2fd3(*(undefined2 *)(iVar1 + 4),*(undefined2 *)(iVar1 + 6));
        }
        else if (*(int *)(iVar1 + 0xe) != 0 || *(int *)(iVar1 + 0x10) != 0) {
          FUN_4bdc_28e6(*(undefined2 *)(iVar1 + 0xe),*(undefined2 *)(iVar1 + 0x10),0);
          do {
          } while (*(char *)((int)*(undefined4 *)(iVar1 + 0xe) + 0x158) != -1);
          FUN_2e67_10e9(*(undefined2 *)(iVar1 + 0xe),*(undefined2 *)(iVar1 + 0x10),2);
          *(undefined2 *)(iVar1 + 0x10) = 0;
          *(undefined2 *)(iVar1 + 0xe) = 0;
        }
        return 1;
      }
      return 0;
    }
    local_6 = FUN_4bdc_3951(0xffff);
    iStack_4 = in_DX;
    while (local_6 != 0 || iStack_4 != 0) {
      *(uint *)(local_6 + 0x12) = *(uint *)(local_6 + 0x12) & 0xffef;
      if (*(int *)(local_6 + 0xe) == 0 && *(int *)(local_6 + 0x10) == 0) {
        local_6 = FUN_4bdc_3951(0xfffd);
        iStack_4 = in_DX;
      }
      else {
        FUN_4bdc_28e6(*(undefined2 *)(local_6 + 0xe),*(undefined2 *)(local_6 + 0x10),0);
        do {
        } while (*(char *)((int)*(undefined4 *)(local_6 + 0xe) + 0x158) != -1);
        FUN_2e67_10e9(*(undefined2 *)(local_6 + 0xe),*(undefined2 *)(local_6 + 0x10),2);
        *(undefined2 *)(local_6 + 0x10) = 0;
        *(undefined2 *)(local_6 + 0xe) = 0;
        local_6 = 0;
        iStack_4 = 0;
      }
    }
    if (param_1 == -1) {
      return 1;
    }
  }
  local_6 = FUN_4bdc_3951(0xfffe);
  while (local_6 != 0 || in_DX != 0) {
    *(uint *)(local_6 + 0x12) = *(uint *)(local_6 + 0x12) & 0xffef;
    local_6 = FUN_4bdc_3951(0xfffd);
  }
  FUN_4bdc_3165();
  return 1;
}


