# Level 08

## Recherche
---
on a un programme level08 qui attend un fichier a lire, et un token qui doit etre notre getflag. sauf qu'on ne peut pas le lire. level08 lit bien le contenu d'un fichier, si je met coucou dans un fichier level08 peut le lire. il faut dont trouver une solution pour bouger token dans une zone ou je peux le lire. potentiellement tmp, mais je ne peux actuellement pas le bouger. 

grace a la commande ln -s on peut créer un lien symbolique. si je fais un lien symbolique de token dans le meme dossier mais sous le nom link, cela crée un lien et le programme croit utiliser link alors qu'il est de suite redirigé vers token

et ca marche, level le plus rapide jusqu'a maintenant
quif5eloekouj29ke0vouxean

et en fait non, c'est juste le code
il faut faire comme avant, su flag08 mettre le code, puis lancer getflag et hop c'est enfin bon
---
## Flag : 25749xKZ8L7DkSCwJkT9dyv6f
---
## Sitographie
https://linuxize.com/post/how-to-create-symbolic-links-in-linux-using-the-ln-command/
