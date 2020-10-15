We start with **SAM** and **SYSTEM** files, these are database files from Windows. We can use [samdump2](https://linux.die.net/man/1/samdump2) to extract the hashes from these files
```
 # samdump2 SYSTEM SAM > hash.txt
```

If we take a look inside the new file, we now have 4 hashes. We only need the hash for the Max user account
```
 # grep Max hash.txt > hash2.txt
```

Now we have the hash, we need a way to crack it. Max's blog could provide useful information, we can use a tool called [CeWL](https://github.com/digininja/CeWL) to create a custom wordlist using words that commonly appear on a site
```
 # cewl https://max-pizza-party.tumblr.com/ > wordlist.txt
```

Our new wordlist is a step in the right direction, but it's unlikely his password will just be single words. We can use [cupp](https://github.com/Mebus/cupp) to improve on what we have
```
 # cupp -w wordlist.txt
 ___________ 
   cupp.py!                 # Common
      \                     # User
       \   ,__,             # Passwords
        \  (oo)____         # Profiler
           (__)    )\   
              ||--|| *      [ Muris Kurgas | j0rgan@remote-exploit.org ]
                            [ Mebus | https://github.com/Mebus/]


      *************************************************
      *                    WARNING!!!                 *
      *         Using large wordlists in some         *
      *       options bellow is NOT recommended!      *
      *************************************************

> Do you want to concatenate all words from wordlist? Y/[N]: Y
> Do you want to add special chars at the end of words? Y/[N]: Y
> Do you want to add some random numbers at the end of words? Y/[N]:Y
> Leet mode? (i.e. leet = 1337) Y/[N]: N

[+] Now making a dictionary...
[+] Sorting list and removing duplicates...
[+] Saving dictionary to wordlist.txt.cupp.txt, counting 2938719 words.
[+] Now load your pistolero with wordlist.txt.cupp.txt and shoot! Good luck!
```

Now we have the hash we need and a dictionary attack it with, let's put it all together and crack it with [John](https://github.com/openwall/john), remembering to specify that we are using NTLM hashes with the `--format=NT` flag
```
 # john --format=NT --wordlist=wordlist.txt.cupp.txt hash2.txt 
Using default input encoding: UTF-8
Loaded 1 password hash (NT [MD4 256/256 AVX2 8x3])
Warning: no OpenMP support for this hash type, consider --fork=6
Press 'q' or Ctrl-C to abort, almost any other key for status
###########      (Max)
1g 0:00:00:00 DONE (2020-10-15 03:14)
Session completed
```