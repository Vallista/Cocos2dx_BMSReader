#pragma once

typedef enum E_SCENE_TYPE_tag
{
	E_PUSH_SCENE = 0,
	E_REPLACE_SCENE,
	E_SCENE_MAX,
}E_SCENE_TYPE;

typedef enum E_CHANGE_SCENE_tag{
	
	E_CHANGE_CROSSFADE		= 0,
	E_CHANGE_FADE			,
	E_CHANGE_FADEBL			,
	E_CHANGE_FADEDOWN		,
	E_CHANGE_FADETR			,
	E_CHANGE_FADEUP			,
	E_CHANGE_FLIPANGULAR	,
	E_CHANGE_FLIPX			,
	E_CHANGE_FLIPY			,
	E_CHANGE_JUMPZOOM		,
	E_CHANGE_MOVEINB		,
	E_CHANGE_MOVEINL		,
	E_CHANGE_MOVEINR		,
	E_CHANGE_MOVEINT		,
	E_CHANGE_PAGETURN		,
	E_CHANGE_ROTOZOOM		,
	E_CHANGE_SLIDEINB		,
	E_CHANGE_SLIDEINR		,
	E_CHANGE_SLIDEINL		,
	E_CHANGE_SLIDEINT		,
	E_CHANGE_ZOOMFLIPX		,
	E_CHANGE_ZOOMFLIPY		,
	E_CHANGE_MAX			,

}E_CHANGE_SCENE;

class CSurportManager
{
public:
	static CSurportManager* instance()
	{
		static CSurportManager instance;

		return &instance;
	}

	CSurportManager()
	{
		
	}

	~CSurportManager()
	{

	}

public:
	static void ChangeScene(E_CHANGE_SCENE sceneType , E_SCENE_TYPE type, CCScene* pTargetScene , float fChangeTime = 1.0f);
	static string* StringSplit(string strOrigin, string strTok);

	template<typename T>
	static T SmoothStep(T value1, T value2, float amount)
	{
		float num = Clamp(amount, 0.0f, 1.0f);
		return Lerp(value1, value2, (num * num) * (3.0f - (2.0f * num)));
	}

	static int Clamp(int value, int min, int max)
	{
		return Max(min, Min(max, value));
	}

	static float Clamp(float value, float min, float max)
	{
		return Max(min, Min(max, value));
	}

	static double Clamp(double value, double min, double max)
	{
		return Max(min, Min(max, value));
	}

	template<typename T>
	static T Min(T value1, T value2)
	{
		return value1 < value2 ? value1 : value2;
	}

	template<typename T>
	static T Max(T value1, T value2)
	{
		return value1 > value2 ? value1 : value2;
	}

	template<typename T>
	static T Lerp(T value1, T value2, float amount)
	{
		return T(value1 + ((T)(value2 - value1) * amount ));
	}
};