# Level 02

## Recherche

utilisation de scp pour copier du ssh vers mon poste.

__*scp -P 4242 level02@192.168.56.(101):/home/user/level02/level02.pcap .  *__

ouverture du fichier avec wireshark, a un moment il y a ecrit password

dans cette page ou il y a ecrit password, en effectuant une analyse : follow -> tcp stream, on peut voir les echanges entre le serveur et le client

de ce fait, on peut voir la reponse du client au moment ou le password est demande. (page 43)

on trouve ceci : ft_wandr...NDRel.L0L

evidemment cela ne marche pas

en cliquant sur les lettres du mot de passe, on se rend compte que wireshark m'emmene a chaque fois sur un nouveau paquet ou se trouve une lettre du mot de passe tape par le client. et les point correspondent a 7f, et c'est de l'hexa. 

Donc en allant dans la table ascii, puisque c'est la traduction de l'ascii, on voit que 7f, c'est del, il s'agit donc du nombre de fois que le client a tape sur del pour supprimer des lettres et donc retaper un morceau du mot de passe

code décrypté et fonctionnel : 

### Code : ft_waNDReL0L

## Flag : kooda2puivaav1idi4f57q8iq