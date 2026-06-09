// TIM2.EXE: FUN_4fd6_11ac @ file 0x05610C Ghidra 0x50F0C
// Subsystem: misc | Size: 171 bytes


int __cdecl16near FUN_4fd6_11ac(void)

{
  code *pcVar1;
  undefined2 uVar2;
  uint in_AX;
  int iVar3;
  uint in_CX;
  uint in_DX;
  uint uVar4;
  uint in_BX;
  uint unaff_SI;
  int unaff_DI;
  bool bVar5;
  byte bVar6;
  
  uVar2 = uRam00050008;
  if (*(int *)0x47 == 0) {
    bVar6 = false;
    *(uint *)0x5f = in_AX;
    *(byte *)0x61 = (byte)in_DX;
    *(uint *)0x67 = in_BX;
    *(byte *)0x69 = (byte)in_CX;
    pcVar1 = (code *)swi(0x15);
    (*pcVar1)(0x554c);
    if (!(bool)bVar6) {
      return 0;
    }
  }
  else {
    *(uint *)0x4d = unaff_SI + 1 & 0xfffe;
    *(int *)0x4f = unaff_DI + (uint)(0xfffe < unaff_SI);
    if ((byte)in_DX < 0x10) {
      *(undefined2 *)0x51 = 0;
      uVar4 = in_DX >> 4 | in_DX << 0xc;
    }
    else {
      *(undefined2 *)0x51 = *(undefined2 *)0x47;
      bVar5 = in_AX < *(uint *)0x49;
      in_AX = in_AX - *(uint *)0x49;
      uVar4 = (in_DX - *(int *)0x4b) - (uint)bVar5;
    }
    *(uint *)0x53 = in_AX;
    *(uint *)0x55 = uVar4;
    if ((byte)in_CX < 0x10) {
      *(undefined2 *)0x57 = 0;
      uVar4 = in_CX >> 4 | in_CX << 0xc;
    }
    else {
      *(undefined2 *)0x57 = *(undefined2 *)0x47;
      bVar5 = in_BX < *(uint *)0x49;
      in_BX = in_BX - *(uint *)0x49;
      uVar4 = (in_CX - *(int *)0x4b) - (uint)bVar5;
    }
    *(uint *)0x59 = in_BX;
    *(uint *)0x5b = uVar4;
    iVar3 = (*(code *)*(undefined2 *)0x43)(0x5000);
    if (iVar3 != 0) {
      return 0;
    }
    bVar6 = 1;
  }
  return -(uint)bVar6;
}

