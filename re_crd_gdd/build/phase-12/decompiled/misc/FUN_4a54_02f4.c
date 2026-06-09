// TIM2.EXE: FUN_4a54_02f4 @ file 0x04FA34 Ghidra 0x4A834
// Subsystem: misc | Size: 82 bytes


void __cdecl16near FUN_4a54_02f4(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  
  while (param_3 = param_3 + -1, iVar2 = param_4, param_1 <= param_3) {
    while (iVar2 = iVar2 + -1, param_2 <= iVar2) {
      cVar1 = (*DAT_5b41_285a)(DAT_5b41_2848);
      if ((cVar1 != '\0') || (DAT_5b41_285e != 0)) {
        (*DAT_554c_566c)(0x4000,param_3,iVar2,cVar1);
      }
    }
  }
  return;
}

