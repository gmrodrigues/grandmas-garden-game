// TIM2.EXE: FUN_1a9e_539c @ file 0x024F7C Ghidra 0x1FD7C
// Subsystem: level | Size: 119 bytes


int __cdecl16far FUN_1a9e_539c(int param_1,int param_2,undefined2 param_3,uint param_4)

{
  code *pcVar1;
  undefined2 uVar2;
  int iVar3;
  bool bVar4;
  
  if ((param_2 == param_1) && (param_2 == -1)) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    iVar3 = param_1 << 4;
  }
  else {
    bVar4 = false;
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    if (bVar4) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      if ((param_4 & 1) != 0) {
        FUN_1000_0624(0,uVar2,0,param_1,param_2);
        iVar3 = 0;
      }
    }
  }
  return iVar3;
}

