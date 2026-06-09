// TIM2.EXE: FUN_1a9e_3854 @ file 0x023434 Ghidra 0x1E234
// Subsystem: level | Size: 267 bytes


void __cdecl16far FUN_1a9e_3854(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int *piVar8;
  undefined2 unaff_SS;
  int iVar9;
  int iVar10;
  
  iVar9 = param_2;
  iVar10 = param_1;
  uVar2 = DAT_554c_4d74;
  puVar7 = &stack0xfffe;
  iVar4 = param_3 + param_1;
  iVar5 = param_4 + param_2;
  if (DAT_554c_42cc != '\0') {
    if (DAT_554c_42c3 != '\0') {
      iVar6 = param_1 - DAT_554c_42c4;
      if (iVar6 < 0) {
        param_1 = param_1 - iVar6;
        param_3 = param_3 + iVar6;
      }
      iVar6 = param_2 - DAT_554c_42c8;
      if (iVar6 < 0) {
        param_2 = param_2 - iVar6;
        param_4 = param_4 + iVar6;
      }
      iVar4 = DAT_554c_42c6 - (iVar4 + -1);
      if (iVar4 < 0) {
        param_3 = param_3 + iVar4;
      }
      iVar4 = DAT_554c_42ca - (iVar5 + -1);
      if (iVar4 < 0) {
        param_4 = param_4 + iVar4;
      }
    }
    puVar7 = &stack0xfffe;
    if ((0 < param_3) && (puVar7 = &stack0xfffe, 0 < param_4)) {
      *(int *)0x0 = param_2;
      piVar8 = (int *)0x4;
      *(int *)0x2 = param_4;
      do {
        piVar1 = piVar8 + 1;
        *piVar8 = param_1;
        piVar8 = piVar8 + 2;
        *piVar1 = param_1 + param_3 + -1;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
      puVar7 = &stack0xfffe;
      (*DAT_554c_4de2)(0x1a9e);
    }
    *(int *)(puVar7 + 8) = iVar9;
    *(int *)(puVar7 + 6) = iVar10;
  }
  if ((DAT_554c_42cc == '\0') || (DAT_554c_42cd != DAT_554c_42ce)) {
    uVar2 = *(undefined2 *)(puVar7 + 6);
    uVar3 = *(undefined2 *)(puVar7 + 8);
    func_0x00010102(0x1a9e,*(undefined2 *)(puVar7 + -4),uVar3,*(undefined2 *)(puVar7 + -4),
                    *(undefined2 *)(puVar7 + -6));
    func_0x00010102(0x1a9e,uVar2,*(undefined2 *)(puVar7 + -6));
    func_0x00010102(0x1a9e,uVar2,uVar3,uVar2);
    func_0x00010102(0x1a9e,uVar2,uVar3,*(undefined2 *)(puVar7 + -4),uVar3);
  }
  return;
}

