// TIM2.EXE: FUN_1000_a3c1 @ file 0x01F5C1 Ghidra 0x1A3C1
// Subsystem: utility | Size: 48 bytes


int __cdecl16far FUN_1000_a3c1(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar6 = (undefined2)((ulong)param_2 >> 0x10);
  pcVar5 = (char *)param_2;
  uVar3 = 0xffff;
  pcVar4 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 != '\0');
  uVar3 = ~uVar3;
  uVar7 = (undefined2)((ulong)param_1 >> 0x10);
  pcVar4 = (char *)param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar2 = pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar1 == *pcVar2);
  return (uint)(byte)pcVar4[-1] - (uint)(byte)pcVar5[-1];
}

