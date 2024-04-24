#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "controller/ProductController.hpp"

using namespace std;

int main()
{
	std::ifstream configurationFile("./config/configuration.json");
	const auto config = nlohmann::json::parse(configurationFile);
    controller::ProductController productController(config);
    productController.saveProduct();
    productController.showProducts();
    productController.editProduct();
    productController.showProducts();
	std::cin.get();
	return 0;
}
