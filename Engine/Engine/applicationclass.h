////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "inputclass.h"
#include "d3dclass.h"
#include "cameraclass.h"
#include "terrainclass.h"
#include "timerclass.h"
#include "fpsclass.h"
#include "cpuclass.h"
#include "fontshaderclass.h"
#include "textclass.h"
#include "terrainshaderclass.h"
#include "lightclass.h"
#include "simplexnoisegenerator.h"
#include "skydomeclass.h"
#include "skydomeshaderclass.h"
#include "trackclass.h"
#include "modelshaderclass.h"
#include "lightshaderclass.h"
#include "modelclass.h"
#include "car.h"
#include "screenobjectclass.h"
#include "textureshaderclass.h"
#include "rendertextureclass.h"
#include "collisionclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: ApplicationClass
////////////////////////////////////////////////////////////////////////////////
class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

private:
	bool HandleInput(float);
	bool RenderGraphics();
	bool RenderToTexture();
	bool RenderScene(D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix);

private:
	InputClass* m_Input;
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	TerrainClass* m_Terrain;
	TimerClass* m_Timer;
	FpsClass* m_Fps;
	CpuClass* m_Cpu;
	FontShaderClass* m_FontShader;
	TextClass* m_Text;
	TerrainShaderClass* m_TerrainShader;
	LightClass* m_Light;
	SimplexNoiseGenerator m_NoiseGenerator;
	SkyDomeClass* m_SkyDome;
	SkyDomeShaderClass* m_SkyDomeShader;
	TrackClass* m_Racetrack;
	ModelShaderClass* m_ModelShader;
	LightShaderClass* m_LightShader;
	Car* m_PlayerCar;
	ModelClass* m_PlayerCarModel;
	Car* m_AICar;
	ModelClass* m_AICarModel;
	ScreenObjectClass* m_WingMirror;
	TextureShaderClass* m_TextureShader;
	D3DXMATRIX screenViewMatrix = D3DXMATRIX(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, -4.0f, 4.0f, 1.0f);
	RenderTextureClass* m_RenderTexture;
	ScreenObjectClass* m_RearView;
	CollisionClass* m_Collision;

	int debugCount = 2;
	ModelClass* m_Model[2];

	int m_screenWidth;
	int m_screenHeight;
};

#endif