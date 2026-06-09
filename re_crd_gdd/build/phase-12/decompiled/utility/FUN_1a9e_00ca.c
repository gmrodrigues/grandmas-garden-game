// TIM2.EXE: FUN_1a9e_00ca @ file 0x01FCAA Ghidra 0x1AAAA
// Subsystem: utility | Size: 103 bytes


undefined2 __cdecl16near FUN_1a9e_00ca(undefined2 param_1,undefined2 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  while ((param_3 != 0 && (0 < iVar2))) {
    uVar1 = param_3;
    if (0x32 < param_3) {
      uVar1 = 0x32;
    }
    iVar2 = FUN_1000_0d10(0x5f60,1,uVar1,DAT_5b41_0047);
    param_3 = param_3 - iVar2;
    FUN_1000_05ea(param_1,param_2,0x5f60,0x554c,iVar2);
    FUN_1000_1a00(iVar2,0x1000);
  }
  return 0;
}

