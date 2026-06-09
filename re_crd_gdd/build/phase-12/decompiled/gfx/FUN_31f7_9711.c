// TIM2.EXE: FUN_31f7_9711 @ file 0x040881 Ghidra 0x3B681
// Subsystem: gfx | Size: 89 bytes


undefined2 __cdecl16far FUN_31f7_9711(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = *(int *)((int)param_1 + 0x3e);
  if (iVar1 < 2) {
    uVar2 = 0x1400;
  }
  else if (iVar1 < 6) {
    uVar2 = 0x1200;
  }
  else if (iVar1 < 10) {
    uVar2 = 0x1000;
  }
  else if (iVar1 < 0x15) {
    uVar2 = 0xe00;
  }
  else if (iVar1 < 0x79) {
    uVar2 = 0xc00;
  }
  else if (iVar1 < 0x97) {
    uVar2 = 0xa00;
  }
  else if (iVar1 < 0xc9) {
    uVar2 = 0x800;
  }
  else {
    uVar2 = 0x600;
  }
  return uVar2;
}

