#include "Scene.h"
#include "Camera.h"
#include "Pixel.h"
#include "Tetrahedron.h"

/*
Main.cpp
This file contains the main function for the project
*/

int main()
{

	// Initialize scene & camera
	Scene scene;
	Camera camera;

	// Set camera position
	camera.setEye(1);

	// Render scene & create image
	camera.render(scene);
	camera.createImage();
}

/*
Code Structure

	- Vertex (Done)
	- Direction (Done)
	- ColorDbl (Done)
	- Ray (Done?) what is importance and alpha variable in .h commented out
	- Triangle (Done?) rayIntersection hopefully works?
	- Scene (Done?) according to basic code structure everything is implemented
		- Needs, light, sphere, tetrahedra
	- Pixel (Done)
	- Camera, Needs some work with pixel color calculations
	- Tetrahedron Not working correctly with Camera.cpp when rendering
	- Spehere
	- Light/Reflection
*/