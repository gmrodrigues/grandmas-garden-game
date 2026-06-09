// TIM2.EXE: FUN_31f7_4fd6 @ file 0x03C146 Ghidra 0x36F46
// Subsystem: misc | Size: 609 bytes


void __cdecl16far FUN_31f7_4fd6(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (int)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x40;
  if ((DAT_5b41_0923 & 7) == 4) {
    *(undefined2 *)(iVar1 + 0x16) = 0;
    FUN_28eb_4f3d(iVar1,iVar5,0x3000,0xffe6,0x1a,0xffe6,0x1a);
    iVar4 = iVar1;
    iVar6 = iVar5;
LAB_31f7_51ca:
    do {
      iVar2 = *(int *)(iVar4 + 0x8e);
      iVar4 = *(int *)(iVar4 + 0x8c);
      if (iVar4 == 0 && iVar2 == 0) goto LAB_31f7_51e5;
      iVar6 = iVar2;
      if (*(int *)(iVar4 + 0x16) != 0) {
        iVar3 = *(int *)(iVar4 + 8);
        if (iVar3 == 0x46) {
          if (*(int *)(iVar4 + 0x10) <
              (int)((undefined2 *)&DAT_5b41_098d)
                   [(uint)(DAT_5b41_0989 <= *(int *)(iVar4 + 0xa8)) +
                    (uint)(DAT_5b41_098b <= *(int *)(iVar4 + 0xa8))]) goto LAB_31f7_51ca;
        }
        else if (iVar3 < 0x47) {
          if (iVar3 == 0x24) {
            if (*(int *)(iVar4 + 0x10) <
                (int)((undefined2 *)&DAT_5b41_0981)
                     [(uint)(DAT_5b41_097d <= *(int *)(iVar4 + 0xa8)) +
                      (uint)(DAT_5b41_097f <= *(int *)(iVar4 + 0xa8))]) goto LAB_31f7_51ca;
          }
          else if (iVar3 < 0x25) {
            if (iVar3 == 0x19) {
              if (*(int *)(iVar4 + 0x90) < 0) {
                if ((*(byte *)(iVar4 + 0xc) & 0x10) != 0) goto LAB_31f7_51ca;
              }
              else if ((*(byte *)(iVar4 + 0xc) & 0x10) == 0) goto LAB_31f7_51ca;
            }
            else if ((iVar3 != 0x1d) && (iVar3 != 0x22)) goto LAB_31f7_51ca;
          }
          else if ((iVar3 != 0x29) && (iVar3 != 0x2d)) goto LAB_31f7_51ca;
        }
        else if (iVar3 == 0x50) {
          if (*(int *)(iVar4 + 0x10) < DAT_5b41_0999) {
            iVar3 = 0;
          }
          else if (*(int *)(iVar4 + 0x10) < DAT_5b41_099b) {
            iVar3 = 1;
          }
          else {
            iVar3 = 2;
          }
          if (*(int *)(iVar4 + 0x10) < (int)((undefined2 *)&DAT_5b41_0993)[iVar3])
          goto LAB_31f7_51ca;
        }
        else if (iVar3 < 0x51) {
          if (iVar3 == 0x4b) {
            if (*(int *)(iVar4 + 0x10) < DAT_5b41_09a5) goto LAB_31f7_51ca;
          }
          else if (iVar3 == 0x4e) {
            if (*(int *)(iVar4 + 0x10) < DAT_5b41_09a7) goto LAB_31f7_51ca;
          }
          else if ((iVar3 != 0x4f) || (*(int *)(iVar4 + 0x16) != 1)) goto LAB_31f7_51ca;
        }
        else if (iVar3 == 0x6d) {
          if (*(int *)(iVar4 + 0x10) <= DAT_5b41_09a9) goto LAB_31f7_51ca;
        }
        else if (iVar3 != 0x8a) goto LAB_31f7_51ca;
        *(undefined2 *)(iVar1 + 0x16) = 1;
      }
    } while( true );
  }
LAB_31f7_51fe:
  for (iVar4 = 4; iVar4 < 6; iVar4 = iVar4 + 1) {
    iVar2 = iVar1 + iVar4 * 4;
    iVar6 = *(int *)(iVar2 + 0x60);
    iVar2 = *(int *)(iVar2 + 0x5e);
    if (iVar2 != 0 || iVar6 != 0) {
      *(undefined2 *)(iVar2 + 0x16) = *(undefined2 *)(iVar1 + 0x16);
    }
  }
  return;
LAB_31f7_51e5:
  if (*(int *)(iVar1 + 0x16) == 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffb;
  }
  else {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 4;
  }
  goto LAB_31f7_51fe;
}

