# Malware Analysis Task Answers

## Task 1

1. What is the file type?

    The file type is `PE32+ executable (GUI)`

2. What is the file size?

    The file size is `7,239,165 bytes`
   
3. When was the file created?

    The file was created on `25 January 2024, 15:02:56`

4. What is the MD5 hash of the file?

    The MD5 hash is `5c8cfdb60e5b30248e9f63c88843903e`

## Task 2

1. Check the strings in the file. What do you notice?

    Most of the strings are unreadable, but there are some readable items, in particular the name of some DLLs.

2. What DLLs does the file contain?

    The file uses the following DLLs:
    
    ```
    ucrtbase.dll
    USER32.dll
    KERNEL32.dll
    ADVAPI32.dll
    bVCRUNTIME140.dll
    blibcrypto-3.dll
    bpython312.dll
    8python312.dll
    ```

3. What are your first thoughts from these DLLs?
   
    The DLLs are all standard Windows DLLs, except for `blibcrypto-3.dll` which is a DLL from the `OpenSSL` library. This is a library used for encryption and decryption, so it is likely that the malware uses this library to encrypt or decrypt data.

4. Which of thes DLLs does the program actually use?

    ```
    USER32.dll
    KERNEL32.dll
    ADVAPI32.dll
    ```

5. How does this change your views from question 2?
    
    This tells us that the malware does not use the `OpenSSL` library, so it is unlikely that the malware encrypts or decrypts data.

## Task 3

1. From the limited information you have, do you think its safe to run the file?

    There is nothing suspicious about the file so far, so it is probably safe to run the file.

2. What happens?

    The file opens a terminal window and displays a flag

3. What is the flag?

    The flag is `dmu{m4lwar3_an4lys1s}`
    

## Task 4

1. What 2 processes does the executable create?
   
    The executable creates the following processes:
    
    ```
    conhost.exe
    dmuhackersware.exe
    ```

2. Do you think these processes are normal?

    The `conhost.exe` process is a standard Windows process, so it is normal. The `dmuhackersware.exe` process is the malware itself.

## Challenge

```py
import time
print("dmu{m4lwar3_an4lys1s}")
time.sleep(5)
```