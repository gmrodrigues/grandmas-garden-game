// TIM2.EXE: FUN_2424_000c @ file 0x02944C Ghidra 0x2424C
// Subsystem: misc | Size: 422 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_2424_000c(void)

{
  int iVar1;
  int in_DX;
  int extraout_DX;
  char *pcVar2;
  
  FUN_406b_03cb(0xfffd,0);
  pcVar2 = (char *)0x406b;
  FUN_406b_0a39();
  if ((_DAT_5b41_1b88 & 4) != 0) {
    _DAT_5b41_1b88 = _DAT_5b41_1b88 | 2;
  }
  if (((_DAT_5b41_1b88 | DAT_5b41_1b8a) & 6) != 0) {
    DAT_5b41_1b84 = DAT_5b41_1b80;
    DAT_5b41_1b86 = DAT_5b41_1b82;
  }
  if (DAT_5b41_1b9c != 0) {
    DAT_5b41_04f9 = 1;
  }
  if ((DAT_5b41_1b98 != 0) && ((iRam000557bc != 3 || (iRam000557c0 != 0)))) {
    if ((DAT_5b41_0937 != 0x2000) && (DAT_5b41_0939 != 9)) {
      pcVar2 = (char *)s_SIGNIN_RES_554c_3111 + 10;
      iVar1 = FUN_311b_033a(0);
      if (iVar1 != 0) goto LAB_2424_0088;
    }
    DAT_5b41_1b86 = DAT_554c_49ac;
  }
LAB_2424_0088:
  if (((DAT_5b41_1b9e != 0 || DAT_5b41_1ba0 != 0) || (DAT_5b41_1ba2 != 0 || DAT_5b41_1ba4 != 0)) &&
     (((_DAT_5b41_1b88 | DAT_5b41_1b8a) & 2) != 0)) {
    FUN_406b_03cb(0x28,0xffff);
    FUN_406b_03cb(0xfffd,0);
    do {
    } while( true );
  }
  if ((DAT_5b41_1b9e != 0 || DAT_5b41_1ba0 != 0) && ((DAT_5b41_1b9c != 0 || (DAT_5b41_04f9 != 0))))
  {
    if (DAT_5b41_1ae2 != 0 || DAT_5b41_1ae4 != 0) {
      if (*(int *)(DAT_5b41_1ae2 + 0x20) != 0 || *(int *)(DAT_5b41_1ae2 + 0x22) != 0) {
        (*(code *)*(undefined2 *)(DAT_5b41_1ae2 + 0x20))(pcVar2,DAT_5b41_1ae2,DAT_5b41_1ae4,2);
        in_DX = extraout_DX;
      }
      _DAT_5b41_1ae2 = 0;
    }
  }
  if (((DAT_5b41_1b9e == 0 && DAT_5b41_1ba0 == 0) && (DAT_5b41_1ba2 == 0 && DAT_5b41_1ba4 == 0)) &&
     ((DAT_5b41_1b94 & 1) != 0)) {
    if (DAT_5b41_1b90 == 0x1f) {
      iVar1 = FUN_460e_0f42(15000);
      if (iVar1 == 0 && in_DX == 0) {
        iVar1 = FUN_2e67_072c(3000,0xffff);
        FUN_2e67_072c(3000,iVar1 == 0);
      }
    }
    else if ((DAT_5b41_1b90 == 0x32) && (iVar1 = FUN_460e_0f42(15000), iVar1 == 0 && in_DX == 0)) {
      iVar1 = FUN_2e67_072c(1000,0xffff);
      iVar1 = FUN_2e67_072c(1000,iVar1 == 0);
      if (iVar1 == 0) {
        FUN_2e67_045f(DAT_5b41_0755,0,0,1);
        return;
      }
    }
  }
  return;
}

