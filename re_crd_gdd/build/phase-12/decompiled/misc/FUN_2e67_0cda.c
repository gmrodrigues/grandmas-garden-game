// TIM2.EXE: FUN_2e67_0cda @ file 0x03454A Ghidra 0x2F34A
// Subsystem: misc | Size: 85 bytes


char __cdecl16far FUN_2e67_0cda(void)

{
  char cVar1;
  int in_DX;
  int iVar2;
  int iStack_a;
  undefined4 uStack_6;
  
  if (DAT_5b41_0cb8 == '\0') {
    if (DAT_554c_2fcc != 0 || DAT_554c_2fce != 0) {
      DAT_5b41_0ca0 = FUN_22de_01ec(DAT_554c_2fcc,DAT_554c_2fce,2,1);
      DAT_5b41_0ca2 = in_DX;
    }
    if (DAT_554c_2fd0 != 0) {
      in_DX = DAT_554c_2fd0 >> 0xf;
      DAT_5b41_0c9c = FUN_22de_01ec(DAT_554c_2fd0,in_DX,2,1);
      DAT_5b41_0c9e = in_DX;
    }
    DAT_5b41_0cac = FUN_22de_01ec(0xbd0,0,2,1);
    DAT_5b41_0cae = in_DX;
    DAT_5b41_0cb0 = DAT_5b41_0cac;
    DAT_5b41_0cb2 = in_DX;
    if (DAT_5b41_0cac != 0 || in_DX != 0) {
      iStack_a = DAT_5b41_0cac;
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(int *)(iStack_a + 0x174) = in_DX;
        *(int *)(iStack_a + 0x172) = iStack_a + 0x17a;
        iStack_a = iStack_a + 0x17a;
      }
    }
    if (DAT_554c_2fca != 0) {
      DAT_5b41_0ca4 = (int *)FUN_22de_01ec(DAT_554c_2fca * 0x14,0,2,1);
      uStack_6 = (int *)CONCAT22(in_DX,DAT_5b41_0ca4);
      iVar2 = DAT_554c_2fca;
      DAT_5b41_0ca6 = in_DX;
      DAT_5b41_0ca8 = DAT_5b41_0ca4;
      DAT_5b41_0caa = in_DX;
      if (DAT_5b41_0ca4 != (int *)0x0 || in_DX != 0) {
        while (iVar2 + -1 != 0) {
          ((int *)uStack_6)[1] = uStack_6._2_2_;
          *uStack_6 = (int)((int *)uStack_6 + 10);
          uStack_6 = (int *)CONCAT22(uStack_6._2_2_,(int *)uStack_6 + 10);
          iVar2 = iVar2 + -1;
        }
      }
    }
    if (((((DAT_554c_2fcc == 0 && DAT_554c_2fce == 0) || (DAT_5b41_0ca0 != 0 || DAT_5b41_0ca2 != 0))
         && ((DAT_554c_2fd0 == 0 || (DAT_5b41_0c9c != 0 || DAT_5b41_0c9e != 0)))) &&
        (DAT_5b41_0cac != 0 || DAT_5b41_0cae != 0)) &&
       ((DAT_554c_2fca == 0 || (DAT_5b41_0ca4 != (int *)0x0 || DAT_5b41_0ca6 != 0)))) {
      DAT_5b41_0cb8 = '\x01';
      cVar1 = DAT_5b41_0cb8;
    }
    else {
      FUN_2e67_0e27();
      cVar1 = DAT_5b41_0cb8;
    }
  }
  else {
    cVar1 = '\x01';
  }
  return cVar1;
}

