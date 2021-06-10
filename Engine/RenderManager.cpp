//
// Created by Ahmad Rahimi on 9/25/17.
//

#include <SDL_ttf.h>
#include "headers/RenderManager.h"


RenderManager* RenderManager::renderManager;
Camera RenderManager::Camera = {-250,-470,-5};
float RenderManager::ScreenSize = 720;
bool RenderManager::DrawDebug = true;
bool RenderManager::DoRecalc = false;
RenderManager::RenderManager() {
	SDL_CreateWindowAndRenderer(720, 720, 0, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window, "Shooter");
	SDL_Surface* surface = SDL_GetWindowSurface(this->window);
    TTF_Init();
}

RenderManager::~RenderManager() {
	SDL_DestroyWindow(this->window);
}

SDL_Surface* RenderManager::LoadImage(const std::string &filePath) {
	if (this->sprites.count(filePath) == 0) {
		this->sprites[filePath] = IMG_Load(filePath.c_str());
	}
	return this->sprites[filePath];
}

void RenderManager::BlitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle,
	double angle) {
	int resp = SDL_RenderCopyEx(this->renderer, texture, sourceRectangle, destinationRectangle, angle, NULL, SDL_FLIP_HORIZONTAL);
	if (resp != 0) {
		std::cout << SDL_GetError() << std::endl;
	}
}

RenderManager* RenderManager::Instance() {
	if (!renderManager) {
		renderManager = new RenderManager;
	}
	return renderManager;
}

void RenderManager::Flip() {
	SDL_RenderPresent(this->renderer);
}

void RenderManager::Clear() {
	SDL_RenderClear(this->renderer);
}

SDL_Renderer* RenderManager::GetRenderer() const {
	return this->renderer;
}

Camera &RenderManager::GetCamera() {
	return Camera;
}

float RenderManager::GetScreenSize() {
	return RenderManager::ScreenSize;
}
