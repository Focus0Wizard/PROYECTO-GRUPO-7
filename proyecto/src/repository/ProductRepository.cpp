#include "repository/ProductRepository.hpp"

namespace repository
{
	ProductRepository::ProductRepository(PersistenceManagerPtr<Product> persistenceManager)
		: m_persistenceManager(persistenceManager) {}

	bool ProductRepository::save(const Product& product)
	{
		return m_persistenceManager->save(product.getId(), product);
	}

	bool ProductRepository::edit(const Product& product)
	{
		return m_persistenceManager->edit(product.getId(), product);
	}

	bool ProductRepository::remove(const Product& product)
	{
		return m_persistenceManager->remove(product.getId());
	}

	ProductMap ProductRepository::find()
	{
		return m_persistenceManager->find();
	}

	std::optional<Product> ProductRepository::find(const std::function<bool(const Product&)>& predicate)
	{
		return m_persistenceManager->find(predicate);
	}
}