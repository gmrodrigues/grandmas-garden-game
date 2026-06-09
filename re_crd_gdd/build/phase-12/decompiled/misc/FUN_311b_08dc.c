// TIM2.EXE: FUN_311b_08dc @ file 0x036C8C Ghidra 0x31A8C
// Subsystem: misc | Size: 436 bytes


undefined2 __cdecl16far FUN_311b_08dc(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 in_DX;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_SS;
  undefined2 local_1a [11];
  undefined2 local_4;
  
  puVar5 = (undefined2 *)&DAT_554c_2ff4;
  puVar6 = local_1a;
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  local_4 = 1;
  uRam000557ba = 3;
  uRam000557b6 = 0xa8c;
  uRam000557b8 = 0xa8c;
  DAT_554c_2fee = 3;
  DAT_554c_2ff0 = 0xa8c;
  DAT_554c_2ff2 = 0xa8c;
  DAT_5b41_1b9a = 1;
  if (DAT_5b41_0d28 == '\0') {
    uVar3 = FUN_4340_06ef(0x834);
    FUN_4340_0a29((undefined1 *)&DAT_5b41_0d28,0x554c,uVar3,in_DX);
  }
  if (DAT_5b41_0d33 == '\0') {
    uVar3 = FUN_4340_06ef(0x835);
    FUN_4340_0a29((undefined1 *)&DAT_5b41_0d33,0x554c,uVar3,in_DX);
  }
  FUN_28eb_1234();
  iVar4 = FUN_4876_0009((char *)s_HEDTOHED_ITF_554c_300a,0);
  if (iVar4 != 0) {
    FUN_460e_15eb(0x4e26,0x4e2a,local_1a);
    FUN_4876_1643(0x4e26,(undefined1 *)&DAT_5b41_0d28,0x554c,0xb);
    FUN_4876_1643(0x4e27,(undefined1 *)&DAT_5b41_0d33,0x554c,0xb);
    FUN_4876_0720(0x4e22,0xc10,(char *)s_SIGNIN_RES_554c_3111 + 10,0,0);
    FUN_4876_0720(0x4e23,0xc10,(char *)s_SIGNIN_RES_554c_3111 + 10,0,0);
    FUN_460e_0f98(0x4e22,1);
    FUN_460e_0f98(0x4e23,1);
    FUN_4876_0720(0x4e24,0xc10,(char *)s_SIGNIN_RES_554c_3111 + 10,0,0);
    FUN_4876_0720(0x4e25,0xc10,(char *)s_SIGNIN_RES_554c_3111 + 10,0,0);
    FUN_460e_0f98(0x4e24,1);
    FUN_460e_0f98(0x4e25,1);
    FUN_4876_0720(0x4e21,0xc10,(char *)s_SIGNIN_RES_554c_3111 + 10,0,0);
    FUN_460e_0f98(0x4e21,1);
    FUN_311b_0c97();
    FUN_2424_050d(20000);
    FUN_54a4_003e(0x2424,(undefined2 *)&DAT_5b41_0d3e,0xa90,(char *)s_SIGNIN_RES_554c_3111 + 10,
                  DAT_554c_2f1c);
    func_0x00054ab5(0x54a4,20000,1,0,0);
    FUN_4876_03c4(0,DAT_554c_2f1c);
    if (DAT_5b41_0d3e != 2) {
      DAT_5b41_0947 = 0;
      DAT_5b41_0949 = 0;
      DAT_5b41_094b = 0;
      return local_4;
    }
  }
  DAT_5b41_0947 = 0;
  DAT_5b41_094b = 0;
  DAT_5b41_0949 = 0;
  return 2;
}

