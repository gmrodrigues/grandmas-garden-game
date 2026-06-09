// TIM2.EXE: FUN_1000_2eee @ file 0x0180EE Ghidra 0x12EEE
// Subsystem: utility | Size: 100 bytes


undefined4 __cdecl16near FUN_1000_2eee(void)

{
  int in_AX;
  int in_CX;
  int iVar1;
  int in_BX;
  int iVar2;
  
  if (in_BX != DAT_1000_2bad) {
    iVar2 = in_BX + in_AX;
    *(int *)0x0 = in_CX - in_AX;
    *(int *)0x2 = in_BX;
    *(int *)0x0 = in_AX;
    iVar1 = in_BX + in_CX;
    if (*(int *)0x2 == 0) {
      *(int *)0x8 = iVar2;
    }
    else {
      *(int *)0x2 = iVar2;
    }
    FUN_1000_2ceb();
    return CONCAT22(in_BX,4);
  }
  *(int *)0x0 = in_AX;
  FUN_1000_305a(0,in_BX + in_AX);
  return CONCAT22(in_BX,4);
}

