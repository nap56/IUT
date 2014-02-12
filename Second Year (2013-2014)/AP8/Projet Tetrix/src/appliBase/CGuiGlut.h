//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================


//=====================================================================
// classe GUI, s'occupe du fenetrage et de l'interface avec l'utilisateur
//=====================================================================
//-----------------------------------------------------------------
// Ici fichier des d�clarations des fonctions. Une fonction ne peut �tre d�clar�e qu'une seule fois
// d'ou l'ajout d'une routine qui dit que si votre fichier � d�j� �t� inclu avant pas la peine de le re-inclure
//-----------------------------------------------------------------
#ifndef __GUI_H__	// routine qui sert � pas inclure 2 fois le m�me fichier
#define __GUI_H__	//


//-----------------------------------------------------------------
// On inclu les fichiers .h qui contiennent les d�clarations des fonctions
// On a besoin ici des objets SDL (SDLKey, SDL_Event) d�clar�s dans SDL.h
// ainsi que des d�clarations des fonctions OPENGL
//-----------------------------------------------------------------

#include <vector>					// utilis� par "std::vector<SDLKey> m_keyEvents;"
#include "Common.h"					// structure UserEvents utilis�e pour r�cup�rer les donn�es li�es � la souris


#include "GL/glut.h"
#include "CApplication.h"

//class MyApplication: public CApplication
//{
//	void OnInit(){std::cout<<"OnInit"<< std::endl;};
//	void OnRender(){std::cout<<"OnRender"<< std::endl;};
//	void OnRelease(){std::cout<<"OnRelease"<< std::endl;};
//};

////////////////////////////////////////////////////////////////////////
// Class qui d�finit un GUI � partir de la bibliotheque GLFW, � savoir la cr�ation de la fenetre,  gestion de la cam�ra, clavier , joystik ...
////////////////////////////////////////////////////////////////////////
class CGuiGlut
{
public:	// les fonctions suivantes peuvent �tre appel�es par d'autres classes / programmes

	//----------------------------------------------------------
	// constructeur
	//----------------------------------------------------------
	CGuiGlut(){}

	//----------------------------------------------------------
	// Destructeur
	//----------------------------------------------------------
	virtual ~CGuiGlut(){}

	//----------------------------------------------------------
	// intialisation du GUI
	//----------------------------------------------------------
	static void InitializeGraphics(int argc, char **argv, CApplication* application);

	//----------------------------------------------------------
	// instruction a lancer pour le rendu de la scene
	//----------------------------------------------------------
	static void RunGraphics (void);
	
protected:	// les fonctions suivantes peuvent �tre appel�es seulement pas cettte m�me classe et les classes filles de cette classe
	
	static void InitGL(void);
	static void ReshapeFunc(int width, int height);
	static void DisplayFunc(void);
	static void KeyboardFunc(unsigned char key, int /*x*/, int /*y*/);
	static void SpecialFunc(int key, int /*x*/, int /*y*/);
	
	// application
	static CApplication*	m_application;

	// The number of our GLUT window
	static	int			windowID;
	static	std::string	appVersionName;
	static	bool		gMouseAdjustingCameraAngle ;
	static	bool		gMouseAdjustingCameraRadius ;
	static	int			gMouseAdjustingCameraLastX;
	static	int			gMouseAdjustingCameraLastY;

};



#endif // __GUI_H__ fin de la routine