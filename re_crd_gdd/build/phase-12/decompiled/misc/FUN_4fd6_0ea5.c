// TIM2.EXE: FUN_4fd6_0ea5 @ file 0x055E05 Ghidra 0x50C05
// Subsystem: misc | Size: 43 bytes


void __cdecl16far FUN_4fd6_0ea5(void)

{
  code *pcVar1;
  undefined2 uVar2;
  
  uVar2 = uRam00050008;
  if (((*(byte *)0x38 & 4) != 0) && (*(int *)0x32 != -1)) {
    pcVar1 = (code *)swi(0x67);
    (*pcVar1)();
    *(undefined2 *)0x32 = 0xffff;
    *(undefined1 *)0x38 = 0;
  }
  return;
}

