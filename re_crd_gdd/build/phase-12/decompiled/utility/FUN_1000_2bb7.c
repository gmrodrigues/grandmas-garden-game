// TIM2.EXE: FUN_1000_2bb7 @ file 0x017DB7 Ghidra 0x12BB7
// Subsystem: utility | Size: 99 bytes


void __cdecl16near FUN_1000_2bb7(void)

{
  int in_DX;
  undefined2 uVar1;
  int iVar2;
  
  if (in_DX == DAT_1000_2bab) {
LAB_1000_2bf5:
    DAT_1000_2bab = 0;
    DAT_1000_2bad = 0;
    DAT_1000_2baf = 0;
  }
  else {
    iVar2 = *(int *)0x2;
    DAT_1000_2bad = iVar2;
    if (*(int *)0x2 == 0) {
      in_DX = DAT_1000_2bab;
      if (iVar2 != DAT_1000_2bab) {
        DAT_1000_2bad = *(int *)0x8;
        uVar1 = 0;
        FUN_1000_2c8b(0,iVar2);
        goto LAB_1000_2c13;
      }
      goto LAB_1000_2bf5;
    }
  }
  uVar1 = 0;
  iVar2 = in_DX;
LAB_1000_2c13:
  FUN_1000_305a(uVar1,iVar2);
  return;
}

