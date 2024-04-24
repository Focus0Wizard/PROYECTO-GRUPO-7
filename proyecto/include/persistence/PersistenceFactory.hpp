#ifndef PERSISTENCE_FACTORY_HPP
#define PERSISTENCE_FACTORY_HPP

#include <memory>
#include <nlohmann/json.hpp>
#include "LocalPersistence.hpp"
#include "PersistenceManager.hpp"

namespace persistence
{
    template<class T>
    class PersistenceFactory
    {
    public:
        static PersistenceManagerPtr<T> createPersistence(nlohmann::json configuration) {
            PersistenceManagerPtr<T> result;
            const auto& config{configuration.at("persistence")};
            const auto& persistenceType{config.at("type").get_ref<const std::string &>()};
            const auto& persistenceConf{config.at("configuration")};
            if (persistenceType == "local")
            {
                result = std::make_shared<LocalPersistence<T>>();
                result->configure(persistenceConf);
                return result;
            }
            return result;
        };
    };
}

#endif // !PERSISTENCE_FACTORY_HPP
