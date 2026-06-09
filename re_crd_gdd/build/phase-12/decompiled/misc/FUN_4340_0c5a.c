// TIM2.EXE: FUN_4340_0c5a @ file 0x04925A Ghidra 0x4405A
// Subsystem: misc | Size: 85 bytes


int __cdecl16far FUN_4340_0c5a(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if ((byte *)param_1 == (byte *)0x0 && param_1._2_2_ == 0) {
    if ((byte *)param_2 == (byte *)0x0 && param_2._2_2_ == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = -1;
    }
    return iVar2;
  }
  if ((byte *)param_2 == (byte *)0x0 && param_2._2_2_ == 0) {
    return 1;
  }
  do {
    uVar3 = (uint)*param_1;
    param_1 = (byte *)CONCAT22(param_1._2_2_,(byte *)param_1 + 1);
    bVar1 = *param_2;
    param_2 = (byte *)CONCAT22(param_2._2_2_,(byte *)param_2 + 1);
    if (uVar3 == 0) break;
  } while (uVar3 == bVar1);
  return uVar3 - bVar1;
}

