#include "view/ProductView.hpp"

namespace view
{
	void ProductView::show(const ProductMap& products)
	{
		for (const auto& product : products)
		{
			std::cout << "Id: " << product.second.getId() << "\n";
            std::cout << "Nombre: " << product.second.getName() << "\n";
            std::cout << "Detalles: " << product.second.getDetails() << "\n";
            std::cout << "Precio: " << product.second.getPrice() << "\n";
		}
	}

    Product ProductView::read()
    {
        std::uint32_t id;
        double price;
        std::string name;
        std::string details;
        std::cout << "Ingrese el id: ";
        std::cin >> id;
        std::cout << "Ingrese el nombre: ";
        std::cin >> name;
        std::cout << "Ingrese los detalles: ";
        std::cin >> details;
        std::cout << "Ingrese el precio: ";
        std::cin >> price;
        return {id, name, details, price};
    }
}