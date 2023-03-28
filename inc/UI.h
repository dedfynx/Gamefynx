#pragma once 

#include <string>
#include <map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Def.h"


class UI{
    public:
        UI(GLFWwindow* window, const char* glVersion);
        void Update();
        void Render(GLFWwindow* window);
        void Clean();

        void Dockspace();
        void Viewport(GLuint texture);
        void MemWatch();

        bool getAction(std::string act){
            if(actions.find(act) != actions.end() ){
                return actions[act];
            }
            else{
                return false;
            }
        }
        void resetAction(std::string act){
            if(actions.find(act) != actions.end() ){
                actions[act] = false;
            }         
        }

    private:
        bool show_demo_window = false; 
        std::map<std::string, bool> actions = {
            {"Load", false},
        };
};