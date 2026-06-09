// TIM2.EXE: FUN_2424_20ab @ file 0x02B4EB Ghidra 0x262EB
// Subsystem: misc | Size: 186 bytes


void __cdecl16far FUN_2424_20ab(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 local_6;
  
  if ((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0) {
    *(uint *)((int)DAT_5b41_0567 + 0xe) = *(uint *)((int)DAT_5b41_0567 + 0xe) & 0xffdf;
  }
  for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
    if (iVar3 == 0) {
      puVar2 = (undefined2 *)&DAT_5b41_0557;
    }
    else {
      puVar2 = (undefined2 *)&DAT_5b41_054f;
    }
    local_6 = (undefined2 *)CONCAT22(0x554c,puVar2);
    while( true ) {
      iVar1 = ((undefined2 *)local_6)[1];
      puVar2 = (undefined2 *)*local_6;
      local_6 = (undefined2 *)CONCAT22(iVar1,puVar2);
      if (puVar2 == (undefined2 *)0x0 && iVar1 == 0) break;
      if ((param_1 != 0) || (*(char *)(puVar2 + 0xc) != '\0')) {
        FUN_2424_23db(puVar2,iVar1);
        if (param_1 == 0) {
          *(byte *)(puVar2 + 0xc) =
               (*(byte *)(puVar2 + 0xc) & 0x7f) - 1 | *(byte *)(puVar2 + 0xc) & 0x80;
        }
        else {
          *(undefined1 *)(puVar2 + 0xc) = 0;
        }
      }
    }
  }
  if (((int)DAT_5b41_0567 != 0 || DAT_5b41_0567._2_2_ != 0) &&
     ((*(byte *)((int)DAT_5b41_0567 + 0xe) & 0x20) == 0)) {
    FUN_2424_229b();
  }
  FUN_2424_2469();
  return;
}

