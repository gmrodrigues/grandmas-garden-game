// TIM2.EXE: FUN_31f7_0867 @ file 0x0379D7 Ghidra 0x327D7
// Subsystem: misc | Size: 214 bytes


void __cdecl16far FUN_31f7_0867(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  if (DAT_5b41_195a == 0) {
    DAT_5b41_1958 = 0;
    DAT_5b41_195a = FUN_4551_0370(DAT_5b41_09b6,2);
    DAT_5b41_195c = FUN_4551_0370(DAT_5b41_09b6,4);
    DAT_5b41_195e = FUN_4551_0370(DAT_5b41_09b6,5);
  }
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x10) == DAT_5b41_1958) {
    DAT_554c_3a08 = 0;
  }
  else if (*(int *)(iVar1 + 0x10) == DAT_5b41_195a) {
    DAT_554c_3a08 = 1;
  }
  else if (*(int *)(iVar1 + 0x10) == DAT_5b41_195c) {
    DAT_554c_3a08 = 2;
  }
  else {
    DAT_554c_3a08 = 3;
  }
  *(undefined1 *)(iVar1 + 0x7a) = ((undefined1 *)&DAT_554c_3a0a)[DAT_554c_3a08 * 2];
  *(undefined1 *)(iVar1 + 0x7b) = ((undefined1 *)&DAT_554c_3a0b)[DAT_554c_3a08 * 2];
  *(undefined2 *)(iVar1 + 0x98) =
       *(undefined2 *)
        (*(int *)(*(int *)(*(int *)(iVar1 + 8) * 2 + 0x302) + 0x46) + DAT_554c_3a08 * 2);
  FUN_28eb_3670(iVar1,uVar2);
  return;
}

