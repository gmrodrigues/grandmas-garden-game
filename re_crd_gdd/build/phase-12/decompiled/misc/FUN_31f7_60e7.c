// TIM2.EXE: FUN_31f7_60e7 @ file 0x03D257 Ghidra 0x38057
// Subsystem: misc | Size: 79 bytes


/* WARNING: Control flow encountered bad instruction data */

uint __cdecl16far FUN_31f7_60e7(undefined4 param_1,undefined4 param_2)

{
  uint in_AX;
  uint uVar1;
  int iVar2;
  int in_DX;
  int *piVar3;
  int unaff_SI;
  int unaff_DI;
  undefined2 uVar4;
  undefined2 in_FS;
  int in_stack_0000fff6;
  
  iVar2 = (int)param_1;
  if (((int)param_2 == 0xf) && (uVar1 = *(uint *)(iVar2 + 0x10), uVar1 < 4)) {
    switch(uVar1) {
    case 0:
      *(int *)(unaff_SI + 0x4c) = *(int *)(unaff_SI + 0x4c) + unaff_SI;
      if (*(int *)(iVar2 + 8) == 0x25) {
        if (*(int *)(iVar2 + 0x10) == 0) {
          DAT_554c_3b40 = DAT_554c_3b40 + -1;
          if (DAT_554c_3b40 < 1) {
            *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
            uVar1 = FUN_460e_1a42();
            in_AX = uVar1 / 200;
            DAT_554c_3b40 = uVar1 % 200 + 0x28;
          }
        }
        else {
          *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
          in_AX = *(uint *)(iVar2 + 0x10);
          if (in_AX == DAT_5b41_19ee) {
            *(undefined2 *)(iVar2 + 0x10) = 0;
          }
        }
      }
      return in_AX;
    case 1:
      return in_AX;
    case 2:
      break;
    case 3:
      if (CARRY2(uVar1,uVar1) || unaff_DI == -1) {
        *(uint *)(uVar1 * 2 + 0x16) = in_AX;
        uVar4 = (undefined2)((ulong)param_2 >> 0x10);
        if (unaff_SI != 0) {
          *(uint *)0x1b = *(uint *)0x1b | 0x200;
        }
        if ((*(byte *)0x1c & 2) == 0) {
          if (unaff_DI == 0) {
            *(int *)(in_stack_0000fff6 + 0x18) = *(int *)(in_stack_0000fff6 + 0x18) + 1;
          }
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
        return uVar1;
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    while( true ) {
      if (in_AX == 0) {
        DAT_5b41_1b4e = 0;
        DAT_5b41_1b4c = 0;
        DAT_5b41_1b4a = unaff_DI;
        DAT_5b41_1b48 = (int)param_2;
        DAT_5b41_1b46 = unaff_SI;
        DAT_5b41_1b3c = 0;
        return 1;
      }
      in_AX = 0;
      iVar2 = FUN_22de_01ec(unaff_SI * 0x12 + 4,0,DAT_5b41_1b50);
      if (iVar2 == 0 && in_DX == 0) break;
      piVar3 = (int *)(iVar2 + unaff_SI * 0x12);
      piVar3[1] = DAT_5b41_1b44;
      *piVar3 = DAT_5b41_1b42;
      DAT_5b41_1b42 = iVar2;
      DAT_5b41_1b44 = in_DX;
    }
    FUN_3f2b_011d();
    return 0;
  }
  *(undefined2 *)(iVar2 + 0xa8) = *(undefined2 *)(iVar2 + 0x10);
  FUN_31f7_60af(iVar2,param_1._2_2_);
  FUN_2424_0f94(iVar2,param_1._2_2_,3);
  uVar1 = FUN_28eb_2d82(iVar2,param_1._2_2_,2);
  return uVar1;
}

