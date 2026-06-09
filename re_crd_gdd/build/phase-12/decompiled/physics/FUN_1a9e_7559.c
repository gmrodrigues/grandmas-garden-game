// TIM2.EXE: FUN_1a9e_7559 @ file 0x027139 Ghidra 0x21F39
// Subsystem: physics | Size: 358 bytes


int __cdecl16far FUN_1a9e_7559(int *param_1,char param_2)

{
  undefined2 *puVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  
  DAT_5b41_282e = param_2 + -1;
  DAT_5b41_283f = FUN_1000_127a(2000);
  DAT_5b41_2835 = *(int *)*param_1;
  DAT_5b41_2833 = *(uint *)(*param_1 + 2);
  DAT_5b41_2837 = DAT_5b41_2833;
  DAT_5b41_2839 = DAT_5b41_2835;
  for (; *param_1 != 0; param_1 = param_1 + 1) {
    iVar4 = DAT_5b41_2839 + ((int)DAT_5b41_2837 >> 4);
    uVar7 = DAT_5b41_2837 & 0xf;
    DAT_5b41_2837 = uVar7;
    DAT_5b41_2839 = iVar4;
    if (DAT_554c_42df == '\0') {
      uVar5 = *(int *)(*param_1 + 6) * *(int *)(*param_1 + 8);
      uVar8 = FUN_2fc8_00fc(0x1000,uVar5,0,0,0);
      FUN_1a9e_74bc(uVar8,*(undefined2 *)*param_1,((undefined2 *)*param_1)[1],uVar5 >> 3);
      puVar1 = (undefined2 *)*param_1;
      *puVar1 = (int)((ulong)uVar8 >> 0x10);
      puVar1[1] = (int)uVar8;
      FUN_1a9e_7911(puVar1);
      func_0x0002fdf5(0x1000,uVar8);
    }
    else {
      FUN_1a9e_7911(*param_1);
    }
    piVar2 = (int *)*param_1;
    *piVar2 = iVar4;
    piVar2[1] = uVar7;
    piVar2[2] = -2;
  }
  iVar4 = DAT_5b41_2839 - DAT_5b41_2835;
  iVar6 = DAT_5b41_2837 - DAT_5b41_2833;
  DAT_5b41_282f = iVar4 + (iVar6 + 0xf >> 4);
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  FUN_1000_130c(DAT_5b41_283f);
  return iVar4 * 0x10 + iVar6;
}

