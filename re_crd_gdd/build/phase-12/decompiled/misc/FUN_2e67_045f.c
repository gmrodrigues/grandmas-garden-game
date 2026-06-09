// TIM2.EXE: FUN_2e67_045f @ file 0x033CCF Ghidra 0x2EACF
// Subsystem: misc | Size: 184 bytes


/* WARNING: Instruction at (ram,0x000255cc) overlaps instruction at (ram,0x000255cb)
    */
/* WARNING: Type propagation algorithm not settling */

uint __cdecl16far FUN_2e67_045f(undefined2 *****param_1,undefined2 param_2,int param_3,char param_4)

{
  undefined2 *****pppppuVar1;
  undefined2 *puVar2;
  char cVar3;
  undefined2 ****ppppuVar4;
  uint uVar5;
  undefined2 ******ppppppuVar6;
  undefined2 *****pppppuVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  int unaff_SI;
  int *unaff_DI;
  int *piVar11;
  int unaff_ES;
  undefined2 ******ppppppuVar12;
  undefined2 ******ppppppuVar13;
  int iStackY_2c;
  undefined2 ******ppppppuStackY_2a;
  int iStackY_28;
  int iStackY_26;
  int iStackY_24;
  undefined4 uStackY_22;
  undefined4 uStackY_1e;
  uint uStackY_1a;
  int iStackY_18;
  int in_stack_0000ffea;
  undefined2 *******pppppppuStack_e;
  undefined2 ******ppppppuStack_c;
  undefined2 ******ppppppuStack_a;
  int local_4;
  
  if (DAT_5b41_0bec == 0) {
    uVar5 = 0xffff;
  }
  else {
    if ((DAT_5b41_0503 == 0) || ((undefined2 *****)0x3e7 < param_1)) {
      pppppuVar7 = param_1;
      piVar11 = unaff_DI;
      if ((DAT_5b41_0503 != 0) && (param_1 < (undefined2 *****)0x7d0)) {
        for (piVar11 = (int *)0x0; (int)piVar11 < 9; piVar11 = (int *)((int)piVar11 + 1)) {
          if ((undefined2 *****)((undefined2 *)&DAT_554c_2f24)[(int)piVar11] == pppppuVar7) {
            pppppuVar7 = (undefined2 *****)((undefined2 *)&DAT_554c_2f36)[(int)piVar11];
          }
        }
      }
      ppppppuStack_c = (undefined2 ******)0x2e67;
      pppppppuStack_e = (undefined2 *******)0xeb2a;
      ppppppuStack_a = (undefined2 ******)pppppuVar7;
      ppppppuVar6 = (undefined2 ******)FUN_2e67_0c9b();
      if (DAT_5b41_0bee != 0) {
        _ppppppuStack_a = (undefined2 ******)CONCAT22(unaff_DI,1);
        ppppppuStack_c = (undefined2 ******)param_3;
        pppppppuStack_e = (undefined2 *******)ppppppuVar6;
        uVar5 = FUN_2e67_08ed(pppppuVar7);
        return uVar5;
      }
      if (((undefined2 *****)0xf9f < pppppuVar7) ||
         (*(char *)((uint)pppppuVar7 / 1000 + 0x6b94) == '\0')) {
        uVar5 = (uint)pppppuVar7 / 1000;
        if (4 < uVar5) {
          return 0;
        }
        iVar8 = uVar5 * 2;
        ppppppuVar13 = (undefined2 ******)0x2000;
        switch(uVar5) {
        case 1:
          *(int *)(iVar8 + 0x3c) = uVar5 - *(int *)(iVar8 + 0x28);
          *(int *)(iVar8 + 0x3c) = *(int *)(iVar8 + 0x3c) << (9U - param_4 & 0x1f);
          _ppppppuStack_a = (undefined2 ******)CONCAT22(unaff_DI,ppppppuVar6);
          ppppppuStack_c = (undefined2 ******)param_1;
          pppppppuStack_e = (undefined2 *******)0x2000;
          uVar5 = FUN_549b_007a();
          return uVar5;
        case 2:
          _ppppppuStack_a = (undefined2 ******)CONCAT22(unaff_DI,0x2000);
          ppppppuStack_c = (undefined2 ******)0x1ea;
          uVar5 = (*DAT_554c_4d7e)();
          return uVar5;
        case 3:
          *(char *)(piVar11 + (uVar5 - 0x1dd)) = (char)piVar11[uVar5 - 0x1dd] + -1;
          iVar8 = piVar11[1];
          ppppppuStack_a = (undefined2 ******)*piVar11;
          ppppppuStack_c = (undefined2 ******)param_3;
          pppppppuStack_e = &pppppppuStack_e;
          FUN_2424_1a04(&stack0xfffa);
          FUN_2424_1a04(&pppppppuStack_e,&ppppppuStack_a,param_3);
          pppppppuStack_e =
               (undefined2 *******)
               (((int)ppppppuStack_a - (int)pppppppuStack_e) / 4 + (int)pppppppuStack_e);
          ppppppuStack_c =
               (undefined2 ******)((iVar8 - (int)ppppppuStack_c) / 4 + (int)ppppppuStack_c);
          uVar5 = FUN_2424_1a04();
          DAT_5b41_04aa = DAT_5b41_04aa + -1;
          return uVar5;
        case 4:
          cVar3 = *(char *)(iVar8 + 0x7a);
          do {
            pppppuVar7 = (undefined2 *****)((int)unaff_DI + (int)cVar3);
            iVar8 = (int)((undefined2 ******)uStackY_1e)[0x18] +
                    (int)*(char *)((int)(undefined2 ******)uStackY_1e + iStackY_18 * 2 + 0x7b);
            ppppppuVar12 = ppppppuVar13;
            if ((uStackY_22._2_2_ == iStackY_28) &&
               ((undefined2 ******)uStackY_22 == ppppppuStackY_2a)) {
              uStackY_1a = (uint)*(byte *)(iStackY_2c + 0x15);
              _ppppppuStack_a = (undefined2 ******)CONCAT22(3,iStackY_2c);
              ppppppuStack_c = (undefined2 ******)uStackY_1e._2_2_;
              pppppppuStack_e = (undefined2 *******)(undefined2 ******)uStackY_1e;
              ppppppuVar12 = (undefined2 ******)0x28eb;
              in_stack_0000ffea = FUN_28eb_3b36();
            }
            pppppuVar1 = ((undefined2 ******)uStackY_22)[0x18];
            iVar9 = (int)pppppuVar1 +
                    (int)*(char *)((int)(undefined2 ******)uStackY_22 + uStackY_1a * 2 + 0x7b);
            if ((int)pppppuVar7 < (int)pppppuVar1) {
              ppppppuStack_c = (undefined2 ******)((int)pppppuVar7 - DAT_5b41_0925);
              pppppuVar7 = pppppuVar1;
            }
            else {
              ppppppuStack_c = (undefined2 ******)((int)pppppuVar1 - DAT_5b41_0925);
            }
            if (iVar8 < iVar9) {
              pppppppuStack_e = (undefined2 *******)(iVar8 - DAT_5b41_0927);
              iVar8 = iVar9;
            }
            else {
              pppppppuStack_e = (undefined2 *******)(iVar9 - DAT_5b41_0927);
            }
            iVar8 = iVar8 - DAT_5b41_0927;
            if (0 < in_stack_0000ffea) {
              iVar8 = iVar8 + (in_stack_0000ffea >> 1);
            }
            uVar5 = (uint)((int)pppppuVar7 + (-(int)ppppppuStack_c - DAT_5b41_0925) <
                          iVar8 - (int)pppppppuStack_e);
            for (puVar10 = DAT_5b41_04ac; ppppppuVar13 = ppppppuVar12, puVar10 != (undefined2 *)0x0;
                puVar10 = (undefined2 *)*puVar10) {
              if ((((puVar10[6] == 1) &&
                   ((int)puVar10[1] <= (int)((int)pppppuVar7 + (uVar5 - DAT_5b41_0925)))) &&
                  ((int)((int)ppppppuStack_c - uVar5) <= (int)puVar10[3])) &&
                 (((int)puVar10[2] <= (int)(iVar8 + (uint)(uVar5 == 0)) &&
                  ((int)((int)pppppppuStack_e - (uint)(uVar5 == 0)) <= (int)puVar10[4])))) {
                _ppppppuStack_a = (undefined2 ******)CONCAT22(0x81,ppppppuVar6);
                ppppppuStack_c = (undefined2 ******)param_1;
                ppppppuVar13 = (undefined2 ******)0x28eb;
                pppppppuStack_e = (undefined2 *******)ppppppuVar12;
                FUN_28eb_2d82();
                uStackY_22 = (undefined2 ******)CONCAT22(iStackY_28,ppppppuStackY_2a);
                break;
              }
            }
            if ((uStackY_22._2_2_ == iStackY_28) &&
               ((undefined2 ******)uStackY_22 == ppppppuStackY_2a)) {
              uStackY_22 = (undefined2 ******)0x0;
              uStackY_1e = (undefined2 ******)0x0;
            }
            else {
              uStackY_1e = uStackY_22;
              uStackY_22 = (undefined2 ******)
                           CONCAT22(((undefined2 ******)uStackY_22)[0x30],
                                    ((undefined2 ******)uStackY_22)[0x2f]);
            }
            if ((undefined2 ******)uStackY_1e == (undefined2 ******)0x0 && uStackY_1e._2_2_ == 0) {
              return 0;
            }
            if ((undefined2 ******)uStackY_22 == (undefined2 ******)0x0 && uStackY_22._2_2_ == 0) {
              return 0;
            }
            if ((uStackY_1e._2_2_ != iStackY_24) ||
               ((undefined2 ******)uStackY_1e != (undefined2 ******)iStackY_26)) {
              iStackY_18 = 1;
              in_stack_0000ffea = 0;
            }
            unaff_DI = (int *)*(undefined2 *)((int)(undefined2 ******)uStackY_1e + 0x2e);
            cVar3 = *(char *)((int)(undefined2 ******)uStackY_1e + (iStackY_18 + 0x3d) * 2);
            unaff_ES = uStackY_1e._2_2_;
          } while( true );
        }
        *(uint *)(iVar8 + 0x7c) = uVar5;
        ppppppuStack_a[0x4c] = (undefined2 *****)param_1[0x4c];
        ppppuVar4 = (undefined2 ****)*(int *)(*(int *)((int)param_1[4] * 2 + 0x302) + 0x22);
        ppppppuStack_a[0x4b] = (undefined2 *****)ppppuVar4;
        if ((ppppuVar4 != (undefined2 ****)0x0) &&
           (*(int *)(*(int *)((int)param_1[4] * 2 + 0x302) + 0x46) == 0)) {
          ppppppuStack_a = (undefined2 ******)ppppppuStack_a[0x4b];
          unaff_DI = (int *)0x6;
          ppppppuStack_c = (undefined2 ******)0x2000;
          ppppppuVar13 = (undefined2 ******)0x1000;
          pppppppuStack_e = (undefined2 *******)0xc07a;
          ppppuVar4 = (undefined2 ****)FUN_1000_12bf();
          ppppppuStack_a[0x4c] = (undefined2 *****)ppppuVar4;
          if (ppppuVar4 == (undefined2 ****)0x0) {
            unaff_SI = 1;
            goto LAB_28eb_3257;
          }
          for (local_4 = 0; local_4 < (int)ppppppuStack_a[0x4b]; local_4 = local_4 + 1) {
            *ppppuVar4 = *ppppppuStack_c;
            ppppuVar4[1] = ppppppuStack_c[1];
            ppppuVar4[2] = ppppppuStack_c[2];
            ppppuVar4 = ppppuVar4 + 3;
            ppppppuStack_c = ppppppuStack_c + 3;
          }
        }
        ppppppuStack_a[0x54] = (undefined2 *****)param_1[0x54];
        ppppppuStack_a[0x55] = (undefined2 *****)param_1[0x55];
        ppppppuStack_a[0x56] = (undefined2 *****)param_1[0x56];
        puVar2 = (undefined2 *)(*(int *)((int)ppppppuStack_a[4] * 2 + 0x302) + 8);
        pppppppuStack_e = (undefined2 *******)0xc104;
        ppppppuStack_c = ppppppuVar13;
        (*(code *)*puVar2)();
LAB_28eb_3257:
        if ((unaff_SI != 0) && (ppppppuStack_a != (undefined2 ******)0x0 || unaff_DI != (int *)0x0))
        {
          pppppppuStack_e = (undefined2 *******)0xc120;
          ppppppuStack_c = ppppppuVar13;
          FUN_2321_0c23();
          ppppppuStack_a = (undefined2 ******)0x0;
        }
        return (uint)ppppppuStack_a;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}

