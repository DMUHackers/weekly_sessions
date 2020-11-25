# Burp Suite Configuration Guide

Burp Suite is an integrated platform for performing security testing of web applications. Its various tools work seamlessly together to support the entire testing process, from initial mapping and analysis of an application’s attack surface, through to finding and exploiting security vulnerabilities. - [kali.org](https://tools.kali.org/web-applications/burpsuite)

## 1 - FoxyProxy

To allow you to switch between browsing normally and using Burp Suite, it's best to install FoxyProxy. This enables you to quickly switch the proxy you are using.

### Installing FoxyProxy

First, go to the firefox add-ons page and install FoxyProxy.

<p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/burp_configuration/screenshots/burp_1.png?raw=true">
</p>


### Adding the Burp proxy

Select the options tab in FoxyProxy:

<p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/burp_configuration/screenshots/burp_2.png?raw=true">
</p>

And fill in the required sections as per below (this is based on the default kali configuration):

<p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/burp_configuration/screenshots/burp_3.png?raw=true">
</p>

## 2 - Importing the Burp certificate

### Initial steps

Ensure you have Burp running in the background with intercept turned off and you have selected the new Burp configuration in FoxyProxy.

### Downloading the certificate

Navigate to http://burp and download the CA Certificate on the right hand side. Save this file.

<p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/burp_configuration/screenshots/burp_4.png?raw=true">
</p>

### Importing the certificate

Go to your Firefox settings > privacy & security. Select the 'View Certificates'.

<p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/burp_configuration/screenshots/burp_5.png?raw=true">
</p>

Click 'Import' and select your downloaded cacert.der file.

<p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/burp_configuration/screenshots/burp_6.png?raw=true">
</p>

Select the following option and click ok.

<p align="center">
	<img src="https://github.com/DMUHackers/weekly_sessions/blob/master/2020-2021/week_6/burp_configuration/screenshots/burp_7.png?raw=true">
</p>


## 3 - Success

You should now be able to use Burp to intercept requests, modify and analyse them, and more! To stop using Burp, simply use FoxyProxy to switch back to your normal proxy settings.

If you need extra help feel free to ask in the [Discord](https://discord.gg/Vvrk4kK).
