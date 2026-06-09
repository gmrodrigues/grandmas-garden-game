// TIM2.EXE: FUN_1000_554f @ file 0x01A74F Ghidra 0x1554F
// Subsystem: utility | Size: 444 bytes


void __cdecl16far FUN_1000_554f(void)

{
  char *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_4;
  
  pcVar1 = (char *)FUN_1000_498c(0x5e2e);
  if (((((pcVar1 == (char *)0x0) || (uVar2 = FUN_1000_54d4(pcVar1), uVar2 < 4)) ||
       ((*(byte *)(*pcVar1 + 0x59c1) & 0xc) == 0)) ||
      ((((*(byte *)(pcVar1[1] + 0x59c1) & 0xc) == 0 || ((*(byte *)(pcVar1[2] + 0x59c1) & 0xc) == 0))
       || ((pcVar1[3] != '-' && ((pcVar1[3] != '+' && ((*(byte *)(pcVar1[3] + 0x59c1) & 2) == 0)))))
       ))) || (((*(byte *)(pcVar1[3] + 0x59c1) & 2) == 0 &&
               ((*(byte *)(pcVar1[4] + 0x59c1) & 2) == 0)))) {
    DAT_554c_5e2c = 1;
    DAT_554c_5e2a = 0;
    DAT_554c_5e28 = 18000;
    FUN_1000_5472(DAT_554c_5e24,0x5e31);
    FUN_1000_5472(DAT_554c_5e26,0x5e35);
    uVar3 = CONCAT22(DAT_554c_5e2a,DAT_554c_5e28);
  }
  else {
    FUN_1000_4a32(DAT_554c_5e26,0,4);
    FUN_1000_54f0(DAT_554c_5e24,pcVar1,3);
    *(undefined1 *)(DAT_554c_5e24 + 3) = 0;
    FUN_1000_3bfb(pcVar1 + 3);
    uVar3 = FUN_1000_1fce();
    DAT_554c_5e2a = (undefined2)((ulong)uVar3 >> 0x10);
    DAT_554c_5e28 = (undefined2)uVar3;
    DAT_554c_5e2c = 0;
    for (local_4 = 3; pcVar1[local_4] != '\0'; local_4 = local_4 + 1) {
      if ((*(byte *)(pcVar1[local_4] + 0x59c1) & 0xc) != 0) {
        uVar2 = FUN_1000_54d4(pcVar1 + local_4);
        uVar3 = CONCAT22(DAT_554c_5e2a,DAT_554c_5e28);
        if (((2 < uVar2) &&
            (uVar3 = CONCAT22(DAT_554c_5e2a,DAT_554c_5e28),
            (*(byte *)(pcVar1[local_4 + 1] + 0x59c1) & 0xc) != 0)) &&
           (uVar3 = CONCAT22(DAT_554c_5e2a,DAT_554c_5e28),
           (*(byte *)(pcVar1[local_4 + 2] + 0x59c1) & 0xc) != 0)) {
          FUN_1000_54f0(DAT_554c_5e26,pcVar1 + local_4,3);
          *(undefined1 *)(DAT_554c_5e26 + 3) = 0;
          uVar3 = CONCAT22(DAT_554c_5e2a,DAT_554c_5e28);
          DAT_554c_5e2c = 1;
        }
        break;
      }
    }
  }
  DAT_554c_5e2a = (undefined2)((ulong)uVar3 >> 0x10);
  DAT_554c_5e28 = (undefined2)uVar3;
  return;
}

