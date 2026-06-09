// TIM2.EXE: FUN_1a9e_836a @ file 0x027F4A Ghidra 0x22D4A
// Subsystem: physics | Size: 160 bytes


void __cdecl16far FUN_1a9e_836a(char *param_1,byte *param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  
  FUN_1000_1a00(0x1a9e);
  FUN_1000_1a00(0x1000);
  while (iVar4 = param_3 + -1, param_3 != 0) {
    cVar1 = *param_1;
    FUN_1000_1a44(0x1000);
    for (uVar3 = 1; param_3 = iVar4, (uVar3 & 0xff) != 0; uVar3 = uVar3 << 1) {
      if ((uVar3 & 0xaa) == 0) {
        *param_2 = (uVar3 & (int)cVar1) != 0;
      }
      else {
        if ((uVar3 & (int)cVar1) == 0) {
          bVar2 = 0;
        }
        else {
          bVar2 = 0x10;
        }
        *param_2 = *param_2 | bVar2;
        FUN_1000_1a44(0x1000);
      }
    }
  }
  return;
}

