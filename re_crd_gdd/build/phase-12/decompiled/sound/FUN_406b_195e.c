// TIM2.EXE: FUN_406b_195e @ file 0x04720E Ghidra 0x4200E
// Subsystem: sound | Size: 121 bytes


void __cdecl16far
FUN_406b_195e(int param_1,undefined2 param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int local_4;
  
  pbVar8 = (byte *)(param_3 & 0xf);
  local_4 = 0;
  do {
    iVar7 = 8;
    do {
      pcVar5 = (char *)(param_1 + local_4);
      bVar4 = 0;
      iVar6 = param_6;
      do {
        pcVar1 = pcVar5;
        cVar3 = *pcVar1;
        *pcVar1 = *pcVar1 << 1;
        bVar4 = bVar4 >> 1 | (cVar3 < '\0') << 7;
        pcVar5 = pcVar5 + (param_5 >> 3);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      for (iVar6 = 8 - param_6; iVar6 != 0; iVar6 = iVar6 + -1) {
        bVar4 = bVar4 >> 1;
      }
      pbVar2 = pbVar8;
      pbVar8 = pbVar8 + 1;
      *pbVar2 = bVar4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    local_4 = local_4 + 1;
  } while (local_4 < (int)(param_5 >> 3));
  return;
}

