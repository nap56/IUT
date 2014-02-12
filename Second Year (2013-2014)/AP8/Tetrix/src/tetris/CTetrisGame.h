//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================

#ifndef __CTETRIS_GAME_H__	// routine qui sert � �viter l'inclusion multiple
#define __CTETRIS_GAME_H__	//

#include "CPieceAbstract.h"
#include "CTGameTable.h"
#include "CRandomizer.h"
#include "TetrisUtils.h"

class CTetrisGame {

public:
	/**
		\brief constructeur par d�faut de la piece
	*/
	CTetrisGame() {;}

	/**
		\brief constructeur 
	*/
	CTetrisGame ( unsigned int gamePosX, unsigned int gamePosY, unsigned int boardWidth, unsigned int boardHeight, float dimCase );
	
	/**
		\brief destructeur de CTetrisGame
	*/
	~CTetrisGame();

	/**
		\brief	met � jour le tetris en fonction du temps pass� (le nombre de fois que la boucle de rendu est appel�e)
				la m�thode descend automatiquement la pi�ce courante
				check si collision, si ligne � d�truire, le score et si game over
		\return l'�tat du jeu (ok ou game over)
	*/
	ActionResult Update(unsigned int step);

	/**
		\brief	modifie la position et l'orientation de la piece courante
		\param action � faire
		\return l'�tat du jeu (ok, collision ou game over)
	*/
	ActionResult MovePiece(PieceAction action);

	/**
		\brief renvoit le tableau du jeu avec les cases occup�es et leur couleur
		\return le tableau du jeu
	*/
	CTGameTable& GetBoard();

	/**
		\brief renvoit position du jeu dans la fen�tre openGL
		\param entier en abcisse
	*/
	unsigned int GetXPos();

	/**
		\brief renvoit position du jeu dans la fen�tre openGL
		\param entier en ordonn�e
	*/
	unsigned int GetYPos();

	/**
		\brief renvoit la taille d'une case du tetris
		\param entier sur la taille des cases
	*/
	float& GetCaseDim();

	/**
		\brief renvoit un pointeur sur la pi�ce courante
		\return  poniteur sur CPieceAbstract
	*/
	CPieceAbstract* GetPiece();

	/**
		\brief renvoit le score courant
		\return entier > 0
	*/
	unsigned int GetScore();

private:

	/**
		\brief ajout d'une piece al�atoire
	*/
	void AddPiece();

	/**
		\brief collision avec autre objets dans la scene ?
	*/
	bool CheckCollision();

	/**
		\brief collision avec les bords du jeu ?
	*/
	bool CheckBorderCollision();

	/**
		\brief insertion de la piece courante dans le tableau de jeu
	*/
	void InsertPiece();

	/**
		\brief cherche la premi�re ligne pleine
		\return index de la ligne pleine , -1 sinon !!!
	*/
	int GetFullRow();

	/**
		\brief supprime une ligne pleine
		\return index de la ligne pleine
	*/
	void DeleteRow(unsigned int rowIndex);

	/**
		\brief check si la partie est termin�e
		\return vrai si c'est le cas
	*/
	bool IsGameOver();

	/**
		\brief renvoit par un entier sign� le nombre de colonne du tableau
		\return entier sign� de la largeur du tableau
	*/
	int NbBoardCols();

	/**
		\brief renvoit par un entier sign� le nombre de lignes du tableau
		\return entier sign� de la largeur du tableau
	*/
	int NbBoardRows();


	//----------------------------------------------------------
	// Donn�es membres
	//----------------------------------------------------------
	CTGameTable		m_board				;	///< le tableau du jeu avec les cases occup�es et leur couleur
	unsigned int	m_xPos				;	///< position en abcisse du jeu dans la fen�tre openGL
	unsigned int	m_yPos				;	///< position en ordonn�e du jeu dans la fen�tre openGL
	float			m_caseDim			;	///< taille d'une case du tetris
};

#endif
