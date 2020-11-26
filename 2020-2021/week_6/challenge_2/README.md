# Challenge 2 - Leave the Juice Shop a 0 star rating

What a horrible website, let's destroy their hopes and dreams by leaving a 0-star review!

<details>
  <summary>Click me for a hint</summary>
  
  ```
  Try intercepting the request with burp and see if you can spot anything obvious.
  ```
</details>


<details>
  <summary>Click me for all the spoilers</summary>
  
  # Spoilers
  
  Go to the customer feedback form.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_2/ch2shots/1.png">
  </p>
  
 Make sure your burp is now intercepting!
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_2/ch2shots/2.png">
  </p>
  
  Leave some lovely feedback and submit the request.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_2/ch2shots/3.png">
  </p>
  
  Your should now see the intercepted request in Burp (if you don't, forward captured requests until you do).

  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_2/ch2shots/4.png">
  </p>
  
  Change your rating to '0' and forward the request.
  
  <p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/challenge_2/ch2shots/5.png">
  </p>

</details>

