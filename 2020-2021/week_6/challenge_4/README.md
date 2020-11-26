# Challenge 4 - Register a new admin user for the shop

Why do I have to register as a member? Let's create a new admin user!

<details>
  <summary>Click me for a hint</summary>
  
  ```
  Try and intercept the registration request to see what it looks like. Maybe you could add a new parameter?
  ```
</details>

<details>
  <summary>Click me for all the spoilers</summary>
  
  # Spoilers
  
  Go to the login page, and begin registering a new user.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_4/ch4shots/1.png">
  </p>
  
 Make sure your burp is now intercepting!
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_4/ch4shots/2.png">
  </p>
  
  Submit the request and go back to Burp. Right click and send this to the 'Repeater'.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_4/ch4shots/3.png">
  </p>
  
  Click 'Send' and see what response you get. It seems we're being assinged the role: 'customer'.

  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_4/ch4shots/4.png">
  </p>
  
  Change the email (so we're creating a new user) and add a new parameter "role":"admin". Make sure to include a comma on the parameter before.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_4/ch4shots/5.png">
  </p>
  
  Send the request again.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_4/ch4shots/6.png">
  </p>  
  
  Success, we created an admin user!

</details>

