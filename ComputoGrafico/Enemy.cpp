#include "Enemy.h"

Enemy::Enemy(Player* player,std::string path)
{
	this->player = player;
	model.LoadModel(path);
	model.AddTexture("Assets/Textures/textureBender.png");
	transform.SetTranslation(0.0f, 0.0f, -20.0f);
}

void Enemy::Draw()
{
	transform.SetScale(1.0f, 1.0f, 1.0f);//adidier
	transform.SetRotation(0, 0, 0);
	model.SetTransform(transform);
	model.Draw();
}

void Enemy::Update()
{
	glm::vec3 dir = player->GetCamera()->getCameraPosition() - transform.GetTranslation();
	dir = glm::normalize(dir)*0.005f;
	transform.SetTranslation(transform.GetTranslation().x + dir.x,
		transform.GetTranslation().y + dir.y,
		transform.GetTranslation().z + dir.z);
}