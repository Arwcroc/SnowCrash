# Level 05

il va falloir relancer la vm ici, sinon ca bug en theorie

## Recherche

cd / 
find / mail
cd /rofs/var/mail
cat level05

ou trouve une ligne de command avec beaucoup de chose dont __*/2 * * * *__ avec le reste de la ligne

apres recherche, il s'avere que c'est un __crontab guru__ le script execute toutes les 2 minutes ce qu'on lui dit de faire

il va a mon avis falloir utiliser ce temps de 2 minutes pour mettre un fichier a la place

le reste de la ligne parle d'un fichier sur /usr/sbin/openarenaserver , il y a un script a l'interieur, le fichier est execute toutes les deux minutes par le crontab. 

cat /usr/sbin/openarenaserver

le for est pour parcourir tous les fichiers de /opt/openarenaserver, le ulimit pour passer les fichiers qui prendraient trop de temps, et le bash -x est apparemment pour du debug.

on peut rajouter un fichier dans ce dossier, on peut donc mettre un script dedans qui sera execute toutes les 2 minutes.

echo "/bin/getflag > /tmp/level05" > /opt/openarenaserver/script.sh

je redirige getflag vers tmp level05 car je sais que j'y ai acces

sachant que le fichier ne s'execute que toutes les 2 minutes, je lance une commande permettant de l'excuter en boucle pour voir quand ca pop

watch -n 1 cat /tmp/level05

## Flag : viuaaale9huek52boumoomioc


#Sitographie

https://www.baeldung.com/linux/create-crontab-script
https://patchthenet.com/articles/linux-privilege-escalation-three-easy-ways-to-get-a-root-shell/