// TIM2.EXE: FUN_406b_1765 @ file 0x047015 Ghidra 0x41E15
// Subsystem: sound | Size: 68 bytes


void __cdecl16far FUN_406b_1765(undefined1 *param_1,int param_2,undefined1 param_3,int param_4)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  
  if (param_2 != 0 || param_1 != (undefined1 *)0x0) {
    param_4 = param_4 * 3;
    do {
      bVar2 = in(0x3da);
    } while ((bVar2 & 8) == 0);
    bVar2 = in(0x3c7);
    if ((bVar2 & 3) != 0) {
      in(0x3c9);
    }
    out(0x3c7,param_3);
    do {
      uVar3 = in(0x3c9);
      puVar1 = param_1;
      param_1 = param_1 + 1;
      *puVar1 = uVar3;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

