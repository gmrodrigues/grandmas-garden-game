// TIM2.EXE: FUN_3f2b_12db @ file 0x04578B Ghidra 0x4058B
// Subsystem: sound | Size: 173 bytes


uint * __cdecl16far FUN_3f2b_12db(uint param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  
  iVar2 = DAT_554c_3d5a;
  if ((DAT_554c_3d57 != '\0') && (DAT_554c_3d5a != 0)) {
    if (*(uint *)0x0 < 5) {
      *(int *)0x0 = *(int *)0x0 * 0x4000 + -0x10;
      *(undefined2 *)0x2 = 0x10;
      *(undefined2 *)0x4 = 0;
      *(undefined2 *)0x6 = 0;
      *(undefined2 *)0x8 = 0;
    }
    if ((param_1 != 0) && (param_1 < 0xfffb)) {
      uVar3 = param_1 + 5 & 0xfffe;
      if (uVar3 < 8) {
        uVar3 = 8;
      }
      if (*(int *)0x4 != 0) {
        puVar4 = (uint *)*(undefined2 *)0x8;
        puVar5 = puVar4;
        if (puVar4 != (uint *)0x0) {
          do {
            if (uVar3 <= *puVar5) {
              if (*puVar5 < uVar3 + 8) {
                FUN_3f2b_128d();
                *puVar5 = *puVar5 + 1;
                return puVar5 + 2;
              }
              puVar4 = (uint *)FUN_3f2b_13ee();
              return puVar4;
            }
            puVar1 = puVar5 + 3;
            puVar5 = (uint *)*puVar1;
          } while ((uint *)*puVar1 != puVar4);
        }
        puVar4 = (uint *)FUN_3f2b_13c3();
        return puVar4;
      }
      puVar4 = (uint *)FUN_3f2b_1388();
      return puVar4;
    }
  }
  return (uint *)0x0;
}

