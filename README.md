# Markdown file

# README

## Dependencies
- GLFW
- GLAD

---

## ⚙️ GLFW & GLAD – Was machen die eigentlich?

### 🧱 GLFW – „Fenster & Eingabe“
GLFW ist eine Library, die dafür sorgt, dass dein Programm ein Fenster öffnen, Eingaben verarbeiten und einen OpenGL-Kontext erstellen kann.

**GLFW kümmert sich um:**
- Fenster erstellen und verwalten
- Tastatur-, Maus- und Joystick-Eingaben
- OpenGL-Kontext erstellen
- Bildschirmgröße und Auflösung abrufen
- `glfwGetProcAddress` – nötig für GLAD

### ⚡ GLAD – „OpenGL-Funktionen laden“
GLAD ist ein sogenannter OpenGL-Loader. Er lädt alle OpenGL-Funktionen zur Laufzeit – also `glDrawArrays`, `glUseProgram`, `glGenBuffers` usw.

Ohne GLAD wüsste dein Programm nicht, wo diese Funktionen im Speicher liegen. Deshalb musst du am Anfang einmal schreiben:

```cpp
gladLoadGL(glfwGetProcAddress);
```

Damit ist OpenGL einsatzbereit.

### 🧠 Zusammenspiel

| Aufgabe                          | Zuständig |
|----------------------------------|-----------|
| Fenster erstellen                | GLFW      |
| Kontext aktivieren               | GLFW      |
| Funktionen dynamisch auflösen    | GLAD      |
| Eingaben verarbeiten             | GLFW      |
| Zeichnen mit OpenGL              | Du 😎      |

---
