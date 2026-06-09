// TIM2.EXE: FUN_460e_1314 @ file 0x04C5F4 Ghidra 0x473F4
// Subsystem: misc | Size: 154 bytes


int __cdecl16far FUN_460e_1314(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar1 = DAT_5b41_1c12;
  iVar2 = DAT_5b41_1c14;
  do {
    iVar4 = iVar2;
    iVar3 = iVar1;
    if (iVar3 == 0 && iVar4 == 0) {
      return iVar5;
    }
    DAT_5b41_1c1a = 0;
    DAT_5b41_1c16 = iVar3;
    DAT_5b41_1c18 = iVar4;
    if (((param_1 == 0) && (*(int *)(iVar3 + 0x26) != 0)) || (*(int *)(iVar3 + 0xc) == param_1)) {
      if (*(int *)(iVar3 + 0x26) != 0) {
        *(int *)(iVar3 + 0x26) = *(int *)(iVar3 + 0x26) + -1;
      }
      if (*(int *)(iVar3 + 0x1c) != 0 || *(int *)(iVar3 + 0x1e) != 0) {
        iVar5 = iVar5 + 1;
        (*(code *)*(undefined2 *)(iVar3 + 0x1c))(0x460e,iVar3,iVar4);
      }
      if (param_1 != 0) {
        return iVar5;
      }
    }
    iVar1 = DAT_5b41_1c16;
    iVar2 = DAT_5b41_1c18;
    if (DAT_5b41_1c1a == 0) {
      iVar1 = *(int *)(iVar3 + 4);
      iVar2 = *(int *)(iVar3 + 6);
    }
  } while( true );
}

