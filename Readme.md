# Proyecto Simpson

Este es un proyecto de un juego basado en la familia Simpson. El objetivo es crear una serie de niveles y personajes para una experiencia interactiva utilizando Qt y C++.

## Estructura del Proyecto

La estructura del proyecto es la siguiente:


### Descripción de Archivos y Carpetas

- **`src/`**: Contiene todo el código fuente del proyecto, organizado en dos carpetas principales:
  - **`headers/`**: Contiene los archivos de cabecera (`.h`) que definen las interfaces de las clases y funciones.
    - `MainWindow.h`: Define la ventana principal del juego.
    - `Character.h`: Define la clase base para los personajes del juego (Bart, Lisa, Homero).
    - `Bart.h`, `Lisa.h`, `Homer.h`: Archivos específicos para cada personaje.
    - `Level.h`: Define la estructura base de los niveles del juego.
    - `Level1.h`, `Level2.h`: Archivos que definen los niveles específicos del juego.
    - `Trap.h`: Define las trampas dentro de los niveles.
    - `Item.h`: Define los objetos del juego (piezas del televisor).
    - `utils.h`: Contiene funciones utilitarias, como el manejo de colisiones.
  - **`sources/`**: Contiene los archivos de implementación (`.cpp`), que contienen la lógica del juego.
    - `main.cpp`: El punto de entrada principal del juego.
    - `MainWindow.cpp`: Implementación de la ventana principal del juego.
    - `Character.cpp`: Implementación de la clase base para los personajes.
    - `Bart.cpp`, `Lisa.cpp`, `Homer.cpp`: Implementación de las clases específicas de los personajes.
    - `Level.cpp`: Implementación de la clase base para los niveles.
    - `Level1.cpp`, `Level2.cpp`: Implementación de los niveles específicos.
    - `Trap.cpp`: Implementación de las trampas.
    - `Item.cpp`: Implementación de los objetos del juego.
    - `utils.cpp`: Implementación de las funciones utilitarias.

- **`assets/`**: Carpeta que contiene los recursos multimedia utilizados en el juego.
  - **`images/`**: Imágenes y sprites del juego.
  - **`sounds/`**: Archivos de sonido y música del juego.

- **`resources.qrc`**: Archivo de recursos de Qt que agrupa todos los recursos (como imágenes y sonidos) para facilitar su uso dentro del proyecto.

- **`CMakeLists.txt`**: Archivo de configuración para CMake, que se utiliza para definir cómo se construye el proyecto, qué bibliotecas se deben incluir y qué configuraciones son necesarias para compilar el juego.

## Requisitos

Para compilar y ejecutar este proyecto, necesitas tener Qt y CMake instalados en tu sistema. Si usas Qt Creator, se recomienda abrir el proyecto directamente desde el IDE para facilitar la gestión de dependencias.

## Cómo compilar

1. Clona este repositorio en tu máquina.
2. Navega a la carpeta del proyecto y crea un directorio de compilación:
   ```bash
   mkdir build
   cd build

