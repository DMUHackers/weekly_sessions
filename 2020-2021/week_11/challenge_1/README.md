# Challenge 1 - Linux box


Box IP: 10.8.0.30

<details>
  <summary>Click here for a walkthrough</summary>
  
  Once you have gained the foothold with SSH, you can view date_checker.c with the below command. Here we can see the program returns a date in the command line.
  
  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_11/challenge_1/ch1shots/catdatechecker.png">
  </p>
  
  Echo a bash shell to /tmp/date. You can see 'date' is used in the program above.
  
  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_11/challenge_1/ch1shots/echobinbash.png">
  </p>

  Change the permissions of the file to be executable

  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_11/challenge_1/ch1shots/chmodtmpdate.png">
  </p>
  
  
  
  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_11/challenge_1/ch1shots/exportpath.png">
  </p>
  
  Run the program as so, and check your success with 'id'
  
  <p align="center">
	      <img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_11/challenge_1/ch1shots/rootgained.png">
  </p>

</details>
