

#include "MathFunctions.h"
#include <time.h>
#include "Vector.h"
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <string>
#include <conio.h>
#include <vector>
#include "bspflags.h"
#include "UTIL Functions.h"
#include "Interfaces.h"

void AngleVectors(const Vector &angles, Vector *forward)
{
	Assert(s_bMathlibInitialized);
	Assert(forward);

	float	sp, sy, cp, cy;

	sy = sin(DEG2RAD(angles[1]));
	cy = cos(DEG2RAD(angles[1]));

	sp = sin(DEG2RAD(angles[0]));
	cp = cos(DEG2RAD(angles[0]));

	forward->x = cp*cy;
	forward->y = cp*sy;
	forward->z = -sp;
}

void VectorTransform(const Vector in1, float in2[3][4], Vector &out)
{
	out[0] = DotProduct(in1, Vector(in2[0][0], in2[0][1], in2[0][2])) + in2[0][3];
	out[1] = DotProduct(in1, Vector(in2[1][0], in2[1][1], in2[1][2])) + in2[1][3];
	out[2] = DotProduct(in1, Vector(in2[2][0], in2[2][1], in2[2][2])) + in2[2][3];
}

void SinCos(float a, float* s, float*c)
{
	*s = sin(a);
	*c = cos(a);
}

void VectorAngles(Vector forward, Vector &angles)
{
	float tmp, yaw, pitch;

	if (forward[2] == 0 && forward[0] == 0)
	{
		yaw = 0;

		if (forward[2] > 0)
			pitch = 90;
		else
			pitch = 270;
	}
	else
	{
		yaw = (atan2(forward[1], forward[0]) * 180 / PI);

		if (yaw < 0)
			yaw += 360;

		tmp = sqrt(forward[0] * forward[0] + forward[1] * forward[1]);
		pitch = (atan2(-forward[2], tmp) * 180 / PI);

		if (pitch < 0)
			pitch += 360;
	}

	if (pitch > 180)
		pitch -= 360;
	else if (pitch < -180)
		pitch += 360;

	if (yaw > 180)
		yaw -= 360;
	else if (yaw < -180)
		yaw += 360;

	if (pitch > 89)
		pitch = 89;
	else if (pitch < -89)
		pitch = -89;

	if (yaw > 180)
		yaw = 180;
	else if (yaw < -180)
		yaw = -180;

	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0;
}

void AngleVectors(const Vector &angles, Vector *forward, Vector *right, Vector *up)
{
	float sr, sp, sy, cr, cp, cy;

	SinCos(DEG2RAD(angles[1]), &sy, &cy);
	SinCos(DEG2RAD(angles[0]), &sp, &cp);
	SinCos(DEG2RAD(angles[2]), &sr, &cr);

	if (forward)
	{
		forward->x = cp*cy;
		forward->y = cp*sy;
		forward->z = -sp;
	}

	if (right)
	{
		right->x = (-1 * sr*sp*cy + -1 * cr*-sy);
		right->y = (-1 * sr*sp*sy + -1 * cr*cy);
		right->z = -1 * sr*cp;
	}

	if (up)
	{
		up->x = (cr*sp*cy + -sr*-sy);
		up->y = (cr*sp*sy + -sr*cy);
		up->z = cr*cp;
	}
}

void Normalize(Vector &vIn, Vector &vOut)
{
	float flLen = vIn.Length();
	if (flLen == 0) {
		vOut.Init(0, 0, 1);
		return;
	}
	flLen = 1 / flLen;
	vOut.Init(vIn.x * flLen, vIn.y * flLen, vIn.z * flLen);
}


void CalcAngle(Vector src, Vector dst, Vector &angles)
{
	Vector delta = src - dst;
	double hyp = delta.Length2D(); //delta.Length
	angles.y = (atan(delta.y / delta.x) * 57.295779513082f);
	angles.x = (atan(delta.z / hyp) * 57.295779513082f);
	angles[2] = 0.00;

	if (delta.x >= 0.0)
		angles.y += 180.0f;
}

Vector CalcAngleUC(Vector& src, Vector& dst)
{
	Vector vAngle;
	Vector delta((src.x - dst.x), (src.y - dst.y), (src.z - dst.z));
	double hyp = sqrt(delta.x*delta.x + delta.y*delta.y);

	vAngle.x = (float)(asinf((delta.z + 64.06f) / hyp) * 57.295779513082f);
	vAngle.y = (float)(atanf(delta.y / delta.x) * 57.295779513082f);
	vAngle.z = 0.0f;

	if (delta.x >= 0.0)
		vAngle.y += 180.0f;

	return vAngle;
}

