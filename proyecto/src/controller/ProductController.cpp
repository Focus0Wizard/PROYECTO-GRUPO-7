#include "controller/ProductController.hpp"

namespace controller
{
	ProductController::ProductController(nlohmann::json configuration)
        : m_productService(std::make_shared<ProductRepository>(PersistenceFactory<Product>::createPersistence(std::move(configuration)))) {}

	void ProductController::showProducts()
	{
		view::ProductView::getInstance().show(m_productService.findAll());
	}

	void ProductController::saveProduct()
	{
        m_productService.save(view::ProductView::getInstance().read());
	}

    void ProductController::editProduct()
    {
        m_productService.edit(view::ProductView::getInstance().read());
    }
}