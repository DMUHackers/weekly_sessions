# Challenge 1 - DOM XSS

DOM Based XSS is an XSS attack wherein the attack payload is executed as a result of modifying the DOM (Document Object Model) “environment”.

Learn more about the Document Object Model [here](https://www.w3.org/TR/WD-DOM/introduction.html)

<details>
  <summary>Click here for a walkthrough</summary>
  
  First navigate to the home page where there's a searh bar.
  
  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_12/challenge_1/ch1shots/homescreen.PNG">
  </p>
  
  We can test for and check the vulnerability of the search bar/site using the following injection of code ``` <iframe src="javascript:alert(`xss`)" ```. Type or copy it in, then search!
  
  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_12/challenge_1/ch1shots/searchbarcommand.PNG">
  </p>
  
  The 'xss' part of the above code displays the message. This could be changed to what you would like, as I have below.
  
  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_12/challenge_1/ch1shots/JeremyJUiceLove.PNG">
  </p>

  You should find the challenge complete. Move on to challenge 2 or have a look at some other challenges on the scoreboard if you've unlocked that already.

  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_12/challenge_1/ch1shots/ChallengeComplete.PNG">
  </p>
  
</details>
