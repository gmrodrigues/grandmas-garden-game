// TIM2.EXE: FUN_553b_00b6 @ file 0x05A666 Ghidra 0x55466
// Subsystem: misc | Size: 10 bytes


uint FUN_553b_00b6(void)

{
  code *pcVar1;
  byte bVar2;
  char extraout_AH;
  byte in_AF;
  
  pcVar1 = (code *)swi(0x3f);
  bVar2 = (*pcVar1)();
  TaskRegister();
  in_AF = 9 < (bVar2 & 0xf) | in_AF;
  return CONCAT11(extraout_AH - in_AF,bVar2 + in_AF * -6) & 0xff0f;
}

