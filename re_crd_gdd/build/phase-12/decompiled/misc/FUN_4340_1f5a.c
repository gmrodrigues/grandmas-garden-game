// TIM2.EXE: FUN_4340_1f5a @ file 0x04A55A Ghidra 0x4535A
// Subsystem: misc | Size: 240 bytes


void __cdecl16far
FUN_4340_1f5a(undefined4 param_1,undefined2 param_2,undefined2 param_3,uint param_4)

{
  undefined2 uVar1;
  int iVar2;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  iVar2 = FUN_4340_167e((int)param_1,param_1._2_2_,param_2,param_3,&local_a);
  uVar1 = DAT_554c_42d6;
  if (iVar2 != 0) {
    if ((param_4 & 2) == 0) {
      DAT_554c_42ce = *(char *)((int)param_1 + 0xe);
    }
    else {
      DAT_554c_42d6 = DAT_554c_42d8;
      iVar2 = local_a;
      do {
        DAT_554c_42ce = FUN_1a9e_5d60(iVar2,local_8);
        iVar2 = iVar2 + 1;
      } while ((int)DAT_554c_42ce == *(int *)((int)param_1 + 0xe));
    }
    DAT_554c_42d6 = uVar1;
    if ((param_4 & 1) == 0) {
      FUN_1a9e_5722(local_a + -1,local_8,local_a + -1,local_8 + local_4 + -1);
      FUN_1a9e_5722(local_a + -2,local_8 + -1,local_a,local_8 + -1);
      FUN_1a9e_5722(local_a + -2,local_8 + local_4 + -1,local_a,local_8 + local_4 + -1);
    }
    else {
      DAT_554c_42cc = 0;
      FUN_1a9e_3854(local_a + -1,local_8 + -1,local_6 + 1,local_4 + 1);
    }
  }
  return;
}

