# Level 07

## Recherche
---
man xxd : make a hexdump or do the reverse. 

asprintf : Les fonctions asprintf() et vasprintf() sont similaires à sprintf(3) et vsprintf(3), si ce n'est qu'elles allouent une chaîne de caractères de taille suffisante pour contenir la sortie, y compris l'octet NULL terminal, et qu'elles renvoient un pointeur vers cette chaîne via le premier paramètre. Ce pointeur devra être passé en paramètre à free(3) afin de libérer la zone allouée lorsqu'elle ne sera plus nécessaire.

getenv : Cette fonction est utilisée pour récupérer le contenu d'une variable d'environnement. Les variables d'environnement sont définies par le système d'exploitation utilisé et permmettent d'obtenir des informations sur l'environnement dans lequel s'exécute le processus (le programme) en cours.

setresuid : setresuid() fixe les UID réel, effectif et (effectif) sauvé du processus appelant. Un processus utilisateur non privilégié peut fixer son UID réel, effectif ou sauvé avec sa valeur d'UID actuel, d'UID effectif actuel, ou d'UID sauvé. Les processus privilégiés (sous Linux, ce qui ont la capacité CAP_SETUID) peut positionner son UID réel, effectif ou sauvé à une valeur quelconque. Si l'un des paramètres vaut -1, la valeur correspondante n'est pas modifiée. 

setresgid : De manière analogue, setresgid() définit les GID réel,  effectif  et  sauvé  du  processus appelant  (et  définit  toujours  le  fsgid à la même valeur que le GID effectif) avec les mêmes restrictions pour les processus n'ayant aucun GID nul.

system : Cette fonction permet de lancer l'exécution d'une commande sur le système d'exploitation hôte : un nouveau processus est lancé pour chaque appel à cette fonction. L'appel à cette fonction bloquera le thread en cours jusqu'à que la commande lancée finisse. Si la sortie standard de votre programme est redirigée dans sur une console ou sur un fichier, vous pourrez y aussi retrouver les resultats produits par la commande exécutée par la fonction system. 

getegid : getgid() retourne le GID réel du processus appelant. 

geteuid : geteuid() retourne l'UID effectif du processus appelant.

---
get env semble une piste, mais pas echo qui n'est pas la bonne piste pour ce level. le programmme renvoit level07 car selon LTRACE c'est la fonction getenv qui va chercher le logname, il faudrait le changer dans les variables env pour afficher getflag, mais pour l'instant il n'y a que la string qui s'affiche, je dois trouver si il y a un moyen d'executer.

echo "/bin/exec /bin/getflag" > /tmp/echo 
chmod 777 /tmp/echo
export PATH=/tmp:$PATH
ltrace ./level07


pour modifier le logname il faut faire export LOGNAME puis mettre ce que l'on veut. dans notre cas, getflag, "getflag", 'getflag', /bin/getflag, "/bin/getflag", '/bin/getflag', /tmp/echo avec un faux echo qui va executer getflag etc... rien de tout cela ne fonctionne.

et pour cause, le ltrace nous a bien montré ce qui se fait dans le code, system appel echo et juste apres logname pour afficher logname
sauf que, on peut separer les deux commandes, en donnant la valeur ';/bin/getflag' a logname.  de ce fait, le system va executer echo de rien, puis executer getflag et nous donner la valeur puisque ce n'est pas nous qui demandons mais le system


---
## Flag : fiumuikeil55xe9cu4dood66h
---
## Sitographie

https://stackoverflow.com/questions/8304396/what-is-vulnerable-about-this-c-code
https://tldp.org/LDP/abs/html/special-chars.html
https://man7.org/linux/man-pages/man1/ltrace.1.html
https://stackoverflow.com/questions/22869637/setting-variables-with-executing-a-command-with-exec


