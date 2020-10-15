In this challenge we are given a .hccapx file
```
 # ls
maxnet.hccapx
```

hccapx is a custom format, developed for [hashcat](https://hashcat.net/hashcat/). As we have part of the password, we can make use of hashcat's [mask attack](https://hashcat.net/wiki/doku.php?id=mask_attack) feature. View the manpage for more info
```
 # man hashcat
```

We need to set the hash-type to 2500, WPA/WPA2
```
OPTIONS
   -m, --hash-type=NUM
          Hash-type, see references below 
   [...]
Hash types
   2500 = WPA/WPA2
```

We will be performing a brute-force attack, attack-mode 3
```
OPTIONS
   -a, --attack-mode=NUM
          Attack-mode, see references below
   [...]
Attack mode
   3 = Brute-force
```

Finally we will define custom charset 1 to contain upper and lowercase alphanumeric characters, we will use this for our mask
```
OPTIONS
   -1, --custom-charset1=CS
          User-defined charsets example --custom-charset1=?dabcdef : sets charset ?1  to  0123456789abcdef  -1
          mycharset.hcchr : sets charset ?1 to chars contained in file 
   [...]
Built-in charsets
   ?l = abcdefghijklmnopqrstuvwxyz
   ?u = ABCDEFGHIJKLMNOPQRSTUVWXYZ
   ?d = 0123456789
```

Let's combine our findings and crack the hash. Note that we know the password is in the format U2#H7#X#, we use our custom charset **?1** as defined earlier in place of any characters that we don't know
```
 # hashcat -m 2500 maxnet.hccapx -a 3 -1 '?l?u?d' 'U2?1H7?1X?1'
```
