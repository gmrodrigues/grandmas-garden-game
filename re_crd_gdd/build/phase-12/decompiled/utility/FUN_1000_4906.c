// TIM2.EXE: FUN_1000_4906 @ file 0x019B06 Ghidra 0x14906
// Subsystem: utility | Size: 134 bytes


int __cdecl16far FUN_1000_4906(int param_1,int param_2,uint param_3)

{
  code *pcVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  char local_4a [70];
  int local_4;
  
  local_4 = param_1;
  if (param_1 == 0) {
    pcVar1 = (code *)swi(0x21);
    bVar2 = (*pcVar1)();
    local_4 = bVar2 + 1;
  }
  bVar4 = 0xbf < (byte)local_4;
  local_4a[0] = (byte)local_4 + 0x40;
  local_4a[1] = 0x3a;
  local_4a[2] = 0x5c;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if (!bVar4) {
    uVar3 = FUN_1000_54d4(local_4a);
    if (uVar3 < param_3) {
      if ((param_2 != 0) || (param_2 = FUN_1000_3226(param_3), param_2 != 0)) {
        FUN_1000_5472(param_2,local_4a);
        return param_2;
      }
      uRam0005554e = 8;
    }
    else {
      uRam0005554e = 0x22;
    }
  }
  return 0;
}

