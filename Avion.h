#pragma once
#include <osg/Vec3f>

class Avion{

protected:
	osg::Vec3f position;
	osg::Vec3f direction; // direction actuelle
	osg::Vec3f up; // vecteur up
	bool cooldown; // est ce qu'on a tiré le tour d'avant
	bool tir; // est ce qu'on tire 
	float angle; // demandez à mael xD
	float cap; // demandez à mael  (c'est de la 3D lol)
	bool camp; // 0 pour le joueur 1 pour lennemi
	int id;
	
public:
	Avion();

	osg::Vec3f getPosition(){return position;};
	osg::Vec3f getDirection(){return direction;};
	osg::Vec3f getUp(){return up;};
	bool getCooldown(){return cooldown;};
	bool getTir(){return tir;};
	float getAngle(){return angle;};
	float getCap(){return cap;};
	bool getCamp(){return camp;};
	int getId(){return id;};

	void setPosition(osg::Vec3f _position){ position=_position;};
	void setDirection(osg::Vec3f _direction){ direction=_direction;};
	void setUp(osg::Vec3f _up){ up=_up;};
	void setCooldown(bool _cooldown){ cooldown=_cooldown;};
	bool setTir(bool _tir){ tir=_tir;};
	float setAngle(float _angle){ angle=_angle;};
	float setCap(float _cap){ cap=_cap;};
	void setCamp(bool _camp){ camp=_camp;};

	virtual void avancer(int cube_size); //On a défini la fonction vide dans le cpp
	void tourner(float tang, float dir);
	void tirer();
	virtual void strategie(std::vector<Avion> v)=0;
	~Avion();
};
