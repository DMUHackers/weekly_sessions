# Challenge 1 - Admin Login

Try and use SQLi to login as the admin on your juice shop app!

<details>
  <summary>Click me for a hint</summary>
  
  ```
  Try to view the login request in burp, what happens if you put ' as the email?
  ```
</details>

<details>
  <summary>Click me for all the spoilers</summary>
  
  # Spoilers
  
  Firstly, go to the login page and make sure burp is intercepting.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_1/ch1shots/1.png">
  </p>
  
  Try to login with email: `'` and password: `a`.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_1/ch1shots/2.png">
  </p>
  
  Once the request has been captured in burp, right click and `Send to Repeater`.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_1/ch1shots/3.png">
  </p>
  
  Send the request and take a look at the error message.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_1/ch1shots/4.png">
  </p
  
  The query is: `SELECT * FROM Users WHERE email = '<email>' AND password = '<password>' AND deletedAt IS NULL`
  
  So it will select the information held in the `Users` table if a row exists with the specified email and password.
  
  To bypass this, we will inject into the query to make it resolve as True. We will try `' or 1=1 -- `, as 1=1 always resolves as True and `-- ` will "comment out" (i.e. ignore) the rest of the query.
  
  So the new query should look like this: `SELECT * FROM Users WHERE email = '' or 1=1 --` ~~AND password = '' AND deletedAt IS NULL~~
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_1/ch1shots/5.png">
  </p>

  Success! We logged in as admin!



  This can be tested on the actual login page without using burp as well:


  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_1/ch1shots/6.png">
  </p> 

  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_7/challenge_1/ch1shots/7.png">
  </p>

</details>
