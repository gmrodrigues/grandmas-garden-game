// TIM2.EXE: FUN_311b_00fc @ file 0x0364AC Ghidra 0x312AC
// Subsystem: misc | Size: 188 bytes


void __cdecl16far FUN_311b_00fc(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  
  uVar7 = DAT_554c_42d8;
  uVar6 = DAT_554c_42ca;
  uVar5 = DAT_554c_42c8;
  uVar4 = DAT_554c_42c6;
  uVar3 = DAT_554c_42c4;
  uVar2 = DAT_554c_42c3;
  if (DAT_554c_3e4a != 0) {
    uVar10 = (undefined2)((ulong)param_1 >> 0x10);
    iVar8 = (int)param_1;
    iVar9 = *(int *)(iVar8 + 0xe) * 0x12;
    if (*(int *)(iVar9 + 0xda) != 0 || *(int *)(iVar9 + 0xdc) != 0) {
      DAT_554c_42d8 = 0xa000;
      DAT_554c_42c3 = 1;
      DAT_554c_42c4 = 0;
      DAT_554c_42c6 = DAT_554c_49aa + -1;
      DAT_554c_42c8 = 0;
      DAT_554c_42ca = DAT_554c_3e4a + -1;
      puVar1 = (undefined2 *)(*(int *)(iVar8 + 0xe) * 0x12 + 0xda);
      (*(code *)*puVar1)((char *)s_SIGNIN_RES_554c_3111 + 10,iVar8,uVar10);
    }
  }
  DAT_554c_42c3 = uVar2;
  DAT_554c_42c4 = uVar3;
  DAT_554c_42c6 = uVar4;
  DAT_554c_42c8 = uVar5;
  DAT_554c_42ca = uVar6;
  DAT_554c_42d8 = uVar7;
  return;
}

