// TIM2.EXE: FUN_1000_333d @ file 0x01853D Ghidra 0x1333D
// Subsystem: utility | Size: 66 bytes


void __cdecl16near FUN_1000_333d(void)

{
  uint in_CX;
  int in_DX;
  int iVar1;
  int *in_BX;
  int *piVar2;
  
  if (in_DX + 8U <= in_CX) {
    if (in_BX == DAT_554c_5b52) {
      *in_BX = in_DX;
      *in_BX = *in_BX + 1;
      FUN_1000_2a77(in_DX + (int)in_BX);
    }
    else {
      piVar2 = (int *)((int)in_BX + in_DX);
      piVar2[1] = (int)in_BX;
      iVar1 = in_CX - in_DX;
      *in_BX = *in_BX - iVar1;
      *(undefined2 *)((int)piVar2 + iVar1 + 2) = piVar2;
      *piVar2 = iVar1 + 1;
      FUN_1000_31ae();
    }
  }
  return;
}

