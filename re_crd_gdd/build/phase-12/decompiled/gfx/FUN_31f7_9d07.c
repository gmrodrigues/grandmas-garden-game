// TIM2.EXE: FUN_31f7_9d07 @ file 0x040E77 Ghidra 0x3BC77
// Subsystem: gfx | Size: 158 bytes


void __cdecl16far FUN_31f7_9d07(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = (uint)((*(byte *)(iVar2 + 0xc) & 0x20) != 0);
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(uVar1 * 2 + *(int *)(DAT_554c_03b6 + 0x46));
  FUN_28eb_3670(iVar2,uVar3,uVar1);
  if ((*(byte *)(iVar2 + 0xc) & 0x20) == 0) {
    *(undefined1 *)(iVar2 + 0x7b) = *(undefined1 *)(*(int *)(iVar2 + 0x10) + 0x3cb2);
    *(undefined1 *)(iVar2 + 0x5b) = 0x39;
  }
  else {
    *(undefined1 *)(iVar2 + 0x7b) = *(undefined1 *)(*(int *)(iVar2 + 0x10) + 0x3cbb);
    *(undefined1 *)(iVar2 + 0x5b) = 0xc;
  }
  *(undefined1 *)(iVar2 + 0x7a) = 0xb;
  *(undefined1 *)(iVar2 + 0x5a) = 10;
  *(undefined2 *)(iVar2 + 0x5c) = 7;
  FUN_28eb_2107(*(undefined2 *)(iVar2 + 0x76));
  FUN_28eb_3328(iVar2,uVar3);
  return;
}

