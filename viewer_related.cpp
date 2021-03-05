#include "viewer_related.h"
#include "common.h"

extern Eigen::MatrixXd V;
extern Eigen::MatrixXi F;

void customize_menu(igl::opengl::glfw::imgui::ImGuiMenu& menu, igl::opengl::glfw::Viewer& viewer)
{
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
}
