// TIM2.EXE: FUN_28eb_4dea @ file 0x032E9A Ghidra 0x2DC9A
// Subsystem: misc | Size: 107 bytes


void __cdecl16far FUN_28eb_4dea(void)

{
  undefined1 local_6 [2];
  char local_4;
  char local_3;
  
  DAT_5b41_0935 = DAT_5b41_0511;
  DAT_5b41_0933 = DAT_5b41_0511;
  DAT_5b41_0931 = DAT_5b41_0511;
  DAT_5b41_092f = DAT_5b41_0511;
  FUN_1000_185e(local_6);
  if ((local_3 == '\x02') && (local_4 == '\x0e')) {
    DAT_5b41_092f = 1;
  }
  if ((local_3 == '\x03') && (local_4 == '\x11')) {
    DAT_5b41_0931 = 1;
  }
  if ((local_3 == '\n') && (local_4 == '\x1f')) {
    DAT_5b41_0933 = 1;
  }
  if ((local_3 == '\f') && (local_4 == '\x19')) {
    DAT_5b41_0935 = 1;
  }
  return;
}

