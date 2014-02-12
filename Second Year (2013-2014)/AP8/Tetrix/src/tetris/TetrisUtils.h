#ifndef __TETRIS_UTILS_H__	// routine qui sert � pas inclure 2 fois le m�me fichier
#define __TETRIS_UTILS_H__	//


#define WIDTH_BOARD  10		///< largeur de la grille du jeu
#define HEIGHT_BOARD  20	///< hauteur de la grille du jeu
#define POSX_BOARD  300		///< position en X de la grille du jeu dans la fen�tre GLUT
#define POSY_BOARD  100		///< position en Y de la grille du jeu dans la fen�tre GLUT
#define DIM_CASE  17.0 		///< taille d'une case de la grille du jeu (carr�e)

/**
	\brief Actions possibles par l'utilisateur
*/
enum PieceAction
{
	PA_RotateRight, // rotation horlogique
	PA_RotateLeft,	// rotation anti-horlogique
	PA_MoveRight,	// d�placement � droite
	PA_MoveLeft,	// d�placement � gauche
	PA_MoveBottom,	// d�placement vers le bas
	PA_MoveBottom2 	// d�placement rapide vers le bas
};

/**
	\brief Etat du jeu apr�s une action (update, modification de position ou orientation piece)
*/
enum ActionResult
{
	AR_Ok,
	AR_Collision,
	AR_GameOver
};



#endif // __TETRIS_UTILS_H__ fin de la routine
