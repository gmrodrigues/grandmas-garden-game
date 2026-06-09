// TIM2.EXE: FUN_28eb_4d0a @ file 0x032DBA Ghidra 0x2DBBA
// Subsystem: misc | Size: 138 bytes


void __cdecl16far FUN_28eb_4d0a(void)

{
  undefined2 uVar1;
  int iVar2;
  int in_BX;
  int iVar3;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 uVar4;
  undefined2 unaff_SS;
  
  do {
    iVar2 = *(int *)(in_BX + 0x60);
    uVar1 = *(undefined2 *)(in_BX + 0x5e);
    *(int *)(unaff_BP + -0x10) = iVar2;
    *(undefined2 *)(unaff_BP + -0x12) = uVar1;
    while( true ) {
      if (*(int *)(unaff_BP + -0xe) == 0 && *(int *)(unaff_BP + -0xc) == 0) {
        FUN_28eb_2107();
        uVar1 = FUN_28eb_399d();
        uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -6) >> 0x10);
        iVar3 = (int)*(undefined4 *)(unaff_BP + -6);
        *(undefined2 *)(iVar3 + 0xb2) = uVar1;
        *(undefined2 *)(iVar3 + 0xb0) = uVar1;
        *(undefined2 *)(iVar3 + 0xae) = uVar1;
        uVar1 = FUN_28eb_399d();
        uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -6) >> 0x10);
        iVar3 = (int)*(undefined4 *)(unaff_BP + -6);
        *(undefined2 *)(iVar3 + 0xb8) = uVar1;
        *(undefined2 *)(iVar3 + 0xb6) = uVar1;
        *(undefined2 *)(iVar3 + 0xb4) = uVar1;
        *(undefined2 *)(unaff_DI + 0x1c) = 0;
        *(undefined2 *)(unaff_DI + 0x1a) = 0;
        *(undefined2 *)(unaff_DI + 0x18) = 0;
        uVar1 = FUN_28eb_32d8(*(undefined2 *)(unaff_BP + -6),*(undefined2 *)(unaff_BP + -4),0x1000);
        *(int *)(unaff_BP + -4) = iVar2;
        *(undefined2 *)(unaff_BP + -6) = uVar1;
        if (*(int *)(unaff_BP + -6) != 0 || *(int *)(unaff_BP + -4) != 0) {
          FUN_28eb_4c3f();
          return;
        }
        return;
      }
      uVar1 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0xe) >> 0x10);
      iVar2 = (int)*(undefined4 *)(unaff_BP + -0xe);
      if (*(int *)(iVar2 + 8) == 7) {
        *(int *)(iVar2 + 0x78) = unaff_DI;
      }
      iVar2 = *(int *)(unaff_DI + 10);
      if ((iVar2 != *(int *)(unaff_BP + -0xc)) ||
         (*(int *)(unaff_DI + 8) != *(int *)(unaff_BP + -0xe))) break;
      *(undefined2 *)(unaff_BP + -0xc) = 0;
      *(undefined2 *)(unaff_BP + -0xe) = 0;
    }
    uVar1 = *(undefined2 *)(unaff_BP + -0x12);
    *(undefined2 *)(unaff_BP + -0xc) = *(undefined2 *)(unaff_BP + -0x10);
    *(undefined2 *)(unaff_BP + -0xe) = uVar1;
    unaff_ES = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0x12) >> 0x10);
    in_BX = (int)*(undefined4 *)(unaff_BP + -0x12);
  } while( true );
}

