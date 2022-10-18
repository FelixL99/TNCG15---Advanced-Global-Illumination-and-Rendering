#include "Scene.h"

// Default Constructor, define room
Scene::Scene()
{
    createRoom();
    createTetrahedron();
}

// Default Destructor
Scene::~Scene()
{
}

// Function createRoom, Create room triangles
void Scene::createRoom() {

    // Define all room vertices
    Vertex vertices[12]{
      Vertex(glm::vec3(-3.0f, 0.0f, 5.0f)),  //v0 Roof
      Vertex(glm::vec3(0.0f, 6.0f, 5.0f)),   //v1 Roof
      Vertex(glm::vec3(10.0f, 6.0f, 5.0f)),  //v2 Roof
      Vertex(glm::vec3(13.0f, 0.0f, 5.0f)),  //v3 Roof
      Vertex(glm::vec3(10.0f, -6.0f, 5.0f)), //v4 Roof
      Vertex(glm::vec3(0.0f, -6.0f, 5.0f)),  //v5 Roof

      Vertex(glm::vec3(-3.0f, 0.0f, -5.0f)),  //v6 Floor
      Vertex(glm::vec3(0.0f, 6.0f, -5.0f)),   //v7 Floor
      Vertex(glm::vec3(10.0f, 6.0f, -5.0f)),  //v8 Floor
      Vertex(glm::vec3(13.0f, 0.0f, -5.0f)),  //v9 FLoor
      Vertex(glm::vec3(10.0f, -6.0f, -5.0f)), //v10 Floor
      Vertex(glm::vec3(0.0f, -6.0f, -5.0f)),  //v11 Floor
    };

    // Create and add all triangles for the room (floor, walls & roof)
    // Assign white color to floor and roof, give each of the six different colors

    // Roof
    triangles.push_back(Triangle(vertices[0], vertices[1], vertices[5], white));
    triangles.push_back(Triangle(vertices[1], vertices[2], vertices[5], white));
    triangles.push_back(Triangle(vertices[2], vertices[4], vertices[5], white));
    triangles.push_back(Triangle(vertices[2], vertices[3], vertices[4], white));

    // Walls
    triangles.push_back(Triangle(vertices[0], vertices[11], vertices[6], green));
    triangles.push_back(Triangle(vertices[0], vertices[5], vertices[11], green));

    triangles.push_back(Triangle(vertices[5], vertices[10], vertices[11], blue));
    triangles.push_back(Triangle(vertices[5], vertices[4], vertices[10], blue));

    triangles.push_back(Triangle(vertices[4], vertices[9], vertices[10], orange));
    triangles.push_back(Triangle(vertices[3], vertices[9], vertices[4], orange));

    triangles.push_back(Triangle(vertices[3], vertices[8], vertices[9], gray));
    triangles.push_back(Triangle(vertices[2], vertices[8], vertices[3], gray));

    triangles.push_back(Triangle(vertices[2], vertices[7], vertices[8], cyan));
    triangles.push_back(Triangle(vertices[1], vertices[7], vertices[2], cyan));

    triangles.push_back(Triangle(vertices[0], vertices[6], vertices[1], red));
    triangles.push_back(Triangle(vertices[1], vertices[6], vertices[7], red));

    // Floor
    triangles.push_back(Triangle(vertices[6], vertices[11], vertices[7], white));
    triangles.push_back(Triangle(vertices[7], vertices[11], vertices[8], white));
    triangles.push_back(Triangle(vertices[8], vertices[11], vertices[10], white));
    triangles.push_back(Triangle(vertices[8], vertices[10], vertices[9], white));

    std::cout << "Room triangles added!" << std::endl;
    std::cout << "Triangle amount: " << triangles.size() << std::endl;
}

// Function createTetrahedron, create tetrahedron object
void Scene::createTetrahedron() 
{
    //Tetra
    //        3
    //       /|\
    //      / | \
    //     /  |  \
    //    /   |   \
    //  0/____|1___\2

    Vertex vertices[4]{
      Vertex(glm::vec3(8.0f, -1.0f, 0.0f)), //v0
      Vertex(glm::vec3(8.0f, 0.0f, 0.0f)),  //v1 
      Vertex(glm::vec3(7.0f, 1.0f, 0.0f)),  //v2 
      Vertex(glm::vec3(9.0f, 0.0f, 1.0f)),  //v3
    };

    Tetrahedron tetrahedron(vertices[0], vertices[1], vertices[2], vertices[3], red);

    tetrahedrons.push_back(tetrahedron);
    //triangles.push_back(tetrahedron.getTetrahedronTriangle(0));
    //triangles.push_back(tetrahedron.getTetrahedronTriangle(1));
    //triangles.push_back(tetrahedron.getTetrahedronTriangle(2));
    //triangles.push_back(tetrahedron.getTetrahedronTriangle(3));

    std::cout << "Tetrahedras triangles added!" << std::endl;
}

// Function triangleIntersected, returns the first intersected triangle and intersection point 
Triangle Scene::triangleIntersected(Ray& r, glm::vec3& intersectionPoint)
{
    Triangle temp;

    // Go through vector triangles and check for intersection
    for (vector<Triangle>::iterator it = triangles.begin(); it != triangles.end(); it++)
    {
        // If true then there is an intersection with triangle *it and ray, save *it in temp variable and return
        if ((*it).rayIntersection(r, intersectionPoint)) {
            temp = *it;
            break;
        }
    }

    return temp;
}

Tetrahedron Scene::tetrahedronIntersected(Ray& r, glm::vec3& intersectionPoint)
{
    Tetrahedron temp;

    // Go through vector triangles and check for intersection
    for (vector<Tetrahedron>::iterator it = tetrahedrons.begin(); it != tetrahedrons.end(); it++)
    {
        // If true then there is an intersection with triangle *it and ray, save *it in temp variable and return
        if ((*it).rayIntersection(r, intersectionPoint)) {
            temp = *it;
            break;
        }
    }

    return temp;
}


