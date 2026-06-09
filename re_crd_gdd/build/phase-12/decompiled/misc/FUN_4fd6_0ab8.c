// TIM2.EXE: FUN_4fd6_0ab8 @ file 0x055A18 Ghidra 0x50818
// Subsystem: misc | Size: 282 bytes


int __cdecl16far FUN_4fd6_0ab8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int in_DX;
  uint uVar5;
  
  uVar2 = uRam00050008;
  if ((*(byte *)0x10 & 2) == 0) {
    bVar1 = false;
    iVar3 = FUN_4fd6_0ed0();
    if (iVar3 == 0 && in_DX == 0) {
LAB_4fd6_0adf:
      iVar3 = -1;
    }
    else {
      while( true ) {
        if ((param_2 < *(uint *)0x3c) || ((param_2 == *(uint *)0x3c && (param_1 < *(uint *)0x3a))))
        {
          param_2 = *(uint *)0x3c;
          param_1 = *(uint *)0x3a;
        }
        if ((*(uint *)0x40 < param_2) || ((*(uint *)0x40 <= param_2 && (*(uint *)0x3e < param_1))))
        goto LAB_4fd6_0adf;
        uVar4 = *(uint *)0x3e - param_1;
        uVar5 = (*(int *)0x40 - param_2) - (uint)(*(uint *)0x3e < param_1);
        if ((param_3 != 0 || param_4 != 0) &&
           ((param_4 <= uVar5 && ((param_4 < uVar5 || (*(uint *)0x3e < uVar4)))))) {
          uVar4 = param_3;
          uVar5 = param_4;
        }
        if ((*(uint *)0x57a4 <= uVar5) && ((*(uint *)0x57a4 < uVar5 || (*(uint *)0x57a2 < uVar4))))
        {
          uVar5 = *(uint *)0x57a4;
          uVar4 = *(uint *)0x57a2;
        }
        if ((uVar5 == 0) && (uVar4 >> 4 < *(uint *)0x11a)) goto LAB_4fd6_0adf;
        *(uint *)0x130 = param_1;
        *(uint *)0x132 = param_2;
        *(int *)0x134 = uVar4 + param_1;
        *(int *)0x136 = uVar5 + param_2 + (uint)CARRY2(uVar4,param_1);
        *(uint *)0x138 = param_1;
        *(uint *)0x13a = param_2;
        iVar3 = FUN_4fd6_1080(uVar4,uVar5,param_1,param_2);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (bVar1) break;
        bVar1 = true;
        param_3 = uVar4;
        param_4 = uVar5;
      }
      *(undefined2 *)0x13c = 0xc01;
      *(undefined2 *)0x13e = 0;
      *(undefined2 *)0x112 = 1;
      *(byte *)0x10 = *(byte *)0x10 | 1;
      *(undefined2 *)0x82 = 0x1158;
      *(undefined2 *)0x80 = 0xd14;
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

