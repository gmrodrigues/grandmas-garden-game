// TIM2.EXE: FUN_1a9e_5dc8 @ file 0x0259A8 Ghidra 0x207A8
// Subsystem: level | Size: 308 bytes


/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint __cdecl16far FUN_1a9e_5dc8(undefined1 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  code *pcVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined2 extraout_DX;
  int extraout_DX_00;
  undefined2 *unaff_SI;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined4 uVar9;
  
  DAT_554c_559f = param_1;
  DAT_554c_49a8 = 0;
  DAT_554c_42df = 0;
  DAT_554c_49aa = 0x140;
  DAT_554c_49ac = 200;
  if (DAT_554c_445e != 0 || DAT_554c_4460 != 0) {
    func_0x0002fdf5(0x1a9e,DAT_554c_445e,DAT_554c_4460);
    DAT_554c_445e = 0;
    DAT_554c_4460 = 0;
  }
  DAT_554c_559e = FUN_1a9e_60c4();
  uVar9 = FUN_1a9e_5f2a();
  iVar6 = (int)((ulong)uVar9 >> 0x10);
  DAT_554c_42dd = (byte)uVar9;
  if (((int)uVar9 == 0) || (pcVar4 = (code *)FUN_1a9e_7325((int)uVar9,param_3), iVar6 == 0)) {
    DAT_554c_42dd = 0;
  }
  else {
    DAT_554c_55a0 = pcVar4;
    DAT_554c_55a2 = iVar6;
    (*pcVar4)(0x1a9e,(undefined1 *)&DAT_554c_42c0,0x4e42,0x554c);
    puVar7 = (undefined2 *)&DAT_554c_4d76;
    for (iVar6 = 100; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = unaff_SI;
      unaff_SI = unaff_SI + 1;
      *puVar2 = *puVar1;
    }
    puVar7 = (undefined2 *)&DAT_554c_4d76;
    iVar6 = 0x32;
    do {
      puVar8 = puVar7 + 1;
      puVar7 = puVar7 + 2;
      *puVar8 = extraout_DX;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  uRam000004f0 = 0x554c;
  DAT_554c_42d6 = DAT_554c_42d4;
  DAT_554c_42d8 = DAT_554c_42d2;
  DAT_554c_42ca = DAT_554c_49ac + -1;
  DAT_554c_42c6 = DAT_554c_49aa + -1;
  uVar5 = (uint)DAT_554c_42dd;
  if (uVar5 != 0) {
    if (DAT_554c_4d74 != 0) {
      func_0x0002fdf5(0x1a9e,0,DAT_554c_4d74 + -1);
    }
    FUN_2fc8_00fc(0x1a9e,DAT_554c_49ac * 4 + 0x20,0,0,0);
    if (extraout_DX_00 != 0) {
      DAT_554c_4d74 = extraout_DX_00 + 1;
      pcVar3 = (code *)swi(0x10);
      (*pcVar3)();
      DAT_5b41_25d8 = 0;
      DAT_5b41_25dc = 0;
      DAT_554c_4308 = 0x808;
      DAT_554c_42f4 = 0x808;
      DAT_554c_431c = 0;
      DAT_554c_4330 = 0xffff;
      DAT_5b41_25d6 = &stack0xfffe;
      DAT_5b41_25da = &stack0xfffe;
    }
  }
  return uVar5;
}

