// TIM2.EXE: FUN_31f7_995b @ file 0x040ACB Ghidra 0x3B8CB
// Subsystem: gfx | Size: 169 bytes


void __cdecl16far FUN_31f7_995b(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 2;
  }
  if (3 < *(int *)(iVar2 + 0x10)) {
    iVar1 = iVar1 + 1;
  }
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(iVar1 * 2 + *(int *)(DAT_554c_03b4 + 0x46));
  FUN_28eb_3670(iVar2,uVar3);
  if ((*(byte *)(iVar2 + 0xc) & 0x10) == 0) {
    *(undefined1 *)(iVar2 + 0x7a) = *(undefined1 *)(*(int *)(iVar2 + 0x10) + 0x3c94);
    *(undefined1 *)(iVar2 + 0x5a) = 0x2d;
  }
  else {
    *(undefined1 *)(iVar2 + 0x7a) = *(undefined1 *)(*(int *)(iVar2 + 0x10) + 0x3c9d);
    *(undefined1 *)(iVar2 + 0x5a) = 0x25;
  }
  *(undefined1 *)(iVar2 + 0x7b) = 0xc;
  *(undefined1 *)(iVar2 + 0x5b) = 0x1f;
  *(undefined2 *)(iVar2 + 0x5c) = 7;
  FUN_28eb_2107(*(undefined2 *)(iVar2 + 0x76));
  FUN_28eb_3328(iVar2,uVar3);
  return;
}

