// TIM2.EXE: FUN_2fc8_01f3 @ file 0x035073 Ghidra 0x2FE73
// Subsystem: misc | Size: 260 bytes


/* WARNING: Instruction at (ram,0x0002ff71) overlaps instruction at (ram,0x0002ff6d)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2fc8_01f3(int param_1)

{
  uint *puVar1;
  undefined1 uVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  byte in_AL;
  byte bVar6;
  undefined2 uVar7;
  undefined2 in_DX;
  undefined1 *in_BX;
  undefined2 *puVar8;
  int unaff_BP;
  undefined2 *puVar9;
  undefined2 *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  byte in_AF;
  byte in_stack_00000001;
  undefined1 uStack0004;
  
  uVar2 = in(in_DX);
  *unaff_DI = uVar2;
  puVar1 = (uint *)(unaff_BP + (int)unaff_SI);
  *puVar1 = *puVar1 + (uint)(in_stack_00000001 < (byte)unaff_DI[0x3c]) *
                      (((uint)(unaff_DI + 2) & 3) - (*puVar1 & 3));
  uVar7 = in(in_DX);
  *(undefined2 *)(unaff_DI + 2) = uVar7;
  uStack0004 = (undefined1)((uint)(unaff_DI + 4) >> 8);
  puVar9 = (undefined2 *)(unaff_BP + -1);
  uVar7 = in(in_DX);
  bVar4 = 9 < ((byte)uVar7 & 0xf) | 9 < ((in_AL ^ 0x38) & 0xf) | in_AF;
  if (param_1 + 1 == 1 || (char)(param_1 + 1) == (char)((uint)in_BX >> 8)) {
    bVar6 = ((byte)uVar7 + bVar4 * '\x06' & 0xf) % 0x37;
    puVar8 = (undefined2 *)&stack0x0001;
    cVar5 = '\x16';
    do {
      puVar9 = puVar9 + -1;
      puVar8 = puVar8 + -1;
      *puVar8 = *puVar9;
      cVar5 = cVar5 + -1;
    } while ('\0' < cVar5);
    iVar3 = *(int *)(unaff_DI + 4);
    bVar4 = 9 < (bVar6 & 0xf) | bVar4;
    _DAT_5000_eaf7 = CONCAT11(bVar4,bVar6 + bVar4 * '\x06') & 0xff0f;
    uVar2 = *in_BX;
    if (((int)(uint)bVar6 < iVar3) && (SBORROW2((uint)bVar6,iVar3))) {
      *(uint *)(in_BX + -1) = *(uint *)(in_BX + -1) ^ (uint)unaff_SI;
      DAT_554c_36f1 = DAT_554c_36f1 + '\x01';
      puVar9 = (undefined2 *)in(0x36);
      unaff_DI[6] = *(undefined1 *)0xb136;
      *(undefined2 *)0x367c = puVar9;
      out(*puVar9,CONCAT11(uVar2,(char)in_DX));
    }
  }
  else {
    out(*unaff_SI,in_DX);
  }
  FUN_28eb_4cfc();
  return;
}

