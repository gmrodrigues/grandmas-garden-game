// TIM2.EXE: FUN_1000_6e27 @ file 0x01C027 Ghidra 0x16E27
// Subsystem: utility | Size: 133 bytes


undefined2 __cdecl16far
FUN_1000_6e27(int param_1,undefined2 param_2,undefined2 param_3,undefined2 *param_4)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 unaff_SS;
  bool bVar3;
  
  bVar3 = (*(byte *)(param_1 + 4) & 6) != 0;
  for (puVar2 = (undefined2 *)*(undefined2 *)0x14;
      (puVar2 != (undefined2 *)0xffff && (puVar2 != param_4)); puVar2 = (undefined2 *)*puVar2) {
    iVar1 = (*(code *)puVar2[1])(0x1000,param_1);
    if (iVar1 == 0) {
      return 0;
    }
    if (bVar3) {
      *(undefined2 *)0x14 = puVar2;
    }
  }
  if (bVar3) {
    *(undefined2 *)0x14 = puVar2;
  }
  return 1;
}

