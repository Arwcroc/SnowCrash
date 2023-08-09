# Level 11

## Recherche
---

on lance la commande nc avec le server local : nc 127.0.0.1 5151
le server demande un mot de passe, dans les ressources on  trouve une longue string qui doit servir de comparaison, on apprend egalement que cela fait appelle a la fonction sha1sum, donc le cryptage de la string doit etre en sha1

avec dcode on trouve NotSoEasy mais ca ne marche pas.

echo NotSoEasy | sha1sum : cela ne donne pourtant pas le meme cryptage
printf NotSoEasy | sha1sum : cela donne le bon, echo doit rajouter quelque chose

en cherchant dans le man de echo on voit qu'il faut rajouter -n a la commande pour le pas ajouter de newline a la commande et donc ne pas fausser le cryptage


au final tout cela ne sert pas a grand chose. le but c'est de slalomer entre les commande faite par le programme. 
de ce fait il fait user des ';'

dans ce style : 

-n NotSoEasy > /dev/null ; /bin/getflag > ~/flag.txt ; echo -n NotSoEasy

apres plusieurs moment de recherche on en est arrivé a cette ecriture
(a rentrer dans la demande de mot de passe)

 ; /bin/getflag > /tmp/flag.txt ; echo -n NotSoEasy

on skip des le debut pour ne pas faire le echo, et on redirige getflag dans un fichier dans tmp, puis on fini proprement avec echo -n NotSoEasy. Le programme ne sera pas content mais un cat du fichier tmp nous suffira a recuperer le flag

---
## Flag : fa6v5ateaw21peobuub8ipe6s
---
## Sitographie

https://www.tunnelsup.com/hash-analyzer/

https://sha1.gromweb.com/?hash=f05d1d066fb246efe0c6f7d095f909a7a0cf34a0

https://www.tutorialspoint.com/lua/lua_operators.htm

