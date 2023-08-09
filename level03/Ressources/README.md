# Level 03

## Recherche

exercice assez difficile...

on commence avec un programme, qui nous dis "exploit me"

apres recherche, j'essaie xxd sur le fichier, et je vois que plusieurs chose sont inscrite

de ce fait, pour plus de visibilite, j'utilises la commande strings avec le programme et je vois que le exploit me est mis devant /usr/bin/env

il faut donc modifier le env. en recherchant je trouve que c'est une base du hack, modifier le path du env pour qu' il cherche un programme qu'il attend mais pas au meme endroit pour executer un programme malveillant

on apprend qu'il ne faut pas de mot de passe mais un flag pour ce niveau. donc utiliser la commande getflag mais elle ne me donne rien car je n'ai pas le mot de passe de flag03

copie du programme /bin/getflag sur le dossier actuel en ayant change les droits. 
chmod u+w .  
chmod pour modifier les droits u pour le user donc nous w pour le droit d'ecriture qui permet de copier

il faut modifier le nom de getflag, pour que level utilise notre getflag a la place de echo a l'avenir. mv getflag echo

relance la vm pour modifier le path proprement, un endroit que je connais avoir le droit d'acces c'est tmp

je change donc le path pour que son premier chemin de recherche ca soit la, et il y trouvera mon getflag, deguise en echo PATH="/tmp:$PATH"

on change le pass avec export PATH="/tmp:$PATH" , et on copie notre getflag(echo) dans tmp __cd echo /tmp__

on lance le programme et il donne le flag

## Flag : qi0maab88jeaj46qoumi7maus


# Sitographie

- https://lettieri.iet.unipi.it/hacking/env-exploits.pdf
- https://fr.wikipedia.org/wiki/Executable_and_Linkable_Format
- http://www.linuxcertif.com/man/1/file/
- https://0x1.gitlab.io/exploit/Linux-Privilege-Escalation/#suid
- https://linux.die.net/man/1/strings
- 