// TIM2.EXE: FUN_4340_0ef6 @ file 0x0494F6 Ghidra 0x442F6
// Subsystem: misc | Size: 70 bytes


byte * __cdecl16far FUN_4340_0ef6(byte *param_1,int param_2,byte *param_3)

{
  byte *pbVar1;
  undefined2 uVar2;
  
  if ((param_1 != (byte *)0x0 || param_2 != 0) && (param_1 < (byte *)param_3)) {
    do {
      pbVar1 = (byte *)param_3 + -1;
      param_3 = (byte *)CONCAT22(param_3._2_2_,pbVar1);
      if (pbVar1 <= param_1) break;
    } while (*param_3 < 0x21);
    while ((param_1 < (byte *)param_3 &&
           (uVar2 = (undefined2)((ulong)param_3 >> 0x10), 0x20 < ((byte *)param_3)[-1]))) {
      param_3 = (byte *)CONCAT22(uVar2,(byte *)param_3 + -1);
    }
  }
  return (byte *)param_3;
}

