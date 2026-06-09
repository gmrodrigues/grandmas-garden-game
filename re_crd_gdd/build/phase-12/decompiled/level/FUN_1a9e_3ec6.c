// TIM2.EXE: FUN_1a9e_3ec6 @ file 0x023AA6 Ghidra 0x1E8A6
// Subsystem: level | Size: 74 bytes


int __cdecl16far FUN_1a9e_3ec6(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = 0;
  if (DAT_554c_4f22 != '\0') {
    iVar2 = 0;
    if (DAT_554c_4f2b != 0xffff) {
      uVar5 = 0;
      uVar4 = 1;
      uVar3 = DAT_554c_4f2b;
      while (uVar1 = uVar3 & 1, uVar3 = uVar3 >> 1, uVar1 != 0) {
        uVar4 = uVar4 << 1;
        uVar5 = (uint)(byte)((char)uVar5 + 4);
      }
      *(undefined2 *)(uVar5 + 0x4f6f) = param_3;
      *(undefined2 *)(uVar5 + 0x4f6d) = param_3;
      *(undefined2 *)(uVar5 + 0x4f2d) = param_1;
      *(undefined2 *)(uVar5 + 0x4f2f) = param_2;
      DAT_554c_4f2b = DAT_554c_4f2b | uVar4;
      iVar2 = (uVar5 >> 2) + 1;
    }
  }
  return iVar2;
}

