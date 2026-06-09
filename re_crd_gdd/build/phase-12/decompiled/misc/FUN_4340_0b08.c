// TIM2.EXE: FUN_4340_0b08 @ file 0x049108 Ghidra 0x43F08
// Subsystem: misc | Size: 130 bytes


int __cdecl16far FUN_4340_0b08(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  if ((undefined1 *)param_1 == (undefined1 *)0x0 && param_1._2_2_ == 0) {
    if ((undefined1 *)param_2 == (undefined1 *)0x0 && param_2._2_2_ == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = -1;
    }
  }
  else if ((undefined1 *)param_2 == (undefined1 *)0x0 && param_2._2_2_ == 0) {
    iVar3 = 1;
  }
  else {
    if (param_3 != 0) {
      do {
        puVar2 = param_2;
        puVar1 = param_1;
        param_1 = (undefined1 *)CONCAT22(param_1._2_2_,(undefined1 *)param_1 + 1);
        iVar3 = FUN_1000_21ca(*puVar1);
        param_2 = (undefined1 *)CONCAT22(param_2._2_2_,(undefined1 *)param_2 + 1);
        local_4 = FUN_1000_21ca(*puVar2);
        param_3 = param_3 + -1;
        if ((param_3 == 0) || (iVar3 == 0)) break;
      } while (iVar3 == local_4);
    }
    iVar3 = iVar3 - local_4;
  }
  return iVar3;
}

