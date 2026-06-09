// TIM2.EXE: FUN_1000_3773 @ file 0x018973 Ghidra 0x13773
// Subsystem: utility | Size: 151 bytes


undefined2 __cdecl16far FUN_1000_3773(int param_1)

{
  code *pcVar1;
  code *pcVar2;
  int local_6;
  int local_4;
  
  local_4 = FUN_1000_3620(param_1);
  if (local_4 == -1) {
    return 1;
  }
  local_6 = *(int *)(local_4 * 4 + 0x5b5b);
  pcVar1 = (code *)*(int *)(local_4 * 4 + 0x5b59);
  if ((local_6 == 0) && (pcVar1 == (code *)0x1)) {
    return 0;
  }
  if (pcVar1 != (code *)0x0 || local_6 != 0) {
    *(undefined2 *)(local_4 * 4 + 0x5b5b) = 0;
    *(undefined2 *)(local_4 * 4 + 0x5b59) = 0;
    (*pcVar1)(0x1000,param_1,*(undefined1 *)(local_4 + 0x5b77));
    return 0;
  }
  if (param_1 != 2) {
    if (param_1 != 0x16) goto LAB_1000_37d1;
    FUN_1000_13f1();
  }
  pcVar2 = (code *)swi(0x23);
  (*pcVar2)();
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)();
LAB_1000_37d1:
  FUN_1000_17d2(1);
  return 0;
}

