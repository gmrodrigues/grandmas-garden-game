// TIM2.EXE: FUN_4fd6_1158 @ file 0x0560B8 Ghidra 0x50EB8
// Subsystem: misc | Size: 84 bytes


void __cdecl16far FUN_4fd6_1158(void)

{
  undefined2 uVar1;
  
  uVar1 = uRam00050008;
  if (*"l." != '\0') {
    if (*(int *)0x47 == 0) {
      if (iRam00000066 == 0x5468) {
        uRam00000064 = DAT_5468_002f;
        iRam00000066 = DAT_5468_0031;
        *(undefined1 *)0x42 = 0;
      }
    }
    else {
      (*(code *)*(undefined2 *)0x43)(0x5000,0x554c);
      (*(code *)*(undefined2 *)0x43)(0x5000);
    }
  }
  return;
}

