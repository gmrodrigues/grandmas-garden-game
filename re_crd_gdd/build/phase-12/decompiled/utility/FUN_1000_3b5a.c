// TIM2.EXE: FUN_1000_3b5a @ file 0x018D5A Ghidra 0x13B5A
// Subsystem: utility | Size: 139 bytes


undefined1 * FUN_1000_3b5a(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = FUN_1000_3be5(param_2,0);
  if (iVar1 == 0) {
    FUN_1000_5472((undefined1 *)&DAT_5b41_2a20,param_2);
    iVar1 = FUN_1000_4526(0,(undefined1 *)&DAT_5b41_2a20,0x50);
    if (iVar1 != 0) {
      FUN_1000_5472((undefined1 *)&DAT_5b41_2a20,iVar1);
      FUN_1000_3157(iVar1);
    }
    puVar2 = (undefined1 *)&DAT_5b41_2a20;
  }
  else {
    FUN_1000_5189(param_2,0x5b8a,(undefined1 *)&DAT_5b41_2a20);
    if (DAT_5b41_2a20 == '\0') {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      puVar2 = (undefined1 *)&DAT_5b41_2a20;
    }
  }
  return puVar2;
}

