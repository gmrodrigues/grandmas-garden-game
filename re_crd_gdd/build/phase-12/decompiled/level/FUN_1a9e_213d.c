// TIM2.EXE: FUN_1a9e_213d @ file 0x021D1D Ghidra 0x1CB1D
// Subsystem: level | Size: 514 bytes


char * __cdecl16far FUN_1a9e_213d(undefined2 param_1)

{
  char *pcVar1;
  int iVar2;
  int in_DX;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  int iVar3;
  byte local_34c [64];
  undefined1 local_30c [768];
  char *local_c;
  int local_a;
  undefined4 local_8;
  int local_4;
  
  local_a = 0;
  local_c = (char *)0x0;
  DAT_554c_4e94 = *(int *)(DAT_554c_42dd * 2 + 0x4e96);
  for (iVar3 = 1;
      (((undefined2 *)&DAT_554c_445e)[iVar3 * 2] != 0 ||
       ((undefined2 *)&DAT_554c_4460)[iVar3 * 2] != 0 && (iVar3 < 10)); iVar3 = iVar3 + 1) {
  }
  if (iVar3 < 10) {
    iVar2 = FUN_1000_1887(param_1);
    if (iVar2 == 0) {
      local_4 = 1;
      param_1 = FUN_1000_13c9(param_1);
    }
    else {
      local_4 = 0;
    }
    iVar2 = FUN_1000_1465(param_1,*(undefined2 *)(DAT_554c_42dd * 2 + 0x4ed4),0);
    if ((in_DX == -1) && (iVar2 == -1)) {
      if ((DAT_554c_42df != '\0') &&
         (((iVar2 = FUN_1000_1465(param_1,0x4efa,0), in_DX != -1 || (iVar2 != -1)) &&
          (iVar2 = FUN_1000_0d10(local_34c,1,0x40,param_1), iVar2 != 0)))) {
        iVar2 = DAT_554c_4e94 >> 0xf;
        local_c = (char *)FUN_1a9e_539c(DAT_554c_4e94,iVar2,0,0);
        local_a = iVar2;
        if (local_c != (char *)0x0 || iVar2 != 0) {
          local_8 = (char *)CONCAT22(iVar2,local_c);
          for (iVar2 = 0; iVar2 < 0x20; iVar2 = iVar2 + 1) {
            *local_8 = ((byte)((uint)*(undefined2 *)(local_34c + iVar2 * 2) >> 8) & 0xf) << 2;
            pcVar1 = (char *)local_8;
            local_8 = (char *)CONCAT22(local_8._2_2_,(char *)local_8 + 1);
            *local_8 = ((byte)(*(int *)(local_34c + iVar2 * 2) >> 4) & 0xf) << 2;
            local_8 = (char *)CONCAT22(local_8._2_2_,pcVar1 + 2);
            *local_8 = (local_34c[iVar2 * 2] & 0xf) << 2;
            local_8 = (char *)CONCAT22(local_8._2_2_,pcVar1 + 3);
          }
          for (iVar2 = 0; iVar2 < 0x2a0; iVar2 = iVar2 + 1) {
            *local_8 = '\0';
            local_8 = (char *)CONCAT22(local_8._2_2_,(char *)local_8 + 1);
          }
        }
      }
    }
    else {
      iVar2 = DAT_554c_4e94 >> 0xf;
      local_c = (char *)FUN_1a9e_539c(DAT_554c_4e94,iVar2,0,0);
      local_a = iVar2;
      if (local_c != (char *)0x0 || iVar2 != 0) {
        FUN_1000_0d10(local_30c,1,DAT_554c_4e94,param_1);
        func_0x00010511(0x1000,local_c,local_a,local_30c);
      }
    }
    if (local_4 != 0) {
      FUN_1000_1853(param_1,unaff_DI,unaff_SI);
    }
  }
  ((undefined2 *)&DAT_554c_4460)[iVar3 * 2] = local_a;
  ((undefined2 *)&DAT_554c_445e)[iVar3 * 2] = local_c;
  return local_c;
}

