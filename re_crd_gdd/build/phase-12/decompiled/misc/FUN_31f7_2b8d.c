// TIM2.EXE: FUN_31f7_2b8d @ file 0x039CFD Ghidra 0x34AFD
// Subsystem: misc | Size: 114 bytes


void __cdecl16far FUN_31f7_2b8d(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  if ((DAT_5b41_051f & 1) != 0) {
    uVar4 = (undefined2)((ulong)param_1 >> 0x10);
    iVar3 = (int)param_1;
    if (*(int *)(iVar3 + 0x10) == 0) {
      DAT_554c_3ada = DAT_554c_3ada + -1;
      if (-1 < DAT_554c_3ada) {
        return;
      }
      uVar1 = FUN_460e_1a42();
      DAT_554c_3ada = uVar1 % 100 + 0x14;
      *(undefined2 *)(iVar3 + 0x10) = 1;
    }
    else {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
      iVar2 = FUN_4551_0308(DAT_5b41_09dc,*(undefined2 *)(iVar3 + 0x10));
      if (iVar2 == -1) {
        *(undefined2 *)(iVar3 + 0x10) = 0;
      }
    }
    FUN_28eb_3328(iVar3,uVar4);
  }
  return;
}

