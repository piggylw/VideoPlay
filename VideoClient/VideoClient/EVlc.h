#pragma once
#include "vlc.h"
#include <string>

class VlcSize {
public:
	int width;
	int height;
	VlcSize(int w = 0, int h = 0)
	{
		width = w;
		height = h;
	}
	VlcSize(const VlcSize& size)
	{
		width = size.width;
		height = size.height;
	}

	VlcSize& operator=(const VlcSize& size)
	{
		width = size.width;
		height = size.height;
	}
};
class EVlc
{
public:
	EVlc();
	~EVlc();
	int SetMedia(const std::string& strUrl);
	int Play();
	int Pause();
	int Stop();
	int SetHwnd(HWND hWnd);
	float GetPostion();
	void SetPosion(float pos);
	int GetVolume();
	int SetVolume(int volume);
	VlcSize GetMediaInfo();
protected:
	libvlc_instance_t* m_instance;
	libvlc_media_t* m_media;
	libvlc_media_player_t* m_player;
};

