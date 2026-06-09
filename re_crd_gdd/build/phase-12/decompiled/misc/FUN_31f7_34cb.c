// TIM2.EXE: FUN_31f7_34cb @ file 0x03A63B Ghidra 0x3543B
// Subsystem: misc | Size: 95 bytes


void __cdecl16far FUN_31f7_34cb(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  
  if (DAT_5b41_19c8 == 0) {
    DAT_5b41_19c8 = FUN_4551_0370(DAT_5b41_09e8,3);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = DAT_554c_3ae4;
  if ((0 < *(int *)(iVar2 + 0x10)) && (*(int *)(iVar2 + 0x10) < DAT_5b41_19c8)) {
    uVar1 = DAT_554c_3ae6;
  }
  *(undefined2 *)(iVar2 + 0x7a) = uVar1;
  *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)*(undefined2 *)(iRam000557fc + 0x46);
  FUN_28eb_3670(iVar2,uVar3);
  return;
}

