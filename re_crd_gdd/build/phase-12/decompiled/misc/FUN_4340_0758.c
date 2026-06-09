// TIM2.EXE: FUN_4340_0758 @ file 0x048D58 Ghidra 0x43B58
// Subsystem: misc | Size: 155 bytes


/* WARNING: Restarted to delay deadcode elimination for space: ram */

int __cdecl16far FUN_4340_0758(undefined2 param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int in_DX;
  char *pcVar4;
  int iVar5;
  undefined4 local_6;
  
  if (DAT_53c6_0006 != 0) {
    pcVar3 = (char *)FUN_4340_06ef(param_1);
    local_6 = (char *)CONCAT22(in_DX,pcVar3);
    if (pcVar3 != (char *)0x0 || in_DX != 0) {
      DAT_53c6_0008 = (DAT_53c6_0008 + 1) % DAT_53c6_0006;
      pcVar3 = (char *)(DAT_53c6_0008 * 0x100 + DAT_53c6_000a);
      for (iVar5 = 0xff; pcVar2 = local_6, pcVar4 = pcVar3, iVar5 != 0; iVar5 = iVar5 + -1) {
        local_6 = (char *)CONCAT22(local_6._2_2_,(char *)local_6 + 1);
        cVar1 = *pcVar2;
        pcVar4 = pcVar3 + 1;
        *pcVar3 = cVar1;
        if (cVar1 == '\0') break;
        pcVar3 = pcVar4;
      }
      *pcVar4 = '\0';
      return DAT_53c6_0008 * 0x100 + DAT_53c6_000a;
    }
  }
  return 0;
}

