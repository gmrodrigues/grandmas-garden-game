// TIM2.EXE: FUN_406b_17a9 @ file 0x047059 Ghidra 0x41E59
// Subsystem: sound | Size: 70 bytes


undefined1 __cdecl16far
FUN_406b_17a9(undefined1 *param_1,int param_2,undefined1 param_3,int param_4)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  if (param_2 != 0 || param_1 != (undefined1 *)0x0) {
    param_4 = param_4 * 3;
    do {
      bVar2 = in(0x3da);
    } while ((bVar2 & 8) == 0);
    bVar2 = in(0x3c7);
    if ((bVar2 & 3) != 3) {
      out(0x3c9,bVar2 & 3);
    }
    out(0x3c8,param_3);
    do {
      puVar1 = param_1;
      param_1 = param_1 + 1;
      uVar3 = *puVar1;
      out(0x3c9,uVar3);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return uVar3;
}

