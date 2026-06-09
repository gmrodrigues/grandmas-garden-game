// TIM2.EXE: FUN_28eb_482b @ file 0x0328DB Ghidra 0x2D6DB
// Subsystem: misc | Size: 107 bytes


void __cdecl16far FUN_28eb_482b(void)

{
  int iVar1;
  int in_DX;
  int iVar2;
  
  if ((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0) {
    FUN_28eb_4896((int)DAT_5b41_0567,DAT_5b41_0567._2_2_);
  }
  iVar1 = FUN_28eb_3287(0x3000);
  while( true ) {
    if (iVar1 == 0 && in_DX == 0) break;
    iVar2 = in_DX;
    if ((in_DX != DAT_5b41_0567._2_2_) || (iVar1 != (int)DAT_5b41_0567)) {
      FUN_28eb_4896(iVar1,in_DX);
    }
    iVar1 = FUN_28eb_32d8(iVar1,in_DX,0x1000);
    in_DX = iVar2;
  }
  return;
}

