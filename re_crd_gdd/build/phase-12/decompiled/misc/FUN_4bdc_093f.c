// TIM2.EXE: FUN_4bdc_093f @ file 0x0518FF Ghidra 0x4C6FF
// Subsystem: misc | Size: 36 bytes


void __cdecl16far FUN_4bdc_093f(void)

{
  int in_AX;
  undefined1 in_CL;
  undefined1 in_CH;
  char in_DL;
  undefined2 unaff_ES;
  
  if (*(char *)(in_AX + 0x15e) != in_DL) {
    *(char *)(in_AX + 0x160) = in_DL;
    *(undefined1 *)(in_AX + 0x161) = in_CL;
    *(undefined1 *)(in_AX + 0x163) = in_CH;
    *(undefined1 *)(in_AX + 0x162) = 0;
  }
  return;
}

