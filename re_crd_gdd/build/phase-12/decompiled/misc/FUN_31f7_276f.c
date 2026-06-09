// TIM2.EXE: FUN_31f7_276f @ file 0x0398DF Ghidra 0x346DF
// Subsystem: misc | Size: 191 bytes


void __cdecl16far FUN_31f7_276f(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  uVar4 = 0x31f7;
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x10) != 0) {
    uVar4 = 0x4551;
    iVar1 = FUN_4551_0308(DAT_5b41_09d6,*(undefined2 *)(iVar2 + 0x10));
    if (iVar1 != 0) {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
      FUN_2424_0f94(iVar2,uVar3,3);
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x2000;
      return;
    }
  }
  if (*(int *)(iVar2 + 0x10) == 0) {
    if (*(int *)(iVar2 + 0x3a) == 0x3000) {
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xffef;
    }
    else if (*(int *)(iVar2 + 0x3a) == -0x3000) {
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x10;
    }
    else {
      *(undefined2 *)(iVar2 + 0x96) = 0;
      *(undefined2 *)(iVar2 + 0x3c) = 0;
      *(undefined2 *)(iVar2 + 0x3a) = 0;
      *(undefined2 *)(iVar2 + 0x10) = 1;
      uVar4 = 0x28eb;
      FUN_28eb_3328(iVar2,uVar3);
    }
    FUN_553b_00b6(uVar4,iVar2,uVar3,0,0x18,0);
    return;
  }
  *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
  FUN_28eb_3328(iVar2,uVar3);
  return;
}

