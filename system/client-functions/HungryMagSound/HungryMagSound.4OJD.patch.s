.meta name="MAG alert"
.meta description="Plays a sound when\nyour MAG is hungry"
# Original code by Ralf @ GC-Forever and Aleron Ives
# https://www.gc-forever.com/forums/viewtopic.php?t=2050
# https://www.gc-forever.com/forums/viewtopic.php?t=2049
# Xbox port by fuzziqersoftware

entry_ptr:
reloc0:
  .offsetof start
start:
  .include  WriteCodeBlocksXB

  .data     0x00181075
  .data     0x0000000A
  .binary   E998010000CCCC83C410

  .data     0x00181212
  .data     0x0000000D
  .binary   31C0898694010000505050EB52

  .data     0x00181271
  .data     0x0000000F
  .binary   048D50BAB09D2E00FFD2E9FCFDFFFF

  .data     0x00000000
  .data     0x00000000
