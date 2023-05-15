#include <iostream>

#include <Eigen/Dense>
#include "denoiser/denoiser.hpp"
#include "cxxopts/cxxopts.hpp"
#include "igl/readOBJ.h"


int main(int argc, char *argv[]) {
    cxxopts::Options options("TV mesh denoiser", "Mesh denoising via TV regularization on normals");
    options.add_options()
            ("obj", "obj file containing the input mesh", cxxopts::value<std::string>())
            ;
    options.parse_positional({"obj"});
    auto args = options.parse(argc, argv);

    tvd::hello(args["obj"].as<std::string>());

    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    igl::readOBJ(args["obj"].as<std::string>(), V, F);
    std::cout << V.rows() << " vertices and " << F.rows() << " triangles" << std::endl;
}