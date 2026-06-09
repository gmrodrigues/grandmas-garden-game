// rope-physics-pass
// File offset 0x05514A Ghidra 0x4FF4A


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __cdecl16near
FUN_406b_1e72(undefined2 param_1,int *param_2,int param_3,undefined1 param_4,undefined1 param_5)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  int in_CX;
  uint in_DX;
  char *pcVar6;
  int unaff_DI;
  int iVar7;
  char *pcVar8;
  bool bVar9;
  ulong uVar10;
  undefined2 uStack_a;
  
  uVar3 = (int)DAT_554c_42dd - 8;
  if (8 < uVar3) {
    return (ulong)in_DX << 0x10;
  }
  bVar9 = CARRY2(uVar3,uVar3);
  iVar4 = uVar3 * 2;
  iVar7 = unaff_DI;
  switch(uVar3) {
  case 0:
    *(char *)((int)param_2 + 0x15) = *(char *)((int)param_2 + 0x15) << 3;
    if (unaff_DI != *param_2) {
      FUN_1000_137d();
    }
    DAT_5b41_1cef = unaff_DI;
    return CONCAT22(in_DX,1);
  case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 2:
    return CONCAT22(in_DX,uVar3);
  case 3:
    uVar5 = *(undefined2 *)0x86;
    pcVar8 = (char *)0x0;
    do {
      do {
        pcVar6 = pcVar8;
        pcVar8 = pcVar6 + 1;
      } while (*pcVar6 != '\0');
      pcVar8 = pcVar6 + 2;
    } while (pcVar6[1] != '\0');
    pcVar6 = pcVar6 + 4;
    pcVar8 = "";
    do {
      pcVar1 = pcVar6;
      pcVar6 = pcVar6 + 1;
      cVar2 = *pcVar1;
      pcVar1 = pcVar8;
      pcVar8 = pcVar8 + 1;
      *pcVar1 = cVar2;
    } while (cVar2 != '\0');
    uVar10 = FUN_4fd6_0266(0xfe);
    return uVar10;
  case 4:
    if (uVar3 != DAT_5b41_1b84) {
      param_2 = (int *)((uint)param_2 | 4);
    }
    if (DAT_5b41_1cd8 != DAT_5b41_1b86) {
      param_2 = (int *)((uint)param_2 | 8);
    }
    if (DAT_5b41_1cda != DAT_5b41_1b80) {
      param_2 = (int *)((uint)param_2 | 0x10);
    }
    if (DAT_5b41_1cdc != DAT_5b41_1b82) {
      param_2 = (int *)((uint)param_2 | 0x20);
    }
    if (DAT_5b41_1cde != DAT_5b41_1b92) {
      param_2 = (int *)((uint)param_2 | 0x40);
    }
    if (DAT_5b41_1ce0 != _DAT_5b41_1b94) {
      param_2 = (int *)((uint)param_2 | 0x80);
    }
    if (DAT_5b41_1b98 == 0) {
      param_2 = (int *)((uint)param_2 & 0xfeff);
    }
    DAT_5b41_1cd2 = _DAT_5b41_1b88;
    DAT_5b41_1cd4 = DAT_5b41_1b8a;
    DAT_5b41_1cd6 = DAT_5b41_1b84;
    DAT_5b41_1cd8 = DAT_5b41_1b86;
    DAT_5b41_1cda = DAT_5b41_1b80;
    DAT_5b41_1cdc = DAT_5b41_1b82;
    DAT_5b41_1cde = DAT_5b41_1b92;
    DAT_5b41_1ce0 = _DAT_5b41_1b94;
    DAT_5b41_1ce4 = 0;
    uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)param_2);
    if (((uint)param_2 & 1) != 0) {
      uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)DAT_5b41_1cd2);
    }
    if (((uint)param_2 & 2) != 0) {
      uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)DAT_5b41_1cd4);
    }
    if (((uint)param_2 & 4) != 0) {
      uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)DAT_5b41_1cd6);
    }
    if (((uint)param_2 & 8) != 0) {
      uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)DAT_5b41_1cd8);
    }
    if (((uint)param_2 & 0x10) != 0) {
      uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)DAT_5b41_1cda);
    }
    if (((uint)param_2 & 0x20) != 0) {
      uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)DAT_5b41_1cdc);
    }
    if (((uint)param_2 & 0x40) != 0) {
      uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)DAT_5b41_1cde);
    }
    if (((uint)param_2 & 0x80) != 0) {
      uVar5 = FUN_42da_05c8((char)DAT_5b41_1ce2,(char)DAT_5b41_1ce0);
    }
    return CONCAT22(in_DX,uVar5);
  case 5:
    if ((((uVar3 != 0 || DAT_5b41_1b56 != 0) && (param_2 != (int *)0x0 || param_3 != 0)) &&
        (param_3 == 0)) && (param_2 < (int *)0xffdd)) {
      FUN_3f2b_0dd2();
      uVar5 = FUN_3f2b_0fa3(param_2,0,param_4,param_5);
      FUN_3f2b_0e15();
      return CONCAT22(in_DX,uVar5);
    }
    return 0;
  case 6:
    DAT_554c_3d78 = uVar3;
    DAT_554c_3e46 = iVar4 + -4 + in_CX;
    return CONCAT22(DAT_554c_3d5a,param_3) & 0xffff3fff;
  case 8:
    in(in_DX);
    iVar4 = FUN_460e_0aa3(param_2,0,param_3,param_4);
    if (iVar4 != 0 || in_DX != 0) {
      return CONCAT22(in_DX,*(undefined2 *)(iVar4 + 4));
    }
    return (ulong)in_DX << 0x10;
  }
  while( true ) {
    if (iVar4 == 0) goto LAB_4bdc_0a61;
    *(undefined1 *)((int)*(undefined4 *)(iVar7 + 0xe) + 0x15c) = (char)in_DX;
    if (bVar9) break;
    iVar4 = *(int *)(iVar7 + 0x14);
    bVar9 = false;
    iVar7 = iVar7 + 4;
  }
  for (iVar4 = 0x38; iVar4 + 4 != iVar7; iVar4 = iVar4 + -4) {
    *(undefined2 *)(iVar4 + 0x12) = *(undefined2 *)(iVar4 + 0xe);
    *(undefined2 *)(iVar4 + 0x14) = *(undefined2 *)(iVar4 + 0x10);
  }
LAB_4bdc_0a61:
  *(uint *)(iVar7 + 0xe) = uVar3;
  *(int *)(iVar7 + 0x10) = unaff_DI;
  uVar5 = FUN_4bdc_0da0();
  return CONCAT22(uStack_a,uVar5);
}

