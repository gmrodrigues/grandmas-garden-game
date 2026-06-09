// TIM2.EXE: FUN_1000_509b @ file 0x01A29B Ghidra 0x1509B
// Subsystem: utility | Size: 204 bytes


int __cdecl16far FUN_1000_509b(uint param_1,char *param_2,int param_3)

{
  uint *puVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined2 uVar8;
  char local_5;
  int local_4;
  
  if (param_1 < DAT_554c_5914) {
    if ((param_3 + 1U < 2) || ((*(byte *)(param_1 * 2 + 0x5917) & 2) != 0)) {
      iVar4 = 0;
    }
    else {
      do {
        local_4 = FUN_1000_2006(param_1,param_2,param_3);
        if (local_4 + 1U < 2) {
          return local_4;
        }
        iVar4 = local_4;
        pcVar6 = param_2;
        pcVar3 = param_2;
        if ((*(byte *)(param_1 * 2 + 0x5917) & 0x40) == 0) {
          return local_4;
        }
        do {
          while( true ) {
            pcVar7 = pcVar3;
            cVar2 = *pcVar6;
            pcVar5 = param_2;
            if (cVar2 == '\x1a') {
              FUN_1000_1c50(param_1,-iVar4,-(uint)(iVar4 != 0),1);
              puVar1 = (uint *)(param_1 * 2 + 0x5916);
              *puVar1 = *puVar1 | 0x200;
              goto LAB_1000_515e;
            }
            if (cVar2 == '\r') break;
            *pcVar7 = cVar2;
            iVar4 = iVar4 + -1;
            pcVar6 = pcVar6 + 1;
            pcVar3 = pcVar7 + 1;
            if (iVar4 == 0) goto LAB_1000_5134;
          }
          iVar4 = iVar4 + -1;
          pcVar6 = pcVar6 + 1;
          pcVar3 = pcVar7;
        } while (iVar4 != 0);
        uVar8 = 0x554c;
        FUN_1000_2006(param_1,&local_5,1);
        *pcVar7 = local_5;
LAB_1000_5134:
        pcVar7 = pcVar7 + 1;
      } while (pcVar7 == pcVar5);
LAB_1000_515e:
      iVar4 = (int)pcVar7 - (int)pcVar5;
    }
  }
  else {
    iVar4 = FUN_1000_1b4b(6);
  }
  return iVar4;
}

