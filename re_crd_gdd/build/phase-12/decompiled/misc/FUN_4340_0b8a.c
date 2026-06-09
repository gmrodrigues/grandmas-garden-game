// TIM2.EXE: FUN_4340_0b8a @ file 0x04918A Ghidra 0x43F8A
// Subsystem: misc | Size: 107 bytes


int __cdecl16far FUN_4340_0b8a(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
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
    do {
      puVar2 = param_2;
      puVar1 = param_1;
      param_1 = (undefined1 *)CONCAT22(param_1._2_2_,(undefined1 *)param_1 + 1);
      iVar3 = FUN_1000_21ca(*puVar1);
      param_2 = (undefined1 *)CONCAT22(param_2._2_2_,(undefined1 *)param_2 + 1);
      iVar4 = FUN_1000_21ca(*puVar2);
      if (iVar3 == 0) break;
    } while (iVar3 == iVar4);
    iVar3 = iVar3 - iVar4;
  }
  return iVar3;
}

