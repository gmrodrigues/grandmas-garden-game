// TIM2.EXE: FUN_2321_00ff @ file 0x02850F Ghidra 0x2330F
// Subsystem: misc | Size: 635 bytes


void __cdecl16far FUN_2321_00ff(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int *piVar5;
  undefined2 in_DX;
  undefined2 uVar6;
  
  DAT_0000_0417 = DAT_0000_0417 & 0x8f;
  FUN_1000_02a3();
  FUN_3f2b_0000(0x280,10,0x280,0,0);
  FUN_4340_0006(10,4);
  FUN_460e_0006(5,800,0);
  FUN_2e67_0007();
  FUN_2321_0b53(0x96);
  iVar1 = FUN_1a9e_5dc8(0xd,0x80,0x1fd);
  if (iVar1 == 0) {
    FUN_3f2b_0f46(0);
    FUN_1000_17bf(0);
  }
  DAT_5b41_0527 = FUN_1a9e_213d(0x204);
  DAT_5b41_0529 = in_DX;
  DAT_5b41_052b = FUN_1a9e_213d(0x20c);
  DAT_5b41_052d = in_DX;
  DAT_5b41_052f = FUN_1a9e_213d(0x218);
  DAT_5b41_0531 = in_DX;
  FUN_1a9e_2342(DAT_5b41_0527,DAT_5b41_0529);
  FUN_1a9e_48fc(0);
  FUN_1a9e_5cd8();
  FUN_1a9e_3f33(0xd);
  FUN_1a9e_3ec6(0x4db,0x2321,4);
  FUN_4340_0133(50000,0x222);
  for (iVar1 = 0; iVar1 < 0x32; iVar1 = iVar1 + 1) {
    uVar2 = FUN_4340_06ef(iVar1 + -0x3caf);
    uVar3 = FUN_4340_0d94(uVar2,in_DX);
    uVar6 = 0x51a7;
    *(undefined2 *)(iVar1 << 2) = uVar3;
    iVar4 = FUN_4340_0caf(uVar2,in_DX,0x2c);
    uVar2 = FUN_4340_0d94(iVar4 + 1,uVar6);
    in_DX = 0x51a7;
    *(undefined2 *)(iVar1 * 4 + 2) = uVar2;
  }
  FUN_4340_0133(50000,0);
  FUN_406b_0198(1,0);
  FUN_406b_0e04(3);
  FUN_406b_0c62(DAT_554c_49aa / 2,DAT_554c_49ac / 2);
  FUN_406b_02f2(0x22d,0,0x51a7);
  FUN_406b_03cb(1,0xffff);
  FUN_2e67_00fd(DAT_554c_3e62,DAT_554c_3e64,0x239,0x240);
  FUN_2e67_08c9(1);
  DAT_554c_02e8 = FUN_2321_05a9();
  for (iVar1 = 1; iVar1 < 999; iVar1 = iVar1 + 1) {
    FUN_2e67_02b5(0x2e67,iVar1);
  }
  DAT_5b41_0533 = FUN_4340_0849(0x248);
  DAT_5b41_0535 = FUN_4340_0849(0x255);
  DAT_554c_3d4e = 0;
  if (((DAT_554c_3d52 == 0) && (DAT_554c_3d57 != '\0')) && (DAT_554c_3d4e = 1, 8 < DAT_554c_3d54)) {
    DAT_554c_3d4e = 5;
  }
  DAT_5b41_0523 = FUN_3e34_0836(0x25f,DAT_554c_3d4e);
  DAT_5b41_050d = FUN_4551_0002(0x26b);
  FUN_1a3f_0001(0);
  func_0x00054aab(0x1a3f);
  FUN_28eb_4dea();
  FUN_2424_087c(0xb4);
  func_0x00055048(0x2424,0);
  DAT_5b41_096b = 0;
  piVar5 = (int *)FUN_1000_12bf(0x14,10);
  DAT_5b41_0472 = piVar5;
  DAT_5b41_096d = piVar5;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar5 = (int)(piVar5 + 5);
    piVar5 = piVar5 + 5;
  }
  return;
}

