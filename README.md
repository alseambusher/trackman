#Description
Trackman is a tool which can be used in public places like cyber center to monitor what people are doing. There are two parts in trackman which are trackman server and trackman client. Once both parts of trackman has been instanciated, Trackman client monitors the system and sends data to the trackman server via TCP packets.
Please note that trackman has/will be made for constructive purposes like fighting terrorism..etc only  
By default the application runs on port number 1050 and on localhost unless explictly specified.
##Install
<pre>./configure</pre>
##Trackman server
To start give
<pre>./trackman-server {port-no} </pre>
For example
<pre>./trackman-server 1090 </pre>
Here is the sample output
<pre>
starting trackman-server...
28Thu Dec 27 22:53:10 IST 2012
520x2800003 Gvim: server.c (~/alse_cn/trackman) - GVIM
28Thu Dec 27 22:56:04 IST 2012
630x240008f Firefox: alseambusher (Suresh Alse) - Mozilla Firefox
28Thu Dec 27 22:56:14 IST 2012
340x2600006 Gnome-terminal: Terminal
</pre>
##Trackman client
To start give
<pre>./trackman-client {host} {port-no} [option]</pre>
For example
<pre>./trackman-client 10.3.1.250 1090</pre>
To start in silent mode
<pre>./trackman-client {host} {port-no} --silent</pre>
##Stop Trackman
<pre>./kill-trackman </pre>
