#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

int main() {

    // glfw initialisieren (Fenster- und Kontextverwaltung für OpenGL)
    glfwInit();

    // OpenGL-Version 3.3 anfordern – muss zur Shader-Version (#version 330 core) passen
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Core-Profile verwenden (moderne OpenGL-Funktionen, keine Kompatibilitätsfunktionen)
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    //create a windowed mode window and its openGL context
    GLFWwindow* window = glfwCreateWindow(800, 800, "C OpenGL", NULL, NULL);

    // Wenn das Fenster nicht erstellt werden kann → Fehler ausgeben und beenden
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // make the windows context current
    glfwMakeContextCurrent(window);

    // openGL-Funktionen verfügbar machen
    gladLoadGL(glfwGetProcAddress);

    // Legt fest, in welchem Bereich des Fensters OpenGL zeichnet (Viewport)
    glViewport(0, 0, 800, 800);

    // Hintergrundfarbe setzen (RGBA)
    glClearColor(0.07f,0.13f,0.17f, 1.0f);

    // Frame-Buffer löschen (Bildschirm mit Hintergrundfarbe füllen)
    glClear(GL_COLOR_BUFFER_BIT);

    // Vorder- und Rückpuffer tauschen (aktuelles Bild anzeigen)
    glfwSwapBuffers(window);

    // Haupt-Loop: läuft, bis das Fenster geschlossen wird
    while(!glfwWindowShouldClose(window))
    {
        // Poll for and process events
        glfwPollEvents();
    }

    // fenster wieder zerstören
    glfwDestroyWindow(window);
    // Lib-Init terminieren
    glfwTerminate();
    return 0;
}