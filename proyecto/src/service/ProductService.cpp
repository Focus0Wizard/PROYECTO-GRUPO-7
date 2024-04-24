#include "service/ProductService.hpp"

namespace service
{
    ProductService::ProductService(ProductRepositoryPtr productRepository)
        : m_productRepository(productRepository) {}

    bool ProductService::save(const Product& product)
    {
        bool result = false;
        try 
        {
            result = m_productRepository->save(product);
        }
        catch (const std::exception& e)
        {
            spdlog::error("ProductService::save::error: {}", e.what());
        }
        return result;
    }

    bool ProductService::edit(const Product& product)
    {
        bool result = false;
        try
        {
            result = m_productRepository->edit(product);
        }
        catch (const std::exception& e)
        {
            spdlog::error("ProductService::edit::error: {}", e.what());
        }
        return result;
    }

    bool ProductService::remove(const Product& product)
    {
        bool result = false;
        try
        {
            result = m_productRepository->remove(product);
        }
        catch (const std::exception& e)
        {
            spdlog::error("ProductService::remove::error: {}", e.what());
        }
        return result;
    }

    ProductMap ProductService::findAll()
    {
        ProductMap result;
        try
        {
            result = m_productRepository->find();
        }
        catch (const std::exception& e)
        {
            spdlog::error("ProductService::findAll::error: {}", e.what());
        }
        return result;
    }
}
