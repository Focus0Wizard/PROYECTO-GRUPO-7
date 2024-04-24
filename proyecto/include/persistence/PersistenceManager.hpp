#ifndef PERSISTENCE_MANAGER_HPP
#define PERSISTENCE_MANAGER_HPP

#include <algorithm>
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include <optional>
#include <utility>

namespace persistence
{
	template<typename T>
	class PersistenceManager
	{
	public:
		void configure(nlohmann::json configuration);
		virtual bool save(std::uint32_t index, const T& data) = 0;
		virtual bool edit(std::uint32_t index, const T& data) = 0;
		virtual bool remove(std::uint32_t index) = 0;
		virtual std::map<std::uint32_t, T> find() = 0;
		virtual std::optional<T> find(const std::function<bool(const T&)>& predicate) = 0;
	protected:
		nlohmann::json m_configuration;
	};

	template<typename T>
	using PersistenceManagerPtr = std::shared_ptr<PersistenceManager<T>>;

	template<typename T>
	inline void PersistenceManager<T>::configure(nlohmann::json configuration)
	{
		m_configuration = std::move(configuration);
	}
}

#endif // !PERSISTENCE_MANAGER_HPP
