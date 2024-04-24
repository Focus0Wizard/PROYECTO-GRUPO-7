#ifndef PRODUCT_VIEW_HPP
#define PRODUCT_VIEW_HPP

#include <iostream>
#include "util/Singleton.hpp"
#include "model/Product.hpp"

using namespace model;

namespace view
{
	class ProductView :
            public util::Singleton<ProductView>
	{
	public:
		void show(const ProductMap &products);
        Product read();
	};

}
#endif // !PRODUCT_VIEW_HPP
