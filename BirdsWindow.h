#ifndef BIRDSWINDOW_H_
#define BIRDSWINDOW_H_

#include "Window.h"
#include "Texture.h"
#include "LayerTexture.h"

class BirdsWindow final: public Window
{
private:
	Texture _birds;
	Texture _eagle;
	Texture _oblako;
	Texture _sun;
	Texture _background;
	LayerTexture _mountains;
	LayerTexture _mount;
	LayerTexture _mountain;

//	int x, y, w, h;
	double sun_x, sun_y;
	double phase[5];
	double eagle_x, eagle_y;
	static constexpr int BIRDS_WINDOW_WIDTH = 800;
	static constexpr int BIRDS_WINDOW_HEIGHT = 600;

	SDL_FRect birds[5] {
			{10.0, 20.0, 50.0, 50.0},
			{500.0, 400.0, 50.0, 50.0},
			{150.0, 200.0, 50.0, 50.0},
			{350.0, 108.0, 50.0, 50.0},
			{120.0, 50.0, 50.0, 50.0},
		};

	SDL_FRect clouds[6] {
		{128.0, 200.0, 228.0, 164.0},
		{356.0, 430.0, 292.0, 170.0},
		{500.0, 340.0, 260.0, 190.0},
		{10.0, 40.0, 384.0, 192.0},
		{320.0, 179.0, 180.0, 200.0},
		{220.0, 230.0, 400.0, 300.0},
	};
public:
	BirdsWindow();
	virtual ~BirdsWindow() = default;

	virtual void render() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void update() override;
};


#endif /* BIRDSWINDOW_H_ */
