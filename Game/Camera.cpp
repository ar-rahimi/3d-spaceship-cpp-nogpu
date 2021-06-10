//
// Created by Ahmad Rahimi on 2/22/18.
//

#include <math.h>
#include "Camera.h"
#include "Matrix3d.h"

Camera::Camera(float x, float y, float z) : position{x, y, z}{

}

void Camera::updatePosition(Controls dir) {
    if(!follow) {
        switch (dir) {
            case Controls::CamLeft:
                position.x -= 10;
                break;
            case Controls::CamRight:
                position.x += 10;
                break;
            case Controls::CamUp:
                position.y -= 10;
                break;
            case Controls::CamDown:
                position.y += 10;
                break;
            case Controls::CamScaleDown:
                position.z -= 10;
                break;
            case Controls::CamScaleUp:
                position.z += 10;
                break;
            case Controls::RotateCamRight:
                rotateCameraHor(Point(eye.x, eye.z), -3);
                break;
            case Controls::RotateCamLeft:
                rotateCameraHor(Point(eye.x, eye.z), 3);
                break;
            case Controls::RotateCamUp:
                rotateCameraVert(Point(eye.y, eye.z), -3);
                break;
            case Controls::RotateCamDown:
                rotateCameraVert(Point(eye.y, eye.z), 3);
                break;
        }
    }
}

Matrix Camera::getCameraMatrix() {
    Point3d z = (eye - lookAt).getNormalized();
    Point3d y = up.getNormalized();
    Point3d x = Point3d::GetOutProduct(y, z).getNormalized();
    y = Point3d::GetOutProduct(z, x).getNormalized();

    return Matrix({
                                    {x.x, x.y, x.z, -Point3d::GetInProduct(x, eye)},
                                    {y.x, y.y, y.z, -Point3d::GetInProduct(y, eye)},
                                    {z.x, z.y, z.z, -Point3d::GetInProduct(z, eye)},
                                    {0, 0, 0, 1}
                            });
}

Matrix Camera::getProjectionMatrix() {
    float a = fov * (M_PI_2 / 180);
    float scale = near * tanf(a*0.5f);

    return Matrix({
                                        {scale, 0.0f, 0.0f, 0.0f},
                                        {0.0f, scale, 0.0f, 0.0f},
                                        {0.0f, 0.0f, ( -far )/(far - near), -1.f},
                                        {0.0f, 0.0f, ((-far) * near) / (far - near), 0.0f},
                                });
}

Matrix Camera::correctViewMatrix(Matrix viewMatrix) {
    if(viewMatrix.data.size() < 4){
        std::vector<float> extraRow;
        for(int i = 0; i < viewMatrix.data[0].size(); i++){
            extraRow.emplace_back(1);
        }
        viewMatrix.data.emplace_back(extraRow);
    }
    return viewMatrix;
}

void Camera::handleEvents(Controls dir) {
    if(dir == Controls::SwitchCamera)
        follow = !follow;
}

void Camera::rotateCameraHor(Point pos, float rad) {
    rad = rad * (M_PI_2 / 180);
    float s = sinf(rad);
    float c = cosf(rad);
    eye.x = pos.x*c-pos.y*s;
    eye.z = pos.y*c+pos.x*s;
}

void Camera::rotateCameraVert(Point pos, float rad) {
    rad = rad * (M_PI_2 / 180);
    float s = sinf(rad);
    float c = cosf(rad);
    eye.y = pos.x*c-pos.y*s;
    eye.z = pos.y*c+pos.x*s;
}
