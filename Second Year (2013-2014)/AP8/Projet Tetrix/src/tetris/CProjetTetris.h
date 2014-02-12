//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================



#ifndef __PROJET_TETRIS_H__	// routine qui sert � pas inclure 2 fois le m�me fichier
#define __PROJET_TETRIS_H__	//

//-----------------------------------------------------------------
// Notre programme va avoir besoin 
// des fonctions sp�cifiques � l'utilisateur (iterface graphique utilisateur GUI) et
// des fonctions n�c�ssaires au rendu (dessin) d'un objet dans la scene
//
// On inclu les fichiers .h qui contiennent les d�clarations des fonctions
//-----------------------------------------------------------------
#include "CApplication.h"		// ensemble des fonctions contenant notre environnement de d�veloppement
#include "CTetrisGame.h"			// le jeu t�tris (pas d'affichage dedans  !!!!!)

////////////////////////////////////////////////////////////////////////
/// classe Demo: elle est notre classe cliente, elle poss�de l'ensemble des propri�t�s de la classe CApplication
/// et donc utilise le GUI et le renderer. 
//
// Projet Tetris
//
////////////////////////////////////////////////////////////////////////
class CProjetTetris: public CApplication {

public:
	/** 
		\brief constructeur par d�faut de CProjetTetris
	*/
	CProjetTetris();

	/**
		\brief destructeur de CProjetTetris
	*/
	~CProjetTetris();

	/**
		\brief initilisation de notre appli (rien car dessiner un cube � l'�cran ne n�c�ssite aucune initialisation)
		 !! M�thode appel�e dans la m�thode Init de la classe CApplication
	*/
	bool OnInit();

	/**
		\brief notre sc�ne � dessiner
		 !! M�thode appel�e dans la m�thode Run de la classe CApplication
	*/
	void OnRender();

	/**
		\brief destructuion de notre appli (rien car dessiner un cube � l'�cran ne n�c�ssite aucune destruction)
		 !! M�thode appel�e dans la m�thode Release de la classe CApplication
	*/
	void OnRelease();


private:
	
	//----------------------------------------------------------
	// Donn�es membres
	//----------------------------------------------------------
	unsigned int		m_step;			///< compteur de passage dans la m�thode onRender() permet de g�rer implicitement le temps
	CTetrisGame		m_game;			///< le jeu !!
	
	// Attributs temporaires
	// Il s'agit d'un test i.e. un carr� qui descend pour vous montrer comment �volue le jeu au cours du temps
	int				m_posYPiece;			
	int				m_posXPiece;

	/** 
		\brief affichage de la grille de jeu
	*/
	void DrawTetris();

	/** 
		\brief affichage des informations du jeu
	*/
	void DrawInfo();




	//----------------------------------------------------------
	// quelques outils pour afficher des carr� et des rectangles
	//----------------------------------------------------------
	/** 
		\brief affiche un carr� plein
		\param 1&2 coordonn�es
		\param 3: dimension (cot�) du carr�
		\param 4: couleur
	*/
	void DrawFillSquare(int x, int y, float dim, const CVector3 &color) ;
	
	/** 
		\brief affiche un rectangle plein
		\param 1&2 coordonn�es
		\param 3&4: largeur et hauteur
		\param 4: couleur
	*/
	void DrawFillRect(int x, int y, float w, float h, const CVector3 &color) ;

	/** 
		\brief affiche le contour d'un rectangle 
		\param 1&2 coordonn�es
		\param 3&4: largeur et hauteur
		\param 4: couleur
		\param 5: taille de la ligne
	*/
	void DrawRect(int x, int y, float w, float h, const CVector3 &color, float lineWidth = 1.5f) ;
};


#endif // __ProjetTetris_H__ fin de la routine
