// TIM2.EXE: FUN_1a9e_5938 @ file 0x025518 Ghidra 0x20318
// Subsystem: level | Size: 101 bytes


undefined2 __cdecl16far FUN_1a9e_5938(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  uVar1 = in(0x3ce);
  out(0x3ce,0);
  uVar2 = in(0x3cf);
  DAT_554c_5582 = CONCAT11(uVar1,uVar2);
  out(0x3ce,1);
  uVar1 = in(0x3cf);
  out(0x3cf,0);
  out(0x3ce,4);
  uVar2 = in(0x3cf);
  DAT_554c_5584 = CONCAT11(uVar1,uVar2);
  out(0x3ce,5);
  uVar1 = in(0x3cf);
  out(0x3cf,DAT_554c_5591);
  DAT_a000_ffff = DAT_554c_5591;
  out(0x3cf,DAT_554c_558e);
  out(0x3ce,8);
  uVar2 = in(0x3cf);
  DAT_554c_5586 = CONCAT11(uVar1,uVar2);
  out(0x3cf,0xff);
  out(0x3ce,3);
  DAT_554c_558a = in(0x3cf);
  out(0x3cf,0);
  uVar1 = in(0x3c4);
  out(0x3c4,2);
  uVar2 = in(0x3c5);
  DAT_554c_5588 = CONCAT11(uVar1,uVar2);
  out(0x3c5,0xf);
  return CONCAT11(uVar1,0xf);
}

