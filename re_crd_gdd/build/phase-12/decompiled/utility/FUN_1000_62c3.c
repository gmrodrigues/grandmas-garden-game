// TIM2.EXE: FUN_1000_62c3 @ file 0x01B4C3 Ghidra 0x162C3
// Subsystem: utility | Size: 82 bytes


int __cdecl16far FUN_1000_62c3(uint param_1)

{
  uint *puVar1;
  int iVar2;
  undefined2 unaff_SS;
  
  iVar2 = FUN_1000_3226(param_1,0x554c);
  if (iVar2 == 0) {
    if ((0x80 < param_1) || ((*(byte *)((int)*(undefined4 *)0x16 + 4) & 1) != 0)) {
      FUN_1000_143a();
    }
    puVar1 = (uint *)((int)*(undefined4 *)0x16 + 4);
    *puVar1 = *puVar1 | 1;
    iVar2 = *(int *)((int)*(undefined4 *)0x16 + 0x1c);
  }
  return iVar2;
}

