// TIM2.EXE: FUN_3f2b_011d @ file 0x0445CD Ghidra 0x3F3CD
// Subsystem: sound | Size: 259 bytes


void __cdecl16far FUN_3f2b_011d(int param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  undefined4 local_6;
  
  if (DAT_5b41_1b42 != (undefined2 *)0x0 || DAT_5b41_1b44 != 0) {
    puVar3 = DAT_5b41_1b42;
    iVar4 = DAT_5b41_1b44;
    if (param_1 != 0) {
      local_6 = (undefined2 *)CONCAT22(DAT_5b41_1b44,DAT_5b41_1b42);
      iVar6 = 1;
      while( true ) {
        puVar3 = DAT_5b41_1b42;
        iVar4 = DAT_5b41_1b44;
        iVar5 = DAT_5b41_1b46;
        if ((undefined2 *)local_6 == (undefined2 *)0x0 && local_6._2_2_ == 0) break;
        while( true ) {
          puVar3 = (undefined2 *)local_6;
          uVar7 = (undefined2)((ulong)local_6 >> 0x10);
          if (iVar5 == 0) break;
          if ((puVar3[1] != 0) && (puVar3[2] != 0)) {
            puVar2 = (undefined2 *)((int)DAT_5b41_1b3e + puVar3[2] * 4);
            (*(code *)*puVar2)((char *)s_PROAUDIO_DRV_554c_3f20 + 0xb,iVar6);
          }
          iVar6 = iVar6 + 1;
          local_6 = (undefined2 *)CONCAT22(uVar7,puVar3 + 9);
          iVar5 = iVar5 + -1;
        }
        local_6 = (undefined2 *)CONCAT22(puVar3[1],(undefined2 *)*local_6);
      }
    }
    while (puVar3 != (undefined2 *)0x0 || iVar4 != 0) {
      iVar6 = (puVar3 + DAT_5b41_1b46 * 9)[1];
      puVar1 = (undefined2 *)puVar3[DAT_5b41_1b46 * 9];
      FUN_22de_0351(puVar3,iVar4);
      puVar3 = puVar1;
      iVar4 = iVar6;
    }
    if ((int)DAT_5b41_1b3e != 0 || DAT_5b41_1b3e._2_2_ != 0) {
      FUN_22de_0351((int)DAT_5b41_1b3e,DAT_5b41_1b3e._2_2_);
    }
    DAT_5b41_1b44 = 0;
    DAT_5b41_1b42 = (undefined2 *)0x0;
    DAT_5b41_1b3e = 0;
    DAT_5b41_1b46 = 0;
    DAT_5b41_1b48 = 0;
    DAT_5b41_1b4a = 0;
  }
  return;
}

