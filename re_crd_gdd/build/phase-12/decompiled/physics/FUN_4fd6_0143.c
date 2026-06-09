// TIM2.EXE: FUN_4fd6_0143 @ file 0x0550A3 Ghidra 0x4FEA3
// Subsystem: physics | Size: 83 bytes


void __cdecl16far FUN_4fd6_0143(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 in_BX;
  undefined2 unaff_ES;
  undefined2 in_stack_00000000;
  undefined2 in_stack_00000002;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(in_BX);
  *(undefined2 *)0x2 = in_stack_00000000;
  *(undefined2 *)0x4 = in_stack_00000002;
  if (*(int *)0x128 == 0) {
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    *(undefined2 *)0x128 = uVar2;
  }
  else {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    *(undefined2 *)0x128 = 0;
  }
  return;
}

