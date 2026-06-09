// TIM2.EXE: FUN_1000_4099 @ file 0x019299 Ghidra 0x14099
// Subsystem: utility | Size: 180 bytes


int FUN_1000_4099(uint param_1,undefined2 param_2,undefined2 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined2 local_6;
  uint local_4;
  
  iVar2 = FUN_1000_3fcc(&local_6,&local_4,param_2);
  *(int *)(param_4 + 2) = iVar2;
  if (iVar2 == 0) {
LAB_1000_40de:
    *(undefined1 *)(param_4 + 4) = 0xff;
    *(undefined2 *)(param_4 + 2) = 0;
  }
  else {
    if (*(char *)(param_4 + 4) < '\0') {
      cVar1 = FUN_1000_4ae6(param_3,local_4 | param_1,local_6);
      *(char *)(param_4 + 4) = cVar1;
      if (cVar1 < '\0') goto LAB_1000_40de;
    }
    iVar2 = FUN_1000_1b9d((int)*(char *)(param_4 + 4));
    if (iVar2 != 0) {
      *(uint *)(param_4 + 2) = *(uint *)(param_4 + 2) | 0x200;
    }
    iVar2 = FUN_1000_52a4(param_4,0,(*(byte *)(param_4 + 3) & 2) != 0,0x200);
    if (iVar2 == 0) {
      *(undefined2 *)(param_4 + 0xc) = 0;
      return param_4;
    }
    FUN_1000_3d77(param_4);
  }
  return 0;
}

