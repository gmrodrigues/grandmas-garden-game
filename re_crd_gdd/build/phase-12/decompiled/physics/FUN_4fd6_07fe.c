// TIM2.EXE: FUN_4fd6_07fe @ file 0x05575E Ghidra 0x5055E
// Subsystem: physics | Size: 151 bytes


void __cdecl16far FUN_4fd6_07fe(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint *in_CX;
  uint *puVar6;
  uint uVar7;
  undefined2 unaff_SS;
  
  bVar5 = false;
  iVar2 = *(int *)0x110;
  uVar3 = *(uint *)0x124;
  puVar6 = (uint *)&stack0xfffe;
  while (puVar6 < in_CX) {
    uVar7 = *puVar6 >> 1;
    if (uVar7 == 0) break;
    if (((((*puVar6 & 1) == 0) && (uVar4 = puVar6[2], uVar4 < uVar3)) && (puVar6[1] == 0)) &&
       (*(int *)0x0 == iVar2)) {
      bVar5 = true;
      *(undefined2 *)0x2 = 0;
    }
    puVar6 = (uint *)(uVar7 << 1);
  }
  if (bVar5) {
    while( true ) {
      uVar7 = *puVar6 >> 1;
      if (uVar7 == 0) break;
      if ((((*puVar6 & 1) == 0) && (uVar4 = puVar6[2], uVar4 < uVar3)) &&
         ((puVar6[1] != 0 && ((*(int *)0x0 == iVar2 && (*(int *)0x2 == 0)))))) {
        LOCK();
        uVar1 = *(uint *)0x2;
        *(uint *)0x2 = puVar6[1];
        UNLOCK();
        puVar6[1] = uVar1;
      }
      puVar6 = (uint *)(uVar7 << 1);
    }
  }
  return;
}

