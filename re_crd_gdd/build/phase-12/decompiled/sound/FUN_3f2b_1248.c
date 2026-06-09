// TIM2.EXE: FUN_3f2b_1248 @ file 0x0456F8 Ghidra 0x404F8
// Subsystem: sound | Size: 69 bytes


void __cdecl16near FUN_3f2b_1248(void)

{
  uint uVar1;
  uint *puVar2;
  uint *in_BX;
  uint *puVar3;
  undefined2 unaff_ES;
  
  *in_BX = *in_BX - 1;
  if (in_BX != (uint *)*(undefined2 *)0x4) {
    puVar3 = (uint *)in_BX[1];
    if ((*puVar3 & 1) == 0) {
      *puVar3 = *puVar3 + *in_BX;
      *(undefined2 *)((int)in_BX + *in_BX + 2) = puVar3;
      in_BX = puVar3;
      goto LAB_3f2b_1273;
    }
  }
  FUN_3f2b_12af();
LAB_3f2b_1273:
  puVar3 = (uint *)(*in_BX + (int)in_BX);
  uVar1 = *puVar3;
  if ((uVar1 & 1) != 0) {
    return;
  }
  *in_BX = *in_BX + uVar1;
  *(undefined2 *)((int)puVar3 + uVar1 + 2) = in_BX;
  puVar2 = (uint *)puVar3[3];
  if (puVar3 != puVar2) {
    *(undefined2 *)0x8 = puVar2;
    uVar1 = puVar3[2];
    puVar2[2] = uVar1;
    *(undefined2 *)(uVar1 + 6) = puVar2;
    return;
  }
  *(undefined2 *)0x8 = 0;
  return;
}

