#pragma once
// igl includes
#include <igl/opengl/glfw/Viewer.h>
#include <igl/read_triangle_mesh.h>
#include <igl/file_dialog_open.h>

//imgui includes
#include <igl/opengl/glfw/imgui/ImGuiMenu.h>
#include <imgui.h>

void customize_menu(igl::opengl::glfw::imgui::ImGuiMenu& menu, igl::opengl::glfw::Viewer& viewer);