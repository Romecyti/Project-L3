


cmake_minimum_required(VERSION 3.10.0)
project(projet_TETRIS CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

find_package(Qt5Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()
find_package(Qt5 COMPONENTS LinguistTools REQUIRED)
find_package(Qt5 COMPONENTS Multimedia REQUIRED)
find_package(Qt5 COMPONENTS MultimediaWidgets REQUIRED)


# OpenGL
find_package(Qt COMPONENTS QtOpenGL REQUIRED)
find_package(OpenGL REQUIRED)
SET(LIBRARIES ${OPENGL_LIBRARIES})


# SDL

#find_package(SDL2 REQUIRED)
#include_directories(${SDL_INCLUDE_DIR})

# QJoyStick Class (by Alex Spataru)

# executable
add_executable(${PROJECT_NAME} main.cpp
    ./model/model.cc
    ./model/jeu/tetrisclassique.cc
    ./model/jeu/tetrismultijoueur.cc
    ./model/base/cube.cc
    ./model/base/matrice3d.cc
    ./model/base/m3exceptions.cpp
    ./model/base/plateau.cc
    ./model/base/piece.cc
    ./model/base/m3exists.cpp
    
    ./model/base/pieces/p_cube.cc
    ./model/base/pieces/p_l.cc
    ./model/base/pieces/p_cube.cc
    ./model/base/pieces/p_i.cc
    ./model/base/pieces/p_laugmente.cc
    ./model/base/pieces/p_z.cc
    ./model/base/pieces/p_z3d.cc
    ./model/base/pieces/p_t.cc
    ./model/base/pieces/p_t3d.cc
    ./model/base/pieces/p_carre.cc
    ./model/base/pieces/p_classique_1.cc
    ./model/base/pieces/p_classique_2.cc
    ./model/base/pieces/p_classique_3.cc
    ./model/base/pieces/p_classique_4.cc
    ./model/base/pieces/p_classique_5.cc
    ./model/base/pieces/p_classique_6.cc
    ./model/base/pieces/p_classique_7.cc
    ./model/base/pieces/p_classique_8.cc
    
    ./controlleur/controlleur_tetris_classique.cc
    ./controlleur/controlleurtetrismulti.cc

    ./controlleur/controlleur.cc
    ./controlleur/supercontrolleur.cc
    ./controlleur/controlleur_menu.cc
    #./vue/base/tetris_opengl.cc
           
    ./model/settings/settings.cc
    ./model/settings/settings_controller.cc
    ./model/settings/settings_exceptions.cpp
    ./vue/vue_mainmenu.cc
    ./vue/vue_mainmenu.ui
    ./vue/opengl_tetrisc.cc
    ./vue/vue_tetris_c.cpp
    ./vue/vuetetrismulti.cc
    ./vue/tetris_classique_resultats.cc
    ./vue/resultattetrismulti.cc
    ./ressources.qrc
    )



target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Multimedia ${LIBRARIES} ${SDL_INCLUDE_DIR})
