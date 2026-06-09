// TIM2.EXE: FUN_1000_3226 @ file 0x018426 Ghidra 0x13226
// Subsystem: utility | Size: 96 bytes


uint * __cdecl16far FUN_1000_3226(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)0x0;
  if (param_1 != 0) {
    if (param_1 < 0xfffb) {
      uVar2 = param_1 + 5 & 0xfffe;
      if (uVar2 < 8) {
        uVar2 = 8;
      }
      if (DAT_554c_5b50 == 0) {
        puVar3 = (uint *)FUN_1000_3286();
      }
      else {
        puVar3 = DAT_554c_5b54;
        if (DAT_554c_5b54 != (uint *)0x0) {
          do {
            if (uVar2 <= *puVar3) {
              if (*puVar3 < uVar2 + 8) {
                FUN_1000_31e7();
                *puVar3 = *puVar3 + 1;
                return puVar3 + 2;
              }
              puVar3 = (uint *)FUN_1000_32ef();
              return puVar3;
            }
            puVar1 = puVar3 + 3;
            puVar3 = (uint *)*puVar1;
          } while ((uint *)*puVar1 != DAT_554c_5b54);
        }
        puVar3 = (uint *)FUN_1000_32c6();
      }
    }
    else {
      puVar3 = (uint *)0x0;
    }
  }
  return puVar3;
}

