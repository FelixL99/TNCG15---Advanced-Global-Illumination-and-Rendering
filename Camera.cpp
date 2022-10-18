#include "Camera.h"

// Default Destructor
Camera::~Camera()
{
}

// Function render, renders scene all color values saved in ColorDbl for each pixel
void Camera::render(Scene scene) { 
    
    // Set eye according to eyeSwitch
    Vertex eye;
    if (eyeSwitch == 0) eye = eye1;
    else if (eyeSwitch == 1) eye = eye2;

    // Loop through the pixels, set pixel color from ray
    for (int j = 0; j < SIZE; j++) 
    {
        for (int i = 0; i < SIZE; i++) {

            Ray pixelRay;
            ColorDbl pixelColor;
            Triangle triangleIntersected;
            Tetrahedron tetrahedronIntersected;
            glm::vec3 pixelCurrent;
            glm::vec3 intersectionPoint;

            pixelCurrent = eye.getVec3() + glm::vec3(0, i * (2.0f / SIZE) - (1 - (1 / SIZE)), j * (2.0f / SIZE) - (1 - (1 / SIZE))) - eye.getVec3();

            //crete a ray from the eye to current pixel
            pixelRay = Ray(eye, Vertex(pixelCurrent));
            // Launch the ray into the scene. The function will take the reference to the ray and set it's color.
            triangleIntersected = scene.triangleIntersected(pixelRay, intersectionPoint);
            tetrahedronIntersected = scene.tetrahedronIntersected(pixelRay, intersectionPoint);
            //after rayIntersection r's color (colorDbl) has changes to the triangle color that it hits
           
            //pixelRay.setColor(triangleIntersected.getColor());

            image[i][j].setColor(triangleIntersected.getColor() * (255.99f));
        }
    }
}

// Function createImage, takes the ColorDbl values for each pixel and creates an image
void Camera::createImage(const string filename) {
    
    FILE* fp = fopen("render.ppm", "wb"); /* b - binary mode */
    fprintf(fp, "P6\n%d %d\n255\n", SIZE, SIZE);
    for (int j = SIZE - 1; j > -1; --j)
    {
        for (int i = SIZE - 1; i > -1; --i)
        {
            static unsigned char color[3];
            color[0] = (unsigned char)image[i][j].getColor().getColorVec().x;  // Red channel
            color[1] = (unsigned char)image[i][j].getColor().getColorVec().y;  // Green channel
            color[2] = (unsigned char)image[i][j].getColor().getColorVec().z;  // Blue channel
            fwrite(color, 1, 3, fp);
        }
    }

    fclose(fp);
}

// Function setEye, switches between the two camera positions
void Camera::setEye(int _eye) {
    if (_eye == 0 || _eye == 1)
        eyeSwitch = _eye;
    else eyeSwitch = 0;
}