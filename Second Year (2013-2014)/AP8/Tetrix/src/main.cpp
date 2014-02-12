//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================


#include "CGuiGlut.h"
#include "CProjetTetris.h"

////////////////////////////////////////////////////////////////////////
/// la fonction main est sp�ciale 
/// puisque la premiere lanc�e � l'execution automatiquement
///
/// return code de fin d'application
////////////////////////////////////////////////////////////////////////
int main ( int argc, char *argv[] ) {

	CProjetTetris* monProjet = new CProjetTetris();

	// initialize graphics
	// cette m�thode permet d'intialiser le fenetrage associ� � votre application: CProjetTetris
   	CGuiGlut::InitializeGraphics ( argc, argv, monProjet );

	// run the main event processing loop
	// on lance une boucle infinie de rendu/mise � jour de la fen�tre/mise � jour de votre jeu 
	// qui se finit uniquement quand l'utilisateur le demande !!! esc ou X
	CGuiGlut::RunGraphics();  

	delete monProjet;
}
