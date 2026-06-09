// TIM2.EXE: FUN_4bdc_19f4 @ file 0x0529B4 Ghidra 0x4D7B4
// Subsystem: misc | Size: 208 bytes


void __cdecl16near FUN_4bdc_19f4(void)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uStack_e;
  undefined2 uStack_c;
  char *pcStack_a;
  undefined2 uStack_8;
  undefined1 *puStack_6;
  int aiStack_4 [2];
  
  aiStack_4[1] = 0x554c;
  iVar5 = 0;
  do {
    iVar6 = (int)((ulong)*(undefined4 *)(iVar5 + 0x4e) >> 0x10);
    iVar2 = (int)*(undefined4 *)(iVar5 + 0x4e);
    if ((iVar6 == 0) && (iVar2 == 0)) {
      return;
    }
    *(int *)(iVar2 + 0x154) = *(int *)(iVar2 + 0x154) + 1;
    uStack_8 = (undefined2)((ulong)*(undefined4 *)*(undefined4 *)(iVar2 + 8) >> 0x10);
    iVar4 = (int)*(undefined4 *)*(undefined4 *)(iVar2 + 8);
    iVar4 = iVar4 + *(int *)(iVar4 + (uint)(byte)(((*(byte *)(iVar2 + 0x165) & 0xf) - 1) * '\x02'));
    if (*(byte *)(iVar2 + 0x165) < 0x11) {
      *(byte *)(iVar2 + 0x165) = *(byte *)(iVar2 + 0x165) | 0x80;
      pcVar3 = (char *)(iVar4 + 1);
      if (*pcVar3 == -2) {
        pcVar3 = (char *)(iVar4 + 2);
      }
      puStack_6 = *(undefined1 **)(pcVar3 + 3);
      pcStack_a = pcVar3 + 9;
      uStack_c = *(undefined2 *)(pcVar3 + 1);
      uStack_e = CONCAT11(*(undefined1 *)(iVar2 + 0x15d),*(undefined1 *)(iVar2 + 0x15e));
      aiStack_4[0] = iVar2;
      FUN_4bdc_31c9(3,&uStack_e);
    }
    else {
      aiStack_4[0] = CONCAT11(*(undefined1 *)(iVar2 + 0x15d),*(undefined1 *)(iVar2 + 0x15e));
      puStack_6 = (undefined1 *)aiStack_4;
      uStack_8 = 4;
      pcStack_a = (char *)0x4000;
      uStack_c = 0xd853;
      uVar1 = FUN_4bdc_31c9();
      if ((char)((uint)uVar1 >> 8) != '\0') {
        *(undefined2 *)(iVar2 + 0x154) = 0;
      }
      if ((char)uVar1 != '\0') {
        *(undefined1 *)(iVar2 + 0x165) = 0;
        aiStack_4[0] = -0x278f;
        FUN_4bdc_0cf1();
        uRam0004020a = 1;
      }
    }
    iVar5 = iVar5 + 4;
  } while (iVar5 != 0x40);
  return;
}