bool IsVisible(IClientEntity* pLocal, IClientEntity* pEntity, int BoneID)
{
	if (BoneID < 0) return false;

	trace_t Trace;
	Vector start = pLocal->GetOrigin() + pLocal->GetViewOffset();
	Vector end = GetHitboxPosition(pEntity, BoneID);//pEntity->GetBonePos(BoneID);

	UTIL_TraceLine(start, end, MASK_SOLID, pLocal, 0, &Trace);

	if (Trace.m_pEnt == pEntity)
	{
		return true;
	}

	if (Trace.fraction == 1.0f)
	{
		return true;
	}

	return false;
}

bool IsVisible1337(IClientEntity* pLocalClientBaseCBaseEntity, Vector vecOrigin, Vector vecFinal, IClientEntity* pClientBaseCBaseEntity)
{
	Ray_t ray;
	ray.Init(vecOrigin, vecFinal);

	CTraceFilter TraceFilter;
	TraceFilter.pSkip = pLocalClientBaseCBaseEntity;

	trace_t trace;
	Interfaces::Trace->TraceRay(ray, MASK_SHOT, &TraceFilter, &trace);

	return (trace.m_pEnt == pClientBaseCBaseEntity || trace.fraction >= 1.0f);
}

bool IsVisibleAllBones(IClientEntity* pEntity)
{
	if (pEntity != nullptr)
	{
		if (!pEntity->IsAlive())
			return false;

		Vector vSrcOrigin = pEntity->GetEyePosition();

		if (vSrcOrigin.IsZero() || !vSrcOrigin.IsValid())
			return false;

		BYTE bHitBoxCheckVisible[20] = {
			(int)CSGOHitboxID::Stomach, //1
			(int)CSGOHitboxID::Pelvis, //2
			(int)CSGOHitboxID::UpperChest, //3
			(int)CSGOHitboxID::Chest, //4
			(int)CSGOHitboxID::LowerChest, //5
			(int)CSGOHitboxID::Head, //6
			(int)CSGOHitboxID::Neck, //7
			(int)CSGOHitboxID::NeckLower, //8
			(int)CSGOHitboxID::LeftUpperArm, //9
			(int)CSGOHitboxID::RightUpperArm, //10
			(int)CSGOHitboxID::LeftThigh, //11
			(int)CSGOHitboxID::RightThigh, //12
			(int)CSGOHitboxID::LeftHand, //13
			(int)CSGOHitboxID::RightHand, //14
			(int)CSGOHitboxID::LeftFoot, //15
			(int)CSGOHitboxID::RightFoot, //16
			(int)CSGOHitboxID::LeftShin, //17
			(int)CSGOHitboxID::RightShin, //18
			(int)CSGOHitboxID::LeftLowerArm, //19
			(int)CSGOHitboxID::RightLowerArm, //20
		};

		CTraceFilter filter;

		filter.pSkip = pEntity;

		for (int nHit = 0; nHit < 6; nHit++)
		{
			Vector vHitBox = GetHitboxPosition(pEntity, bHitBoxCheckVisible[nHit]);

			if (vHitBox.IsZero() || !vHitBox.IsValid())
				continue;

			trace_t tr;
			Ray_t ray;

			ray.Init(vSrcOrigin, vHitBox);



			Interfaces::Trace->TraceRay(ray, PlayerVisibleMask, &filter, &tr);

			if (tr.m_pEnt == (IClientEntity*)pEntity && !tr.allsolid)
				return true;
		}

		return false;
	}
}

void NormalizeVector(Vector& vec) {
	for (int i = 0; i < 3; ++i) {
		while (vec[i] > 180.f)
			vec[i] -= 360.f;

		while (vec[i] < -180.f)
			vec[i] += 360.f;
	}
	vec[2] = 0.f;
}

void CalcAngleYawOnly(Vector src, Vector dst, Vector &angles)
{
	Vector delta = src - dst;
	double hyp = delta.Length2D();
	angles.y = (atan(delta.y / delta.x) * 57.295779513082f);
	//	angles.x = (atan(delta.z / hyp) * 57.295779513082f);
	angles[2] = 0.00;

	if (delta.x >= 0.0)
		angles.y += 180.0f;
}

inline Vector ExtrapolateTick(Vector p0, Vector v0)
{
	return p0 + (v0 * Interfaces::Globals->interval_per_tick);
}

Vector IClientEntity::GetPredicted(Vector p0)
{
	return ExtrapolateTick(p0, this->GetVelocity());
}