// TIM2.EXE: FUN_1000_63e4 @ file 0x01B5E4 Ghidra 0x163E4
// Subsystem: utility | Size: 750 bytes


void __cdecl16near
FUN_1000_63e4(undefined4 param_1,undefined2 param_2,undefined2 param_3,code *param_4,
             undefined2 param_5,uint param_6)

{
  uint uVar1;
  undefined2 unaff_SS;
  undefined2 uVar2;
  undefined2 uVar3;
  uint local_6;
  
  uVar2 = *(undefined2 *)((int)*(undefined4 *)0x16 + 6);
  local_6 = param_6 & 1;
  if ((param_6 & 4) != 0) {
    local_6 = local_6 | 2;
  }
  uVar1 = local_6;
  if (((param_6 & 2) != 0) && (uVar1 = local_6 | 4, (param_6 & 0x100) == 0)) {
    uVar1 = local_6 | 0x24;
  }
  local_6 = uVar1;
  if ((param_6 & 0x20) != 0) {
    local_6 = local_6 | 8;
  }
  if ((param_6 & 0x80) != 0) {
    local_6 = local_6 | 0x10;
  }
  if ((param_6 & 0x1000) == 0) {
    switch(local_6) {
    case 0:
      (*param_4)((undefined2)param_1,param_2);
      break;
    case 1:
LAB_1000_6547:
      (*param_4)(0x1000,(undefined2)param_1,param_2);
      break;
    case 2:
      (*param_4)((undefined2)param_1,param_1._2_2_,param_2,param_3);
      break;
    case 3:
      (*param_4)(0x1000,(undefined2)param_1,param_1._2_2_,param_2,param_3);
      break;
    case 4:
      uVar2 = param_2;
LAB_1000_6586:
      (*param_4)((undefined2)param_1,uVar2);
      break;
    case 5:
      uVar3 = param_2;
LAB_1000_6594:
      (*param_4)(0x1000,(undefined2)param_1,uVar3);
      break;
    case 6:
    case 10:
LAB_1000_6517:
      (*param_4)((undefined2)param_1,param_1._2_2_,param_2,param_3);
      break;
    case 7:
    case 0xb:
LAB_1000_652a:
      (*param_4)(0x1000,(undefined2)param_1,param_1._2_2_,param_2,param_3);
      break;
    case 8:
      (*param_4)();
      break;
    case 9:
LAB_1000_6501:
      (*param_4)(0x1000);
      break;
    case 0x10:
      (*param_4)(param_2);
      break;
    case 0x11:
      (*param_4)(0x1000,param_2);
      break;
    case 0x12:
      (*param_4)(param_2,param_3,uVar2);
      break;
    case 0x13:
      (*param_4)(0x1000,param_2,param_3,uVar2);
      break;
    case 0x14:
      (*param_4)(param_2);
      break;
    case 0x15:
      (*param_4)(0x1000,param_2);
      break;
    case 0x16:
      (*param_4)(param_2,param_3,uVar2);
      break;
    case 0x17:
      (*param_4)(0x1000,param_2,param_3,uVar2);
    }
  }
  else {
    switch(local_6) {
    case 0:
      (*param_4)((undefined2)param_1,0,param_2);
      break;
    case 1:
      (*param_4)(0x1000,(undefined2)param_1,0,param_2);
      break;
    case 2:
      (*param_4)((undefined2)param_1,param_1._2_2_,0,param_2,param_3);
      break;
    case 3:
      (*param_4)(0x1000,(undefined2)param_1,param_1._2_2_,0,param_2,param_3);
      break;
    case 4:
      (*param_4)((undefined2)param_1,param_2,0);
      break;
    case 5:
      (*param_4)(0x1000,(undefined2)param_1,param_2,0);
      break;
    case 6:
      (*param_4)((undefined2)param_1,param_1._2_2_,param_2,param_3,0);
      break;
    case 7:
      (*param_4)(0x1000,(undefined2)param_1,param_1._2_2_,param_2,param_3,0);
      break;
    case 8:
      (*param_4)();
      break;
    case 9:
      goto LAB_1000_6501;
    case 10:
      goto LAB_1000_6517;
    case 0xb:
      goto LAB_1000_652a;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      break;
    case 0x10:
      (*param_4)(0,param_2);
      break;
    case 0x11:
      param_1._0_2_ = 0;
      goto LAB_1000_6547;
    case 0x12:
      (*param_4)(0,param_2,param_3,uVar2);
      break;
    case 0x13:
      (*param_4)(0x1000,0,param_2,param_3,uVar2);
      break;
    case 0x14:
      uVar2 = 0;
      param_1._0_2_ = param_2;
      goto LAB_1000_6586;
    case 0x15:
      uVar3 = 0;
      param_1._0_2_ = param_2;
      goto LAB_1000_6594;
    case 0x16:
      (*param_4)(param_2,param_3,0,uVar2);
      break;
    case 0x17:
      (*param_4)(0x1000,param_2,param_3,0,uVar2,0x554c);
    }
  }
  return;
}

