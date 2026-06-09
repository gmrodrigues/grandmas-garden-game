// TIM2.EXE: FUN_1000_9a89 @ file 0x01EC89 Ghidra 0x19A89
// Subsystem: utility | Size: 81 bytes


undefined2 __cdecl16far FUN_1000_9a89(int param_1)

{
  int *piVar1;
  undefined2 uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined2 unaff_ES;
  bool bVar6;
  
  if (DAT_554c_5b50 == 0) {
    uVar2 = 1;
  }
  else {
    piVar4 = DAT_554c_5b54;
    if (DAT_554c_5b54 == (int *)0x0) {
LAB_1000_9ac4:
      uVar2 = 2;
    }
    else {
      do {
        uVar3 = *piVar4 - 8U >> 1;
        bVar6 = uVar3 == 0;
        piVar5 = piVar4 + 4;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          piVar1 = piVar5;
          piVar5 = piVar5 + 1;
          bVar6 = param_1 == *piVar1;
        } while (bVar6);
        if (!bVar6) {
          return 0xfffd;
        }
        piVar5 = (int *)piVar4[3];
        if (piVar5 == DAT_554c_5b54) goto LAB_1000_9ac4;
      } while ((piVar4 != piVar5) && (piVar4 = piVar5, piVar5 != (int *)0x0));
      uVar2 = 0xffff;
    }
  }
  return uVar2;
}

