// TIM2.EXE: FUN_4a54_119f @ file 0x0508DF Ghidra 0x4B6DF
// Subsystem: misc | Size: 756 bytes


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __cdecl16near FUN_4a54_119f(uint param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined2 unaff_SS;
  undefined1 local_10c [256];
  int local_c;
  uint local_a;
  int local_8;
  uint local_6;
  uint local_4;
  
  puVar6 = DAT_5b41_2858;
  if ((param_4 == 0) || (param_3 == 0)) {
    return;
  }
  if ((param_3 == 1) && (param_4 == 1)) {
    uVar10 = *DAT_5b41_2858;
    uVar3 = DAT_5b41_2858[1];
    *DAT_5b41_2858 = uVar10 + 8;
    puVar6[1] = uVar3 + (0xfff7 < uVar10);
    uVar10 = CONCAT11((char)(*(uint *)(puVar6[2] +
                                      (((uVar10 >> 1 | (uint)((uVar3 & 1) != 0) << 0xf) >> 1 |
                                       (uint)((uVar3 >> 1 & 1) != 0) << 0xf) >> 1 |
                                      (uint)((uVar3 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar10 & 7)),
                      (char)param_1) & 0xff03;
    out(0x3c4,CONCAT11('\x01' << (sbyte)uVar10,2));
    *(undefined1 *)(*(int *)(param_2 * 2 + 0x49b2) + (param_1 >> 2)) = (char)(uVar10 >> 8);
    return;
  }
  local_8 = (param_3 & 0xff) * (param_4 & 0xff);
  uVar10 = 8;
  if ((char)((uint)local_8 >> 8) == '\0') {
    uVar10 = 0;
    bVar8 = (char)local_8 - 1;
    do {
      uVar10 = uVar10 + 1;
      bVar8 = bVar8 >> 1;
    } while (bVar8 != 0);
  }
  bVar8 = (byte)uVar10 & 0xf;
  uVar4 = *DAT_5b41_2858;
  uVar5 = DAT_5b41_2858[1];
  puVar1 = DAT_5b41_2858;
  uVar3 = *puVar1;
  *puVar1 = *puVar1 + uVar10;
  puVar6[1] = puVar6[1] + (uint)CARRY2(uVar3,uVar10);
  puVar7 = DAT_5b41_2858;
  uVar10 = *(uint *)(puVar6[2] +
                    (((uVar4 >> 1 | (uint)((uVar5 & 1) != 0) << 0xf) >> 1 |
                     (uint)((uVar5 >> 1 & 1) != 0) << 0xf) >> 1 |
                    (uint)((uVar5 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar4 & 7) &
           (uint)(byte)((byte)(-0x100 << bVar8) | (byte)(0xff00 >> 0x10 - bVar8));
  local_4 = 0;
  bVar8 = (byte)uVar10;
  bVar9 = bVar8;
  while (bVar9 != 0) {
    local_4 = local_4 + 1;
    bVar9 = (byte)uVar10 >> 1;
    uVar10 = (uint)bVar9;
  }
  local_a = param_1 + param_3;
  local_c = param_2 + param_4;
  bVar8 = bVar8 + 1;
  local_6 = (uint)bVar8;
  uVar10 = local_8 * local_4 + local_6 * 8;
  iVar11 = param_2;
  if ((uint)(local_8 * 8) < uVar10 || local_8 * 8 - uVar10 == 0) {
    do {
      do {
        puVar6 = DAT_5b41_2858;
        uVar10 = *DAT_5b41_2858;
        uVar3 = DAT_5b41_2858[1];
        *DAT_5b41_2858 = uVar10 + 8;
        puVar6[1] = uVar3 + (0xfff7 < uVar10);
        uVar10 = CONCAT11((char)(*(uint *)(puVar6[2] +
                                          (((uVar10 >> 1 | (uint)((uVar3 & 1) != 0) << 0xf) >> 1 |
                                           (uint)((uVar3 >> 1 & 1) != 0) << 0xf) >> 1 |
                                          (uint)((uVar3 >> 2 & 1) != 0) << 0xf)) >>
                                ((byte)uVar10 & 7)),(char)param_1) & 0xff03;
        out(0x3c4,CONCAT11('\x01' << (sbyte)uVar10,2));
        *(undefined1 *)(*(int *)(iVar11 * 2 + 0x49b2) + (param_1 >> 2)) = (char)(uVar10 >> 8);
        iVar11 = iVar11 + 1;
      } while (iVar11 < local_c);
      param_1 = param_1 + 1;
      iVar11 = param_2;
    } while ((int)param_1 < (int)local_a);
    return;
  }
  if (bVar8 == 1) {
    uVar10 = *DAT_5b41_2858;
    uVar3 = DAT_5b41_2858[1];
    *DAT_5b41_2858 = uVar10 + 8;
    puVar7[1] = uVar3 + (0xfff7 < uVar10);
    iVar11 = *(int *)(param_2 * 2 + 0x49b2);
    do {
      (*DAT_554c_4d9e)(0x4a54,iVar11);
      iVar11 = iVar11 + 0x50;
      param_4 = param_4 - 1;
    } while (param_4 != 0);
    return;
  }
  puVar12 = local_10c;
  do {
    puVar6 = DAT_5b41_2858;
    uVar10 = *DAT_5b41_2858;
    uVar3 = DAT_5b41_2858[1];
    *DAT_5b41_2858 = uVar10 + 8;
    puVar6[1] = uVar3 + (0xfff7 < uVar10);
    puVar2 = puVar12;
    puVar12 = puVar12 + 1;
    *puVar2 = (char)(*(uint *)(puVar6[2] +
                              (((uVar10 >> 1 | (uint)((uVar3 & 1) != 0) << 0xf) >> 1 |
                               (uint)((uVar3 >> 1 & 1) != 0) << 0xf) >> 1 |
                              (uint)((uVar3 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar10 & 7));
    bVar8 = (char)local_6 - 1;
    local_6 = (uint)bVar8;
  } while (bVar8 != 0);
  do {
    do {
      puVar6 = DAT_5b41_2858;
      bVar8 = (byte)local_4 & 0xf;
      uVar3 = *DAT_5b41_2858;
      uVar4 = DAT_5b41_2858[1];
      puVar1 = DAT_5b41_2858;
      uVar10 = *puVar1;
      *puVar1 = *puVar1 + local_4;
      puVar6[1] = puVar6[1] + (uint)CARRY2(uVar10,local_4);
      uVar10 = CONCAT11(local_10c[*(uint *)(puVar6[2] +
                                           (((uVar3 >> 1 | (uint)((uVar4 & 1) != 0) << 0xf) >> 1 |
                                            (uint)((uVar4 >> 1 & 1) != 0) << 0xf) >> 1 |
                                           (uint)((uVar4 >> 2 & 1) != 0) << 0xf)) >>
                                  ((byte)uVar3 & 7) &
                                  (uint)(byte)((byte)(-0x100 << bVar8) |
                                              (byte)(0xff00 >> 0x10 - bVar8))],(char)param_1) &
               0xff03;
      out(0x3c4,CONCAT11('\x01' << (sbyte)uVar10,2));
      *(undefined1 *)(*(int *)(iVar11 * 2 + 0x49b2) + (param_1 >> 2)) = (char)(uVar10 >> 8);
      iVar11 = iVar11 + 1;
    } while (iVar11 < local_c);
    param_1 = param_1 + 1;
    iVar11 = param_2;
  } while (param_1 < local_a);
  return;
}

