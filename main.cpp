#include "viewer_related.h"
#include "common.h"

int main(int argc, char *argv[])
{
    // Plot the mesh
    igl::opengl::glfw::Viewer viewer;
    igl::opengl::glfw::imgui::ImGuiMenu menu;
    viewer.plugins.push_back(&menu);
    customize_menu(menu, viewer);
    viewer.launch();
}