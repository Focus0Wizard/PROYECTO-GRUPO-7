#ifndef PRODUCT_CONTROLLER_HPP
#define PRODUCT_CONTROLLER_HPP

#include <utility>
#include "persistence/PersistenceFactory.hpp"
#include "repository/ProductRepository.hpp"
#include "service/ProductService.hpp"
#include "view/ProductView.hpp"

namespace controller
{
	using model::Product;
    using persistence::PersistenceFactory;
    using repository::ProductRepository;
    using service::ProductService;

	class ProductController
	{
	public:
		explicit ProductController(nlohmann::json configuration);
		~ProductController() = default;
		void showProducts();
		void saveProduct();
        void editProduct();
	private:
		ProductService m_productService;
	};
}

#endif // !PRODUCT_CONTROLLER_HPP
