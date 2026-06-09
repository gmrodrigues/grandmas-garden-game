// TIM2.EXE: FUN_1000_91ee @ file 0x01E3EE Ghidra 0x191EE
// Subsystem: utility | Size: 197 bytes


void __cdecl16near FUN_1000_91ee(byte param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  DAT_554c_5e52 = param_1;
  uVar1 = FUN_1000_913e();
  DAT_554c_5e54 = (char)((uint)uVar1 >> 8);
  if ((byte)uVar1 != DAT_554c_5e52) {
    FUN_1000_913e();
    uVar1 = FUN_1000_913e();
    DAT_554c_5e52 = (byte)uVar1;
    DAT_554c_5e54 = (char)((uint)uVar1 >> 8);
  }
  if (((DAT_554c_5e52 < 4) || (0x3f < DAT_554c_5e52)) || (DAT_554c_5e52 == 7)) {
    DAT_554c_5e55 = 0;
  }
  else {
    DAT_554c_5e55 = 1;
  }
  if (DAT_554c_5e52 == 0x40) {
    DAT_554c_5e53 = DAT_0000_0484 + '\x01';
  }
  else {
    DAT_554c_5e53 = '\x19';
  }
  if (DAT_554c_5e52 != 7) {
    iVar2 = FUN_1000_90fe(0x5e5d,0xffea,0xf000);
    if (iVar2 == 0) {
      iVar2 = FUN_1000_912c();
      if (iVar2 == 0) {
        DAT_554c_5e56 = 1;
        goto LAB_1000_927c;
      }
    }
  }
  DAT_554c_5e56 = 0;
LAB_1000_927c:
  if (DAT_554c_5e52 == 7) {
    DAT_554c_5e59 = 0xb000;
  }
  else {
    DAT_554c_5e59 = 0xb800;
  }
  DAT_554c_5e57 = 0;
  DAT_554c_5e4d = 0;
  DAT_554c_5e4c = 0;
  DAT_554c_5e4e = DAT_554c_5e54 + -1;
  DAT_554c_5e4f = DAT_554c_5e53 + -1;
  return;
}

