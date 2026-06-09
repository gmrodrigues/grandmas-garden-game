// TIM2.EXE: FUN_4fd6_0ed0 @ file 0x055E30 Ghidra 0x50C30
// Subsystem: misc | Size: 432 bytes


int __cdecl16far FUN_4fd6_0ed0(void)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  code *pcVar5;
  long lVar6;
  undefined2 uVar7;
  char cVar8;
  undefined2 uVar9;
  byte extraout_AH;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined2 in_BX;
  char *pcVar13;
  char *pcVar14;
  undefined2 unaff_SS;
  bool bVar15;
  undefined1 uVar16;
  undefined4 uVar17;
  char local_1f [8];
  uint local_17;
  uint local_f;
  
  uVar7 = uRam00050008;
  if ((*(byte *)0x42 & 1) == 0) {
    *(undefined1 *)0x42 = 1;
LAB_4fd6_0ef4:
    *(undefined2 *)0x3a = 0;
    *(undefined2 *)0x3c = 0x10;
    *(undefined2 *)0x3e = 0;
    *(undefined2 *)0x40 = 0x10;
    pcVar5 = (code *)swi(0x21);
    uVar9 = (*pcVar5)();
    if (((((byte)uVar9 < 10) && (DAT_f000_fffe < 0xfd)) && (DAT_f000_fffe != 0xfb)) &&
       (DAT_f000_fffe != 0xf9)) {
      if (0x30 < CONCAT11((byte)uVar9,(char)((uint)uVar9 >> 8))) {
        pcVar5 = (code *)swi(0x2f);
        cVar8 = (*pcVar5)();
        if (cVar8 == -0x80) {
          pcVar5 = (code *)swi(0x2f);
          (*pcVar5)();
          *(undefined2 *)0x43 = in_BX;
          *(undefined2 *)0x45 = 0xf000;
          (*(code *)*(undefined2 *)0x43)();
          if (1 < extraout_AH) {
            uVar11 = (*(code *)*(undefined2 *)0x43)();
            if (uVar11 != 0) {
              uVar17 = (*(code *)*(undefined2 *)0x43)();
              if ((int)uVar17 != 0) {
                *(undefined2 *)0x47 = (int)((ulong)uVar17 >> 0x10);
                uVar17 = (*(code *)*(undefined2 *)0x43)();
                if ((int)uVar17 != 0) {
                  *(undefined2 *)0x3a = in_BX;
                  *(undefined2 *)0x3c = (int)((ulong)uVar17 >> 0x10);
                  uVar10 = (uint)((ulong)uVar11 * 0x400);
                  uVar4 = *(uint *)0x3a;
                  iVar12 = *(int *)0x3c;
                  *(int *)0x3e = uVar10 + *(uint *)0x3a;
                  *(int *)0x40 = (int)((ulong)uVar11 * 0x400 >> 0x10) + iVar12 +
                                 (uint)CARRY2(uVar10,uVar4);
                }
                (*(code *)*(undefined2 *)0x43)();
                (*(code *)*(undefined2 *)0x43)();
                *(undefined2 *)0x47 = 0;
              }
            }
            goto LAB_4fd6_1065;
          }
        }
      }
      pcVar5 = (code *)swi(0x15);
      uVar11 = (*pcVar5)();
      if (uVar11 != 0) {
        lVar6 = (ulong)uVar11 * 0x400;
        *(undefined2 *)0x3e = (int)lVar6;
        *(undefined2 *)0x40 =
             CONCAT11((char)((ulong)lVar6 >> 0x18),(char)((ulong)lVar6 >> 0x10) + '\x10');
        if (*(int *)0x43 != 0 || *(int *)0x45 != 0) {
          *(undefined1 *)0x3c = 0x11;
          *(undefined2 *)0x3a = 0;
        }
        bVar15 = false;
        uVar16 = 1;
        FUN_4fd6_11ac();
        if (!bVar15) {
          pcVar14 = local_1f;
          pcVar13 = "d C++ - Copyright 1993 Borland Intl.";
          iVar12 = 5;
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            pcVar2 = pcVar14;
            pcVar14 = pcVar14 + 1;
            pcVar1 = pcVar13;
            pcVar13 = pcVar13 + 1;
            uVar16 = *pcVar1 == *pcVar2;
          } while ((bool)uVar16);
          if ((bool)uVar16) {
            *(undefined2 *)0x3a = (int)((ulong)local_17 * (ulong)local_f);
            *"nd Intl." = (char)((ulong)local_17 * (ulong)local_f >> 0x10) + '\x10';
          }
          bVar15 = true;
          pcVar13 = "";
          pcVar14 = "d C++ - Copyright 1993 Borland Intl.";
          iVar12 = 5;
          do {
            if (iVar12 == 0) break;
            iVar12 = iVar12 + -1;
            pcVar2 = pcVar13;
            pcVar13 = pcVar13 + 1;
            pcVar1 = pcVar14;
            pcVar14 = pcVar14 + 1;
            bVar15 = *pcVar1 == *pcVar2;
          } while (bVar15);
          if (bVar15) {
            bVar3 = *(byte *)0x2e;
            if ((*(byte *)0x3c <= bVar3) &&
               ((bVar3 != *(byte *)0x3c || (*(uint *)0x3a < *(uint *)0x2c)))) {
              *(uint *)0x3a = *(uint *)0x2c;
              *(byte *)0x3c = bVar3;
            }
          }
          goto LAB_4fd6_1065;
        }
      }
    }
    iVar12 = 0;
  }
  else {
    if ((*(byte *)0x42 & 2) == 0) goto LAB_4fd6_0ef4;
LAB_4fd6_1065:
    iVar12 = *(int *)0x3e - *(int *)0x3a;
  }
  return iVar12;
}

