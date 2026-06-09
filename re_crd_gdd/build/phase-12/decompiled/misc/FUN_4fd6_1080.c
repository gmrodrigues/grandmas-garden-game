// TIM2.EXE: FUN_4fd6_1080 @ file 0x055FE0 Ghidra 0x50DE0
// Subsystem: misc | Size: 215 bytes


undefined2 __stdcall16far FUN_4fd6_1080(uint param_1,int param_2,uint param_3,int param_4)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar1 = uRam00050008;
  if ((*(byte *)0x42 & 1) != 0) {
    if ((*(byte *)0x42 & 2) != 0) {
      return 0;
    }
    *(byte *)0x42 = *(byte *)0x42 | 2;
    if (*(int *)0x43 == 0 && *(int *)0x45 == 0) {
      *(uint *)0x3a = param_3;
      *(int *)0x3c = param_4;
      DAT_5468_002f = uRam00000064;
      DAT_5468_0031 = uRam00000066;
      uRam00000064 = 0x3f;
      uRam00000066 = 0x5468;
      DAT_5468_003a = param_3;
      DAT_5468_003c = (undefined1)param_4;
      iVar2 = param_3 + param_1;
      iVar3 = param_4 + param_2 + (uint)CARRY2(param_3,param_1);
      DAT_5468_002e = (undefined1)iVar3;
      DAT_5468_002c = iVar2;
LAB_4fd6_1143:
      *(int *)0x3e = iVar2;
      *(int *)0x40 = iVar3;
      return 0;
    }
    uVar4 = 0x400;
    uVar5 = (*(code *)*(undefined2 *)0x43)(0x5000);
    if ((int)uVar5 != 0) {
      *(undefined2 *)0x47 = (int)((ulong)uVar5 >> 0x10);
      uVar5 = (*(code *)*(undefined2 *)0x43)(0x5000);
      iVar3 = (int)((ulong)uVar5 >> 0x10);
      if ((int)uVar5 != 0) {
        *(uint *)0x3a = uVar4;
        *(int *)0x3c = iVar3;
        *(uint *)0x49 = uVar4;
        *(int *)0x4b = iVar3;
        iVar2 = uVar4 + param_1;
        iVar3 = iVar3 + param_2 + (uint)CARRY2(uVar4,param_1);
        goto LAB_4fd6_1143;
      }
    }
  }
  return 0xffff;
}

