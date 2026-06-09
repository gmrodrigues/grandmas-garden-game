// TIM2.EXE: FUN_1000_833f @ file 0x01D53F Ghidra 0x1833F
// Subsystem: utility | Size: 258 bytes


void __cdecl16far
FUN_1000_833f(int param_1,undefined2 param_2,int param_3,undefined2 param_4,int param_5,int param_6,
             undefined2 param_7)

{
  undefined2 uVar1;
  int *piVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  int local_10;
  int local_e;
  undefined4 local_6;
  
  lVar6 = CONCAT22(param_6,param_5);
  uVar1 = *(undefined2 *)(param_3 + 8);
  piVar2 = (int *)*(int *)(param_3 + 6);
  local_6 = (int *)CONCAT22(uVar1,piVar2);
  uVar3 = piVar2[0xd];
  if (param_5 == 0 && param_6 == 0) {
    lVar6 = FUN_1000_1fce();
  }
  lVar7 = FUN_1000_18f4(lVar6,uVar3,0);
  lVar8 = FUN_1000_1fce();
  uVar4 = lVar6 - lVar8;
  iVar5 = FUN_1000_1fce();
  param_1 = iVar5 + param_1;
  if (uVar4 == 0) goto LAB_1000_8429;
  while( true ) {
    FUN_1000_8074(param_1,param_2,piVar2,uVar1,uVar4,1,param_7);
LAB_1000_8429:
    local_e = (int)((ulong)lVar7 >> 0x10);
    local_10 = (int)lVar7;
    if (lVar7 == 0) break;
    param_1 = param_1 - *local_6;
    uVar4 = (ulong)uVar3;
    lVar7 = CONCAT22(local_e - (uint)(local_10 == 0),local_10 + -1);
  }
  return;
}

