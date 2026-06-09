// TIM2.EXE: FUN_1000_3308 @ file 0x018508 Ghidra 0x13308
// Subsystem: utility | Size: 53 bytes


void __cdecl16near FUN_1000_3308(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int *in_BX;
  int *piVar5;
  
  piVar3 = (int *)FUN_1000_3226();
  if (piVar3 != (int *)0x0) {
    piVar5 = in_BX + 2;
    for (uVar4 = *in_BX - 5U >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
      piVar2 = piVar3;
      piVar3 = piVar3 + 1;
      piVar1 = piVar5;
      piVar5 = piVar5 + 1;
      *piVar2 = *piVar1;
    }
    FUN_1000_3157(in_BX + 2);
  }
  return;
}

