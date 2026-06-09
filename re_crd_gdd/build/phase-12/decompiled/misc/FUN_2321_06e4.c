// TIM2.EXE: FUN_2321_06e4 @ file 0x028AF4 Ghidra 0x238F4
// Subsystem: misc | Size: 584 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_2321_06e4(void)

{
  int iVar1;
  undefined2 unaff_BP;
  int unaff_SI;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = unaff_SI;
  FUN_2321_0616();
  DAT_5b41_0953 = 0;
  FUN_406b_055f(DAT_5b41_0527,DAT_5b41_0529);
  FUN_550e_002a(0x406b);
  DAT_5b41_0937 = 0x1000;
  DAT_5b41_1b9a = 0;
  uVar2 = 0x551d;
  FUN_551d_0039();
  iRam000557bc = 7;
  DAT_554c_02f0 = 0xffff;
  LAB_554c_02ee = 0xffff;
  DAT_5b41_0567 = 0;
  uVar4 = 0;
LAB_2321_091f:
  if (DAT_5b41_0937 == 1) {
    return;
  }
  DAT_5b41_1b9a = (uint)(iRam000557bc == 2);
  while (iRam000557bc == 7) {
    FUN_54b0_0034(uVar2,iVar3,uVar4,unaff_BP);
    uVar2 = 0x54b0;
    if (iRam000557bc != 7) {
      uVar2 = 0x2424;
      unaff_BP = 0x3974;
      FUN_2424_050d();
    }
  }
  DAT_554c_02f0 = 0xffff;
  LAB_554c_02ee = 0xffff;
  uVar4 = DAT_5b41_0567;
  FUN_2424_000c();
  FUN_406b_03cb(0xfffd,0);
  if ((DAT_5b41_0939 != 9) && ((DAT_5b41_0939 & 0x8000) == 0)) goto code_r0x000239b3;
  goto LAB_2321_07f7;
code_r0x000239b3:
  FUN_54b4_0034(0x406b);
  if ((DAT_5b41_16af != 0 || DAT_5b41_16b1 != 0) &&
     ((*(int *)(DAT_5b41_16af + 0x20) != 0 || *(int *)(DAT_5b41_16af + 0x22) != 0 &&
      (iVar1 = FUN_28eb_4d94(), iVar1 == 0)))) {
    (*(code *)*(undefined2 *)(DAT_5b41_16af + 0x20))(0x28eb,DAT_5b41_16af,DAT_5b41_16b1,0);
  }
  uVar2 = 0x460e;
  FUN_460e_1092(0,0x61,0x54a4);
  if (iRam000557bc == 7) goto LAB_2321_091f;
LAB_2321_07f7:
  uVar2 = 0x28eb;
  iVar1 = FUN_28eb_4d94();
  if ((iVar1 == 0) || (DAT_5b41_16af != 0 || DAT_5b41_16b1 != 0)) {
    if (DAT_5b41_16af == 0 && DAT_5b41_16b1 == 0) {
      if ((DAT_5b41_0939 == 9) || ((DAT_5b41_0939 & 0x8000) != 0)) {
        uVar2 = 0x550e;
        FUN_550e_0025(0x28eb);
      }
      if (((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0) && (unaff_SI == 0)) {
        FUN_2424_0915((int)DAT_5b41_0567,DAT_5b41_0567._2_2_,3);
        uVar2 = 0x2424;
        FUN_2424_0f94((int)DAT_5b41_0567,DAT_5b41_0567._2_2_,3);
        if ((DAT_5b41_0939 != 9) && ((DAT_5b41_0939 & 0x8000) == 0)) {
          DAT_5b41_0567 = 0;
        }
        unaff_SI = 1;
      }
      FUN_550e_0020(uVar2);
    }
  }
  else {
    FUN_550e_0025(0x28eb);
    unaff_SI = 0;
  }
  iVar1 = (int)((ulong)uVar4 >> 0x10);
  if (((int)uVar4 == 0 && iVar1 == 0) || ((*(byte *)((int)uVar4 + 0xf) & 0x20) == 0)) {
    if (((int)DAT_5b41_0567 == 0 && DAT_5b41_0567._2_2_ == 0) ||
       ((*(byte *)((int)DAT_5b41_0567 + 0xf) & 0x20) == 0)) goto LAB_2321_08c9;
  }
  FUN_2424_35f9(0,0);
  if ((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0) {
    FUN_2424_35f9((int)DAT_5b41_0567,DAT_5b41_0567._2_2_);
  }
LAB_2321_08c9:
  FUN_2424_0f94((int)DAT_5b41_0567,DAT_5b41_0567._2_2_,0);
  func_0x00055164(0x2424);
  FUN_2321_092c();
  FUN_2424_03c5();
  if (DAT_5b41_092d != 0) {
    FUN_2424_201e();
    DAT_5b41_092d = DAT_5b41_092d + -1;
  }
  FUN_2424_0771(1);
  FUN_2e67_045f(DAT_5b41_0755,0,0,1);
  FUN_2321_0597(3);
  uVar2 = 0x28eb;
  FUN_28eb_482b();
  goto LAB_2321_091f;
}

