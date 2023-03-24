# Level 13

## Recherche
---

ici il va falloir jouer pour modifier l'uid. 

il faut faire croire qu'on est 4242, et donc jouer avec la gestion de l'uid et le preload.
je cree fakeuid.c 

int getuid()
{
	return(4242);
}
int geteuid()
{
	return(4242);
}

il faut ensuite le compiler pour en faire une lib

gcc -shared fakeuid.c -o fakeuid.so

on peut changer le preload en faisant comme suis. 
export LD_PRELOAD=~/fakeuid.so

pourtant ca ne marche pas, mon uid est change et le programme me dit toujours que je suis 2013

et le probleme c'est qu'il y a un check plus profond, justement pour eviter ce genre de magouille. Le resoudre est plutot simple. le probleme c'est qu'il se rend bien comtpe que entre level13 et flag13, il y a une difference, donc il bloque. 

cp level13 ./level113

On faisant un copier coller, on recupere les droits sur le nouveau fichier qui est une simple copie. et en lançant le nouveau programme, le mot de passe apparait

---
## Flag : 
---
## Sitographie
https://linuxhint.com/difference-between-real-effective-user-id-in-linux-os/
https://repo.zenk-security.com/Techniques%20d.attaques%20%20.%20%20Failles/Quelques%20astuces%20avec%20LD_PRELOAD.pdf
