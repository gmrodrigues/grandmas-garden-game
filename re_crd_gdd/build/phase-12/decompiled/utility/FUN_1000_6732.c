// TIM2.EXE: FUN_1000_6732 @ file 0x01B932 Ghidra 0x16732
// Subsystem: utility | Size: 413 bytes


void __cdecl16near
FUN_1000_6732(undefined4 param_1,code *param_2,undefined2 param_3,uint param_4,int param_5)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  uint local_8;
  
  if (param_5 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  uVar1 = *(undefined2 *)((int)*(undefined4 *)0x16 + 6);
  if (DAT_5b41_2a84 != (code *)0x0 || DAT_5b41_2a86 != 0) {
    (*DAT_5b41_2a84)(0x1000,param_2,param_3);
  }
  local_8 = param_4 & 1;
  if ((param_4 & 4) != 0) {
    local_8 = local_8 | 2;
  }
  uVar2 = local_8;
  if (((param_4 & 2) != 0) && (uVar2 = local_8 | 4, (param_4 & 0x100) == 0)) {
    uVar2 = local_8 | 0x24;
  }
  local_8 = uVar2;
  if ((param_4 & 0x20) != 0) {
    local_8 = local_8 | 8;
  }
  if ((param_4 & 0x80) != 0) {
    local_8 = local_8 | 0x10;
  }
  switch(local_8) {
  case 0:
    (*param_2)((undefined2)param_1,uVar3);
    break;
  case 1:
    (*param_2)(0x1000,(undefined2)param_1,uVar3);
    break;
  case 2:
    (*param_2)((undefined2)param_1,param_1._2_2_,uVar3);
    break;
  case 3:
    (*param_2)(0x1000,(undefined2)param_1,param_1._2_2_,uVar3);
    break;
  case 4:
    (*param_2)((undefined2)param_1,uVar3);
    break;
  case 5:
    goto LAB_1000_685f;
  case 6:
    (*param_2)((undefined2)param_1,param_1._2_2_,uVar3);
    break;
  case 7:
    (*param_2)(0x1000,(undefined2)param_1,param_1._2_2_,uVar3);
    break;
  case 8:
    (*param_2)();
    break;
  case 9:
    (*param_2)(0x1000);
    break;
  case 10:
    (*param_2)((undefined2)param_1,param_1._2_2_);
    break;
  case 0xb:
    uVar3 = param_1._2_2_;
LAB_1000_685f:
    (*param_2)(0x1000,(undefined2)param_1,uVar3);
    break;
  case 0x10:
    (*param_2)(uVar3);
    break;
  case 0x11:
    (*param_2)(0x1000,uVar3);
    break;
  case 0x12:
    (*param_2)(uVar3,uVar1);
    break;
  case 0x13:
    (*param_2)(0x1000,uVar3,uVar1);
    break;
  case 0x14:
    (*param_2)(uVar3);
    break;
  case 0x15:
    (*param_2)(0x1000,uVar3);
    break;
  case 0x16:
    (*param_2)(uVar3,uVar1);
    break;
  case 0x17:
    (*param_2)(0x1000,uVar3,uVar1,0x554c);
  }
  return;
}

