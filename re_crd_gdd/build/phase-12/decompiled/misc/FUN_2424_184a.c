// TIM2.EXE: FUN_2424_184a @ file 0x02AC8A Ghidra 0x25A8A
// Subsystem: misc | Size: 291 bytes


void __cdecl16far FUN_2424_184a(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_DX;
  undefined2 *puVar7;
  
  for (puVar7 = DAT_5b41_04b0; puVar7 != (undefined2 *)0x0; puVar7 = (undefined2 *)*puVar7) {
    iVar2 = puVar7[1];
    iVar3 = puVar7[2];
    iVar4 = puVar7[3];
    iVar5 = puVar7[4];
    DAT_554c_42c3 = 1;
    DAT_554c_42c4 = iVar2;
    if (iVar2 < 0) {
      DAT_554c_42c4 = 0;
    }
    DAT_554c_42c6 = iVar4;
    DAT_554c_42c8 = iVar3;
    DAT_554c_42ca = iVar5;
    iVar6 = FUN_460e_0f42(0xffff);
    while (iVar6 != 0 || in_DX != 0) {
      if ((((((*(int *)(iVar6 + 0x1c) != 0 || *(int *)(iVar6 + 0x1e) != 0) &&
             (*(int *)(iVar6 + 0x14) <= iVar4)) &&
            (iVar2 <= *(int *)(iVar6 + 0x18) + *(int *)(iVar6 + 0x14) + -1)) &&
           ((*(int *)(iVar6 + 0x16) <= iVar5 &&
            (iVar3 <= *(int *)(iVar6 + 0x1a) + *(int *)(iVar6 + 0x16) + -1)))) &&
          ((iVar3 <= iVar5 && (*(int *)(iVar6 + 0x10) != DAT_5b41_0d12)))) &&
         (((((param_1 != 0 && (5000 < *(uint *)(iVar6 + 0x10))) &&
            (*(int *)(iVar6 + 0x10) == DAT_554c_2f1c)) && (*(int *)(iVar6 + 0x26) == 0)) ||
          ((param_1 == 0 && (*(int *)(iVar6 + 0x10) != DAT_554c_2f1c)))))) {
        (*(code *)*(undefined2 *)(iVar6 + 0x1c))(0x460e,iVar6,in_DX);
      }
      piVar1 = (int *)(iVar6 + 6);
      iVar6 = *(int *)(iVar6 + 4);
      in_DX = *piVar1;
    }
  }
  FUN_2424_02e7();
  return;
}

