// TIM2.EXE: FUN_3f2b_1204 @ file 0x0456B4 Ghidra 0x404B4
// Subsystem: sound | Size: 68 bytes


void __cdecl16near FUN_3f2b_1204(void)

{
  byte *in_BX;
  byte *pbVar1;
  undefined2 unaff_ES;
  
  pbVar1 = in_BX;
  if ((byte *)*(undefined2 *)0x4 != in_BX) {
    pbVar1 = *(byte **)(in_BX + 2);
    if ((*pbVar1 & 1) != 0) {
      *(undefined2 *)0x6 = pbVar1;
      pbVar1 = in_BX;
      goto LAB_3f2b_1242;
    }
    if (pbVar1 != (byte *)*(undefined2 *)0x4) {
      FUN_3f2b_128d();
      *(undefined2 *)0x6 = *(undefined2 *)(pbVar1 + 2);
      goto LAB_3f2b_1242;
    }
  }
  *(undefined2 *)0x4 = 0;
  *(undefined2 *)0x6 = 0;
  *(undefined2 *)0x8 = 0;
LAB_3f2b_1242:
  FUN_3f2b_11a0(pbVar1);
  return;
}

