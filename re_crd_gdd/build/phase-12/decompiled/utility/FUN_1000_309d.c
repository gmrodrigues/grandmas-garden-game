// TIM2.EXE: FUN_1000_309d @ file 0x01829D Ghidra 0x1309D
// Subsystem: utility | Size: 143 bytes


undefined4 __cdecl16near FUN_1000_309d(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  
  uVar6 = FUN_1000_199b();
  uVar1 = (uint)uVar6 + uRam0005555a;
  iVar2 = uVar1 + param_1;
  uVar1 = (int)((ulong)uVar6 >> 0x10) + (uint)CARRY2((uint)uVar6,uRam0005555a) + param_2 +
          (uint)CARRY2(uVar1,param_1);
  uVar4 = uVar1 < 0xf;
  uVar5 = uVar1 == 0xf;
  if ((int)uVar1 < 0xf) {
LAB_1000_30c8:
    uVar6 = FUN_1000_1a85();
    FUN_1000_1fe5();
    if (((!(bool)uVar4) &&
        (FUN_1000_1fe5(), uVar3 = uRam0005555c, uVar1 = uRam0005555a, (bool)uVar4 || (bool)uVar5))
       && (iVar2 = FUN_1000_2fcc(uVar6), iVar2 != 0)) goto LAB_1000_3126;
  }
  else if ((int)uVar1 < 0x10) {
    uVar4 = iVar2 != -1;
    uVar5 = iVar2 == -1;
    goto LAB_1000_30c8;
  }
  uVar3 = 0xffff;
  uVar1 = 0xffff;
LAB_1000_3126:
  return CONCAT22(uVar3,uVar1);
}

