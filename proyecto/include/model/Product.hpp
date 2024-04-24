#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <memory>
#include <map>

namespace model
{
	class Product
	{
	public:
		Product();
		Product(std::uint32_t id, std::string name, std::string details, double price);
		std::uint32_t getId() const;
		std::string getName() const;
		std::string getDetails() const;
		std::uint32_t getQuantity() const;
        double getPrice() const;
    private:
		std::uint32_t m_id;
		std::string m_name;
		std::string m_details;
		std::uint32_t m_quantity;
		double m_price;
	};

	typedef std::map<std::uint32_t, Product> ProductMap;
	typedef ProductMap::iterator ProductIt;
}

#endif // !PRODUCT_HPP
