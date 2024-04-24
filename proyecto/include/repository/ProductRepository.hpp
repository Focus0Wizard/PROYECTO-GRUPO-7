#ifndef PRODUCT_REPOSITORY_HPP
#define PRODUCT_REPOSITORY_HPP

#include <nlohmann/json.hpp>
#include "persistence/PersistenceManager.hpp"
#include "model/Product.hpp"

using namespace model;
using namespace persistence;

namespace repository
{
	class ProductRepository
	{
	public:
		explicit ProductRepository(PersistenceManagerPtr<Product> persistenceManger);
		~ProductRepository() = default;
		bool save(const Product& product);
		bool edit(const Product& product);
		bool remove(const Product& product);
		ProductMap find();
		std::optional<Product> find(const std::function<bool(const Product&) >& predicate);
	private:
		PersistenceManagerPtr<Product> m_persistenceManager;
	};

	typedef std::shared_ptr<ProductRepository> ProductRepositoryPtr;
}

#endif // !PRODUCT_REPOSITORY_HPP
