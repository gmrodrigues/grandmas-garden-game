// TIM2.EXE: FUN_311b_01b8 @ file 0x036568 Ghidra 0x31368
// Subsystem: misc | Size: 77 bytes


/* WARNING: Instruction at (ram,0x00031c12) overlaps instruction at (ram,0x00031c0f)
    */

int __cdecl16far FUN_311b_01b8(undefined4 param_1)

{
  char *pcVar1;
  int in_AX;
  int in_CX;
  undefined2 in_DX;
  int iVar2;
  uint uVar3;
  undefined1 *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined4 local_6;
  int iStack_4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar3 = *(int *)(iVar2 + 0xc) + 0xdcd3;
  if (4 < uVar3) {
    if ((*(int *)(iVar2 + 0x2e) != in_CX) && (*(int *)(iVar2 + 0x2e) = in_CX, DAT_5b41_0d26 == 0)) {
      *(undefined2 *)(iVar2 + 0x26) = 1;
    }
    return 0;
  }
  switch(*(int *)(iVar2 + 0xc)) {
  case 0x232d:
    goto switchD_3000_1380_caseD_232d;
  case 0x232e:
    (&stack0xfffe)[(int)unaff_SI] = (&stack0xfffe)[(int)unaff_SI] + '\x01';
    (&stack0xfffe)[(int)unaff_DI] = (&stack0xfffe)[(int)unaff_DI] + (char)((uint)in_DX >> 8);
    (&stack0x6895)[(int)unaff_DI] = (&stack0x6895)[(int)unaff_DI] << 3;
    pcVar1 = (char *)(uVar3 * 2 + 0x5e);
    *pcVar1 = *pcVar1 + '\x01';
    return in_AX + 0x46c7;
  case 0x232f:
    *unaff_DI = *unaff_SI;
    break;
  case 0x2331:
    FUN_311b_0c97();
    FUN_2424_050d();
  }
  FUN_54a4_003e();
  func_0x00054ab5();
  FUN_4876_03c4();
  if (DAT_5b41_0d3e == 2) {
    iStack_4 = 2;
  }
  DAT_5b41_0947 = 0;
  DAT_5b41_094b = 0;
  DAT_5b41_0949 = 0;
  in_AX = iStack_4;
switchD_3000_1380_caseD_232d:
  return in_AX;
}

