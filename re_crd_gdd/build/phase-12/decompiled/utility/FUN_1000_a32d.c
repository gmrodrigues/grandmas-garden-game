// TIM2.EXE: FUN_1000_a32d @ file 0x01F52D Ghidra 0x1A32D
// Subsystem: utility | Size: 40 bytes


int __cdecl16far FUN_1000_a32d(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  uVar3 = 0;
  uVar4 = 0;
  if (param_3 != 0) {
    uVar8 = (undefined2)((ulong)param_1 >> 0x10);
    pcVar5 = (char *)param_1;
    uVar7 = (undefined2)((ulong)param_2 >> 0x10);
    pcVar6 = (char *)param_2;
    do {
      if (param_3 == 0) break;
      param_3 = param_3 + -1;
      pcVar2 = pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 == *pcVar2);
    uVar3 = (uint)(byte)pcVar5[-1];
    uVar4 = (uint)(byte)pcVar6[-1];
  }
  return uVar3 - uVar4;
}

