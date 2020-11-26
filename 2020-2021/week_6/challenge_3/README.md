# Challenge 3 - Get yourself a juicy coupon code from the Juice Shop support bot

The prices on this website are extortionate! I wonder if we can get a discount from their support bot?

<details>
  <summary>Click me for a hint</summary>
  
  ```
  Try sending lots of different words to the support bot and see what responses you get. Burp intruder can make this a lot easier!
  ```
</details>

<details>
  <summary>Click me for all the spoilers</summary>
  
  # Spoilers
  
  Go to the support chat bot.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/1.png">
  </p>
  
  Let's give it a name, just to make sure it's working.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/2.png">
  </p>
  
  Make sure your Burp is intercepting.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/3.png">
  </p>
  
  Send a message to the chat bot and check the intercepted request in Burp (you can forward requests until you see the message request).
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/4.png">
  </p>
  
  Right click and select 'Send to Intruder'.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/5.png">
  </p>
  
  Go to the payloads tab and clear the highlighted section. We want to specifically target 'query'.
 
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/6.png">
  </p>
  
  Highlight the message you sent and 'add' this, it should look something like the below.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/7.png">
  </p>
  
  The next step is to add some payloads. Go to the payloads tab and add some words to your payloads list. Because we're looking for a coupon code, we'll add the words "code" and "coupon" a few times.
  
  Once done, click 'Start attack'.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/8.png">
  </p>

This may take some time depending on the size of your list. You can now sort by response length and look through these to see what the bot has said.

  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_3/ch3shots/9.png">
  </p>

Success! The bot gave us a code.


</details>

