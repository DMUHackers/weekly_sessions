Let's try unzipping the provided zip file
```
 # unzip darkest-secret.zip 
Archive:  darkest-secret.zip
[darkest-secret.zip] my_big_secret.txt password: 
   skipping: my_big_secret.txt       incorrect password
```

# Method 1 - fcrackzip

Let's try to crack the password using fcrackzip!

```
 # fcrackzip -u -D -p /opt/rockyou.txt darkest-secret.zip

PASSWORD FOUND!!!!: pw == ############  
```

# Method 2 - John

It's secured with a password, so we'll need to get the hashed password in order to crack it
```
 # zip2john darkest-secret.zip > darkest-secret.zip.hash
```

Now let's crack that hash with [John the Ripper](https://github.com/openwall/john), providing [rockyou.txt](https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt) as a dictionary
```
# john --wordlist=/opt/rockyou.txt darkest-secret.zip.hash 
Using default input encoding: UTF-8
Loaded 1 password hash (PKZIP [32/64])
Will run 4 OpenMP threads
Press 'q' or Ctrl-C to abort, almost any other key for status
############     (darkest-secret.zip/my_big_secret.txt)
1g 0:00:00:00 DONE
Session completed
```

