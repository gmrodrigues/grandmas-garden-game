// TIM2.EXE: FUN_1000_2c1a @ file 0x017E1A Ghidra 0x12C1A
// Subsystem: utility | Size: 113 bytes


void __cdecl16near FUN_1000_2c1a(void)

{
  undefined2 uVar1;
  int in_DX;
  int iVar2;
  undefined2 uStack_2;
  
  uStack_2 = *(int *)0x2;
  *(undefined2 *)0x2 = 0;
  *(int *)0x8 = uStack_2;
  if ((in_DX == DAT_1000_2bab) || (*(int *)0x2 != 0)) {
    FUN_1000_2cb4();
    uStack_2 = in_DX;
  }
  else {
    iVar2 = *(int *)0x0;
    *(int *)0x0 = *(int *)0x0 + iVar2;
    iVar2 = in_DX + iVar2;
    if (*(int *)0x2 == 0) {
      *(int *)0x8 = uStack_2;
    }
    else {
      *(int *)0x2 = uStack_2;
    }
  }
  iVar2 = uStack_2 + *(int *)0x0;
  if (*(int *)0x2 != 0) {
    return;
  }
  *(int *)0x0 = *(int *)0x0 + *(int *)0x0;
  *(int *)0x2 = uStack_2;
  if (iVar2 != *(int *)0x6) {
    uVar1 = *(undefined2 *)0x6;
    DAT_1000_2baf = *(undefined2 *)0x4;
    *(undefined2 *)0x6 = uVar1;
    *(undefined2 *)0x4 = DAT_1000_2baf;
    return;
  }
  DAT_1000_2baf = 0;
  return;
}

