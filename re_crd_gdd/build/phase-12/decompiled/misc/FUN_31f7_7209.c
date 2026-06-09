// TIM2.EXE: FUN_31f7_7209 @ file 0x03E379 Ghidra 0x39179
// Subsystem: misc | Size: 90 bytes


/* WARNING: Instruction at (ram,0x0003709b) overlaps instruction at (ram,0x0003709a)
    */
/* WARNING: Removing unreachable block (ram,0x00037706) */
/* WARNING: Removing unreachable block (ram,0x0003771c) */
/* WARNING: Removing unreachable block (ram,0x00037719) */
/* WARNING: Removing unreachable block (ram,0x00037925) */

uint __cdecl16far FUN_31f7_7209(undefined4 param_1,int param_2)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  uint in_AX;
  uint uVar4;
  int iVar5;
  int iVar6;
  int unaff_SI;
  undefined2 uVar7;
  undefined2 in_stack_0000fffa;
  int iVar9;
  ulong uVar8;
  
  iVar5 = (int)param_1;
  if ((param_2 != 0xf) || (uVar4 = *(uint *)(iVar5 + 0x10), 3 < uVar4)) {
    *(undefined2 *)(iVar5 + 0xa8) = *(undefined2 *)(iVar5 + 0x10);
    FUN_31f7_71d1(iVar5,param_1._2_2_);
    FUN_28eb_3328(iVar5,param_1._2_2_);
    FUN_2424_0f94(iVar5,param_1._2_2_,3);
    uVar4 = FUN_28eb_2d82(iVar5,param_1._2_2_,2);
    return uVar4;
  }
  switch(uVar4) {
  case 0:
    pcVar1 = (char *)(uVar4 * 2 + unaff_SI);
    *pcVar1 = *pcVar1 + -1;
    return (uint)(byte)((char)in_AX + 0x89);
  case 1:
    return in_AX;
  case 2:
    uVar8 = CONCAT22(0x57c,in_stack_0000fffa);
    break;
  case 3:
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
code_r0x0003709d:
  iVar3 = 1;
LAB_31f7_5134:
  iVar9 = (int)(uVar8 >> 0x10);
  if (*(int *)((int)uVar8 + 0x10) < (int)((undefined2 *)&DAT_5b41_098d)[iVar9 + iVar3])
  goto LAB_31f7_51c7;
LAB_31f7_51be:
  do {
    *(undefined2 *)(iVar5 + 0x16) = 1;
LAB_31f7_51c7:
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              do {
                uVar7 = (undefined2)(uVar8 >> 0x10);
                iVar3 = *(int *)((int)uVar8 + 0x8e);
                iVar9 = *(int *)((int)uVar8 + 0x8c);
                uVar8 = CONCAT22(iVar3,iVar9);
                if (iVar9 == 0 && iVar3 == 0) {
                  if (*(int *)(iVar5 + 0x16) == 0) {
                    *(uint *)(iVar5 + 0x10) = *(uint *)(iVar5 + 0x10) & 0xfffb;
                  }
                  else {
                    *(uint *)(iVar5 + 0x10) = *(uint *)(iVar5 + 0x10) | 4;
                  }
                  uVar4 = 0;
                  for (iVar3 = 4; iVar3 < 6; iVar3 = iVar3 + 1) {
                    iVar6 = iVar5 + iVar3 * 4;
                    iVar9 = *(int *)(iVar6 + 0x60);
                    iVar6 = *(int *)(iVar6 + 0x5e);
                    uVar4 = 0;
                    if (iVar6 != 0 || iVar9 != 0) {
                      uVar4 = *(uint *)(iVar5 + 0x16);
                      *(uint *)(iVar6 + 0x16) = uVar4;
                    }
                  }
                  return uVar4;
                }
              } while (*(int *)(iVar9 + 0x16) == 0);
              iVar6 = *(int *)(iVar9 + 8);
              if (iVar6 == 0x46) {
                bVar2 = DAT_5b41_0989 <= *(int *)(iVar9 + 0xa8);
                uVar8 = (ulong)CONCAT12(bVar2,iVar9);
                if (DAT_5b41_098b <= *(int *)(iVar9 + 0xa8)) goto code_r0x0003709d;
                iVar3 = 0;
                goto LAB_31f7_5134;
              }
              if (0x46 < iVar6) break;
              if (iVar6 == 0x24) {
                bVar2 = DAT_5b41_097d <= *(int *)(iVar9 + 0xa8);
                uVar8 = (ulong)CONCAT12(bVar2,iVar9);
                if ((int)((undefined2 *)&DAT_5b41_0981)
                         [(uint)bVar2 + (uint)(DAT_5b41_097f <= *(int *)(iVar9 + 0xa8))] <=
                    *(int *)(iVar9 + 0x10)) goto LAB_31f7_51be;
              }
              else if (iVar6 < 0x25) {
                if (iVar6 == 0x19) {
                  if (*(int *)(iVar9 + 0x90) < 0) {
                    if ((*(byte *)(iVar9 + 0xc) & 0x10) == 0) goto LAB_31f7_51be;
                  }
                  else if ((*(byte *)(iVar9 + 0xc) & 0x10) != 0) goto LAB_31f7_51be;
                }
                else if ((iVar6 == 0x1d) || (iVar6 == 0x22)) goto LAB_31f7_51be;
              }
              else if ((iVar6 == 0x29) || (iVar6 == 0x2d)) goto LAB_31f7_51be;
            }
            if (iVar6 != 0x50) break;
            if (*(int *)(iVar9 + 0x10) < DAT_5b41_0999) {
              iVar6 = 0;
            }
            else if (*(int *)(iVar9 + 0x10) < DAT_5b41_099b) {
              iVar6 = 1;
            }
            else {
              iVar6 = 2;
            }
            if ((int)((undefined2 *)&DAT_5b41_0993)[iVar6] <= *(int *)(iVar9 + 0x10))
            goto LAB_31f7_51be;
          }
          if (0x50 < iVar6) break;
          if (iVar6 == 0x4b) {
            if (DAT_5b41_09a5 <= *(int *)(iVar9 + 0x10)) goto LAB_31f7_51be;
          }
          else if (iVar6 == 0x4e) {
            if (DAT_5b41_09a7 <= *(int *)(iVar9 + 0x10)) goto LAB_31f7_51be;
          }
          else if ((iVar6 == 0x4f) && (*(int *)(iVar9 + 0x16) == 1)) goto LAB_31f7_51be;
        }
        if (iVar6 == 0x6d) break;
        if (iVar6 == 0x8a) goto LAB_31f7_51be;
      }
    } while (*(int *)(iVar9 + 0x10) <= DAT_5b41_09a9);
  } while( true );
}

