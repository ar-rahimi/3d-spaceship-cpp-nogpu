//
// Created by Ahmad Rahimi on 11/10/17.
//
#include "mvector.h"

using namespace std;

Vector::Vector(Point beginPoint, Point endPoint) {
    this->beginPoint = beginPoint;
    this->lengthPoint = endPoint;
    this->rgb[0] = rand() % 255 + 1;
    this->rgb[1] = rand() % 255 + 1;
    this->rgb[2] = rand() % 255 + 1;
}

void Vector::Draw() {
    SDL_SetRenderDrawColor(RenderManager::Instance()->GetRenderer(), rgb[0], rgb[1], rgb[2], SDL_ALPHA_OPAQUE);
    int point_scale = 6;
    this->drawtext();
    SDL_RenderSetScale(RenderManager::Instance()->GetRenderer(), 1, 1);
    SDL_RenderDrawLine(RenderManager::Instance()->GetRenderer(), beginPoint.x * Vector::SCALE,
                       beginPoint.y * Vector::SCALE, calcEndX() * Vector::SCALE, calcEndY() * Vector::SCALE);
    SDL_RenderSetScale(RenderManager::Instance()->GetRenderer(), point_scale, point_scale);
    SDL_RenderDrawPoint(RenderManager::Instance()->GetRenderer(), (calcEndX() * Vector::SCALE/point_scale),(calcEndY() * Vector::SCALE/point_scale));
}

Vector Vector::calculate(Vector *other_vector, bool plus) {
    Vector res;
    if(plus){
        other_vector->setBeginPoint(this->beginPoint);
        res = Vector(Point(this->beginPoint.x, this->beginPoint.y),Point(this->lengthPoint.x + other_vector->lengthPoint.x, this->lengthPoint.y + other_vector->lengthPoint.y));
    }else{
        other_vector->setBeginPoint(Point(this->calcEndX(), this->calcEndY()));
        res = Vector(Point(this->beginPoint.x, this->beginPoint.y),Point(this->lengthPoint.x - other_vector->lengthPoint.x, this->lengthPoint.y - other_vector->lengthPoint.y));
    }
    return res;
}

const Point &Vector::getBeginPoint() const {
    return beginPoint;
}

void Vector::setBeginPoint(const Point &beginPoint) {
    Vector::beginPoint = beginPoint;
}

const Point &Vector::getEndPoint() const {
    return lengthPoint;
}

void Vector::setEndPoint(const Point &endPoint) {
    Vector::lengthPoint = endPoint;
}


void Vector::drawtext() {
//    SDL_Renderer *renderer = RenderManager::GetRenderManager()->GetRenderer();
//
//    TTF_Font* font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 12);
//
//    SDL_Color foregroundColor = { 255, 255, 255 };
//    SDL_Color backgroundColor = { 0, 0, 0 };
//    std::string string = "(" + std::to_string(this->x) + "," + std::to_string(this->x) + ")";
//    const char *cstr = string.c_str();
//    SDL_Surface* textSurface = TTF_RenderText_Shaded(font, cstr, foregroundColor, backgroundColor);
//    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, textSurface); //now you can convert it into a texture
//
//    SDL_Rect textLocation = { 50, 50, 24, 4};
//
//    SDL_RenderCopy(renderer, Message, NULL, &textLocation);
//
//    SDL_FreeSurface(textSurface);
//
//    TTF_CloseFont(font);
}

float Vector::calcEndX() {
    return this->beginPoint.x + this->lengthPoint.x;
}

float Vector::calcEndY() {
    return this->beginPoint.y + this->lengthPoint.y;
}

Point Vector::getCalculatedEndPoint() {
    return Point(this->calcEndX(), this->calcEndY());
}
