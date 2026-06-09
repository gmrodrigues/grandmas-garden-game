// TIM2.EXE: FUN_49fc_0518 @ file 0x04F6D8 Ghidra 0x4A4D8
// Subsystem: misc | Size: 109 bytes


undefined2 __cdecl16far FUN_49fc_0518(uint param_1)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  byte extraout_DH;
  byte bVar4;
  int iVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  
  uVar6 = 0;
  uVar7 = param_1 == 0;
  if ((param_1 == 1) || (uVar7 = param_1 < 2, param_1 == 2)) {
    pcVar1 = (code *)swi(0x21);
    bVar2 = (*pcVar1)();
    if ((bool)uVar7) {
      return 0;
    }
    bVar4 = (byte)param_1 ^ 3;
    uVar7 = bVar2 < bVar4;
    if (bVar2 == bVar4) {
      return 0;
    }
  }
  pcVar1 = (code *)swi(0x21);
  iVar3 = (*pcVar1)();
  if (!(bool)uVar7) {
    uVar7 = 0;
    if (iVar3 == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 1;
    }
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if ((!(bool)uVar7) && ((extraout_DH & 0x10) != 0)) {
    uVar6 = 4;
  }
  iVar5 = 0;
  pcVar1 = (code *)swi(0x2f);
  iVar3 = (*pcVar1)();
  if ((iVar3 != 0) && (iVar5 == -0x5253)) {
    uVar6 = 8;
  }
  return uVar6;
}

