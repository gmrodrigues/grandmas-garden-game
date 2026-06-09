// TIM2.EXE: FUN_1a9e_5c0a @ file 0x0257EA Ghidra 0x205EA
// Subsystem: level | Size: 58 bytes


/* WARNING: Removing unreachable block (ram,0x00020615) */

void __cdecl16far FUN_1a9e_5c0a(void)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  uint in_stack_0000000c;
  
  if (in_stack_0000000c != 0) {
    puVar7 = (undefined2 *)FUN_1a9e_5aa5(0x554c);
    uVar3 = (undefined2)((ulong)puVar7 >> 0x10);
    puVar5 = (undefined2 *)puVar7;
    puVar7 = (undefined2 *)FUN_1a9e_5aa5();
    uVar4 = (undefined2)((ulong)puVar7 >> 0x10);
    puVar6 = (undefined2 *)puVar7;
    for (uVar2 = in_stack_0000000c >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar5;
      puVar5 = puVar5 + 1;
      *puVar1 = *puVar7;
    }
    for (uVar2 = (uint)((in_stack_0000000c & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
      puVar1 = puVar6;
      puVar6 = (undefined2 *)((int)puVar6 + 1);
      puVar7 = puVar5;
      puVar5 = (undefined2 *)((int)puVar5 + 1);
      *(undefined1 *)puVar1 = *(undefined1 *)puVar7;
    }
  }
  return;
}

