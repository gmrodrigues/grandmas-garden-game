// TIM2.EXE: FUN_1000_31ae @ file 0x0183AE Ghidra 0x131AE
// Subsystem: utility | Size: 57 bytes


void __cdecl16near FUN_1000_31ae(void)

{
  uint uVar1;
  uint *puVar2;
  uint *in_BX;
  uint *puVar3;
  
  *in_BX = *in_BX - 1;
  if (in_BX != DAT_554c_5b50) {
    puVar3 = (uint *)in_BX[1];
    if ((*puVar3 & 1) == 0) {
      *puVar3 = *puVar3 + *in_BX;
      *(undefined2 *)((int)in_BX + *in_BX + 2) = puVar3;
      in_BX = puVar3;
      goto LAB_1000_31d1;
    }
  }
  FUN_1000_3203();
LAB_1000_31d1:
  puVar3 = (uint *)(*in_BX + (int)in_BX);
  uVar1 = *puVar3;
  if ((uVar1 & 1) != 0) {
    return;
  }
  *in_BX = *in_BX + uVar1;
  *(undefined2 *)((int)puVar3 + uVar1 + 2) = in_BX;
  puVar2 = (uint *)puVar3[3];
  if (puVar3 != puVar2) {
    uVar1 = puVar3[2];
    DAT_554c_5b54 = puVar2;
    puVar2[2] = uVar1;
    *(undefined2 *)(uVar1 + 6) = puVar2;
    return;
  }
  DAT_554c_5b54 = (uint *)0x0;
  return;
}

