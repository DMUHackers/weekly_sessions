In this challenge we are provided a password-protected docx file. We'll need a tool to extract the hash into a format that [John the Ripper](https://github.com/openwall/john) can crack. For this we can use [office2john](https://github.com/openwall/john/blob/bleeding-jumbo/run/office2john.py)
```
 # wget https://raw.githubusercontent.com/openwall/john/bleeding-jumbo/run/office2john.py
```

Let's change the permissions on the downloaded script so we are able to run it
```
 # chmod +x office2john.py
```

Now we can use it to extract the hash
```
 # ./office2john.py Max_super_secret_shopping_list.docx > Max_super_secret_shopping_list.docx.hash
```

We now have a hash file, we can crack it using [John the Ripper](https://github.com/openwall/john), providing [rockyou.txt](https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt) as a dictionary
```
 # john --wordlist=/opt/rockyou.txt Max_super_secret_shopping_list.docx.hash
Using default input encoding: UTF-8
Loaded 1 password hash (Office, 2007/2010/2013 [SHA1 256/256 AVX2 8x / SHA512 256/256 AVX2 4x AES])
Cost 1 (MS Office version) is 2007 for all loaded hashes
Cost 2 (iteration count) is 50000 for all loaded hashes
Will run 4 OpenMP threads
Press 'q' or Ctrl-C to abort, almost any other key for status
#########        (Max_super_secret_shopping_list.docx)
1g 0:00:03:46 DONE
Session completed
```