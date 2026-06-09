// TIM2.EXE: FUN_1a9e_599d @ file 0x02557D Ghidra 0x2037D
// Subsystem: level | Size: 93 bytes


undefined2 __cdecl16far FUN_1a9e_599d(void)

{
  undefined1 uVar1;
  
  out(0x3c4,2);
  out(0x3c5,(char)DAT_554c_5588);
  out(0x3c4,(char)((uint)DAT_554c_5588 >> 8));
  out(0x3ce,3);
  out(0x3cf,DAT_554c_558a);
  out(0x3ce,8);
  out(0x3cf,(char)DAT_554c_5586);
  out(0x3ce,5);
  out(0x3cf,DAT_554c_5591);
  out(0x3cf,(char)((uint)DAT_554c_5586 >> 8));
  out(0x3ce,4);
  out(0x3cf,(char)DAT_554c_5584);
  out(0x3ce,1);
  out(0x3cf,(char)((uint)DAT_554c_5584 >> 8));
  out(0x3ce,0);
  out(0x3cf,(char)DAT_554c_5582);
  uVar1 = (undefined1)((uint)DAT_554c_5582 >> 8);
  out(0x3ce,uVar1);
  return CONCAT11(uVar1,uVar1);
}

