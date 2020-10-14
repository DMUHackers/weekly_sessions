In this challenge we are provided the /etc/passwd and /etc/shadow files from a Linux system
```
 # ls
passwd  shadow
```

In order to crack the user password, we need to first combine the two files into a usable format
```
 # unshadow passwd shadow > unshadowed.txt
```

Now we have a hash file to work with, we can crack it using [John the Ripper](https://github.com/openwall/john), providing [rockyou.txt](https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt) as a dictionary
```
 # john --wordlist=/opt/rockyou.txt unshadowed.txt
Warning: detected hash type "md5crypt", but the string is also recognized as "md5crypt-long"
Use the "--format=md5crypt-long" option to force loading these as that type instead
Using default input encoding: UTF-8
Loaded 1 password hash (md5crypt, crypt(3) $1$ (and variants) [MD5 256/256 AVX2 8x3])
Will run 4 OpenMP threads
Press 'q' or Ctrl-C to abort, almost any other key for status
##########       (max)
1g 0:00:00:09 DONE
Session completed
```