#ifndef PRODUCT_SERVICE_HPP
#define PRODUCT_SERVICE_HPP

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include "repository/ProductRepository.hpp"

using namespace model;
using namespace repository;

namespace service
{
	class ProductService
	{
	public:
		explicit ProductService(ProductRepositoryPtr productRepository);
		~ProductService() = default;
		bool save(const Product& product);
		bool edit(const Product& product);
		bool remove(const Product& product);
		ProductMap findAll();
	private:
		ProductRepositoryPtr m_productRepository;
	};
}

#endif // !PRODUCT_SERVICE_HPP
