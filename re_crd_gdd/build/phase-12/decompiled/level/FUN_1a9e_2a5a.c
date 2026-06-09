// TIM2.EXE: FUN_1a9e_2a5a @ file 0x02263A Ghidra 0x1D43A
// Subsystem: level | Size: 318 bytes


void __cdecl16near FUN_1a9e_2a5a(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_CX;
  int in_BX;
  int iVar4;
  int unaff_BP;
  uint uVar5;
  int unaff_SI;
  uint uVar6;
  int *piVar7;
  undefined2 unaff_ES;
  
  iVar2 = in_CX;
  iVar3 = in_BX;
  if (unaff_BP <= in_BX) {
    iVar2 = unaff_SI;
    iVar3 = unaff_BP;
    unaff_BP = in_BX;
    unaff_SI = in_CX;
  }
  piVar7 = (int *)(iVar2 * 4 + DAT_554c_4f10);
  uVar1 = iVar2 - unaff_SI;
  iVar2 = (uVar1 ^ (int)uVar1 >> 0xf) - ((int)uVar1 >> 0xf);
  uVar6 = (unaff_BP - iVar3) * 2;
  iVar4 = uVar6 - iVar2;
  uVar5 = ((unaff_BP - iVar3) - iVar2) * 2 ^ uVar6;
  iVar2 = iVar2 + 1;
  if (-1 < (int)uVar1) {
    while( true ) {
      *piVar7 = iVar3;
      uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
      iVar3 = iVar3 + uVar1;
      iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
      if (iVar2 == 1) {
        return;
      }
      piVar7[-2] = iVar3;
      uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
      iVar3 = iVar3 + uVar1;
      iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
      if (iVar2 == 2) {
        return;
      }
      piVar7[-4] = iVar3;
      uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
      iVar3 = iVar3 + uVar1;
      iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
      if (iVar2 == 3) {
        return;
      }
      piVar7[-6] = iVar3;
      uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
      iVar3 = iVar3 + uVar1;
      iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
      if (iVar2 == 4) break;
      piVar7[-8] = iVar3;
      uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
      iVar3 = iVar3 + uVar1;
      iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
      if (iVar2 == 5) {
        return;
      }
      piVar7[-10] = iVar3;
      uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
      iVar3 = iVar3 + uVar1;
      iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
      if (iVar2 == 6) {
        return;
      }
      piVar7[-0xc] = iVar3;
      piVar7 = piVar7 + -0xe;
      uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
      iVar3 = iVar3 + uVar1;
      iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
      iVar2 = iVar2 + -7;
      if (iVar2 == 0) {
        return;
      }
    }
    return;
  }
  while( true ) {
    *piVar7 = iVar3;
    uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
    iVar3 = iVar3 + uVar1;
    iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
    if (iVar2 == 1) {
      return;
    }
    piVar7[2] = iVar3;
    uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
    iVar3 = iVar3 + uVar1;
    iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
    if (iVar2 == 2) {
      return;
    }
    piVar7[4] = iVar3;
    uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
    iVar3 = iVar3 + uVar1;
    iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
    if (iVar2 == 3) {
      return;
    }
    piVar7[6] = iVar3;
    uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
    iVar3 = iVar3 + uVar1;
    iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
    if (iVar2 == 4) break;
    piVar7[8] = iVar3;
    uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
    iVar3 = iVar3 + uVar1;
    iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
    if (iVar2 == 5) {
      return;
    }
    piVar7[10] = iVar3;
    piVar7 = piVar7 + 0xc;
    uVar1 = (uint)((byte)((uint)iVar4 >> 8) < 0x80);
    iVar3 = iVar3 + uVar1;
    iVar4 = iVar4 + (-uVar1 & uVar5 ^ uVar6);
    iVar2 = iVar2 + -6;
    if (iVar2 == 0) {
      return;
    }
  }
  return;
}

