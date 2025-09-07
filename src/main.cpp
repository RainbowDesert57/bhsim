#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <cmath>
#include <iostream>

// Struct for 3D points (like your Vec3)
struct Vec3 {
    float x, y, z;
};

// Function to generate points on a sphere
std::vector<Vec3> generateSphere(float radius, int steps) {
    std::vector<Vec3> points;

    for(int i = 0; i <= steps; i++) {
        float theta = i * M_PI / steps;           // polar angle
        for(int j = 0; j <= steps; j++) {
            float phi = j * 2 * M_PI / steps;     // azimuth angle

            float x = radius * sin(theta) * cos(phi);
            float y = radius * cos(theta);
            float z = radius * sin(theta) * sin(phi);

            points.push_back({x, y, z});
        }
    }

    return points;
}

int main() {
    // Initialize GLFW
    if(!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "Sphere Example", nullptr, nullptr);
    if(!window){ glfwTerminate(); return -1; }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if(glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW\n";
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    // Generate sphere points
    float radius = 0.5f;
    int steps = 30; // increase for smoother sphere
    std::vector<Vec3> sphere = generateSphere(radius, steps);

    // Render loop
    while(!glfwWindowShouldClose(window)) {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPointSize(2.0f);         // size of each point
        glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f); // white points
        for(auto &p : sphere) {
            glVertex3f(p.x, p.y, p.z);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

