// TIM2.EXE: FUN_1a9e_4464 @ file 0x024044 Ghidra 0x1EE44
// Subsystem: level | Size: 1153 bytes


/* WARNING: Removing unreachable block (ram,0x0001ef56) */
/* WARNING: Removing unreachable block (ram,0x0001ef5b) */
/* WARNING: Removing unreachable block (ram,0x0001efd1) */
/* WARNING: Removing unreachable block (ram,0x0001efd6) */

void __cdecl16far FUN_1a9e_4464(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  byte bVar11;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  undefined2 *puVar14;
  uint uVar15;
  uint uVar16;
  undefined2 *puVar17;
  undefined2 unaff_ES;
  
  if (1 < (int)DAT_554c_445c) {
    uVar12 = 0;
    uVar16 = 0;
    bVar6 = (int)((undefined2 *)&DAT_554c_436c)[DAT_554c_445c - 1] < DAT_554c_42c4;
    uVar10 = DAT_554c_445c - 1;
    do {
      uVar13 = uVar12;
      iVar8 = DAT_554c_42c6;
      iVar7 = DAT_554c_42c4;
      iVar3 = ((undefined2 *)&DAT_554c_436c)[uVar13];
      bVar4 = iVar3 < DAT_554c_42c4;
      bVar5 = DAT_554c_42c6 < iVar3;
      if (bVar6 || bVar4) {
        uVar15 = uVar16;
        if (!(bool)(bVar6 & bVar4)) {
          if (bVar6) {
            if (bVar4) {
              *(int *)((int)(undefined2 *)&DAT_554c_43bc + uVar16) = DAT_554c_42c4;
              *(int *)((int)(undefined2 *)&DAT_554c_43e4 + uVar16) =
                   (int)(((long)(int)(((undefined2 *)&DAT_554c_4394)[uVar13] -
                                     ((undefined2 *)&DAT_554c_4394)[uVar10]) *
                         (long)(iVar7 - ((undefined2 *)&DAT_554c_436c)[uVar10])) /
                        (long)(int)(((undefined2 *)&DAT_554c_436c)[uVar13] -
                                   ((undefined2 *)&DAT_554c_436c)[uVar10])) +
                   ((undefined2 *)&DAT_554c_4394)[uVar10];
              iVar7 = DAT_554c_42c6;
              iVar3 = DAT_554c_42c4;
              if (bVar4) {
                *(int *)((int)(undefined2 *)&DAT_554c_43be + uVar16) = DAT_554c_42c4;
                *(int *)((int)(undefined2 *)&DAT_554c_43e6 + uVar16) =
                     (int)(((long)(int)(((undefined2 *)&DAT_554c_4394)[uVar10] -
                                       ((undefined2 *)&DAT_554c_4394)[uVar13]) *
                           (long)(iVar3 - ((undefined2 *)&DAT_554c_436c)[uVar13])) /
                          (long)(int)(((undefined2 *)&DAT_554c_436c)[uVar10] -
                                     ((undefined2 *)&DAT_554c_436c)[uVar13])) +
                     ((undefined2 *)&DAT_554c_4394)[uVar13];
                uVar15 = uVar16 + 4;
              }
              else {
                uVar15 = uVar16 + 2;
                if (bVar5) {
                  *(int *)((int)(undefined2 *)&DAT_554c_43be + uVar16) = DAT_554c_42c6;
                  *(int *)((int)(undefined2 *)&DAT_554c_43e6 + uVar16) =
                       (int)(((long)(int)(((undefined2 *)&DAT_554c_4394)[uVar10] -
                                         ((undefined2 *)&DAT_554c_4394)[uVar13]) *
                             (long)(iVar7 - ((undefined2 *)&DAT_554c_436c)[uVar13])) /
                            (long)(int)(((undefined2 *)&DAT_554c_436c)[uVar10] -
                                       ((undefined2 *)&DAT_554c_436c)[uVar13])) +
                       ((undefined2 *)&DAT_554c_4394)[uVar13];
                  uVar15 = uVar16 + 4;
                }
              }
            }
            else {
              *(int *)((int)(undefined2 *)&DAT_554c_43bc + uVar16) = DAT_554c_42c4;
              *(int *)((int)(undefined2 *)&DAT_554c_43e4 + uVar16) =
                   (int)(((long)(int)(((undefined2 *)&DAT_554c_4394)[uVar13] -
                                     ((undefined2 *)&DAT_554c_4394)[uVar10]) *
                         (long)(iVar7 - ((undefined2 *)&DAT_554c_436c)[uVar10])) /
                        (long)(int)(((undefined2 *)&DAT_554c_436c)[uVar13] -
                                   ((undefined2 *)&DAT_554c_436c)[uVar10])) +
                   ((undefined2 *)&DAT_554c_4394)[uVar10];
              *(undefined2 *)((int)(undefined2 *)&DAT_554c_43be + uVar16) =
                   ((undefined2 *)&DAT_554c_436c)[uVar13];
              *(undefined2 *)((int)(undefined2 *)&DAT_554c_43e6 + uVar16) =
                   ((undefined2 *)&DAT_554c_4394)[uVar13];
              uVar15 = uVar16 + 4;
            }
          }
          else if (bVar4) {
            *(int *)((int)(undefined2 *)&DAT_554c_43bc + uVar16) = DAT_554c_42c4;
            *(int *)((int)(undefined2 *)&DAT_554c_43e4 + uVar16) =
                 (int)(((long)(int)(((undefined2 *)&DAT_554c_4394)[uVar10] -
                                   ((undefined2 *)&DAT_554c_4394)[uVar13]) *
                       (long)(iVar7 - ((undefined2 *)&DAT_554c_436c)[uVar13])) /
                      (long)(int)(((undefined2 *)&DAT_554c_436c)[uVar10] -
                                 ((undefined2 *)&DAT_554c_436c)[uVar13])) +
                 ((undefined2 *)&DAT_554c_4394)[uVar13];
            uVar15 = uVar16 + 2;
          }
          else if (bVar5) {
            *(int *)((int)(undefined2 *)&DAT_554c_43bc + uVar16) = DAT_554c_42c6;
            *(int *)((int)(undefined2 *)&DAT_554c_43e4 + uVar16) =
                 (int)(((long)(int)(((undefined2 *)&DAT_554c_4394)[uVar10] -
                                   ((undefined2 *)&DAT_554c_4394)[uVar13]) *
                       (long)(iVar8 - ((undefined2 *)&DAT_554c_436c)[uVar13])) /
                      (long)(int)(((undefined2 *)&DAT_554c_436c)[uVar10] -
                                 ((undefined2 *)&DAT_554c_436c)[uVar13])) +
                 ((undefined2 *)&DAT_554c_4394)[uVar13];
            uVar15 = uVar16 + 2;
          }
        }
      }
      else {
        *(undefined2 *)((int)(undefined2 *)&DAT_554c_43bc + uVar16) =
             ((undefined2 *)&DAT_554c_436c)[uVar13];
        *(undefined2 *)((int)(undefined2 *)&DAT_554c_43e4 + uVar16) =
             ((undefined2 *)&DAT_554c_4394)[uVar13];
        uVar15 = uVar16 + 2;
      }
      uVar12 = (uVar13 & 0x7fff) + 1;
      uVar16 = uVar15;
      bVar6 = bVar4;
      uVar10 = uVar13;
    } while (uVar12 != DAT_554c_445c);
    uVar15 = uVar15 >> 1;
    DAT_554c_445c = uVar15;
    if (uVar15 < 2) {
      puVar14 = (undefined2 *)&DAT_554c_43bc;
      puVar17 = (undefined2 *)&DAT_554c_436c;
      for (uVar10 = uVar15; uVar10 != 0; uVar10 = uVar10 - 1) {
        puVar2 = puVar17;
        puVar17 = puVar17 + 1;
        puVar1 = puVar14;
        puVar14 = puVar14 + 1;
        *puVar2 = *puVar1;
      }
      puVar14 = (undefined2 *)&DAT_554c_43e4;
      puVar17 = (undefined2 *)&DAT_554c_4394;
      for (; uVar15 != 0; uVar15 = uVar15 - 1) {
        puVar2 = puVar17;
        puVar17 = puVar17 + 1;
        puVar1 = puVar14;
        puVar14 = puVar14 + 1;
        *puVar2 = *puVar1;
      }
    }
    else {
      bVar9 = 0;
      if (DAT_554c_42ca < (int)((undefined2 *)&DAT_554c_43e4)[uVar15 - 1]) {
        bVar9 = 4;
      }
      if ((int)((undefined2 *)&DAT_554c_43e4)[uVar15 - 1] < DAT_554c_42c8) {
        bVar9 = bVar9 | 8;
      }
      uVar16 = 0;
      uVar12 = 0;
      uVar10 = uVar15 - 1;
      do {
        uVar13 = uVar12;
        iVar7 = DAT_554c_42ca;
        iVar3 = DAT_554c_42c8;
        bVar11 = 0;
        if (DAT_554c_42ca < (int)((undefined2 *)&DAT_554c_43e4)[uVar13]) {
          bVar11 = 4;
        }
        if ((int)((undefined2 *)&DAT_554c_43e4)[uVar13] < DAT_554c_42c8) {
          bVar11 = bVar11 | 8;
        }
        if (bVar9 == 0 && bVar11 == 0) {
          *(undefined2 *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
               ((undefined2 *)&DAT_554c_43bc)[uVar13];
          *(undefined2 *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) =
               ((undefined2 *)&DAT_554c_43e4)[uVar13];
          uVar16 = uVar16 + 2;
        }
        else if ((bVar9 & bVar11) == 0) {
          if (bVar9 == 0) {
            if ((bVar11 & 8) == 0) {
              if ((bVar11 & 4) != 0) {
                *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) = DAT_554c_42ca;
                *(int *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                     (int)(((long)(int)(((undefined2 *)&DAT_554c_43bc)[uVar10] -
                                       ((undefined2 *)&DAT_554c_43bc)[uVar13]) *
                           (long)(iVar7 - ((undefined2 *)&DAT_554c_43e4)[uVar13])) /
                          (long)(int)(((undefined2 *)&DAT_554c_43e4)[uVar10] -
                                     ((undefined2 *)&DAT_554c_43e4)[uVar13])) +
                     ((undefined2 *)&DAT_554c_43bc)[uVar13];
                uVar16 = uVar16 + 2;
              }
            }
            else {
              *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) = DAT_554c_42c8;
              *(int *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                   (int)(((long)(int)(((undefined2 *)&DAT_554c_43bc)[uVar10] -
                                     ((undefined2 *)&DAT_554c_43bc)[uVar13]) *
                         (long)(iVar3 - ((undefined2 *)&DAT_554c_43e4)[uVar13])) /
                        (long)(int)(((undefined2 *)&DAT_554c_43e4)[uVar10] -
                                   ((undefined2 *)&DAT_554c_43e4)[uVar13])) +
                   ((undefined2 *)&DAT_554c_43bc)[uVar13];
              uVar16 = uVar16 + 2;
            }
          }
          else if (bVar11 == 0) {
            if ((bVar9 & 8) == 0) {
              if ((bVar9 & 4) != 0) {
                *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) = DAT_554c_42ca;
                *(int *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                     (int)(((long)(int)(((undefined2 *)&DAT_554c_43bc)[uVar13] -
                                       ((undefined2 *)&DAT_554c_43bc)[uVar10]) *
                           (long)(iVar7 - ((undefined2 *)&DAT_554c_43e4)[uVar10])) /
                          (long)(int)(((undefined2 *)&DAT_554c_43e4)[uVar13] -
                                     ((undefined2 *)&DAT_554c_43e4)[uVar10])) +
                     ((undefined2 *)&DAT_554c_43bc)[uVar10];
                uVar16 = uVar16 + 2;
              }
            }
            else {
              *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) = DAT_554c_42c8;
              *(int *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                   (int)(((long)(int)(((undefined2 *)&DAT_554c_43bc)[uVar13] -
                                     ((undefined2 *)&DAT_554c_43bc)[uVar10]) *
                         (long)(iVar3 - ((undefined2 *)&DAT_554c_43e4)[uVar10])) /
                        (long)(int)(((undefined2 *)&DAT_554c_43e4)[uVar13] -
                                   ((undefined2 *)&DAT_554c_43e4)[uVar10])) +
                   ((undefined2 *)&DAT_554c_43bc)[uVar10];
              uVar16 = uVar16 + 2;
            }
            *(undefined2 *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                 ((undefined2 *)&DAT_554c_43bc)[uVar13];
            *(undefined2 *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) =
                 ((undefined2 *)&DAT_554c_43e4)[uVar13];
            uVar16 = uVar16 + 2;
          }
          else {
            if ((bVar9 & 8) == 0) {
              if ((bVar9 & 4) != 0) {
                *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) = DAT_554c_42ca;
                *(int *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                     (int)(((long)(int)(((undefined2 *)&DAT_554c_43bc)[uVar13] -
                                       ((undefined2 *)&DAT_554c_43bc)[uVar10]) *
                           (long)(iVar7 - ((undefined2 *)&DAT_554c_43e4)[uVar10])) /
                          (long)(int)(((undefined2 *)&DAT_554c_43e4)[uVar13] -
                                     ((undefined2 *)&DAT_554c_43e4)[uVar10])) +
                     ((undefined2 *)&DAT_554c_43bc)[uVar10];
                uVar16 = uVar16 + 2;
              }
            }
            else {
              *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) = DAT_554c_42c8;
              *(int *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                   (int)(((long)(int)(((undefined2 *)&DAT_554c_43bc)[uVar13] -
                                     ((undefined2 *)&DAT_554c_43bc)[uVar10]) *
                         (long)(iVar3 - ((undefined2 *)&DAT_554c_43e4)[uVar10])) /
                        (long)(int)(((undefined2 *)&DAT_554c_43e4)[uVar13] -
                                   ((undefined2 *)&DAT_554c_43e4)[uVar10])) +
                   ((undefined2 *)&DAT_554c_43bc)[uVar10];
              uVar16 = uVar16 + 2;
            }
            iVar7 = DAT_554c_42ca;
            iVar3 = DAT_554c_42c8;
            if ((bVar11 & 8) == 0) {
              if ((bVar11 & 4) != 0) {
                *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) = DAT_554c_42ca;
                *(int *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                     (int)(((long)(int)(((undefined2 *)&DAT_554c_43bc)[uVar10] -
                                       ((undefined2 *)&DAT_554c_43bc)[uVar13]) *
                           (long)(iVar7 - ((undefined2 *)&DAT_554c_43e4)[uVar13])) /
                          (long)(int)(((undefined2 *)&DAT_554c_43e4)[uVar10] -
                                     ((undefined2 *)&DAT_554c_43e4)[uVar13])) +
                     ((undefined2 *)&DAT_554c_43bc)[uVar13];
                uVar16 = uVar16 + 2;
              }
            }
            else {
              *(int *)((int)(undefined2 *)&DAT_554c_4394 + uVar16) = DAT_554c_42c8;
              *(int *)((int)(undefined2 *)&DAT_554c_436c + uVar16) =
                   (int)(((long)(int)(((undefined2 *)&DAT_554c_43bc)[uVar10] -
                                     ((undefined2 *)&DAT_554c_43bc)[uVar13]) *
                         (long)(iVar3 - ((undefined2 *)&DAT_554c_43e4)[uVar13])) /
                        (long)(int)(((undefined2 *)&DAT_554c_43e4)[uVar10] -
                                   ((undefined2 *)&DAT_554c_43e4)[uVar13])) +
                   ((undefined2 *)&DAT_554c_43bc)[uVar13];
              uVar16 = uVar16 + 2;
            }
          }
        }
        uVar12 = (uVar13 & 0x7fff) + 1;
        bVar9 = bVar11;
        uVar10 = uVar13;
      } while (uVar12 != DAT_554c_445c);
      DAT_554c_445c = uVar16 >> 1;
    }
  }
  return;
}

