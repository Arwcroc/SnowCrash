# Level 03

## Recherche

exercice assez difficile...

on commence avec un programme, qui nous dis "exploit me"

apres recherche, j'essaie xxd sur le fichier, et je vois que plusieurs chose sont inscrite

de ce fait, pour plus de visibilite, j'utilises la commande strings avec le programme et je vois que le exploit me est mis devant /usr/bin/env

il faut donc modifier le env. en recherchant je trouve que c'est une base du hack, modifier le path du env pour qu' il cherche un programme qu'il attend mais pas au meme endroit pour executer un programme malveillant

(merci romain) j'apprend qu'il ne faut pas de mot de passe mais un flag pour ce niveau. donc je dois utiliser la commande getflag mais elle ne me donne rien car je n'ai pas le mot de passe de flag03

je copie le programme /bin/getflag chez moi. ca marche pas, je nai pas les droits

il faut changer les droits de mon dossier. chmod u+w .  / chmod pour modifier les droits u pour le user donc moi w pour le droit d'ecrituere qui me permet de copier

je recommence la copie, et je l'ai

il faut modifier le nom de getflag, pour que level utilise mon getflag a la place de echo a l'avenir. mv getflag echo

apres des recherches et des enervements, le probleme c'est ma vm, j'ai trop fais de test et de merde dedans que pu rien marche

relance la vm pour modifier le path proprement, un endroit que je connais avoir le droit d'acces c'est tmp

je change donc le path pour que son premier chemin de recherche ca soit la, et il y trouvera mon getflag, deguise en echo PATH="/tmp:$PATH"

je lance le programme et il me donne le flag

## Flag : qi0maab88jeaj46qoumi7maus


# Sitographie

- https://lettieri.iet.unipi.it/hacking/env-exploits.pdf
- https://fr.wikipedia.org/wiki/Executable_and_Linkable_Format
- http://www.linuxcertif.com/man/1/file/
- https://0x1.gitlab.io/exploit/Linux-Privilege-Escalation/#suid
- https://linux.die.net/man/1/strings
- 