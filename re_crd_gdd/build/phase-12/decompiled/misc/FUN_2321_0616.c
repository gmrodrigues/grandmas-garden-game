// TIM2.EXE: FUN_2321_0616 @ file 0x028A26 Ghidra 0x23826
// Subsystem: misc | Size: 206 bytes


void __cdecl16far FUN_2321_0616(void)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  
  FUN_5538_0020(0x2321);
  DAT_554c_42d8 = DAT_554c_42d2;
  FUN_28eb_1234();
  FUN_1a9e_2342(DAT_5b41_0527,DAT_5b41_0529);
  FUN_406b_04d8(0);
  DAT_5b41_0517 = 0;
  DAT_5b41_0519 = DAT_554c_49ac + -1;
  DAT_5b41_051b = 0;
  DAT_5b41_051d = 0x237;
  DAT_5b41_0537 = 0;
  DAT_5b41_0539 = 0x237;
  DAT_5b41_053b = 0;
  DAT_5b41_0543 = 0;
  DAT_5b41_053f = 0;
  DAT_5b41_0541 = DAT_554c_49aa + -1;
  DAT_5b41_0545 = DAT_554c_49ac + -1;
  DAT_5b41_053d = DAT_5b41_0519;
  FUN_2321_0af4();
  for (iVar3 = 0; iVar3 < 0x119; iVar3 = iVar3 + 1) {
    iVar1 = *(int *)(iVar3 * 2 + 0x302);
    if (*(int *)(iVar1 + 0x1c) != 0 || *(int *)(iVar1 + 0x1e) != 0) {
      puVar2 = (undefined2 *)(*(int *)(iVar3 * 2 + 0x302) + 0x1c);
      (*(code *)*puVar2)(0x406b,0,0);
    }
  }
  FUN_311b_0008();
  FUN_54b4_005c((char *)s_SIGNIN_RES_554c_3111 + 10);
  FUN_54bb_003e(0x54b4);
  DAT_5b41_0755 = 1000;
  FUN_2e67_045f(1000,0,0,1);
  return;
}

