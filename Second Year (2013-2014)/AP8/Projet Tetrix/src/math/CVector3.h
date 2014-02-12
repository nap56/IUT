//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================


#ifndef _Math_Vector3_H
#define _Math_Vector3_H
#include <limits>
#include <iostream>
#include <cmath>


class CVector3
{
public :

    //----------------------------------------------------------
    // Constructeur par d�faut
    //----------------------------------------------------------
    CVector3(float X = 0, float Y = 0, float Z = 0);

    //----------------------------------------------------------
    // R�initialise le vecteur
    //----------------------------------------------------------
    void Set(float X, float Y, float Z);

    //----------------------------------------------------------
    // Renvoie la norme du vecteur
    //----------------------------------------------------------
    float Length() const;

    //----------------------------------------------------------
    // Renvoie la norme au carr� du vecteur
    //----------------------------------------------------------
    float LengthSq() const;

    //----------------------------------------------------------
    // Normalise le vecteur
    //----------------------------------------------------------
    void Normalize();

    //----------------------------------------------------------
    // Op�rateurs unaires + et -
    //----------------------------------------------------------
    CVector3 operator +() const;
    CVector3 operator -() const;

    //----------------------------------------------------------
    // Op�rateurs binaires + et -
    //----------------------------------------------------------
    CVector3 operator +(const CVector3& v) const;
    CVector3 operator -(const CVector3& v) const;

    //----------------------------------------------------------
    // Op�rateurs += et -=
    //----------------------------------------------------------
    const CVector3& operator +=(const CVector3& v);
    const CVector3& operator -=(const CVector3& v);

    //----------------------------------------------------------
    // Op�rateurs *= et /=
    //----------------------------------------------------------
    const CVector3& operator *=(float t);
    const CVector3& operator /=(float t);

    //----------------------------------------------------------
    // Op�rateurs de comparaison
    //----------------------------------------------------------
    bool operator ==(const CVector3& v) const;
    bool operator !=(const CVector3& v) const;

    //----------------------------------------------------------
    // Op�rateur de cast en float*
    //----------------------------------------------------------
    operator float*();

    //----------------------------------------------------------
    // Donn�es membres
    //----------------------------------------------------------
    float x; ///< Composante X
    float y; ///< Composante Y
    float z; ///< Composante Z
};


//==========================================================
// Fonctions globales relatives aux vecteurs
//==========================================================
 CVector3   operator * (const CVector3& v, float t);
 CVector3   operator / (const CVector3& v, float t);
 CVector3   operator * (float t, const CVector3& v);
 float     Dot  (const CVector3& v1, const CVector3& v2);
 CVector3   Cross(const CVector3& v1, const CVector3& v2);
 std::istream& operator >>(std::istream& Stream, CVector3& Vector);
 std::ostream& operator <<(std::ostream& Stream, const CVector3& Vector);


 /////////////////////////////////////////////////////////////
/// Constructeur par d�faut
///
/// \param X : Composante X du vecteur
/// \param Y : Composante Y du vecteur
/// \param Z : Composante Z du vecteur
///
////////////////////////////////////////////////////////////
inline CVector3::CVector3(float X, float Y, float Z) : x(X),y(Y),z(Z)
{
}


/////////////////////////////////////////////////////////////
/// R�initialise le vecteur
///
/// \param X : Composante X du vecteur
/// \param Y : Composante Y du vecteur
/// \param Z : Composante Z du vecteur
///
////////////////////////////////////////////////////////////
inline void CVector3::Set(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}


/////////////////////////////////////////////////////////////
/// Renvoie la norme du vecteur
///
/// \return Valeur de la norme du vecteur sqrt(x� + y� + z�)
///
////////////////////////////////////////////////////////////
inline float CVector3::Length() const
{
    return std::sqrt(LengthSq());
}


/////////////////////////////////////////////////////////////
/// Renvoie la norme au carr� du vecteur
///
/// \return Carr� de la norme du vecteur (x� + y� + z�)
///
////////////////////////////////////////////////////////////
inline float CVector3::LengthSq() const
{
    return x * x + y * y + z * z;
}


/////////////////////////////////////////////////////////////
/// Normalise le vecteur
///
////////////////////////////////////////////////////////////
inline void CVector3::Normalize()
{
    float Norm = Length();

    if (std::abs(Norm) > std::numeric_limits<float>::epsilon())
    {
        x /= Norm;
        y /= Norm;
        z /= Norm;
    }
}


/////////////////////////////////////////////////////////////
/// Op�rateur unaire +
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////
inline CVector3 CVector3::operator +() const
{
    return (*this);
}


/////////////////////////////////////////////////////////////
/// Op�rateur unaire -
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////

inline CVector3 CVector3::operator -() const
{
    return CVector3(-x, -y, -z);
}


/////////////////////////////////////////////////////////////
/// Op�rateur binaire +
///
/// \param v : Vecteur � additionner
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////

inline CVector3 CVector3::operator +(const CVector3& v) const
{
    return CVector3(x + v.x, y + v.y, z + v.z);
}


