#ifndef BINARY_FILE_PERSISTENCE_HPP
#define BINARY_FILE_PERSISTENCE_HPP

#include "PersistenceManager.hpp"

namespace persistence
{
	template<typename T>
	class LocalPersistence :
            public PersistenceManager<T>
	{
	public:
		bool save(std::uint32_t index, const T& data);
		bool edit(std::uint32_t index, const T& data);
		bool remove(std::uint32_t index);
		std::map<std::uint32_t, T> find();
		std::optional<T> find(const std::function<bool(const T&)>& predicate);
    private:
        std::map<std::uint32_t, T> elements;
	};

	template<typename T>
	inline bool persistence::LocalPersistence<T>::save(std::uint32_t index, const T& data)
	{
        elements.insert(std::make_pair(index, data));
        return true;
	}

	template<typename T>
	inline bool persistence::LocalPersistence<T>::edit(std::uint32_t index, const T& data)
	{
        elements[index] = data;
		return true;
	}

	template<typename T>
	inline bool LocalPersistence<T>::remove(std::uint32_t index)
	{
        elements.erase(index);
		return false;
	}

	template<typename T>
	inline std::map<std::uint32_t, T> LocalPersistence<T>::find()
	{
		return elements;
	}

	template<typename T>
	inline std::optional<T> LocalPersistence<T>::find(const std::function<bool(const T&)>& predicate)
	{
		return std::optional<T>();
	}
}

#endif // !BINARY_FILE_PERSISTENCE_HPP
