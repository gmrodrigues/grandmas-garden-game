// TIM2.EXE: FUN_2424_0324 @ file 0x029764 Ghidra 0x24564
// Subsystem: misc | Size: 113 bytes


void __cdecl16far FUN_2424_0324(void)

{
  int *piVar1;
  int iVar2;
  int extraout_DX;
  int iVar3;
  
  FUN_2424_0304();
  FUN_2424_0395(0x2424);
  iVar3 = extraout_DX;
  FUN_2424_0304();
  iVar2 = FUN_460e_0f42(0xffff);
  do {
    if (iVar2 == 0 && iVar3 == 0) {
      return;
    }
    if (*(int *)(iVar2 + 0x1c) != 0 || *(int *)(iVar2 + 0x1e) != 0) {
      if (*(int *)(iVar2 + 0x10) == DAT_5b41_0d12) {
        if (*(int *)(iVar2 + 0x26) == 0) goto LAB_2424_037a;
        *(undefined2 *)(iVar2 + 0x26) = 0;
      }
      (*(code *)*(undefined2 *)(iVar2 + 0x1c))(0x460e,iVar2,iVar3);
    }
LAB_2424_037a:
    piVar1 = (int *)(iVar2 + 6);
    iVar2 = *(int *)(iVar2 + 4);
    iVar3 = *piVar1;
  } while( true );
}

