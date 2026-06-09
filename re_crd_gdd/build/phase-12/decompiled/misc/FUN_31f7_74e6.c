// TIM2.EXE: FUN_31f7_74e6 @ file 0x03E656 Ghidra 0x39456
// Subsystem: misc | Size: 340 bytes


undefined2 __cdecl16far FUN_31f7_74e6(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  uVar1 = *(undefined2 *)(iVar5 + 0x9c);
  iVar2 = *(int *)(iVar5 + 0x9a);
  iVar4 = *(int *)(iVar5 + 0xa2);
  if (((*(byte *)(iVar2 + 0xc) & 0x10) != 0) &&
     (iVar4 = (*(int *)(DAT_554c_037c + 0x22) - iVar4) + -2, iVar4 < 0)) {
    iVar4 = iVar4 + *(int *)(DAT_554c_037c + 0x22);
  }
  bVar3 = DAT_5b41_1a52 <= *(int *)(iVar2 + 0x10);
  if ((iVar4 == 0) || (iVar4 == 4)) {
    if ((*(int *)(iVar5 + 8) == 0x2a) || (*(int *)(iVar5 + 8) == 0x36)) {
      *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_1a4a)[bVar3];
      FUN_28eb_3328(iVar2,uVar1);
      FUN_2424_0f94(iVar5,uVar6,3);
      *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x2000;
      return 0;
    }
    if ((iVar4 == 0) && ((*(byte *)(iVar5 + 0xd) & 0x10) == 0)) {
      *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_1a4e)[bVar3];
      FUN_28eb_3328(iVar2,uVar1);
      if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
        *(int *)(iVar5 + 0x3a) = *(int *)(iVar5 + 0x3a) + 0x600;
      }
      else {
        *(int *)(iVar5 + 0x3a) = *(int *)(iVar5 + 0x3a) + -0x600;
      }
      *(undefined2 *)(iVar5 + 0x3c) = 0xea00;
      FUN_549b_007a(0x28eb,iVar5,uVar6);
      return 0;
    }
  }
  if ((((iVar4 == 3) && ((int)((undefined2 *)&DAT_5b41_1a42)[bVar3] <= *(int *)(iVar2 + 0x10))) &&
      (*(int *)(iVar2 + 0x10) < (int)((undefined2 *)&DAT_5b41_1a4a)[bVar3])) &&
     (*(int *)(iVar5 + 0x3c) < -0x400)) {
    *(undefined2 *)(iVar2 + 0x10) = ((undefined2 *)&DAT_5b41_1a4e)[bVar3];
    FUN_28eb_3328(iVar2,uVar1);
  }
  return 1;
}

