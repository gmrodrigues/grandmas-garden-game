// TIM2.EXE: FUN_1000_5494 @ file 0x01A694 Ghidra 0x15494
// Subsystem: utility | Size: 64 bytes


int __cdecl16far FUN_1000_5494(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  do {
    do {
      pbVar1 = param_1;
      param_1 = param_1 + 1;
      bVar2 = *pbVar1;
      bVar3 = *param_2;
      uVar5 = (uint)bVar3;
      uVar4 = (uint)bVar2;
      if (bVar2 == 0) goto LAB_1000_54ce;
      pbVar1 = param_2;
      param_2 = param_2 + 1;
    } while (bVar2 == *pbVar1);
    if ((0x60 < bVar2) && (bVar2 < 0x7b)) {
      uVar4 = (uint)(byte)(bVar2 - 0x20);
    }
    if ((0x60 < bVar3) && (bVar3 < 0x7b)) {
      uVar5 = (uint)(byte)(bVar3 - 0x20);
    }
  } while ((char)uVar4 == (char)uVar5);
LAB_1000_54ce:
  return uVar4 - uVar5;
}

