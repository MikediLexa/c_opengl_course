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

    // Beschreiben der Dreiecks-Koordniaten A, B, C mit A(-0.5, -0.5), B(0.5, -0.5) und C(0.5, 0.5)
    float vertices [] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        //-0.5f, 0.5f, 0.0f,
    };



    // Vertex Shader Source Code in C-String gespeichert
    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";


    // Shader-Objekt erzeugen 
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);


    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();


    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    glUseProgram(shaderProgram);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Hier wird ein Vertex-Shader aufgebaut.
    // Managen des Speichers, aus dem der Vertex Shader herausarbeitet --> Vertex Buffer Objects (VBO)
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // Verbinden des neu generierten Buffers mit dem buffer object GL_ARRAY_Buffer (von OpenGl)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // glBufferData-Funktion kopiert den oben definierte Vertex Daten in den Buffer-Speicher
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Haupt-Loop: läuft, bis das Fenster geschlossen wird
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 0, 4);

        glfwSwapBuffers(window);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    // fenster wieder zerstören
    glfwDestroyWindow(window);
    // Lib-Init terminieren
    glfwTerminate();
    return 0;
}