# Level 01

## Recherche

recherche de comment avoir acces au mdp sur linux

test de la commande __cat /etc/passwd__

découverte que le flag01 est : 
__42hDRfypTqqnw__
test de su flag01 avec le password trouvé mais ça ne marche pas, il doit être crypté

recherche de comment fonctionne un password sur linux

__man 5 password__ annonce que c'est decryptable avec __man 3 crypt__

__cd /__ est accessible

le mot de passe du flag01 semble etre crypte en **_"Data Encryption Standard"_** __(DES)__

il faudrait utiliser john the ripper comme preconise dans la video du staff
install john the ripper (demarche en bas)

**_john --show ./Documents/snowcrash/papass_**

code décrypté et fonctionnel : 

### Code : abcdefg

## Flag : f2av5il02puano7naaf6adaaf

-----
-----
-----
-----


# Sitographie
- https://cromwell-intl.com/cybersecurity/password.html#wherestored
- https://cromwell-intl.com/cybersecurity/password.html#wherestored
- https://www.cyberciti.biz/faq/understanding-etcpasswd-file-format/
- https://bash.cyberciti.biz/guide/Chsh_command
- https://www.digitalocean.com/community/tutorialshow-to-use-passwd-and-adduser-to-manage-passwords-on-a-linux-vps
- https://www.thesslstore.com/blog/difference-encryption-hashing-salting/
- https://www.php.net/manual/fr/function.crypt.php
- https://jipe.developpez.com/articles/algo/table-hachage/?page=theorie
- https://fr.wikipedia.org/wiki/Data_Encryption_Standard
- https://github.com/openwall/john/blob/bleeding-jumbo/README.md
- 



rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source    $HOME/.zshrc && brew update

brew install john