Avancement du projet :

Toutes les fonctionnalit�s obligatoires ont �t� impl�ment�es, l'interface graphique est compl�te.
L'application a �t� test�e, son fonctionnement est correct et correspondant � celui attendu. 


------------------------------------------------------------- fonctionnalit�s obligatoires -------------------------------------------------------------------------------- 


						A) pour l'interface graphique : 

* l'interface graphique est non-redimensionnable, afin d'�viter des soucis d'ajustement lors de l'agrandissement ou du r�tr�cissement de la fen�tre.



						B) pour la partie Fichier : 

* La  partie "Sauvegarder" pour pouvoir sauvegarder par s�rialisation l'annuaire avec les contacts rajout�s si il y en a dans un fichier annuaire.out
avec une fen�tre de confirmation qui s'affiche une fois la sauvegarde effectu�e.

* La partie "Charger" qui permet de charger un fichier Annuaire.out, celui �tant un annuaire sous forme binaire (pr�c�demment sauvegard� par exemple).

* La partie "Quitter" qui ferme l'application Wintel apr�s confirmation par l'utilisateur (pour �viter les clics par erreur).



						C) pour la partie Contact :

* affichage des informations du contact dans la partie de droite quand on clique sur celui-ci.

* La partie "Ajouter" qui permet d'entrer un nouveau contact dans l'annuaire (il faut au minimum entrer son nom sinon un message d'erreur s'affiche.

* La partie "Modifier" qui permet de changer les informations d'un contact apr�s clic sur ce contact dans la liste � gauche.
Il faut �galement ne pas laisser de champ vide pour le nom sinon un message d'erreur s'affiche.
D'autre part, les champs contenant les informations du contact sont directement remplis lors de l'ouverture de la fen�tre "Modifier".
Une v�rification du nom du contact � modifier � �t� mise en place, et un message d'erreur s'affiche si celui-ci n'est pas pr�sent dans l'annuaire 

* La partie "Supprimer" permettant de supprimer un contact de l'annuaire, avec les m�mes conditions de v�rification que pour la partie "Modifier".



						D) pour la partie "Aide" : 

* affichage d'une fen�tre d'aide contenant des explications sur le projet Wintel


---------------------------------------------------------- fonctionnalit�s bonus mises en places --------------------------------------------------------------------------

* Mise en place d'une r�action au bouton "Composer" : une fen�tre de confirmation s'ouvre indiquant que la composition du num�ro est en cours.
* Au moment de quitter, si l'utilisateur vient d'ajouter ou de modifier un contact sans avoir sauvegard�, une fen�tre de confirmation
demande � l'utilisateur si il souhaite r�aliser une sauvegarde avant de fermer l'application.



