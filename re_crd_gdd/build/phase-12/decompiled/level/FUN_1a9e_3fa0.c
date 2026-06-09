// TIM2.EXE: FUN_1a9e_3fa0 @ file 0x023B80 Ghidra 0x1E980
// Subsystem: level | Size: 57 bytes


bool __cdecl16far FUN_1a9e_3fa0(void)

{
  code *pcVar1;
  byte bVar2;
  bool bVar3;
  undefined2 in_stack_00000002;
  
  bVar3 = DAT_554c_4f22 != '\0';
  if (bVar3) {
    out(0x43,0x36);
    out(0x40,0);
    out(0x40,0);
    bVar2 = in(0x21);
    out(0x21,bVar2 & 0xfc);
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    *(undefined1 *)&DAT_554c_4f22 = 0;
  }
  return bVar3;
}

