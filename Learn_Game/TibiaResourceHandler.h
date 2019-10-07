#pragma once
#include <map>
#include <memory>
#include <string>
#include <iostream>
namespace TGC
{
	template <typename T>
	class ResourceHandler
	{
		std::map<std::string, std::shared_ptr<T>> resourceList;
	public:
		ResourceHandler() = default;
		~ResourceHandler() = default;
		void addResource(std::string name, std::shared_ptr<T> resource);
		std::shared_ptr<T> getResourceByName(std::string name);
	};

	template<typename T>
	inline void ResourceHandler<T>::addResource(std::string name, std::shared_ptr<T> resource)
	{
		if (resourceList.find(name) != resourceList.end())
		{
			std::cout << "resource named:" << name << " exist on the list!" << std::endl;
			return;
		}
		resourceList.insert(std::make_pair(name, resource));
	}

	template<typename T>
	inline std::shared_ptr<T> ResourceHandler<T>::getResourceByName(std::string name)
	{
		auto findResoult = resourceList.find(name);
		if (findResoult == resourceList.end())
		{
			std::cout << "resource named:" << name << " don't exist on the list!" << std::endl;
			return std::shared_ptr<T>();
		}
		else
		{
			return findResoult->second;
		}
	}
}