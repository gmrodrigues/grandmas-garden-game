// TIM2.EXE: FUN_406b_0e67 @ file 0x046717 Ghidra 0x41517
// Subsystem: sound | Size: 692 bytes


/* WARNING: Removing unreachable block (ram,0x0004178a) */

void __cdecl16far FUN_406b_0e67(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  iVar2 = DAT_5b41_1b6a + 1;
  bVar6 = DAT_5b41_1b6a == 0;
  DAT_5b41_1b6a = iVar2;
  if ((bVar6) && ((DAT_53bd_004a & 2) == 0)) {
    DAT_5b41_1b8c = 0;
    if (((DAT_53bd_0052 & 1) != 0) && (DAT_5b41_1ae2 == 0 && DAT_5b41_1ae4 == 0)) {
      iVar2 = FUN_1a9e_4d00(0x2a);
      if ((iVar2 == 0) && (iVar2 = FUN_1a9e_4d00(0x36), iVar2 == 0)) {
        iVar2 = 1;
      }
      else {
        iVar2 = 4;
      }
      iVar1 = FUN_1a9e_4d00(0x47);
      if (((iVar1 != 0) || (iVar1 = FUN_1a9e_4d00(0x4b), iVar1 != 0)) ||
         (iVar1 = FUN_1a9e_4d00(0x4f), iVar1 != 0)) {
        DAT_5b41_1b7c = DAT_5b41_1b7c - DAT_53bd_0002 * iVar2;
        DAT_5b41_1b8c = DAT_5b41_1b8c | 4;
      }
      iVar1 = FUN_1a9e_4d00(0x49);
      if (((iVar1 != 0) || (iVar1 = FUN_1a9e_4d00(0x4d), iVar1 != 0)) ||
         (iVar1 = FUN_1a9e_4d00(0x51), iVar1 != 0)) {
        DAT_5b41_1b7c = DAT_5b41_1b7c + DAT_53bd_0002 * iVar2;
        DAT_5b41_1b8c = DAT_5b41_1b8c | 8;
      }
      iVar1 = FUN_1a9e_4d00(0x47);
      if (((iVar1 != 0) || (iVar1 = FUN_1a9e_4d00(0x48), iVar1 != 0)) ||
         (iVar1 = FUN_1a9e_4d00(0x49), iVar1 != 0)) {
        DAT_5b41_1b7e = DAT_5b41_1b7e - DAT_53bd_0002 * iVar2;
        DAT_5b41_1b8c = DAT_5b41_1b8c | 1;
      }
      iVar1 = FUN_1a9e_4d00(0x4f);
      if (((iVar1 != 0) || (iVar1 = FUN_1a9e_4d00(0x50), iVar1 != 0)) ||
         (iVar1 = FUN_1a9e_4d00(0x51), iVar1 != 0)) {
        DAT_5b41_1b7e = DAT_5b41_1b7e + DAT_53bd_0002 * iVar2;
        DAT_5b41_1b8c = DAT_5b41_1b8c | 2;
      }
      if (DAT_5b41_1b8c != 0) {
        FUN_1a9e_5a40(DAT_5b41_1b7c,DAT_5b41_1b7e);
      }
    }
    if ((DAT_554c_5594 == '\0') || (iVar2 = FUN_1a9e_5a82(0), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    iVar2 = FUN_1a9e_4d00(0x39);
    if (((iVar2 == 0) && (iVar2 = FUN_1a9e_4d00(0x1c), iVar2 == 0)) &&
       ((iVar2 = FUN_1a9e_4d00(0x52), iVar2 == 0 &&
        ((iVar2 = FUN_1a9e_4d00(0x4e), iVar2 == 0 && (iVar2 = FUN_1a9e_4d00(0x4c), iVar2 == 0))))))
    {
      bVar6 = false;
    }
    else {
      bVar6 = true;
    }
    if ((((DAT_53bd_0052 & 1) == 0) || (!bVar6)) || (DAT_5b41_1ae2 != 0 || DAT_5b41_1ae4 != 0)) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
    uVar5 = FUN_406b_158a(0,uVar3 | uVar4);
    if ((int)uVar5 < 2) {
      uVar5 = DAT_53bd_004e & 0xfff7;
    }
    DAT_53bd_004e = uVar5 & 0xfffe | uVar3 | uVar4;
    if ((DAT_554c_5594 == '\0') || (iVar2 = FUN_1a9e_5a82(1), iVar2 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    uVar4 = FUN_406b_158a(1,uVar3);
    if ((int)uVar4 < 2) {
      uVar4 = DAT_53bd_0050 & 0xfff7;
    }
    DAT_53bd_0050 = uVar4 & 0xfffe | uVar3;
  }
  DAT_5b41_1b6a = DAT_5b41_1b6a + -1;
  return;
}

