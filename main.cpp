// igl includes
#include <igl/opengl/glfw/Viewer.h>
#include <igl/read_triangle_mesh.h>
#include <igl/file_dialog_open.h>

//imgui includes
#include <igl/opengl/glfw/imgui/ImGuiMenu.h>
#include <imgui.h>

Eigen::MatrixXd V;
Eigen::MatrixXi F;

void customize_menu(igl::opengl::glfw::Viewer& viewer);

int main(int argc, char *argv[])
{
    // Plot the mesh
    igl::opengl::glfw::Viewer viewer;
    customize_menu(viewer);
}

void customize_menu(igl::opengl::glfw::Viewer& viewer)
{
	igl::opengl::glfw::imgui::ImGuiMenu menu;
	viewer.plugins.push_back(&menu);
    menu.callback_draw_viewer_menu = [&]()
    {
        if (ImGui::Button("Load Mesh"))
        {
            std::string filename = igl::file_dialog_open();
            if (!filename.empty() && igl::read_triangle_mesh(filename, V, F))
            {
                viewer.data().set_mesh(V, F);
                viewer.core().align_camera_center(V, F);
            }
        }
    };
    viewer.launch();
}
