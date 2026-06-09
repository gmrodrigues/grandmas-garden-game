// TIM2.EXE: FUN_4340_154e @ file 0x049B4E Ghidra 0x4494E
// Subsystem: misc | Size: 180 bytes


int __cdecl16far
FUN_4340_154e(undefined2 *param_1,byte *param_2,int param_3,undefined2 *param_4,undefined2 *param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 local_6;
  
  if ((((undefined2 *)param_1 == (undefined2 *)0x0 && param_1._2_2_ == 0) ||
      (param_2 == (byte *)0x0 && param_3 == 0)) ||
     (((undefined2 *)param_1)[8] == 0 && ((undefined2 *)param_1)[9] == 0)) {
    iVar2 = 0;
  }
  else {
    iVar3 = FUN_4340_1eea(*param_1);
    iVar2 = 0;
    local_6 = (byte *)CONCAT22(param_3,param_2);
    while (0x20 < *local_6) {
      iVar2 = iVar2 + 1;
      local_6 = (byte *)CONCAT22(local_6._2_2_,(byte *)local_6 + 1);
    }
    bVar1 = *local_6;
    *local_6 = 0;
    if (param_4 != (undefined2 *)0x0) {
      uVar4 = (*(code *)*(undefined2 *)(iVar3 + 0x10))
                        (0x4340,(undefined2 *)param_1,param_1._2_2_,param_2,param_3);
      *param_4 = uVar4;
    }
    if (param_5 != (undefined2 *)0x0) {
      uVar4 = (*(code *)*(undefined2 *)(iVar3 + 0x14))
                        (0x4340,(undefined2 *)param_1,param_1._2_2_,param_2,param_3);
      *param_5 = uVar4;
    }
    *local_6 = bVar1;
  }
  return iVar2;
}

