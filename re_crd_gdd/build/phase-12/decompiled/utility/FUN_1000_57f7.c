// TIM2.EXE: FUN_1000_57f7 @ file 0x01A9F7 Ghidra 0x157F7
// Subsystem: utility | Size: 301 bytes


int __cdecl16far FUN_1000_57f7(uint param_1,char *param_2,int param_3)

{
  uint *puVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char local_8c [130];
  char *local_a;
  char local_7;
  int local_6;
  int local_4;
  
  if (param_1 < DAT_554c_5914) {
    if (param_3 + 1U < 2) {
      local_4 = 0;
    }
    else {
      if ((*(byte *)(param_1 * 2 + 0x5917) & 8) != 0) {
        FUN_1000_1c50(param_1,0,0,2);
      }
      if ((*(byte *)(param_1 * 2 + 0x5917) & 0x40) == 0) {
        local_4 = FUN_1000_5924(param_1,param_2,param_3);
      }
      else {
        puVar1 = (uint *)(param_1 * 2 + 0x5916);
        *puVar1 = *puVar1 & 0xfdff;
        local_a = param_2;
        local_6 = param_3;
        do {
          pcVar4 = local_8c;
          do {
            if (local_6 == 0) {
              local_4 = (int)pcVar4 - (int)local_8c;
              if (local_4 == 0) {
                return param_3;
              }
              iVar3 = FUN_1000_5924(param_1,local_8c,local_4);
              if (iVar3 == local_4) {
                return param_3;
              }
              if (iVar3 == -1) {
                return -1;
              }
              goto LAB_1000_5914;
            }
            local_6 = local_6 + -1;
            pcVar2 = local_a + 1;
            local_7 = *local_a;
            local_a = pcVar2;
            if (local_7 == '\n') {
              *pcVar4 = '\r';
              pcVar4 = pcVar4 + 1;
            }
            *pcVar4 = local_7;
            pcVar4 = pcVar4 + 1;
          } while ((int)pcVar4 - (int)local_8c < 0x80);
          local_4 = (int)pcVar4 - (int)local_8c;
          iVar3 = FUN_1000_5924(param_1,local_8c,local_4);
        } while (iVar3 == local_4);
        if (iVar3 == -1) {
          local_4 = -1;
        }
        else {
          param_3 = param_3 - local_6;
LAB_1000_5914:
          local_4 = (param_3 + iVar3) - local_4;
        }
      }
    }
  }
  else {
    local_4 = FUN_1000_1b4b(6);
  }
  return local_4;
}

