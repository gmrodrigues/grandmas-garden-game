// TIM2.EXE: FUN_4340_2080 @ file 0x04A680 Ghidra 0x45480
// Subsystem: misc | Size: 62 bytes


undefined2 __cdecl16far FUN_4340_2080(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 local_4;
  
  FUN_4340_08dd(*(undefined2 *)((int)param_1 + 2));
  iVar1 = FUN_1a9e_5320(param_2,0,&local_4);
  if (iVar1 != 0) {
    return local_4;
  }
  uVar2 = FUN_4340_09cc(0);
  return uVar2;
}

