// TIM2.EXE: FUN_1000_6ef8 @ file 0x01C0F8 Ghidra 0x16EF8
// Subsystem: utility | Size: 1140 bytes


/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

undefined2 __cdecl16far FUN_1000_6ef8(void)

{
  uint uVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined2 *puVar4;
  undefined4 in_EBX;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined1 *in_ESP;
  undefined2 uVar13;
  undefined1 *puVar12;
  int iVar14;
  undefined4 in_EBP;
  undefined4 uVar15;
  undefined2 *puVar16;
  undefined4 in_ESI;
  undefined4 in_EDI;
  undefined2 unaff_ES;
  undefined2 uVar17;
  undefined2 unaff_SS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar18;
  byte bVar19;
  byte in_AF;
  byte bVar20;
  byte bVar21;
  byte in_TF;
  byte in_IF;
  byte bVar22;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  
  puVar5 = (undefined1 *)in_ESP;
  uVar13 = (undefined2)((ulong)in_ESP >> 0x10);
  *(undefined2 *)(puVar5 + -2) = in_AX;
  *(int *)(puVar5 + -4) = (int)in_ECX;
  *(int *)(puVar5 + -6) = (int)in_EDX;
  *(int *)(puVar5 + -8) = (int)in_EBX;
  *(int *)((int)puVar5 + -10) = (int)puVar5 + -8;
  *(int *)(puVar5 + -0xc) = (int)in_EBP;
  *(int *)(puVar5 + -0xe) = (int)in_ESI;
  *(int *)(puVar5 + -0x10) = (int)in_EDI;
  *(undefined2 *)(puVar5 + -0x12) = 0x554c;
  *(undefined2 *)(puVar5 + -0x14) = unaff_ES;
  uVar15 = CONCAT22((int)((ulong)in_EBP >> 0x10),(int)puVar5 + -0x14);
  bVar18 = puVar5 + -0x14 < (undefined1 *)0x186;
  bVar22 = SBORROW2((int)puVar5 + -0x14,0x186);
  bVar21 = (int)puVar5 + -0x19a < 0;
  bVar20 = puVar5 == (undefined1 *)0x19a;
  bVar19 = (POPCOUNT((int)puVar5 - 0x19aU & 0xff) & 1U) == 0;
  *(int *)(puVar5 + -0x19c) = (int)puVar5 + -0x9a;
  *(undefined2 *)(puVar5 + -0x19e) = 0x1000;
  puVar6 = puVar5 + -0x1a0;
  *(undefined2 *)(puVar5 + -0x1a0) = 0x6f11;
  FUN_1000_6ef3();
  uVar2 = *(undefined2 *)(puVar6 + 4);
  *(uint *)(puVar6 + 4) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar22 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar21 & 1) * 0x80 | (uint)(bVar20 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar19 & 1) * 4 | (uint)(bVar18 & 1);
  uVar17 = *(undefined2 *)(puVar6 + 4);
  puVar12 = (undefined1 *)CONCAT22(uVar13,puVar6 + 6);
  iVar3 = (int)uVar15;
  *(undefined2 *)(iVar3 + -8) = uVar17;
  if (DAT_554c_5b4c < 3) {
    *(undefined2 *)(iVar3 + -0x9c) = 0;
    *(undefined2 *)(iVar3 + -0x9e) = 0;
    *(undefined2 *)(iVar3 + -0xa0) = 0;
    *(undefined2 *)(iVar3 + -0xa2) = 0;
    *(undefined2 *)(iVar3 + -0xa4) = 0;
    *(undefined2 *)(iVar3 + -0xa6) = 0;
    *(undefined2 *)(iVar3 + -0xa8) = 0;
    *(undefined2 *)(iVar3 + -0xaa) = 0;
    *(undefined2 *)(iVar3 + -0xac) = 0;
    *(undefined2 *)(iVar3 + -0xae) = 0;
    *(undefined2 *)(iVar3 + -0xb0) = 0;
    *(undefined2 *)(iVar3 + -0xb2) = 0;
    *(undefined2 *)(iVar3 + -0xb4) = 0;
    *(undefined2 *)(iVar3 + -0xb6) = 0;
    uVar2 = *(undefined2 *)(iVar3 + -8);
    *(undefined2 *)(iVar3 + -0x90) = 0;
  }
  else {
    *(ulong *)(puVar6 + 2) = CONCAT22(extraout_var,uVar17);
    *(ulong *)(puVar6 + -2) = CONCAT22((int)((ulong)in_ECX >> 0x10),uVar2);
    *(undefined4 *)(puVar6 + -6) = in_EDX;
    *(undefined4 *)(puVar6 + -10) = in_EBX;
    *(undefined1 **)(puVar6 + -0xe) = puVar12;
    *(undefined4 *)(puVar6 + -0x12) = uVar15;
    *(undefined4 *)(puVar6 + -0x16) = in_ESI;
    *(undefined4 *)(puVar6 + -0x1a) = in_EDI;
    *(undefined1 **)(iVar3 + -10) = puVar6 + -0x1a;
    *(undefined2 *)(puVar6 + -0x1c) = 0x20;
    *(undefined2 *)(puVar6 + -0x1e) = unaff_SS;
    *(undefined2 *)(puVar6 + -0x20) = *(undefined2 *)(iVar3 + -10);
    *(undefined2 *)(puVar6 + -0x22) = unaff_SS;
    *(int *)(puVar6 + -0x24) = iVar3 + -0x186;
    *(undefined2 *)(puVar6 + -0x26) = 0x1000;
    puVar7 = puVar6 + -0x28;
    *(undefined2 *)(puVar6 + -0x28) = 0x6f39;
    FUN_1000_a355();
    uVar15 = *(undefined4 *)(puVar7 + 0x16);
    iVar3 = (int)uVar15;
    uVar2 = *(undefined2 *)(iVar3 + -0x186);
    *(undefined2 *)(iVar3 + -0xb4) = *(undefined2 *)(iVar3 + -0x184);
    *(undefined2 *)(iVar3 + -0xb6) = uVar2;
    uVar2 = *(undefined2 *)(iVar3 + -0x182);
    *(undefined2 *)(iVar3 + -0xb0) = *(undefined2 *)(iVar3 + -0x180);
    *(undefined2 *)(iVar3 + -0xb2) = uVar2;
    uVar2 = *(undefined2 *)(iVar3 + -0x176);
    *(undefined2 *)(iVar3 + -0xac) = *(undefined2 *)(iVar3 + -0x174);
    *(undefined2 *)(iVar3 + -0xae) = uVar2;
    uVar2 = *(undefined2 *)(iVar3 + -0x172);
    *(undefined2 *)(iVar3 + -0xa8) = *(undefined2 *)(iVar3 + -0x170);
    *(undefined2 *)(iVar3 + -0xaa) = uVar2;
    uVar2 = *(undefined2 *)(iVar3 + -0x16e);
    *(undefined2 *)(iVar3 + -0xa4) = *(undefined2 *)(iVar3 + -0x16c);
    *(undefined2 *)(iVar3 + -0xa6) = uVar2;
    uVar2 = *(undefined2 *)(iVar3 + -0x16a);
    *(undefined2 *)(iVar3 + -0xa0) = *(undefined2 *)(iVar3 + -0x168);
    *(undefined2 *)(iVar3 + -0xa2) = uVar2;
    uVar2 = *(undefined2 *)(iVar3 + -0x17e);
    *(undefined2 *)(iVar3 + -0x9c) = *(undefined2 *)(iVar3 + -0x17c);
    *(undefined2 *)(iVar3 + -0x9e) = uVar2;
    *(ulong *)(puVar7 + 0x2a) =
         (ulong)(in_NT & 1) * 0x4000 | (ulong)SCARRY2((int)(puVar7 + 4),10) * 0x800 |
         (ulong)(in_IF & 1) * 0x200 | (ulong)(in_TF & 1) * 0x100 |
         (ulong)((int)(puVar7 + 0xe) < 0) * 0x80 | (ulong)(puVar7 == (undefined1 *)0xfff2) * 0x40 |
         (ulong)(in_AF & 1) * 0x10 | (ulong)((POPCOUNT((uint)(puVar7 + 0xe) & 0xff) & 1U) == 0) * 4
         | (ulong)((undefined1 *)0xfff5 < puVar7 + 4) | (ulong)(in_ID & 1) * 0x200000 |
         (ulong)(in_VIP & 1) * 0x100000 | (ulong)(in_VIF & 1) * 0x80000 |
         (ulong)(in_AC & 1) * 0x40000;
    puVar12 = (undefined1 *)ZEXT24(puVar7 + 0x2e);
    *(undefined2 *)(iVar3 + -0x90) = (int)((ulong)*(undefined4 *)(puVar7 + 0x2a) >> 0x10);
    uVar2 = *(undefined2 *)(iVar3 + -8);
  }
  iVar3 = (int)uVar15;
  *(undefined2 *)(iVar3 + -0x92) = uVar2;
  uVar1 = *(uint *)(iVar3 + -0x9e);
  *(int *)(iVar3 + -0x8c) = *(int *)(iVar3 + -0x9c) + (uint)(0xffe7 < uVar1);
  *(int *)(iVar3 + -0x8e) = uVar1 + 0x18;
  if ((*(int *)(iVar3 + 0x1a) == 0xeef) && (*(int *)(iVar3 + 0x18) == -0x532)) {
    uVar17 = (undefined2)((ulong)*(undefined4 *)(iVar3 + 0x24) >> 0x10);
    iVar14 = (int)*(undefined4 *)(iVar3 + 0x24);
    uVar2 = *(undefined2 *)(iVar14 + 6);
    uVar17 = *(undefined2 *)(iVar14 + 4);
  }
  else {
    *(int *)(iVar3 + -10) = iVar3;
    uVar2 = *(undefined2 *)(*(int *)(iVar3 + -10) + 0x16);
    uVar17 = *(undefined2 *)(*(int *)(iVar3 + -10) + 0x14);
  }
  *(undefined2 *)(iVar3 + -4) = uVar2;
  *(undefined2 *)(iVar3 + -6) = uVar17;
  uVar2 = *(undefined2 *)(iVar3 + -6);
  *(undefined2 *)(iVar3 + -0x98) = 0;
  *(undefined2 *)(iVar3 + -0x9a) = uVar2;
  uVar2 = *(undefined2 *)(iVar3 + -4);
  *(undefined2 *)(iVar3 + -0x94) = 0;
  *(undefined2 *)(iVar3 + -0x96) = uVar2;
  puVar8 = (undefined1 *)puVar12;
  *(undefined2 *)(puVar8 + -2) = 0x14;
  *(undefined2 *)(puVar8 + -4) = unaff_SS;
  *(int *)(puVar8 + -6) = iVar3;
  *(undefined2 *)(puVar8 + -8) = unaff_SS;
  *(int *)(puVar8 + -10) = iVar3 + -0x166;
  *(undefined2 *)(puVar8 + -0xc) = 0x1000;
  puVar9 = puVar8 + -0xe;
  *(undefined2 *)(puVar8 + -0xe) = 0x7076;
  FUN_1000_a355();
  puVar10 = (undefined2 *)(puVar9 + 0xe);
  iVar3 = (int)uVar15;
  uVar2 = *(undefined2 *)(iVar3 + -0x164);
  *(undefined2 *)(iVar3 + -0xb8) = 0;
  *(undefined2 *)(iVar3 + -0xba) = uVar2;
  uVar2 = *(undefined2 *)(iVar3 + -0x166);
  *(undefined2 *)(iVar3 + -0xbc) = 0;
  *(undefined2 *)(iVar3 + -0xbe) = uVar2;
  *(undefined2 *)(iVar3 + -0xc0) = 0;
  *(undefined2 *)(iVar3 + -0xc2) = in_FS;
  *(undefined2 *)(iVar3 + -0xc4) = 0;
  *(undefined2 *)(iVar3 + -0xc6) = in_GS;
  *(undefined2 *)(iVar3 + -0x88) = 0;
  *(undefined2 *)(iVar3 + -0x8a) = unaff_SS;
  *(undefined2 *)(iVar3 + -0xa2) = *(undefined2 *)(iVar3 + -0x154);
  *(undefined2 *)(iVar3 + -0xae) = *(undefined2 *)(iVar3 + -0x15a);
  *(undefined2 *)(iVar3 + -0xa6) = *(undefined2 *)(iVar3 + -0x156);
  *(undefined2 *)(iVar3 + -0xaa) = *(undefined2 *)(iVar3 + -0x158);
  *(undefined2 *)(iVar3 + -0xb2) = *(undefined2 *)(iVar3 + -0x160);
  *(undefined2 *)(iVar3 + -0xb6) = *(undefined2 *)(iVar3 + -0x162);
  *(undefined2 *)(iVar3 + -0x9e) = *(undefined2 *)(iVar3 + -0x15e);
  uVar2 = *(undefined2 *)(iVar3 + 0x18);
  *(uint *)(iVar3 + -0x54) = *(uint *)(iVar3 + 0x1a) & 0xefff;
  *(undefined2 *)(iVar3 + -0x56) = uVar2;
  uVar2 = *(undefined2 *)(iVar3 + 0x1c);
  *(undefined2 *)(iVar3 + -0x50) = *(undefined2 *)(iVar3 + 0x1e);
  *(undefined2 *)(iVar3 + -0x52) = uVar2;
  uVar2 = *(undefined2 *)(iVar3 + -6);
  *(undefined2 *)(iVar3 + -0x4a) = *(undefined2 *)(iVar3 + -4);
  *(undefined2 *)(iVar3 + -0x4c) = uVar2;
  *(undefined2 *)(iVar3 + -0x4e) = 0;
  if (*(int *)(iVar3 + 0x24) == 0 && *(int *)(iVar3 + 0x26) == 0) {
    *(undefined2 *)(iVar3 + 0x22) = 0;
    *(undefined2 *)(iVar3 + 0x20) = 0;
  }
  if ((*(int *)(iVar3 + 0x22) != 0) || (0xf < *(uint *)(iVar3 + 0x20))) {
    *(undefined2 *)(iVar3 + 0x22) = 0;
    *(undefined2 *)(iVar3 + 0x20) = 0xf;
  }
  *(undefined2 *)(iVar3 + -0x48) = *(undefined2 *)(iVar3 + 0x20);
  *(undefined2 *)(iVar3 + -2) = 0;
  while ((*(int *)(iVar3 + 0x22) != 0 || (*(uint *)(iVar3 + -2) < *(uint *)(iVar3 + 0x20)))) {
    puVar4 = (undefined2 *)(*(int *)(iVar3 + -2) * 4 + iVar3 + -0x46);
    uVar17 = (undefined2)((ulong)*(undefined4 *)(iVar3 + 0x24) >> 0x10);
    puVar16 = (undefined2 *)((int)*(undefined4 *)(iVar3 + 0x24) + *(int *)(iVar3 + -2) * 4);
    uVar2 = *puVar16;
    puVar4[1] = puVar16[1];
    *puVar4 = uVar2;
    *(int *)(iVar3 + -2) = *(int *)(iVar3 + -2) + 1;
  }
  while( true ) {
    *(undefined2 *)((int)puVar10 + -2) = 0xffff;
    *(undefined2 *)((int)puVar10 + -4) = unaff_SS;
    *(int *)((int)puVar10 + -6) = (int)uVar15 + -0x152;
    *(int *)((int)puVar10 + -8) = (int)uVar15 + -0x56;
    *(undefined2 *)((int)puVar10 + -10) = 0x1000;
    puVar11 = (undefined2 *)((int)puVar10 + -0xc);
    *(undefined2 *)((int)puVar10 + -0xc) = 0x719b;
    iVar3 = FUN_1000_6e27();
    puVar10 = puVar11 + 6;
    iVar14 = (int)uVar15;
    if (iVar3 != 0) break;
    if ((*(byte *)(iVar14 + 0x1c) & 1) == 0) goto LAB_1000_71f4;
    *(undefined2 *)(iVar14 + -0x54) = 0xc000;
    *(undefined2 *)(iVar14 + -0x56) = 0x25;
    uVar2 = *(undefined2 *)(iVar14 + 0x1c);
    *(undefined2 *)(iVar14 + -0x50) = *(undefined2 *)(iVar14 + 0x1e);
    *(undefined2 *)(iVar14 + -0x52) = uVar2;
    *(undefined2 *)(iVar14 + -0x4a) = 0;
    *(undefined2 *)(iVar14 + -0x4c) = 0;
    *(undefined2 *)(iVar14 + -0x4e) = 0;
    *(undefined2 *)(iVar14 + -0x48) = 0;
  }
  *(uint *)(iVar14 + -0x52) = *(uint *)(iVar14 + -0x52) | 2;
  puVar11[5] = 0xffff;
  puVar11[4] = unaff_SS;
  puVar11[3] = iVar14 + -0x152;
  puVar11[2] = iVar14 + -0x56;
  puVar11[1] = 0x1000;
  *puVar11 = 0x71ea;
  iVar3 = FUN_1000_6e27();
  if (iVar3 != 0) {
    *(undefined2 *)((int)puVar11 + 10) = 0x1000;
    *(undefined2 *)((int)puVar11 + 8) = 0x736c;
    FUN_1000_287e();
    return *(undefined2 *)(iVar14 + 0x12);
  }
