//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================


//=====================================================================
// classe APPLICATION, s'occupe d'encapsuler l'ensemble des fonction communes � une application
//=====================================================================
#ifndef __APPLICATION_H__	// routine qui sert � pas inclure 2 fois le m�me fichier
#define __APPLICATION_H__	//



//-----------------------------------------------------------------
// Notre programme va avoir besoin 
// des fonctions sp�cifiques � l'utilisateur (iterface graphique utilisateur GUI) et
// des fonctions n�c�ssaires au rendu d'un objet dans la scene
//
// On inclu les fichiers .h qui contiennent les d�clarations des fonctions
//-----------------------------------------------------------------
#include "Common.h"				// donn�es li�es � la souris
#include "CRenderer.h"			// objet CRenderer


////////////////////////////////////////////////////////////////////////
/// classe CApplication: elle encapsule l'ensemble de l'application � savoir l'utilisation du GUI et du renderer
/// L'objectif �tant qu'elle sert de classe commune � ttes applications qui se serviront des fonctions suivantes
////////////////////////////////////////////////////////////////////////
class CApplication {

public:
	//----------------------------------------------------------
	// constructeur de l'objet
	//----------------------------------------------------------
	CApplication() 
		:m_windowSetUp(new WindowSetup(800, 640)), m_UserEvents(0), m_camera(0)  {}

	//----------------------------------------------------------
	// destructeur de l'objet
	//----------------------------------------------------------
	virtual ~CApplication(){}

	//----------------------------------------------------------
	// initilisation de l'appli
	//----------------------------------------------------------
	void Init()		;

	//----------------------------------------------------------
	// boucle de rendu
	//----------------------------------------------------------
	void Render()		;

	//----------------------------------------------------------
	// fin de l'appli, destruction et nettoyage des objets utilis�*
	// au cour de l'appli
	//----------------------------------------------------------
	void Release()	;


	//----------------------------------------------------------
	// appel � la structure des �v�nements utilisateur
	//----------------------------------------------------------
	UserEvents*	GetUserEvents();

	//----------------------------------------------------------
	// appel � la structure de config de la fen�tre
	//----------------------------------------------------------
	WindowSetup*	GetWindowInfo();

protected:

	//==================================================================
	// M�thodes d�di�es � l'h�ritage
	//==================================================================
	//----------------------------------------------------------
	// l'appel � la fonction d'initialisation de notre sous objet "appli sp�cifique"
	//----------------------------------------------------------
	virtual bool OnInit() = 0;

	//----------------------------------------------------------
	// l'appel � la fonction de  rendu de notre sous objet "appli sp�cifique"
	//----------------------------------------------------------
	virtual void OnRender() = 0;

	//----------------------------------------------------------
	// l'appel � la fonction de destruction de notre sous objet "appli sp�cifique"
	//----------------------------------------------------------
	virtual void OnRelease() = 0;


	//----------------------------------------------------------
	// Donn�es membres
	//----------------------------------------------------------
	WindowSetup*	m_windowSetUp;	///< infos li�es � la fen�tre (pointeur car paratag� par deux objets)
	CRenderer		m_renderer	;	///< D�claration du renderer 
	UserEvents*		m_UserEvents;	///< infos li�es � la souris/cam�ra (pointeur car paratag� par deux objets)
	CCamera*			m_camera	;	// la camera
};

inline WindowSetup*		CApplication::GetWindowInfo()		{ return m_windowSetUp;}
inline UserEvents*		CApplication::GetUserEvents()		{ return m_UserEvents;}



#endif // __APPLICATION_H__ fin de la routine
