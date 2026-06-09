// TIM2.EXE: FUN_4a54_15aa @ file 0x050CEA Ghidra 0x4BAEA
// Subsystem: misc | Size: 739 bytes


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __cdecl16near FUN_4a54_15aa(int param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined2 unaff_SS;
  undefined1 local_10c [262];
  uint local_6;
  
  puVar4 = DAT_5b41_2858;
  if ((param_4 == 0) || (param_3 == 0)) {
    return;
  }
  if ((param_3 == 1) && (param_4 == 1)) {
    uVar10 = *DAT_5b41_2858;
    uVar11 = DAT_5b41_2858[1];
    *DAT_5b41_2858 = uVar10 + 8;
    puVar4[1] = uVar11 + (0xfff7 < uVar10);
    *(undefined1 *)
     ((int)*(undefined4 *)(DAT_5b41_2858 + 4) + DAT_5b41_2858[param_2 + 0xc] + param_1) =
         (char)(*(uint *)(puVar4[2] +
                         (((uVar10 >> 1 | (uint)((uVar11 & 1) != 0) << 0xf) >> 1 |
                          (uint)((uVar11 >> 1 & 1) != 0) << 0xf) >> 1 |
                         (uint)((uVar11 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar10 & 7));
    return;
  }
  iVar8 = (param_3 & 0xff) * (param_4 & 0xff);
  uVar10 = 8;
  if ((char)((uint)iVar8 >> 8) == '\0') {
    uVar10 = 0;
    bVar6 = (char)iVar8 - 1;
    do {
      uVar10 = uVar10 + 1;
      bVar6 = bVar6 >> 1;
    } while (bVar6 != 0);
  }
  bVar6 = (byte)uVar10 & 0xf;
  uVar12 = *DAT_5b41_2858;
  uVar3 = DAT_5b41_2858[1];
  puVar1 = DAT_5b41_2858;
  uVar11 = *puVar1;
  *puVar1 = *puVar1 + uVar10;
  puVar4[1] = puVar4[1] + (uint)CARRY2(uVar11,uVar10);
  puVar5 = DAT_5b41_2858;
  uVar10 = *(uint *)(puVar4[2] +
                    (((uVar12 >> 1 | (uint)((uVar3 & 1) != 0) << 0xf) >> 1 |
                     (uint)((uVar3 >> 1 & 1) != 0) << 0xf) >> 1 |
                    (uint)((uVar3 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar12 & 7) &
           (uint)(byte)((byte)(-0x100 << bVar6) | (byte)(0xff00 >> 0x10 - bVar6));
  uVar11 = 0;
  bVar6 = (byte)uVar10;
  bVar7 = bVar6;
  while (bVar7 != 0) {
    uVar11 = uVar11 + 1;
    bVar7 = (byte)uVar10 >> 1;
    uVar10 = (uint)bVar7;
  }
  iVar9 = param_1 + param_3;
  bVar6 = bVar6 + 1;
  local_6 = (uint)bVar6;
  uVar10 = iVar8 * uVar11 + local_6 * 8;
  iVar13 = param_2;
  if ((uint)(iVar8 * 8) < uVar10 || iVar8 * 8 - uVar10 == 0) {
    do {
      do {
        puVar4 = DAT_5b41_2858;
        uVar10 = *DAT_5b41_2858;
        uVar11 = DAT_5b41_2858[1];
        *DAT_5b41_2858 = uVar10 + 8;
        puVar4[1] = uVar11 + (0xfff7 < uVar10);
        *(undefined1 *)
         ((int)*(undefined4 *)(DAT_5b41_2858 + 4) + DAT_5b41_2858[iVar13 + 0xc] + param_1) =
             (char)(*(uint *)(puVar4[2] +
                             (((uVar10 >> 1 | (uint)((uVar11 & 1) != 0) << 0xf) >> 1 |
                              (uint)((uVar11 >> 1 & 1) != 0) << 0xf) >> 1 |
                             (uint)((uVar11 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar10 & 7));
        iVar13 = iVar13 + 1;
      } while (iVar13 < (int)(param_2 + param_4));
      param_1 = param_1 + 1;
      iVar13 = param_2;
    } while (param_1 < iVar9);
    return;
  }
  if (bVar6 == 1) {
    uVar10 = *DAT_5b41_2858;
    uVar11 = DAT_5b41_2858[1];
    *DAT_5b41_2858 = uVar10 + 8;
    puVar5[1] = uVar11 + (0xfff7 < uVar10);
    uVar11 = *(uint *)(puVar5[2] +
                      (((uVar10 >> 1 | (uint)((uVar11 & 1) != 0) << 0xf) >> 1 |
                       (uint)((uVar11 >> 1 & 1) != 0) << 0xf) >> 1 |
                      (uint)((uVar11 >> 2 & 1) != 0) << 0xf));
    uVar12 = param_3;
    iVar8 = param_1;
    do {
      do {
        *(undefined1 *)
         ((int)*(undefined4 *)(DAT_5b41_2858 + 4) + DAT_5b41_2858[param_2 + 0xc] + iVar8) =
             (char)(uVar11 >> ((byte)uVar10 & 7));
        uVar12 = uVar12 - 1;
        iVar8 = iVar8 + 1;
      } while (uVar12 != 0);
      param_2 = param_2 + 1;
      param_4 = param_4 - 1;
      uVar12 = param_3;
      iVar8 = param_1;
    } while (param_4 != 0);
    return;
  }
  puVar14 = local_10c;
  do {
    puVar4 = DAT_5b41_2858;
    uVar10 = *DAT_5b41_2858;
    uVar12 = DAT_5b41_2858[1];
    *DAT_5b41_2858 = uVar10 + 8;
    puVar4[1] = uVar12 + (0xfff7 < uVar10);
    puVar2 = puVar14;
    puVar14 = puVar14 + 1;
    *puVar2 = (char)(*(uint *)(puVar4[2] +
                              (((uVar10 >> 1 | (uint)((uVar12 & 1) != 0) << 0xf) >> 1 |
                               (uint)((uVar12 >> 1 & 1) != 0) << 0xf) >> 1 |
                              (uint)((uVar12 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar10 & 7));
    bVar6 = (char)local_6 - 1;
    local_6 = (uint)bVar6;
    iVar8 = param_2;
  } while (bVar6 != 0);
  do {
    do {
      puVar4 = DAT_5b41_2858;
      bVar6 = (byte)uVar11 & 0xf;
      uVar12 = *DAT_5b41_2858;
      uVar3 = DAT_5b41_2858[1];
      puVar1 = DAT_5b41_2858;
      uVar10 = *puVar1;
      *puVar1 = *puVar1 + uVar11;
      puVar4[1] = puVar4[1] + (uint)CARRY2(uVar10,uVar11);
      *(undefined1 *)
       ((int)*(undefined4 *)(DAT_5b41_2858 + 4) + DAT_5b41_2858[iVar8 + 0xc] + param_1) =
           local_10c[*(uint *)(puVar4[2] +
                              (((uVar12 >> 1 | (uint)((uVar3 & 1) != 0) << 0xf) >> 1 |
                               (uint)((uVar3 >> 1 & 1) != 0) << 0xf) >> 1 |
                              (uint)((uVar3 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar12 & 7) &
                     (uint)(byte)((byte)(-0x100 << bVar6) | (byte)(0xff00 >> 0x10 - bVar6))];
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(param_2 + param_4));
    param_1 = param_1 + 1;
    iVar8 = param_2;
  } while (param_1 < iVar9);
  return;
}