/////////////////////////////////////////////////////////////
/// Op�rateur binaire -
///
/// \param v : Vecteur � soustraire
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////

inline CVector3 CVector3::operator -(const CVector3& v) const
{
    return CVector3(x - v.x, y - v.y, z - v.z);
}

/////////////////////////////////////////////////////////////
/// Op�rateur +=
///
/// \param v : Vecteur � additioner
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////
inline const CVector3& CVector3::operator +=(const CVector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;

    return *this;
}


/////////////////////////////////////////////////////////////
/// Op�rateur -=
///
/// \param v : Vecteur � soustraire
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////
inline const CVector3& CVector3::operator -=(const CVector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;

    return *this;
}


/////////////////////////////////////////////////////////////
/// Op�rateur *= avec un scalaire
///
/// \param t : Scalaire
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////
inline const CVector3& CVector3::operator *=(float t)
{
    x *= t;
    y *= t;
    z *= t;

    return *this;
}


/////////////////////////////////////////////////////////////
/// Op�rateur /= avec un scalaire
///
/// \param t : Scalaire
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////
inline const CVector3& CVector3::operator /=(float t)
{
    x /= t;
    y /= t;
    z /= t;

    return *this;
}


/////////////////////////////////////////////////////////////
/// Op�rateur de comparaison ==
///
/// \param v : Vecteur � comparer
///
/// \return True si les deux vecteurs sont identiques
///
////////////////////////////////////////////////////////////
inline bool CVector3::operator ==(const CVector3& v) const
{
    return ((std::abs(x - v.x) <= std::numeric_limits<float>::epsilon()) &&
            (std::abs(y - v.y) <= std::numeric_limits<float>::epsilon()) &&
            (std::abs(z - v.z) <= std::numeric_limits<float>::epsilon()));
}


/////////////////////////////////////////////////////////////
/// Op�rateur de comparaison !=
///
/// \param v : Vecteur � comparer
///
/// \return True si les deux vecteurs sont diff�rents
///
////////////////////////////////////////////////////////////
inline bool CVector3::operator !=(const CVector3& v) const
{
    return !(*this == v);
}


/////////////////////////////////////////////////////////////
/// Op�rateur de cast en float*
///
/// \return Pointeur sur les composantes du vecteur
///
////////////////////////////////////////////////////////////
inline CVector3::operator float*()
{
    return &x;
}


/////////////////////////////////////////////////////////////
/// Op�rateurs de multiplication avec un scalaire
///
/// \param v : Vecteur
/// \param t : Scalaire
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////
inline CVector3 operator *(const CVector3& v, float t)
{
    return CVector3(v.x * t, v.y * t, v.z * t);
}


/////////////////////////////////////////////////////////////
/// Op�rateurs de division par un scalaire
///
/// \param v : Vecteur
/// \param t : Scalaire
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////
inline CVector3 operator /(const CVector3& v, float t)
{
    return CVector3(v.x / t, v.y / t, v.z / t);
}


/////////////////////////////////////////////////////////////
/// Op�rateurs de multiplication avec un scalaire
///
/// \param t : Scalaire
/// \param v : Vecteur
///
/// \return R�sultat de l'op�ration
///
////////////////////////////////////////////////////////////
inline CVector3 operator *(float t, const CVector3& v)
{
    return v * t;
}


/////////////////////////////////////////////////////////////
/// Effectue le produit scalaire entre deux vecteurs
///
/// \param v1 : Vecteur 1
/// \param v2 : Vecteur 2
///
/// \return R�sultat du produit scalaire
///
////////////////////////////////////////////////////////////
inline float Dot(const CVector3& v1, const CVector3& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


/////////////////////////////////////////////////////////////
/// Effectue le produit vectoriel entre deux vecteurs
///
/// \param v1 : Vecteur 1
/// \param v2 : Vecteur 2
///
/// \return R�sultat du produit vectoriel
///
////////////////////////////////////////////////////////////
inline CVector3 Cross(const CVector3& v1, const CVector3& v2)
{
    return CVector3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}


/////////////////////////////////////////////////////////////
/// Surcharge de l'op�rateur >> entre un flux et un vecteur
///
/// \param Stream : Flux d'entr�e
/// \param Vector : Vecteur
///
/// \return R�f�rence sur le flux d'entr�e
///
////////////////////////////////////////////////////////////

inline std::istream& operator >>(std::istream& Stream, CVector3& Vector)
{
    return Stream >> Vector.x >> Vector.y >> Vector.z;
}


/////////////////////////////////////////////////////////////
/// Surcharge de l'op�rateur << entre un flux et un vecteur
///
/// \param Stream : Flux de sortie
/// \param Vector : Vecteur
///
/// \return R�f�rence sur le flux de sortie
///
////////////////////////////////////////////////////////////

inline std::ostream& operator <<(std::ostream& Stream, const CVector3& Vector)
{
    return Stream << Vector.x << " " << Vector.y << " " << Vector.z;
}


#endif
