// TIM2.EXE: FUN_4340_0849 @ file 0x048E49 Ghidra 0x43C49
// Subsystem: misc | Size: 100 bytes


int __cdecl16far FUN_4340_0849(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_3f2b_0577(param_1,0x554c);
    if (iVar1 != 0) {
      FUN_3f2b_09ca(iVar1,1);
      return iVar1;
    }
    uVar2 = FUN_1000_0b20(param_1,0x3fb2);
    iVar1 = FUN_1000_0c9d(uVar2);
    if (iVar1 == 0) {
      iVar1 = FUN_3f2b_0220(param_1,0x554c,0,0,0,0x993,0x4340);
      return iVar1;
    }
  }
  return 0;
}

