# Level 00

initialiser vm - avec virtualbox - snowcrash.iso
dans les outils - reseaux - creer host only

## Recherche

_ssh level00@192.168.56.(101) -p 4242_ (le chiffre change en fonction du host only)

lecture des fichiers cachés

découverte de su, recherche sur su

test de su flag00 , demande un mot de passe inconnu

la video de l'intra nous parle de __FIND__, recherche de la commande FIND

outre plusieurs flag, un nous sera utile : -user 

trop d'erreur, solution -> __find / -user flag00 2>/dev/null__

recherche du contenu des fichiers : __cat rofs/usr/sbin/john__

on trouve ce code : __cdiiddwpgswtgt__
par déduction et parce que je ne connais que celui la, je vais sur dcode.fr et je décrypte comme si c'était du code césar

code décrypté et fonctionnel : 

### Code : nottoohardhere

## Flag : x24ti5gi3x0ol2eh4esiuxias