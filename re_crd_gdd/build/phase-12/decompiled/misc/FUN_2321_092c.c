// TIM2.EXE: FUN_2321_092c @ file 0x028D3C Ghidra 0x23B3C
// Subsystem: misc | Size: 300 bytes


void __cdecl16far FUN_2321_092c(void)

{
  int iVar1;
  undefined2 uVar2;
  
  if (iRam000557bc == 2) {
    if (iRam0005575e != DAT_5b41_096f) {
      iRam0005575e = DAT_5b41_096f;
      DAT_5b41_094f = 1 - DAT_5b41_094f;
      DAT_5b41_0951 = 0;
    }
    if (((DAT_5b41_0951 == 0) && (DAT_5b41_1ae2 == 0 && DAT_5b41_1ae4 == 0)) &&
       (DAT_5b41_0937 != 0x2000)) {
      DAT_5b41_0953 = 0;
      DAT_5b41_094f = 1 - DAT_5b41_094f;
      FUN_2e67_045f(0xbf8,0,1,1);
      FUN_2e67_0a1f();
      if (DAT_5b41_094f == 0) {
        DAT_5b41_0757 = 0xc;
        DAT_5b41_0951 = iRam000557b6;
      }
      else {
        DAT_5b41_0757 = 9;
        DAT_5b41_0951 = iRam000557b8;
      }
      FUN_311b_02be();
      FUN_311b_02fa();
      FUN_2424_03c5();
      if (DAT_5b41_094f == 0) {
        uVar2 = 0x22;
      }
      else {
        uVar2 = 0x23;
      }
      FUN_406b_03cb(uVar2,0xffdc);
      FUN_54a4_0043(0,(undefined2 *)&DAT_5b41_1a3c,0x7983,0,0);
      FUN_2424_050d(0);
      FUN_2424_03c5();
      DAT_5b41_0945 = 0;
      DAT_5b41_0943 = 0;
      DAT_5b41_093d = 0;
      DAT_5b41_093b = 0;
      DAT_5b41_0941 = 0;
      DAT_5b41_093f = 0;
      DAT_5b41_0953 = 1;
    }
    iVar1 = FUN_406b_03cb(0xfffc,0);
    if (iVar1 == 0) {
      if (DAT_5b41_094f == 0) {
        uVar2 = 0x22;
      }
      else {
        uVar2 = 0x23;
      }
      FUN_406b_03cb(uVar2,0xffdc);
    }
  }
  return;
}

