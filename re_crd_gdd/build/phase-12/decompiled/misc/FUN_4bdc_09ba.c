// TIM2.EXE: FUN_4bdc_09ba @ file 0x05197A Ghidra 0x4C77A
// Subsystem: misc | Size: 190 bytes


/* WARNING: Removing unreachable block (ram,0x0004c7fc) */
/* WARNING: Removing unreachable block (ram,0x0004c7ff) */
/* WARNING: Removing unreachable block (ram,0x0004c808) */

void __cdecl16far FUN_4bdc_09ba(void)

{
  undefined1 uVar1;
  int in_AX;
  undefined2 uVar2;
  char in_CL;
  int unaff_SI;
  int iVar3;
  undefined2 unaff_ES;
  
  if (*(char *)(in_AX + 0x15c) != in_CL) {
    *(char *)(in_AX + 0x15c) = in_CL;
    uVar2 = FUN_4bdc_2159();
    if (unaff_SI != 0xff) {
      *(undefined2 *)(unaff_SI + 0xe) = 0;
      *(undefined2 *)(unaff_SI + 0x10) = 0;
      if (unaff_SI != 0x3c) {
        do {
          iVar3 = unaff_SI;
          *(undefined2 *)(iVar3 + 0xe) = *(undefined2 *)(iVar3 + 0x12);
          *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(iVar3 + 0x14);
          unaff_SI = iVar3 + 4;
        } while (iVar3 + 4 != 0x3c);
        *(undefined2 *)(iVar3 + 0x12) = 0;
        *(undefined2 *)(iVar3 + 0x14) = 0;
      }
      uVar1 = *(undefined1 *)(in_AX + 0x15c);
      for (iVar3 = 0; *(int *)(iVar3 + 0x10) != 0; iVar3 = iVar3 + 4) {
        *(undefined1 *)((int)*(undefined4 *)(iVar3 + 0xe) + 0x15c) = uVar1;
      }
      *(undefined2 *)(iVar3 + 0xe) = uVar2;
      *(undefined2 *)(iVar3 + 0x10) = unaff_ES;
      FUN_4bdc_0da0();
    }
  }
  return;
}

