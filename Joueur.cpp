#include "Joueur.h"
#include<cmath>
#include<osg/vec3f>
#include <vector>

using namespace osg;

Joueur::Joueur(osg::Vec3f pos, osg::Vec3f dir, int num) : Avion()
{
	position = pos;
	direction = dir;
	camp=false;
	id=num;
}

Joueur::~Joueur(){
}

void Joueur::avancer(int cube_size) : avion(int cube_size){//i correspond à la place de l'avion dans le vecteur, ne pas oublier de mettre le bon argument dans le main
    position += direction/(sqrt(direction[0]**2+direction.[1]**2+direction[2]**2));
    float taille = (float)cube_size;
}

void Joueur::strategie(std::vector<Avion> v){

    //Strategie hors mur
    //Si on peut pointer (cône 45degree) vers un avion ennemi (qui avance
    //d'une case dans sa propre direction) alors on tourne et on tir si on peu
    //Si on ne peut pas pointer on va se diriger vers l'avion ennemi le plus proche

    int indiceProche = -1; //indice de l'avion ennemi  le plus proche
    float angleMin = -1;
    for (int i = 0; i< v.size();i++)
    {
        if (v[i].getCamp) //avion ennemi
        {
            Vec3f posFuture = v[i].getPosition +v[i].getDirection - position;
            posFuture.normalize();
            float prodScal = posFuture^direction;
            if (prodScal<angleMin || angleMin == -1)
            {
                angleMin = acos(prodScal);
                indiceProche = i;
            }
        }
    }
    //on a l'avion le plus proche
    //decision tir
    if (angleMin<45 && !cooldown)
    {
        tir = true;
    }
    else{
        tir = false;
    }
    //deplacement vers l'avion le plus proche
    if (angleMin< 80)
    {
        angle = min(angleMin, 45.0f);

    }


    //Prevoir l'evitement des murs
     for (int i = 0; i< v.size();i++)
    {
        if (v[i].camp == 0)
    }

}