// TIM2.EXE: FUN_2e67_07f1 @ file 0x034061 Ghidra 0x2EE61
// Subsystem: misc | Size: 50 bytes


/* WARNING: Instruction at (ram,0x0002a0b3) overlaps instruction at (ram,0x0002a0b2)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl16far FUN_2e67_07f1(int *param_1,undefined2 *param_2)

{
  uint *puVar1;
  ulong uVar2;
  bool bVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint extraout_DX;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int unaff_SI;
  int unaff_DI;
  int iVar12;
  int unaff_ES;
  undefined4 uStackY_10;
  uint uVar13;
  undefined4 in_stack_0000fff4;
  int in_stack_0000fff8;
  int in_stack_0000fffa;
  
  if ((DAT_5b41_0bec == 0) || ((int *)param_1 == (int *)0x0)) {
    return 0;
  }
  uVar2 = ((ulong)param_1 & 0xffff) / 1000;
  uVar7 = (uint)uVar2;
  uVar9 = (uint)(int *)param_1 % 1000;
  if (4 < uVar7) {
    return 0;
  }
  uVar10 = uVar7 * 2;
  uVar13 = (uint)in_stack_0000fff4;
  switch(uVar7) {
  case 0:
    DAT_554c_516f = FUN_2fc8_01f3();
    uVar4 = FUN_2fc8_01f3();
    *param_2 = uVar4;
    uVar9 = DAT_554c_516f;
    *param_1._2_2_ = DAT_554c_516f;
    return uVar9;
  case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 3:
    if (((uVar7 | DAT_5b41_1b8a) & 2) != 0) {
      FUN_406b_03cb(0x28,0xffff);
      FUN_406b_03cb(0xfffd,0);
      do {
      } while( true );
    }
    if ((DAT_5b41_1b9e != 0 || DAT_5b41_1ba0 != 0) && ((DAT_5b41_1b9c != 0 || (DAT_5b41_04f9 != 0)))
       ) {
      if (DAT_5b41_1ae2 != 0 || DAT_5b41_1ae4 != 0) {
        if (*(int *)(DAT_5b41_1ae2 + 0x20) != 0 || *(int *)(DAT_5b41_1ae2 + 0x22) != 0) {
          (*(code *)*(undefined2 *)(DAT_5b41_1ae2 + 0x20))(0x2000,DAT_5b41_1ae2,DAT_5b41_1ae4,2);
          uVar9 = extraout_DX;
        }
        _DAT_5b41_1ae2 = 0;
      }
    }
    uVar7 = DAT_5b41_1b9e | DAT_5b41_1ba0;
    if (((uVar7 == 0) && (uVar7 = DAT_5b41_1ba2 | DAT_5b41_1ba4, uVar7 == 0)) &&
       ((DAT_5b41_1b94 & 1) != 0)) {
      if (DAT_5b41_1b90 == 0x1f) {
        uVar7 = FUN_460e_0f42(15000);
        uVar7 = uVar7 | uVar9;
        if (uVar7 == 0) {
          iVar12 = FUN_2e67_072c(3000,0xffff);
          uVar7 = FUN_2e67_072c(3000,iVar12 == 0);
        }
      }
      else {
        uVar7 = DAT_5b41_1b90;
        if (DAT_5b41_1b90 == 0x32) {
          uVar7 = FUN_460e_0f42(15000);
          uVar7 = uVar7 | uVar9;
          if (uVar7 == 0) {
            iVar12 = FUN_2e67_072c(1000,0xffff);
            uVar7 = FUN_2e67_072c(1000,iVar12 == 0);
            if (uVar7 == 0) {
              uVar9 = FUN_2e67_045f(DAT_5b41_0755,0,0,1);
              return uVar9;
            }
          }
        }
      }
    }
    return uVar7;
  case 4:
    iVar12 = *(int *)(uVar10 + 8);
    do {
      if (iVar12 != 0xb) {
        iVar12 = (int)((ulong)uStackY_10 >> 0x10);
        piVar11 = (int *)uStackY_10;
        if (piVar11[4] == 0x24) {
          iVar5 = piVar11[0x13] + 0x2a;
          iVar6 = piVar11[0x14] + 0x3d;
        }
        else if (piVar11[4] == 0x46) {
          iVar5 = piVar11[0x13] + 0x2f;
          iVar6 = piVar11[0x14] + 0x4a;
        }
        else {
          iVar5 = piVar11[0x13] + (piVar11[0x24] >> 1);
          iVar6 = piVar11[0x14] + piVar11[0x25];
        }
        bVar3 = false;
        if (((((piVar11[0x4d] != 0 || piVar11[0x4e] != 0) &&
              ((uint *)piVar11[0x4e] == param_1._2_2_)) && ((int *)piVar11[0x4d] == (int *)param_1))
            && ((0 < piVar11[0x1e] && (unaff_SI < iVar5)))) && (iVar5 < in_stack_0000fffa)) {
          bVar3 = true;
        }
        if (((!bVar3) && (unaff_SI < iVar5)) &&
           ((iVar5 < in_stack_0000fffa &&
            ((in_stack_0000fff8 + 0x14 < iVar6 &&
             (iVar6 + -4 < (int)((ulong)in_stack_0000fff4 >> 0x10))))))) {
          bVar3 = true;
        }
        if (bVar3) {
          iVar5 = ((int *)param_1)[0x46];
          piVar11[0x47] = ((int *)param_1)[0x47];
          piVar11[0x46] = iVar5;
          ((int *)param_1)[0x47] = iVar12;
          ((int *)param_1)[0x46] = (int)piVar11;
          piVar11[7] = piVar11[7] | 0x10;
          iVar5 = ((int *)param_1)[0x1d];
          piVar11[0x1e] = ((int *)param_1)[0x1e];
          piVar11[0x1d] = iVar5;
          piVar11[0x57] = uVar13;
        }
      }
      do {
        puVar1 = (uint *)((int *)uStackY_10)[1];
        piVar11 = (int *)*uStackY_10;
        uStackY_10 = (int *)CONCAT22(puVar1,piVar11);
        if (piVar11 == (int *)0x0 && puVar1 == (uint *)0x0) {
          return 0;
        }
      } while ((((param_1._2_2_ == puVar1) && ((int *)param_1 == piVar11)) ||
               ((*(byte *)((int)piVar11 + 0xd) & 0x20) != 0)) ||
              ((*(byte *)((int)piVar11 + 0xf) & 0x40) != 0));
      iVar12 = piVar11[4];
    } while( true );
  }
  DAT_554c_478b = DAT_554c_478b + '\x01';
  if ((uVar2 & 0x2b) == 0) {
    uVar8 = DAT_5b41_1b84 - unaff_DI >> 0xf;
    uVar9 = DAT_5b41_1b86 - ((uVar7 & 0xff2b) + (int)*(char *)(uVar10 + 0x7b));
    uVar7 = (int)uVar9 >> 0xf;
    iVar12 = ((DAT_5b41_1b84 - unaff_DI ^ uVar8) - uVar8) + ((uVar9 ^ uVar7) - uVar7);
    uVar9 = DAT_5b41_1b84 - unaff_SI >> 0xf;
    unaff_ES = (DAT_5b41_1b84 - unaff_SI ^ uVar9) - uVar9;
    in_stack_0000fff4 = CONCAT22(unaff_ES,uVar13);
    uVar9 = DAT_5b41_1b86 - iVar12;
    uVar7 = (int)uVar9 >> 0xf;
    if (iVar12 < (int)(unaff_ES + ((uVar9 ^ uVar7) - uVar7))) {
      *(int *)param_1 = 0;
    }
    else {
      *(int *)param_1 = 1;
    }
    uVar10 = uVar13;
    if (*(int *)(uVar13 + 8) != 7) {
      if (*(int *)(uVar13 + *(int *)param_1 * 2 + 0x76) != 0) {
        DAT_5b41_04f0 = 0;
        return 0;
      }
      DAT_5b41_04f0 = 0;
      return uVar13;
    }
  }
  if (*(int *)(uVar10 + 0x5e) != 0 || *(int *)(uVar10 + 0x60) != 0) {
    DAT_5b41_04f0 = 0;
    return 0;
  }
  DAT_5b41_04f0 = 0;
  return (uint)in_stack_0000fff4;
}

