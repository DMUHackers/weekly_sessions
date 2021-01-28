# Challenge 2 - Whale Messaging

We recorded some whales out at sea. It sounds like they're trying to talk to us. Can you work out what they're trying to say?

File: [relaxing_whale_sounds.wav](https://github.com/DMUHackers/weekly_sessions/raw/master/2020-2021/week_10/challenges/challenge_2/relaxing_whale_sounds.wav)

<details>
    <summary>Solution (SPOILERS)</summary>

  In this solution, we'll be using a tool to view the [spectogram](https://en.wikipedia.org/wiki/Spectrogram) of the audio file. There are many tools that can be used, but in this example we'll be using [Sonic Visualiser](https://www.sonicvisualiser.org/download.html)

  First, open the file in Sonic Visualiser
  ![](https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_10/challenges/challenge_2/screenshots/1.png?raw=true)

  With the file open, by default we will be shown a waveform of the audio
  ![](https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_10/challenges/challenge_2/screenshots/2.png?raw=true)

  To show the spectogram, select Layer > Add Spectogram > All Channels Mixed
  ![](https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_10/challenges/challenge_2/screenshots/3.png?raw=true)

  We're presented with a spectogram, there's definitely something there but it's not quite right. It appears squashed at the bottom. Let's try changing to a logarithmic view
  ![](https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_10/challenges/challenge_2/screenshots/4.png?raw=true)

  There it is! 
  ![](https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_10/challenges/challenge_2/screenshots/5.png?raw=true)

</details>
