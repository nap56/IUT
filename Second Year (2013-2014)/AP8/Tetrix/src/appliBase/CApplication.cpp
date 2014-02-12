//========================================================================
// Projet DUT C++ / Jeu Tetris
//
//------------------------------------------------------------------------
// Copyright (c) 2010-2011 Equipe SAMSARA (T. LE NAOUR, N. COURTY, S. GIBET)
// VALORIA - UBS 
//========================================================================


//-----------------------------------------------------------------
// On inclut les fichiers .h qui contiennent les d�clarations des m�thodes
// Les impl�mentations de nos m�thodes ont besoin de leurs d�clarations 
// ainsi que des d�clarations des fonctions OPENGL
//-----------------------------------------------------------------
#include "CApplication.h"

/////////////////////////////////////////////////////////////
/// Initialise le GUI (Graphic user interface), le renderer et l'application enfant
///
/// \return code d'erreur
////////////////////////////////////////////////////////////
void CApplication::Init() {

	// infos li�es � la souris/cam�ra (pointeur car paratag� par deux objets)
	m_UserEvents = new UserEvents				;

	// construction de la cam�ra
	m_camera = new CCameraLookAt();

	// D�claration du renderer (le renderer va automatiquement appeler son contructeur)
	m_renderer.Create(m_windowSetUp, m_UserEvents, m_camera)	;

	// appel � la m�thode de d�but enfant
	OnInit();

}


/////////////////////////////////////////////////////////////
/// lance la boucle d'affichage, g�re les �venements syst�me et le rendu de la sc�ne
///
////////////////////////////////////////////////////////////
void CApplication::Render() {

	// appel � la m�thode de rendu enfant
	OnRender();
}

/////////////////////////////////////////////////////////////
/// Fini l'application: d�truit les objets plus utilis�s
///
////////////////////////////////////////////////////////////
void CApplication::Release() {

	// appel � la m�thode de fin enfant
	OnRelease();

	//// on supprime la m�moire allou�e aux objets gui et mouse events
	//delete m_camera		;
	delete m_windowSetUp;
	delete m_UserEvents;
}
