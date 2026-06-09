// TIM2.EXE: FUN_1000_1ae8 @ file 0x016CE8 Ghidra 0x11AE8
// Subsystem: utility | Size: 47 bytes


uint __cdecl16far FUN_1000_1ae8(void)

{
  uint uVar1;
  uint uVar2;
  uint in_AX;
  uint uVar3;
  uint *in_BX;
  undefined2 unaff_ES;
  
  uVar3 = in_AX + *in_BX;
  if (!CARRY2(in_AX,*in_BX)) {
    uVar2 = in_BX[1];
    LOCK();
    uVar1 = *in_BX;
    *in_BX = uVar3 & 0xf;
    UNLOCK();
    LOCK();
    in_BX[1] = (uVar3 >> 4) + uVar2;
    UNLOCK();
    return uVar1;
  }
  uVar2 = in_BX[1];
  LOCK();
  uVar1 = *in_BX;
  *in_BX = uVar3 & 0xf;
  UNLOCK();
  LOCK();
  in_BX[1] = (uVar3 >> 4) + uVar2 + 0x1000;
  UNLOCK();
  return uVar1;
}

