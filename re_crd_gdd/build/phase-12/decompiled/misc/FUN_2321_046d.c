// TIM2.EXE: FUN_2321_046d @ file 0x02887D Ghidra 0x2367D
// Subsystem: misc | Size: 110 bytes


void __cdecl16far FUN_2321_046d(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  while ((iVar3 = param_1 + -1, param_1 != 0 && (*param_2 != 0))) {
    iVar1 = *param_2;
    param_2 = param_2 + 1;
    iVar2 = FUN_4340_0b8a(iVar1,0x554c,0x277,0x554c);
    param_1 = iVar3;
    if (iVar2 == 0) {
      DAT_554c_3e70 = 1;
    }
    else {
      iVar3 = FUN_4340_0b8a(iVar1,0x554c,0x280,0x554c);
      if (iVar3 == 0) {
        DAT_554c_3e66 = 0;
      }
      else {
        iVar3 = FUN_4340_0b8a(iVar1,0x554c,0x286,0x554c);
        if (iVar3 == 0) {
          DAT_5b41_0511 = 1;
        }
      }
    }
  }
  return;
}

