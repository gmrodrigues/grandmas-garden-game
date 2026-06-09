// TIM2.EXE: FUN_1a9e_58d9 @ file 0x0254B9 Ghidra 0x202B9
// Subsystem: level | Size: 95 bytes


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void __cdecl16far FUN_1a9e_58d9(void)

{
  undefined2 in_CX;
  undefined2 in_DX;
  undefined1 in_BL;
  undefined2 *puVar1;
  
  if ((DAT_554c_5596 == '\0') &&
     (DAT_554c_5178 = in_CX, DAT_554c_517a = in_DX, DAT_554c_5595 = in_BL,
     DAT_554c_517c != (code *)0x0 || DAT_554c_517e != 0)) {
    DAT_554c_5596 = '\x01';
    DAT_554c_557e = 0x1a9e;
    DAT_554c_557c = 0x2fe;
    FUN_1a9e_5938();
    DAT_554c_557e = 0x1a9e;
    puVar1 = (undefined2 *)&DAT_554c_557c;
    DAT_554c_557c = 0x303;
    (*DAT_554c_517c)();
    *(undefined2 *)((int)puVar1 + -2) = 0x1a9e;
    *(undefined2 *)((int)puVar1 + -4) = 0x307;
    FUN_1a9e_599d();
    DAT_554c_5596 = DAT_554c_5596 + -1;
  }
  return;
}

