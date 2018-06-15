

#pragma once

#include "Hacks.h"

Vector GetAutostrafeView();

class CMiscHacks : public CHack
{
public:
	void Init();
	void Draw();
	void RotateMovement(CInput::CUserCmd * pCmd, float rotation);
	void walkbot(CInput::CUserCmd * pCmd, IClientEntity * pLocal);
	void lby();
	bool doCircularStrafe(CInput::CUserCmd * pCmd, Vector & OriginalView);
	void Move(CInput::CUserCmd *pCmd, bool &bSendPacket);
	void FakeWalk(CInput::CUserCmd * pCmd, bool & bSendPacket);
private:
	void AutoJump(CInput::CUserCmd *pCmd);
	void AutoJumpSMAC(CInput::CUserCmd *pCmd);
	void EdgeJump(CInput::CUserCmd *pCmd);
	void Walkbot(CInput::CUserCmd *pCmd);
	void PerfectStrafe(CInput::CUserCmd *pCmd);
	void LegitStrafe(CInput::CUserCmd *pCmd);
	void RageStrafe(CInput::CUserCmd *pCmd);
	void ChatSpamInterwebz();
	void Crutcke(CInput::CUserCmd * pCmd);
	void circlestrafer(CInput::CUserCmd * cmd);
	void ChatSpamName();
	void ChatSpamDisperseName();
	void Grenade();
	void ChatSpamRegular();
	void ChatSpamReports();
	void ChatSpamCallout();
	//void ChatSpamAchievement();
	//void NameDispersion();
	//void ChatSpamAchievement();
	void Fakelag(CInput::CUserCmd *pCmd, bool &bSendPacket);

	//std::string GetNameChange();

	/*void ChatSpam();
	void Namechanger();

	std::string GetRegularSpam();
	std::string GetCustomSpam();
	std::string GetPlayerSpam();
	std::string GetSinglePlayerSpam();

	std::string GetNameChange();
	std::string GetNameCalloutChange();*/
	void circlestrafer(CInput::CUserCmd * cmd, Vector & Originalview);
};



