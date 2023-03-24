# Level 09

## Recherche
---
le programme incremente ce quon lui envoie, token devient tpmhr t change pas, o  +1 = p etc

je peux faire un cat de token et il y a plusieurs lettres dedans

il faut recuperer le token pour bosser plus facilement dessus, donc avec une secure copy

```scp -P 4242 level09@192.168.56.101:/home/user/level09/token .```

(ne pas oublier de recuperer tous les droits sur token)

je fais un main vite fait pour tester mon idée, que chaque lettre se decale en rapport de son iteration.

``` ./a.out $(cat token)```

j'ai le code : f3iji1ju5yuevaus41q1afiuq
je le test avec su flag09 dans la vm snowcrash, il me dit de recuperer mon flag, mon idée était la bonne.

---
## Flag : s5cAJpM8ev6XHw998pRWG728z
---
## Sitographie
