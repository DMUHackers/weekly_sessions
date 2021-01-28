# Challenge 2 - Whale Messaging

We recorded some whales out at sea. It sounds like they're trying to talk to us. Can you work out what they're trying to say?

File: [relaxing_whale_sounds.wav](https://github.com/DMUHackers/weekly_sessions/raw/master/2020-2021/week_10/challenges/challenge_2/relaxing_whale_sounds.wav)

<details>
    <summary>Solution (SPOILERS)</summary>

  Data is hidden in this image using `steghide`
  First, let's install it
  ```
  # apt update
  # apt install steghide
  ```

  Now let's extract the hidden file
  ```
  # steghide extract -sf bojack.jpg
  ```

  steghide asks for a passphrase, hitting enter we can try without using a passphrase
  ```
  Enter passphrase:
  wrote extracted data to "extracted_secret.txt".
  ```

  It worked! Now let's see what's hidden in the file
  ```
  # cat extracted_secret.txt
  ```

</details>