LAB_1000_71f4:
  if (DAT_554c_5b4c < 3) {
    iVar3 = *(int *)(iVar14 + -0x8e);
    uVar2 = *(undefined2 *)(iVar14 + -0x8a);
    *(undefined2 *)(iVar3 + -0x1a) = *(undefined2 *)(iVar14 + -0xbe);
    *(undefined2 *)(iVar3 + -0x18) = *(undefined2 *)(iVar14 + -0xba);
    *(undefined2 *)(iVar3 + -0x16) = *(undefined2 *)(iVar14 + -0xb6);
    *(undefined2 *)(iVar3 + -0x14) = *(undefined2 *)(iVar14 + -0xb2);
    *(undefined2 *)(iVar3 + -0x12) = *(undefined2 *)(iVar14 + -0x9e);
    *(undefined2 *)(iVar3 + -0x10) = *(undefined2 *)(iVar14 + -0x8e);
    *(undefined2 *)(iVar3 + -0xe) = *(undefined2 *)(iVar14 + -0xae);
    *(undefined2 *)(iVar3 + -0xc) = *(undefined2 *)(iVar14 + -0xaa);
    *(undefined2 *)(iVar3 + -10) = *(undefined2 *)(iVar14 + -0xa6);
    *(undefined2 *)(iVar3 + -8) = *(undefined2 *)(iVar14 + -0xa2);
    *(undefined2 *)(iVar3 + -6) = *(undefined2 *)(iVar14 + -0x92);
    *(undefined2 *)(iVar3 + -4) = *(undefined2 *)(iVar14 + -0x9a);
    *(undefined2 *)(iVar3 + -2) = *(undefined2 *)(iVar14 + -0x96);
    return *(undefined2 *)(iVar3 + -8);
  }
  iVar3 = *(int *)(iVar14 + -0x8e);
  uVar2 = *(undefined2 *)(iVar14 + -0x8a);
  *(undefined2 *)(iVar3 + -0x30) = *(undefined2 *)(iVar14 + -0xc6);
  *(undefined2 *)(iVar3 + -0x2e) = *(undefined2 *)(iVar14 + -0xc2);
  *(undefined2 *)(iVar3 + -0x2c) = *(undefined2 *)(iVar14 + -0xbe);
  *(undefined2 *)(iVar3 + -0x2a) = *(undefined2 *)(iVar14 + -0xba);
  uVar17 = *(undefined2 *)(iVar14 + -0xb6);
  *(undefined2 *)(iVar3 + -0x26) = *(undefined2 *)(iVar14 + -0xb4);
  *(undefined2 *)(iVar3 + -0x28) = uVar17;
  uVar17 = *(undefined2 *)(iVar14 + -0xb2);
  *(undefined2 *)(iVar3 + -0x22) = *(undefined2 *)(iVar14 + -0xb0);
  *(undefined2 *)(iVar3 + -0x24) = uVar17;
  uVar17 = *(undefined2 *)(iVar14 + -0x9e);
  *(undefined2 *)(iVar3 + -0x1e) = *(undefined2 *)(iVar14 + -0x9c);
  *(undefined2 *)(iVar3 + -0x20) = uVar17;
  uVar17 = *(undefined2 *)(iVar14 + -0x8e);
  *(undefined2 *)(iVar3 + -0x1a) = *(undefined2 *)(iVar14 + -0x8c);
  *(undefined2 *)(iVar3 + -0x1c) = uVar17;
  uVar17 = *(undefined2 *)(iVar14 + -0xae);
  *(undefined2 *)(iVar3 + -0x16) = *(undefined2 *)(iVar14 + -0xac);
  *(undefined2 *)(iVar3 + -0x18) = uVar17;
  uVar17 = *(undefined2 *)(iVar14 + -0xaa);
  *(undefined2 *)(iVar3 + -0x12) = *(undefined2 *)(iVar14 + -0xa8);
  *(undefined2 *)(iVar3 + -0x14) = uVar17;
  uVar17 = *(undefined2 *)(iVar14 + -0xa6);
  *(undefined2 *)(iVar3 + -0xe) = *(undefined2 *)(iVar14 + -0xa4);
  *(undefined2 *)(iVar3 + -0x10) = uVar17;
  uVar17 = *(undefined2 *)(iVar14 + -0xa2);
  *(undefined2 *)(iVar3 + -10) = *(undefined2 *)(iVar14 + -0xa0);
  *(undefined2 *)(iVar3 + -0xc) = uVar17;
  uVar17 = *(undefined2 *)(iVar14 + -0x92);
  *(undefined2 *)(iVar3 + -6) = *(undefined2 *)(iVar14 + -0x90);
  *(undefined2 *)(iVar3 + -8) = uVar17;
  *(undefined2 *)(iVar3 + -4) = *(undefined2 *)(iVar14 + -0x9a);
  *(undefined2 *)(iVar3 + -2) = *(undefined2 *)(iVar14 + -0x96);
  return (int)*(undefined4 *)(iVar3 + -0xc);
}

