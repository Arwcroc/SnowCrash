# Level 14

## Recherche
---
On arrive sur le level 14, avec ll on ne trouve rien. Le fichier étant complétement vide, on n'a accés à rien d'utile sauf une chose, que nous utilisons depuis le début : /bin/getflag

En demandant à nos connaissances, la seule solution ici est donc d'utiliser gdb sur getflag pour aller dans le programme comprendre son fonctionnement. 
il faut donc faire : gdb /bin/getflag

ici, on peut commencer a faire break (ou b) main pour initier un breakpoint, puis run (ou r) pour lancer getflag, et enfin disasemble (ou disas) pour voir l'entièreté du programme.

apres avoir lu tout le programme, on a remarqué un patern cyclique, dont les lignes importantes sont en bas de ce fichier. En fait, apres reflexion, recherche etc, on s'est apercu que c'etait les cle crypté de tous les level de snowcrash, ce qui est au final logique. mais cela ne nous aidera pas ici. 

On a donc essayé de faire comme pour le level d'avant, chercher une difference d'id pour acceder a une zone qui m'est interdite en temps normal.
il y a bien une différence. l'id est 2014, alors que l'id de flag14 est 3014. Pas possible de changer dans gdb

On a trouvé que au debut du programme il y avait un ptrace. en fait, en utilisant le b main je passe obligatoirement par ptrace. le ptrace en question permet de tourner en fond pour limiter les acces memoires, interdire le "reverse" entre autre restriction.
a partir de cela on a pensé a quelques choses, si ce ptrace check si on a le bon id, il y a forcement un endroit ou il fait la comparaison. comme il n'y a pas de int dans l'asm, on a transformé 3014 en hexa pour trouv BC6. en cherchant dans le disas, on trouve bien un : 

0x08048bb6 <+624>:	cmp    $0xbc6,%eax

si la comparaison est bonne getflag va ici :

0x08048bbb <+629>:	je     0x8048de5 <main+1183>

il faut donc acceder a main+1183

maintenant c'est plus simple. pour bypass le ptrace ce n'est pas compliqué, faut juste commencer le programme après. le main juste apres c'est ici :

0x08048990 <+74>:	jns    0x80489a8 <main+98>

donc on peut faire : b *0x08048990
puis : r

ici le programme se lance juste apres le ptrace, je peux donc jump au main a dequat si la comparaison est bonne (la ou il y a "je")

donc on fait :

jump  *0x8048de5

et on trouve le flag

plus qu'à faire su flag14 et rentrer le mdp pour être sur

---
## Flag : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
---
## Sitographie

https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf
https://beginners.re/RE4B-FR.pdf
https://beta.hackndo.com/assembly-basics/
http://www.pageperso.lif.univ-mrs.fr/~alexis.nasr/Ens/Compilation/cm06_x86.pdf
https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm
http://www.lsv.fr/~goubault/CoursProgrammation/Doc/minic007
https://stackoverflow.com/questions/21718397/what-are-the-esp-and-the-ebp-registers
https://www.stashofcode.fr/deboguer-avec-gdb-un-bref-didacticiel/
https://cs.lmu.edu/~ray/notes/nasmtutorial/
http://www.scs.stanford.edu/nyu/04fa/notes/l2.pdf
https://gist.github.com/poxyran/71a993d292eee10e95b4ff87066ea8f2


   0x08048992 <+76>:	movl   $0x8048fa8,(%esp)
   0x080489a8 <+98>:	movl   $0x8048fc4,(%esp)
   0x080489f2 <+172>:	movl   $0x8048ff6,(%esp)
   0x08048a3c <+246>:	movl   $0x8049009,(%esp)
   0x08048bfa <+692>:	movl   $0x80490b2,(%esp)
   0x08048c1e <+728>:	movl   $0x80490cc,(%esp)
   0x08048c42 <+764>:	movl   $0x80490e6,(%esp)
   0x08048c66 <+800>:	movl   $0x8049100,(%esp)
   0x08048c8a <+836>:	movl   $0x804911a,(%esp)
   0x08048cae <+872>:	movl   $0x8049134,(%esp)
   0x08048cd2 <+908>:	movl   $0x804914e,(%esp)
   0x08048cf6 <+944>:	movl   $0x8049168,(%esp)
   0x08048d1a <+980>:	movl   $0x8049182,(%esp)
   0x08048d3e <+1016>:	movl   $0x804919c,(%esp)
   0x08048d62 <+1052>:	movl   $0x80491b6,(%esp)
   0x08048d86 <+1088>:	movl   $0x80491d0,(%esp)
   0x08048daa <+1124>:	movl   $0x80491ea,(%esp)
   0x08048dcb <+1157>:	movl   $0x8049204,(%esp)
   0x08048dec <+1190>:	movl   $0x8049220,(%esp)