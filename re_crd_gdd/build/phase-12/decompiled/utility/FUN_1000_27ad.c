// TIM2.EXE: FUN_1000_27ad @ file 0x0179AD Ghidra 0x127AD
// Subsystem: utility | Size: 90 bytes


void __cdecl16far FUN_1000_27ad(void)

{
  undefined2 in_AX;
  int in_BX;
  undefined2 *puVar1;
  int unaff_BP;
  undefined2 unaff_SI;
  undefined2 unaff_SS;
  
  puVar1 = (undefined2 *)(*(int *)(in_BX + 4) + unaff_BP);
  puVar1[3] = in_BX;
  puVar1[4] = in_AX;
  puVar1[5] = &stack0x0004;
  puVar1[7] = 0x554c;
  puVar1[8] = unaff_SI;
  puVar1[1] = 0x7ba9;
  puVar1[2] = 0x1000;
  puVar1[6] = 0;
  puVar1[9] = 0;
  puVar1[0xd] = *(undefined2 *)0x10;
  puVar1[0xe] = *(undefined2 *)0x12;
  *puVar1 = *(undefined2 *)0x14;
  *(undefined2 *)0x14 = puVar1;
  return;
}

