Salut,
Va voi prezenta programul pe care l-am facut.
In cadrul programului principal "pb8.c" avem functiile pentru cerinte, si main-ul.

In cadrul programului "lista.c" avem functiile pentru cerintele 1 si 2, plus si functiile facute pentru lista(creare nod, stergere lista).

In cadrul programului "stiva.c" avem functiile pentru cerinta 3 atasata stivei si functiile facute pentru stiva(pop,push,verificare daca e goala, si delete stack,initialize).

In cadrul programului "coada.c" avem functiile pentru cerinta 3 atasate coadei(sunt functiile care au fost chemate exclusiv pentru functia coada) si functiile facute pentru coada(intialize,enqueue,dequeue,print).

In cadrul programului "tree5.c" avem functiile pentru cerinta 4 si 5 si functiile facute pentru arbore(pentru crearea si eliberare).

In cadrul cerintei unu lucram cu structura player(first name,second name si points), luam in considerare numarul total de echipa, numarul de oameni in echipa, spatiile, backslash-urile, numele echipei.

Dupa ce am adunat punctele de la toti coechipierii, bagam numele echipei, punctajul total numele si numarul coechipierile dintr-o echipa intr-un nod ce va face parte dintr-o lista.

In cadrul cerintei doi, mai intai am gasit cea mai mare putere a lui 2 care este mai mica decat sirul nostru(fiind p). Dupa aceea parcurgem sirul nostru pana cand ajungem ca numarul elementelor sirului sa fie egale cu p. De fiecare data eliminam echipa cu cel mai mic punctaj. Facem asta prin gasirea indicelui acelui element, am decis ca e mai usor sa fac asa pentru a elimina deoarece pentru a elimina elementul specific(de exemplu: daca am echipe cu punctaje egale, trebuie sa il elimin pe primul dintr ele). Si dupa in functia de eliminare, elimin elementul care se potriveste cu indicele(daca indicele este k, echipa pe care trebuie sa o eliminam trebuie sa apara pe locul k).

In cadrul cerintei trei, am creat stiva pentru castigatori si pierzatori. Si coada in care punem meciurile, prima data parcurgem functia de facere a cozii(in care selectam echipele care vor fi in coada), dupa aceea printam aceea coada si interiorul acelei functii selectam stivele de echipe castigatoare si pierzatoare, printam stiva, golim stiva cu echipele pierzatoare si coada. Prima data facem cu noduri(primele parcurgeri ale functiilor), dar dupa prelucram stiva cu echipa castigatoare. Dupa ce gasim coada in cadrul stivei, golim echipa castigatoare. Noi repetam acest proces pana este o singura echipa castigatoare. Dupa la final, golim echipa castigatoare si pierzatoare si coada acestora. De retinut, in cadrul acestei cerinte am facut o functie pentru a retine cele top 8 echipe(ce ne va trebuie pentru cerinta 4 si 5). Mai intai verificam daca ajuns ca numarul de echipe sa fie 16 si bagam echipele castigatoare intr-un stiva top8. De asemenea, am creat functii pentru a nu lua in considerare spatiile atunci cand printam coada cu meciurile si cu stive, din cauza ca checker-ul avea probleme cu spatiile.

In cadrul cerintei patru, si parcurgem stiva(cu stiva->top si stiva->top->next) si daca acel element este mai mare(din pct de vedere al valorii numerice) sau daca sunt egale numerice(dar are literele mai in urma din pct de vedere alphabetic)(sau daca are numarul mai mare de caractere, in cazul in care litere precedente sunt egale) il punem in nodul din dreapta, nodului current si daca nu indeplineste aceste conditii mentionate anterior il punem in stanga. Si dupa ce punem toate lista in arbore, il parcurgem descrescator(prin parcurgerea recursiva prima data a nodurilor din dreapta in functie si dupa ele parcurgem recursiv cele din stanga), un fel de RSD inversat, deoarece parcurgem Dreapta, radacina, stanga. Dupa aceea stiva la final. Si la final returnam returnam arborele pentru cerinta 5. Eliberam stack-ul top8.

In cadrul cerintei cinci, avem arborele top8 si creeam dupa o stiva numita bst_ordonat, dupa aceea parcurgem arborele la fel ca la cerinta 4, doar ca in loc sa printam in fisier, bagam in stiva. Parcurgem stiva si facem functia de AVL, in care ca si data trecuta luam in considerare ordinea lexicografica si ordinea numerelor(ca si data trecuta numarul mai mare sau/si litera mai mare), dar tinem cont si de balans (daca inaltimea partii stangi e mult mai decat cea stanga(diferenta sa fie mai mare decat 1), si viceversa(in cazul celalat sa fie <1). 
Dar de data asta facem si rotatii, in cazul in care nodul stanga e mai mare decat valoarea din lista sau nodul din dreapta e mai mic decat valoarea din lista facem pur si simplu rotatii la stanga, respectiv dreapta. ( deci nod->nota e copilul din stanga a lui root->left prima data si dupa nod->nota e copilul din dreapta a lui root->right).

 Dar daca nodul din stanga e mai mica decat valoarea din lista, facem o rotatie la stanga(nodului la stanga) si facem o rotatie la dreapta nodului nostru. (deci nod->nota e copilul din dreapta a lui root->left).
Dar daca nodul din dreapta e mai mare decat valoarea din lista, facem o rotatie la dreapta(nodului la dreapta) si facem o rotatie la stanga nodului nostru. (deci nod->nota e copilul din stanga a lui root->right).

Si facem asta pana cand includem toate elementele din stiva->top si pana cand arborele este echilibrat. La finalul cerintei 5, facem o parcurgere ca la cerinta patru dar de data asta includem nivelurile si incepem de la zero. Noi ii ceram sa afiseze numai nivelul 2(de fiecare data cand facem recursiv root->right sau root->left, creste nivelul).
Iesim din cerinta si eliberam aborele BST.









