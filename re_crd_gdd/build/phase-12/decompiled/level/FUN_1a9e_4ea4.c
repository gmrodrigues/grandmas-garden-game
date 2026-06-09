// TIM2.EXE: FUN_1a9e_4ea4 @ file 0x024A84 Ghidra 0x1F884
// Subsystem: level | Size: 98 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl16far FUN_1a9e_4ea4(byte *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while (*param_1 != 0) {
    iVar2 = (uint)*param_1 - (uint)(byte)DAT_554c_431c;
    param_1 = (byte *)CONCAT22(param_1._2_2_,(byte *)param_1 + 1);
    if ((-1 < iVar2) && (iVar2 < (int)(uint)(byte)DAT_554c_4330)) {
      bVar1 = (byte)DAT_554c_42f4;
      if (DAT_5b41_2676 != 0 || DAT_5b41_2678 != 0) {
        bVar1 = *(byte *)((int)_DAT_5b41_2626 + iVar2);
      }
      iVar3 = iVar3 + (uint)bVar1;
    }
  }
  return iVar3;
}

