// TIM2.EXE: FUN_4876_077d @ file 0x04E0DD Ghidra 0x48EDD
// Subsystem: misc | Size: 110 bytes


undefined2 __cdecl16far FUN_4876_077d(undefined4 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  
  if (*(int *)((int)param_1 + 0x38) == 0 && *(int *)((int)param_1 + 0x3a) == 0) {
    uVar1 = 2;
    if ((*(int *)((int)param_1 + 0x34) == 0 && *(int *)((int)param_1 + 0x36) == 0) &&
       (1 < *(uint *)((int)param_1 + 0x2c))) {
      *(int *)((int)param_1 + 0x2e) = *(int *)((int)param_1 + 0x2e) + 1;
      if (*(uint *)((int)param_1 + 0x2c) <= *(uint *)((int)param_1 + 0x2e)) {
        *(undefined2 *)((int)param_1 + 0x2e) = 0;
      }
      *(undefined2 *)((int)param_1 + 0x26) = 2;
    }
  }
  else {
    uVar1 = (*(code *)*(undefined2 *)((int)param_1 + 0x38))
                      (0x4876,(int)param_1,param_1._2_2_,param_2);
  }
  return uVar1;
}

