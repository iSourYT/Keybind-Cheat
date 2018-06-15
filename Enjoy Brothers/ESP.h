#pragma once

#include "Hacks.h"

class CEsp : public CHack
{
public:

	inline float CSGO_Armor(float flDamage, int ArmorValue)
	{
		float flArmorRatio = 0.5f;
		float flArmorBonus = 0.5f;
		if (ArmorValue > 0) {
			float flNew = flDamage * flArmorRatio;
			float flArmor = (flDamage - flNew) * flArmorBonus;

			if (flArmor > static_cast<float>(ArmorValue)) {
				flArmor = static_cast<float>(ArmorValue) * (1.f / flArmorBonus);
				flNew = flDamage - flArmor;
			}

			flDamage = flNew;
		}
		return flDamage;
	}


	int tr = 255;
	int tg = 0;
	int tb = 0;

	int trv = 255;
	int tgv = 255;
	int tbv = 0;

	int ctr = 0;
	int ctg = 0;
	int ctb = 255;

	int ctrv = 0;
	int ctgv = 255;
	int ctbv = 255;
	void Init();
	void Draw();
	void DrawPlayer(IClientEntity * pEntity, player_info_t pinfo);
	void Move(CInput::CUserCmd *pCmd, bool &bSendPacket);
	struct ESPBox
	{
		int x, y, w, h;
	};
	bool CanWallbang(float & dmg);
	void SpecList();
	void DrawIcon(IClientEntity * pEntity, CEsp::ESPBox size);
private:
	IClientEntity * BombCarrier;


	void DrawBombPlanted(IClientEntity * pEntity, ClientClass * cClass);


	Color GetPlayerColor(IClientEntity * pEntity);

	Color GetPlayerColor2(IClientEntity * pEntity);


};