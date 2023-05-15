#include <iostream>
#include <filesystem>

#include <Eigen/Dense>
#include "denoiser/denoiser.hpp"
#include "cxxopts/cxxopts.hpp"
#include "igl/readOBJ.h"
#include "igl/writeOBJ.h"
#include "igl/per_face_normals.h"


int main(int argc, char *argv[]) {
    cxxopts::Options options("TV mesh denoiser", "Mesh denoising via TV regularization on normals");
    options.add_options()
            ("obj", "obj file containing the input mesh", cxxopts::value<std::string>())
             ("a,alpha", "denoising strength", cxxopts::value<double>()->default_value("100.0"))
            ;
    options.parse_positional({"obj"});
    auto args = options.parse(argc, argv);

    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    igl::readOBJ(args["obj"].as<std::string>(), V, F);
    std::cout << V.rows() << " vertices and " << F.rows() << " triangles." << std::endl;


    Eigen::MatrixXd iniN, N;
    igl::per_face_normals(V, F, iniN);
    auto denoiser = tvd::Denoiser<double>(V, F);
    denoiser.alpha = args["alpha"].as<double>();
    denoiser.denoise(iniN, N, /*n_iter=*/70);
    tvd::Denoiser<double>::recover_positions(F, N, V);

    std::filesystem::create_directory("./result");
    igl::writeOBJ("./result/denoised.obj", V, F);
}