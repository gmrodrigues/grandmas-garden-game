// TIM2.EXE: FUN_1000_4ae6 @ file 0x019CE6 Ghidra 0x14AE6
// Subsystem: utility | Size: 373 bytes


int __cdecl16far FUN_1000_4ae6(undefined2 param_1,uint param_2,uint param_3)

{
  undefined2 uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_4;
  
  uVar1 = uRam0005554e;
  if ((param_2 & 0xc000) == 0) {
    param_2 = param_2 | DAT_554c_593e & 0xc000;
  }
  local_4 = FUN_1000_3c7c(param_1,0);
  uRam0005554e = uVar1;
  if ((param_2 & 0x100) != 0) {
    param_3 = param_3 & DAT_554c_5940;
    if ((param_3 & 0x180) == 0) {
      FUN_1000_1b4b(1);
    }
    if (local_4 == 0xffff) {
      iVar3 = DAT_554c_5944;
      if (DAT_554c_5944 != 2) {
LAB_1000_4b7d:
        iVar3 = FUN_1000_1b4b(iVar3);
        return iVar3;
      }
      local_4 = (uint)((param_3 & 0x80) == 0);
      if ((param_2 & 0xf0) == 0) {
        iVar3 = FUN_1000_4ab3(local_4,param_1);
        if (iVar3 < 0) {
          return iVar3;
        }
        goto LAB_1000_4c1c;
      }
      iVar3 = FUN_1000_4ab3(0,param_1);
      if (iVar3 < 0) {
        return iVar3;
      }
      FUN_1000_3ce9(iVar3);
    }
    else if ((param_2 & 0x400) != 0) {
      iVar3 = 0x50;
      goto LAB_1000_4b7d;
    }
  }
  iVar3 = FUN_1000_4c5b(param_1,param_2);
  if (-1 < iVar3) {
    bVar2 = FUN_1000_312c(iVar3,0);
    if ((bVar2 & 0x80) == 0) {
      if ((param_2 & 0x200) != 0) {
        FUN_1000_4ad0(iVar3);
      }
    }
    else {
      uVar4 = param_2 | 0x2000;
      uVar5 = param_2 & 0x8000;
      param_2 = uVar4;
      if (uVar5 != 0) {
        FUN_1000_312c(iVar3,1,bVar2 | 0x20);
      }
    }
    if ((((local_4 & 1) != 0) && ((param_2 & 0x100) != 0)) && ((param_2 & 0xf0) != 0)) {
      FUN_1000_3c7c(param_1,1,1);
    }
  }
LAB_1000_4c1c:
  if (-1 < iVar3) {
    if ((param_2 & 0x300) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x1000;
    }
    if ((local_4 & 1) == 0) {
      uVar5 = 0x100;
    }
    else {
      uVar5 = 0;
    }
    *(uint *)(iVar3 * 2 + 0x5916) = uVar4 | param_2 & 0xf8ff | uVar5;
  }
  return iVar3;
}

