// TIM2.EXE: FUN_4bdc_1944 @ file 0x052904 Ghidra 0x4D704
// Subsystem: misc | Size: 132 bytes


void __cdecl16far FUN_4bdc_1944(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (cRam000401ff != '\0') {
    return;
  }
  if (cRam0004020a != '\0') {
    FUN_4bdc_0da0();
  }
  iVar2 = 0;
  do {
    iVar3 = (int)((ulong)*(undefined4 *)(iVar2 + 0xe) >> 0x10);
    iVar1 = (int)*(undefined4 *)(iVar2 + 0xe);
    if (iVar3 == 0 && iVar1 == 0) break;
    if (*(char *)(iVar1 + 0x164) == '\0') {
      if (*(char *)(iVar1 + 0x163) != '\0') {
        FUN_4bdc_175f();
        if (*(char *)(iVar1 + 0x158) == -1) {
          iVar2 = iVar2 + -4;
          goto LAB_4bdc_19a6;
        }
      }
      if (*(char *)(iVar1 + 0x165) == '\0') {
        FUN_4bdc_1ac4();
      }
      else {
        FUN_4bdc_19c8();
      }
      if (*(char *)(iVar1 + 0x158) != -1) goto LAB_4bdc_19a6;
    }
    else {
LAB_4bdc_19a6:
      iVar2 = iVar2 + 4;
    }
  } while (iVar2 != 0x40);
  FUN_4bdc_19f4();
  FUN_4bdc_18fc();
  (*pcRam000556ad)(0x4000);
  return;
}

