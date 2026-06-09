// TIM2.EXE: FUN_1000_9a3f @ file 0x01EC3F Ghidra 0x19A3F
// Subsystem: utility | Size: 74 bytes


undefined2 __cdecl16far FUN_1000_9a3f(int param_1)

{
  int *piVar1;
  undefined2 uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined2 unaff_ES;
  
  if (DAT_554c_5b50 == 0) {
    uVar2 = 1;
  }
  else {
    piVar4 = DAT_554c_5b54;
    if (DAT_554c_5b54 == (int *)0x0) {
LAB_1000_9a78:
      uVar2 = 2;
    }
    else {
      do {
        piVar5 = piVar4 + 4;
        for (uVar3 = *piVar4 - 8U >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
          piVar1 = piVar5;
          piVar5 = piVar5 + 1;
          *piVar1 = param_1;
        }
        piVar5 = (int *)piVar4[3];
        if (piVar5 == DAT_554c_5b54) goto LAB_1000_9a78;
      } while ((piVar4 != piVar5) && (piVar4 = piVar5, piVar5 != (int *)0x0));
      uVar2 = 0xffff;
    }
  }
  return uVar2;
}

