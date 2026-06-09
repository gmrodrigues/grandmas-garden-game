// TIM2.EXE: FUN_4a54_1054 @ file 0x050794 Ghidra 0x4B594
// Subsystem: misc | Size: 71 bytes


undefined4 __cdecl16near FUN_4a54_1054(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint *puVar6;
  undefined2 unaff_SS;
  
  puVar6 = DAT_5b41_2858;
  bVar5 = (byte)param_1 & 0xf;
  uVar3 = *DAT_5b41_2858;
  uVar4 = DAT_5b41_2858[1];
  puVar1 = DAT_5b41_2858;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_1;
  puVar6[1] = puVar6[1] + (uint)CARRY2(uVar2,param_1);
  return CONCAT22(uVar4 >> 3,
                  *(uint *)(puVar6[2] +
                           (((uVar3 >> 1 | (uint)((uVar4 & 1) != 0) << 0xf) >> 1 |
                            (uint)((uVar4 >> 1 & 1) != 0) << 0xf) >> 1 |
                           (uint)((uVar4 >> 2 & 1) != 0) << 0xf)) >> ((byte)uVar3 & 7) &
                  (uint)(byte)((byte)(-0x100 << bVar5) | (byte)(0xff00 >> 0x10 - bVar5)));
}

