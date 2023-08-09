# Level 08

## Recherche
---
on a un programme level08 qui attend un fichier a lire, et un token qui doit etre notre getflag. sauf qu'on ne peut pas le lire. level08 lit bien le contenu d'un fichier, si je met coucou dans un fichier level08 peut le lire. il faut dont trouver une solution pour lire token.

grace a la commande ln -s on peut créer un lien symbolique. si on fait un lien symbolique de token dans le meme dossier mais sous le nom link, cela crée un lien et le programme croit utiliser link alors qu'il est de suite redirigé vers token

chmod u+w .
ln -s token link
./level08 link

et ca marche, level le plus rapide jusqu'a maintenant
quif5eloekouj29ke0vouxean

su flag08 avec le code puis getflag

---
## Flag : 25749xKZ8L7DkSCwJkT9dyv6f
---
## Sitographie
https://linuxize.com/post/how-to-create-symbolic-links-in-linux-using-the-ln-command/
