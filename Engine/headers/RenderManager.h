//
// Created by Ahmad Rahimi on 9/25/17.
//

#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H
#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "../../Game/point3d.h"
#include "../../Game/Camera.h"

using namespace std;

struct SDL_Window;
struct SDL_Renderer;

class RenderManager {
public:
	RenderManager();
	~RenderManager();

	SDL_Surface* LoadImage(const std::string &filePath);
	/* void BlitSurface
	* Drawing images on a screen
	*/
	void BlitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle, double angle = 0);

	/* void flip
	* Render everything on screen
	*/
	void Flip();

	/* void clear
	* Clear the screen
	*/
	void Clear();

	/* SDL_Renderer* getRenderer
	* Returns the renderer
	*/
	SDL_Renderer* GetRenderer() const;

	static RenderManager* Instance();

    static Camera &GetCamera();
	static float GetScreenSize();
    static bool DrawDebug;
	static bool DoRecalc;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	map<std::string, SDL_Surface*> sprites;
	static RenderManager *renderManager;
	static Camera Camera;
	static float ScreenSize;


};
#endif //RENDERMANAGER_H