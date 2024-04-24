#include "model/Product.hpp"

namespace model
{
	Product::Product() :
		m_id(0), m_price(0), m_quantity(0) {}

	Product::Product(std::uint32_t id, std::string name, std::string details, double price) :
		m_id(id), m_name(std::move(name)), m_details(std::move(details)), m_price(price), m_quantity(0) {}

	std::uint32_t Product::getId() const
	{
		return m_id;
	}

	std::string Product::getName() const
	{
		return m_name;
	}

	std::string Product::getDetails() const
	{
		return m_details;
	}

	std::uint32_t Product::getQuantity() const
	{
		return m_quantity;
	}

    double Product::getPrice() const {
        return m_price;
    }
}