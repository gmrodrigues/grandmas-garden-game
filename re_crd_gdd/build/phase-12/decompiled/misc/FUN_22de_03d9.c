// TIM2.EXE: FUN_22de_03d9 @ file 0x0283B9 Ghidra 0x231B9
// Subsystem: misc | Size: 85 bytes


void FUN_22de_03d9(void)

{
  int iVar1;
  
  FUN_1000_4d37(DAT_5b41_17d8);
  FUN_1000_4d37(DAT_5b41_17da);
  FUN_1000_4d37(DAT_5b41_17dc);
  do {
    do {
      while (iVar1 = FUN_1000_9695(), iVar1 == 0xd) {
        FUN_3f2b_117b();
        FUN_1000_9677(0x19e,0);
      }
    } while (iVar1 != 0x1b);
    FUN_3f2b_117b();
    FUN_1000_17bf(1);
  } while( true );
}

