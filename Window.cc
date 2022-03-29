#include "Window.h"
#include <iostream>

Window::Window(int w, int h)
: _width(w), _height(h)
{
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow("SDL Window",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					w, h,
					SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);
	if (_window == nullptr) {
			std::cerr <<
					"Не могу создать окно: " <<
				SDL_GetError() << std::endl;
		exit(1);
	}
	_renderer = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(_window.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (_renderer == nullptr) {
		std::cerr <<
				"Не могу создать рендерер: " <<
				SDL_GetError()
				<< std::endl;
		exit(1);
	}
}

void Window::main_loop()
{
	auto keys = SDL_GetKeyboardState(nullptr);

	SDL_Event event;
	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.scancode){
				case SDL_SCANCODE_ESCAPE: return;
				default:
					;
				}
			}
			handle_event(event);
		}

		handle_keys(keys);
		update();
		render();
		SDL_RenderPresent(_renderer.get());
	}
}
