// TIM2.EXE: FUN_1a9e_5c44 @ file 0x025824 Ghidra 0x20624
// Subsystem: level | Size: 90 bytes


void __cdecl16far
FUN_1a9e_5c44(undefined2 param_1,undefined2 param_2,undefined1 param_3,uint param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 *puVar5;
  bool bVar6;
  undefined2 *puVar7;
  
  do {
    uVar1 = 32000;
    if (param_5 == 0) {
      if (param_4 == 0) {
        return;
      }
      if ((int)param_4 < 0x7d01) {
        uVar1 = param_4;
      }
    }
    uVar4 = uVar1;
    puVar7 = (undefined2 *)FUN_1a9e_5aa5();
    uVar3 = (undefined2)((ulong)puVar7 >> 0x10);
    puVar5 = (undefined2 *)puVar7;
    if (9 < (int)uVar1) {
      if ((POPCOUNT((uint)puVar5 & 0xff) & 1U) != 0) {
        puVar5 = (undefined2 *)((int)puVar5 + 1);
        *(undefined1 *)puVar7 = param_3;
        uVar1 = uVar1 - 1;
      }
      for (uVar2 = uVar1 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
        puVar7 = puVar5;
        puVar5 = puVar5 + 1;
        *puVar7 = CONCAT11(param_3,param_3);
      }
      uVar1 = (uint)((uVar1 & 1) != 0);
    }
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      puVar7 = puVar5;
      puVar5 = (undefined2 *)((int)puVar5 + 1);
      *(undefined1 *)puVar7 = param_3;
    }
    bVar6 = param_4 < uVar4;
    param_4 = param_4 - uVar4;
    param_5 = param_5 - (uint)bVar6;
  } while( true );
}

